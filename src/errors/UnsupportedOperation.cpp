#include <errors/UnsupportedOperation.h>

using namespace jsonlang::errors;

UnsupportedOperation::UnsupportedOperation()
    : std::invalid_argument("UnsupportedOperation") {}

UnsupportedOperation::UnsupportedOperation(const std::string& what)
    : std::invalid_argument(what) {}
