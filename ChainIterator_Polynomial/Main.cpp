#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "stdlib.h"

using namespace std;
using std::string;

std::string ReplaceAll(std::string &str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
}

template <typename T> class Chain;

template <typename T>
class ChainNode
{
	friend class Chain<T>;
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

template<typename T>
class Chain
{
private:
	ChainNode<T> *first;
	ChainNode<T> *last;
public:
	Chain()
	{
		first = 0;
	}

	void InsertBack(const T &item)
	{
		if (first)
		{
			last->link = new ChainNode<T>(item);
			last = last->link;
			last->link = NULL;
		}
		else
		{
			first = last = new ChainNode<T>(item);
			first->link = NULL;
		}
	}
	class ChainIterator
	{
	private:
		ChainNode<T> *current;
	public:
		ChainIterator(ChainNode<T> *startNode = 0)
		{
			current = startNode;
		}

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

		bool operator&&(const ChainIterator right) const {
			return current && right.current;
		}
	};
	ChainIterator begin()      //체인이터레이터의 시작부분
	{
		return ChainIterator(first);
	}

	ChainIterator end()      //끝부분
	{
		return ChainIterator(0);
	}

};

class Polynomial {
public:
	struct Term
	{
		float coef;
		int exp;
		Term Set(float c, int e)
		{
			coef = c;
			exp = e;
			return *this;
		}
	};

	Polynomial();
	Polynomial operator+(Polynomial &b); //a+p.a b+p.a c+p.a
	Polynomial operator*(Polynomial &b);
	void InsertTerm(Term &term);
	float Eval(float x);
	friend ostream &operator<<(ostream &os, Polynomial &p);
	friend istream &operator>>(istream &is, Polynomial &p);

private:
	Chain<Term> poly;
	float evalresult;
};

Polynomial::Polynomial() {
}

void Polynomial::InsertTerm(Term &term) {
	Polynomial::poly.InsertBack(term);
}

//연산자 오버로딩
Polynomial Polynomial::operator+(Polynomial &b) {
	Term temp;
	Chain<Term>::ChainIterator ai = Polynomial::poly.begin();
	Chain<Term>::ChainIterator bi = b.poly.begin();
	Polynomial c;
	while (ai != NULL && bi != NULL)
	{
		if (ai->exp == bi->exp)
		{
			float sum = ai->coef + bi->coef;
			if (sum) {
				c.poly.InsertBack(temp.Set(sum, ai->exp));
			}
			ai++;
			bi++;
		}
		else if (ai->exp < bi->exp)
		{
			c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
			bi++;
		}
		else
		{
			c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
			ai++;
		}
	}
	while (ai != 0)
	{
		c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
		ai++;
	}
	while (bi != 0)
	{
		c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
		bi++;
	}
	return c;
}

Polynomial Polynomial::operator*(Polynomial &b) {
	Term temp;
	Chain<Term>::ChainIterator ai = Polynomial::poly.begin();
	Chain<Term>::ChainIterator bi = b.poly.begin();
	Polynomial d;
	while (ai != NULL)
	{
		while (bi != NULL)
		{
			Polynomial c;
			float coef_sum = ai->coef * bi->coef;
			int exp_sum = ai->exp + bi->exp;
			c.poly.InsertBack(temp.Set(coef_sum, exp_sum));
			d = c + d;
			bi++;
		}
		bi = b.poly.begin();
		ai++;
	}

	return d;
}

float Polynomial::Eval(float x) {
	float result = 0;
	Chain<Term>::ChainIterator ai = Polynomial::poly.begin();
	while (ai != 0)
	{
		float temp = 1;
		cout << ai->coef << " " << ai->exp << endl;
		for (int i = 0; i < ai->exp; i++)
		{
			temp *= x;
		}
		result += ai->coef*temp;
		ai++;
	}
	evalresult = result;
	return result;
}

ostream &operator<<(ostream &os, Polynomial &p) {

	Chain<Polynomial::Term>::ChainIterator i = p.poly.begin();
	while (1)
	{
		Polynomial::Term term = i.getData();
		if (term.exp == 0) {
			os << term.coef;
		}
		else if (term.exp == 1)
			os << term.coef << "x";
		else
			os << term.coef << "x^" << term.exp;
		if (++i != p.poly.end()) {
			os << "+";
		}
		else {
			os << " ";
			break;
		}
	}
	return os;
}

istream &operator>>(istream &is, Polynomial &p)
{

	string lhs; // 다항식 1
	char term_seps[] = "+";
	char *term_token;
	float coef_term;
	float coef_float_term;
	int exp_term;
	int i = 0;

	is >> lhs;
	lhs = ReplaceAll(lhs, "-", "+-");
	term_token = strtok(&lhs[0], term_seps);
	while (term_token != NULL)
	{
		if (term_token[0] == '-') {
			if (term_token[1] == 'x') {
				coef_term = -1;
				exp_term = 0;
				if (strstr(term_token, "^")) {
					exp_term = atoi(&term_token[2]);
				}
				else if (strstr(term_token, "x")) {
					exp_term = 1;
				}
				else {
					exp_term = 0;
				}
			}
			else {
				if (strstr(term_token, ".")) {
					coef_term = atoi(&term_token[1]);
					coef_float_term = atoi(&term_token[3]);
					coef_term = (coef_term + coef_float_term*0.1)*(-1);
					if (strstr(term_token, "^")) {
						exp_term = atoi(&term_token[6]);
					}
					else if (strstr(term_token, "x")) {
						exp_term = 1;
					}
					else {
						exp_term = 0;
					}
				}
				else
				{
					coef_term = atoi(&term_token[1])*(-1);
					exp_term = 0;
					if (strstr(term_token, "^")) {
						exp_term = atoi(&term_token[4]);
					}
					else if (strstr(term_token, "x")) {
						exp_term = 1;
					}
					else {
						exp_term = 0;
					}
				}
			}
		}
		else if (term_token[0] == 'x') {
			coef_term = 1;
			exp_term = 0;
			if (strstr(term_token, "^")) {
				exp_term = atoi(&term_token[2]);
			}
			else if (strstr(term_token, "x")) {
				exp_term = 1;
			}
			else {
				exp_term = 0;
			}
		}
		else {
				if (strstr(term_token, ".")) {
					coef_term = atoi(&term_token[0]);
					coef_float_term = atoi(&term_token[2]);
					coef_term = coef_term + coef_float_term*0.1;
					if (strstr(term_token, "^")) {
						exp_term = atoi(&term_token[5]);
					}
					else if (strstr(term_token, "x")) {
						exp_term = 1;
					}
					else {
						exp_term = 0;
					}
				}
				else {
					coef_term = atoi(&term_token[0]);
					if (strstr(term_token, "^")) {
						exp_term = atoi(&term_token[3]);
					}
					else if (strstr(term_token, "x")) {
						exp_term = 1;
					}
					else {
						exp_term = 0;
					}
				}
		}
		Polynomial::Term temp;
		temp.exp = exp_term;
		temp.coef = coef_term;
		p.InsertTerm(temp);
		term_token = strtok(NULL, term_seps);
	}
	return is;
}



int main() {
	
	int i = 0;
	int T; // testcase 갯수
	int choice;
	int variable;
	cin >> T;
	Polynomial* a = new Polynomial[T];
	Polynomial* b = new Polynomial[T];
	Polynomial* result = new Polynomial[T];
	int* evaluations = new int[T];

	while (i < T) {
		cin >> a[i];
		cin >> b[i];
		cin >> variable;
		cin >> choice;
		if (choice == 1)
			result[i] = a[i] + b[i];
		else if(choice == 2)
			result[i] = a[i] * b[i];
		evaluations[i] = result[i].Eval(variable);
		i++;
	}

	for (i = 0; i < T; i++) {
		cout << result[i];
		cout << evaluations[i] << endl;
	}
	system("pause");
}