#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <sort/insertion.hpp>
#include <vector>
#include <random>
#include <execution>
#include <ranges>

namespace stdr = std::ranges;

std::random_device rd;
std::mt19937 engine{rd()};

TEST_CASE("Insertion: Correctness") {
  std::vector<int> iv(1'000);
  stdr::generate(iv, engine);

  auto expected = iv;
  stdr::sort(expected);

  sort::insertion(iv.begin(), iv.end());
  REQUIRE_EQ(iv, expected);
}

TEST_CASE("Insertion: Reverse sort") {
  std::vector<int> base(1'000);
  stdr::generate(base, engine);

  auto expected = base;
  stdr::sort(expected, std::greater{});

  auto test = base;
  sort::insertion(begin(test), end(test), std::greater{});
  CHECK(stdr::is_sorted(test, std::greater{}));

  REQUIRE_EQ(test, expected);
}

TEST_CASE("Insertion: Sort with predicate") {
  std::vector<int> base(1'000);
  stdr::generate(base, engine);

  auto comp = [](const int i, const int j) -> bool { return i < j; };

  auto expected = base;
  stdr::sort(expected, comp);

  auto test = base;
  sort::insertion(begin(test), end(test), comp);

  REQUIRE_EQ(test, expected);
}

TEST_CASE("Insertion: range impl") {
  std::vector<int> base(1'000);
  stdr::generate(base, engine);

  sort::ranges::insertion(base);

  CHECK(stdr::is_sorted(base));
}
