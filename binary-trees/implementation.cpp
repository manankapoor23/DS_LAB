#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert into BST
Node* insertBST(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Level order traversal (BFS)
void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

// Inorder (L, Root, R) — sorted for BST
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder (Root, L, R)
void preOrder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Postorder (L, R, Root)
void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    // Insert your numbers into BST
    int values[] = {15, 18, 6, 7, 17, 3, 4, 13, 9, 20, 2};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insertBST(root, values[i]);
    }

    cout << "Level Order (BFS): ";
    levelOrder(root);
    cout << "\n";

    cout << "Inorder (sorted): ";
    inorder(root);
    cout << "\n";

    cout << "Preorder: ";
    preOrder(root);
    cout << "\n";

    cout << "Postorder: ";
    postOrder(root);
    cout << "\n";

    return 0;
}
