//
// Copyright (c) 2018 Yannick Schinko
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
//
#include <gtest/gtest.h>

#include "fraction.hpp"

int main(int argc, char **argv) {
  ::testing::FLAGS_gtest_output = "xml:gtestresults.xml";
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
