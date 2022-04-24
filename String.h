#pragma once
#include <iostream>

class String {
protected:
  char *str;
  int len;

public:
  String();
  String(char *_str);
  String(String &other);

  ~String();

  char* getStr();
  int getLen() const;
  int setLen(const char *_str);

  String operator+(const String& str);
  String& operator=(char* a);
  bool operator==(const String& a) const;
  bool operator<(const String& a) const;
  bool operator>(const String& a) const;
  char operator[](int a);

  int findIdx(char *_str);
  char** split(char c);

  friend std::ostream &operator<<(std::ostream &out, const String& str);
  friend std::istream &operator>>(std::istream &in, String &a);

  //методы доп заданий
  char* multiplyStr();

};