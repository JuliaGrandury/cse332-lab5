# CSE 332S Lab 5: OOP Design #

Lab overview:
This lab will build upon studios 16-21. Throughout studios 16-21 and continuing into lab 5, you will build a software simulation of a file system, some simple file types that may be stored in a file system, and a user interface similar to a command prompt or terminal that allows a user to interact with the file system and files it contains. Throughout the design and implementation of the file system, OOP design principles and patterns learned throughout the semester will be used to ensure the file system can be extended with new functionality in the future, easy to modify without major code refactoring, and easy to configure with different functionality as needed. 

What you will implement in lab 5: ​For lab 5, you will be modifying a couple of the commands I have written for you to extend their functionality a bit. You will also be creating a few additional commands to increase the functionality of the program. The commands you will modify or implement are listed below, you will find further details on the specification and requirements of each command later in this document. In lab 5, you will:
1. Modify the LSCommand to take an additional option that displays metadata information about each file in the CWD
2. Modify the HierarchicalFileSystem to enforce that empty directories cannot be removed. Then modify the RemoveCommand to implement an option that recursively removes all files contained within a directory and then removes the directory
3. Create and implement a command called “cat” that concatenates user input onto a file
4. Create and implement a command called “ds” that displays the contents of a file based
on the file’s type
5. Create and implement a copy command. Copy makes a copy of an existing file and
stores it somewhere else in the file system
6. Create and implement a command for creating symbolic links.
