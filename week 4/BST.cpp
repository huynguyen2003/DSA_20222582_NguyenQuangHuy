#include <iostream>
#include <utility>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(NULL), right(NULL) {}
};

struct BST {
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int val) {
        if (node == NULL)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (node == NULL) return NULL;

        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        } 
        else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        } 
        else {
          
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
          
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } 
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* minNode = findMin(node->right); 
                node->data = minNode->data;          
                node->right = deleteNode(node->right, minNode->data); 
            }
        }
        return node;
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    void inorder(Node* node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void print() {
        inorder(root);
    }
};