#pragma once
#include <iostream>
#include "TAllocator.h"
#include "TReverseIterator.h"
using namespace std;

template<class T, class Allocator = TAllocator<T>>
class TVector
{
protected:
	T* _data;
	size_t _size;
	size_t _capacity;
	Allocator _alloc;
public:
	using value_type = T;
	using allocator_type = Allocator;
	using size_type = size_t;
	using difference_type = ptrdiff_t;
	using reference = T&;
	using const_reference = const T&;
	using pointer = T*;
	using const_pointer = const T*;
	using iterator = T*;
	using const_iterator = const T*;
	using reverse_iterator = TReverseIterator<iterator>;
	using const_reverse_iterator = TReverseIterator<const_iterator>;

	TVector() noexcept (noexcept(Allocator()));
	explicit TVector(const Allocator& alloc) noexcept;
	explicit TVector(size_type count, const T& value = T(), const Allocator& alloc = Allocator());
	TVector(const TVector& other);
	TVector(const TVector& other, const Allocator& alloc);
	TVector(TVector&& other);
	TVector(TVector&& other, const Allocator& alloc);

	~TVector();

	TVector& operator=(const TVector<T, Allocator>& other);
	TVector& operator=(TVector<T,Allocator>&& other) noexcept;

	T& operator[](size_type pos);
	const T& operator[](size_type pos) const;
	T& At(size_type pos);
	const T& At(size_type pos) const;
	T& Front();
	const T& Front() const;
	T& Back();
	const T& Back() const;
	T* Data();
	const T* Data() const;




	template<class O>
	friend ostream& operator<<(ostream& out, TVector<O>& t);
};

template<class T, class Allocator>
inline TVector<T, Allocator>::TVector() noexcept(noexcept(Allocator()))
	:_data(nullptr),_size(0),_capacity(0),_alloc(Allocator()) {}

template<class T, class Allocator>
inline TVector<T, Allocator>::TVector(const Allocator& alloc) noexcept
	:_data(nullptr), _size(0), _capacity(0), _alloc(alloc) {}

template<class T, class Allocator>
inline TVector<T, Allocator>::TVector(size_type count, const T& value, const Allocator& alloc)
	:_alloc(alloc),_size(count),_capacity(count)
{
	_data = _alloc.Allocate(count);
	for (size_type i = 0; i < count; ++i)
		_alloc.Construct(_data + i, value);
}

template<class T, class Allocator>
inline TVector<T, Allocator>::TVector(const TVector& other)
	:_alloc(other._alloc),_size(other._size),_capacity(other._capacity)
{
	_data = _alloc.Allocate(_capacity);
	for (size_type i = 0; i < _size; ++i)
		_alloc.Construct(_data + i, other._data[i]);
}

template<class T, class Allocator>
inline TVector<T, Allocator>::TVector(const TVector& other, const Allocator& alloc)
	:_alloc(other._alloc), _size(other._size), _capacity(other._capacity)
{
	_data = _alloc.Allocate(_capacity);
	for (size_type i = 0; i < _size; ++i)
		_alloc.Construct(_data + i, other._data[i]);
}

template<class T, class Allocator>
inline TVector<T, Allocator>::TVector(TVector&& other)
	:_size(other._size),_data(other._data),_capacity(other._capacity),_alloc(move(other._alloc))
{
	other._data = nullptr;
	other._capacity = 0;
	other._size = 0;
}

template<class T, class Allocator>
inline TVector<T, Allocator>::TVector(TVector&& other, const Allocator& alloc)
	:_alloc(other._alloc), _size(other._size), _capacity(other._capacity)
{
	if (_alloc == other._alloc)
	{
		_data = other._data;
		other._data = nullptr;
		other._size = 0;
		other._capacity = 0;
	}
	else
	{
		_data = _alloc.Allocate(_capacity);
		for (size_type i = 0; i < _size; ++i)
			_alloc.Construct(_data + i,move(other._data[i]));
	}
}

template<class T, class Allocator>
inline TVector<T, Allocator>::~TVector()
{
	for (size_type i = 0; i < _size; ++i)
		_alloc.Destroy(_data + i);
	_alloc.Deallocate(_data, _capacity);
}


template<class T, class Allocator>
inline TVector<T, Allocator>& TVector<T, Allocator>::operator=(const TVector<T, Allocator>& other)
{
	if (this != &other)
	{
		for (size_type i = 0; i < _size; ++i)
			_alloc.Destroy(_data + i);
		_alloc.Deallocate(_data,_capacity);
		_size = other._size;
		_capacity = other._capacity;
		_data = _alloc.Allocate(_capacity);
		for (size_type i = 0; i < _size; ++i)
			_alloc.Construct(_data + i, other._data[i]);
	}
	return *this;
}


template<class T, class Allocator>
inline TVector<T, Allocator>& TVector<T, Allocator>::operator=(TVector<T, Allocator>&& other) noexcept
{
	if (this != &other)
	{
		Clear();
		_alloc.Deallocate(_data, _capacity);

		_data = other._data;
		_capacity = other._capacity;
		_size = other._size;
		_alloc = move(other._alloc);

		other._data = nullptr;
		other._capacity = 0;
		other._size = 0;
	}
	return *this;
}

template<class T, class Allocator>
inline T& TVector<T, Allocator>::operator[](size_type pos)
{
	return _data[pos];
}

template<class T, class Allocator>
inline const T& TVector<T, Allocator>::operator[](size_type pos) const
{
	return _data[pos];
}

template<class T, class Allocator>
inline T& TVector<T, Allocator>::At(size_type pos)
{
	if (pos >= _size)
		throw 1;
	return _data[pos];
}

template<class T, class Allocator>
inline const T& TVector<T, Allocator>::At(size_type pos) const
{
	if (pos >= _size)
		throw 1;
	return _data[pos];
}

template<class T, class Allocator>
inline T& TVector<T, Allocator>::Front()
{
	return this->At(0);
}

template<class T, class Allocator>
inline const T& TVector<T, Allocator>::Front() const
{
	return this->At(0);
}

template<class T, class Allocator>
inline T& TVector<T, Allocator>::Back()
{
	return this->At(_size-1);
}

template<class T, class Allocator>
inline const T& TVector<T, Allocator>::Back() const
{
	return this->At(_size - 1);
}

template<class T, class Allocator>
inline T* TVector<T, Allocator>::Data()
{
	return _data;
}

template<class T, class Allocator>
inline const T* TVector<T, Allocator>::Data() const
{
	return _data;
}

template<class O>
inline ostream& operator<<(ostream& out, TVector<O>& t)
{
	for (size_t i = 0; i < t._size; ++i)
		out << t[i] << "\n";
	return out;
}
