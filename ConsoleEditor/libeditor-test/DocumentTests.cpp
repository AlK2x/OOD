#include "stdafx.h"

BOOST_AUTO_TEST_SUITE(debug_test_suite)

BOOST_AUTO_TEST_CASE(always_pass)
{
	BOOST_CHECK(true);
}

BOOST_AUTO_TEST_SUITE_END()