#include <variable/variable.h>

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

namespace jsonlang {
namespace variable {

Variable::ValuePtrSequence operator,(Variable::ValuePtrSequence seq,
                                     const Variable& var) {
  return (seq, Variable::ValuePtr(var.get_value().clone_to_heap()));
}

Variable::ValuePtrSequence operator,(const Variable& left,
                                     const Variable& right) {
  return (Variable::ValuePtrSequence(), left, right);
}

}  // namespace variable
}  // namespace jsonlang
