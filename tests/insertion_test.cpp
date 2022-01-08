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

TEST_CASE("Insertion: Check return value") {
  std::vector<int> base(1'000);
  std::iota(base.begin(), base.end(), 0);

  auto expected = base;
  auto ret = stdr::sort(expected);
  REQUIRE_EQ(999, *(ret - 1));

  auto test = base;
  auto ret_mine = sort::insertion(begin(test), end(test));
  REQUIRE_EQ(999, *(ret_mine - 1));
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

TEST_CASE("Insertion: Range implementation correctness") {
  std::vector<int> base(1'000);
  stdr::generate(base, engine);

  auto test = base;
  auto expected = base;
  stdr::sort(expected);

  sort::ranges::insertion(test);
  CHECK(stdr::is_sorted(test));

  REQUIRE_EQ(test, expected);
}

TEST_CASE("Insertion: Check range impl. return value") {
  std::vector<int> base(1'000);
  std::iota(base.begin(), base.end(), 0);

  auto expected = base;
  auto ret = stdr::sort(expected);
  REQUIRE_EQ(999, *(ret - 1));

  auto test = base;
  auto ret_mine = sort::ranges::insertion(test);
  REQUIRE_EQ(999, *(ret_mine - 1));
}

TEST_CASE("Insertion: Make use of range projection") {
  using person = std::pair<std::string, std::string>;

  std::vector<person> people{
      {"tintin", "detective"}, {"snowy", "lifeguard"}, {"haddock", "captain"}};

  auto expected = people;
  stdr::sort(expected, std::less{}, &person::first);

  auto test = people;
  sort::ranges::insertion(people, std::less{}, &person::first);

  REQUIRE_EQ(test, expected);
}

TEST_CASE("Insertion: Ranges with predicate") {
  std::vector<int> base(1'000);
  stdr::generate(base, engine);

  auto comp = [](const int i, const int j) -> bool { return i < j; };

  auto expected = base;
  stdr::sort(expected, comp);

  auto test = base;
  sort::ranges::insertion(test, comp);

  REQUIRE_EQ(test, expected);
}

TEST_CASE("Insertion: Ranges impl. reverse sort") {
  std::vector<int> base(1'000);
  stdr::generate(base, engine);

  auto expected = base;
  stdr::sort(expected, std::greater{});

  auto test = base;
  sort::ranges::insertion(test, std::greater{});

  CHECK(stdr::is_sorted(test, std::greater{}));

  REQUIRE_EQ(test, expected);
}
