#pragma once
#include <iterator>

class Stack
{
private:
	class Element
	{
	public:
		Element( int val,Element* pNext )
			:
			val( val ),
			pNext( pNext )
		{}
		Element( Element& src )
			:
			val( src.val )
		{
			if( src.pNext != nullptr )
			{
				pNext = new Element( *src.pNext );
			}
		}
		Element& operator=( const Element& ) = delete;
		int GetVal() const
		{
			return val;
		}
		Element* GetNextElement()
		{
			return pNext;
		}
		int* GetValPtr() 
		{
			//int* ptr= &val;
			return &val;
		}
		int* GetEndValPtr() 
		{
			Element* ptr = pNext;
			while (ptr->pNext != nullptr)
			{
				ptr = ptr->pNext;
			}
			return ptr->GetValPtr();
		}
		Element* Disconnect()
		{
			auto pTemp = pNext;
			pNext = nullptr;
			return pTemp;
		}
		int CountElements() const
		{
			if( pNext != nullptr )
			{
				return pNext->CountElements() + 1;
			}
			else
			{
				return 1;
			}
		}
		~Element()
		{
			delete pNext;
			pNext = nullptr;
		}
	public:
		int val;
		Element* pNext = nullptr;
	};
public:
	//Implementing the regular iterator for Stack
	class Iterator
	{
	public:
		Iterator() = default;
		Iterator(Element* pElement)
			:
			pCurrentElement(pElement)
		{}
		int& operator*() const
		{
			return pCurrentElement->val;
		}
		Iterator& operator++() //prefix incrementor
		{
			if (pCurrentElement != nullptr)
				pCurrentElement = pCurrentElement->pNext;
			return *this;
		}
		Iterator operator++(int) //postfix operator
		{
			if (pCurrentElement != nullptr)
			{
				Element* temp = pCurrentElement;
				pCurrentElement = pCurrentElement->pNext;
			}
			return *this;
		}
		bool operator!=(const Iterator& rhs) const
		{
			return rhs.pCurrentElement != pCurrentElement;
		}
	private:
		Element* pCurrentElement = nullptr;
	};
	Iterator begin()
	{
		return { pTop };
	}
	Iterator end()
	{
		return {};
	}

	public:
	//Implementing the const iterator for Stack
	class const_Iterator
	{
	public:
		const_Iterator(const Element* const pElement)
			:
			pCurrentElement(pElement)
		{}
		const int& operator*() const
		{
			return pCurrentElement->val;
		}
		const const_Iterator& operator++() //prefix incrementor
		{
			if (pCurrentElement != nullptr)
				pCurrentElement = pCurrentElement->pNext;
			return *this;
		}
		const const_Iterator operator++(const int) //postfix operator
		{
			if (pCurrentElement != nullptr)
			{
				const Element* temp = pCurrentElement;
				pCurrentElement = pCurrentElement->pNext;
			}
			return *this;
		}
		bool operator!=(const const_Iterator& rhs) const
		{
			return rhs.pCurrentElement != pCurrentElement;
		}
	private:
		const Element* pCurrentElement;
	};
	const_Iterator begin() const
	{
		return const_Iterator(pTop);
	}
	const_Iterator end() const
	{
		return const_Iterator(nullptr);
	}
public:
	Stack() = default;
	Stack( const Stack& src )
	{
		*this = src;
	}
	Stack& operator=( const Stack& src )
	{
		if( &src != this )
		{
			if( !Empty() )
			{
				delete pTop;
				pTop = nullptr;
			}

			if( !src.Empty() )
			{
				pTop = new Element( *src.pTop );
			}
		}
		return *this;
	}
	~Stack()
	{
		delete pTop;
		pTop = nullptr;
	}
	void Push( int val )
	{
		pTop = new Element( val,pTop );
	}
	int Pop()
	{
		if( !Empty() )
		{
			const int tempVal = pTop->GetVal();
			auto pOldTop = pTop;
			pTop = pTop->Disconnect();
			delete pOldTop;
			return tempVal;
		}
		else
		{
			return -1;
		}
	}
	int Size() const
	{
		if( !Empty() )
		{
			return pTop->CountElements();
		}
		else
		{
			return 0;
		}
	}
	bool Empty() const
	{
		return pTop == nullptr;
	}
private:
	Element* pTop = nullptr;
};