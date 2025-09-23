#include <iostream>
using namespace std;

#define MAX 1000

struct List {
    int a[MAX];
    int n; // số phần tử hiện tại
};

// Truy cập
int get(List L, int i) {
    if (i < 0 || i >= L.n) return -1;
    return L.a[i];
}

// Chèn đầu
void insertFirst(List &L, int x) {
    for (int i = L.n; i > 0; i--) L.a[i] = L.a[i-1];
    L.a[0] = x;
    L.n++;
}

// Chèn cuối
void insertLast(List &L, int x) {
    L.a[L.n++] = x;
}

// Chèn tại i
void insertAt(List &L, int i, int x) {
    if (i < 0 || i > L.n) return;
    for (int j = L.n; j > i; j--) L.a[j] = L.a[j-1];
    L.a[i] = x;
    L.n++;
}

// Xóa đầu
void deleteFirst(List &L) {
    for (int i = 0; i < L.n-1; i++) L.a[i] = L.a[i+1];
    L.n--;
}

// Xóa cuối
void deleteLast(List &L) {
    if (L.n > 0) L.n--;
}

// Xóa tại i
void deleteAt(List &L, int i) {
    if (i < 0 || i >= L.n) return;
    for (int j = i; j < L.n-1; j++) L.a[j] = L.a[j+1];
    L.n--;
}

// Duyệt xuôi
void traverseForward(List L) {
    for (int i = 0; i < L.n; i++) cout << L.a[i] << " ";
    cout << endl;
}

// Duyệt ngược
void traverseBackward(List L) {
    for (int i = L.n-1; i >= 0; i--) cout << L.a[i] << " ";
    cout << endl;
}

int main() {
    List L;
    L.n = 0;

    // Chèn cuối
    insertLast(L, 10);
    insertLast(L, 20);
    insertLast(L, 30);
    cout << "Sau khi chèn cuối 10,20,30: ";
    traverseForward(L);

    // Chèn đầu
    insertFirst(L, 5);
    cout << "Sau khi chèn đầu 5: ";
    traverseForward(L);

    // Chèn tại vị trí i
    insertAt(L, 2, 15);
    cout << "Sau khi chèn 15 vào vị trí 2: ";
    traverseForward(L);

    // Xóa đầu
    deleteFirst(L);
    cout << "Sau khi xóa đầu: ";
    traverseForward(L);

    // Xóa cuối
    deleteLast(L);
    cout << "Sau khi xóa cuối: ";
    traverseForward(L);

    // Xóa tại vị trí i
    deleteAt(L, 1);
    cout << "Sau khi xóa tại vị trí 1: ";
    traverseForward(L);

    // Duyệt ngược
    cout << "Duyệt ngược: ";
    traverseBackward(L);

    // Truy cập
    cout << "Phần tử tại vị trí 0 là: " << get(L, 0) << endl;

    return 0;
}
