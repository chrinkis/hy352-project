#include <values/value.h>

using namespace jsonlang::values;

Value::SharedPtr Value::get(int i) const {
  throw errors::UnsupportedOperation();
}

Value::SharedPtr Value::get(const std::string& key) const {
  throw errors::UnsupportedOperation();
}

void Value::append(const Value& value) {
  throw errors::UnsupportedOperation();
}

void Value::set_at(const std::string& index, const Value& value) {
  throw errors::UnsupportedOperation();
}

void Value::set_at(const int index, const Value& value) {
  throw errors::UnsupportedOperation();
}

void Value::remove(const std::string& index) {
  throw errors::UnsupportedOperation();
}

void Value::remove(const int index) {
  throw errors::UnsupportedOperation();
}

void Value::clear() {
  throw errors::UnsupportedOperation();
}

Value::Sequence Value::operator,(const Value& other) {
  return (Sequence(), SharedPtr(this->clone_to_heap()),
          SharedPtr(other.clone_to_heap()));
}

bool Value::neq_op(const Value& other) const {
  return !this->eq_op(other);
}

bool Value::gt_op(const Value& other) const {
  throw errors::UnsupportedOperation();
}

bool Value::ge_op(const Value& other) const {
  throw errors::UnsupportedOperation();
}

bool Value::lt_op(const Value& other) const {
  throw errors::UnsupportedOperation();
}

bool Value::le_op(const Value& other) const {
  throw errors::UnsupportedOperation();
}

Value::Ptr Value::add_op(const Value& other) const {
  throw errors::UnsupportedOperation();
}

Value::Ptr Value::sub_op(const Value& other) const {
  throw errors::UnsupportedOperation();
}

Value::Ptr Value::mul_op(const Value& other) const {
  throw errors::UnsupportedOperation();
}

Value::Ptr Value::div_op(const Value& other) const {
  throw errors::UnsupportedOperation();
}

Value::Ptr Value::mod_op(const Value& other) const {
  throw errors::UnsupportedOperation();
}

bool Value::not_op() const {
  throw errors::UnsupportedOperation();
}

bool Value::and_op(const Value& other) const {
  throw errors::UnsupportedOperation();
}

bool Value::or_op(const Value& other) const {
  throw errors::UnsupportedOperation();
}

namespace jsonlang {
namespace values {

Value::Sequence operator,(Value::Sequence seq, const Value& val) {
  return (seq, Value::SharedPtr(val.clone_to_heap()));
}

std::ostream& operator<<(std::ostream& out, const Value& val) {
  return out << std::string(val);
}

}  // namespace values
}  // namespace jsonlang
