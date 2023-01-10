#include <variable/variable.h>
#include <cassert>

using namespace jsonlang::variable;

Variable Variable::operator[](const std::string& index) const {
  Value::SharedPtr value = this->value->get(index);

  return Variable(value, this->value, index);
}

Variable Variable::operator[](int index) const {
  Value::SharedPtr value = this->value->get(index);

  return Variable(value, this->value, index);
}

Variable& Variable::operator=(const values::Value& value) {
  if (this->parent) {
    if (this->index_int == -1) {
      this->parent->set_at(index_str, value);
    } else {
      this->parent->set_at(index_int, value);
    }
  } else {
    this->value = Value::SharedPtr(value.clone_to_heap());
    this->parent = Value::SharedPtr();
    this->index_int = -1;
    this->index_str = std::string();
  }

  return *this;
}

Appender Variable::operator+=(const values::Value& value) {
  Appender appender(*this);

  return (appender, value);
}

const jsonlang::values::Value& Variable::get_value() const {
  return *(this->value);
}

Variable::operator std::string() const {
  assert(this->value);

  return std::string(*this->value);
}

Variable::Variable(const Value::SharedPtr& _value,
                   Value::SharedPtr _parent,
                   const std::string& _index)
    : value(_value), parent(_parent), index_str(_index) {}

Variable::Variable(const Value::SharedPtr& _value,
                   Value::SharedPtr _parent,
                   int _index)
    : value(_value), parent(_parent), index_int(_index) {
  assert(_index >= 0);
  assert(_index < _parent->get_size());
}

Variable::Variable(const values::Value& _value)
    : value(Value::SharedPtr(_value.clone_to_heap())) {}

Variable::Variable(const Variable& other)
    : value(Value::SharedPtr(other.value->clone_to_heap())) {}

void Variable::erase() {
  if (this->parent) {
    if (this->index_int == -1) {
      this->parent->remove(this->index_str);

    } else {
      this->parent->remove(this->index_int);
    }

  } else {
    this->value->clear();
  }
}

Variable::operator Value&() {
  return *this->value;
}

Variable::Variable(const Value::Ptr _value) : value(Value::SharedPtr(_value)) {
  assert(_value);
}

namespace jsonlang {
namespace variable {

Variable operator+(const Variable& left, const Variable& right) {
  return Variable(left.get_value().add_op(right.get_value()));
}

Variable operator-(const Variable& left, const Variable& right) {
  return Variable(left.get_value().sub_op(right.get_value()));
}

Variable operator*(const Variable& left, const Variable& right) {
  return Variable(left.get_value().mul_op(right.get_value()));
}

Variable operator/(const Variable& left, const Variable& right) {
  return Variable(left.get_value().div_op(right.get_value()));
}

Variable operator%(const Variable& left, const Variable& right) {
  return Variable(left.get_value().mod_op(right.get_value()));
}

bool operator>(const Variable& left, const Variable& right) {
  return left.get_value().gt_op(right.get_value());
}

bool operator>=(const Variable& left, const Variable& right) {
  return left.get_value().ge_op(right.get_value());
}

bool operator<(const Variable& left, const Variable& right) {
  return left.get_value().lt_op(right.get_value());
}

bool operator<=(const Variable& left, const Variable& right) {
  return left.get_value().le_op(right.get_value());
}

bool operator&&(const Variable& left, const Variable& right) {
  return left.get_value().and_op(right.get_value());
}

bool operator||(const Variable& left, const Variable& right) {
  return left.get_value().or_op(right.get_value());
}

bool operator!(const Variable& left) {
  return left.get_value().not_op();
}

bool operator==(const Variable& left, const Variable& right) {
  return left.get_value().eq_op(right.get_value());
}

bool operator!=(const Variable& left, const Variable& right) {
  return left.get_value().neq_op(right.get_value());
}

Variable::Value::Sequence operator,(Variable::Value::Sequence seq,
                                    const Variable& var) {
  return (seq, Variable::Value::SharedPtr(var.get_value().clone_to_heap()));
}

Variable::Value::Sequence operator,(const Variable& left,
                                    const Variable& right) {
  return (Variable::Value::Sequence(), left, right);
}

}  // namespace variable
}  // namespace jsonlang
