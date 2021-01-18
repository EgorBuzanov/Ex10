// Copyright 2021 Egor Buzanov

#include "postfix.h"

#include "MyStack.h"

std::string infix2postfix(std::string infix) {
  std::string postfix;
  MyStack<char> operations_stack(200);
  int i = 0;

  while (i < infix.length()) {
    if (infix[i] != ' ') {
      if (infix[i] >= '0' && infix[i] <= '9') {
        while (infix[i] != ' ' && infix[i] != ')' && i < infix.length()) {
          postfix += infix[i];
          ++i;
        }
        --i;
        postfix += ' ';
      } else {
        if (infix[i] == '(') {
          operations_stack.push(infix[i]);
        } else {
          if (infix[i] == ')') {
            while (operations_stack.get() != '(') {
              postfix += operations_stack.pop();
              postfix += ' ';
            }
            operations_stack.pop();
          } else {
            if (infix[i] == '+' || infix[i] == '-') {
              while (operations_stack.get() == '+' ||
                     operations_stack.get() == '-' ||
                     operations_stack.get() == '*' ||
                     operations_stack.get() == '/') {
                postfix += operations_stack.pop();
                postfix += ' ';
              }
              operations_stack.push(infix[i]);
            } else if (infix[i] == '*' || infix[i] == '/') {
              while (operations_stack.get() == '*' ||
                     operations_stack.get() == '/') {
                postfix += operations_stack.pop();
                postfix += ' ';
              }
              operations_stack.push(infix[i]);
            }
          }
        }
      }
    }
    ++i;
  }
  if (postfix.back() == ' ') {
    postfix.pop_back();
  }
  while (!operations_stack.isEmpty()) {
    postfix += ' ';
    postfix += operations_stack.pop();
  }

  return postfix;
}
