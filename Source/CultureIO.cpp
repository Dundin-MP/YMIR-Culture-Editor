#include "CultureIO.h"

void    cultureIO::assignPointers(cultureInfo& inInfo,              //Assign local and class communication pointers.
                                 culturePoints& inPoints,
                                 cultureSettings& inSet){
    something       = &(cultureRaw[0].fileSide[2]);
    blockNum        = &(cultureRaw[0].fileSide[0]);
    blockSize       = &(cultureRaw[0].fileSide[1]);
    available_CP    = &(cultureRaw[2].progSide);
    culture_Prog    = &(cultureRaw[3].progSide);
    culture_LVL     = &(cultureRaw[4].progSide);
    unsure_1        = &(cultureRaw[5].progSide);
    prog_Rate       = &(cultureRaw[6].progSide);
    bonus_CP        = &(cultureRaw[7].progSide);
    unsure_2        = &(cultureRaw[8].progSide);
    infoIO          = &inInfo;
    pointsIO        = &inPoints;
    settingsIO      = &inSet;
}
void    cultureIO::assignDefaults(){                                //Assign local default values by pointer.
    *something  = 602;
    *blockNum   = 28;
    *blockSize  = 16;
}
int     cultureIO::hex8ToInt(string entry8Hex){                     //Translates 2 bytes of hex to an int.
    short s;
    char c;
    int returnInt = 0;
    for(int i = 0; i < 8; i++){
        c = entry8Hex.at(i);       // Assign local char
        if(c < 65)   {s = c-48;}   // compare value to ascii, if number
        else         {s = c-55;}   // Or if letter
        returnInt = returnInt*16 + s;    // Shift int value left, append next short; Create returnInt
    }
    return returnInt;
}
string  cultureIO::intToHex8(int entryInt){                         //Translates int into up to 2 bytes of hex.
    short s;
    char c[8];
    string returnString = "";
    for(int i = 0; i < 8; i++){
        s = entryInt%16;              // Assign local short
        if(s < 10)   {c[i] = s+48;}   // Compare value to ascii, if less than 10
        else         {c[i] = s+55;}   // Or if A or greater
        entryInt = entryInt/16;             // Look at next hex int value
    }
    for(int i = 0; i < 8; i += 2){                                  //Endianness
        returnString = returnString + c[i+1] + c[i];                //Magic!
    }
    return returnString;
}

void    cultureIO::importHex(string entryFile){                     //Translate file from hex to relevent data.
    entryFile = fiveCharsSubtract(entryFile);
    string currentSegment = entryFile.substr(0, 24);
    fillDataEntry(currentSegment, 0);
    for(int i = 1; i <= (*blockSize*4); i++){
        currentSegment = entryFile.substr(i*24, 24);
        fillDataEntry(currentSegment, i);
    }
}
string  cultureIO::fiveCharsSubtract(string entry){                 //Trim non-hex characters from file.
    //char first[4] = {28, 0, 16, 0}, last[1] = {0};
    return entry.substr(4,(entry.length()-5));
}
void    cultureIO::fillDataEntry(string entryHex24, int location){  //Translate hex to int and store it in class memory.
    string localString = "";
    for(int i = 24; i >= 0; i-=2){                                  //Endianness
        localString.append(entryHex24.substr(i,2));                 //Magic!
    }
    cultureRaw[location].fileSide[1] = this->hex8ToInt(localString.substr(0*8,8));
    cultureRaw[location].fileSide[0] = this->hex8ToInt(localString.substr(1*8,8));
    cultureRaw[location].fileSide[2] = this->hex8ToInt(localString.substr(2*8,8));
}
void    cultureIO::exportToProgram(){                               //Export local class memory to static classes.
    short ID, cons, prod;
    for(int i = 1; i<=*blockSize; i++){
        ID   = cultureRaw[*blockSize*1+i].progSide;
        cons = cultureRaw[*blockSize*2+i].progSide;
        prod = cultureRaw[*blockSize*3+i].progSide;
        pointsIO->addEntry(ID, cons, prod, 1);
    }
    infoIO->setAll(*culture_Prog, *culture_LVL, *bonus_CP, *prog_Rate, *unsure_1, *unsure_2, pointsIO->getSpentPoints());
}

void    cultureIO::importFromStatic(){                              //Import static class data to local memory.
    string NA;
    short ID, cons, prod;
    if(pointsIO->getEntryCount() > 16){*blockSize = pointsIO->getEntryCount();}
    *available_CP   = infoIO->get_Available_CP();
    *culture_Prog   = infoIO->get_Current_Progress();
    *culture_LVL    = infoIO->get_Level();
    *unsure_1       = infoIO->get_Unsure_XP();
    *prog_Rate      = infoIO->get_Progress_Rate();
    *bonus_CP       = infoIO->get_Bonus_CP();
    *unsure_2       = infoIO->get_Unsure_Player_ID();
    for(int i = 1; i<=*blockSize; i++){
        pointsIO->getEntry(i-1, NA, ID, cons, prod, 1);
        cultureRaw[(*blockSize)*1+i].progSide = ID;
        cultureRaw[(*blockSize)*2+i].progSide = cons;
        cultureRaw[(*blockSize)*3+i].progSide = prod;
    }
}
string  cultureIO::buildOutput(){                                   //Construct string for program output.
    string completeHex = "", emptySegment = "000000000000000000000000";
    string localString;
    for(int i = 0; i <= (*blockSize*4); i++){                           // [k] Read every memory entry
        localString = "";
        localString.append(intToHex8(cultureRaw[i].fileSide[2]));
        localString.append(intToHex8(cultureRaw[i].fileSide[0]));
        localString.append(intToHex8(cultureRaw[i].fileSide[1]));
        completeHex.append(localString);
    }
    localString = "";
    for(int i = (*blockSize)*4; i <= ((*blockSize)*(*blockNum)); i++){
        localString.append(emptySegment);
    }
    completeHex.append(localString);
    return completeHex;
}

        cultureIO::cultureIO(cultureInfo& inInfo,                   //Initialize the class with default values and class communication pointers.
                             culturePoints& inPoints,
                             cultureSettings& inSet){
    assignPointers(inInfo, inPoints, inSet);
    assignDefaults();
}

void    cultureIO::loadFile(){                                      //Load a culture file into the program.
    ifstream inCulture;
    string inString;
    inCulture.open(settingsIO->getSavePath() + settingsIO->fileName);
    pointsIO->purgeAllEntries();
    if(inCulture.good()){
        getline(inCulture, inString);
        importHex(inString);
        exportToProgram();
        cout << "Successfully opened \"" << settingsIO->fileName << "\"." << endl;
        inCulture.close();
    }else{
        cout << "Failed to open \"" << settingsIO->fileName << "\"." << endl;
    }
}
void    cultureIO::saveFile(){                                      //Print program data to a culture file.
    ofstream outCulture;
    outCulture.open(settingsIO->getSavePath() + settingsIO->fileName);
    if(outCulture.good()){
        pointsIO->purgeEmptyEntries();
        importFromStatic();
        outCulture << char(28) << char(0) << char(16) << char(0) << buildOutput() << char(0);//feels jury-rigged. make char insertion function
        cout << "Successfully saved \""  << settingsIO->fileName << "\"." << endl;
        outCulture.close();
    }else{
        cout << "Failed to save \""      << settingsIO->fileName << "\"." << endl;
    }
}

