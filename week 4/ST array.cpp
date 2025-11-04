#include <iostream>
#include <utility>
using namespace std;

template <typename Key, typename Value>
struct SymbolTable {
    int MAX = 100;
    Key keys[MAX];
    Value values[MAX];
    int count = 0;

    SymbolTable() {
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    bool contains(Key key) {
        for (int i = 0; i < count; i++) {
            if (keys[i] == key)
                return true;
        }
        return false;
    }

    Value* get(Key key) {
        for (int i = 0; i < count; i++) {
            if (keys[i] == key)
                return &values[i];
        }
        return nullptr; 
    }

    void put(Key key, Value value) {
        for (int i = 0; i < count; i++) {
            if (keys[i] == key) {
                values[i] = value;
                return;
            }
        }

        keys[count] = key;
        values[count] = value;
        count++;
    }

    void deleteKey(Key key) {
        for (int i = 0; i < count; i++) {
            if (keys[i] == key) {
                for (int j = i; j < count - 1; j++) {
                    keys[j] = keys[j + 1];
                    values[j] = values[j + 1];
                }
                count--;
                return;
            }
        }
    }

    void print() {
        for (int i = 0; i < count; i++) {
            cout << keys[i] << " -> " << values[i] << endl;
        }
    }
};