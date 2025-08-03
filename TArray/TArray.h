#pragma once
#include <iostream>
#include "TReverseIterator.h"
using namespace std;

template<typename T, size_t N>
class TArray
{
protected:
	T elems[N];
public:
	T& operator[](size_t pos);
	const T& operator[](size_t pos) const;
	T& At(size_t pos);
	const T& At(size_t pos) const;
	T& Front();
	const T& Front() const;
	T& Back();
	const T& Back() const;
	T* Data() noexcept;
	const T* Data() const noexcept;

	T* begin() noexcept;
	const T* begin() const noexcept;
	T* end() noexcept;
	const T* end() const noexcept;
	const T* cbegin() const noexcept;
	const T* cend() const noexcept;
	TReverseIterator<T*> rbegin() noexcept;
	TReverseIterator<T*> rend() noexcept;
	TReverseIterator<const T*> rbegin() const noexcept;
	TReverseIterator<const T*> rend() const noexcept;
	TReverseIterator<const T*> rcbegin() const noexcept;
	TReverseIterator<const T*> rcend() const noexcept;

	constexpr bool Empty() const noexcept;
	constexpr size_t Size() const noexcept;
	constexpr size_t MaxSize() const noexcept;

	void Fill(const T& value);
	void Swap(TArray& other) noexcept;
};

template<typename T, size_t N>
inline T& TArray<T, N>::operator[](size_t pos)
{
	return elems[pos];
}

template<typename T, size_t N>
inline const T& TArray<T, N>::operator[](size_t pos) const
{
	return elems[pos];
}

template<typename T, size_t N>
inline T& TArray<T, N>::At(size_t pos)
{
	if (pos > N)
		throw 1;
	else
		return elems[pos];
}

template<typename T, size_t N>
inline const T& TArray<T, N>::At(size_t pos) const
{
	if (pos > N)
		throw 1;
	else
		return elems[pos];
}

template<typename T, size_t N>
inline T& TArray<T, N>::Front()
{
	return elems[0];
}

template<typename T, size_t N>
inline const T& TArray<T, N>::Front() const
{
	return elems[0];
}

template<typename T, size_t N>
inline T& TArray<T, N>::Back()
{
	return elems[N-1];
}

template<typename T, size_t N>
inline const T& TArray<T, N>::Back() const
{
	return elems[N-1];
}

template<typename T, size_t N>
inline T* TArray<T, N>::Data() noexcept
{ 
    return elems;
}

template<typename T, size_t N>
inline const T* TArray<T, N>::Data() const noexcept
{
	return elems;
}

template<typename T, size_t N>
inline T* TArray<T, N>::begin() noexcept
{
	return &elems[0];
}

template<typename T, size_t N>
inline const T* TArray<T, N>::begin() const noexcept
{
	return &elems[0];
}

template<typename T, size_t N>
inline T* TArray<T, N>::end() noexcept
{
	return &elems[0]+N;
}

template<typename T, size_t N>
inline const T* TArray<T, N>::end() const noexcept
{
	return &elems[0] + N;
}

template<typename T, size_t N>
inline TReverseIterator<T*> TArray<T, N>::rbegin() noexcept
{
	return TReverseIterator<T*>(elems + N);
}

template<typename T, size_t N>
inline TReverseIterator<const T*> TArray<T, N>::rbegin() const noexcept
{
	return TReverseIterator<const T*>(elems + N);
}

template<typename T, size_t N>
inline TReverseIterator<T*> TArray<T, N>::rend() noexcept
{
	return TReverseIterator<T*>(elems);
}

template<typename T, size_t N>
inline TReverseIterator<const T*> TArray<T, N>::rend() const noexcept
{
	return TReverseIterator<const T*>(elems);
}

template<typename T, size_t N>
inline TReverseIterator<const T*> TArray<T, N>::rcbegin() const noexcept
{
	return TReverseIterator<const T*>(cend());
}

template<typename T, size_t N>
inline TReverseIterator<const T*> TArray<T, N>::rcend() const noexcept
{
	return TReverseIterator<const T*>(cbegin());
}

template<typename T, size_t N>
inline const T* TArray<T, N>::cbegin() const noexcept
{
	return begin();
}

template<typename T, size_t N>
inline const T* TArray<T, N>::cend() const noexcept
{
	return end();
}

template<typename T, size_t N>
inline constexpr bool TArray<T, N>::Empty() const noexcept
{
	return N==0;
}

template<typename T, size_t N>
inline constexpr size_t TArray<T, N>::Size() const noexcept
{
	return N;
}

template<typename T, size_t N>
inline constexpr size_t TArray<T, N>::MaxSize() const noexcept
{
	return N;
}

template<typename T, size_t N>
inline void TArray<T, N>::Fill(const T& value)
{
	for (size_t i = 0; i < N; ++i)
		elems[i] = value;
}

template<typename T, size_t N>
inline void TArray<T, N>::Swap(TArray& other) noexcept
{
	for (size_t i = 0; i < N; ++i)
		swap(elems[i], other.elems[i]);
}