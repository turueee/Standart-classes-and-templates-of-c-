#pragma once
#include <iostream>
using namespace std;

template<typename T>
class TAllocator
{
public:
	using value_type = T;
	using pointer = T*;
	using const_pointer = const T*;
	using reference = T&;
	using const_reference = const T&;
	using size_type = size_t;
	using difference_type = ptrdiff_t;

	template <typename U>
	struct rebind
	{
		using other = TAllocator<U>;
	};

	constexpr TAllocator() noexcept = default;
	constexpr TAllocator(const TAllocator&) noexcept = default;
	template<typename U>
	constexpr TAllocator(const TAllocator<U>&) noexcept;
	~TAllocator() = default;

	[[nodiscard]] constexpr T* Allocate(size_type n);
	constexpr void Deallocate(pointer p, size_type n);

	template<typename U,typename... Args>
	constexpr void Construct(U* p, Args&&... args);
	template<typename U>
	constexpr void Destroy(U* p);

	constexpr bool operator== (const TAllocator&) const noexcept;
	constexpr bool operator!= (const TAllocator&) const noexcept;
};

template<typename T>
constexpr T&& Forward(T& t) noexcept
{
	return static_cast<T&&>(t);
}

template<typename T>
inline constexpr T* TAllocator<T>::Allocate(size_type n)
{
	return static_cast<pointer>(::operator new(n*sizeof(value_type)));
}

template<typename T>
inline constexpr void TAllocator<T>::Deallocate(pointer p, size_type n)
{
	::operator delete(p,n*sizeof(T));
}

template<typename T>
inline constexpr bool TAllocator<T>::operator==(const TAllocator&) const noexcept
{
	return true;
}

template<typename T>
inline constexpr bool TAllocator<T>::operator!=(const TAllocator&) const noexcept
{
	return false;
}

template<typename T>
template<typename U, typename ...Args>
inline constexpr void TAllocator<T>::Construct(U* p, Args && ...args)
{
	new (static_cast<void*>(p)) U(Forward<Args>(args)...);
}

template<typename T>
template<typename U>
inline constexpr void TAllocator<T>::Destroy(U* p)
{
	p->~U();
}