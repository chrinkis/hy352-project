#pragma once

#include <string>

namespace jsonlang {
namespace values {
namespace object {

class Key {
  const std::string key;

 public:
  Key(const std::string& key);

  std::string get_key() const;

  bool operator<(const Key& other) const;
};

}  // namespace object
}  // namespace values
}  // namespace jsonlang
