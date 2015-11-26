Kyle Consiglio		(k.consiglio@csu.fullerton.edu)
Trevor Hurt		(thurt@csu.fullerton.edu)
Jared Kotoff		(krylic@gmail.com)
Natally Santillan	(nat1130@csu.fullerton.edu)
CPSC 456 - Section 1
Assignment 2

************
PART I
************

Try opening the file using the 7-zip program. What happens? (Note: one way to open the file using the 7-zip program is to right-click on result.7z and choose 7-zip ? Open archive. What happens? Are you able to extract and run the worm.bat file inside the archive?

After appending and renaming the file to result.7z, I found the worm.bat file and was able to execute without any issues. In addition, the file size was reduced to the same as worm.bat.



Repeat the above steps, but this time rename the file to result.gif extension. Try opening the file. What happens?

It changed the file to the contents of the lol.gif that I downloaded from before and copied, also being able to open the files without any issues. The file size was reduced to the same as lol.gif.



Explain what is happening. Do some research in order to find out what the above copy command does. In your explanation be sure to explain the role of each argument in the above command. Also, be sure to explain how Windows handles files which leads to the above behavior.

The copy command is used to copy one or more files known as the source files, and store them into the destination file. The /B argument means it’s in binary mode, placing both files’ bytes into the destination file. Windows handles this behavior by having the copied files stored in the same format they are found in, meaning the copied files can be used just as you would use the original.



How can this technique be used for hiding malicious codes?

When copying the files it contains additional bytes, so we can inject malicious instructions to hijack the executable and change the original behavior for malicious intent.



How robust is this technique in terms of avoiding detection by anti-virus tools? You may need to do some research.

This method is not very robust, as shown from before when copying the files it adds additional bytes to the files. Typically most anti-virus software should raise a red flag when noticing this and right away it will be detected.



************
PART II
************

System Requirments: 32-bit Ubuntu 12.04 system with g++ version 4.8 installed

INSTRUCTIONS

The program shall take names of multiple executable files as command line argument and merge these executables into a single executable file called bound. The binder program shall be invoked using python binder.py < PROG 1> <PROG 2>...<PROG N> command line where each PROGi  is an executable program.

For example, to run the program use the following commands 

  python binder.py /usr/bin/ls /usr/bin/pwd

upon sucession the following shall be ouput
  Compiling..
  Compilation succeeded

To run all executable files passed in as parameters simply type in the following command
  ./bound
  
The ouput should resemble something like the following example where <Program Output> shall be what the program is suppose to do: 
  <Program Output 1>
  Child Complete
  <Program Output 2> 
  Child Complete....
  <Program Output N>
  Child Complete
  wait: No child processes

************
BONUS
************

System Requirements: Visual Studios 2013, Python 3.6 install along with hexdump library 

WARNING: If C++ programs are compiled through visual studios make sure to compile them in release mode otherwise binder.py won't work. 

INSTRUCTIONS

The program shall take names of multiple executable files as command line argument and merge these executables into a single executable file called bound. The binder program shall be invoked using python binder.py < PROG 1> <PROG 2>...<PROG N> command line where each PROGi  is an executable program.

For example, to run the program use the following commands 

  python binder.py <PROG 1>.exe <PROG 2>.exe

upon sucession the following shall be ouput
  Compiling..
  Compilation succeeded

To run all executable files passed in as parameters simply type in the following command
  c:\bound.exe
  
The ouput should resemble something like the following example where <Program Output> shall be what the program is suppose to do: 
  <Program Output 1>
  Child Complete
  <Program Output 2> 
  Child Complete....
  <Program Output N>
  Child Complete
  wait: No child processes
