#include <variable/appender.h>

#include <variable/variable.h>

using namespace jsonlang::variable;

Appender::Appender(Variable& _variable) : variable(_variable) {}

Appender &Appender::operator,(const values::Value& value) {
  this->variable.value->append(value);

  return *this;
}
