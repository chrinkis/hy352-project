#include <values/boolean.h>

#include <cassert>

using namespace jsonlang::values;

Boolean::Boolean(const bool _data) : data(_data) {}

Boolean::Boolean(const Boolean& other) : data(other.data) {}

int Boolean::get_size() const {
  return 1;
}
bool Boolean::is_emtpy() const {
  return false;
}
bool Boolean::has_key(const std::string& key) const {
  return false;
}
const char* Boolean::get_type() const {
  return "boolean";
}

Boolean::operator std::string() const {
  return (this->data ? "true" : "false");
}

Boolean* Boolean::clone_to_heap() const {
  return new Boolean(*this);
}

bool Boolean::eq_op(const Value& other) const {
  const Boolean* other_boolean = dynamic_cast<const Boolean*>(&other);

  if (!other_boolean) {
    throw errors::UnsupportedOperation();
  }

  return (this->data == other_boolean->data);
}

bool Boolean::not_op() const {
  return !this->data;
}

bool Boolean::and_op(const Value& other) const {
  const Boolean* other_bool = dynamic_cast<const Boolean*>(&other);

  if (!other_bool) {
    throw errors::UnsupportedOperation();
  }

  return (this->data && other_bool->data);
}

bool Boolean::or_op(const Value& other) const {
  const Boolean* other_bool = dynamic_cast<const Boolean*>(&other);

  if (!other_bool) {
    throw errors::UnsupportedOperation();
  }

  return (this->data || other_bool->data);
}

Boolean::Boolean(Value::Void) {
  assert(0);
}
