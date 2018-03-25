/***********************************************************************

 Title         : hotspotlist.cpp
 Author        : Mohamed Raffik
 Created on    : October 24, 2017
 Description   : Function definitions of the HSList Interface
 Purpose       :

 Modifications : see hotspotlist.h for modifications

***********************************************************************/



#include "bst.h"
#include "hotspotlist.h"
#include <vector>
#include <string>


int HSList::write(ostream & s)
{
	hotspotlist.print(s);

	return hotspotlist.length();
}


int HSList::insert(const Hotspot & hotspot)
{
	Hotspot temp(hotspot);
	int success = hotspotlist.insert(temp);
	return success;
}


int HSList::insert(const HSList & hlist)
{
	int items = 0;
	items = hotspotlist.merge(hlist.get_list());
	return items;
}


int HSList::remove(int ObjectID)
{
	string extra = "1";
	Hotspot temp(ObjectID, num_Boros, extra, extra, extra, extra, 0, 0, extra);
	int success = hotspotlist.remove(temp);
	return success;
}


int HSList::size()
{
	int s = hotspotlist.length();
    return s;
}


int HSList::retrieve(int ObjectID, Hotspot & hotspot)
{
	string extra = "1";
	Hotspot temp(ObjectID, MN, extra, extra, extra, extra, 0, 0, extra);
	hotspot = hotspotlist.retrieve(temp);

	if (hotspot == temp) { return 1; }

	return 0;
}



int HSList::make_empty()
{
	int success = hotspotlist.make_empty();
	return success;
}


BTree<Hotspot> HSList::get_list() const { return hotspotlist; }


bool HSList::save_by_id(string infile, string outfile)
{
	ifstream in;
	in.open(infile.c_str());

	ofstream out;
	out.open(outfile.c_str());

	if (in.is_open())
	{
		string s;

		if (out.is_open())
		{
			while (getline(in,s))
			{
				bool valid = true;

				for (int i = 0; i < (signed)s.length(); i++)
				{
					if (!isdigit(s[i])) { valid = false; }
				}

				if (valid)
				{
					int ID = atof(s.c_str());

					Hotspot temp;
					int found = retrieve(ID, temp);
					if (found) { temp.print(out); }
				}

				else { cerr << "'" << s << "' is not a valid Object ID." << endl; }
			}
		}

		else { cerr << "'" << outfile << "' could not be opened." << endl; return false; }
	}

	else { cerr << "'" << infile << "' could not be opened." << endl; return false; }

	in.close();
	out.close();

	return true;
}



bool HSList::save_by_loc(const double & la, const double & lon, const double & dist, string outfile)
{
    ofstream out;
    out.open(outfile.c_str());

    if (out.is_open())
    {
        stack<Node<Hotspot>*> parents;

        Node<Hotspot> * current = hotspotlist.get_root();

        while (current != NULL)
        {
            parents.push(current);
            current = current->left_node;
        }

        while (!parents.empty())
        {
            current = parents.top();
            Hotspot temp = current->data;

            if (temp.distance(la, lon) <= dist) { temp.print_id(out); }

            current = current->right_node;
            parents.pop();

            while (current != NULL)
            {
                parents.push(current);
                current = current->left_node;
            }
        }
    }

	else { cerr << "'" << outfile << "' could not be opened." << endl; return false; }

	out.close();

	return true;
}



bool HSList::insert(string infile)
{
	ifstream in;
	in.open(infile.c_str());

	if (in.is_open())
	{
		string s;

		while (getline(in,s))
		{
			Hotspot temp(s);
			insert(temp);
		}
	}

	else { cerr << "'" << infile << "' could not be opened." << endl; return false; }

	in.close();

	return true;
}



bool HSList::delete_by_id(string infile)
{
	ifstream in;

	in.open(infile.c_str());

	if (in.is_open())
	{
		string s;

		while (getline(in,s))
		{
			bool valid = true;

			for (int i = 0; i < (signed)s.length(); i++)
			{
				if (!isdigit(s[i])) { valid = false; }
			}

			if (valid)
			{
				int ID = atof(s.c_str());
				remove(ID);
			}

			else { cerr << "'" << s << "' is not a valid Object ID." << endl; }
		}
	}

	else { cerr << "'" << infile << "' could not be opened." << endl; return false; }

	in.close();

	return true;
}


bool HSList::save_by_boro(Boro_type borocode, string outfile)
{
    ofstream out;
    out.open(outfile.c_str());

    if (out.is_open())
    {
        stack<Node<Hotspot>*> parents;

        Node<Hotspot> * current = hotspotlist.get_root();

        while (current != NULL)
        {
            parents.push(current);
            current = current->left_node;
        }

        while (!parents.empty())
        {
            current = parents.top();
            Hotspot temp = current->data;

            if (temp.compare_boro(borocode)) { temp.print_id(out); }

            current = current->right_node;
            parents.pop();

            while (current != NULL)
            {
                parents.push(current);
                current = current->left_node;
            }
        }
    }

	else { cerr << "'" << outfile << "' could not be opened." << endl; return false;}

	out.close();

	return true;
}




bool HSList::write(string outfile)
{
	ofstream out;
	out.open(outfile.c_str());

	if (out.is_open())
	{
		write(out);
	}

	else { cerr << "'" << outfile << "' could not be opened." << endl; return false; }

	out.close();

	return true;
}

