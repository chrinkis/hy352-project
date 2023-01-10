#pragma once

#include <jsonlang/collections/sequence.h>
#include <jsonlang/values/value.h>
#include <jsonlang/variable/appender.h>
#include <memory>
#include <ostream>
#include <string>

namespace jsonlang {
namespace variable {

class Variable {
  friend class Appender;

 public:
  using Value = values::Value;

 private:
  Value::SharedPtr value;

 private:
  Value::SharedPtr parent;
  int index_int = -1;
  std::string index_str;

 private:
  Variable(const Value::SharedPtr& _value,
           Value::SharedPtr _parent,
           const std::string& _index);

  Variable(const Value::SharedPtr& _value,
           Value::SharedPtr _parent,
           int _index);

 public:
  Variable(const values::Value& _value);
  Variable(const Value::Ptr _value);
  Variable(const Variable& other);

 public:
  const values::Value& get_value() const;

  operator std::string() const;

 public:
  Variable& operator=(const values::Value& value);
  Appender operator+=(const values::Value& value);
  Variable operator[](const std::string& _index) const;
  Variable operator[](int _index) const;
  void erase() const;

  operator Value&();
};

Variable::Value::Sequence operator,(Variable::Value::Sequence seq,
                                    const Variable& var);

Variable::Value::Sequence operator,(const Variable& left,
                                    const Variable& right);

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

std::ostream& operator<<(std::ostream& out, const Variable& var);

}  // namespace variable
}  // namespace jsonlang
