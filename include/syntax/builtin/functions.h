#pragma once

#include <jsonlang/values/boolean.h>
#include <jsonlang/values/number.h>
#include <jsonlang/values/string.h>
#include <jsonlang/values/value.h>
#include <jsonlang/variable/variable.h>

using namespace jsonlang::values;
using namespace jsonlang::variable;

// Use variable args in order to support `,` inside the macros

#define SIZE_OF(...) size_of(__VA_ARGS__)

#define IS_EMPTY(...) is_empty(__VA_ARGS__)

#define HAS_KEY(...) has_key(__VA_ARGS__)

#define TYPE_OF(...) type_of(__VA_ARGS__)

String type_of(const Value& value) {
  return String(value.get_type());
}

String type_of(const Variable& variable) {
  return String(variable.get_value().get_type());
}

Boolean has_key(const Value& value, const std::string& key) {
  return Boolean(value.has_key(key));
}

Boolean has_key(const Variable& variable, const std::string& key) {
  return Boolean(variable.get_value().has_key(key));
}

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
