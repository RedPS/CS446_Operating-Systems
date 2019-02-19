# CS 446 Project 1

## General information
For this program we will be simulating an OS environment. This program
accepts a set of instructions from a metadata file (.mdf) and it will
use a configuration file to set up the environment.
Please compile using the provided makefile and run the simulation using the command
below:

```
./sim1 CONFIG.conf
```
## Implementation
I have decided to make this program as modular as I could since we were
informed that future projects would build on top of this one. Hence I
have tried to separate everything into their own components by creating
classes and making sure to follow the OOP principle.

## Data Structure & Algorithm
Most of the data structure used in this program is consisted of
vectors, I saw no need for using other data structures as a simple
array with easy access (vectors) would suffice. If a program becomes larger however it is a good idea to start thinking about migrating to other data structures maybe a combination of queues and binary trees to make accessing instructions faster.
I am also using STL to make accessing vectors, printing, erasing or modifying them in genral easier.

## Detail about functions
Functions used in classes are self explainatory as they are normal functions used in anyother classes. I will try to go over the functions used in the \"Functions\" file since they are not part of any classes. I have also put them into their own namespace in case I don't want to use them in the future or other functions gets added to them it will be easier to keep track of them.

### ProcessTheTime(...)

```
void ProcessTheTime(args);
```

This functions goes over the loaded metadata and tries to make sense of it. It will get the time cycle and multiply it with the appropriate time cycle of a descriptor, given in the config file.
Of course error handling is a must here so I am checking for basic errors that might be caused by the user or a corrupted file.

### logtofile(...)

```
void logtofile(args);
```
As the name already indicates, this function handles all logging info. It will process info about where the user/instruction wants the output to be logged and will do just that.

### logoutput(...)

```
void logoutput(args);
```
This function is depended on logtofile(...) since it will look at the arguments passed by logotofile(...) to indicate where it needs to print the output. What I have done is I pass in either Both (which means output to both monitor and file) or monitor or just file. At first my implementation would accept "monitor" or "Monitor", "file" or "File" but after careful consideration I have decided to make that case sensitive, since that is how most keywords work in C/C++.


