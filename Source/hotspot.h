/***********************************************************************

 Title         : hotspot.h
 Author        : Mohamed Raffik
 Created on    : September 24, 2017
 Description   : Interface file of the Hotspot class
 Purpose       :

 Modifications : December 1, 2017
                 -split() was modified to handle all possible cases
                 when parsing a line from a csv file
                 -boro_to_string() and string_to_boro() functions were modified
                 to accommodate the new Boro of type Unknown
                 -New compare_boro() function
                 -A new ostream operator was used to allow the template classes
                 to print this type of data
                 -New print_id() function

***********************************************************************/


#ifndef __HOTSPOT_H__
#define __HOTSPOT_H__

#include "command.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>


using namespace std;


class Hotspot
{
public:

	/** Hotspot() - default constructor */
    Hotspot() {}


	/** Hotspot() - constructor of Hotspot that takes a string
	 * @pre  - The string is a valid line to create a Hotspot file
	 * @post - A Hotspot object is constructed
	 */
    Hotspot(const string s);


	/** Hotspot() - constructor of a Hotspot object that takes another Hotspot Object
	 * @pre - None
	 * @post - The constructed Hotspot will be equal to the Hotspot Object passed
	 */
    Hotspot(const Hotspot & hotspot);


	/** Hotspot() - constructor of a Hotspot object by setting the data members
	 * @pre  - The data passed match the types of the data members
	 * @post - The constructed Hotspot object data members are equal to the given data
	 */
    Hotspot(const int obj_id, Boro_type boro, string type, string provider, string name, string location, double latitude, double longitude, string ssid);


	/** set() - sets the data members of the Hotspot Object to the given data
	 * @pre    - The data passed matches the type of the data members
	 * @post   - The data members are equal to the data given
	 * @return - None
	 */
    void set(int obj_id, Boro_type boro, string type, string provider, string name, string location, double latitude, double longitude, string ssid);


	/** get() - passes the data members of the Hotspot object to the given parameters
	 * @pre    - The parameters match the types of the data members
	 * @post   - The parameters are equal to the data members
	 * @return - None
	 */
    void get(int & obj_id, Boro_type & boro, string & type, string & provider, string & name, string & location, double & latitude, double & longitude, string & ssid);


	/** print() - outputs the data members of the Hotspot Object to an ostream in the form : "ObjectID,Boro,Type,Provider,Name,Location,Latitude,Longitude,SSID" **/
    void print(ostream & s);


    /** print_id() - outputs only the ObjectId of the Hotspot Object to an ostream **/
    void print_id(ostream & s);


	/** compare_boro - compares the Boro of the current hotspot object with the given borocode
	 * @pre - None
	 * @post - None
	 * @return - Returns true if the boro given is equal to the hotspot boro, else it is false
	 */
   	bool compare_boro(Boro_type boro);


    /** distance() - returns the distance of the current Hotspot object to the point specified by the latitude and longitude **/
   	double distance(double latitude, double longitude);


	/** <() - compares two Hotspot Objects
	 * @pre    - None
	 * @post   - None
	 * @return - Returns true it lt's ObjectID < rt's ObjectID, else it is false
	 */
    friend bool operator< (const Hotspot & lt, const Hotspot & rt);


	/** ==() - compares two Hotspot Objects
	 * @pre    - None
	 * @post   - None
	 * @return - Returns true if lt's ObjectID is equal to rt's ObjectID, else it is false
	 */
    friend bool operator==(const Hotspot & lt, const Hotspot & rt);


	/** <<() - prints the contents of the hotspot to an ostream	*/
    friend ostream & operator<<(ostream & s, const Hotspot & t);

private:

	/** split() - function only used by the Hotspot(string s) constructor
	 * @pre    - Pos is less than the length of the line
	 * @post   - A substring if parsed from line based off of the limit or the length of the line, pos will be the number as a counter over the string
	 * @return - Returns the substring from the beginning of the string to the limit or the length of the line
	 */
	string split(string line, int & pos);


	/** boro_to_string() - converts a Boro_type parameter to a string, used only by print()
	 * @return - Returns either "MN" , "BK", "BX", "QU", "SI", or "UNKNOWN"
	 */
	string boro_to_string(Boro_type boro) const;


	/** string_to_boro - converts a string to a Boro_type, used only by print()
	 * @return - Returns a Boro_type within the Boro_type enum
	 */
	Boro_type string_to_boro(string boro);


    int       ObjectId;       // Any valid integer
    Boro_type Boro;           // A valid Boro_type or num_Boro for an unknown type
    string    Type;           // A string of the type of Hotspot (ex. "Free")
    string    Provider;       // A string of the provider of the Hotspot (ex. DowntownWifi)
    string    Name;           // A string of the name of the Hotspot
    string    Location;       // A string of the location of the Hotpot
    double    Latitude;
    double    Longitude;
    string    SSID;
};



#endif // __HOTSPOT_H__
