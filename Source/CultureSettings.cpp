#include "CultureSettings.h"

void    cultureSettings::createDir(){               //Generate a Culture Editor files directory
    string dirName = "Culture_Editor_Files";
    struct stat buffer;//MAGIC! looks like cpp17 has a better way, i'll look into that, this one is arcane
    if(stat(dirName.c_str(), &buffer)){
        int check = mkdir(dirName.c_str());
    }
}
bool    cultureSettings::readFile(){                //Read the settings file, if none found, run createFile();
    ifstream inFile;
    string inString, workingString;
    int substrStart;
    int substrLen;
    inFile.open("Culture_Editor_Files/Settings.txt");
    if(!inFile.good()){return 0;}//error

    getline(inFile, inString);//replace with loop
    substrStart = inString.find("[")+1;
    substrLen = inString.find("]") - substrStart;
    workingString = inString.substr(substrStart, substrLen);
    defaultFileName = workingString;

    getline(inFile, inString);
    substrStart = inString.find("[")+1;
    substrLen = inString.find("]") - substrStart;
    workingString = inString.substr(substrStart, substrLen);
    savePath = workingString;

    getline(inFile, inString);
    substrStart = inString.find("[")+1;
    substrLen = inString.find("]") - substrStart;
    workingString = inString.substr(substrStart, substrLen);
    intro = workingString;

    getline(inFile, inString);
    substrStart = inString.find("[")+1;
    substrLen = inString.find("]") - substrStart;
    workingString = inString.substr(substrStart, substrLen);
    alwaysDisplayIntro = stoi(workingString);

    getline(inFile, inString);
    substrStart = inString.find("[")+1;
    substrLen = inString.find("]") - substrStart;
    workingString = inString.substr(substrStart, substrLen);
    showProdLevel = stoi(workingString);

    getline(inFile, inString);
    substrStart = inString.find("[")+1;
    substrLen = inString.find("]") - substrStart;
    workingString = inString.substr(substrStart, substrLen);
    limitProduction = stoi(workingString);
    inFile.close();
    return 1;
}
void    cultureSettings::writeFile(){               //Write settings file with any changes
    ofstream outFile;
    outFile.open("Culture_Editor_Files/Settings.txt");
    if(!outFile.good()){return;}//error
    outFile
    << "DefaultFileName ["      << defaultFileName      << "]" << endl
    << "SavePath ["             << savePath             << "]" << endl
    << "Intro ["                << intro                << "]" << endl
    << "AlwaysDisplayIntro ["   << alwaysDisplayIntro   << "]" << endl
    << "ShowProdLevel ["        << showProdLevel        << "]" << endl
    << "LimitProduction ["      << limitProduction      << "]" << endl;
    outFile.close();
}
void    cultureSettings::defaultSettings(){         //Set all values to default
    defaultFileName = "culture_10.yds";
    savePath = "Culture_Editor_Files/YMIR_Save_Files/";
    intro = "If you haven't yet done so, I recommend you read Readme.txt written for and included in each version of the YMIR Culture File Editor before using the program. Regardless if you have though, I hope you find the editor useful. May you find a five deepmine gold vein on your capital!";
    displayIntro = 1;
    alwaysDisplayIntro = 0;
    showProdLevel = 1;
    limitProduction = 1;
}
        cultureSettings::cultureSettings(){         //Initializer
    createDir();
    bool goodFile = readFile();
    if(!goodFile){
        defaultSettings();
        writeFile();
    }//offer to reset/make new file
    fileName = defaultFileName;
}

void    cultureSettings::setDefaultFileName(){      //Set default file name
    cout << "The current Default File Name is:\n" << defaultFileName << endl;
    string localFileName = requestStringInput("Change the Default File Name to: ");
    string confirmYN = requestStringInput("Are you sure [Y/N]? Your new Default File Name will change to: " + localFileName, 1);
    if(confirmYN == "Y"){
        defaultFileName = localFileName + ".yds";
        cout << "Default File Name changed to \"" << defaultFileName << "\"" << endl;
    }else{
        cout << "Default File Name not changed." << endl;
    }
}
void    cultureSettings::setSavePath(){             //Set save path
    cout << "The current Save Path is:\n" << savePath << endl;
    string localSavePath = requestStringInput("Change the Save Path to: ");
    string confirmYN = requestStringInput("Are you sure [Y/N]? Your new Save Path will change to: " + localSavePath, 1);
    if(confirmYN == "Y"){
        savePath = localSavePath;
        cout << "Save Path changed to \"" << savePath << "\"" << endl;
    }else{
        cout << "Save Path not changed." << endl;
    }
}
string  cultureSettings::getSavePath(){             //Get save path
    return savePath;
}

void    cultureSettings::showIntro(){               //Display introPrompt if displayIntro=1 or alwaysDisplayIntro=1
    cout << "{-----------------YMIR Culture File Editor----------------}\n";
    if(!alwaysDisplayIntro){
    if(!displayIntro)
        {return;}}
    cout << intro;
}
void    cultureSettings::resetIntro(){              //Set displayIntro to the original string
    intro = "If you haven't yet done so, I recommend you read Readme.txt written for and included\nin each version of the YMIR Culture File Editor before using the program.\nRegardless if you have though, I hope you find the editor useful. \nMay you find a five deepmine gold vein on your capital!\n";
    writeFile();
}
void    cultureSettings::toggleAlwaysShowIntro(){   //Set alwaysDisplayIntro to [1|0]
    string localString = "Not ";
    alwaysDisplayIntro = !alwaysDisplayIntro;
    if(alwaysDisplayIntro){localString = "";}
    cout << "Intro is " << localString << "Always Shown" << endl;
    writeFile();
}
void    cultureSettings::changeIntro(){             //Allow manually changing intro, include that \n is "end line"
    intro = requestStringInput("Type the new intro here\n:");
    writeFile();
}

void    cultureSettings::toggleShowProdLevel(){        //Set showProdLevel to [1|0]
    string localString = "Invested CP";
    showProdLevel = !showProdLevel;
    if(showProdLevel){localString = "Production Level";}
    cout << "Show " << localString << endl;
    writeFile();
}
bool    cultureSettings::getShowProdLevel(){
    return showProdLevel;
}
void    cultureSettings::toggleLimitProduction(){   //Set limitProduction to [1|0]
    string localString = "Not ";
    limitProduction = !limitProduction;
    if(limitProduction){localString = "";}
    cout << "Culture Skills are " << localString << "Limited to 5" << endl;
    writeFile();
}
bool    cultureSettings::getLimitProduction(){
    return limitProduction;
}

