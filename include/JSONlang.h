#include <jsonlang/values/array.h>
#include <jsonlang/values/boolean.h>
#include <jsonlang/values/null.h>
#include <jsonlang/values/number.h>
#include <jsonlang/values/object.h>
#include <jsonlang/values/string.h>
#include "jsonlang/values/object/key.h"

#define STR(S) #S

#define STRING(X) jsonlang::values::String(X)

#define NUMBER(X) jsonlang::values::Number(X)

#define TRUE jsonlang::values::Boolean(true)
#define FALSE jsonlang::values::Boolean(false)

#undef NULL
#define NULL jsonlang::values::Null()

#define OBJECT jsonlang::values::Object
#define KEY(X) jsonlang::values::object::Key(STR(X)) <<= (false) ? (nullptr)

#define ARRAY jsonlang::values::Array();
