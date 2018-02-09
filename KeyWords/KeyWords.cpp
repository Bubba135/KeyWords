// KeyWords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."}
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWORD = WORDS[choice][WORD]; //word to guess
	string theHINT = WORDS[choice][HINT]; //hint for word

	string jumble = theWORD; //jumbled version of word
	int lenght = jumble.size();
	for (int i = 0; i < lenght; ++i);
	{
		int index1 = (rand() % lenght);
		int index2 = (rand() % lenght);
		char temp = jumble[index2];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	//For the player
	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "The jumble is: " << jumble;

	string guess;
	cout << "\n\nYour Guess: ";
	cin >> guess;

	while ((guess != theWORD) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHINT;
		}
		else
		{
			cout << "Sorry, that's not it.";
		}

		cout << "\n\nYour Guess: ";
		cin >> guess;
	}
		
	if (guess == theWORD)
	{
		cout << "\nThat's it! You Guessed it!\n";
	}

	cout << "\nThanks for Playing.\n";

	system("pause");
    return 0;
}

