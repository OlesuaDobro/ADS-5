// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
template<typename T, int size>
class Tstack {
 private:
    const int Ksize = size;
    T data[100];
    int top;

 public:
    Tstack(): top(0) {}
    T get() {
     if (!isEmpty()) {
            return arr[top - 1];
        } else {
            throw std::string("Empty");
        }
}
bool isEmpty() {
        return top == 0;
    }
    bool isFull() {
        return top == size - 1;
    }
    T pop() {
        if (top > 0)
            return data[--top];
    } else {
            throw std::string("Empty");
    }
}
    void push(const T& item) {
        if (top <= size - 1) {
            arr[top++] = item;
        } else {
            throw std::string("Full");
        }
    }
Tstack<char, 100> stack1;
Tstack<int, 100> stack2;
#endif  // INCLUDE_TSTACK_H_
