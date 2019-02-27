#pragma once


template<typename Object>
class List
{
private:
	struct Node
	{
		Object data;
		Node *prev;
		Node *next;

		Node(const Object &d = Object{}, Node*p = nullptr, Node *n = nullptr) :data{ d }, prev{ p }, next{ n } {}
		Node(Object &&d, Node*p = nullptr, Node*n = nullptr) :data{ std::move(d) }, prev{ p }, next{ n }{ }

	};
public:
	class const_iterator
	{
	public:
		const_iterator():current{nullptr}{}

		const Object & operator* ()const
		{
			return retrieve();
		}

		const_iterator &operator++ ()
		{
			current = current->next;
			return *this;
		}

		const_iterator operator++(int)
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}

		bool operator==(const const_iterator &rhs)const
		{
			return current == rhs.current;
		}
		bool operator!=(const const_iterator &rhs)const
		{
			return !(*this == rhs);
		}

	protected:
		Node* current;

		Object &retrieve() const
		{
			return current->data;
		}
		const_iterator(Node *p):current{p}{}
		friend class List<Object>;
	};

	class iterator :public const_iterator
	{
	public:
		iterator() {}

		Object & operator*()
		{
			return const_iterator::retrieve();
		}

		const Object & operator* ()const
		{
			return const_iterator::operator*();
		}

		iterator &operator++()
		{
			this->current = this->current->next;
			return *this;
		}

		iterator operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}

	protected:
		iterator(Node *p):const_iterator{p}{}

		friend class List<Object>;
	};

public:
	List()
	{
		init();
	}
	~List()
	{
		clear();
		delete head;
		delete tail;
	}

	iterator begin()
	{
		return{ head->next };
	}

	const_iterator begin() const
	{
		return{ head->next };
	}

	iterator end()
	{
		return{ tail };
	}

	const_iterator end() const
	{
		return{ tail };
	}

	int size() const
	{
		return theSize;
	}

	bool empty() const
	{
		return size() == 0;
	}

	void clear()
	{
		while (!empty())
		{
			pop_front();
		}
	}

	Object & front()
	{
		return *begin();
	}

	const Object& front()const
	{
		return *begin();
	}

	Object & back()
	{
		return *--end();
	}

	const Object &back()const
	{
		return *--end();
	}

	void push_back(const Object &x)
	{
		insert(end(), x);
	}

	void pop_front()
	{
		erase(begin());
	}

	void pop_back()
	{
		erase(--end());
	}

	iterator insert(iterator itr, const Object & x)
	{
		Node *p = itr.current;
		theSize++;
		return{ p->prev = p->prev->next = new Node{x,p->prev,p} };
	}

	iterator erase(iterator itr)
	{
		Node *p = itr.current;
		iterator retVal{ p->next };
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		theSize--;

		return retVal;
	}

private:
	int theSize;
	Node *head;
	Node *tail;

	void init()
	{
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}
};