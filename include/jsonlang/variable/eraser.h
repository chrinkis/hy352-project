#pragma once

namespace jsonlang {
namespace variable {

class Variable;

class Eraser {
 public:
  Eraser& operator<<(const Variable& variable);
};

}  // namespace variable
}  // namespace jsonlang
