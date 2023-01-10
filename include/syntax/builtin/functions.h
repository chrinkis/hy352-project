#pragma once

#include <jsonlang/values/boolean.h>
#include <jsonlang/values/value.h>
#include <jsonlang/variable/variable.h>

using namespace jsonlang::values;
using namespace jsonlang::variable;

#define SIZE_OF  // TODO

#define IS_EMPTY  // TODO

#define HAS_KEY(val_or_var, key) has_key(val_or_var, key)

#define TYPE_OF  // TODO

Boolean has_key(const Value& value, const std::string& key) {
  return Boolean(value.has_key(key));
}

Boolean has_key(const Variable& variable, const std::string& key) {
  return Boolean(variable.get_value().has_key(key));
}
