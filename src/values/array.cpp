#include <values/array.h>

#include <cassert>
#include <memory>
#include <stdexcept>
#include <string>
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

Array Array::operator[](const Sequence& data_sequence) {
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

Array* Array::add_op(const Value& other) const {
  const Array* other_array = dynamic_cast<const Array*>(&other);

  if (!other_array) {
    throw errors::UnsupportedOperation();
  }

  Array* first = this->clone_to_heap();
  Array second = Array(*other_array);

  for (auto current_value : second.data) {
    first->data.push_back(current_value);
  }

  return first;
}

void Array::append(const Value& value) {
  SharedPtr clone = SharedPtr(value.clone_to_heap());

  this->data.push_back(clone);
}

void Array::set_at(const int index, const Value& value) {
  assert(index >= 0);
  assert(index <= this->get_size());

  if (index < this->data.size()) {
    this->data[index] = SharedPtr(value.clone_to_heap());
  } else if (index == this->data.size()) {
    this->data.push_back(SharedPtr(value.clone_to_heap()));
  } else {
    assert(0);
  }
}

void Array::remove(const int index) {
  assert(index >= 0);
  assert(index < this->get_size());
  this->data.erase(this->data.begin() + index);
}

void Array::clear() {
  this->data.clear();
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
    throw errors::UnsupportedOperation();
  }

  if (this->get_size() != other_array->get_size()) {
    return false;
  }

  try {
    for (int i = 0; i < this->get_size(); i++) {
      if (!this->data[i]->eq_op(*other_array->data[i])) {
        return false;
      }
    }
  } catch (errors::UnsupportedOperation& e) {
    return false;
  }

  return true;
}

Value::SharedPtr Array::get(int i) const {
  return this->data.at(i);
}

Array::Sequence& operator,(Array::Sequence& seq,
                           const jsonlang::values::Value& val) {
  Array::SharedPtr value_clone_shared_ptr(val.clone_to_heap());

  return (seq, value_clone_shared_ptr);
}
