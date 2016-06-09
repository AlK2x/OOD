#include "stdafx.h"
#include "../libeditor/History.h"
#include "../libeditor/ICommand.h"

struct History_
{
	CHistory history;
};

class CMockCommand : public ICommand
{
public:

	virtual void Execute() override
	{
		++executeCount;
	}
	virtual void Unexecute() override
	{
		++unexecuteCount;
	}

	unsigned executeCount = 0;
	unsigned unexecuteCount = 0;
};

BOOST_FIXTURE_TEST_SUITE(History, History_)
	BOOST_AUTO_TEST_SUITE(by_default)
		BOOST_AUTO_TEST_CASE(cant_undo_empty_history)
		{
			BOOST_CHECK_EQUAL(history.CanRedo(), false);
			BOOST_CHECK_EQUAL(history.CanUndo(), false);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(with_one_command)
		BOOST_AUTO_TEST_CASE(execute_command_when_add_to_history)
		{
			auto command = std::make_unique<CMockCommand>();
			unsigned * executeCount = &command->executeCount;
			BOOST_CHECK_EQUAL(*executeCount, 0);
			history.AddAndExecuteCommand(std::move(command));
			BOOST_CHECK_EQUAL(*executeCount, 1);
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct History_with_one_command_ : public History_
	{
		unsigned * executeCountPtr;
		unsigned * unexecuteCountPtr;

		History_with_one_command_()
		{
			auto command = std::make_unique<CMockCommand>();
			executeCountPtr = &command->executeCount;
			unexecuteCountPtr = &command->unexecuteCount;
			history.AddAndExecuteCommand(std::move(command));
		}

	};
	BOOST_FIXTURE_TEST_SUITE(with_one_executed_command, History_with_one_command_)
		BOOST_AUTO_TEST_CASE(call_enexecute_only_one_time_when_undo_command)
		{
			BOOST_CHECK_EQUAL(*executeCountPtr, 1);
			BOOST_CHECK_EQUAL(*unexecuteCountPtr, 0);
			history.Undo();
			BOOST_CHECK_EQUAL(*unexecuteCountPtr, 1);
			history.Undo();
			BOOST_CHECK_EQUAL(*unexecuteCountPtr, 1);
		}
		BOOST_AUTO_TEST_CASE(call_unenexecute_only_one_time_when_redo_command)
		{
			BOOST_CHECK_EQUAL(*unexecuteCountPtr, 0);
			history.Redo();
			BOOST_CHECK_EQUAL(*executeCountPtr, 1);
			history.Redo();
			BOOST_CHECK_EQUAL(*executeCountPtr, 1);
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct History_with_two_commands_ : public History_
	{
		unsigned * executeCountPtr1;
		unsigned * unexecuteCountPtr1;

		unsigned * executeCountPtr2;
		unsigned * unexecuteCountPtr2;

		History_with_two_commands_()
		{
			auto command1 = std::make_unique<CMockCommand>();
			executeCountPtr1 = &command1->executeCount;
			unexecuteCountPtr1 = &command1->unexecuteCount;

			auto command2 = std::make_unique<CMockCommand>();
			executeCountPtr2 = &command2->executeCount;
			unexecuteCountPtr2 = &command2->unexecuteCount;

			history.AddAndExecuteCommand(std::move(command1));
			history.AddAndExecuteCommand(std::move(command2));
		}
	};

	BOOST_FIXTURE_TEST_SUITE(with_two_executed_commands, History_with_two_commands_)
		BOOST_AUTO_TEST_CASE(each_command_executed_one_time)
		{
			BOOST_CHECK_EQUAL(*executeCountPtr1, 1);
			BOOST_CHECK_EQUAL(*unexecuteCountPtr1, 0);
			BOOST_CHECK_EQUAL(*executeCountPtr2, 1);
			BOOST_CHECK_EQUAL(*unexecuteCountPtr2, 0);
		}
		BOOST_AUTO_TEST_CASE(call_redo_without_undo_do_nothing_with_commands)
		{
			history.Redo();
			BOOST_CHECK_EQUAL(*unexecuteCountPtr2, 0);
			BOOST_CHECK_EQUAL(*unexecuteCountPtr1, 0);
		}
		BOOST_AUTO_TEST_CASE(undo_last_inserted_command)
		{
			history.Undo();
			BOOST_CHECK_EQUAL(*unexecuteCountPtr2, 1);
			BOOST_CHECK_EQUAL(*unexecuteCountPtr1, 0);
		}
		BOOST_AUTO_TEST_CASE(call_undo_two_times_will_unexecute_both_commands)
		{
			history.Undo();
			history.Undo();
			BOOST_CHECK_EQUAL(*unexecuteCountPtr2, 1);
			BOOST_CHECK_EQUAL(*unexecuteCountPtr1, 1);
		}
		BOOST_AUTO_TEST_CASE(redo_call_execute_last_undo_command)
		{
			history.Undo();
			history.Redo();
			BOOST_CHECK_EQUAL(*unexecuteCountPtr2, 1);
			BOOST_CHECK_EQUAL(*unexecuteCountPtr1, 0);

			BOOST_CHECK_EQUAL(*executeCountPtr2, 2);
			BOOST_CHECK_EQUAL(*executeCountPtr1, 1);
		}
		BOOST_AUTO_TEST_CASE(redo_after_two_calls_undo_will_execute_first_command)
		{
			history.Undo();
			history.Undo();
			history.Redo();

			BOOST_CHECK_EQUAL(*executeCountPtr1, 2);
			BOOST_CHECK_EQUAL(*executeCountPtr2, 1);

			BOOST_CHECK_EQUAL(*unexecuteCountPtr1, 1);
			BOOST_CHECK_EQUAL(*unexecuteCountPtr2, 1);
		}
		BOOST_AUTO_TEST_CASE(move_back_and_fourth_on_history_will_increment_execute_and_unexecute_calls)
		{
			history.Undo();
			history.Undo();
			history.Redo();
			history.Redo();

			BOOST_CHECK_EQUAL(*executeCountPtr1, 2);
			BOOST_CHECK_EQUAL(*executeCountPtr2, 2);
			BOOST_CHECK_EQUAL(*unexecuteCountPtr1, 1);
			BOOST_CHECK_EQUAL(*unexecuteCountPtr2, 1);

			history.Undo();
			history.Undo();
			history.Redo();
			history.Redo();

			BOOST_CHECK_EQUAL(*executeCountPtr1, 3);
			BOOST_CHECK_EQUAL(*executeCountPtr2, 3);
			BOOST_CHECK_EQUAL(*unexecuteCountPtr1, 2);
			BOOST_CHECK_EQUAL(*unexecuteCountPtr2, 2);	
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_FIXTURE_TEST_SUITE(change_comand_history, History_with_two_commands_)
		BOOST_AUTO_TEST_CASE(new_executed_command_erase_redo_history)
		{
			auto newCommand = std::make_unique<CMockCommand>();
			unsigned * newExecuteCountPtr = &newCommand->executeCount;
			unsigned * newUnexecuteCountPtr = &newCommand->unexecuteCount;

			BOOST_CHECK_EQUAL(*executeCountPtr2, 1);
			BOOST_CHECK_EQUAL(*executeCountPtr1, 1);

			BOOST_CHECK_EQUAL(*unexecuteCountPtr2, 0);
			BOOST_CHECK_EQUAL(*unexecuteCountPtr1, 0);

			history.Undo();
			history.AddAndExecuteCommand(std::move(newCommand));

			BOOST_CHECK_EQUAL(*newExecuteCountPtr, 1);
			BOOST_CHECK_EQUAL(*newUnexecuteCountPtr, 0);

			history.Undo();

			BOOST_CHECK_EQUAL(*newExecuteCountPtr, 1);
			BOOST_CHECK_EQUAL(*newUnexecuteCountPtr, 1);
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()