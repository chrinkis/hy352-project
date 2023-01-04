#include <variable/variable.h>
#include <cassert>

using namespace jsonlang::variable;

Variable Variable::operator[](const std::string& index) const {
  ValuePtr value = this->value->get(index);

  return Variable(value, this->value, index);
}

Variable Variable::operator[](int index) const {
  ValuePtr value = this->value->get(index);

  return Variable(value, this->value, index);
}

Appender Variable::operator+=(const values::Value& value) {
  Appender appender(*this);

  return (appender, value);
}

Variable::Variable(const ValuePtr& _value,
                   ValuePtr _parent,
                   const std::string& _index)
    : value(_value), parent(_parent), index_str(_index) {}

Variable::Variable(const ValuePtr& _value, ValuePtr _parent, int _index)
    : value(_value), parent(_parent), index_int(_index) {
  assert(_index >= 0);
  assert(_index < _parent->get_size());
}

Variable::Variable(const values::Value& _value)
    : value(ValuePtr(_value.clone_to_heap())) {}

Variable::Variable(const Variable& other)
    : value(ValuePtr(other.value->clone_to_heap())) {}

void Variable::erase() {
  if (this->parent) {
    if (this->index_int == -1) {
      this->parent->remove(this->index_str);

    } else {
      this->parent->remove(this->index_int);
    }

  } else {
    this->value->clear();
  }
}
