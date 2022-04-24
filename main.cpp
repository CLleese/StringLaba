#include <iostream>
#include "String.h"

int main() {
  String string("Hello World");
  String s2("aabb");
  String r = s2;
  String s;
  s = "It's string";

  std::cin >> s;
  std::cout << s + string;
  std::cout << string[5];
  std::cout << string.findIdx("Worl");

  if (s2 < s)
    std::cout << "These strings not equals";

  return 0;

}