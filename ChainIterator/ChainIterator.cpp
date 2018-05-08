#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T> class Chain;

template <typename T>
class ChainNode {
	friend class Chain<T>;            // ChainNode�� Chain�� ������ Ŭ������ ����
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

	void InsertBack(T item)      // ���� ����
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

	ChainIterator begin()      //ü�����ͷ������� ���ۺκ�
	{
		return ChainIterator(first);
	}

	ChainIterator end()      //���κ�
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
		i++;      //���� ������ �����ε� �س���!!
	}

	os << i.getData();
	os << endl;
	return os;
}

template <typename T>
T getMinimum(Chain<T> &c)
{
	T minimum = 9999;  //�ִ� 9999����.
	typename Chain<T>::ChainIterator i = c.begin();
	while (i != c.end())
	{
		if (i.getData() < minimum) minimum = i.getData();
		i++;   //�������� �Ѿ
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