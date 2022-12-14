#include "array.h"

#include <cassert>
#include <memory>
#include <vector>

collections::Sequence<std::shared_ptr<jsonlang::values::Value> >& operator,(
    collections::Sequence<std::shared_ptr<jsonlang::values::Value> >& seq,
    const jsonlang::values::Value& val) {
  auto value_clone = val.clone_to_heap();
  std::shared_ptr<jsonlang::values::Value> value_clone_shared_ptr(value_clone);

  return (seq, value_clone_shared_ptr);
}

using namespace jsonlang::values;
using namespace jsonlang::values::array;

Array::Array(const Array& other) {
  for (auto current_value : other.data) {
    auto current_value_clone = current_value->clone_to_heap();
    ValuePtr current_value_clone_shared_ptr(current_value_clone);
    this->data.push_back(current_value_clone_shared_ptr);
  }
}

Array::Array() : data(std::vector<std::shared_ptr<Value> >()) {}

Array Array::operator[](const Value& single_data) {
  auto data_clone = single_data.clone_to_heap();
  ValuePtr data_clone_shared_ptr(data_clone);
  this->data.push_back(data_clone_shared_ptr);

  return *this;
}

// should be const
Array Array::operator[](Sequence_of_ValuePtrs& data_sequence) {
  for (auto current_value : data_sequence) {
    this->data.push_back(current_value);
  }

  return *this;
}

Value& Array::operator[](const int index) const {
  assert(index >= 0);
  assert(index < this->get_size());

  return *this->data[index];
}

Array Array::operator+(const Array& other) const {
  Array first = Array(*this);
  Array second = Array(other);

  for (auto current_value : second.data) {
    first.data.push_back(current_value);
  }

  return first;
}

// TODO:
bool Array::operator==(const Array& other) const {
  if (this->get_size() != other.get_size())
    return false;

  for (int current_index = 0; current_index < this->get_size(); current_index++)
    // if (*this->data[current_index] != *other.data[current_index])
    return false;

  return true;
}

bool Array::operator!=(const Array& other) const {
  return !(*this == other);
}

int Array::get_size() const {
  return this->data.size();
}

bool Array::is_emtpy() const {
  return this->data.empty();
}

bool Array::has_key(const std::string& key) const {
  return false;
}

const char* Array::get_type() const {
  return "array";
}

Array::operator std::string() const {
  std::string return_string = "[";

  for (auto current_value : this->data) {
    return_string += std::string(*current_value) + ",";
  }
  return_string += "]";

  return return_string;
}

Array* Array::clone_to_heap() const {
  return new Array(*this);
}

Array::Array(std::nullptr_t null) {
  assert(0);
}
