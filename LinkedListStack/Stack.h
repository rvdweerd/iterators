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
	class Iterator
	{
	public:
		Iterator(Element* pElement)
			:
			pCurrentElement(pElement)
		{}
		//Iterator operator++(int) //postfix incrementor
		//{}
		int& operator*()
		{
			return pCurrentElement->val;
		}
		Iterator& operator++() //prefix incrementor
		{
			if (pCurrentElement != nullptr)
				pCurrentElement = pCurrentElement->pNext;// GetNextElement();
			return *this;
		}
		bool operator!=(Iterator& rhs)
		{
			return rhs.pCurrentElement != pCurrentElement;
		}
	private:
		Element* pCurrentElement;
	};
	Iterator begin()
	{
		return Iterator(pTop);
	}
	Iterator end()
	{
		return Iterator(nullptr);
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