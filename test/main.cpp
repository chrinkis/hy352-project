#include <JSONlang.h>

JSON(empty_array) = ARRAY
JSON(empty_string) = STRING("")

PROGRAM_BEGIN

/*
  PRINT STRING("empty_array="),empty_array
  PRINT STRING("Is empty_array empty?"),IS_EMPTY(empty_array)
  SET empty_array[0] ASSIGN NUMBER(10)
  PRINT STRING("empty_array after insertion: "),empty_array
  PRINT STRING("Is empty_array empty?"),IS_EMPTY(empty_array)
  */

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

/*
PRINT STRING("empty_array = "), empty_array
SET empty_array[0] ASSIGN NUMBER(0)
PRINT STRING("(after assignment) empty_array = "), empty_array
SET empty_array[0] ASSIGN NUMBER(2)
PRINT STRING("(after assignment) empty_array = "), empty_array
*/

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
//PRINT STRING("10.2 < 32 = "), NUMBER(10.2) < NUMBER(32)
PRINT STRING("10.2 + 32 = "), NUMBER(10.2) + NUMBER(32)
PRINT STRING("100 % 30 = "), NUMBER(10.2) % NUMBER(32)
PRINT STRING("TRUE && FALSE = "), TRUE && FALSE
PRINT STRING("TRUE || FALSE = "), TRUE || FALSE
JSON(var) = NUMBER(10.2) + NUMBER(32)
PRINT STRING("var = 10.2 + 32 = "), var


// ------------------------variable operators---------------------------------------------
PRINT STRING("-------Variable functions---------")

PROGRAM_END
