#include "stdafx.h"
#include "../libeditor/DocumentItemFormatter.h"
#include "../libeditor/IParagraph.h"
#include "../libeditor/Paragraph.h"
#include "../libeditor/DocumentItem.h"

struct Document_Item_With_Paragraph_
{
	CConstDocumentItem item;
	IParagraphPtr paragraph;

	Document_Item_With_Paragraph_()
	{
		paragraph = std::make_shared<CParagraph>();
		std::string text("test");
		paragraph->SetText(text);
		CConstDocumentItem itemI(paragraph);
		item = itemI;
	}
};

BOOST_FIXTURE_TEST_SUITE(DocumentFormatter, Document_Item_With_Paragraph_)

	BOOST_AUTO_TEST_CASE(Format_list)
	{
		CDocumentItemFormatter formatter;
		std::string result = formatter.FormatForList(item, 0);
		BOOST_CHECK_EQUAL(result, "0. Paragraph: test");
	}

	BOOST_AUTO_TEST_CASE(Format_html_with_html_entities)
	{
		CDocumentItemFormatter formatter;
		paragraph->SetText("<script>");
		BOOST_CHECK_EQUAL(formatter.FormatForHtml(item), "<p>&lt;script&gt;</p>");

		paragraph->SetText("\"");
		BOOST_CHECK_EQUAL(formatter.FormatForHtml(item), "<p>&quot;</p>");

		paragraph->SetText("");
		BOOST_CHECK_EQUAL(formatter.FormatForHtml(item), "<p></p>");
	}

BOOST_AUTO_TEST_SUITE_END()
