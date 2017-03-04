/*
Name:					Stefani Moore
Last Date Modified:			11-11-2016
Assignment:				HW10
*/

//******************************************************
//HashTable.cpp File
//
//HashTable class implementations
//
//******************************************************

#include "HashTable.h"

//constructor
HashTable::HashTable(int sizeT)
{
	headPtr = new Node*[sizeT];

	for (int i = 0; i < sizeT; i++)
	{
		headPtr[i] = nullptr;
	}
	wordCount = 0;
}

//destructor
HashTable::~HashTable()
{
}

bool HashTable::isEmpty(int key)
{
	if (key >= 0 && key < NUM_BUCKETS)
	{
		return headPtr[key] == nullptr; //If ptr is empty, returns true, else returns false
	}
	return true;
}

int HashTable::hash(string inputWord)
{
	std::locale loc; //used in character case conversion
	char tempChar = 'x';
	string tempString = "";
	int tempInt = 0;


	for (size_t i = 0; i < inputWord.length(); i++) //for entire string length
	{
		tempChar = std::tolower(inputWord[i], loc); //Converts all characters to lower case

		tempInt += int(tempChar); //Sums up the total ASCII value of the characters in the string
	}

	return tempInt % NUM_BUCKETS; //Returns hashKey which is equal to the sum of the ASCII character values mod 1373
}

void HashTable::insertWord(string newWord)
{
	int key = hash(newWord);
	appendWord(key, newWord); //determine hashKey and appended to that hash bucket
}

void HashTable::appendWord(int hashKey, string newWord)
{
	Node* tempNode = new Node(); //allocate memory for new node

	tempNode->wordNode = newWord; //wordNode of tempNode new Node struct = newWord
	tempNode->nextPtr = nullptr; //nextPtr of tempNode new Node struct = nullptr

	if (isEmpty(hashKey)) //If the bucket is empty, headPtr = tempNode
	{
		headPtr[hashKey] = tempNode;
	}
	else //If not empty traverse linked list until nullptr is reached and insert new node at the end
	{
		Node* tempPtr = headPtr[hashKey];
		while (tempPtr->nextPtr != nullptr)
		{
			tempPtr = tempPtr->nextPtr;
		}
		tempPtr->nextPtr = tempNode;
	}

	//++bucketSize[hashKey]; //increase bucket size for the specific bucket
	++wordCount; // increase total word count
}

int HashTable::WordCount()
{
	return wordCount; //return total word count of hash table
}

int HashTable::Count(string searchWord)
{
	int key = hash(searchWord); //Get hash value of search word
	int search = 0; //To hold count of times the word is encountered

	if(!isEmpty(key)) //If hashKey bucket is not empty
	{
		for (Node* tempPtr = headPtr[key]; tempPtr != nullptr; tempPtr = tempPtr->nextPtr)
		{
			if (tempPtr->wordNode == searchWord) //If word encountered search = search + 1
			{
				search++;
			}
		}
	}

	return search; //Return total times the word is exists within the hashtable
}

void HashTable::emptyHash()
{
	wordCount = 0;

	cout << "\nDeleting hash table contents.\n";

	for (int i = 0; i < NUM_BUCKETS; i++)
	{
		if (!isEmpty(i))
		{
			while (!isEmpty(i))
			{
				Node* tempPtr = headPtr[i];
				headPtr[i] = headPtr[i]->nextPtr;
				delete tempPtr;
			}
		}
	}
}
