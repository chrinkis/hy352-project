#include "number.h"
#include <string>

using namespace jsonlang::values::number;

Number::Number(const float _data) : data(_data) {}

Number Number::operator+(const Number& other) const {
  return Number(this->data + other.data);
}

Number Number::operator-(const Number& other) const {
  return Number(this->data - other.data);
}
Number Number::operator*(const Number& other) const {
  return Number(this->data * other.data);
}

Number Number::operator/(const Number& other) const {
  return Number(this->data / other.data);
}

Number Number::operator%(const Number& other) const {
  // float numbers do not allow modulo operator ("%").
  return Number((int)this->data % (int)other.data);
}

bool Number::operator>(const Number& other) const {
  return (this->data > other.data);
}

bool Number::operator>=(const Number& other) const {
  return (this->data >= other.data);
}

bool Number::operator<(const Number& other) const {
  return (this->data < other.data);
}

bool Number::operator<=(const Number& other) const {
  return (this->data <= other.data);
}

int Number::get_size() const {
  return 1;
}

bool Number::is_emtpy() const {
  return false;
}

bool Number::has_key(const std::string& key) const {
  return false;
}

const char* Number::get_type() const {
  return "number";
}

Number::operator std::string() const {
  return std::to_string(this->data);
}
