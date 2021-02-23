#include "gtestsample/sample.hpp"
#include "gtest/gtest.h"

namespace
{
  class test_sample : public ::testing::Test
  {
    protected:
      Sample* sample;
      void TearDown(void)
      {
        delete sample;
      }
  };

  TEST_F(test_sample, constructor_10)
  {
    sample = new Sample{10};
    EXPECT_EQ(sample->v, 10);
  }

  TEST_F(test_sample, constructor_m5)
  {
    sample = new Sample{-5};
    EXPECT_EQ(sample->v, -5);
  }

  TEST_F(test_sample, set_m8_get)
  {
    sample = new Sample;
    sample->set(-8);
    EXPECT_EQ(sample->get(), -8);
  }
};
