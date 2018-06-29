#pragma once


#include <new>
#include <algorithm>
#include <stdexcept>
#include <cassert>

template <typename T>
class CMyArray
{
public:
	CMyArray() = default;

	CMyArray(const CMyArray& arr)
	{
		const auto size = arr.GetSize();
		if (size != 0)
		{
			m_begin = RawAlloc(size);
			try
			{
				CopyItems(arr.m_begin, arr.m_end, m_begin, m_end);
				m_endOfCapacity = m_end;
			}
			catch (...)
			{
				DeleteItems(m_begin, m_end);
				throw;
			}
		}
	}

	CMyArray(CMyArray&& arr)
		: m_begin(arr.m_begin),
		 m_end(arr.m_end),
		 m_endOfCapacity(arr.m_endOfCapacity)
	{
		arr.m_begin = nullptr;
		arr.m_end = nullptr;
		arr.m_endOfCapacity = nullptr;
	}


	void Append(const T& value)
	{
		if (m_end == m_endOfCapacity)
		{
			size_t newCapacity = std::max(size_t(1), GetCapacity() * 2);

			auto newBegin = RawAlloc(newCapacity);
			T* newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
				new (newEnd) T(value);
				++newEnd;
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}
			DeleteItems(m_begin, m_end);


			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newCapacity;
		}
		else
		{
			new (m_end) T(value);
			++m_end;
		}
	}

	T& operator[](size_t index)
	{
		if (index >= GetSize())
		{
			throw std::out_of_range("Index is out of range");
		}
		
		return m_begin[index];
	}

	const T& operator[](size_t index) const
	{
		if (index >= GetSize())
		{
			throw std::out_of_range("Index is out of range");
		}

		return m_begin[index];
	}
	 
	void Resize(size_t newSize)
	{
		if (newSize > GetSize())
		{
			if (newSize > GetCapacity())
			{
				size_t newCapacity = newSize * 2;
				auto newBegin = RawAlloc(newCapacity);
				T* newEnd = newBegin;
				try
				{
					CopyItems(m_begin, m_end, newBegin, newEnd);
				}
				catch (...)
				{
					DeleteItems(newBegin, newEnd);
					throw;
				}
				DeleteItems(m_begin, m_end);
				m_begin = newBegin;
				m_end = newEnd;
				m_endOfCapacity = m_begin + newCapacity;
			}
			T* newEnd = m_begin + newSize;
			while (m_end != newEnd)
			{
				new (newEnd) T();
				++newEnd;
			}
		}
		T* newEnd = m_begin + newSize;
		DeleteItems(newEnd, m_end);
		m_end = newEnd;
	}

	void Clear()
	{
		DeleteItems(m_begin, m_end);
		m_begin = nullptr;
		m_begin = m_begin;
		m_endOfCapacity = m_begin;
	}

	//присваивание
	CMyArray& operator=(CMyArray& other)
	{
		if (std::addressof(other) != this)
		{
			CMyArray arrCopy(other);
			std::swap(m_begin, arrCopy.m_begin);
			std::swap(m_end, arrCopy.m_end);
			std::swap(m_endOfCapacity, arrCopy.m_endOfCapacity);
		}
		return *this;
	}

	//перемещающий оператор присваивания
	CMyArray& operator=(CMyArray&& other)
	{
		if (&other != this)
		{
			Clear();
			m_begin = other.m_begin;
			m_end = other.m_end;
			m_endOfCapacity = other.m_endOfCapacity;

			other.m_begin = nullptr;
			other.m_end = nullptr;
			other.m_endOfCapacity = nullptr;
		}
		return *this;
	}


	T& GetBack()
	{
		assert(GetSize() != 0u);
		return m_end[-1];
	}

	const T& GetBack() const
	{
		assert(GetSize() != 0u);
		return m_end[-1];
	}

	size_t GetSize() const
	{
		return m_end - m_begin;
	}

	size_t GetCapacity() const
	{
		return m_endOfCapacity - m_begin;
	}
	~CMyArray()
	{
		DeleteItems(m_begin, m_end);
	}

private:
	static void DeleteItems(T* begin, T* end)
	{
		DestroyItems(begin, end);
		RawDealloc(begin);
	}

	static void CopyItems(const T* srcBegin, T* srcEnd, T* const dstBegin, T*& dstEnd)
	{
		for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
		{
			new (dstEnd) T(*srcBegin);
		}
	}

	static void DestroyItems(T* from, T* to)
	{
		while (to != from)
		{
			--to;
			to->~T();
		}
	}

	static T* RawAlloc(size_t n)
	{
		size_t memSize = n * sizeof(T);
		T* p = static_cast<T*>(malloc(memSize));
		if (!p)
		{
			throw std::bad_alloc();
		}
		return p;
	}

	static void RawDealloc(T* p)
	{
		free(p);
	}

private:
	T* m_begin = nullptr;
	T* m_end = nullptr;
	T* m_endOfCapacity = nullptr;
};