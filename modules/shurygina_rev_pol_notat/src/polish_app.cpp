// Copyright 2022 Kozel Svetlana

#include <exception>
#include <iostream>
#include <string>
#include <stack>
#include "include/polish_notation.h"
#include "include/lexem.h"
#include "include/stack.h"
#include "include/rev_pol_app.h"

std::string Application::operator()(int argc, const char* argv[]) {
  if (argc == 1 || argc > 2) {
    return this->help(argv[0]);
  }
  std::string output {};
  if (argc == 2) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string str = argv[1];
    lex = l1.separatExpressionOnLexems(str);
    output = l1.revPolNot(lex);
  }
  return output;
}

std::string Application::help(const char* appname) {
  return std::string {"Revers Polish notation\nUsage: "}
    + std::string {appname}
    + std::string {" Enter problem <problem>\n        No limits"};
}
