/***********************************************************************

 Title         : bst.h
 Author        : Mohamed Raffik
 Created on    : December 4, 2017
 Description   : Interface file for the template classes of Node, BST,
                 and BTree (Derived from BST)
 Purpose       :

 Modifications :

***********************************************************************/



#ifndef __BST_H__
#define __BST_H__

#include <stack>
#include <iostream>

using namespace std;

template <class T>
class Node
{
    public:

        /** Node() - constructor of the Node class **/
        Node (T & new_data);

		Node<T> * left_node;   // Left branch of type Node <T> *

		Node<T> * right_node;  // Right branch of type Node <T> *

		T data;                // Data of type T
};


template <class T>
class BST
{
	public:

        /** BST() - default constructor of BST **/
		BST();

		/** Binary Tree Modifiers **/
		virtual int insert(T & data) = 0;

		virtual int remove(const T & data) = 0;

		virtual int make_empty() = 0;

		/** Binary Tree search methods **/
        virtual T retrieve(const T & data) = 0;

		virtual T get_smallest() = 0;

		/** Prints Binary Tree **/
		virtual void print(ostream & s) = 0;
};



template <class T>
class BTree : public BST<T>
{
	public:

        /** BTree() - default constructor of BTree **/
		BTree();

		/** insert() - adds  Node object holding the data of type T into the Binary Tree
		 * @pre -    Data is of a valid type T
		 * @post -   The data will be inserted into the Tree if it is unique
		 * @return - 1 if the data was successfully insert, else 0
		 */
		int insert(T & data);

		/** remove() - removes a Node object containing identical data to the T data passed
		 * @pre -    Data is of a valid type T
		 * @post -   The Node will be removed if it is found in the tree
		 * @return - 1 if the data was successfully removed, else 0
		 */
		int remove(const T & data);

		/** retrieve() finds a node object with the matching data type and returns it
		 * @pre -    The data passed is of a valid type T
		 * @post -   None
		 * @return - Data of type T
		 */
		T retrieve(const T & data);

		int make_empty();

		T get_smallest();

		void print(ostream & s);

		int length();

		int merge(BTree new_tree);

		Node <T> * get_root() { return head_node; }

	private:

		Node<T> * head_node;

		int size;
};

#include "bst.cpp"

#endif // __BST_H__
