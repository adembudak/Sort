#ifndef INSERTION_H_INCLUDED
#define INSERTION_H_INCLUDED

#include <iterator>
#include <functional>
#include <ranges>

namespace sort {

template <std::sortable T, typename Compare = std::less<>>
constexpr T insertion(T first, T last, Compare comp = {}) {
  const auto N = std::distance(first, last);
  if (first == last)
    return first;

  for (std::size_t i = 1; i < N; ++i) {
    for (std::size_t j = i; j > 0 && comp(*(first + j), *(first + j - 1)); --j) {
      std::iter_swap(first + j, first + j - 1);
    }
  }

  return last;
}

namespace ranges {

struct insertion_fn {
  template <std::random_access_iterator I, std::sentinel_for<I> S,
            typename Comp = std::ranges::less, typename Proj = std::identity>
  requires std::sortable<I, Comp, Proj>
  constexpr I operator()(I first, S last, Comp comp = {}, Proj proj = {}) const {
    if (first == last)
      return first;

    std::size_t N = std::ranges::distance(first, last);

    I last_iter = std::ranges::next(first, last);

    for (std::size_t i = 1; i < N; ++i) {
      for (std::size_t j = i; j > 0 && comp(*(first + j), *(first + j - 1)); --j) {
        std::iter_swap(first + j, first + j - 1);
      }
    }

    return last_iter;
  }

  template <std::ranges::random_access_range R, class Comp = std::ranges::less,
            class Proj = std::identity>
  requires std::sortable<std::ranges::iterator_t<R>, Comp, Proj>
  constexpr std::ranges::borrowed_iterator_t<R> operator()(R &&r, Comp comp = {},
                                                           Proj proj = {}) const {
    return (*this)(std::ranges::begin(r), std::ranges::end(r), std::move(comp), std::move(proj));
  }
};

inline constexpr insertion_fn insertion;

} // namespace ranges

} // namespace sort

#endif
