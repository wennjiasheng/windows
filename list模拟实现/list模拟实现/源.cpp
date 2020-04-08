#pragma once

template<class T>
struct ListNode
{
	ListNode(const T& data = T())
	:_pnext(nullptr)
	, ppre(nullptr)
	, _data(data)
	{}
	ListNode<T>* _pnext;
	ListNode<T>* _ppre;
	T _data;
};
namespace n
{
	template<class T>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
		typedef ListIterator<T> self;
		ListIterator(PNode pNode = nullptr)
			:_pNode(pNode)
		{
		}
		ListIterator(const self& s)
			:_pNode(s._pNode)
		{}
		T& operator*()
		{
			return _pNode->_data;
		}
		T* operator->()
		{
			return &(_pNode->_data);
		}
		self& operator++()
		{
			_pNode = _pNode->_pnext;
			return *this;
		}
		self& operator--()
		{
			_pNode = _pNode->_ppre;
			return *this;
		}
		self& operator++(int)//ºóÖÃ++
		{
			self temp(*this);
			_pNode = _pNode->_pnext;
			return temp;
		}
		self& operator--(int)//ºóÖÃ--
		{
			self temp(*this);
			_pNode = _pNode->_ppre;
			return temp;
		}
		bool operator!=(const self& s)const
		{
			return _pNode != s->_pNode;
		}
		bool operator==(const self& s)const
		{
			return _pNode == s->_pNode;
		}
	private:
		PNode _pNode;
	};
	template<class>
	class list
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;

	public:
		list()
		{
			Creathead();
		}
		list(size_t n, const T& data = T())
		{
			Creathead();
			for (size_t i = 0; i < n; i++)
				push_back(data);
		}
		list(T* first, T* last)
		{
			Creathead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& l)
		{
			PNode pcur = l._phead->_pnext;
			while (pcur != l._phead->_pnext)
			{
				push_back(pcur->_data);
				pcur = pcur->_pnext;
			}
		}
		~list()
		{
			clear();
			delete _phead;
			_phead = nullptr;
		}
		size_t size()const
		{
			size_t count = 0;
			PNode pcur = _phead->_pnext;
			while (pcur != _phead->_pnext)
			{
				count++;
				pcur = pcur->_pnext;
			}
			return count;
		}
		bool empty()const
		{
			return _phead == _phead->_pnext;
		}
		void resize(size_t n, const T& data =0 )
		{
			size_t oldsize = size();
			if (oldsize < n)
			{
				for (int i = oldsize; i < n; i++)
				{
					push_back(data);
				}
			
			}
			else
			{
				for (int i = n; i < oldsize; i++)
					pop_back();
			}		
		}
		T& front()
		{
			return _phead->_pnext->_data;
		}
		const T& front()const
		{
			return _phead->_pnext->_data;
		}
		T& back()
		{
			return _phead->_ppre->_data;
		}
		const T& back()const
		{
			return _phead->_ppre->_data;
		}
		void push_back(const T& data)
		{
			PNode pcur = new Node(data);
			pcur->_pnext = _phead;
			pcur->_ppre = _phead->_ppre;
			_phead->_ppre->_pnext = pcur;
			_phead->_ppre = pcur;
		}
		void pop_back()
		{
			PNode pcur = _phead->_ppre;
			_phead->_ppre = pcur->_ppre;
			pcur->_ppre->_pnext = _phead;
			delete pcur;
		}
		void push_front(const T& data)
		{
			PNode newnode = new Node(data);
			newnode->_ppre = _phead;
			newnode->_pnext = _phead->_pnext;
			_phead->_pnext = newnode;
			newnode->_pnext->_ppre = newnode;
		}
		void pop_front()
		{
			PNode pcur = _phead->_pnext;
			_phead->_pnext = pcur->_pnext;
			pcur->_pnext->_ppre = _phead;
			delete pcur;
		}
		void swap(list<T>& l)
		{
			swap(_phead, l._phead);
		}
		void clear()
		{
			PNode pcur = _phead->_pnext;
			while (pcur != _phead)
			{
				_phead->_pnext = pcur->_pnext;
				delete pcur;
				pcur = _phead->_pnext;
			}
			_phead->_pnext = _phead;
			_phead->_ppre = _phead;
		}

	private:
		void Creathead()
		{
			_phead = new Node;
			_phead->_pnext = _phead;
			_phead->_ppre = _phead;

		}
	private:
		PNode _phead;
	};

}