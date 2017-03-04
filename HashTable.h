#pragma once
/*
Name:				Stefani Moore
Last Date Modified:		11-11-2016
Assignment:			HW10
*/

//******************************************************
//HashTable.h File
//
//HashTable class declaration
//
//******************************************************
#ifndef HASH_H
#define HASH_H

#include<locale> //for tolower coversion
#include <iostream> //input-output stream
#include <string> //string
#include <sstream> //string-stream conversion
#include<cctype> //isalnum
#include<fstream> //filestream
#include<vector> //vector
#include<ctime> //To determine execute time

using std::string;
using std::cin;
using std::cout;
using std::endl;

const int NUM_BUCKETS = 1373; //Number of buckets for the hash table

class HashTable
{

private:

	struct Node //Used for the linked list implementation
	{
		string wordNode; //Word input
		Node* nextPtr; //Pointer to next node in the list
	};

	Node** headPtr; //Reference to head pointer within a given bucket

	int wordCount; //total word count of the hashTable


public:

	HashTable(int sizeT = NUM_BUCKETS); //Constructor table initialized to size of 1373

	~HashTable(); //Destructor

	bool isEmpty(int key); //Used to determine if the table is empty

	int hash(string wordInput); //Creates a hashKey from the string

	void insertWord(string newWord); //Insert word into the table

	void appendWord(int hashKey, string newWord); //append word to the end of a buckets linked list

	int WordCount(); //total word count in the hash table

	int Count(string searchWord); //return number of times word is found in the table

	void emptyHash();

};//End HashTable class

#endif
