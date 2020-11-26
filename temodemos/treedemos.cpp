#include "bintree.h"

using namespace std;
using namespace main_savitch_10;

template <class Item>
void printout(Item& it)
// Library facilities used: iostream
{
	std::cout << it << " ";
}

template <class Item>
void setX(Item& it)
// Library facilities used: iostream
{
	std::cout << "changing " << it << " to 'X'" << endl;
	it = 'X';
}

int main()
{
	/*
	binary_tree_node<char> *v=new 	binary_tree_node<char>('V');
	binary_tree_node<char> *q=new 	binary_tree_node<char>('Q');
	binary_tree_node<char> *l=new 	binary_tree_node<char>('L');
	binary_tree_node<char> *e=new 	binary_tree_node<char>('E');
	binary_tree_node<char> *t=new 	binary_tree_node<char>('T');
	binary_tree_node<char> *k=new 	binary_tree_node<char>('K');
	binary_tree_node<char> *a=new 	binary_tree_node<char>('A');
	binary_tree_node<char> *s=new 	binary_tree_node<char>('S');

	v->set_left(q); v->set_right(l);
	q->set_left(e); q->set_right(t);
	t->set_left(k);
	l->set_right(a);
	a->set_right(s);

	inorder(printout<char>,v);
	*/

	binary_tree_node<char>* f = new 	binary_tree_node<char>('F');
	binary_tree_node<char>* c = new 	binary_tree_node<char>('C');
	binary_tree_node<char>* a = new 	binary_tree_node<char>('A');
	binary_tree_node<char>* b = new 	binary_tree_node<char>('B');
	binary_tree_node<char>* o = new 	binary_tree_node<char>('O');
	binary_tree_node<char>* m = new 	binary_tree_node<char>('M');
	binary_tree_node<char>* w = new 	binary_tree_node<char>('W');
	binary_tree_node<char>* n = new 	binary_tree_node<char>('N');

	f->set_left(c); f->set_right(o);
	c->set_left(a); a->set_right(b);
	o->set_left(m); m->set_right(n);
	o->set_right(w);

	int sz = tree_depth(f);
	cout << "tree depth is " << sz << endl << endl;

	cout << "Pre-Order printing orginal tree.........." << endl;
	preorder(printout<char>, f);
	cout << endl;

	cout << "In-Order printing orginal tree.........." << endl;
	inorder(printout<char>, f);
	cout << endl;

	cout << "Post-Order printing orginal tree.........." << endl;
	postorder(printout<char>, f);
	cout << endl;

	cout << "Backward In-Order printing orginal tree.........." << endl;
	backwardinorder(printout<char>, f);
	cout << endl;

	/*
	cout << "in order modifying the tree.........." << endl;
	inorder(setX<char>, f);

	cout << "in order printing modified tree.........." << endl;
	inorder(printout<char>, f);
	*/
}