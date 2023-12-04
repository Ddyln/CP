#include <bits/stdc++.h>
using namespace std;
typedef int Key; // non-negative number
#define RED 1
#define BLACK 0
const Key nullKey = -1;
class BSTree
{
private:
    struct Node
    {
        Key key;
        bool color;
        Node *left, *right;
        Node(Key key)
        {
            this->key = key;
            color = RED;
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
    bool Color(link p) {
        if (p == nullptr)
            return BLACK;
        return p->color;
    }
    void assignColor(link& root, bool color) {
        if (root == nullptr)
            return;
        root->color = color;
    }
	void insert(link& root, Key key){
		if(root==nullptr) root = new Node(key);
        if (key == root->key)
            return;
		if (key > root->key) insert(root->right,key);
	    if (key < root->key) insert(root->left,key);

        if (Color(root->right) == RED) {
            leftRotate(root);
            assignColor(root, Color(root->left));
            assignColor(root->left, RED);
        }
        if (Color(root->left) == RED && Color(root->left->left) == RED) {
            rightRotate(root);
            assignColor(root, BLACK);
            assignColor(root->right, RED);
        }
        if (Color(root->left) == RED && Color(root->right) == RED) {
            assignColor(root, RED);
            assignColor(root->left, BLACK);
            assignColor(root->right, BLACK);
        }
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
};
int main()
{
    BSTree tree;

	tree.insert(5);
	tree.insert(1);
	tree.insert(4);
	tree.insert(3);
	tree.insert(2);
    tree.insert(8);
    tree.insert(9);
    tree.insert(7);
    tree.insert(16);
    tree.insert(11);
    tree.insert(12);
    tree.insert(15);
	tree.printTree();
}