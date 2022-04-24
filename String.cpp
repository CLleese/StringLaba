#include "String.h"
#include <iostream>

String::String() {
  len = 0;
  str = new char [0];
}

String::String(char *_str) {
  str = _str;
  len = setLen(str);
}


String::String(String &other) {
  str = new char;
  for (int i = 0; i < other.len; i++)
  {
    str[i] = other[i];
  }

  this->len = other.len;
}

String::~String() {
  len = 0;
  str = nullptr;
  delete str;
}


char *String::getStr() {
  return this->str;
}

int String::getLen() const {
  return len;
}

int String::setLen(const char *_str) {
  int count = 0;
  for(int i = 0; _str[i] != '\0'; i++)
  {
    count++;
  }
  ;

  return count;
}


String String::operator+(const String& a) {
  String result;
  result.len = this->len + a.len;
  char *tmpstr = new char[ result.len ];

  for(int i = 0; i < this->len+1; i++)
  {
    tmpstr[i] = this->str[i]; //копируем первую строку
  }
  for(int i = 0; i < a.len + 1; i++)
  {
    tmpstr[ this->len + i ] = a.str[i]; //дописываем вторую сроку в хвост
  }

  result.str = tmpstr;

  tmpstr = nullptr;
  delete[] tmpstr;

  return result;
}

String& String::operator=(char *a) {
  this->str = new char;
  for (int i = 0; i < setLen(a); i++)
  {
    str[i] = a[i];
  }

  this->len = setLen(a);

  return *this;
}

bool String::operator==(const String& a) const {
  if (this->len != a.len) return false;

  for(int i = 0; i < a.len; i++)
  {
    if(this->str[i] != a.str[i]) return false;
  }

  return true;
}


bool String::operator<(const String& a) const {
  if(this->len > a.len) return false;
  else if (this->len < a.len) return true;

  for(int i = 0; i < a.len; i++)
  {
    if (this->str[i] < a.str[i]) return true;
  }
  return false;
}

bool String::operator>(const String &a) const {
  if(this->len < a.len) return false;
  else if (this->len > a.len) return true;

  for(int i = 0; i < a.len; i++)
  {
    if (this->str[i] > a.str[i]) return true;
  }
  return false;
}


char String::operator[](int a) {
  return this->str[a];
}


std::ostream &operator<<(std::ostream &out, const String& a) {
  out << a.str << std::endl;
  return out;
}

std::istream &operator>>(std::istream &in, String &a) {

  char *tmp = new char[255];

  in.getline(tmp, 255);

  a.str = tmp;
  a.setLen(tmp);

  tmp = nullptr;
  delete[] tmp;

  return in;
}




//метод поиска вхождения подслова или символа, возвращает индекс начала входа
int String::findIdx(char *_str) {
  int tmplen = setLen(_str);

  bool flag;
  for(int i = 0; i < this->len; i++)
  {
    flag = true;
    if (this->str[i] == _str[0])
    {
      for(int j = 0; j < tmplen; j++)
      {
        if (this->str[j+i] != _str[j]){
          flag = false;
          break;
        }
        return i;
      }
    }

  }
  if (!flag)
    return 0;
}



//char **String::split(char c) {
//  char* tmpstr = new char;
//  char** array = new char*;
//
//  for (int i = 0; i < this->len; i++) {
//    tmpstr[i] = this->str[i];
//    if(this->str[i] == c) {
//
//    }
//
//  }
//
//  return array;
//}

//методы доп заданий



