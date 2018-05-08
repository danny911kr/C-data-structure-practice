#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T> class Chain;

template <typename T>
class ChainNode {
	friend class Chain<T>;            // ChainNode에 Chain을 프랜드 클래스로 선언
private:
	T data;
	ChainNode<T> *link;
public:
	ChainNode(const T element)
	{
		this->data = element;
	}
	T getData()
	{
		return data;
	}
};

template <typename T>
class Chain {
private:
	ChainNode<T> *first;
	ChainNode<T> *last;
public:
	Chain() {
		first = 0;
	}

	void InsertBack(T item)      // 끝에 삽입
	{
		if (first)
		{
			last->link = new ChainNode<T>(item);
			last = last->link;
		}
		else
		{
			first = last = new ChainNode<T>(item);
		}
	}

	class ChainIterator {
	private:
		ChainNode<T>* current;
	public:
		ChainIterator(ChainNode<T>* startNode = 0) {
			current = startNode;
		};

		T getData() { return current->data; }
		T& operator*() const { return current->data; }
		T* operator->() const { return &current->data; }

		ChainIterator& operator++() {
			current = current->link;
			return *this;
		}

		ChainIterator operator++(int) {
			ChainIterator old = *this;
			current = current->link;
			return old;
		}

		bool operator!=(const ChainIterator right) const {
			return current != right.current;
		}
		bool operator==(const ChainIterator right) const {
			return current == right.current;
		}

		template <typename T>
		friend ostream &operator<<(ostream &os, Chain<T> &c);

		template <typename T>
		friend T getMinimum(Chain<T> &c);
	};

	ChainIterator begin()      //체인이터레이터의 시작부분
	{
		return ChainIterator(first);
	}

	ChainIterator end()      //끝부분
	{
		return ChainIterator(last);
	}

	template <typename T>
	friend ostream &operator<<(ostream &os, Chain<T> &c);

	template <typename T>
	friend T getMinimum(Chain<T> &c);
};

template <typename T>
ostream &operator<<(ostream &os, Chain<T> &c)
{
	typename Chain<T>::ChainIterator i = c.begin();
	while (i != c.end())
	{
		os << i.getData() << "->";
		i++;      //위에 연산자 오버로딩 해놓음!!
	}

	os << i.getData();
	os << endl;
	return os;
}

template <typename T>
T getMinimum(Chain<T> &c)
{
	T minimum = 9999;  //최대 9999까지.
	typename Chain<T>::ChainIterator i = c.begin();
	while (i != c.end())
	{
		if (i.getData() < minimum) minimum = i.getData();
		i++;   //다음으로 넘어감
	}
	return minimum;
}

int main(void)
{
	Chain<int> list;
	int n;
	do {
		cin >> n;
		list.InsertBack(n);
	} while (getc(stdin) == ' ');

	cout << endl << list << endl;
	cout << getMinimum(list) << endl;

	return 0;
}