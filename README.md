# HashTable_HW10
*******************************************************
*  Name      :  Stefani Moore        
*  Student ID:  106789878  
*  Class     :  CSCI 2421           
*  HW#       :  10                
*  Due Date  :  Nov. 6, 2016
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

***Program Not yet developed. Will upload ASAP***

This programming homework is to develop a simple spelling 
checker. The file dict.datPreview contains 25,025 frequently 
used words, each on a separate line in lowercase. Read the 
file, and insert the words into a hash table with 1373 buckets.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver file that calls sub-functions
   to read a book from a file and spell check the words.

Name:  Hash.h
   Contains the definition for the Hash class.  

Name: Hash.cpp
   Defines and implements the Hash class.    
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on Microsoft Visual
   Studios Community 2015.  It was compiled, run, and tested 
   on the csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [MooreHW10]

   Now you should see a directory named homework with the files:
        main.cpp
       	Hash.h
       	Hash.cpp
	dict.dat
	book.txt
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [MooreHW10] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[spellCheck]

4. Delete the obj files, executables, and core dump by
   %./make clean
