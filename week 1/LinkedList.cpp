#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

struct LinkedList {
    Node* head;
    LinkedList() {
    head = NULL; }

    // Truy cập phần tử vị trí i (O(N))
    int get(int pos) {
        Node* cur = head;
        int idx = 0;
        while (cur != NULL && idx < pos) {
            cur = cur->next;
            idx++;
        }
        if (cur == NULL){ 
        return -1;} 
        return cur->data;
    }

    //Chèn vào đầu (O(1))
    void addHead(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    //Chèn vào cuối (O(N))
    void addTail(int x) {
        Node* newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* cur = head;
        while (cur->next != NULL) {
        cur = cur->next;}
        cur->next = newNode;
    }

    //Chèn vào vị trí i (O(N))
    void addAt(int x, int pos) {
        if (pos == 0) { 
        addHead(x); return; }
        Node* cur = head;
        for (int i = 0; cur != NULL && i < pos-1; i++) {
            cur = cur->next;
        }
        if (cur == NULL) 
        return;
        Node* newNode = new Node(x);
        newNode->next = cur->next;
        cur->next = newNode;
    }

    // Xóa phần tử đầu (O(1))
    void delHead() {
        if (head == NULL) 
        return;
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    //Xóa phần tử cuối (O(N))
    void delTail() {
        if (head == NULL){
        return;}
        if (head->next == NULL) { 
        delete head;
        head = NULL; 
        return; }
        Node* cur = head;
        while (cur->next->next != NULL) {
        cur = cur->next;}
        delete cur->next;
        cur->next = NULL;
    }

    //Xóa vị trí i (O(N))
    void delAt(int pos) {
        if (pos == 0) { 
        delHead(); 
        return;}
        Node* cur = head;
        for (int i = 0; cur != NULL && i < pos-1; i++) {
            cur = cur->next;
        }
        if (cur == NULL || cur->next == NULL) return; 
        Node* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
    }

    //Duyệt xuôi (O(N))
    void printForward() {
        Node* cur = head;
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    // Duyệt ngược (O(N))
    void printReverse(Node* cur) {
        if (cur == NULL) return;
        printReverse(cur->next);
        cout << cur->data << " ";
    }
    void printReverseList() {
        printReverse(head);
        cout << endl;
    }
};

int main() {
    LinkedList l;
    l.addHead(10);
    l.addHead(20);
    l.addTail(5);
    l.addAt(15, 1);

    cout << "Duyet xuoi: ";
    l.printForward();

    cout << "Duyet nguoc: ";
    l.printReverseList();

    l.delHead();
    l.delTail();
    cout << "Sau khi xoa: ";
    l.printForward();

    cout << "Phan tu vi tri 1: " << l.get(1) << endl;
    return 0;
}
