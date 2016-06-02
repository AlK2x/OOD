#pragma once
#include "Menu.h"
#include "Document.h"
#include "DocumentItemFormatter.h"
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
		for (size_t i = 0; i < m_document->GetItemsCount(); ++i)
		{
			std::cout << m_formatter.FormatForList(m_document->GetItem(i), i) << std::endl;
			std::cout << m_formatter.FormatForHtml(m_document->GetItem(i)) << std::endl;
		}
		std::cout << "-------------" << std::endl;
	}

	void InsertParagraph(std::istream & in)
	{
		std::string positionStr;
		std::string paragraphText;
		in >> positionStr;
		in >> std::ws;
		getline(in, paragraphText);
		if (positionStr == "end")
		{
			m_document->InsertParagraph(paragraphText);
		}
		else
		{
			std::stringstream ss(positionStr);
			size_t position;
			ss >> position;
			m_document->InsertParagraph(paragraphText, position);
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
	CDocumentItemFormatter m_formatter;
	std::unique_ptr<IDocument> m_document;
};
