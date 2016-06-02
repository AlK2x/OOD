#pragma once
#include "Menu.h"
#include "Document.h"
#include <iostream>
#include <sstream>

class CEditor
{
public:
	CEditor()  //-V730
		:m_document(std::make_unique<CDocument>())
	{
		m_menu.AddItem("help", "Help", [this](std::istream&) { m_menu.ShowInstructions(); });
		m_menu.AddItem("exit", "Exit", [this](std::istream&) { m_menu.Exit(); });
		AddMenuItem("SetTitle", "Changes title. Args: <new title>", &CEditor::SetTitle);
		m_menu.AddItem("list", "Show document", std::bind(&CEditor::List, this, std::placeholders::_1));
		AddMenuItem("undo", "Undo command", &CEditor::Undo);
		AddMenuItem("redo", "Redo undone command", &CEditor::Redo);
		AddMenuItem("InsertParagraph", "Insert paragraph. Args: <position>|end <paragraph text>", &CEditor::InsertParagraph);
	}

	void Start()
	{
		m_menu.Run();
	}

private:
	// ”казатель на метод класса CEditor, принимающий istream& и возвращающий void
	typedef void (CEditor::*MenuHandler)(std::istream & in);

	void AddMenuItem(const std::string & shortcut, const std::string & description, MenuHandler handler)
	{
		m_menu.AddItem(shortcut, description, std::bind(handler, this, std::placeholders::_1));
	}

	// TODO: скипнуть первый пробел элегантнее
	void SetTitle(std::istream & in)
	{
		std::string head;
		std::string tail;

		if (in >> head)
		{
			getline(in, tail);
		}
		std::string title = head + tail;

		m_document->SetTitle(title);
	}

	void List(std::istream &)
	{
		std::cout << "-------------" << std::endl;
		std::cout << m_document->GetTitle() << std::endl;
		std::cout << m_document->GetItem(0).GetParagraph()->GetText() << std::endl;
		std::cout << "-------------" << std::endl;
	}

	void InsertParagraph(std::istream & in)
	{
		std::string position;
		std::string paragraphText;
		in >> position;
		in >> std::ws;
		getline(in, paragraphText);
		if (position == "end")
		{
			m_document->InsertParagraph(paragraphText);
		}
	}

	void Undo(std::istream &)
	{
		if (m_document->CanUndo())
		{
			m_document->Undo();
		}
		else
		{
			std::cout << "Can't undo" << std::endl;
		}
	}

	void Redo(std::istream &)
	{
		if (m_document->CanRedo())
		{
			m_document->Redo();
		}
		else
		{
			std::cout << "Can't redo" << std::endl;
		}
	}

	CMenu m_menu;
	std::unique_ptr<IDocument> m_document;
};
