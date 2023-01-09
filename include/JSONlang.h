#include <jsonlang/values/array.h>
#include <jsonlang/values/boolean.h>
#include <jsonlang/values/null.h>
#include <jsonlang/values/number.h>
#include <jsonlang/values/object.h>
#include <jsonlang/values/string.h>

using namespace jsonlang::values;

#define STR(S) #S

#define STRING(X) String(X)

#define NUMBER(X) Number(X)

#define TRUE Boolean(true)
#define FALSE Boolean(false)

#undef NULL
#define NULL Null()

#define OBJECT Object
#define KEY(X) Object::Key(STR(X)) <<= (false) ? (Value::Void())

#define ARRAY Array()
