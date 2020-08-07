# Minesweeper
A SFML based C++ Minesweeper game.

Project Name: Minesweeper
Project Description:
Minesweeper is a single-player puzzle game. The objective of the game is to clear a rectangular board containing hidden "mines" or bombs without detonating any of them, with help from clues about the number of neighboring mines in each field. The game originates from the 1960s, and has been written for many computing platforms in use today. It has many variations and offshoots. Project Implementation: You have to implement console-based Minesweeper game using two-dimensional arrays (1212) in C++. The description of the modules you will have to implement are as follows: When a player starts the game he/she will initially be presented with a grid of undifferentiated blocks. Some randomly selected blocks, unknown to the player, would be designated to contain mines. Typically, the size of the grid and the number of mines are set in advance by the user, either by entering the numbers or selecting from defined skill levels, depending on the implementation. You can set the size of the grid 1212 and mines to 15. (For bonus marks you may add an option for the user to enter grid size and number of mines as he/she desires.) The game would be played by revealing squares of the grid by entering the index of a particular cell to indicate each square. If a square containing a mine is revealed, the player loses the game. If no mine is revealed, a digit is instead displayed in the square, indicating how many adjacent squares contain mines. For example: Suppose the user selected the cell shown in gray. As the square contains three mines in its adjacent cells, it therefore displays 3.

If no mines are adjacent, the square becomes blank, and all adjacent squares will be recursively revealed. The player uses this information to deduce the contents of other squares, and may either safely reveal each square or mark the square as containing a mine by using flag. A question mark may be placed in an unrevealed square to serve as an aid to logical deduction. Implementations may also allow players to quickly "clear around" a revealed square once the correct number of mines have been flagged around it. The game is won when all mine-free squares are revealed, because all mines have been located. Initially the user cannot place a mine on the first square revealed.

Outputs - Characters to be used:

 M: For mines
 * or +: For squares
 F: For Flags
 ?: For unknown values
 0, 1, 2, 3, 4, 5, 6: depending on the mines in the adjacent cells
 Row numbers: To display the number of each row
 Column numbers: To display the number of each column. Extra would be given to those who use some graphics to show the above stated objects Inputs: Each the user has to select a cell, he/she will be asked to enter:
 Row number
 Column number
 Selection type (can be a flag, unknown or open square) Optional: For bonus marks you may give option (when the game starts) to the user to enter:
 Grid size
 Number of mines Scores/Variables to be maintained/displayed:
 Total number of squares
 Number of squares opened
 Total flags placed
 Total question marks placed
 Total Number of mines
 Number of mines remaining
 Time taken
 High Scores along with player names (use filing to save scores for each player) Menus and Instructions: Your game must show a menu when it is started. It must contain the following:
Play game
How to play
High scores
Exit
, etc.
