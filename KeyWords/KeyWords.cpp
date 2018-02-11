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
		{"west", "The direction toward the point of the horizon where the sun sets."},
		{"sandbar", "Narrow sandbank."},
		{"civilization", "The stage of human social development."},
		{"persistent", "Keep at it."},
		{"israel", "A Jewish state."}
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
	cout << "\t\t\tWelcome to The Code Bracker!\n\n";
	cout << "Unscramble the letters that we intersept form the eastern world.\n";
	cout << "Enter 'hint' if you need help from another agent.\n";
	cout << "Enter 'quit' if you are not up to the job.\n\n";
	cout << "The Secret Word is: " << jumble;

	string guess;
	cout << "\n\nYour Final Answer: ";
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
		cout << "\nThat's it! You are up for a promotes!\n";
	}

	cout << "\nThanks for your good work.\n";

	system("pause");
    return 0;
}

