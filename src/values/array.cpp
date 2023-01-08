#include <values/array.h>

#include <cassert>
#include <memory>
#include <stdexcept>
#include <vector>

using namespace jsonlang::values;

Array::Array(const Array& other) {
  for (auto current_value : other.data) {
    auto current_value_clone = current_value->clone_to_heap();
    SharedPtr current_value_clone_shared_ptr(current_value_clone);
    this->data.push_back(current_value_clone_shared_ptr);
  }
}

Array::Array() : data(std::vector<SharedPtr>()) {}

Array Array::operator[](const Value& single_data) {
  auto data_clone = single_data.clone_to_heap();
  SharedPtr data_clone_shared_ptr(data_clone);
  this->data.push_back(data_clone_shared_ptr);

  return *this;
}

// should be const
Array Array::operator[](Sequence& data_sequence) {
  for (auto current_value : data_sequence) {
    this->data.push_back(current_value);
  }

  return *this;
}

Value& Array::operator[](const int index) const {
  assert(index >= 0);
  assert(index < this->get_size());
  assert(this->get_size() == this->data.size());

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
  /*if (this->get_size() != other.get_size())
    return false;

  for (int current_index = 0; current_index < this->get_size(); current_index++)
     if (*this->data[current_index] != *other.data[current_index])
    return false;
        */

  return this->eq_op(other);
}

Array* Array::add_op(const Value& other) const {
  assert(dynamic_cast<const Array*>(&other));

  const Array* other_array = dynamic_cast<const Array*>(&other);

  return (*this + *other_array).clone_to_heap();
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

Array::Array(Value::Void) {
  assert(0);
}

bool Array::eq_op(const Value& other) const {
  const Array* other_array = dynamic_cast<const Array*>(&other);

  if (!other_array) {
    return false;
  }

  if (this->get_size() != other_array->get_size()) {
    return false;
  }

  for (int current_index = 0; current_index < this->get_size();
       current_index++) {
    SharedPtr value = this->data.at(current_index);
    SharedPtr other_value;

    try {
      other_value = other_array->data.at(current_index);
    } catch (std::out_of_range& out_of_range) {
      return false;
    }

    if (!other_value->eq_op(*value)) {
      return false;
    }
  }

  return true;
}
