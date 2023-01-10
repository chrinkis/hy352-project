#include <JSONlang.h>

#include <iostream>

PROGRAM_BEGIN
  JSON(bla) = STRING("hello")

  JSON(bla_d) = STRING("hello")

  JSON(object) = OBJECT {
    KEY(title)            :                    STRING("title"),
    KEY(year)        :          NUMBER(2011),
  }

  JSON(array) = ARRAY[
    NUMBER(2022),
    STRING("HY352"),
    OBJECT {
      KEY(ggeo) : STRING("ababab"),
      KEY(tassaron) : NUMBER(4),
    }
  ]

  ;std::cout << std::string(object) << std::endl;
  ;std::cout << std::string(array) << std::endl;

PROGRAM_END
