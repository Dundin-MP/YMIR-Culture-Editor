#include "ConsoleIO.h"
//Console I/O Handling
string  makeUniform(string entry){                                  //Return input string with all letters capitalized.
    transform(entry.begin(), entry.end(), entry.begin(), ::toupper);
    return entry;
}
string  requestStringInput(string entry, bool uniform){             //Requests and returns string input.
    string localString;
    cout << entry;
    getline(cin, localString);
    // Enter possible future string error check here
    if(uniform) {return makeUniform(localString);}
    else        {return localString;}
}
int     requestIntInput(string entry){                              //Request and returns int input.
    string localString;
    bool isGood = 1;
    cout << entry;
    getline(cin, localString);
    stringstream localStream(localString);
    localStream >> localString;
    if(localString==""){isGood=0;}
    for(int i = 0; i < localString.length(); i++){
        if(!isdigit(localString.at(i))){
            isGood = 0;
            break;
        }
    }
    if(!isGood){return -1;}
    else{       return stoi(localString);}
}
int     requestIntInput(string entry, int limit, bool truncate){    //Request and returns a value capped int input.
    int localInt = requestIntInput(entry);
    if(localInt>limit){
        if(truncate){
            localInt = limit;
        }else{
            localInt = -1;
        }
    }
    return localInt;
}
bool    isGetLineInt(string& entry){                                //Find if string has any non-numerical characters.
    stringstream localStream(entry);// Remove potential whitespace characters grabbed by getline()
    localStream >> entry;
    bool stillInt = true;              // Default success
    if(entry == ""){stillInt = false;}              // If the string is empty, fail.
    for(int i = 0; i<entry.length(); i++){          // Loop to check per character:
        if(!isdigit(entry.at(i))){stillInt = false;}    // If any character isn't a number, fail.
    }
    return stillInt;
}


static bool loopMenu;
void    menuLoop(const menuDialog &localDialog){                        //Handle menu looping.
    loopMenu = 1;//ensure it's on pre-menu
    while(loopMenu){
        displayMenu(localDialog);
        handleInput(localDialog);
    }
    loopMenu = 1;//ensure it's on before going back a menu
}
void    displayMenu(menuDialog localDialog){                        //Display menu.
    cout << endl << setw(localDialog.title.length()/2 + 25 + 2) << localDialog.title << *localDialog.titleVar << endl;
    for(int i = 0; i < localDialog.choices; i++){
        cout << setw(25) << localDialog.entry[i].choice << " - " << localDialog.entry[i].description << *localDialog.entry[i].choiceVar << endl;
    }
}
void    handleInput(menuDialog localDialog){                        //Process menu commands.
    string menuChoiceCheck;
    string userInput = requestStringInput(localDialog.prompt, 1);
    for(int i = 0; i < localDialog.choices; i++){
        menuChoiceCheck = makeUniform(localDialog.entry[i].choice);
        if(userInput == menuChoiceCheck){
            localDialog.entry[i].action();
            break;
        }
    }
    localDialog.fail;
    localDialog.failAction();
}
void    upMenu(){                                                   //Set loopMenu to 0. The program either goes back a menu or quits.
    loopMenu = 0;
}
void    doNothing(){}                                               //Empty function for blank function pointers.
