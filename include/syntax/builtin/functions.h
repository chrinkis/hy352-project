#pragma once

#include <jsonlang/values/value.h>
#include <jsonlang/variable/variable.h>

using namespace jsonlang::values;
using namespace jsonlang::variable;

#define SIZE_OF  // TODO

#define IS_EMPTY(val_or_var) is_empty(val_or_var)

#define HAS_KEY  // TODO

#define TYPE_OF  // TODO

bool is_empty(const Value& value) {
  return value.is_emtpy();
}

bool is_empty(const Variable& variable) {
  return variable.get_value().is_emtpy();
}
