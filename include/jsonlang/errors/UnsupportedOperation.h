#pragma once

#include <stdexcept>
#include <string>

namespace jsonlang {
namespace errors {

struct UnsupportedOperation : public std::invalid_argument {
 public:
  UnsupportedOperation();
  UnsupportedOperation(const std::string& what);
};

}  // namespace errors
}  // namespace jsonlang
