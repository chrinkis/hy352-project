#pragma once

#include <jsonlang/values/value.h>
#include <jsonlang/variable/variable.h>
#include "jsonlang/values/boolean.h"

using namespace jsonlang::values;
using namespace jsonlang::variable;

Variable operator+(const Value& left, const Value& right) {
  return left.add_op(right);
}

Variable operator-(const Value& left, const Value& right) {
  return left.sub_op(right);
}

Variable operator*(const Value& left, const Value& right) {
  return left.mul_op(right);
}
Variable operator/(const Value& left, const Value& right) {
  return left.div_op(right);
}

Variable operator%(const Value& left, const Value& right) {
  return left.mod_op(right);
}

Boolean operator==(const Value& left, const Value& right) {
  return left.eq_op(right);
}

Boolean operator!=(const Value& left, const Value& right) {
  return left.neq_op(right);
}

Boolean operator>(const Value& left, const Value& right) {
  return left.gt_op(right);
}

Boolean operator>=(const Value& left, const Value& right) {
  return left.ge_op(right);
}

Boolean operator<(const Value& left, const Value& right) {
  return left.lt_op(right);
}

Boolean operator<=(const Value& left, const Value& right) {
  return left.le_op(right);
}

Boolean operator!(const Value& operand) {
  return operand.not_op();
}

Boolean operator&&(const Value& left, const Value& right) {
  return left.and_op(right);
}

Boolean operator||(const Value& left, const Value& right) {
  return left.or_op(right);
}
