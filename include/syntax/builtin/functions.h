#pragma once

#include <jsonlang/values/boolean.h>
#include <jsonlang/values/value.h>
#include <jsonlang/variable/variable.h>

using namespace jsonlang::values;
using namespace jsonlang::variable;

#define SIZE_OF  // TODO

#define IS_EMPTY(val_or_var) is_empty(val_or_var)

#define HAS_KEY  // TODO

#define TYPE_OF  // TODO

Boolean is_empty(const Value& value) {
  return Boolean(value.is_emtpy());
}

Boolean is_empty(const Variable& variable) {
  return Boolean(variable.get_value().is_emtpy());
}
