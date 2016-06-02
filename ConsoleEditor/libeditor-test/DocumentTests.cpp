#include "stdafx.h"
#include "../libeditor/Document.h"

struct Document_
{
	CDocument document;
};

BOOST_FIXTURE_TEST_SUITE(Document, Document_)

	BOOST_AUTO_TEST_SUITE(by_default)
		BOOST_AUTO_TEST_CASE(get_empty_title)
		{
			BOOST_CHECK_EQUAL(document.GetTitle(), "");
		}
	
		BOOST_AUTO_TEST_CASE(cant_undo_command)
		{
			BOOST_CHECK_EQUAL(document.CanUndo(), false);
		}

		BOOST_AUTO_TEST_CASE(cant_redo_command)
		{
			BOOST_CHECK_EQUAL(document.CanRedo(), false);
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct Document_with_title_ : public Document_
	{
		Document_with_title_()
		{
			document.SetTitle("title");
		}
	};

	BOOST_FIXTURE_TEST_SUITE(with_title, Document_with_title_)
		BOOST_AUTO_TEST_CASE(get_same_title)
		{
			BOOST_CHECK_EQUAL(document.GetTitle(), "title");
		}
		
		BOOST_AUTO_TEST_CASE(can_undo_command)
		{
			BOOST_CHECK_EQUAL(document.CanUndo(), true);
		}

		BOOST_AUTO_TEST_CASE(cant_undo_command)
		{
			BOOST_CHECK_EQUAL(document.CanRedo(), false);
		}

		BOOST_AUTO_TEST_CASE(can_undo_set_title)
		{
			document.Undo();
			BOOST_CHECK_EQUAL(document.GetTitle(), "");
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct Document_with_inserted_paragraph_ : public Document_
	{
		Document_with_inserted_paragraph_()
		{
			document.InsertParagraph("paragraph");
		}
	};

	BOOST_FIXTURE_TEST_SUITE(with_paragraph, Document_with_inserted_paragraph_)
		BOOST_AUTO_TEST_CASE(can_undo_command)
		{
			BOOST_CHECK_EQUAL(document.CanUndo(), false);
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()