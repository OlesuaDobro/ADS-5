// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
template<typename T, int size>
class Tstack {
 private:
    T data[size];
    int top;
 public:
    Tstack(): top(0) {}
    void push(const t& item) {
        if (top <= size-1)
            data[top++] = item;
        else
            resize(2*size);
     throw std:string("Full");
    }
    T pop() {
        if (top > 0)
            return data[--top];
        else
            throw std::string("Empty");
    }
};
#endif  // include_tstack_h_
