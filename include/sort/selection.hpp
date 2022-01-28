#ifndef SELECTION_H_INCLUDED
#define SELECTION_H_INCLUDED

#include <iterator>
#include <functional>
#include <ranges>

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

namespace ranges {

struct selection_fn {
  template <std::random_access_iterator I, std::sentinel_for<I> S, typename Comp = std::ranges::less, typename Proj = std::identity>
    requires std::sortable<I, Comp, Proj>

  constexpr I operator()(I first, S last, Comp comp = {}, Proj proj = {}) const {
    if (first == last)
      return first;

    std::size_t N = std::ranges::distance(first, last);
    I last_iter = std::ranges::next(first, last);

    for (std::size_t i = 0; i < N; ++i) {
      std::size_t min = i;
      for (std::size_t j = i + 1; j < N; ++j) {
        if (std::invoke(comp, std::invoke(proj, *(first + j)), std::invoke(proj, *(first + min)))) {
          min = j;
        }
      }
      std::iter_swap((first + i), (first + min));
    }

    return last_iter;
  }

  template <std::ranges::random_access_range R, class Comp = std::ranges::less, class Proj = std::identity>
    requires std::sortable<std::ranges::iterator_t<R>, Comp, Proj>
  constexpr std::ranges::borrowed_iterator_t<R> operator()(R &&r, Comp comp = {}, Proj proj = {}) const {
    return (*this)(std::ranges::begin(r), std::ranges::end(r), std::move(comp), std::move(proj));
  }
};

inline constexpr selection_fn selection;

} // namespace ranges

} // namespace sort

#endif
