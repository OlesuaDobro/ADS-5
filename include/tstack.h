// Copyright 2021 NNTU-CS
#ifndef include_tstack_h_
#define include_tstack_h_
#include <string>
template<typename T, int size>
class tstack {
private:
    T data[size];
    int top;
public:
    Tstack(): top(0) {}
    void push(const t& item) {
        if (top <= size-1)
            data[top++] = item;
        else resize(2*size);
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
