#include <JSONlang.h>

JSON(empty_array) = ARRAY
JSON(empty_string) = STRING("")

PROGRAM_BEGIN

// ------------------------variable definition----------------------------------------
  PRINT STRING("-------Variable definitions-------")

  JSON(hello_string) = STRING("hello world!")
  JSON(type_of_Null) = TYPE_OF(NULL)
  JSON(true_boolean) = TRUE
  JSON(student) = OBJECT {
    KEY(name) : STRING("John"),
    KEY(surname) : STRING("Brown"),
    KEY(age) : NUMBER(21),
    KEY(grades) : OBJECT{ KEY(hy352) : NUMBER(8),
                          KEY(hy100) : NUMBER(7),
                          KEY(hy380) : NULL}
  }
  JSON(animal_noises) = ARRAY[STRING("MOO"), STRING("KOKO"), STRING("WOOF")]


  PRINT STRING("empty_array = "), empty_array
  PRINT STRING("empty_string = "), empty_string
  PRINT STRING("hello_string = "), hello_string
  PRINT STRING("type_of_Null = "), type_of_Null
  PRINT STRING("true_boolean = "), true_boolean
  PRINT STRING("student = "), student
  PRINT STRING("animal_noises = "), animal_noises


// ------------------------variable assignement---------------------------------------
  PRINT STRING("-------Variable assignment--------")

  PRINT STRING("empty_array = "), empty_array
  SET empty_array[0] ASSIGN NUMBER(0)
  PRINT STRING("(after assignment) empty_array = "), empty_array
  SET empty_array[0] ASSIGN NUMBER(2)
  PRINT STRING("(after assignment) empty_array = "), empty_array
  PRINT STRING("student = "), student
  SET student["grades"]["hy380"] ASSIGN NUMBER(10)
  PRINT STRING("student (after assignment)= "), student

// ------------------------variable append--------------------------------------------
  PRINT STRING("-------Variable append------------")

  PRINT STRING("empty_array = "), empty_array
  SET empty_array APPEND NUMBER(1), NUMBER(2), NUMBER(3), STRING("random string"), TRUE, NULL
  PRINT STRING("empty_array (after append) = "), empty_array
  SET empty_array APPEND STRING("One more value")
  PRINT STRING("empty_array (after append) = "), empty_array

// ------------------------variable erase---------------------------------------------
  PRINT STRING("-------Variable erase-------------")

  PRINT STRING("empty_array = "), empty_array
  ERASE empty_array[2]
  PRINT STRING("empty_array (after delete) = "), empty_array
  ERASE empty_array
  PRINT STRING("empty_array (after delete) = "), empty_array
  PRINT STRING("student = "), student
  ERASE student["grades"]["hy380"] 
  PRINT STRING("student (after delete) = "), student


// ------------------------variable operators---------------------------------------------
  PRINT STRING("-------Variable operators---------")

  PRINT STRING("STRING1 + STRING2 = "), STRING("STRING1") + STRING("STRING2")
  PRINT STRING("[1,some_string,] + [Null] = "), ARRAY[NUMBER(1), STRING("some_string")] + ARRAY[NULL]
  PRINT STRING("10.2 < 32 = "), NUMBER(10.2) < NUMBER(32)
  PRINT STRING("10.2 + 32 = "), NUMBER(10.2) + NUMBER(32)
  PRINT STRING("100 % 30 = "), NUMBER(10.2) % NUMBER(32)
  PRINT STRING("TRUE && FALSE = "), TRUE && FALSE
  PRINT STRING("TRUE || FALSE = "), TRUE || FALSE
  JSON(var) = NUMBER(10.2) + NUMBER(32)
  PRINT STRING("var = 10.2 + 32 = "), var


// ------------------------variable functions---------------------------------------------
  PRINT STRING("-------Variable functions---------")

  PRINT STRING("Size of "), student, STRING(" : "), SIZE_OF(student)
  PRINT STRING("Size of "), ARRAY[NULL, NULL], STRING(" : "), SIZE_OF((ARRAY[NULL,NULL]))
  PRINT STRING("Size of "), NULL, STRING(" : "), SIZE_OF(NULL)
  PRINT STRING("Is [] empty? "), IS_EMPTY(ARRAY)
  PRINT STRING("Is {name: someone} empty? "), IS_EMPTY(OBJECT{KEY(name) : STRING("someone")})
  PRINT STRING("Does "), student, STRING(" have key: age? "), HAS_KEY(student, "age")
  PRINT STRING("Does "), student, STRING(" have key: address? "), HAS_KEY(student, "address")
  PRINT STRING("Does "), NUMBER(1), STRING(" have key: address? "), HAS_KEY(NUMBER(1), "address")
  PRINT STRING("Type of "), STRING("hello"), STRING(" : "), TYPE_OF(STRING("hello"))
  PRINT STRING("Type of "), NUMBER(1), STRING(" : "), TYPE_OF(NUMBER(1))
  PRINT STRING("Type of "), TRUE, STRING(" : "), TYPE_OF(TRUE)
  PRINT STRING("Type of "), FALSE, STRING(" : "), TYPE_OF(FALSE)
  PRINT STRING("Type of "), NULL, STRING(" : "), TYPE_OF(NULL)
  PRINT STRING("Type of "), student, STRING(" : "), TYPE_OF(student)
  PRINT STRING("Type of "), empty_array, STRING(" : "), TYPE_OF(empty_array)

PROGRAM_END
