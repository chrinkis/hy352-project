#pragma once

#include <jsonlang/values/value.h>

namespace jsonlang {
namespace values {

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
  bool eq_op(const Value& other) const;

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
