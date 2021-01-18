// Copyright 2021 Egor Buzanov

#include <iostream>

#include "postfix.h"

int main() {
  std::string infix = "3 + 4 * 2 / (1 - 5.5) + 1 * 2 * 3 / 6";
  std::cout << infix << std::endl;
  std::string postfix = infix2postfix(infix);
  std::cout << postfix << std::endl;  // 3 4 2 * 1 5.5 - / + 1 2 * 3 * 6 / +
  return 0;
}
