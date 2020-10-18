// FILE: statistician.cpp
// CLASS IMPLEMENTED: statistician (see statistician.h for documentation)

#include "stats.h"	//Provides the statistician class definition
#include <cassert>  //Provides the assert definition
#include <climits>
#include <iostream>
using namespace std;


namespace main_savitch_2C
{
	//////////////
	// CONSTRUCTOR

	statistician::statistician()
	{
		count = total = 0, tinyest = INT_MAX, largest = INT_MIN;
	}

	////////////////////////////////
	// MODIFICATION MEMBER FUNCTIONS

	void statistician::next(double r)
	{
		if (count == 0) tinyest = largest = r;  //If first input, set both tinyest and largest = r
		count++;								//Add 1 to count
		total += r;								//Add r to total
		if (r <= tinyest) tinyest = r;			//If r is less than tinyest, tinyest = r
		if (r >= largest) largest = r;			//If r is more than largest, largest = r
	}

	void statistician::reset()
	{
		count = total = 0, tinyest = INT_MAX, largest = INT_MIN;  //Set count, total to 0; Set tinyest to INT_MAX and largest to INT_MIN
	}

	////////////////////////////
	// CONSTANT MEMBER FUNCTIONS
	
	int statistician::length() const
	{
		return count;  //Return count
	}

	double statistician::sum() const
	{
		return total;  //Return total
	}

	double statistician::mean() const
	{
		assert(length() > 0);	 //Assert if length has values
		return (total / count);  //Return total divided by count
	}

	double statistician::minimum() const
	{
		assert(length() > 0);  //Assert if length has values
		return tinyest;		   //Return tinyest
	}

	double statistician::maximum() const
	{
		assert(length() > 0);  //Assert if length has values
		return largest;		   //Return largest
	}

	///////////////////
	// FRIEND FUNCTIONS

	statistician operator +
		(const statistician& s1, const statistician& s2)
	{
		/* Postcondition: The statistician that is returned contains
		all the numbers of the sequences of s1 and s2. */

		if(s1.length() == 0) return s2;
		if(s2.length() == 0) return s1;
		double min_both = (s1.tinyest < s2.tinyest) ? s1.tinyest : s2.tinyest;  //Set min_both to the smallest of both tinyests
		double max_both = (s1.largest > s2.largest) ? s1.largest : s2.largest;  //Set max_both to the biggest of both largests
		statistician output;													//Make an object, output, with the tinyest and largest of both
		output.count = s1.count + s2.count;
		output.total = s1.total + s2.total;
		output.tinyest = min_both;
		output.largest = max_both;
		return output;															//Return said object
	}

	statistician operator *
		(double scale, const statistician& s)
	{
		/* Postcondition: The statistician that is returned contains the same
		numbers that s does, but each number has been multiplied by the scale number. */

		if (scale < 0) {
			double max = s.tinyest;			//If scale is negative, max is set to tinyest
			double min = s.largest;			//If scale is negative, min is set to largest
			statistician output;			//If scale is negative, make an object, output, with scale multiplied with each number
			output.count = s.count;
			output.total = s.total * scale;
			output.tinyest = min * scale;
			output.largest = max * scale;
			return output;					//Return said object
		}
		else {
			statistician output;				//If scale is positive or zero, make an object, output, with scale multiplied with each number
			output.count = s.count;
			output.total = s.total * scale;
			output.tinyest = s.tinyest * scale;
			output.largest = s.largest * scale;
			return output;						//Return said object
		}
	}

	//////////////////////////////////////////////////
	// NON-MEMBER functions for the statistician class

	bool operator ==(const statistician& s1, const statistician& s2)
	{
		/* Postcondition: The return value is true if s1 and s2 have the zero
		length. Also, if the length is greater than zero, then s1 and s2 must
		have the same length, the same mean, the same minimum, 
		the same maximum, and the same sum. */
		
		if (s1.length() == 0 && s2.length() == 0) return true;  //If s1 and s2 has zero length, return true
		return (s1.length() > 0 && s2.length() > 0 
			&& s1.length() == s2.length() 
			&& s1.mean() == s2.mean() 
			&& s1.minimum() == s2.minimum()
			&& s1.maximum() == s2.maximum());
		//If s1's and s2's length is greater than zero, then both lengths, means, minimum, and maximum must be the same to return true
	}
}
