#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#pragma warning( disable : 4290 )  // For Visual Studio handling of // throw

#include <vector>
#include <string>
using namespace std;

class LinkedList
{
	/*
		Implements a doubly-linked list of strings 
		All copies are deep copies.	No memory leaks are created.
		Indices start at 0. E.g, a LinkedList with n strings has indices 0, 1, ..., n-1.
	*/
public:

	/*******************************************************************
		Default Constructor
	********************************************************************/
	LinkedList();

	/*******************************************************************
		Copy Constructor for vector. 
		
			Converts a vector of strings to a Linked List of strings

		Input Only:
			strings - a vector of strings
	********************************************************************/
	LinkedList(vector<string> &strings);

	/*******************************************************************
		Copy Constructor
	*/
	LinkedList(const LinkedList &other);

	/*******************************************************************
		Overload of assignment operator
	********************************************************************/
	LinkedList operator=(const LinkedList &other);

	/*******************************************************************
		Destructor
	********************************************************************/
	~LinkedList();

	/*******************************************************************
		add

			adds the element to the end of the list
		
		Input Only:
			element - the element to add

	********************************************************************/
	void add(string element);

	/*******************************************************************
		addToFront

		adds the element to the front of the list

		Input Only:
			element - the element to add

	********************************************************************/
	void addToFront(string element);

	/*************************************************************************************
		addToRear

			adds the element to the end of the list

		Input Only:
			element - the element to add

	************************************************************************************/
	void addToRear(string element);

	/*************************************************************************************
		addAt

			adds the element to the list at the specified index
			all strings (if any) starting at 'index' are moved from index 'ii' to 'ii+1'

		Input Only:
			element - the element to add

	**************************************************************************************/
	void addAt(string element, int index) throw(string);

	 /*************************************************************************************
		addBefore

			adds the elementToAdd to the list at the position of elementToAddBefore
			all strings starting at the position of elementToAddBefore are moved from 
			index 'ii' to 'ii+1'

		Input Only:
			elementToAdd - the element to add
			elementToAddBefore - after elementToAdd is added, this element will
			immediately follow it.
			All indices ii from the index of elementToAdd will have become ii+1

		// throws:
			string "String not found" if elementToAddBefore is missing

	**************************************************************************************/
	void addBefore(string elementToAdd, string elementToAddBefore) throw(string);

	/*************************************************************************************
		addAfter

		adds the elementToAdd to the list at the position immediately after the 
		elementToAddAfter
		all strings starting at the position of elementToAddAfter + 1 are moved from
		index 'ii' to 'ii+1'

		Input Only:
			elementToAdd - the element to add
			elementToAddAfter - after elementToAdd is added, this element will immediately precede it
			All indices ii from the index of elementToAdd will have become ii+1
			
		// throws:
			string "String not found" if elementToAddAfter is missing
	**************************************************************************************/
	void addAfter(string elementToAdd, string elementToAddAfter)  throw(string);

	/*************************************************************************************
		remove

			removes 'element' from the list. The remaining elements keep their same relative poisitions.
			The indices of the elements after 'element' are reduced by 1.

		Input Only:
			element - the element to remove

		// throws:
			string "String not found" if element is missing
	**************************************************************************************/
	void remove(string element)  throw(string);

	/*************************************************************************************
		removeAt

		removes the element at the specified index in the list. The remaining elements keep
		their same relative poisitions.
		The indices of the elements after index' are reduced by 1.

		Input Only:
			index - the index to remove

		// throws:
			string "Index out of range" if index is missing
	**************************************************************************************/
	void removeAt(int index) throw(string);

	/*************************************************************************************
		removeFront

			removes the element at the front of the list. The remaining elements keep 
			their same relative poisitions.
			The indices of the elements after index' are reduced by 1.

		// throws:
			string "List is empty" if list is empty
	**************************************************************************************/
	void removeFront() throw(string);

	/*************************************************************************************
		removeRear

			removes the element at the rear of the list. The remaining elements keep
			their same relative poisitions.

		// throws:
			string "List is empty" if list is empty
	**************************************************************************************/
		void removeRear () throw(string);

	/*************************************************************************************
		getAt

			returns the element at 'index'. the list does not change

		Input Only:
			index - the index of the desired element

		Returns
			the element at 'index'

		// throws:
			string "Index out of range" if index is missing
	**************************************************************************************/
	string getAt(int index) const throw(string);

	/*************************************************************************************
		getFront

			returns the element at the front of the list. the list does not change

			Returns
				the element at the front of the list

		// throws:
			string "List is empty" if list is empty
	**************************************************************************************/
	string getFront() const throw(string);

	/*************************************************************************************
		getRear

			returns the element at the rear of the list. the list does not change

		Returns
			the element at the read of the list

		// throws:
			string "List is empty" if list is empty
	**************************************************************************************/
	string getRear() const throw(string);

	/*************************************************************************************
		getCount

			returns the number of elements in the list. the list does not change

		Returns:
			number of elements in the list. the list does not change

	**************************************************************************************/
	int getCount() const;

	/*************************************************************************************
		isEmpty

			returns true if list is empty, false otherwise. the list does not change

		Returns:
			returns true if list is empty, false otherwise.

	********************************************************************/
	bool isEmpty() const;

	/*************************************************************************************
		isPresent

			returns true if 'element' is in the list, false otherwise. the list does not change

		Returns:
			true if 'element' is in the list, false otherwise.

	**************************************************************************************/
	bool isPresent(string element) const;

	/*************************************************************************************
		toVector

			returns vector of strings that contains the strings in the list optionally sorted.
			the list does not change

		Input Only:
			sorted - if true the vector is sorted, if false the vector is in the order of 
					the list
	
		Returns:
		    the vector as specified by 'sorted'

	**************************************************************************************/
	vector<string> toVector(bool sorted) const;

	/*************************************************************************************
		operator+

			Creates a new list by adding every element of 'other' to the end of the list
			with the following caveats:
				1. the elements of the list do not change their order
				2. the elements of 'other' do not change their order
				3. an element of 'other' is NOT added to list if already present in the list
				4. Neither operand is changed

		Input Only:
			other - the list to add

		Returns:
			the list as specified above

	**************************************************************************************/
	LinkedList operator+(const LinkedList &other) const;

	/*************************************************************************************
		operator-

		Creates a new list by removing every element of 'other' from the list with the 
		following caveats:
			1. the elements of the list do not change their order
			2. the elements of 'other' do not change their order
			3. if an element of 'other' is not present in the list, the list does not change
			4. Neither operand is changed

		Input Only:
			other - the list to subtract

		Returns:
			the list as specified above

	**************************************************************************************/
	LinkedList operator-(const LinkedList &other) const;

	/*************************************************************************************
		operator==

		returns true if and only if every element of 'other' is also an element of the list.
		order if elements is NOT important.

		Input Only:
			other - the list to compare

		Returns:
		    see above

	**************************************************************************************/
	bool operator==(const LinkedList &other) const;

	/*************************************************************************************
		operator<<

			Sends 'list' to the 'os' so that it matched my output.

		Input Only:
			os - the ostream to send the list to
			list - the list to send to 'os'

	Returns:
	see above

	**************************************************************************************/
	friend ostream &operator<<(ostream &os, const LinkedList &list);

private:

	class Node
	{
		friend class LinkedList;

	public:
		inline Node *getNext() const
		{
			return mNext;
		};

		inline string getData()
		{
			return mData;
		}

	private:
		inline Node(string data)
		{
			mPrevious = mNext = 0;
			mData = data;
		}
		
		string mData;
		Node *mPrevious;
		Node *mNext;
	};

	void init();
	void copyAll(const LinkedList &other);
	void deleteAll();
	Node *getNodeAtIndex(int index) const throw(string);

	int find(string s) const;

	Node *mFront;
	Node *mRear;

};
#endif
