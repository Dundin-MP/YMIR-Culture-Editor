#ifndef CULTURESETTINGS
#define CULTURESETTINGS
#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <direct.h>
#include "ConsoleIO.h"
using namespace std;
class cultureSettings{
private:

    string  defaultFileName;        //"culture_10.yds"      //set function from local menu (filemenu allows local temp change) //possibly an option for "test suffix"
    string  savePath;               //"/YMIR_Save_Files"    //set function from local menu
    string  intro;                  //intro string
    bool    displayIntro;           //1                     //On at first run, otherwise off.
    bool    alwaysDisplayIntro;     //0
    bool    showProdLevel;             //1 Spent Consumption & Production Points VS Customs & Skill Levels
    bool    limitProduction;        //1 Limit production points to no more than 5;

    void    createDir();            //Generate a Culture Editor files directory
    bool    readFile();             //Read the settings file, if none found, run createFile();
    void    writeFile();            //Write settings file with any changes
    void    defaultSettings();      //Set all values to default pre-file check
public:
            cultureSettings();      //Initializer
    void    saveSettings();         //Save settings to file

    string  fileName;               //active fileName
    void    setDefaultFileName();   //Set default file name
    void    setSavePath();          //Set save path
    string  getSavePath();          //Get save path

    void    showIntro();            //Display introPrompt if displayIntro=1 or alwaysDisplayIntro=1
    void    resetIntro();           //Set displayIntro to 1
    void    toggleAlwaysShowIntro();//Set alwaysDisplayIntro to [1|0]
    void    changeIntro();          //Allow manually changing intro, include that \n is "end line"

    void    toggleShowProdLevel();     //Set showProdLevel to [1|0]
    bool    getShowProdLevel();   //Get showProdLevel
    void    toggleLimitProduction();//Set limitProduction to [1|0]
    bool    getLimitProduction();   //Get limitProduction
};
#endif // CULTURESETTINGS
