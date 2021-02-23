#include "gtestsample/sample.hpp"

Sample::Sample(void)
  : v(0)
{
}

Sample::Sample(int i)
  : v(i)
{
}

void Sample::set(int i)
{
  this->v = i;
}

int Sample::get(void)
{
  return this->v;
}

