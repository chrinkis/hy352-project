#pragma once

#include <vector>

namespace collections {

template <typename T>
class Sequence {
  std::vector<T> data;

 public:
  Sequence<T>& operator,(const T& element) {
    this->data.push_back(element);

    return *(this);
  }

 public:
  using Iterator = typename std::vector<T>::iterator;
  using ConstIterator = typename std::vector<T>::const_iterator;

  Iterator begin() { return this->data.begin(); }
  Iterator end() { return this->data.end(); }

  ConstIterator begin() const { return this->data.begin(); }
  ConstIterator end() const { return this->data.end(); }
};

}  // namespace collections
