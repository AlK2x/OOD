#pragma once
#include "Menu.h"
#include "Document.h"
#include "ListDocumentFormatter.h"
#include <iostream>
#include <sstream>

namespace fs = boost::filesystem;

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
		AddMenuItem("ReplaceParagraph", "Replace paragraph. Args: <position> <paragraph text>", &CEditor::ReplaceParagraph);
		AddMenuItem("InsertImage", "Insert image. Args: <position>|end <width> <height> <file path>", &CEditor::InsertImage);
		AddMenuItem("DeleteItem", "Delete Item. Args: <position>", &CEditor::DeleteItem);
		AddMenuItem("Save", "Save the document. Args: <path>", &CEditor::Save);
		AddMenuItem("ResizeImage", "Resize image: Args: <position> <width> <height>", &CEditor::ReplaceImage);
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
		m_formatter.FormatDocument(*m_document, std::cout);
		std::cout << "-------------" << std::endl;
	}

	void InsertParagraph(std::istream & in)
	{
		bool error = false;
		boost::optional<size_t> position = ReadPosition(in, error);
		
		if (error)
		{
			ShowErrorMessage("Invalid arguments. Use help.");
		}
		else
		{
			std::string paragraphText = ReadText(in, error);
			try
			{
				m_document->InsertParagraph(paragraphText, position);
			}
			catch (std::out_of_range & e)
			{
				std::cout << e.what() << std::endl;
			}
			
		}
	}

	boost::optional<size_t> ReadPosition(std::istream & in, bool & error)
	{
		std::string positionStr;
		in >> positionStr;
		in >> std::ws;
		if (positionStr == "end")
		{
			return boost::none;
		}
		else
		{
			std::stringstream ss(positionStr);
			size_t position;
			ss >> position;

			error = ss.fail() || ss.bad();
			return position;
		}
	}

	int ReadNumber(std::istream & in, bool & error)
	{
		std::string numStr;
		in >> std::ws >> numStr;
		std::stringstream ss(numStr);
		int num;
		ss >> num;
		error = ss.fail() || ss.bad();
		return num;
	}

	std::string ReadText(std::istream & in, bool & error)
	{
		std::string text;
		getline(in, text);
		error = in.fail() || in.bad();
		return text;
	}

	void ShowErrorMessage(std::string msg)
	{
		std::cout << msg << std::endl;
	}

	void ReplaceParagraph(std::istream & in)
	{
		bool error = false;
		boost::optional<size_t> position = ReadPosition(in, error);
		if (error || position == boost::none)
		{
			ShowErrorMessage("Invalid arguments. Use help.");
			return;
		}
		
		std::string text = ReadText(in, error);

		if (error || position == boost::none)
		{
			ShowErrorMessage("Invalid arguments. Use help.");
		}
		else
		{
			try
			{
				m_document->ReplaceParagraph(text, position.get());
			}
			catch (std::out_of_range const & e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}

	void InsertImage(std::istream & in)
	{
		bool error = false;
		boost::optional<size_t> position = ReadPosition(in, error);
		if (error)
		{
			ShowErrorMessage("Incorrect position. Use help.");
			return;
		}

		int width = ReadNumber(in, error);
		if (error)
		{
			ShowErrorMessage("Incorrect width parameter. Use help.");
			return;
		}

		int height = ReadNumber(in, error);
		if (error)
		{
			ShowErrorMessage("Incorrect height parameter. Use help.");
			return;
		}

		in >> std::ws;
		std::string path = ReadText(in, error);
		if (error)
		{
			ShowErrorMessage("Cant read path parameter. Use help.");
			return;
		}

		try
		{
			m_document->InsertImage(path, width, height, position);
		}
		catch (std::exception const & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	void ReplaceImage(std::istream & in)
	{
		bool error = false;
		boost::optional<size_t> position = ReadPosition(in, error);
		if (error || position == boost::none)
		{
			ShowErrorMessage("Incorrect position. Use help.");
			return;
		}

		int width = ReadNumber(in, error);
		if (error)
		{
			ShowErrorMessage("Incorrect width parameter. Use help.");
			return;
		}

		int height = ReadNumber(in, error);
		if (error)
		{
			ShowErrorMessage("Incorrect height parameter. Use help.");
			return;
		}

		try
		{
			m_document->ResizeImage(width, height, position.get());
		}
		catch (std::exception const & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	void DeleteItem(std::istream & in)
	{
		bool error = false;
		boost::optional<size_t> position = ReadPosition(in, error);

		if (error || position == boost::none)
		{
			ShowErrorMessage("Invalid arguments. Use help.");
			return;
		}
		
		try
		{
			m_document->DeleteItem(position.get());
		}
		catch (std::out_of_range & e)
		{
			std::cout << e.what() << std::endl;
		}
		
	}

	void Save(std::istream & in)
	{
		bool error = false;
		in >> std::ws;
		std::string path = ReadText(in, error);
		try
		{
			m_document->Save(path);
		}
		catch (const std::exception & e)
		{
			std::cout << "Cant save file to path: " + path << std::endl;
			std::cout << e.what() << std::endl;
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
	CListDocumentFormatter m_formatter;
};
