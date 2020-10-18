// FILE: sequence2.cpp
// CLASS IMPLEMENTED: sequence (see sequence2.h for documentation)

#include "sequence2.h"	//Provides the sequence2 class definition
#include <cstdlib>  // Provides size_t
#include <cassert>  //Provides the assert definition
#include <climits>
#include <algorithm>
using namespace std;

namespace main_savitch_4
{
	//CONSTRUCTOR

	sequence::sequence(size_type initial_capacity)
	{
		capacity = initial_capacity;
		data = new value_type[capacity];
		used = 0;
		current_index = 0;
	}

	sequence::sequence(const sequence& source)
	{
		/*Postcondition: The sequence has been initialized
		  as an empty sequence. The insert/attach functions
		  will work efficiently (without allocating
		  new memory) until this capacity is reached.
		*/

		data = new value_type[source.capacity];
		used = source.used;
		current_index = source.current_index;
		capacity = source.capacity;
		copy(source.data, source.data + used, data);
	}

	sequence::~sequence()
	{
		delete[]data;
	}

	//MODIFICATION MEMBER FUNCTIONS

	void sequence::resize(size_type new_capacity)
	{
		/*Postcondition: The sequence's current capacity is 
		  changed to the new_capacity (but not less that the 
		  number of items already on the list). The insert/attach 
		  functions will work efficiently (without allocating 
		  new memory) until this new capacity is reached.
		*/

		value_type* larger_array;

		if (capacity == new_capacity) return;
		if (new_capacity < used) new_capacity = used;

		//Create a new array by updating larger_array's capacity,
		//copying data to larger_array, and deleting data[].

		larger_array = new value_type[new_capacity];
		copy(data, data + used, larger_array);
		delete[]data;
		data = larger_array;
		capacity = new_capacity;
	}

	void sequence::start()
	{
		//Postconditon: current_index is 0
		current_index = 0;
	}

	void sequence::advance()
	{
		//Precondition: is_item returns true.
		assert(is_item());
		current_index++;
	}

	void sequence::insert(const value_type& entry)
	{
		/*Precondition: size() is smaller than capacity
		  Postcondition: A new copy of entry has been inserted 
		  in the sequence before the current item. If there was no 
		  current item, then the new entry has been inserted at the 
		  front of the sequence. In either case, the newly
          inserted item is now the current item of the sequence.
		*/

		size_type i;

		if (size() >= capacity) resize(capacity + 1);
		assert(size() < capacity);

		//Insert entry by moving values from current_index 
		//to used by 1 in the array and inserting entry

		if (!is_item()) current_index = 0;
		for (i = used; i > current_index; i--)
			data[i] = data[i - 1];
		data[current_index] = entry;
		used++;
	}

	void sequence::attach(const value_type& entry)
	{
		/*Precondition: size() is smaller than capacity
		  Postcondition: A new copy of entry has been inserted 
		  in the sequence after the current item. If there was no 
		  current item, then the new entry has been attached to 
		  the end of the sequence. In either case, the newly
		  inserted item is now the current item of the sequence.
		*/

		size_type i;

		if (size() >= capacity) resize(capacity + 1);
		assert(size() < capacity);

		//Attach entry by moving values from current_index + 1
		//to used by 1 in the array and inesrting entry
		
		if (!is_item()) data[current_index] = entry;
		else {
			for (i = used; i > current_index + 1; i--)
				data[i] = data[i - 1];
			data[current_index + 1] = entry;
			current_index++;
		}
		used++;
	}

	void sequence::remove_current()
	{
		/*Precondition: is_item returns true.
		  Postcondition: The current item has been 
		  removed from the sequence, and the item after 
		  this (if there is one) is now the new current item.
		*/

		size_type i;

		assert(is_item());

		//Remove current value by moving current_index's
		//next to current_index and moving forward in the array

		for (i = current_index + 1; i < used; i++)
			data[i - 1] = data[i];
		used--;
	}

	void sequence::operator =(const sequence& source)
	{
		value_type* new_data;

		if (this == &source)
			return;

		//Copy source's data, used, current_index, and
		//resize if necessary

		if (capacity != source.capacity) resize(source.capacity);
		used = source.used;
		copy(source.data, source.data + used, data);
		current_index = source.current_index;
	}

	//CONSTANT MEMBER FUNCTIONS

	sequence::size_type sequence::size() const
	{
		/*Postcondition: The return value is the 
		  number of items in the sequence.
		*/
		
		return used;
	}

	bool sequence::is_item() const
	{
		/*Postcondition: A true return value indicates 
		  that there is a valid
          "current" item that may be retrieved by activating 
		  the current member function (listed below). A false 
		  return value indicates that there is no valid current item.
		*/

		return(current_index < used);
	}

	sequence::value_type sequence::current() const
	{
		/*Precondition: is_item( ) returns true.
		  Postcondition: The item returned is 
		  the current item in the sequence.
		*/

		assert(is_item());
		return data[current_index];
	}
}