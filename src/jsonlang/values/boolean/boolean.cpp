#include "boolean.h"

using namespace jsonlang::values::boolean;

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
