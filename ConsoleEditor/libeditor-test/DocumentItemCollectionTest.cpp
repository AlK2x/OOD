#include "stdafx.h"
#include "../libeditor/DocumentItemCollection.h"

struct Document_item_collection_
{
	CDocumentItemCollection collection;
};

BOOST_FIXTURE_TEST_SUITE(DocumentItemCollection, Document_item_collection_)

	BOOST_AUTO_TEST_SUITE(by_default)
		BOOST_AUTO_TEST_CASE(cant_remove_item)
		{
			BOOST_CHECK_EQUAL(collection.RemoveItem(0), false);
		}

		BOOST_AUTO_TEST_CASE(cant_get_item)
		{
			boost::optional<CDocumentItemPtr> item = collection.GetItem(0);
			if (item)
			{
				BOOST_CHECK(false);
			}
			else
			{
				BOOST_CHECK(true);
			}
		}

		BOOST_AUTO_TEST_CASE(insert_item_to_zero_position)
		{
			CDocumentItemPtr itemPtr = std::shared_ptr<CDocumentItem>();
			bool result = collection.AddItem(itemPtr, boost::optional<size_t>(0));
			BOOST_CHECK_EQUAL(result, true);
			boost::optional<CDocumentItemPtr> storedPtr = collection.GetItem(0);
			BOOST_CHECK_EQUAL(storedPtr.get().get(), itemPtr.get());
			BOOST_CHECK_EQUAL(collection.GetSize(), 1);
		}

		BOOST_AUTO_TEST_CASE(insert_item_to_none_position)
		{
			CDocumentItemPtr itemPtr = std::shared_ptr<CDocumentItem>();
			bool result = collection.AddItem(std::shared_ptr<CDocumentItem>(), boost::none);
			BOOST_CHECK_EQUAL(result, true);
			boost::optional<CDocumentItemPtr> storedPtr = collection.GetItem(0);
			BOOST_CHECK_EQUAL(storedPtr.get().get(), itemPtr.get());
			BOOST_CHECK_EQUAL(collection.GetSize(), 1);
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct Not_empty_document_item_collection_ : public Document_item_collection_
	{
		CDocumentItemPtr itemPtrI;
		Not_empty_document_item_collection_()
		{
			itemPtrI = std::shared_ptr<CDocumentItem>();
			collection.AddItem(itemPtrI, boost::none);
		}
	};
	BOOST_FIXTURE_TEST_SUITE(with_not_empty_collection, Not_empty_document_item_collection_)
		BOOST_AUTO_TEST_CASE(add_item_to_none_position_will_add_at_the_end)
		{
			CDocumentItemPtr itemPtr = std::shared_ptr<CDocumentItem>();
			collection.AddItem(itemPtr, boost::none);
			BOOST_CHECK_EQUAL(collection.GetItem(1).get().get(), itemPtr.get());
		}

		BOOST_AUTO_TEST_CASE(cant_add_item_out_of_range)
		{
			CDocumentItemPtr itemPtr = std::shared_ptr<CDocumentItem>();
			bool result = collection.AddItem(itemPtr, 3);
			BOOST_CHECK_EQUAL(result, false);
			BOOST_CHECK_EQUAL(collection.GetSize(), 1);
			BOOST_CHECK_EQUAL(itemPtrI.get(), collection.GetItem(0).get().get());
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()