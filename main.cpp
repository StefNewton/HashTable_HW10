
/*
Name:				Stefani Moore
Last Date Modified:		11-11-2016
Course:				CSCI 2421 - Data Structures
Assignment:			HW10
Description:			This program is a simple spelling checker. 
				The file dict.dat contains 25,021 frequently used words, 
				each on a separate line in lowercase. Read the file, and insert the 
				words into a hash table with 1373 buckets. The user will be able to 
				input a file to be spell-checked where the misspelled words will be 
				displayed along with the # of words in the dictionary, # of words in 
				the file, and # of words not in the dictionary (i.e. the number of
				misspelled words)

Status:				Compiles via Microsoft Visual Studios Community 2015.


NOTE:

According to canvas the Potter.txt file should be around 78452 words in file and 19531 misspelled 
words. I have found that the only way to get close to these numbers is when blank or empty strings
are counted and when not all non-alphanumeric characters are removed from the beg. and end of a word.
Blank or empty strings result when two non-alphanumeric characters such as, '--' exist in the file to 
spell-check. Really these shouldn't be a part of the word count so I have written code to remove
blank strings from the overall count, which is why my numbers are lower than that listed on canvas.
I also loop though the front and back of each word to make sure that all non-alphanumeric char's are 
removed. For example, if "He didn't know..." was in the book, looking at only the first and last char's
would result in 'he, didn't, know...' (know... is not what should be spell-checked or counted as a word)
So my program will loop until the w of know is reached and as a result it correctly spell-checks 'he,
didn't, know'.  To get close to the canvas result you also have to count know and know... as two seperate
words which is also incorrect. This results in my numbers being way off from canvas, but this to me seems much more 
accurate and eliminates a lot of unnecessary counting and spell-checking of strings that are not actually 
words. I also implemented a second hash table of the misspelled words so that I could quickly search for
misspelled words that I have already printed that way a bunch of duplicates weren't printed to the screen.
This small change cut my program's execution time nearly in half, but comes at the cost of using up more memory.

*/

#include "HashTable.h"


//Functions for spellchecker
HashTable loadDictionary(); //load dictionary into hashtable
void openFile(HashTable& hashTable); //Open file to spellcheck and run spell check 
string isAlphaNumeric(string& wordIn); //removes non alpha-numeric characters from the beginning and end of the word and converts word to lowercase


//***************************************************************************
//
//				MAIN
//
//***************************************************************************

int main()
{
	HashTable dictionaryTable; //HashTable object
	char choice = 'y';
	dictionaryTable = loadDictionary();
	cout << endl;

	while (choice == 'Y' || choice == 'y')
	{
		openFile(dictionaryTable);

			cout << "\n\nSpell check another file? (y/n)\n";
			cin >> choice;
	}

	dictionaryTable.emptyHash();
	return 0;
} //End main


//***************************************************************************

HashTable loadDictionary()
{
	HashTable hashTable; //create hashTable object
	string inputWord; //Word input from file
	std::ifstream fileInput; //input file stream


	fileInput.open("dict.dat");


	if (fileInput.fail()) //Cound not open file
	{
		cout << "\nERROR: Could not open dictionary file.\n";
		exit(1);
	}

	cout << "Loading dictionary file dict.dat....\n";
	while (fileInput >> inputWord) //while there is file content
	{
		hashTable.insertWord(inputWord); //insertWord into hashTable
	}

	cout << "\nDictionary Word Count: " << hashTable.WordCount() << endl; //Display hashTable wordCount

	return hashTable; //return dictionary hashTable
}

void openFile(HashTable& hashTable)
{
	int wordCount = 0;
	int countLine = 0;
	int count = 0;
	int uniqueCount = 0;

	std::ifstream inFile;
	string temp;
	string word;
	string wordStr;

	clock_t beg;
	clock_t end;

	bool fileFail = true;

	HashTable tempHash;


	while (fileFail == true) //Loop will continue until a good / valid file name is entered
	{
		cout << "Input a file to spell check: "; //user inputs a file to check
		cin >> temp;
		cout << endl;
		inFile.open(temp);

		if (inFile.fail()) //check that file is valid
		{
			cout << "\nERROR: Could not open file. Try again.\n";
			fileFail = true; //file failed
		}
		else
			fileFail = false; //file did not fail
	}

	cout << "***********\n "
		<< "My results differ from canvas because I removed blank/empty strings\n"
		<< "from the total count. These happen when stand alone char's such as, --\n"
		<< "are encountered. I also loop through the front and back of each word to\n"
		<< "make sure that all non-alphanumeric characters are removed such as when we\n"
		<< "encounter \"He didn't know....\" it will print has he, didn't, know, \n"
		<< "*************\n\n";

	cout << "Words that could be mispelled: \n\n"; //Prompts user with what words are possibly misspelled

	beg = clock(); //begin timer

	while (inFile >> wordStr) //Read in file word-by-word into a string
	{
		
			
			word = isAlphaNumeric(wordStr); //removes non-alphanumeric characters and converts all alpha char's to lowercase

			if (word != "" && word != " ") //Don't waste time printing or spell-checking empty or blank strings
			{
				++wordCount; //Increase word count

				//SPELL CHECKER
			if (hashTable.Count(word) == 0)
			{
				//Keeps blank strings from being printed to the screen and counted as misspelled words
				if (word != " " && word != "" && !word.empty())
				{
					tempHash.insertWord(word);
					if (tempHash.Count(word) <= 1)
					{
						cout << word << ", ";
						countLine++;
						uniqueCount++;
					}

					count++; //This count is more accurate because it does not include the blank or empty strings 
				}

				if (countLine == 5)
				{
					cout << endl;
					countLine = 0;
				}
			}
		}
	}

	end = clock() - beg; //end timer
	if (count > 0)
	{
		cout << "\n\nInput file word count: " << wordCount << endl;
		cout << "Number of unique words spelled incorrectly: " << uniqueCount << endl;
		cout << "Total number of words spelled incorrectly: " << count << endl; //My number will be lower because it does not include blank strings in the count
		cout << "File checked in " << (double)end / ((double)CLOCKS_PER_SEC) << " seconds!\n";
	}
	else
	{
		cout << "\n\nInput file word count: " << wordCount << endl;
		cout << "No misspelled words found.\n";
		cout << "File checked in " << (double)end / ((double)CLOCKS_PER_SEC) << " seconds!\n";
	}

	tempHash.emptyHash();
}

string isAlphaNumeric(string& wordIn)
{
	int i = 0;
	
	while (!isalnum(wordIn[i]) && wordIn.size() > 0)
	{
			wordIn.erase(i, 1);
	}

	if (wordIn != "" && !wordIn.empty() && wordIn != " ")
	{
		while (!isalnum(wordIn.back()) && wordIn.size() > 0)
		{
			wordIn.pop_back();
		}
	}


	//Convert alpha characters to lower case
	std::locale loc;
	char tempChar;
	string tempStr;

	if (!wordIn.empty() && wordIn != "" && wordIn != " ")
	{
		for (size_t i = 0; i < wordIn.length(); i++)
		{
			if (isalpha(wordIn[i]))
			{
				tempChar = std::tolower(wordIn[i], loc); //Converts all characters to lower case
				tempStr.push_back(tempChar);
			}
			else
				tempStr.push_back(wordIn[i]);
		}
		return tempStr;
	}
	else
		return "";


}

