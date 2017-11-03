#include <catch.hpp>
#include <stack.hpp>

SCENARIO("stack init")
{
	stack<int> st;
	REQUIRE(st.count() == 0);
}
