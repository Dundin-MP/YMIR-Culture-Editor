#ifndef CULTUREMAINMENU
#define CULTUREMAINMENU
#include "ConsoleIO.h"
#include "CultureInfo.h"
#include "CultureIDList.h"
#include "CultureInfo.h"
#include "CulturePoints.h"
#include "CultureIO.h"
#include "CultureSettings.h"
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <string>
#include <sstream>
using namespace std;


void    cultureMenu();/*                                    Open the main culture menu.
Preconditions:
    None.
Postconditions:
    Return nothing.
*/
void    mcShowMenu();/*                                     Display the main culture menu.
Preconditions:
    None.
Postconditions:
    Main culture menu printed to console.
    Return nothing.
*/
void    mcAbout();/*                                        Print author and version data.
Preconditions:
    None.
Postconditions:
    Program Author and version information printed to console.
    Return nothing.
*/

void    mcDataMenu();/*                                     Open the culture data menu.
Preconditions:
    None.
Postconditions:
    Back to main menu.
    Return nothing.
*/
void    cdShow();/*                                         Display Culture Data Values.
Preconditions:
    None.
Postconditions:
    Culture data values printed to console.
    Return nothing.
*/
void    cdLevel();/*                                        Set stored culture level.
Preconditions:
    None.
Postconditions:
    Culture level change is executed.
    Return nothing.
*/
void    cdBonusCP();/*                                      Set stored bonus CP.
Preconditions:
    None.
Postconditions:
    Bonus CP Change is executed.
    Return nothing.
*/
void    cdCurrentProgress();/*                              Set stored current progress.
Preconditions:
    None.
Postconditions:
    Current progress change is executed.
    Return nothing.
*/
void    cdTotalProgress();/*                                Set stored total progress.
Preconditions:
    None.
Postconditions:
    Total Progress change is executed.
    Return nothing.
*/
void    cdUnsureXP();/*                                     Set stored "Unsure XP".
Preconditions:
    None.
Postconditions:
    "Unsure XP" change is executed.
    Return nothing.
*/
void    cdUnsurePlayerID();/*                               Set stored "Unsure Player ID".
Preconditions:
    None.
Postconditions:
    "Unsure Player ID" is executed.
    Return nothing.
*/
void    cdShowMenu();/*                                     Display the culture data menu.
Preconditions:
    None.
Postconditions:
    Culture data menu is shown to console again.
    Return nothing.
*/

void    mcPointsMenu();/*                                   Open the culture points menu.
Preconditions:
    None.
Postconditions:
    Back to main menu.
    Return nothing.
*/
void    cpShow();/*                                         Display culture points entries.
Preconditions:
    None.
Postconditions:
    Display list of CP Entries.
    Return nothing.
*/
void    cpIDList();/*                                       Display list of known culture IDs.
Preconditions:
    None.
Postconditions:
    Display list of known Culture IDs.
    Return nothing.
*/
void    cpAddEntry();/*                                     Add a new culture points entry.
Preconditions:
    None.
Postconditions:
    Execute a CP entry addition.
    Return nothing.
*/
void    cpEditEntry();/*                                    Edit existing culture points entry.
Preconditions:
    None.
Postconditions:
    Execute a CP entry edit.
    Return nothing.
*/
void    cpRemoveEntry();/*                                  Remove existing culture points entry.
Preconditions:
    None.
Postconditions:
    Execute a CP entry removal.
    Return nothing.
*/
void    cpShowMenu();/*                                     Show culture points menu.
Preconditions:
    None.
Postconditions:
    Culture points menu is shown to the console again.
    Return nothing.
*/
void    cpUpMenu();/*                                       Send CP changes to Data class and Set loopMenu to 0.
Preconditions:
    None.
Postconditions:
    culInf spentPoints changes.
    Program go back a menu.
    Return nothing.
*/

void    mcFileMenu();/*                                     Open the file menu.
Preconditions:
    None.
Postconditions:
    Back to main menu.
    Return nothing.
*/
void    cfName();/*                                         Set the file name.
Preconditions:
    None.
Postconditions:
    Execute a file name change.
    Return nothing.
*/
void    cfLoad();/*                                         Load a file to program.
Preconditions:
    None.
Postconditions:
    Execute loading a file to the program.
    Return nothing.
*/
void    cfSave();/*                                         Save program data to a file.
Preconditions:
    None.
Postconditions:
    Execute Saving program data to a file.
    Return nothing.
*/
void    cfShowMenu();/*                                     Show the file menu.
Preconditions:
    None.
Postconditions:
    File menu is shown to the console again.
    Return nothing.
*/

void    mcOptionsMenu();/*                                    Open the options menu.*/
void    defaultFileName();/* */
void    savePath();/* */
void    toggleAlwaysIntro();/* */
void    toggleShowProdLevel();/* */
void    limitPoints();/* */
void    changeIntro();/* */
void    resetIntro();/* */
#endif //CULTUREMAINMENU
