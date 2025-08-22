#include <gtest/gtest.h>
#include "./monitor.h"

// Parameterized test for vitalsOk
class VitalsTest : public ::testing::TestWithParam<std::tuple<float, float, float, bool>> {};

TEST_P(VitalsTest, CheckVitalsOk) {
    float temperature = std::get<0>(GetParam());
    float pulseRate = std::get<1>(GetParam());
    float spo2 = std::get<2>(GetParam());
    bool expected = std::get<3>(GetParam());

    EXPECT_EQ(vitalsOk(temperature, pulseRate, spo2), expected);
}

INSTANTIATE_TEST_SUITE_P(
    VitalsRangeTests,
    VitalsTest,
    ::testing::Values(
        std::make_tuple(99, 102, 70, false),   // Pulse and SpO2 out of range
        std::make_tuple(98.1, 70, 98, true),   // All vitals OK
        std::make_tuple(90, 50, 105, false),   // Pulse out of range
        std::make_tuple(72, 99, 95, true),     // All vitals OK
        std::make_tuple(94, 80, 95, false),    // Temperature low
        std::make_tuple(103, 80, 95, false),   // Temperature high
        std::make_tuple(98, 59, 95, false),    // Pulse low
        std::make_tuple(98, 101, 95, false),   // Pulse high
        std::make_tuple(98, 80, 89, false)     // SpO2 low
    )
);


