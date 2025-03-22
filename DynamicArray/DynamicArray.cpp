class DynamicArray {
private:
    int capacity;
    int length;
    int * arr;

public:
    // constructor
    DynamicArray(int capacity) : capacity(capacity), length(0) {
        arr = new int[capacity];
    }

    // return the element at index i
    // assuming i is a valid index
    int get(int i) {
        return arr[i];
    }

    // overwrite the value at index i
    // assuming i is a valid index
    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(length == capacity) {
            resize();
        }
        arr[length] = n;
        length++;
    }

    int popback() {
        length = length - 1;
        return arr[length];
    }

    void resize() {
        // double the capacity
        capacity = capacity * 2;
        // create a new array with double capacity
        int * newArr = new int[capacity];
        // copy the elements from prev array to new array
        for(int i = 0; i < length; ++i) {
            newArr[i] = arr[i];
        }
        // assign the new array to prev array
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};