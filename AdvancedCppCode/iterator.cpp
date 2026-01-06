#include <iostream>

template<typename T1, typename T2>
T1 efind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
	{
		++first;
	}

	return first;
}

template<typename T> struct Node
{
	T data;
	Node* next;

	Node(const T& a, Node* n) :data(a), next(n) {}
};

template<typename T> class slist_iterator
{
	Node<T>* current = 0;
public:
	slist_iterator(Node<T>* p = 0) :current(p) {}
	slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	T& operator*()
	{
		return current->data;
	}
	bool operator==(const slist_iterator& it)
	{
		return current == it.current;
	}
	bool operator!=(const slist_iterator& it)
	{
		return current != it.current;
	}
};

template<typename T>class slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}

	using iterator = slist_iterator<T>;
	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator(0);
	}
#if 0
	slist_iterator<T> begin()
	{
		return slist_iterator<T>(head);
	}
	slist_iterator<T> end()
	{
		return slist_iterator<T>(0);
	}
#endif

};

int main(void)
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

	//slist_iterator<int>p = s.begin();
	slist<int>::iterator p = s.begin();
	slist<int>::iterator p2 = efind(s.begin(), s.end(), 120);

	if (p2 == s.end())
	{
		std::cout << "fail" << "\n";
	}
	else
	{
		std::cout << *p2 << "\n";
	}

	/*
	std::cout << *p << std::endl;	// 50
	++p;
	std::cout << *p << std::endl;	// 40
	while (p != s.end())
	{
		std::cout << *p << std::endl;
		++p;
	}
	*/
}