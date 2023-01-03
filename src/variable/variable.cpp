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
                   const std::string& _index) {
  this->value = _value;
  this->parent = _parent;
  this->index_str = _index;
}

Variable::Variable(const ValuePtr& _value, ValuePtr _parent, int _index) {
  assert(_index >= 0);
  assert(_index < _value->get_size());

  this->value = _value;
  this->parent = _parent;
  this->index_int = _index;
}

Variable::Variable(const values::Value& value) {
  this->value = ValuePtr(value.clone_to_heap());
}

Variable::Variable(const Variable& other) {
  this->value = ValuePtr(other.value->clone_to_heap());
}

void Variable::erase() {
  std::string removal_index;

  if (this->index_int == -1) {
    removal_index = this->index_str;
  } else {
    removal_index = std::to_string(this->index_int);
  }

  if (this->parent) {
    this->parent->remove(removal_index);
  } else {
    this->value->clear();
  }
}
