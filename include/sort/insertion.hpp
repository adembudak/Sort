#ifndef INSERTION_H_INCLUDED
#define INSERTION_H_INCLUDED

#include <iterator>
#include <functional>

namespace sort {

template <std::sortable T, typename Compare = std::less<>>
constexpr void insertion(T first, T last, Compare comp = Compare{}) {
  const auto N = std::distance(first, last);

  for (std::size_t i = 1; i < N; ++i) {
    for (std::size_t j = i; j > 0 && comp(*(first + j), *(first + j - 1)); --j) {
      std::iter_swap(first + j, first + j - 1);
    }
  }
}

} // namespace sort

#endif
