#include "CultureInfo.h"
#include "iostream"
double  cultureInfo::findLevelProgressMax(int entryLevel){                              //Calculate progress required to level up at parameter level.
    int progToLevel = 0;
    for(int i = 0; i<=entryLevel; i++){
        progToLevel += (i+3)/2;
    }
    return progToLevel*10;
}
void    cultureInfo::findLevelAtProgress(){                                             //Calculate and set values for Level and Current Progress from Total Progress.
    double remainingProgress = total_Progress;
    cout << "remainingProgress: " << remainingProgress << endl;
    int currentLevel = 0;
    bool endHere = 0;
    while(!endHere){   // less code and less machine logic to have the escape condition trigger directly
        remainingProgress -= findLevelProgressMax(currentLevel);
    cout << "remainingProgress: " << remainingProgress << endl;
        if(remainingProgress<0){
            endHere = 1;
        }else{
            currentLevel++;
        }
    }
    setCurrentProgress(-remainingProgress);
    setLevel(currentLevel);
}
void    cultureInfo::findMinimumProgress(){                                             //Calculate and set Minimum Progress from Level.
    minimumProgress = 0;
    for(int i = 0; i < culture_Level; i++){
        minimumProgress += findLevelProgressMax(i);
    }
}

        cultureInfo::cultureInfo(){                                                     //Initializer.
    setAll(0, 0, 3, 0, 0, 0, 0);
}
        cultureInfo::cultureInfo(double entryProgress, int entryLVL, int entryBonus,    //Initializer with input values.
                    double entryRate, double entryUnsure1,
                    double entryUnsure2, int entrySpent){
    setAll(entryProgress, entryLVL, entryBonus, entryRate, entryUnsure1, entryUnsure2, entrySpent);
}
void    cultureInfo::setAll(double entryProgress, int entryLVL, int entryBonus,         //[Re]Set all class variables from input.
                  double entryRate, double entryUnsure1,
                  double entryUnsure2, int entrySpent){
    setLevel            (entryLVL);
    setCurrentProgress  (entryProgress);                        //after level allows progress overflow to next level
    setBonusCP          (entryBonus);
    setProgressRate     (entryRate);
    setUnsureXP         (entryUnsure1);
    setUnsurePlayerID   (entryUnsure2);
    setSpentCP          (entrySpent);
}

void    cultureInfo::setCurrentProgress(double entryProgress){                          //Set Current Progress, handle side-effects.
    current_Progress = entryProgress;
    if(current_Progress >= progressToLevel){
        current_Progress -= progressToLevel;
        setLevel(culture_Level + 1);
    }
    total_Progress = current_Progress + minimumProgress;
}
void    cultureInfo::setLevel(int entryLVL){                                            //Set Culture Level, handle side-effects.
    available_CP -= culture_Level;
    culture_Level = entryLVL;
    available_CP += culture_Level;
    progressToLevel = findLevelProgressMax(culture_Level);
    if(progressToLevel <= current_Progress){
        current_Progress = 0;
    }
    findMinimumProgress();
    total_Progress = (current_Progress + minimumProgress);
}
void    cultureInfo::setBonusCP(int entryBonus){                                        //Set Bonus CP, handle side-effects.
    available_CP -= bonus_CP;
    bonus_CP = entryBonus;
    available_CP += bonus_CP;
}
void    cultureInfo::setProgressRate(double entryRate){                                 //Set Progress Rate.
    progress_Rate = entryRate;
}
void    cultureInfo::setUnsureXP(double entryUnsure){                                   //Set Unsure XP.
    unsure_XP = entryUnsure;
}
void    cultureInfo::setUnsurePlayerID(double entryUnsure){                             //Set Unsure Player ID.
    unsure_Player_ID = entryUnsure;
}
void    cultureInfo::setSpentCP(int entrySpent){                                        //Set Spent CP, handle side-effects.
    available_CP += spentCP;
    spentCP = entrySpent;
    available_CP -= spentCP;
}
void    cultureInfo::setTotalProgress(double entryProg){                                //Set Total Progress, handle side-effects.
    total_Progress = entryProg;
    findLevelAtProgress();
}

double  cultureInfo::get_Current_Progress(){                                            //Retrieve Culture Progress.
    return current_Progress;
}
double  cultureInfo::get_Level(){                                                       //Retrieve Level.
    return culture_Level;
}
double  cultureInfo::get_Bonus_CP(){                                                    //Retrieve Bonus CP.
    return bonus_CP;
}
double  cultureInfo::get_Progress_Rate(){                                               //Retrieve Progress Rate.
    return progress_Rate;
}
double  cultureInfo::get_Unsure_XP(){                                                   //Retrieve "Unsure XP". It appears to scale with progress.
    return unsure_XP;
}
double  cultureInfo::get_Unsure_Player_ID(){                                            //Retrieve "Unsure Player ID" A completely unknown value, It appears to scale with progress.
    return unsure_Player_ID;
}
double  cultureInfo::get_Available_CP(){                                                //Retrieve Available CP.
    return available_CP;
}
double  cultureInfo::get_Total_Progress(){                                              //Retrieve Total Progress.
    return total_Progress;
}
int     cultureInfo::getProgressToLevel(){                                              //Retrieve progress required to level up.
    return progressToLevel;
}

