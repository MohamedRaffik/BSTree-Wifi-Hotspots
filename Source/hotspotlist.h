/***********************************************************************

 Title         : hotspotlist.h
 Author        : Mohamed Raffik
 Created on    : October 24, 2017
 Description   : Interface file of the Hotspot class
 Purpose       :

 Modifications : December 5, 2017
                 -Addition of the save_by_boro function
                 -Editing certain functions to traverse through Binary
                  Trees where necessary

***********************************************************************/



#ifndef __HOTSPOTLIST_H__
#define __HOTSPOTLIST_H__

#include "hotspot.h"
#include "bst.h"

class HSList
{
public:

	/** HSList() - default constructor of the class */
	HSList() {}

	/** write() - puts the data of the Binary Tree onto a out stream
	 * @pre    - The ostream is opened
	 * @post   - Data is outputted onto the stream in the form given in the print() function of the Hotspot Class
     * @return - Returns the number of items put on the stream
	 */
	int write(ostream & s);


	/** insert() - inserts a Hotspot object into the Binary Tree of this class
     * @pre    - The Hotspot object was constructed appropiately
	 * @post   - The Hotspot object is inserted if it is unique in the tree, else it is not
	 * @return - Return 1 if it was inserted successfully, else it returns 0
	 */
	int insert(const Hotspot & hotspot);


	/** insert() - inserts a Binary Tree from another HSList object into this class
	 * @pre    - None
	 * @post   - The Binary Tree is successfully inserted in the Binary Tree of this class while remaining sorted
	 * @return - Returns the number of items successfully inserted into the list
	 */
	int insert(const HSList & list);


	/** remove() - removes a Hotspot Object matching the given ObjectId from the Binary Tree
	 * @pre    - The ObjectId given is a valid integer
	 * @post   - The Hotspot Object matching the Object Id is removed from the list
	 * @return - Returns 1 if the matching Object is removed successfully, else it returns 0
	 */
	int remove(int ObjectID);


	/** size() - returns the length of the linked list */
    int size();


	/** retrieve() - finds a Hotspot Object matching the ObjectId and passes it into the hotspot data member
	 * @pre    - The ObjectId is a valid integer
	 * @post   - The ObjectId that matches a Hotspot object in the Binary Tree is passed to the hotspot data member
	 * @return - Returns 1 is the object was found and passed, else it returns 0
	 */
    int retrieve(int ObjectID, Hotspot & hotspot);


	/** make_empty() - removes all Hotspot objects from the Binary Tree
	 * @pre    - None
	 * @post   - The Binary Tree will be empty with a height of zero
	 * @return - Returns the number of items removed from the list
	 */
	int make_empty();


	/** get_list() - returns the Binary Tree of a HSList object
	 * @pre    - None
	 * @post   - None
	 * @return - The Binary Tree of the HSList object
	 */
    BTree<Hotspot> get_list() const;


	/** save_by_id() - reads an ObjectID file and prints the matching Hotspot objects to a csv file
	 * @pre    - The infile is a valid ObjectID file containing valid ObjectIDs
	 * @post   - The matching Hotspot Objects are printed to the outfile
	 * @return - Returns true if successful else it is false
	 */
	bool save_by_id(string infile, string outfile);


	/** save_by_loc() - based off of a given latitude, longitude, and distance any Hotspot Objects within range of the position given have their ObjectIDs printed to a given ObjectID file
	 * @pre    - None
	 * @post   - The Hotspot Objects that match the conditions have their ObjectIDS printed to the outfile
	 * @return - Returns true if successfully printed to a file, else returns false
	 */
	bool save_by_loc(const double & la, const double & lon, const double & dist, string outfile);


	/** insert() - inserts Hotspot objects created from a valid csv file and inputs them into the Binary Tree of the HSList object
	 * @pre    - The infile is a valid csv file
	 * @post   - The objects, if unique, are inputted into the list
	 * @return - Returns true if the objects are inserted successfully, else it is false
	 */
	bool insert(string infile);


	/** delete_by_id() - removes Hotspot objects in the Binary Tree matching ObjectIds from a valid ObjectId file
	 * @pre - The infile is a valid objectId file
	 * @post - The Hotspot objects matching the ObjectIds are removed from the list
	 * @return - Returns true if the objects were removed successfully, else returns false
	 */
	bool delete_by_id(string infile);


	/** save_by_boro() - finds Hotspot Objects matching the given boro and prints it to the given file
	 * The binary tree of the HSList object is searched through finding any Hotspot objects that match the
	 * given borocode
	 * @pre    - None
	 * @post   - Matching Hotspot objects are printed to the outfile
	 * @return - False if the file could not be opened, else true
	 */
	bool save_by_boro(Boro_type borocode, string outfile);


	/** write() - prints all of the data in the Binary Tree to a given csv file
	 * @pre - The outfile is a valid csv file
	 * @post - The Hotspot Objects of the Binary Tree are printed to the outfile
	 * @return - Returns true if successful, else returns false
	 */
	bool write(string outfile);

private:

	/* Binary Tree containing Hotspot Objects */
	BTree<Hotspot> hotspotlist;

};



#endif // __HOTSPOTLIST_H__
