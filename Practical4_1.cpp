#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;     
    int capacity;  
        capacity = capacity * 2;
        int* newArr = new int[capacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

public:
    DynamicArray() {
        capacity = 2; 
        size = 0;
        arr = new int[capacity];
    }

  
    void insert(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = value;
    }

    
    void deleteAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position\n";
            return;
        }

        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

   
    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    
    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray da;

    da.insert(10);
    da.insert(20);
    da.insert(30);
    da.insert(40);

    cout << "Array: ";
    da.display();

    da.deleteAt(1);

    cout << "After deletion: ";
    da.display();

    return 0;
}