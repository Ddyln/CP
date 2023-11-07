#include <iostream>
#include <string>
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
		insertAtRoot(root, key);
	}
};
int main()
{
    BSTree tree;

	tree.insert(5);
	tree.insert(9);
	tree.insert(2);
	tree.insert(1);
	tree.insert(7);
	// tree.insertAtRoot(3);
	tree.printTree();
}