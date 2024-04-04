// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
  private:
Tdata[size]:
publick:
TStack():top(0){}
void push(count T&item) {
  if (top <= size-1)
    data[top++]=item;
  else resize(2*size);
  throw std:string("Full");
  Tpop(){
    if(top>0)
      return data[--top];
    else
      throw
        } std::string("Empty");
};
}
}
#endif  // INCLUDE_TSTACK_H_
