//
// Copyright (c) 2018 Yannick Schinko
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
//
#include "rngTest/rngUtils.hpp"

std::default_random_engine rng{0};

std::uniform_int_distribution<std::int64_t> int64_rng{std::numeric_limits<std::int64_t>::min(),
                                                      std::numeric_limits<std::int64_t>::max()};
std::uniform_int_distribution<std::uint64_t> uint64_rng{std::numeric_limits<std::uint64_t>::min(),
                                                        std::numeric_limits<std::uint64_t>::max()};
std::uniform_int_distribution<std::int32_t> int32_rng{std::numeric_limits<std::int32_t>::min(),
                                                      std::numeric_limits<std::int32_t>::max()};
std::uniform_int_distribution<std::uint32_t> uint32_rng{std::numeric_limits<std::uint32_t>::min(),
                                                        std::numeric_limits<std::uint32_t>::max()};

void runTest(std::function<void()> test, seed_type seed) {
  runTest([&](std::size_t) { test(); }, seed);
}

void runTest(std::function<void(std::size_t)> test, seed_type seed) {
  resetRng(seed);

  for (std::size_t i = 0; i < rolls; ++i) {
    test(i);
  }
}

void resetRng(seed_type seed) { rng.seed(seed); }

std::int64_t nextInt64() { return int64_rng(rng); }

std::int64_t nextInt64NoZero() {
  std::int64_t out;

  do {
    out = nextInt64();
  } while (out == 0);

  return out;
}

std::uint64_t nextUint64() { return uint64_rng(rng); }

std::uint64_t nextUint64NoZero() {
  std::uint64_t out;

  do {
    out = nextUint64();
  } while (out == 0);

  return out;
}

std::int32_t nextInt32() { return int32_rng(rng); }

std::int32_t nextInt32NoZero() {
  std::int32_t out;

  do {
    out = nextInt32();
  } while (out == 0);

  return out;
}

std::uint32_t nextUint32() { return int64_rng(rng); }

std::uint32_t nextUint32NoZero() {
  std::uint32_t out;

  do {
    out = nextUint32();
  } while (out == 0);

  return out;
}
