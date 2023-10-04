#include "CulturePoints.h"
//#include <iostream>
int     culturePoints::countPoints(int location){                           //Return how much CP is spent on a points entry.
    int returnInt = 0;
    returnInt += entry[location].consumption;
    returnInt += 2*entry[location].production;
    return returnInt;
}
int     culturePoints::findEntry(short entryID){                            //Return location of parameter, else return -1.
    int currentID;
    for(int i = 0; i < entryCount; i++){
        currentID = entry[i].ID;
        if(currentID == entryID){
            return i;
        }
    }
    return -1;
}
int     culturePoints::findEntry(string entryName){                         //Return location of parameter, else return -1.
    string currentName;
    for(int i = 0; i < entryCount; i++){
        currentName = entry[i].name;
        if(currentName == entryName){
            return i;
        }
    }
    return -1;
}

        culturePoints::culturePoints(cultureIDList& inIDList,                //Initializer.
                                     cultureSettings& inSettings){
    entryCount              = 0;
    pointsCount             = 0;
    for(int i = 0; i < NUM_OF(entry); i++){
        entry[i].name       = "";
        entry[i].ID         = 0;
        entry[i].consumption= 0;
        entry[i].production = 0;
    }
    IDList = &inIDList;
    settings = &inSettings;
}

void    culturePoints::removeEntry(int location){                           //Remove indicated points entry.
    pointsCount -= countPoints(location);
    for(int i = location; i< entryCount; i++){
        entry[i] = entry[i+1];
    }
    entry[entryCount-1].name        = "";
    entry[entryCount-1].ID          = 0;
    entry[entryCount-1].consumption = 0;
    entry[entryCount-1].production  = 0;
    entryCount --;
}
void    culturePoints::removeEntryID(short entryID){                        //Remove indicated points entry.
    int location = findEntry(entryID);
    //if location is -1:
    //error message
    //return;
    //else:
    removeEntry(location);
}
void    culturePoints::removeEntryName(string entryName){                   //Remove indicated points entry.
    int location = findEntry(entryName);
    //if location is -1:
    //error message
    //return;
    //else:
    removeEntry(location);
}
void    culturePoints::addEntry(string entryName,                           //Add new points entry and specify every value.
                                  short entryID, short entryCons, short entryProd,
                                  bool alwPts){
    int preExistingEntry = findEntry(entryID);
    if(preExistingEntry>=0){
        editEntry(preExistingEntry, entryName, entryID, entryCons, entryProd);
    }else{
        entry[entryCount].name        = entryName;
        entry[entryCount].ID          = entryID;
        entry[entryCount].consumption = entryCons;
        entry[entryCount].production  = entryProd;
        if((!settings->getShowProdLevel())&(!alwPts)){//distort only if showProdLevel & alwaysPoints are false
            entryProd -= IDList->checkProdMin(entryID);
        }
        pointsCount += countPoints(entryCount);
        entryCount ++;
    }
}
void    culturePoints::addEntry(short entryID,                              //Add a points entry to the list by ID.
                                  short entryCons, short entryProd, bool alwPts){
    string name = IDList->getName(entryID);
    //if name is "":
    //error message
    //return;
    //else:
    addEntry(name, entryID, entryCons, entryProd, alwPts);
}
void    culturePoints::addEntry(string entryName,                           //Add a points entry to the list by name.
                                  short entryCons, short entryProd, bool alwPts){
    int ID = IDList->getID(entryName);
    //if ID is -1:
    //error message
    //return;
    //else:
    addEntry(entryName, ID, entryCons, entryProd, alwPts);
}
void    culturePoints::editEntry(int location, string entryName,            //Edit every value in indicated points entry.
                  short entryID, short entryCons, short entryProd, bool alwPts){
    pointsCount -= countPoints(location);
    entry[location].name        = entryName;
    entry[location].ID          = entryID;
    entry[location].consumption = entryCons;
    entry[location].production  = entryProd;
    if((!settings->getShowProdLevel())&(!alwPts)){//distort only if showProdLevel & alwaysPoints are false
        entryProd -= IDList->checkProdMin(entryID);
    }
    pointsCount += countPoints(location);
}
void    culturePoints::editEntry(int location,                              //Edit an existing points entry location by ID.
                  short entryID, short entryCons, short entryProd){
    string localName = IDList->getName(entryID);
    editEntry(location, localName, entryID, entryCons, entryProd);
}
void    culturePoints::editEntry(int location,                              //Edit an existing points entry location by Name.
                  string entryName, short entryCons, short entryProd){
    int localID = IDList->getID(entryName);
    editEntry(location, entryName, localID, entryCons, entryProd);
}
void    culturePoints::editEntry(short entryID,                             //Edit an existing points entry by ID.
                                   short entryCons, short entryProd){
    int location = findEntry(entryID);
    //if location is -1:
    //error message
    //return;
    //else:
    editEntry(location, entryID, entryCons, entryProd);
}
void    culturePoints::editEntry(string entryName,                          //Edit an existing points entry by Name.
                                   short entryCons, short entryProd){
    int location = findEntry(entryName);
    //if location is -1:
    //error message
    //return;
    //else:
    editEntry(location, entryName, entryCons, entryProd);
}
void    culturePoints::getEntry(int location, string& entryName,            //Retrieve existing points entry values by location.
                        short& entryID, short& entryCons, short& entryProd,
                        bool alwPts){
    entryName   = entry[location].name;
    entryID     = entry[location].ID;
    entryCons   = entry[location].consumption;
    entryProd   = entry[location].production;
    if((!settings->getShowProdLevel())&(!alwPts)){//distort only if showProdLevel & alwaysPoints are false
        entryProd += IDList->checkProdMin(entryID);
    }
}
void    culturePoints::getEntrybyName(string entryName,                     //Retrieve existing points entry values by name.
                              short& entryID, short& entryCons, short& entryProd,
                              bool alwPts){
    int location = findEntry(entryName);
    //if location is -1:
    //error message
    //return;
    //else:
    getEntry(location, entryName, entryID, entryCons, entryProd, alwPts);
}
void    culturePoints::getEntrybyID(string& entryName,                      //Retrieve existing points entry values by ID.
                              short entryID, short& entryCons, short& entryProd,
                              bool alwPts){
    int location = findEntry(entryID);
    //if location is -1:
    //error message
    //return;
    //else:
    getEntry(location, entryName, entryID, entryCons, entryProd, alwPts);
}

int     culturePoints::getSpentPoints(){                                    //Retrieve quantity of spent CP.
    return pointsCount;
}
int     culturePoints::getEntryCount(){                                     //Retrieve quantity of points entries.
    return entryCount;
}

void    culturePoints::purgeEmptyEntries(){                                 //Check every entry and remove any without points.
    for(int i = entryCount-1; i >= 0; i--){
        if(countPoints(i)==0){
            removeEntry(i);
        }
    }
}
void    culturePoints::purgeAllEntries(){                                   //Remove all culture entries.
    for(int i = entryCount-1; i >= 0; i--){
        removeEntry(i);
    }
}

