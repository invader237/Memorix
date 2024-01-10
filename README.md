
# Memorix
[![forthebadge](http://forthebadge.com/images/badges/built-with-love.svg)](http://forthebadge.com)
[![forthebadge](http://forthebadge.com/images/badges/powered-by-electricity.svg)](http://forthebadge.com)

A memory game in C.


## Installation

You clone the [source code](https://github.com/invader237/Memorix) with the command:
```bash
https://github.com/invader237/Memorix
```
Or you can download the ZIP

## Start

No library is needed to run the game, you just need to compile it using this command in the /bin directory :
```bash
gcc -g -o main ../src/main.c ../src/displayFunction.c ../src/tabGenerationFunction.c ../src/turnFunction.c ../src/bot.c
```

To execute enter the command `./main`. 

### Made with
Editor:
* VS Code
* NVIM

Compiler:
* gcc

Debugger: 
* gdb

### Note

* Errors in the display may appear but are not critical. (display of " 0X " in the table when it should be " XX " or of " X* " when it should be " ** " )
* There is a bug where, when a player has to choose his first card, if he gives a letter instead of a number when asked for the column, column three is selected by default (and this does not work for the second card even though it is the same function)
* We have not deleted any branches from the project so that you can see the history of our work if necessary.

### Authors
Diego \
Guillaume
