#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
  ASSERT_TRUE(vitalsOk(90, 50, 105));
  ASSERT_TRUE(vitalsOk(72, 99, 95));
}

