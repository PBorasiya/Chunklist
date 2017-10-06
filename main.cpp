// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "ChunkList.h"

using namespace std;
void PrintList(ofstream& outFile, ChunkList& list);

int main()
{
  ifstream inFile;
  ofstream outFile;
  string inFileName;
  string outFileName;
  string command;

  int number;
  ItemType item;
  ChunkList list;
  bool found;
  int numCommands;



  cout << "Enter name of input command file:" << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file:" << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());


  if (!inFile)
  {
    cout << "file not found" << endl;

  }
  inFile >> command;

  numCommands = 0;
  while (command != "Quit")
  {
    if (command == "PutItem")
    {
      inFile >> number;
      item.Initialize(number);
      list.PutItem(item);
      item.Print(outFile);
      outFile << " is in list" << endl;
    }
    else if (command == "DeleteItem")
    {
      inFile >> number;
      item.Initialize(number);
      list.DeleteItem(item);
      item.Print(outFile);
      outFile << " is deleted" << endl;
    }
    else if (command == "GetItem")
    {
      inFile >> number;
      item.Initialize(number);
      item = list.GetItem(item, found);
      item.Print(outFile);
      if (found)
        outFile << " found in list." << endl;
      else outFile <<  " not in list."  << endl;
    }
    else if (command == "GetLength")
      outFile << "Length is " << list.GetLength() << endl;
    else if (command == "IsFull")
      if (list.IsFull())
        outFile << "List is full." << endl;
      else outFile << "List is not full."  << endl;
    else if (command == "MakeEmpty")
	  list.MakeEmpty();
	else if (command == "PrintList")
	  PrintList(outFile, list);
	else
	  cout << command << " is not a valid command." << endl;
	numCommands++;
    inFile >> command;
  };


  inFile.close();
  outFile.close();
  return 0;
}


void PrintList(ofstream& dataFile, ChunkList& list)

{
  int length;
  ItemType item;

  list.ResetList();
  length = list.GetLength();
  for (int counter = 1; counter <= length; counter++)
  {
    item = list.GetNextItem();
    item.Print(dataFile);
  }
  dataFile << endl;
}

