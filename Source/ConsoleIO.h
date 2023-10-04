#ifndef CONSOLEIO
#define CONSOLEIO
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;
static string nullStr = "";
struct menuDialog{
    string title;
    string *titleVar;
    string prompt;
    string fail;
    int choices;
    void (*failAction)();
    struct{
        string choice;
        string description;
        string *choiceVar;
        void (*action)();
    }entry[20];
};

string  makeUniform(string);/*                              Return input string with all letters capitalized.
Preconditions:
    Existing input parameter.
Postconditions:
    Return modified input string.
*/
string  requestStringInput(string, bool uniform = 0);/*     Requests and return string input.
Preconditions:
    Existing input parameters.
Postconditions:
    Return string.
*/
int     requestIntInput(string entry);/*                    Request and return int input.
Preconditions:
    Existing input parameter.
Postconditions:
    Return int.
*/
int     requestIntInput(string, int, bool truncate = 1);/*  Request and returns a value capped int input.
Preconditions:
    Existing input parameters.
Postconditions:
    Return int.
*/
bool    isGetLineInt(string&);/*                            Find if string has any non-numerical characters.
Preconditions:
    Existing input parameter.
Postconditions:
    Return bool.
*/

void    menuLoop(const menuDialog&);/*                                Handle menu looping.
Preconditions:
    None.
Postconditions:
    Program closes.
    Return nothing.
*/
void    displayMenu(menuDialog);/*                          Display menu.
Preconditions:
    None.
Postconditions:
    Menu displayed to console.
    Return nothing.
*/
void    handleInput(menuDialog);/*                          Process menu commands.
Preconditions:
    None:
Postconditions:
    Menu operation selected and performed.
    Return nothing.
*/
void    upMenu();/*                                         Set loopMenu to 0. The program either goes back a menu or quits.
Preconditions:
    None.
Postconditions:
    Program go back a menu.
    Return nothing.
*/
void    doNothing();/*                                      Empty function for blank function pointers.
Preconditions:
    None.
Postconditions:
    None.
*/

#endif //CONSOLEIO
