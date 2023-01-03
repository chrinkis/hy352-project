#pragma once

#include <jsonlang/collections/sequence.h>
#include <jsonlang/values/value.h>
#include <jsonlang/variable/appender.h>
#include <memory>
#include <string>

namespace jsonlang {
namespace variable {

class Variable {
  friend class Appender;

 public:
  using ValuePtr = std::shared_ptr<values::Value>;
  using ValuePtrSequence = collections::Sequence<ValuePtr>;

 private:
  ValuePtr value;

 private:
  ValuePtr parent;
  int index_int = -1;
  std::string index_str;

 private:
  Variable(const ValuePtr& _value, ValuePtr _parent, const std::string& _index);
  Variable(const ValuePtr& _value, ValuePtr _parent, int _index);

 public:
  Variable(const values::Value& value);
  Variable(const Variable& other);

 public:
  const values::Value& get_value() const;

 public:
  Variable& operator=(const values::Value& value);
  Appender operator+=(const values::Value& value);
  Variable operator[](const std::string& _index) const;
  Variable operator[](int _index) const;
  void erase();
};

Variable operator+(const Variable& left, const Variable& right);
Variable operator-(const Variable& left, const Variable& right);
Variable operator*(const Variable& left, const Variable& right);
Variable operator/(const Variable& left, const Variable& right);
Variable operator%(const Variable& left, const Variable& right);

// `bool` or `values::Boolean` ?
bool operator>(const Variable& left, const Variable& right);
bool operator>=(const Variable& left, const Variable& right);
bool operator<(const Variable& left, const Variable& right);
bool operator<=(const Variable& left, const Variable& right);

bool operator&&(const Variable& left, const Variable& right);
bool operator||(const Variable& left, const Variable& right);
bool operator!(const Variable& left);

bool operator==(const Variable& left, const Variable& right);
bool operator!=(const Variable& left, const Variable& right);

}  // namespace variable
}  // namespace jsonlang
