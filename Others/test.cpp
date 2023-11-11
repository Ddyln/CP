#include <iostream>
#include <string>
using namespace std;

template <class T>
struct Node {
	T data;
	Node<T>* next = nullptr, * prv = nullptr;
	Node<T>(T _data, Node* _next, Node* _prv) {
		data = _data;
		next = _next;
		prv = _prv;
	}
	Node<T>() {}
};

template <class T>
struct Stack {
	Node<T>* dummy1, * dummy2, * tail;
	int size;
	Stack <T> () {
		dummy2 = new Node<T>;
		dummy1 = new Node<T>;
		dummy2->prv = dummy1;
		tail = dummy1;
		size = 0;
	}
	Stack <T> (T data) {
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
	Node<T>* dummy1, * dummy2, * tail, * head;
	int size;

	Queue <T>() {
		dummy2 = new Node<T>;//(data, nullptr, nullptr);
		dummy1 = new Node<T>;//(data, dummy2, nullptr);
		dummy2->prv = dummy1;
		head = tail = dummy1;
		size = 0;
	}
	Queue <T>(T data) {
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

bool isOperator(string s) {
	return (s == "and" || s == "or" || s == "not" || s == "(" || s == ")");
}

int main() {
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);

	string s = "";
	getline(cin, s);
	string input[100];
	int i = 0, n = 1;
	input[0] = "(";
	while (i < s.size()) {
		if (s[i] == ' ')
			i++;
		else if (s[i] == '(' || s[i] == ')') {
			input[n] = "";
			input[n++] += s[i++];
		}
		else {
			string tmp = "";
			while (i < s.size() && s[i] != ' ' && s[i] != '(' && s[i] != ')')
				tmp += s[i++];
			input[n++] = tmp;
		}
	}
	input[n++] = ")";

	Stack <string> dau;
	Queue <string> bieu_thuc;
	for (int i = 0; i < n; i++) {
		if (isOperator(input[i])) {
			if (input[i] == ")") {
				while (dau.size && dau.top() != "(")
					bieu_thuc.push(dau.top()), dau.pop();
				if (dau.size)
					dau.pop();
			}
			else if (input[i] == "(")
				dau.push("(");
			else if (input[i] == "or") {
				while (dau.size && dau.top() == "and")
					bieu_thuc.push(dau.top()), dau.pop();
				dau.push(input[i]);
			}
			else 
				dau.push(input[i]);
		}
		else {
			bieu_thuc.push(input[i]);
		}
	}

	Stack <Queue <string>> res;
	for (Node <string>* p = bieu_thuc.head; p != bieu_thuc.dummy2; p = p->next) {
		// cout << p->data << ' ';
		if (isOperator(p->data)) {
			Queue <string> a(""), b("");
			b = res.top();
			res.pop();
			a = res.top();
			res.pop();
			if (p->data == "or") {
				for (Node <string>* i = b.head; i != b.dummy2; i = i->next)
					a.push(i->data);
				res.push(a);
			}
			else {
				Queue <string> tmp("");
				for (Node <string>* i = a.head; i != a.dummy2; i = i->next)
					for (Node <string>* j = b.head; j != b.dummy2; j = j->next)
						tmp.push(i->data + " and " + j->data);
				res.push(tmp);
			}
		}
		else {
			Queue <string> tmp("");
			tmp.push(p->data);
			res.push(tmp);
		}
	}

	for (Node <string>* p = res.top().head; p != res.top().dummy2; p = p->next) 
		cout << "(" << p->data << ")" << (p->next == res.top().dummy2 ? "" : " or ");
	return 0;
}