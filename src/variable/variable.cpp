#include <variable/variable.h>

using namespace jsonlang::variable;

Variable& Variable::operator=(const values::Value& value) {
  this->value = ValuePtr(value.clone_to_heap());
  this->parent = ValuePtr();
  this->index_int = -1;
  this->index_str = std::string();

  return *this;
}

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
