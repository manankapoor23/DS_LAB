#include <iostream>
#include <vector>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;

public:
    Tree(int a)
    {
        this->data = a;
        this->left = NULL;
        this->right = NULL;
    }
};
vector<int> store;

void inorder(Tree *t, vector<int> &store)
{
    if (t == NULL)
    {
        return;
    }
    inorder(t->left, store);
    inorder(t->right, store);
    store.push_back(t->data);
}

int main()
{
    Tree *root = new Tree(10);
    root->left = new Tree(5);
    root->right = new Tree(15);
    vector<int> store;
    inorder(root, store);

    for (int x : store)
        cout << x << " ";
}
