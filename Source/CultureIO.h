#ifndef CULTUREIO
#define CULTUREIO
#include <iostream>
#include <fstream>
#include "CultureInfo.h"
#include "CultureSettings.h"
#include "CulturePoints.h"
#include "stdint.h"
using namespace std;
class cultureIO{
private:
    union{
        int32_t fileSide[3];                                    //Int32_t Inform translated hex data type, only necessary at this level of translation.
        double progSide;
    }cultureRaw[2000];
    int32_t *something, *blockNum, *blockSize;
    double *available_CP, *culture_Prog, *culture_LVL, *unsure_1, *prog_Rate, *bonus_CP, *unsure_2;
    cultureInfo *infoIO;
    culturePoints *pointsIO;
    cultureSettings *settingsIO;

    int     hex8ToInt(string);/*                                Translate 4 bytes of little endian Hex into an Int.
    Preconditions:
        Existing input of 8 character string of hex.
    Postconditions:
        Return Int.
    */
    string  intToHex8(int);/*                                   Translate Int into 4 bytes of little endian Hex.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Return 8 character string of hex.
    */
    void    assignPointers(cultureInfo&, culturePoints&,        //Assign local and class communication pointers.
                           cultureSettings&);/*
    Preconditions:
        Existing input parameters.
    Postconditions:
        Pointers set to local values for code clarity.
        Pointers set to relevant classes for information transfer.
        Return nothing.
    */
    void    assignDefaults();/*                                 Assign local default values by pointer.
    Preconditions:
        Local class pointers are assigned.
    Postconditions:
        Default file values are assigned.
        return nothing.
    */

    void    importHex(string);/*                                Translate file from hex to relevent data.
    Preconditions:
        Input string represents culture data.
    Postconditions:
        Local values set to input values.
        Return nothing.
    */
    string  fiveCharsSubtract(string);/*                        Trim non-Hex characters from file.
    Preconditions:
        Existing input parameter.
    Postconditions:
        Return output without first four and last characters.
    */
    void    fillDataEntry(string, int);/*                       Translate hex to int and store it in class memory.
    Preconditions:
        Existing input parameters.
    Postconditions:
        A CultureRaw array element is changed.
        Return nothing.
    */
    void    exportToProgram();/*                                Export local class memory to static classes.
    Preconditions:
        None.
    Postconditions:
        CultureInfo class values are set to local data.
        CulturePoints class values are set to local data.
        Return nothing.
    */

    void    importFromStatic();/*                               Import static class data to local memory.
    Preconditions:
        None.
    Postconditions:
        Class memory is loaded from static classes.
        Return nothing.
    */
    string  buildOutput();/*                                    Construct string for program output.
    Preconditions:
        None.
    Postconditions:
        Return hex string representing program data.
    */

public:
            cultureIO(cultureInfo&, culturePoints&,             //Initialize the class with default values and class communication pointers.
                      cultureSettings&);/*
    Preconditions:
        Existing input parameters.
    Postconditions:
        CultureIO is initialized and ready for I/O.
    */

    void    loadFile();/*                                       Load a culture file into the program.
    Preconditions:
        Class is properly initialized.
    Postconditions:
        Program static classes are populated with file data.
    */
    void    saveFile();/*                                       Print program data to a culture file.
    Preconditions:
        Class is properly initialized.
    Postconditions:
        Program static class data is printed to file.
    */

};
#endif //CULTUREIO
