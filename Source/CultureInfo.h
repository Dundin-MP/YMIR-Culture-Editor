#ifndef CULTUREINFO
#define CULTUREINFO
using namespace std;
class cultureInfo{
private:
    double current_Progress, culture_Level, bonus_CP;
    double progress_Rate, unsure_XP, unsure_Player_ID;
    int spentCP, minimumProgress, progressToLevel;
    double available_CP, total_Progress;

    double  findLevelProgressMax(int);/*                    Calculate progress required to level up at parameter level.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Int return.
    */
    void    findLevelAtProgress();/*                        Calculate and set values for Level, Minimum Progress, and Current Progress from Total Progress.
    Preconditions:
        None.
    Postconditions:
        Level changes.
        Available CP changes.
        Minimum Progress changes.
        Current Progress changes.
        No return.
    */
    void    findMinimumProgress();/*                        Calculate and set Minimum Progress.
    Preconditions:
        None
    postconditions:
        Minimum Progress changes.
        No return.
    */

public:
            cultureInfo();/*                                Initializer.
    Preconditions:
        None.
    Postconditions:
        All class variables are initialized to appropriate values.
    */
            cultureInfo(double, int, int, double,           //Initializer with input values.
                        double, double, int);/*
    Preconditions:
        Existing input parameters.
    Postconditions:
        All class variables are initialized to values that are appropriate for input values.
        Variation from expectation may occur with YMIR files of a different version than the editor is designed for.
    */
    void    setAll(double, int, int, double,                //[Re]Set all class variables from input.
                    double, double, int);/*
    Preconditions:
        Existing input parameters.
    Postconditions:
        All class variables are initialized to values that are appropriate for input values.
        Variation from expectation may occur with YMIR files of a different version than the editor is designed for.
        No return.
    */

    void    setCurrentProgress(double);/*                   Set Current Progress, handle side-effects.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Current Progress changes.
        Total Progress changes.
        Culture Level may change.
        Available CP may change.
        No return.
    */
    void    setLevel(int);/*                                Set Culture Level, handle side-effects.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Level changes.
        Available CP changes.
        Current Progress may change.
        No return.
    */
    void    setBonusCP(int);/*                              Set Bonus CP, handle side-effects.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Bonus CP changes.
        Available CP changes.
        No return.
    */
    void    setProgressRate(double);/*                      Set Progress Rate.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Progress Rate is set.
        No return.
    */
    void    setUnsureXP(double);/*                          Set Unsure XP.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Unsure XP changes.
        No return.
    */
    void    setUnsurePlayerID(double);/*                    Set Unsure Player ID.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Unsure Player ID changes.
        No return.
    */
    void    setSpentCP(int);/*                              Set Spent CP, handle side-effects.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Spent CP changes.
        Available CP changes.
        No return.
    */
    void    setTotalProgress(double);/*                     Set Total Progress, handle side-effects.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Total Progress changes.
        Current Progress changes.
        Level may change.
        Available CP may change.
        No return.
    */

    double  get_Current_Progress();/*                       Retrieve Current Progress.
    Preconditions:
        None.
    Postconditions:
        Return Current Progress.
    */
    double  get_Level();/*                                  Retrieve Culture Level.
    Preconditions:
        None.
    Postconditions:
        Return Culture Level.
    */
    double  get_Bonus_CP();/*                               Retrieve Bonus CP.
    Preconditions:
        None.
    Postconditions:
        Return Bonus CP.
    */
    double  get_Progress_Rate();/*                          Retrieve Progress Rate.
    Preconditions:
        None.
    Postconditions:
        Return Progress Rate.
    */
    double  get_Unsure_XP();/*                              Retrieve "Unsure XP". It appears to scale with progress.
    Preconditions:
        None.
    Postconditions:
        Return Unsure XP.
    */
    double  get_Unsure_Player_ID();/*                       Retrieve "Unsure Player ID" A completely unknown value, It appears to scale with progress.
    Preconditions:
        None.
    Postconditions:
        Return Unsure Player ID.
    */
    double  get_Available_CP();/*                           Retrieve Available CP.
    Preconditions:
        None.
    Postconditions:
        Return Available CP.
    */
    double  get_Total_Progress();/*                         Retrieve Total Progress.
    Preconditions:
        None.
    Postconditions:
        Return Total Progress.
    */
    int     getProgressToLevel();/*                         Retrieve progress required to level up.
    Preconditions:
        None.
    Postconditions:
        Return Progress To Level.
    */
};
#endif //CUNTUREINFO
