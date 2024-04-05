// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
template<typename T, int size>
class Tstack {
private:
    const int Ksize = size;
    T data[size];
    int top;
public:
    Tstack(): top(0) {}
    void push(const T& item) {
        if (top <= size)
            data[top++] = item;
        else
            throw std::string("Full");
    }
    T pop() {
        if (top > 0)
            return data[--top];
        else
            throw std::string("Empty");
    }
};
Tstack<char, 100> stack1;
Tstack<int, 100> stack2;
#endif  // INCLUDE_TSTACK_H_
