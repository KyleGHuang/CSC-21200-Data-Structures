// File: queens.cxx
// Written by: Michael Main (main@colorado.edu) Nov 20, 2002
//
// This is a solution to the n-queens problem from Chapter 7
// of "Data Structures and Other Objects Using C++".
// This solution varies a bit from the problem in that the 
// top of the stack will be the column choice for row 1.
// Below that is the column choice for row 2, and so on.
// For example, with n set to 5, the solution shown in the book is:
// Q - - - -
// - - Q - -
// - - - - Q
// - Q - - -
// - - - Q -
// My stack would record this solution as:
// [Bottom of stack] 4 2 5 3 1 [Top of stack].
// So, I don't actually record the choices of the row numbers, and
// furthermore, it's not possible to ever have two queens in the same row.
// Each time I push a new number on top of the stack, the other rows get
// shifted to the next higher row number.

#include <cassert>
#include <iostream>
#include "stack3.h" // Provides the stack class with a peek(i) function.
using namespace std;
using namespace main_savitch_7A;

void print_solution(stack<unsigned int> choices)
{
    unsigned int i;

    cout << "Solution for n = " << choices.size( ) << endl;
    cout << "======================================================" << endl;
    for (i = 1; !choices.empty( ); i++)
    {
	cout << "Queen in row " << i << ", column " << choices.top( ) << endl;
	choices.pop( );
    }
    cout << "======================================================\n" << endl;
}

bool is_conflict(const stack<unsigned int>& choices)
{
    unsigned int i;
    unsigned int newqueen = choices.top( );
    unsigned int other;
    
    for (i = 2; i <= choices.size( ); i++)
    {   // Check whether queen on top of the stack (which is in row 1)
	// conflicts with the queen in row number i.  If so, then return
	// true right away because we found a conflict.
        other = choices.peek(i);
	if ((newqueen == other)          // Queens in the same column
	    || (newqueen+(i-1) == other) // Diagonal left-to-right
	    || (newqueen-(i-1) == other) // Diagonal right-to-left
	    )
	    return true;
    }

    return false;
}
    
void queens(unsigned int n)
{
    stack<unsigned int> choices;
    unsigned int next;
    bool success = false;
    assert (n >= 1);

    choices.push(1);
    success = false;
    
    while (!success && !choices.empty( ))
    {
	if (is_conflict(choices))
	{
	    while (!choices.empty( ) && choices.top( ) == n)
		choices.pop( );
	    if (!choices.empty( ))
	    {
		next = choices.top( ) + 1;
		choices.pop( );
		choices.push(next);
	    }
	}
	else if (choices.size( ) == n)
	    success = true;
	else
	    choices.push(1);
    }

    if (success)
	print_solution(choices);
    else
	cout << "No solutions were found." << endl;
}

int main( )
{
    unsigned int n;
    
    cout << "Please enter n for the n-queens problem (n >= 1): ";
    cin >> n;
    queens(n);

    return 0;
}
