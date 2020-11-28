#pragma once
#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include "TreeType.h"

using namespace std;

const int DisplayTreeCode = 1;
const int InsertValueCode = 2;
const int SearchAvlTreeCode = 3;
const int RemoveValueCode = 4;
const int ClearTreeCode = 5;
const int InitializeTreeCode = 6;
const int ExitProgramCode = 7;

TreeType<string>* avlTree = new TreeType<string>();
int choice;
bool leaveMenu = false;

void ClearAvlTree();
void DisplayBanner();
int DisplayMenu();
void DisplayTree();
void ExitProgram();
void InitializeAvlTree();
void InsertValue();
void HandleInvalidCode();
void RemoveValue();
void SearchAvlTree();
void run();

void ClearAvlTree()
{
	//avlTree->Clear();
	cout << endl << "The AVL Tree has been cleared." << endl;
}
void DisplayBanner()
{
	cout << "******************************************\n";
	cout << "  Lecture Code : AVL Tree \n";
	cout << "******************************************\n\n";

}
int DisplayMenu()
{
	int option;
	system("cls");
	DisplayBanner();
	string menu = " " + to_string(DisplayTreeCode) + " -> Display the AVL Tree.\n"
		+ " " + to_string(InsertValueCode) + " -> Insert into AVL Tree.\n"
		+ " " + to_string(SearchAvlTreeCode) + " -> Search the AVL Tree.\n"
		+ " " + to_string(RemoveValueCode) + " -> Delete from the AVL Tree.\n"
		+ " " + to_string(ClearTreeCode) + " -> Clear the AVL Tree.\n"
		+ " " + to_string(InitializeTreeCode) + " -> Initialize the AVL Tree with default values.\n"

		+ " " + to_string(ExitProgramCode) + " -> Exit.\n\n"
		+ "******************************************\n"
		+ " \n  Enter your choice and press return: \n\n"
		+ "******************************************\n";

	cout << menu;
	cin >> option;
	return option;
}
void DisplayTree()
{
	system("cls");
	DisplayBanner();

	//if(avlTree->IsEmpty())
	{
		cout << "The AVL Tree is empty." << endl << endl;
	}
	//else
	{
		//TreeInorderPrinter<string>* printer = new TreeInorderPrinter<string>(avlTree);
		//cout << printer->printString() << endl << endl;
		cout << avlTree->ToString() << endl << endl;
	}
}
void ExitProgram()
{

	cout << "End of Program.\n";
	cin.get();
	leaveMenu = true;
}
void HandleInvalidCode()
{
	cout << "Not a Valid Choice. \n Please enter again! ";
}
void InitializeAvlTree()
{
	//avlTree->Clear();
	cout << "Initialize AVL Tree:";
	string namesValues[] = { "Tom" , "Ursula", "Mary", "Zaki", "Tim", "Amy" };	// { "Mark", "Ann", "Tom", "Sarah", "Simon" };
	for(string value : namesValues)
	{
		avlTree->InsertItem(value);
		cout << " " << value;
	}
	cout << "." << endl << endl;
}
void InsertValue()
{
	string userInput;
	do
	{
		cout << "\nPlease enter the name you would like to add: (Enter 0 to cancel)\n";
		cin >> userInput;
		if(userInput != "0")
		{
			cout << "Now adding " << userInput << endl;
			avlTree->InsertItem(userInput);
		}
	} while(userInput != "0");
}
void RemoveValue()
{
	string userInput;

	cout << endl << "Please enter the name you would like to Delete:" << endl;
	cin >> userInput;
	avlTree->DeleteItem(userInput);
	if(true)
		cout << "Removed " << userInput << " from the AVL Tree." << endl;
	else
		cout << "The AVL Tree does not contain " << userInput << "." << endl;
}
void SearchAvlTree()
{
	string userInput;
	do
	{
		cout << endl << "Please enter the name you would like to Search: (Enter 0 to cancel)" << endl;
		cin >> userInput;
		if(userInput != "0")
		{
			//avlTree->Contains(userInput)
			if(true)
				cout << "The AVL Tree contains " << userInput << "." << endl;
			else
				cout << "The AVL Tree does not contain " << userInput << "." << endl;
		}
	} while(userInput != "0");
}

void run()
{
	system("Color 80");
	InitializeAvlTree();

	string userInput;
	do
	{
		choice = DisplayMenu();
		switch(choice)
		{
			case ClearTreeCode:		ClearAvlTree();		break;
			case DisplayTreeCode:	DisplayTree();		break;
			case ExitProgramCode:	ExitProgram();		break;
			case InitializeTreeCode:InitializeAvlTree(); break;
			case InsertValueCode:	InsertValue();		break;
			case RemoveValueCode:	RemoveValue();		break;
			case SearchAvlTreeCode:	SearchAvlTree();	break;
			default:	HandleInvalidCode();			break;
		}
		system("pause");
	} while(!leaveMenu);
}