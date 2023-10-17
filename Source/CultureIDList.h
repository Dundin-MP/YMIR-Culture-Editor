#ifndef CULTUREIDLIST
#define CULTUREIDLIST
#include <string>
#include <fstream>
//#include "CultureSettings.h"
using namespace std;
class cultureIDList{
private:
    struct{ //pointer offset is ID, string name, bool canCons, short offsetProduction
        string  name;
        bool    canCons;
        bool    hasProdMin;
    }           entry[200];

    void    setIDEntry(int, string, bool, bool);/*      Set location values.
    Preconditions:
        Existing input parameters.
    Postconditions:
        For ID, following values are set.
            Name
            canCons
            hasProdMin
        No return.
    */
    void    loadFromFile();/*                           Populate entries from file.
    Preconditions:
        Static filename exists.
    Postconditions:
        All entries with an applicable ID in file are populated from const file.
        No return.
    */
    void    parseFileLine(string);/*
    Preconditions:
        Existing input parameter.
    Postconditions:
        The following values are found in the input parameter and passed into setIDEntry.
            ID
            Name
            canCons
            hasProdMin
        No return.
    */
    void    resetIDList();/*                            Set all culture ID values to 0*/
public:
            cultureIDList();/*                          Initializer.
    preconditions:
        Filename static exists.
    postconditions:
        All entries with an applicable ID in file are initialized and populated from file.
        All entries without an applicable ID in file are initialized and empty.
    */

    string  getName(int);/*                             Retrieve name of input ID.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Return Name.
    */
    int     getID(string);/*                            Retrieve ID of input name.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Return ID.
    */
    bool    checkCanCons(int);/*                           Retrieve canCons of input ID.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Return canCons.
    */
    bool    checkProdMin(int);/*                           Retrieve hasProdMin of input ID.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Return hasProdMin.
    */
};
#endif // CULTUREIDLIST
