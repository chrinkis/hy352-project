#include <values/number.h>

#include <sstream>

#include <cassert>
#include <string>

using namespace jsonlang::values;

Number::Number(const float _data) : data(_data) {}

Number::Number(const Number& other) : data(other.data) {}

int Number::get_size() const {
  return 1;
}

bool Number::is_emtpy() const {
  return false;
}

bool Number::has_key(const std::string& key) const {
  return false;
}

const char* Number::get_type() const {
  return "number";
}

Number::operator std::string() const {
  std::stringstream ss;
  ss << this->data;

  return ss.str();
}

Number* Number::clone_to_heap() const {
  return new Number(*this);
}

bool Number::eq_op(const Value& other) const {
  const Number* other_number = dynamic_cast<const Number*>(&other);

  if (!other_number) {
    throw errors::UnsupportedOperation();
  }

  return (this->data == other_number->data);
}

bool Number::gt_op(const Value& other) const {
  const Number* other_number = dynamic_cast<const Number*>(&other);

  if (!other_number) {
    throw errors::UnsupportedOperation();
  }

  return (this->data > other_number->data);
}

bool Number::ge_op(const Value& other) const {
  const Number* other_number = dynamic_cast<const Number*>(&other);

  if (!other_number) {
    throw errors::UnsupportedOperation();
  }

  return (this->data >= other_number->data);
}

bool Number::lt_op(const Value& other) const {
  const Number* other_number = dynamic_cast<const Number*>(&other);

  if (!other_number) {
    throw errors::UnsupportedOperation();
  }

  return (this->data < other_number->data);
}

bool Number::le_op(const Value& other) const {
  const Number* other_number = dynamic_cast<const Number*>(&other);

  if (!other_number) {
    throw errors::UnsupportedOperation();
  }

  return (this->data <= other_number->data);
}

Number* Number::add_op(const Value& other) const {
  const Number* other_number = dynamic_cast<const Number*>(&other);

  if (!other_number) {
    throw errors::UnsupportedOperation();
  }

  return Number(this->data + other_number->data).clone_to_heap();
}

Number* Number::sub_op(const Value& other) const {
  const Number* other_number = dynamic_cast<const Number*>(&other);

  if (!other_number) {
    throw errors::UnsupportedOperation();
  }

  return Number(this->data - other_number->data).clone_to_heap();
}

Number* Number::mul_op(const Value& other) const {
  const Number* other_number = dynamic_cast<const Number*>(&other);

  if (!other_number) {
    throw errors::UnsupportedOperation();
  }

  return Number(this->data * other_number->data).clone_to_heap();
}

Number* Number::div_op(const Value& other) const {
  const Number* other_number = dynamic_cast<const Number*>(&other);

  if (!other_number) {
    throw errors::UnsupportedOperation();
  }

  return Number(this->data / other_number->data).clone_to_heap();
}

Number* Number::mod_op(const Value& other) const {
  const Number* other_number = dynamic_cast<const Number*>(&other);

  if (!other_number) {
    throw errors::UnsupportedOperation();
  }

  return Number(static_cast<int>(this->data) %
                static_cast<int>(other_number->data))
      .clone_to_heap();
}

Number::Number(Value::Void) {
  assert(0);
}
