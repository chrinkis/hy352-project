#include <values/boolean.h>

#include <cassert>

using namespace jsonlang::values;

Boolean::Boolean(const bool _data) : data(_data) {}

Boolean::Boolean(const Boolean& other) : data(other.data) {}

Boolean Boolean::operator&&(const Boolean& other) const {
  return Boolean(this->data && other.data);
}

Boolean Boolean::operator||(const Boolean& other) const {
  return Boolean(this->data || other.data);
}

Boolean Boolean::operator!() const {
  return Boolean(!this->data);
}

bool Boolean::operator==(const Boolean& other) const {
  return (this->data == other.data);
}

bool Boolean::operator!=(const Boolean& other) const {
  return (this->data != other.data);
}

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
    return false;
  }

  return (this->data == other_boolean->data);
}

bool Boolean::not_op() const {
  return !this->data;
}

bool Boolean::and_op(const Value& other) const {
  assert(dynamic_cast<const Boolean*>(&other));

  const Boolean* other_bool = dynamic_cast<const Boolean*>(&other);

  return (*this && *other_bool).data;
}

bool Boolean::or_op(const Value& other) const {
  assert(dynamic_cast<const Boolean*>(&other));

  const Boolean* other_bool = dynamic_cast<const Boolean*>(&other);

  return (*this || *other_bool).data;
}

Boolean::Boolean(Value::Void) {
  assert(0);
}
