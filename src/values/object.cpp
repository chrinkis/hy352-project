#include <values/object.h>

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace jsonlang::values;

Object::Object(std::initializer_list<Pair> pairs) {
  for (Object::Pair pair : pairs) {
    Object::Key key = pair.get_first();
    Object::ValuePtr value_ptr = pair.get_second();

    this->data[key] = value_ptr;
  }
}

Object::Object(const Object& other) {
  for (auto pair : other.data) {
    Object::Key key = pair.first;
    Object::ValuePtr value_ptr = pair.second;

    this->data[key] = Object::ValuePtr(value_ptr->clone_to_heap());
  }
}

Value& Object::operator[](const std::string& key) {
  auto result = this->data[Object::Key(key)];

  assert(result);

  return *result;
}

Object Object::operator+(const Object& other) const {
  Object first = Object(*this);
  Object second = Object(other);

  for (auto pair : second.data) {
    first.data[pair.first] = pair.second;
  }

  return first;
}

void Object::set_at(const std::string& index, const Value& value) {
  assert(this->has_key(index));

  this->data[Key(index)] = ValuePtr(value.clone_to_heap());
}

void Object::remove(const std::string& index) {
  assert(this->has_key(index));

  this->data.erase(index);
}

void Object::clear() {
  this->data.clear();
}

int Object::get_size() const {
  return this->data.size();
}

bool Object::is_emtpy() const {
  return this->data.empty();
}

bool Object::has_key(const std::string& key) const {
  auto search = this->data.find(Object::Key(key));

  return search != this->data.end();
}

const char* Object::get_type() const {
  return "object";
}

Object::operator std::string() const {
  std::string result = "{";

  for (auto pair : this->data) {
    result += pair.first.get_key();
    result += ": ";
    result += std::string(*pair.second);
    result += ", ";
  }

  result += "}";

  return result;
}

Value* Object::clone_to_heap() const {
  return new Object(*this);
}

bool Object::eq_op(const Value& other) const {
  const Object* other_object = dynamic_cast<const Object*>(&other);

  if (!other_object) {
    return false;
  }

  if (this->data.size() != other_object->data.size()) {
    return false;
  }

  for (auto pair : this->data) {
    Key key = pair.first;
    ValuePtr value = pair.second;
    ValuePtr other_value;

    try {
      other_value = other_object->data.at(key);
    } catch (std::out_of_range& out_of_range) {
      return false;
    }

    if (!other_value->eq_op(*value)) {
      return false;
    }
  }

  return true;
}

Object::SmartPtr Object::get(const std::string& key) const {
  return this->data.at(Key(key));
}

Object::Object(Value::Void) {
  assert(0);
}

Object::Pair operator<<=(const Object::Key& key, const Value& value) {
  return Object::Pair(key, Object::ValuePtr(value.clone_to_heap()));
}
