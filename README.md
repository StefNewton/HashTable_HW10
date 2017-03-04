# HashTable_HW10
*******************************************************
*  Name      :  Stefani Moore        
*  Student ID:  106789878  
*  Class     :  CSCI 2421           
*  HW#       :  10                
*  Due Date  :  Nov. 16, 2016
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program is a simple spelling checker. 
The file dict.datPreview contains 25,021 frequently used words, 
each on a separate line in lowercase. Read the file, and insert the 
words into a hash table with 1373 buckets. The user will be able to 
input a file to be spell-checked where the misspelled words will be 
displayed along with the # of words in the dictionary, # of words in 
the file, and # of words not in the dictionary (i.e. the number of
possibly misspelled words).

NOTE:

According to canvas the Potter.txt file should be around 78452 words in 
file and 19531 misspelled words. I have found that the only way to get 
close to these numbers is when blank or empty strings are counted. These 
result when two non-alphanumeric characters such as, '--' exist in the 
file to spell-check. Really these shouldn't be a part of the word count
so I have written code to remove blank strings from the overall count, 
which is why my numbers are lower than that listed on canvas. I also loop 
though the front and back of each word to make sure that all non-alphanumeric
char's are removed. For example, if "He didn't know..." was in the book, 
looking at only the first and last char's would result in 'he, didn't, 
know...' (know... is not what should be spell-checked or counted as a word)
So my program will loop until the w of know is reached and as a result it 
correctly spell-checks 'he, didn't, know'.  This results in my numbers being
way off from canvas, but this to me seems much more accurate and eliminates
a lot of unnecessary counting and spell-checking of strings that are not actually 
"words". I also implemented a second hash table of the misspelled words so that I 
could quickly search for misspelled words that I have already printed that way
a bunch of duplicates weren't printed to the screen. This small change cut my 
program's execution time nearly in half, but comes at the cost of using up
more memory.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver file that calls sub-functions
   to read a book from a file and spell check the words.

Name:  HashTable.h
   Contains the definition for the HashTable class.  

Name: HashTable.cpp
   Defines and implements the HashTable class.    
   
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
       	HashTable.h
       	HashTable.cpp
	dict.dat
	check.txt
	Potter.txt
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [MooreHW10] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[hw10]

4. Delete the obj files, executables, and core dump by
   %./make clean

