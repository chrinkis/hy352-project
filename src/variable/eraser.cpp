#include <variable/eraser.h>
#include <variable/variable.h>

using namespace jsonlang::variable;

Eraser& Eraser::operator<<(const Variable& variable) {
  variable.erase();

  return *this;
}
