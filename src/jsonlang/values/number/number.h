#pragma once

#include "../value.h"

namespace jsonlang {
namespace values {
namespace number {

class Number : public Value {
  float data;

 public:
  Number(const float _data);
  Number(const Number& other);

  Number operator+(const Number& other) const;
  Number operator-(const Number& other) const;
  Number operator*(const Number& other) const;
  Number operator/(const Number& other) const;
  Number operator%(const Number& other) const;
  bool operator>(const Number& other) const;
  bool operator>=(const Number& other) const;
  bool operator<(const Number& other) const;
  bool operator<=(const Number& other) const;
  bool operator==(const Number& other) const;
  bool operator!=(const Number& other) const;

 public:
  int get_size() const;
  bool is_emtpy() const;
  bool has_key(const std::string& key) const;
  const char* get_type() const;

  operator std::string() const;

  Number* clone_to_heap() const;
};

}  // namespace number
}  // namespace values
}  // namespace jsonlang
