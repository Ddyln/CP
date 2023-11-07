#include <bits/stdc++.h>
using namespace std;
typedef int Key; // non-negative number
const Key nullKey = -1;
class BSTree
{
private:
    struct Node
    {
        Key key;
        Node *left, *right;
        Node(Key key)
        {
            this->key = key;
            left = nullptr;
            right = nullptr;
        }
    };
    typedef Node *link;

private:
    int size = 0;
    link root;

public:
    BSTree()
    {
        root = nullptr;
    }
    void printTree(link t, int h)
    {
        if (t == nullptr)
        {
            for (int i = 0; i < h; i++)
                cout << "   ";
            cout << "*  " << endl;
            return;
        }
        printTree(t->right, h + 1);
        for (int i = 0; i < h; i++)
            cout << "   ";
        cout << t->key << endl;
        printTree(t->left, h + 1);
    }
    void printTree()
    {
        printTree(root, 0);
    }
	void insert(link& root, Key key){
		if(root==nullptr) root = new Node(key);
		else if(key > root->key ) insert(root->right,key);
		else insert(root->left,key);
	}
    void insert(Key key)
    {
        size++;
    	insert(root,key);
    }
	void rightRotate(link& h) {
		link x = h->left;
		h->left = x->right;
		x->right = h;
		h = x;
	}
	void leftRotate(link& h) {
		link x = h->right;
		h->right = x->left;
		x->left = h;
		h = x;
	}
	void insertAtRoot(link &root, Key key) {
		if(root==nullptr) {
			root = new Node(key);
			return;
		}
		bool insertLeft = 0;
		if(key > root->key ) insertAtRoot(root->right,key);
		else {
			insertAtRoot(root->left,key);
			insertLeft = 1;
		}
		if (insertLeft) 
			rightRotate(root);
		else
			leftRotate(root);
	}
	void insertAtRoot(Key key) {
        size++;
		insertAtRoot(root, key);
	}
    void makeList(link& root) {
        if (root == nullptr)
            return;
        while (root->left != nullptr)
            rightRotate(root);
        makeList(root->right);
    }
    void DSW_rotate(link &root, int times) {
        if (!times)
            return;
        leftRotate(root);
        DSW_rotate(root->right, --times);
    }
    void DSW() {
        makeList(root);
        int n = size;
        int m = pow(2, (int)log2(n + 1)) - 1;
        DSW_rotate(root, n - m);
        while (m > 1) {
            m = m / 2;
            DSW_rotate(root, m);
        }
    }
};
int main()
{
    BSTree tree;

	tree.insert(4);
	tree.insert(3);
	tree.insert(5);
	tree.insert(1);
	tree.insert(2);
    tree.insert(7);
    tree.insert(9);
    tree.insert(8);
    tree.DSW();
	tree.printTree();
}