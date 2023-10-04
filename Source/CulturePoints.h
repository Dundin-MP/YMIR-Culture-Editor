#ifndef CULTUREPOINTS
#define CULTUREPOINTS
#include <string>
#include "CultureIDList.h"
#include "CultureSettings.h"
#define NUM_OF(x) (sizeof(x)/sizeof(*x))

using namespace std;
class culturePoints{
private:
    cultureIDList *IDList;
    cultureSettings *settings;
    int         entryCount,     pointsCount;
    struct{ //  entry[500].name,    entry[500].ID,  entry[500].consumption,     entry[500].production
        string  name;                                       //Name of the culture
        short   ID;                                         //Culture ID of the entry
        short   consumption;                                //Points spent in Consumption
        short   production;                                 //Points spent in Production
    }       entry[500];

    int     countPoints(int);/*                                                 Return how much CP is spent on a points entry.
    Preconditions:
        Existing input parameter.
    Postconditions:
        CP cost of entry returned.
    */
    int     findEntry(short);/*                                                 Return location of parameter, else return -1.
    Precondition:
        Existing input parameter.
    Postcondition:
        Location of entry returned.
    */
    int     findEntry(string);/*                                                Return location of parameter, else return -1.
    Precondition:
        Existing input parameter.
    Postcondition:
        Location of entry returned.
    */
    void    editEntry(int, string, short, short, short, bool alwPts = 0);/*                      Edit every value in indicated points entry.
    Preconditions:
        Existing entry parameters.
    Postconditions:
        Indicated entry edited.
    */
    void    addEntry(string, short, short, short, bool alwPts = 0);/*           Add new points entry and specify every value.
    Preconditions:
        Existing entry parameters.
    Postconditions:
        New entry added and populated.
    */

public:
            culturePoints(cultureIDList&, cultureSettings&);/*                  Initializer.
    Preconditions:
        Existing input parameters.
    Postconditions:
        Class initialized to 'new game' values.
        Pointer to Culture ID list set.
    */

    void    removeEntry(int);/*                                                 Remove indicated points entry.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Indicated entry removed.
        EntryCount may change.
        PointsCount may change.
        Nothing returned.
    */
    void    removeEntryID(short);/*                                             Remove indicated points entry.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Indicated entry removed.
        EntryCount may change.
        PointsCount may change.
        Nothing returned.
    */
    void    removeEntryName(string);/*                                          Remove indicated points entry.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Indicated entry removed.
        EntryCount may change.
        PointsCount may change.
        Nothing returned.
    */
    void    addEntry(short, short, short, bool alwPts = 0);/*                   Add a points entry to the list by ID.
    Preconditions:
        Existing input parameters.
    Postconditions:
        Entry added with input values.
        Nothing returned.
    */
    void    addEntry(string, short, short, bool alwPts = 0);/*                  Add a points entry to the list by name.
    Preconditions:
        Existing input parameters.
    Postconditions:
        Entry added with input values.
        Nothing returned.
    */
    void    editEntry(int, short, short, short);/*                              Edit an existing points entry location by ID.
    Preconditions:
        Existing input parameters.
    Postconditions:
        Indicated entry edited to input values.
        Nothing returned.
    */
    void    editEntry(int, string, short, short);/*                             Edit an existing points entry location by name.
    Preconditions:
        Existing input parameters.
    Postconditions:
        Indicated entry edited to input values.
        Nothing returned.
    */
    void    editEntry(short, short, short);/*                                   Edit an existing points entry by ID.
    Preconditions:
        Existing input parameters.
    Postconditions:
        Indicated entry edited to input values.
        Nothing returned.
    */
    void    editEntry(string, short, short);/*                                  Edit an existing points entry by name.
    Preconditions:
        Existing input parameters.
    Postconditions:
        Indicated entry edited to input values.
        Nothing returned.
    */
    void    getEntry(int, string&, short&, short&, short&, bool alwPts = 0);/*  Retrieve existing points entry values by location.
    Preconditions:
        Existing input and output parameters.
    Postconditions:
        Input parameters set to values at input location for return.
        Nothing returned.
    */
    void    getEntrybyName(string, short&, short&, short&, bool alwPts = 0);/*  Retrieve existing points entry values by name.
    Preconditions:
        Existing input and output parameters.
    Postconditions:
        Input parameters set to values at input location for return.
        Nothing returned.
    */
    void    getEntrybyID(string&, short, short&, short&, bool alwPts = 0);/*    Retrieve existing points entry values by ID.
    Preconditions:
        Existing input and output parameters.
    Postconditions:
        Input parameters set to values at input location for return.
        Nothing returned.
    */

    int     getSpentPoints();/*                                                 Retrieve quantity of spent CP.
    Preconditions:
        None.
    Postcondition:
        SpentPoints is returned.
    */
    int     getEntryCount();/*                                                  Retrieve quantity of points entries.
    Preconditions:
        None.
    Postcondition:
        EntryCount is returned.
    */

    void    purgeEmptyEntries();/*                                              Check every entry and remove any without points.
    Preconditions:
        None.
    Postconditions:
        Points entries may be removed.
        SpentPoints may change.
        EntryCount may change.
        Nothing returned.
    */
    void    purgeAllEntries();/*                                                Remove all culture entries.
    Preconditions:
        None.
    Postconditions:
        All points entries removed.
        SpentPoints may change.
        EntryCount may change.
        Nothing returned.
    */
};
#endif // CULTUREPOINTS
