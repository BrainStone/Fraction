//
// Copyright (c) 2018 Yannick Schinko
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
//
#pragma once

#include <cstdint>
#include <functional>
#include <limits>
#include <random>

#ifdef LONG_TESTING
constexpr std::size_t rolls{100'000};
#else
constexpr std::size_t rolls{10'000};
#endif

extern std::default_random_engine rng;

extern std::uniform_int_distribution<std::int64_t> int64_rng;
extern std::uniform_int_distribution<std::uint64_t> uint64_rng;
extern std::uniform_int_distribution<std::int32_t> int32_rng;
extern std::uniform_int_distribution<std::uint32_t> uint32_rng;

using seed_type = std::default_random_engine::result_type;

void runTest(std::function<void()> test, seed_type seed = 0);
void runTest(std::function<void(std::size_t)> test, seed_type seed = 0);

void resetRng(seed_type seed = 0);

std::int64_t nextInt64();
std::int64_t nextInt64NoZero();

std::uint64_t nextUint64();
std::uint64_t nextUint64NoZero();

std::int32_t nextInt32();
std::int32_t nextInt32NoZero();

std::uint32_t nextUint32();
std::uint32_t nextUint32NoZero();
