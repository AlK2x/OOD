#include "stdafx.h"
#include "../libeditor/ChangeStringCommand.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(test_change_string_command)

	BOOST_AUTO_TEST_CASE(replace_string)
	{
		string target = "target";
		string newValue = "newValue";

		CChangeStringCommand command(target, newValue);

		command.Execute();
		BOOST_CHECK_EQUAL(target, "newValue");
		BOOST_CHECK_EQUAL(newValue, "newValue");

		command.Unexecute();
		BOOST_CHECK_EQUAL(target, "target");
		BOOST_CHECK_EQUAL(newValue, "newValue");
	}

BOOST_AUTO_TEST_SUITE_END()