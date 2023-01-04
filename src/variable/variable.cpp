#include <variable/variable.h>

using namespace jsonlang::variable;

Variable Variable::operator[](const std::string& index) const {
  ValuePtr value = this->value->get(index);

  return Variable(value, this->value, index);
}

Variable Variable::operator[](int index) const {
  ValuePtr value = this->value->get(index);

  return Variable(value, this->value, index);
}

Appender Variable::operator+=(const values::Value& value) {
  Appender appender(*this);

  return (appender, value);
}

Variable operator+(const Variable& left, const Variable& right) {
  return Variable(*left.get_value().add_op(right.get_value()));
}

Variable operator-(const Variable& left, const Variable& right) {
  return Variable(*left.get_value().sub_op(right.get_value()));
}

Variable operator*(const Variable& left, const Variable& right) {
  return Variable(*left.get_value().mul_op(right.get_value()));
}

Variable operator/(const Variable& left, const Variable& right) {
  return Variable(*left.get_value().div_op(right.get_value()));
}

Variable operator%(const Variable& left, const Variable& right) {
  return Variable(*left.get_value().mod_op(right.get_value()));
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
