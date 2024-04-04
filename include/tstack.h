// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
template<typename T, int size>
class TStack {
 private:
Tdata[size]:
 public:
TStack():top(0) {}
void push(const T&item) {
  if (top <= size-1)
    data[top++] = item;
  else
    resize(2*size);
  throw std:string("Full");
  Tpop() {
    if (top > )
      return data[--top];
    else
      throw
        std::string("Empty");
}
}
}
#endif  // INCLUDE_TSTACK_H_
