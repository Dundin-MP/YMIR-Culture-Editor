#include "CultureMainMenu.h"

static cultureSettings culSet;
const menuDialog mcMenu{//Main Culture Menu
      /*title*/"[---Main Menu---]",
   /*titleVar*/&nullStr,
     /*prompt*/"Main Menu: ",
       /*fail*/"Type \"Menu\" to display the menu or \"Quit\" to exit the program.",
    /*choices*/7,
    /*failAct*/&doNothing,
{//struct[20]
{//     [0]
     /*choice*/"Data Menu",
/*description*/"Display and modify general culture data.",
  /*choiceVar*/&nullStr,
     /*action*/&mcDataMenu},
{//     [1]
     /*choice*/"Points Menu",
/*description*/"Display and modify culture points.",
  /*choiceVar*/&nullStr,
     /*action*/&mcPointsMenu},
{//     [2]
     /*choice*/"File",
/*description*/"Save or Load culture data.",
  /*choiceVar*/&nullStr,
     /*action*/&mcFileMenu},
{//     [3]
     /*choice*/"Options",
/*description*/"Edit program options.",
  /*choiceVar*/&nullStr,
     /*action*/&mcOptionsMenu},
{//     [4]
     /*choice*/"About",
/*description*/"Display program and author info.",
  /*choiceVar*/&nullStr,
     /*action*/&mcAbout},
{//     [5]
     /*choice*/"Menu",
/*description*/"Display this menu.",
  /*choiceVar*/&nullStr,
     /*action*/&mcShowMenu},
{//     [6]
     /*choice*/"Quit",
/*description*/"Exit the program.",
  /*choiceVar*/&nullStr,
     /*action*/&upMenu}
}};
const menuDialog cdMenu{//Culture Data Menu
      /*title*/"[---Data Menu---]",
   /*titleVar*/&nullStr,
     /*prompt*/"Data Menu: ",
       /*fail*/"Type \"Menu\" to display the Settings menu or \"Return\" to return to the main menu.",
    /*choices*/9,
    /*failAct*/&doNothing,
{//struct[20]
{//     [0]
     /*choice*/"Show Data",
/*description*/"Display culture data.",
  /*choiceVar*/&nullStr,
     /*action*/&cdShow},
{//     [1]
     /*choice*/"Level",
/*description*/"Edit Culture Level.",
  /*choiceVar*/&nullStr,
     /*action*/&cdLevel},
{//     [2]
     /*choice*/"Bonus CP",
/*description*/"Edit bonus culture points.",
  /*choiceVar*/&nullStr,
     /*action*/&cdBonusCP},
{//     [3]
     /*choice*/"Current Progress",
/*description*/"Edit progress to next CP.",
  /*choiceVar*/&nullStr,
     /*action*/&cdCurrentProgress},
{//     [4]
     /*choice*/"Total Progress",
/*description*/"Edit total culture progress.",
  /*choiceVar*/&nullStr,
     /*action*/&cdTotalProgress},
{//     [5]
     /*choice*/"Unsure XP",
/*description*/"Edit a value with unknown meaning.",
  /*choiceVar*/&nullStr,
     /*action*/&cdUnsureXP},
{//     [6]
     /*choice*/"Unsure Player ID",
/*description*/"Edit a value with unknown meaning.",
  /*choiceVar*/&nullStr,
     /*action*/&cdUnsurePlayerID},
{//     [7]
     /*choice*/"Return",
/*description*/"Return to the main menu.",
  /*choiceVar*/&nullStr,
     /*action*/&upMenu},
{//     [8]
     /*choice*/"Menu",
/*description*/"Display this menu.",
  /*choiceVar*/&nullStr,
     /*action*/&cdShowMenu}
}};
const menuDialog cpMenu{//Culture Points Menu
      /*title*/"[---Points Menu---]",
   /*titleVar*/&nullStr,
     /*prompt*/"Points Menu: ",
       /*fail*/"Type \"Menu\" to display the Settings menu or \"Return\" to return to the main menu.",
    /*choices*/7,
    /*failAct*/&doNothing,
{//struct[20]
{//     [0] Points List
     /*choice*/"Show Points",
/*description*/"Display culture points entries.",
  /*choiceVar*/&nullStr,
     /*action*/&cpShow},
{//     [1] ID List
     /*choice*/"Show ID List",
/*description*/"Display the current culture ID catalog.",
  /*choiceVar*/&nullStr,
     /*action*/&cpIDList},
{//     [2] Add
     /*choice*/"Add Entry",
/*description*/"Add a new culture entry.",
  /*choiceVar*/&nullStr,
     /*action*/&cpAddEntry},
{//     [3] Edit
     /*choice*/"Edit Entry",
/*description*/"Edit an existing culture entry.",
  /*choiceVar*/&nullStr,
     /*action*/&cpEditEntry},
{//     [4] Remove
     /*choice*/"Remove Entry",
/*description*/"Remove an existing culture entry.",
  /*choiceVar*/&nullStr,
     /*action*/&cpRemoveEntry},
{//     [5] Return
     /*choice*/"Return",
/*description*/"Return to the main menu.",
  /*choiceVar*/&nullStr,
     /*action*/&cpUpMenu},
{//     [6] Menu
     /*choice*/"Menu",
/*description*/"Display this menu.",
  /*choiceVar*/&nullStr,
     /*action*/&cpShowMenu}
}};
const menuDialog cfMenu{//Culture File Menu
      /*title*/"[---File Menu---]",
   /*titleVar*/&nullStr,
     /*prompt*/"File Menu: ",
       /*fail*/"Type \"Menu\" to display the Settings menu or \"Return\" to return to the main menu.",
    /*choices*/4,
    /*failAct*/&doNothing,
{//struct[20]
{//     [0]
     /*choice*/"File Name",
/*description*/"Change the file name.",
  /*choiceVar*/&nullStr,
     /*action*/&cfName},
{//     [1]
     /*choice*/"Load",
/*description*/"Load from file. ",
  /*choiceVar*/&culSet.fileName,
     /*action*/&cfLoad},
{//     [2]
     /*choice*/"Save",
/*description*/"Save to file.   ",
  /*choiceVar*/&culSet.fileName,
     /*action*/&cfSave},
{//     [3]
     /*choice*/"Return",
/*description*/"Return to the main menu.",
  /*choiceVar*/&nullStr,
     /*action*/&upMenu}
}};
const menuDialog coMenu{//Culture File Menu
      /*title*/"[---Settings---]",
   /*titleVar*/&nullStr,
     /*prompt*/"Change Setting: ",
       /*fail*/"Type \"Menu\" to display the Settings menu or \"Return\" to return to the main menu.",
    /*choices*/8,
    /*failAct*/&doNothing,
{//struct[20]
{//     [0]
     /*choice*/"Default File Name",
/*description*/"Set the file name the program will default to in the file menu.",
  /*choiceVar*/&nullStr,
     /*action*/&defaultFileName},
{//     [1]
     /*choice*/"Save Path",
/*description*/"Set the save path the program will use when saving and loading culture files.",
  /*choiceVar*/&nullStr,
     /*action*/&savePath},
{//     [2]
     /*choice*/"Always Show Intro",
/*description*/"This controls if the program intro displays or not. By default it only displays once.",
  /*choiceVar*/&nullStr,
     /*action*/&toggleAlwaysIntro},
{//     [3]
     /*choice*/"Show Production Level",
/*description*/"This controls if Production Level or invested CP is displayed in the points menu.",
  /*choiceVar*/&nullStr,
     /*action*/&toggleShowProdLevel},
{//     [4]
     /*choice*/"Limit Production",
/*description*/"This controls if Culture Skills are limited to 5.",
  /*choiceVar*/&nullStr,
     /*action*/&limitPoints},
{//     [5]
     /*choice*/"Change Intro",
/*description*/"Make your own custom intro!",
  /*choiceVar*/&nullStr,
     /*action*/&changeIntro},
{//     [6]
     /*choice*/"Reset Intro",
/*description*/"Reset the intro to default.",
  /*choiceVar*/&nullStr,
     /*action*/&resetIntro},
{//     [7]
     /*choice*/"Return",
/*description*/"Return to the main menu.",
  /*choiceVar*/&nullStr,
     /*action*/&upMenu}
}};

int     main(int argc, char *argv[]){                               //Display header message and open main culture menu.
      if(argc > 1){
        handleConsole(argc, argv);
        return 1;
    }else{
        culSet.showIntro();
        cultureMenu();
    return 0;
    }
}

//Culture Menu
void    cultureMenu(){menuLoop(mcMenu);}                            //Open the main culture menu.
void    mcShowMenu(){displayMenu(mcMenu);}                          //Display the main culture menu.
void    mcAbout(){                                                  //Print author and version data.
    cout << endl
    << "YMIR Culture Editor Version 0.4" << endl
    << "Author: Dundin" << endl
    << "This program was originally created to perform as an admin tool to allow recovery from possible Culture Point Hell in the CP system's infancy." << endl
    << "As CP are now revokable in-game, it's original purpose is no longer necessary. It may still be useful for exploring different CP distributions quickly in single player" << endl
    << "or for server admin modification of a player's culture files." << endl;
    getch();
}

//Culture Data Menu
static cultureInfo culInf;
void    mcDataMenu(){                                               //Open the culture data menu.
    cdShow();
    menuLoop(cdMenu);
}
void    cdShow(){                                                   //Display culture data values.
    double totalProg    = culInf.get_Total_Progress();
    double currentProg  = culInf.get_Current_Progress();
    int toNextLevel     = culInf.getProgressToLevel();
    int currentLevel    = culInf.get_Level();
    int bonusCP         = culInf.get_Bonus_CP();
    int availableCP     = culInf.get_Available_CP();
    float progRate      = culInf.get_Progress_Rate();
    float unsureXP      = culInf.get_Unsure_XP();
    float unsureID      = culInf.get_Unsure_Player_ID();
    cout << endl    << "Level: " << currentLevel << ", To Next: " << currentProg << "/" << toNextLevel << ", Total Progress: " << totalProg << endl
                    << "Bonus CP: " << bonusCP << ", Available CP: " << availableCP << ", XP Rate: " << progRate << " Prog/Turn" << endl
                    << "Unknown value 1: " << unsureXP << ", It appears to scale somewhat with current XP." << endl
                    << "Unknown value 2: " << unsureID << ", I have no clue what this one is." << endl;
}
void    cdLevel(){                                                  //Set stored culture level.
    int entryLVL = requestIntInput("Level: ");
    if(entryLVL == -1){
        cout << "Invalid Input";
        return;}
    culInf.setLevel(entryLVL);
}
void    cdBonusCP(){                                                //Set stored bonus CP.
    int entryCP = requestIntInput("Bonus CP: ");
    if(entryCP == -1){
        cout << "Invalid Input";
        return;}
    culInf.setBonusCP(entryCP);
}
void    cdCurrentProgress(){                                        //Set stored current progress.
    int entryProg = requestIntInput("Current Progress: ");
    if(entryProg == -1){
        cout << "Invalid Input";
        return;}
    culInf.setCurrentProgress(entryProg);
}
void    cdTotalProgress(){                                          //Set stored total progress.
    int entryProg = requestIntInput("XP: ");
    if(entryProg == -1){
        cout << "Invalid Input";
        return;}
    culInf.setTotalProgress(entryProg);
}
void    cdUnsureXP(){                                               //Set stored "Unsure XP"
    int entryInt = requestIntInput("Entry: ");
    if(entryInt == -1){
        cout << "Invalid Input";
        return;}
    culInf.setUnsureXP(entryInt);
}
void    cdUnsurePlayerID(){                                         //Set stored "Unsure Player ID"
    int entryInt = requestIntInput("Entry: ");
    if(entryInt == -1){
        cout << "Invalid Input";
        return;}
    culInf.setUnsurePlayerID(entryInt);
}
void    cdShowMenu(){displayMenu(cdMenu);}                          //Display the culture data menu.

//Culture Points Menu
static cultureIDList culIDL;
static culturePoints culPnt(culIDL, culSet);
void    mcPointsMenu(){                                             //Open the culture points menu.
    cpShow();
    menuLoop(cpMenu);
}
void    cpShow(){                                                   //Display culture points entries.
    int entries = culPnt.getEntryCount();
    short ID, cons, prod;
    string name;
    if(entries==0){return;}
    cout << endl << setw(6) << "Loc." << setw(2) << "|" << setw(4) << "ID" << setw(2) << "|"
         << setw(6) << "Cons." << setw(2) << "|" << setw(6) << "Prod." << setw(3) << "| " << "Name" << endl;
    for(int i = 0; i<entries; i++){
        culPnt.getEntry(i, name, ID, cons, prod);
        cout << " [" << setw(3) << i << "]"
        << setw(2) << "|"  << setw(4) << ID
        << setw(2) << "|"  << setw(4) << cons
        << setw(4) << "|"  << setw(4) << prod
        << setw(5) << "| " << name << endl;
    }
}
void    cpIDList(){                                                 //Display list of known culture IDs.
    string localString;
    cout << endl << setw(3) << " ID Name" << endl;
    for(int i = 0; i < 200; i++){
        localString = culIDL.getName(i);
        if(localString!=""){
            cout << setw(3) << i << " " << localString << endl;
        }
    }
    cout << endl;
}
void    cpAddEntry(){                                               //Add a new culture points entry.
    bool failedEntry = 0;
    int localCons, localProd;
    int localID  = requestIntInput("ID: ", 499);
    if(localID   == -1){
        failedEntry = true;
        cout << "Please enter a positive number.\n";}
    if(!failedEntry){//add feedback if autocons/ autoprod
        if(culIDL.checkCanCons(localID)){
            localCons  = requestIntInput("Consumption: ", 1);
        if(localCons == -1){
            failedEntry = true;
            cout << "Please enter 0 or 1.\n";}}}
    if(!failedEntry){
        localProd  = requestIntInput("Production: ", 5-culIDL.checkProdMin(localID));
    if(localProd == -1){
        failedEntry = true;
        cout << "Please enter a number from 0 to " << (5-culIDL.checkProdMin(localID)) << ".\n";
    }}
    if(failedEntry){
        return;
    }else{
    culPnt.addEntry(localID, localCons, localProd);
    }
}
void    cpEditEntry(){                                              //Edit existing culture points entry.
    bool failedEntry = 0;
    int localID, localCons, localProd;
    int locLimit  = culPnt.getEntryCount()-1;
    int localLoc  = requestIntInput("Edit Location: ", locLimit, true);
    if(localLoc  == -1){
        failedEntry = true;
        cout << "Please enter a location in the range of 0-" << locLimit << ".\n";
    }
    if(!failedEntry){
        localID  = requestIntInput("ID: ", 499);
    if(localID   == -1){
        failedEntry = true;
        cout << "Please enter a positive number.\n";}
    if(!failedEntry){//add feedback if autocons/ autoprod
        if(culIDL.checkCanCons(localID)){
            localCons  = requestIntInput("Consumption: ", 1);
        if(localCons == -1){
            failedEntry = true;
            cout << "Please enter 0 or 1.\n";}}}
    if(!failedEntry){
        if(culSet.getLimitProduction()){
            localProd = requestIntInput("Production: ", 5-culIDL.checkProdMin(localID));
        }else{
            localProd = requestIntInput("Production: ");
        }
    if(localProd == -1){
        failedEntry = true;
        if(culSet.getLimitProduction()){
            cout << "Please enter a number from 0 to " << (5-culIDL.checkProdMin(localID)) << ".\n";
        }else{
            cout << "Please enter a number greater than 0.\n";
        }}}
    if(failedEntry){
        return;//General failure case
    }else{
    culPnt.editEntry(localLoc, localID, localCons, localProd);
    }}
}
void    cpRemoveEntry(){                                            //Remove existing culture points entry.
    int locLimit  = culPnt.getEntryCount()-1;
    int localLoc  = requestIntInput("Remove Location: ", locLimit, true);
    if(localLoc   == -1){
        cout << "Please enter a location in the range of 0-" << locLimit << ".\n";
        return;
    }
    culPnt.removeEntry(localLoc);
}
void    cpShowMenu(){displayMenu(cpMenu);}                          //Display the culture points menu.
void    cpUpMenu(){                                                 //send spent CP change to culInf and upMenu.
    culInf.setSpentCP(culPnt.getSpentPoints());
    upMenu();
}

//File Menu
void    mcFileMenu(){menuLoop(cfMenu);}                                 //Open the file menu.
void    cfName(){                                                   //Set the file name.
    string localString = requestStringInput("File Name: ");
    //Check file name convention, somehow
    culSet.fileName = localString + ".yds";
    cout << "File Name changed to \"" << culSet.fileName << "\"" << endl;
}
void    cfLoad(){                                                   //Load a file to program.
    cultureIO loadFromFile(culInf, culPnt, culSet);
    loadFromFile.loadFile();
    upMenu();
}
void    cfSave(){                                                   //Save program data to a file.
    cultureIO saveToFile(culInf, culPnt, culSet);
    saveToFile.saveFile();
    upMenu();
}
void    cfShowMenu(){displayMenu(cfMenu);}                          //Show the file menu.

//Settings Menu
void    mcOptionsMenu(){menuLoop(coMenu);}                              //Open the options menu.
void    defaultFileName(){
    culSet.setDefaultFileName();
}
void    savePath(){
    culSet.setSavePath();
}
void    toggleAlwaysIntro(){
    culSet.toggleAlwaysShowIntro();
}
void    toggleShowProdLevel(){
    culSet.toggleShowProdLevel();
}
void    limitPoints(){
    culSet.toggleLimitProduction();
}
void    changeIntro(){
    culSet.changeIntro();
}
void    resetIntro(){
    culSet.resetIntro();
}

void    handleConsole(int argc, char **argv){
    for (int i = 1; i < argc+1; i += 2){
        culSet.fileName = argv[i+1];
        cultureIO fileIO(culInf, culPnt, culSet);
        fileIO.loadFile();
        string argStr = argv[i];
        if(argStr == "bonusUp")
            incrementBonusCP();
        if(argStr == "bonusDn")
            incrementBonusCP(true);
        fileIO.saveFile();
    }
}

void    incrementBonusCP(bool flagDown){
    int bonusMod = 1 + (-2 * flagDown);
    culInf.setBonusCP(culInf.get_Bonus_CP() + bonusMod);
    cout << "Bonus CP is now: " << culInf.get_Bonus_CP() << endl;
}