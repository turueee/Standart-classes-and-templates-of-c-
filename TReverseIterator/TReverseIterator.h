#pragma once
#include <iostream>
using namespace std;

template<typename Iterator>
class TReverseIterator
{
protected:
	Iterator current;
public:
	constexpr TReverseIterator();
	explicit constexpr TReverseIterator(Iterator x);

	template<class U>
	constexpr TReversIterator(const TReverseIterator<U>& other) : current(other.base()) {};

	template<class U>
	constexpr TReversIterator& operator=(const TReverseIterator <U>& other)
	{
		current = other.Base;
		return *this;
	}

	constexpr Iterator Base() const;
	constexpr Iterator& operator*() const;
	constexpr Iterator* operator->() const;
	constexpr Iterator& operator[](ptrdiff_t n) const;

	constexpr TReverseIterator& operator++()
	{
		--current;
		return *this;
	}

	constexpr TReverseIterator operator++(int)
	{
		TReverseIterator tmp(*this);
		--current;
		return tmp;
	}

	constexpr TReverseIterator& operator--()
	{
		++current;
		return *this;
	}

	constexpr TReverseIterator operator--(int)
	{
		TReverseIterator tmp(*this);
		++current;
		return tmp;
	}

	constexpr TReverseIterator operator+(ptrdiff_t n) const { return TReverseIterator(current - n); }
	constexpr TReverseIterator operator-(ptrdiff_t n) const { return TReverseIterator(current + n); }

	constexpr TReverseIterator& operator+=(ptrdiff_t n)
	{
		current -= n;
		return *this;
	}

	constexpr TReverseIterator& operator-=(ptrdiff_t n)
	{
		current += n;
		return *this;
	}
};

template<typename Iterator>
inline constexpr TReverseIterator<Iterator>::TReverseIterator() : current() {}

template<typename Iterator>
inline constexpr TReverseIterator<Iterator>::TReverseIterator(Iterator x) : current(x) {}

template<typename Iterator>
inline constexpr Iterator TReverseIterator<Iterator>::Base() const { return current; }

template<typename Iterator>
inline constexpr Iterator& TReverseIterator<Iterator>::operator*() const 
{
	Iterator tmp = current;
	return *--tmp;
}

template<typename Iterator>
inline constexpr Iterator* TReverseIterator<Iterator>::operator->() const {return addressof(operator*())}

template<typename Iterator>
inline constexpr Iterator& TReverseIterator<Iterator>::operator[](ptrdiff_t n) const
{
	return *(*this + n);
}