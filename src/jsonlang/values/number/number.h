#pragma once

#include "../value.h"

namespace jsonlang {
namespace values {
namespace number {

class Number : public Value {
  float data;

 public:
  Number(const float _data);

  Number operator+(const Number& other) const;
  Number operator-(const Number& other) const;
  Number operator*(const Number& other) const;
  Number operator/(const Number& other) const;
  Number operator%(const Number& other) const;
  bool operator>(const Number& other) const;
  bool operator>=(const Number& other) const;
  bool operator<(const Number& other) const;
  bool operator<=(const Number& other) const;

 public:
  int get_size() const;
  bool is_emtpy() const;
  bool has_key(const std::string& key) const;
  const char* get_type() const;

  operator std::string() const;
};

}  // namespace number
}  // namespace values
}  // namespace jsonlang
