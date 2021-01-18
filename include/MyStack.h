// Copyright 2021 Egor Buzanov

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template <class Type>
class MyStack {
 private:
  int top, size;
  Type *stack;

 public:
  explicit MyStack(int new_size) {
    size = new_size;
    top = 0;
    stack = new Type[size];
  }
  MyStack(const MyStack &copied_obj) {
    size = copied_obj.size;
    top = copied_obj.top;
    stack = new Type[size];
    for (size_t i = 0; i < top; i++) {
      stack[i] = copied_obj.stack[i];
    }
  }
  ~MyStack() { delete[] stack; }
  Type get() const {
    if (top > 0) {
      return stack[top - 1];
    }
    return 0;
  }
  Type pop() {
    if (top > 0) {
      --top;
      return stack[top];
    }
    return 0;
  }
  void push(Type element) {
    if (top < size) {
      stack[top] = element;
      ++top;
    }
  }
  bool isFull() const { return size == top; }
  bool isEmpty() const { return top == 0; }
};

#endif  // INCLUDE_MYSTACK_H_
