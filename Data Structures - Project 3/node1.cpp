// FILE: node1.cxx
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "newnode.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5
{
	size_t list_length(const node* head_ptr)
		// Library facilities used: cstdlib
	{
		const node* cursor;
		size_t answer;

		answer = 0;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			++answer;

		return answer;
	}

	void list_head_insert(node*& head_ptr, const node::value_type& entry)
	{
		head_ptr = new node(entry, head_ptr);
	}

	void list_insert(node* previous_ptr, const node::value_type& entry)
	{
		node* insert_ptr;

		insert_ptr = new node(entry, previous_ptr->link());
		previous_ptr->set_link(insert_ptr);
	}

	node* list_search(node* head_ptr, const node::value_type& target)
		// Library facilities used: cstdlib
	{
		node* cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			if (target == cursor->data())
				return cursor;
		return NULL;
	}

	const node* list_search(const node* head_ptr, const node::value_type& target)
		// Library facilities used: cstdlib
	{
		const node* cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			if (target == cursor->data())
				return cursor;
		return NULL;
	}

	node* list_locate(node* head_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		node* cursor;
		size_t i;

		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link();
		return cursor;
	}

	const node* list_locate(const node* head_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		const node* cursor;
		size_t i;

		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link();
		return cursor;
	}

	void list_head_remove(node*& head_ptr)
	{
		node* remove_ptr;

		remove_ptr = head_ptr;
		head_ptr = head_ptr->link();
		delete remove_ptr;
	}

	void list_remove(node* previous_ptr)
	{
		node* remove_ptr;

		remove_ptr = previous_ptr->link();
		previous_ptr->set_link(remove_ptr->link());
		delete remove_ptr;
	}

	void list_clear(node*& head_ptr)
		// Library facilities used: cstdlib
	{
		while (head_ptr != NULL)
			list_head_remove(head_ptr);
	}

	void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
		// Library facilities used: cstdlib
	{
		head_ptr = NULL;
		tail_ptr = NULL;

		// Handle the case of the empty list.
		if (source_ptr == NULL)
			return;

		// Make the head node for the newly created list, and put data in it.
		list_head_insert(head_ptr, source_ptr->data());
		tail_ptr = head_ptr;

		// Copy the rest of the nodes one at a time, adding at the tail of new list.
		source_ptr = source_ptr->link();
		while (source_ptr != NULL)
		{
			list_insert(tail_ptr, source_ptr->data());
			tail_ptr = tail_ptr->link();
			source_ptr = source_ptr->link();
		}
	}

	std::size_t list_occurrences(const node* head_ptr, const node::value_type& target)
		//Big-O Notation: O(n)
		//The for loop has to go through the length of the list
	{
		const node* cursor;
		size_t count = 0;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link()) {
			if (target == cursor->data())
				++count;
		}

		return count;
	}

	void list_tail_attach(node*& head_ptr, const node::value_type& entry)
		//Big-O Notation: O(n)
		//It goes through the whole list for tail
	{
		node* cursor = head_ptr;

		//If list is empty
		if (!list_length(head_ptr)) {
			head_ptr = new node(entry, NULL);
			return;
		}

		while (cursor->link())
			cursor = cursor->link();

		list_insert(cursor, entry);
		return;
	}

	void list_tail_remove(node*& head_ptr)
		//Big-O Notation: O(n)
		//It goes through the whole list for tail
	{
		node* tail = head_ptr;
		node* previous = head_ptr;

		//If list is empty
		if (!list_length(head_ptr)) return;

		//If there is 1 node in the list
		if (list_length(head_ptr) == 1) {
			list_head_remove(head_ptr);
			return;
		}

		while (tail->link()) {
			previous = tail;
			tail = tail->link();
		}

		list_remove(previous);
		return;
	}

	node* list_copy_front(const node* source_ptr, std::size_t n)
		//Big-O Notation: O(n)
		//It copies for the length of the list or n
	{
		node* head = NULL;
		node* cursor = NULL;
		size_t count = 1;

		assert(n <= list_length(source_ptr));

		//If no nodes asked or list is empty, return head
		if (n == 0 || !list_length(source_ptr))
			return head;

		//Initialize first node
		list_head_insert(head, source_ptr->data());
		cursor = head;

		while (count < n) {
			source_ptr = source_ptr->link();
			list_insert(cursor, source_ptr->data());
			cursor = cursor->link();
			++count;
		}

		return head;
	}
}