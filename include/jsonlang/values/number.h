#pragma once

#include <jsonlang/values/value.h>

namespace jsonlang {
namespace values {

class Number : public Value {
  float data;

 public:  // TODO private
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
  int get_size() const override;
  bool is_emtpy() const override;
  bool has_key(const std::string& key) const override;
  const char* get_type() const override;

  operator std::string() const override;

  Number* clone_to_heap() const override;
  bool eq_op(const Value& other) const override;

  bool gt_op(const Value& other) const override;
  bool ge_op(const Value& other) const override;
  bool lt_op(const Value& other) const override;
  bool le_op(const Value& other) const override;

  Number* add_op(const Value& other) const override;
  Number* sub_op(const Value& other) const override;
  Number* mul_op(const Value& other) const override;
  Number* div_op(const Value& other) const override;
  Number* mod_op(const Value& other) const override;

 public:
  Number(Value::Void);
};

}  // namespace values
}  // namespace jsonlang
