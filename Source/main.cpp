/***********************************************************************

 Title         : main.cpp
 Author        : Mohamed Raffik
 Created on    : October 24, 2017
 Description   : Main file of the proj2 program
 Purpose       : Parses a csv file containing Hotspots throughout New York City and
				 places them into a linked list which can be modified through a set of commands
				 that are given from a text file

 Modifications : December 5, 2017
                 -Addition of the save_by_boro function/command

***********************************************************************/



#include "hotspot.h"
#include "hotspotlist.h"
#include "command.h"

int main(int argc, char *argv[])
{
   if (argc == 3)
   {
        ifstream datafile;

        datafile.open(argv[1]);

        if (datafile.is_open())
        {
            HSList hotspots;

            string line;

            while (getline(datafile, line))
            {
                Hotspot temp(line);
                hotspots.insert(temp);
            }

            datafile.close();

            ifstream cmdfile;
			cmdfile.open(argv[2]);

			if (cmdfile.is_open())
			{
				Command commands;

				while (commands.get_next(cmdfile))
				{
					Boro_type borocode;
					string infile, outfile;
					double lat = 0, lon = 0, dist = 0;
					bool result;

					commands.get_args(infile, outfile, lat, lon, dist, borocode, result);

					if (!result) { cerr << "Bad Command" << endl; }

					else
					{
						if (commands.type_of() == write_cmmd)             { hotspots.write(outfile); }

						else if (commands.type_of() == save_by_id_cmmd)   { hotspots.save_by_id(infile, outfile); }

						else if (commands.type_of() == save_by_loc_cmmd)  { hotspots.save_by_loc(lat, lon, dist, outfile); }

						else if (commands.type_of() == insert_cmmd)       { hotspots.insert(infile); }

						else if (commands.type_of() == delete_by_id_cmmd) { hotspots.delete_by_id(infile); }

						else if (commands.type_of() == save_by_boro_cmmd) { hotspots.save_by_boro(borocode, outfile); }
					}
				}
			}

			else { cerr << "Could not open file '" << argv[2] << "'" << endl; }

			hotspots.make_empty();
        }

        else { cerr << "Could not open file '" << argv[1] << "'" << endl; }
   }

   else { cerr << "Invalid number of arguments" << endl; }
}
