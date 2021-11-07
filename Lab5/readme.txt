Lab 5
Isabella Hansen & Julia Grandury

Display Tests
root $ ds i.img
X X
 X
X X

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds i
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds i.img -d
X X X X X
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds i.img f
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds 

Cat Tests

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat t.txt
Enter data you'd like to write to the file. Enter :wq to save and quit or enter :q to quit without saving
root/t.txt
:q
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat t.txt -a
ho
Enter data you'd like to write to the file. Enter :wq to save and quit or enter :q to quit without saving
root/t.txt
la
com
o es
ta
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat t.txt -a
hola
com
o es
ta

Enter data you'd like to write to the file. Enter :wq to save and quit or enter :q to quit without saving
root/t.txt
yaydyaydyyadkj
fjkfkjf
:q
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat t.txt -a
hola
com
o es
ta

Enter data you'd like to write to the file. Enter :wq to save and quit or enter :q to quit without saving
root/t.txt
:q
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat t.txt
Enter data you'd like to write to the file. Enter :wq to save and quit or enter :q to quit without saving
root/t.txt
oh la la
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds t.txt
oh la la

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat t.txt
Enter data you'd like to write to the file. Enter :wq to save and quit or enter :q to quit without saving
root/t.txt
heheheh
:q
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds t.txt -d
oh la la

LS Tests
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls -l
t.txt   text     size: 2
i.img   image    size: 9
dir     directory        size: 14
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
t.txt
i.img
dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls j
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ lsa
invalid command

Copy Test Cases

(base) H:\object oriented\lab5-aurevoircpp\labfive\Debug>labfive.exe
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
t.txt
i.img
dir

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ls
im.img
te.txt

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ cd ..
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cp dir
Please put in file and directory you want to copy to
command failed
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd t.txt dir
not a directory
command failed
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cp t.txt root/dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ls
im.img
te.txt
t.txt

Remove Tests
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch labfive
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd labfive
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/labfive $ touch i.img
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/labfive $ touch t.txt
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/labfive $ cd ..
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm labfive
root/labfive
This directory is not empty
command failed
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm labfive -r
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
t.txt
i.img
dir

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir
root/dir
This directory is not empty
command failed
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir -r
Could not completely empty directory
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ls
te.txt

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ rm
root/dir/
File does not exist
command failed
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ rm d
root/dir/d
File does not exist
command failed
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ rm t.txt
root/dir/t.txt
File does not exist
command failed
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $