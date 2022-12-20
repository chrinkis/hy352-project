#include <values/number.h>

#include <cassert>
#include <string>

using namespace jsonlang::values;

Number::Number(const float _data) : data(_data) {}

Number::Number(const Number& other) : data(other.data) {}

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
  return Number(static_cast<int>(this->data) % static_cast<int>(other.data));
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

bool Number::operator==(const Number& other) const {
  return (this->data == other.data);
}

bool Number::operator!=(const Number& other) const {
  return (this->data != other.data);
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

Number* Number::clone_to_heap() const {
  return new Number(*this);
}

bool Number::is_equal_to(const Value& other) const {
  const Number* other_number = dynamic_cast<const Number*>(&other);

  if (!other_number) {
    return false;
  }

  return this->data == other_number->data;
}

Number::Number(Value::Void) {
  assert(0);
}
