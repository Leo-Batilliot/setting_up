# setting_up
## Goal of the project  
code a program that takes a map in argument and find the largest **`.`** square in the map and mark it with **`x`**
## Map  
The map has to be composed of **`.`** and **`o`**. 'o' being invalid spots.
```
example of map and it's result:
o...o.        o...o.
..o...        ..oxxx
......  --->  ...xxx
..o...        ..oxxx
...o..        ...o..
......        ......
```
## Usage
use **`make`** to create the **`setting_up`** exectuable   
You can either use a file :  
**`./setting_up <file>`**
the file has to be formated like this (see test.txt if you are unsure)  
```
the size of your map
your map (has to be size*size)
```
or use command line arguments :  
**`./setting_up <size> <pattern you want to repeat>`**
```
example : ./setting_up 3 ".o"
will create the map (see below) and execute the program with it
.o.
o.o
.o.
```
