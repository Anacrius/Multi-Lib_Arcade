# Multi-Lib_Arcade

2019 school project 


## Description

C++ project of a virtual arcade machine: the user can choose a game to play and the player scores is registered.

#### Compilation via Makefile:   ``` make all ```

<br/>

## Dynamic graphic libs

The program has 3 graphic libs available and the user can switch between them while the program is still running:
  - [ncurses](https://invisible-island.net/ncurses/):  lib in C with graphism are made of characters
  - [SFML](https://www.sfml-dev.org/index-fr.php):     graphic lib with image props
  - [SDL](https://www.libsdl.org/):      graphic lib with same assets as SFML 
 <br/>

## Input
|    Key    |        Description        |
| :-------: | ------------------------- |
|LEFT ARROW | Left switch graphical lib |
|RIGHT ARROW| Right switch graphical lib|
|     z     | UP                        |
|     s     | DOWN                      |
|     q     | LEFT                      |
|     d     | RIGHT                     |
|    ESC    | QUIT                      |
|     r     | RESTART                   |
|   Enter   | Confirm                   |

<br/>

## Start screen
When first running the program you start with a screen where you type your username on a virtual keyboard (min. 3 characters) 

Ncurses                                                                 |  SFML/SDL
:----------------------------------------------------------------------:|:--------------------------------------------------------------:
 ![ncurses_start](/img/ncurses_start.png?raw=true "ncurses_start.png")  | ![sfml_start](/img/sfml_start.png?raw=true "sfml_start.png")
 
 <br/>
 
## Games
 
 The project contains 2 games (the 3 others slots are placeholders):
   - [Nibbler](https://en.wikipedia.org/wiki/Nibbler_(video_game)): Snake game (press Enter ingame for extra speed)
   - [Pacman](https://en.wikipedia.org/wiki/Pac-Man): Pac-Man original gameplay
   
Nibbler Ncurses                                                         |  Nibbler SFML/SDL
:----------------------------------------------------------------------:|:--------------------------------------------------------------:
 ![ncurses_snake](/img/ncurses_snake.png?raw=true "ncurses_snake.png")  | ![smfl_snake](/img/smfl_snake.png?raw=true "smfl_snake.png")
 
 Pacman Ncurses                                                         |  Pacman SFML/SDL
:----------------------------------------------------------------------:|:--------------------------------------------------------------:
![ncurses_pacman](/img/ncurses_pacman.png?raw=true "ncurses_pacman.png")| ![sfml_pacman](/img/sfml_pacman.png?raw=true "sfml_pacman.png")

<br/>

## Credits
Benjamin F. (@[AubiOne](https://github.com/Aubi0ne)) <br/>
Chase L. (@[Kirvlawc](https://github.com/Kirvlawc)) <br/>
Maxime U. (@[Anacrius](https://github.com/Anacrius))
