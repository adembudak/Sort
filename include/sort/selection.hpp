#ifndef SELECTION_H_INCLUDED
#define SELECTION_H_INCLUDED

#include <iterator>
#include <functional>

namespace sort {

template <std::sortable T, typename Compare = std::less<>>
constexpr T selection(T first, T last, Compare comp = {}) {
  if (first == last)
    return first;

  const auto N = std::distance(first, last);

  for (std::size_t i = 0; i < N; ++i) {
    std::size_t min = i;
    for (std::size_t j = i + 1; j < N; ++j) {
      if (comp(*(first + j), *(first + min))) {
        min = j;
      }
    }
    std::iter_swap((first + i), (first + min));
  }

  return last;
}

} // namespace sort

#endif
