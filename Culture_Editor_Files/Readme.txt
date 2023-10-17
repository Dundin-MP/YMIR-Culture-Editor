YMIR Culture Editor v0.4.0.2
Authored by Dundin, If you want to contact me, i'm most easily contacted on discord: Dundin
So onward to the cool stuff!	

[----THE README STUFF----]
 - The culture editor needs any files you want to edit in the directory "\Culture_Editor_Files\YMIR_Save_Files" unless you modify the file path in settings.
 - The location to find your culture files on a windows platform is in this directory:
	"C:\Users\[Your Name]\AppData\Local\Ymir\saves\[Game Name]\players"
 - When looking for your local culture files for a solo game your culture file will be "culture_10"
 - It's a good idea to make backups if you're editing a game's save file.
 - Really, make backups.
 - If your settings somehow get messed up (it may interfere with launching the program if it does) you can reset your settings by deleting the "Settings.txt" file and relaunching the program. If you have a particularly keen eye, you may notice the file isn't even there until you first ran the program.
 - If you find yourself with no culture file or backup YMIR will accept a 'blank' culture file; one saved with no options set from the program. I would suggest providing about what you remember having for a Culture Level and 13 Bonus CP.
 - The Editor allows you to edit several unknown values. Change them at your own risk. 
    However if you happen to discover what they do represent, I'll greatly appreciate it if you let me know!

[----COMMAND LINE USE----]
Hey! Guess What! These are a thing now!
Still in early implementation as right now any batch editing of multiple culture files will need to be handled with a script running the program multiple times.
The format for command line arguments is as follows:
[program name] [file to edit] [operation1] [operation1 value] [operation 2] [operation2 value]
For example:
YMIR_Culture_Editor_v0.4.0.2.exe culture_10.yds bonusUp 1 levelDn 2
YMIR_Culture_Editor_v0.4.0.2.exe culture_10.yds bonusDn 1

Currently available commands:
 - bonusUp --> Raise bonus CP
 - bonusDn --> Lower bonus CP
 - levelUp --> Raise culture Level
 - levelDn --> Lower culture level


