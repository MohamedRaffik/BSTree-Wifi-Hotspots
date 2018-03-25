/***********************************************************************

 Title         : hotspot.cpp
 Author        : Mohamed Raffik
 Created on    : October 24, 2017
 Description   : Function definitions of the Hotspot interface
 Purpose       :

 Modifications : See hotspot.h modifications

***********************************************************************/



#include "hotspot.h"
#include <cmath>
#include <iomanip>


const double R = 6372.8;              // radius of earth in km
const double TO_RAD = M_PI / 180.0;   // conversion of degrees to rads

double haversine(double lat1, double lon1, double lat2, double lon2)
{
	lat1       *= TO_RAD;
	lat2       *= TO_RAD;
	lon1       *= TO_RAD;
	lon2       *= TO_RAD;

	double dLat = (lat2 - lat1) / 2;
	double dLon = (lon2 - lon1) / 2;
	double a    = sin(dLat);
	double b    = sin(dLon);

	return 2 * R * asin(sqrt(a * a + cos(lat1) * cos(lat2) * b * b));
}


string Hotspot::split(string line, int & pos)
{
    string s;

    if (pos >= (signed)line.length()) { return s; }

    if (line[pos] == '"')
    {
        for (; pos < (signed)line.length(); pos++)
        {
            if (line[pos] == '"')
            {
                if (line[pos+1] == ',') { s += line[pos]; pos++; pos++; break; }
            }

            s += line[pos];
        }
    }

    else
    {
        for (; pos < (signed)line.length(); pos++)
        {
            if (line[pos] == ',')
            {
                if (line[pos+1] != ' ') { pos++; break; }
            }

            s += line[pos];
        }
    }

    return s;
}


string Hotspot::boro_to_string(Boro_type boro) const
{
    if (MN == boro) { return "MN"; }

    else if (BX == boro) { return "BX"; }

    else if (BK == boro) { return "BK"; }

    else if (QU == boro) { return "QU"; }

    else if (SI == boro) { return "SI"; }

    else { return "UNKNOWN"; }
}


Boro_type Hotspot::string_to_boro(string boro)
{
    if ("MN" == boro) { return MN; }

    else if ("BX" == boro) { return BX; }

    else if ("BK" == boro) { return BK; }

    else if ("QU" == boro) { return QU; }

    else if ("SI" == boro) { return SI; }

    else { return BAD_BORO; }
}


bool Hotspot::compare_boro(Boro_type boro)
{
    if (this->Boro == boro) { return true; }
    return false;
}


double Hotspot::distance(double latitude, double longitude)
{
    double dist = haversine(Latitude, Longitude, latitude, longitude);

    return dist;
}


Hotspot::Hotspot(const string s)
{
    int pos = 0;

    string obj = split(s, pos);
    ObjectId   = atof(obj.c_str());

    string boro = split(s, pos);
    Boro = string_to_boro(boro);

    Type        = split(s, pos);
    Provider    = split(s, pos);
    Name        = split(s, pos);
    Location    = split(s, pos);

    string latitude = split(s, pos);
    Latitude        = atof(latitude.c_str());

    string longitude = split(s,pos);
    Longitude        = atof(longitude.c_str());

    SSID = split(s, pos);
}



Hotspot::Hotspot(const Hotspot & hotspot)
{
    ObjectId  = hotspot.ObjectId;
    Boro      = hotspot.Boro;
    Type      = hotspot.Type;
    Provider  = hotspot.Provider;
    Name      = hotspot.Name;
    Location  = hotspot.Location;
    Latitude  = hotspot.Latitude;
    Longitude = hotspot.Longitude;
    SSID      = hotspot.SSID;
}


Hotspot::Hotspot(const int obj_id, Boro_type boro, string type, string provider, string name, string location, double latitude, double longitude, string ssid)
{
    ObjectId  = obj_id;
    Boro      = boro;
    Type      = type;
    Provider  = provider;
    Name      = name;
    Location  = location;
    Latitude  = latitude;
    Longitude = longitude;
    SSID      = ssid;
}


void Hotspot::set(int obj_id, Boro_type boro, string type, string provider, string name, string location, double latitude, double longitude, string ssid)
{
    ObjectId  = obj_id;
    Boro      = boro;
    Type      = type;
    Provider  = provider;
    Name      = name;
    Location  = location;
    Latitude  = latitude;
    Longitude = longitude;
    SSID      = ssid;
}


void Hotspot::get(int & obj_id, Boro_type & boro, string & type, string & provider, string & name, string & location, double & latitude, double & longitude, string & ssid)
{
    obj_id    = ObjectId;
    boro      = Boro;
    type      = Type;
    provider  = Provider;
    name      = Name;
    location  = Location;
    latitude  = Latitude;
    longitude = Longitude;
    ssid      = SSID;
}



void Hotspot::print(ostream & s)
{
    s << setprecision(15) << ObjectId << ',' << boro_to_string(Boro) << ',' << Type << ',' << Provider << ',' << Name << ',' << Location << ',' << Latitude << ',' << Longitude << ',' << SSID << endl;
}


void Hotspot::print_id(ostream & s)
{
    s << ObjectId << endl;
}


bool operator<(const Hotspot & lt, const Hotspot & rt)
{
    return lt.ObjectId < rt.ObjectId;
}


bool operator==(const Hotspot & lt, const Hotspot & rt)
{
    return lt.ObjectId == rt.ObjectId;
}


ostream & operator<<(ostream & s, const Hotspot & t)
{
    s << setprecision(15) << t.ObjectId << ',' << t.boro_to_string(t.Boro) << ',' << t.Type << ',' << t.Provider << ',' << t.Name << ',' << t.Location << ',' << t.Latitude << ',' << t.Longitude << ',' << t.SSID << endl;

    return s;
}
