# COMP345Proj Assignment 3 Part 4
Advanced C++ Project

Instruction:
1- Create new empty console project in visual studio
2- Copy/Paste all the header, source files and xml files into visual studio project folder
3- In visual studio, in the solution explorer, add existing item for all the .h and .hpp in the Header Files folder and all the .cpp in the Source Files folder.
4- Build.

This code implements the observer/decorator pattern for the display of the logs for the game of PowerGrid.

The class GameLog_Subject is the observable implementing the Subject interface.
- Creates a 5 GameLog_Phase, one for each phase of the game.
- Each GameLog_Phase hold a string(log) for each of the 6 players in the game
- When adding or getting a log, methods takes as arguments the phase number and the color of the player 

The class GameLog_Observer is the observer implementing the Observer interface.
- When instantiated attach itself to GameLog_Subject
- When log is updated, it is notified by subject and display the log.

The class GameLogDecorator is the base decorator for 4 different decorators:
- GameLog_AllPhase_AllPlayer: Display all the log for all phases and all the players
- GameLog_AllPhase_OnePlayer: Display all the log fall all phases, but for only one player
- GameLog_OnePhase_AllPlayer: Display the log for one phase for all players
- GameLog_OnePhase_OnePlayer: Display the log for one phase for only one player


Currently the GameDriver only shows the behaviour of the observer pattern for the power plant market, therefore only phase 2 and phase 5 
when it removes the biggest valued power plant from the market.