#include <jsonlang/variable/eraser.h>
#include <jsonlang/variable/variable.h>

using namespace jsonlang::variable;

#define JSON(var) \
  ;               \
  Variable var

#define SET ;

#define ASSIGN =

#define APPEND +=

#define ERASE \
  ;           \
  Eraser() <<
