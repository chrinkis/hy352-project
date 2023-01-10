#pragma once

#include <jsonlang/values/boolean.h>
#include <jsonlang/values/number.h>
#include <jsonlang/values/value.h>
#include <jsonlang/variable/variable.h>

using namespace jsonlang::values;
using namespace jsonlang::variable;

#define SIZE_OF(val_or_var) size_of(val_or_var)

#define IS_EMPTY(val_or_var) is_empty(val_or_var)

#define HAS_KEY  // TODO

#define TYPE_OF  // TODO

Boolean is_empty(const Value& value) {
  return Boolean(value.is_emtpy());
}

Boolean is_empty(const Variable& variable) {
  return Boolean(variable.get_value().is_emtpy());
}

Number size_of(const Value& value) {
  return Number(value.get_size());
}

Number size_of(const Variable& variable) {
  return Number(variable.get_value().get_size());
}
