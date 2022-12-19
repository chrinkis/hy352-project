#include <values/object/key.h>

#include <string>

using namespace jsonlang::values::object;

Key::Key(const std::string& _key) : key(_key) {}

std::string Key::get_key() const {
  return this->key;
}

bool Key::operator<(const Key& other) const {
  return this->key < other.key;
}
