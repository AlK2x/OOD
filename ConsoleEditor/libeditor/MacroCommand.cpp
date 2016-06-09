#include "stdafx.h"
#include "MacroCommand.h"

void CMacroCommand::AddCommand(std::unique_ptr<ICommand> command)
{
	m_commands.emplace_back(std::move(command));
}

void CMacroCommand::DoExecute()
{
	for (auto & command : m_commands)
	{
		command->Execute();
	}
}

void CMacroCommand::DoUnexecute()
{
	for (auto it = m_commands.rbegin(); it != m_commands.rend(); ++it)
	{
		(*it)->Unexecute();
	}
}
