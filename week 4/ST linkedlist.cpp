#include <iostream>
#include <utility>
using namespace std;

template <typename Key, typename Value>
struct Node {
    Key key;
    Value value;
    Node* next;

    Node(Key k, Value v) : key(k), value(v), next(NULL) {}
};

template <typename Key, typename Value>
struct SymbolTable {
    Node<Key, Value>* head;
    int count;

    SymbolTable() {
        head = NULL;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    bool contains(Key key) {
        Node<Key, Value>* temp = head;
        while (temp != NULL) {
            if (temp->key == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    Value* get(Key key) {
        Node<Key, Value>* temp = head;
        while (temp != NULL) {
            if (temp->key == key)
                return &(temp->value);
            temp = temp->next;
        }
        return nullptr;
    }

    void put(Key key, Value val) {
        Node<Key, Value>* temp = head;
        while (temp != NULL) {
            if (temp->key == key) {
                temp->value = val;
                return;
            }
            temp = temp->next;
        }

        Node<Key, Value>* newNode = new Node<Key, Value>(key, val);
        newNode->next = head;
        head = newNode;
        ++count;
    }

    void deleteKey(Key key) {
        Node<Key, Value>* temp = head;
        Node<Key, Value>* prev = NULL;
        while (temp != NULL) {
            if (temp->key == key) {
                if (prev == NULL)
                    head = temp->next;
                else
                    prev->next = temp->next;
                delete temp;
                count--;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void print() {
        Node<Key, Value>* temp = head;
        while (temp != NULL) {
            cout << temp->key << " -> " << temp->value << endl;
            temp = temp->next;
        }
    }
};