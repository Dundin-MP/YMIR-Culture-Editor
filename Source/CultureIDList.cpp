#include "CultureIDList.h"
//#include <iostream>
void    cultureIDList::setIDEntry(int entryID, string entryName, bool entryCons, bool entryProd){   //Set name, canCons, hasProdMin of entry 'ID'.
    entry[entryID].name = entryName;
    entry[entryID].canCons = entryCons;
    entry[entryID].hasProdMin = entryProd;
}

void    cultureIDList::loadFromFile(){                                                            //Populate entries from file.
    ifstream inFile;
    int loopTooLong = 0;
    string inString;
    inFile.open("Culture_Editor_Files/Culture_ID_List.txt");
    if(!inFile.is_open()){  //If file doesn't open
        //ERROR;
        return;}
    while(!inFile.eof()){   //If file opens
        getline(inFile, inString);
        parseFileLine(inString);
        loopTooLong++;
        if(loopTooLong>199){
            resetIDList();
            break;
        }
    }
    inFile.close();
}

void    cultureIDList::parseFileLine(string inString){                                          //Gather bracketed values: from ID[1]	canConsume[1]	productionMinimum[1]	Name[Hammers]
    int substrStart = 0;
    int substrLen = -2;
    int inID;
    string inName;
    bool inCons, inProd;
    for(int i = 0; i<4; i++){
        inString = inString.substr(substrStart + substrLen + 2);
        substrStart = inString.find("[")+1;
        substrLen = inString.find("]") - substrStart;
        if(i == 0)
            inID = stoi(inString.substr(substrStart, substrLen));
        if(i == 1)
            inCons = (bool)stoi(inString.substr(substrStart, substrLen));
        if(i == 2)
            inProd = (bool)stoi(inString.substr(substrStart, substrLen));
        if(i == 3)
            inName = inString.substr(substrStart, substrLen);
    }
    setIDEntry(inID, inName, inCons, inProd);
}

void    cultureIDList::resetIDList(){                                                               //Set all culture ID values to 0.
        for(int i = 0; i < 200; i++){
        entry[i].name = "";
        entry[i].canCons = false;
        entry[i].hasProdMin = false;
    }
}

        cultureIDList::cultureIDList(){                                                             //Initializer.
    resetIDList();
    loadFromFile();
}

string  cultureIDList::getName(int location){                                                       //Retrieve name of input ID.
    return entry[location].name;
}
int     cultureIDList::getID(string entryName){                                                     //Retrieve ID of input name.
    for(int i = 0; i < 200; i++){
        if(entry[i].name==entryName){
            return i;
        }
    }
    return -1;
}
bool    cultureIDList::checkCanCons(int ID){                                                           //Retrieve canCons of input ID.
    return entry[ID].canCons;
}
bool    cultureIDList::checkProdMin(int ID){                                                           //Retrieve hasProdMin of input ID.
    return entry[ID].hasProdMin;
}

