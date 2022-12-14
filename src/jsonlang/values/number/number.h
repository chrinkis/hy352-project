#pragma once

#include <cstddef>
#include "../value.h"

namespace jsonlang {
namespace values {
namespace number {

class Number : public Value {
  float data;

 private:
  Number(const Number& other);

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
  bool operator==(const Number& other) const;
  bool operator!=(const Number& other) const;

 public:
  int get_size() const;
  bool is_emtpy() const;
  bool has_key(const std::string& key) const;
  const char* get_type() const;

  operator std::string() const;

  Number* clone_to_heap() const;
  bool is_equal_to(const Value& other) const;

 public:
  Number(std::nullptr_t null);
};

}  // namespace number
}  // namespace values
}  // namespace jsonlang
