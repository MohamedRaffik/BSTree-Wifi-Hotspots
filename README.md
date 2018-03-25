# BSTree-Wifi-Hotspots

This command-line program parses Wifi Data of New York City and implements a Binary Search Tree data structure to perform certain actions to the data set.

# Running Program

Ex: ./project4 [CSV FILE] [COMMAND FILE]
The program takes two command line arguments, the first being the hotspot data set and then a command file populated with valid commands as stated in the command.h file.

# Commands:

write [FILE] 
- Outputs the current state of the Binary Search Tree in the program to the file designated
insert[FILE] 
- Inserts data of Wifi Hotspots from the specified file, data must be presented in correct format
delete_by_id [FILE] 
- Removes Wifi Hotspots in the Binary Tree that match the ids given in the file
save_by_id [FROMFILE] [TOFILE] 
- Outputs specified Wifi Hotspots matching ids in the FROMFILE to the TOFILE
save_by_loc [LATITUDE] [LONGITUDE] [DISTANCE] [TOFILE] 
- Outputs Wifi Hotspots located within the specified distance from the point given to the file given
save_by_boro [BOROCODE] [TOFILE]
 BOROCODE Ex: MN (Manhattan), BX (Bronx), BK (Brooklyn), QU (Queens), SI (Staten Island)
- Outputs Wifi Hotspots located in the specified Borocode to the file specified
