#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Node {
	T data;
	Node* next, *prv;
	Node(T _data, Node* _next, Node* _prv) {
		data = _data;
		next = _next;
		prv = _prv;
	}
};

template <class T>
struct Stack {
	Node<T> *dummy1, *dummy2, *tail;
	int size;

	Stack(T data) {
		dummy2 = new Node<T>(data, nullptr, nullptr);
		dummy1 = new Node<T>(data, dummy2, nullptr);
		dummy2->prv = dummy1;
		tail = dummy1;
		size = 0;
	}

	void push(T x) {
		Node<T>* tmp = new Node<T>(x, dummy2, tail);
		tail->next = tmp;
		tail = tmp;
		dummy2->prv = tail;
		size++;
	}

	void pop() {
		if (tail == dummy1)
			return;
		Node<T>* tmp = tail;
		tail = tail->prv;
		tail->next = dummy2;
		dummy2->prv = tail;
		delete tmp;
		size--;
	}

	T top() {
		return tail->data;
	}
};

template <class T>
struct Queue {
	Node<T> * dummy1, * dummy2, * tail, *head;
	int size;

	Queue(T data) {
		dummy2 = new Node<T>(data, nullptr, nullptr);
		dummy1 = new Node<T>(data, dummy2, nullptr);
		dummy2->prv = dummy1;
		head = tail = dummy1;
		size = 0;
	}

	void push(T x) {
		Node<T>* tmp = new Node<T>(x, dummy2, tail);
		tail->next = tmp;
		tail = tmp;
		dummy2->prv = tail;
		if (head == dummy1)
			head = tail;
		size++;
	}

	void pop() {
		if (head == dummy1)
			return;
		Node<T>* tmp = head;
		head = head->next;
		dummy1->next = head;
		head->prv = dummy1;
		delete tmp;
		if (head == dummy2)
			head = tail = dummy1;
		size--;
	}

	T front() {
		return head->data;
	}
};

double toNum(string s) {
	if (s == "0")
		return 0;
	double res1 = 0, res2 = 0;
	int start = 0, sign = 1, n = s.size(), dot = n;
	if (s[0] == '-')
		sign = -1, start++;
	for (int i = start; i < n; i++)
		if (s[i] == '.') {
			dot = i;
			break;
		}
	for (int i = start; i < dot; i++)
		res1 = res1 * 10 + (s[i] - '0');
	for (int i = n - 1; i > dot; i--)
		res2 = res2 / 10 + (s[i] - '0') / 10.0;
	return sign * (res1 + res2);
}

string toString(int n) {
	if (n == 0)
		return "0";
	string res = "";
	while (n) {
		res += char(n % 10 + '0');
		n /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	Stack <int> st(-1);
	st.push(1);
	st.push(2);
	st.push(3);
		
	string s = "";
	getline(cin, s);
	string input[100];
	int i = 0, n = 1;
	input[0] = "(";
	while (i < s.size()) {
		if (s[i] == ' ')
			i++;
		else if (!isdigit(s[i]))
			input[n++] = s[i++];
		else {
			input[n] = "";
			while (i < s.size() && isdigit(s[i]))
				input[n] += s[i++];
			n++;
		}
	}
	input[n++] = ")";
	Stack <string> dau("");
	Queue <string> bieu_thuc("");
	for (int i = 0; i < n; i++) {
		// for (Node<string>* p = dau.dummy1->next; p != dau.dummy2; p = p->next)
		// 	cout << p->data << ' ';
		// cout << endl;
		// cout << input[i] << ' ';
		if (isdigit(input[i][0]))
			bieu_thuc.push(input[i]);
		else {
			if (input[i] == ")") {
				while (dau.size && dau.top() != "(")
					bieu_thuc.push(dau.top()), dau.pop();
				if (dau.size)
					dau.pop();
			}
			else if (input[i] == "(")
				dau.push("(");
			else if (input[i] == "+" || input[i] == "-") {
				while (dau.size && (dau.top() == "*" || dau.top() == "/")) 
					bieu_thuc.push(dau.top()), dau.pop();
				dau.push(input[i]);
			}
			else if (input[i] == "/") {
				dau.push(input[i]);
			}
			else {
				while (dau.size && dau.top() == "/")
					bieu_thuc.push(dau.top()), dau.pop();
				dau.push(input[i]);
			}
		}
	}

	Stack <double> so(-1);
	for (Node <string> *p = bieu_thuc.head; p != bieu_thuc.dummy2; p = p->next) {
		// cerr << p->data << ' ';
		if (!isdigit(p->data[0])) {
			double b = so.top();
			so.pop();
			double a = so.top(); 
			so.pop();
			if (p->data == "+")
				so.push(a + b);
			else if (p->data == "-")
				so.push(a - b);
			else if (p->data == "*")
				so.push(a * b);
			else if (p->data == "/") 
				so.push(a / b);
		}
		else 
			so.push(toNum(p->data));
	}
	cout << so.top();
	return 0;
}