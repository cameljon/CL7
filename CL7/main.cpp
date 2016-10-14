#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void ReadFile(string filename)
{
	ifstream input;
	input.open(filename);

	string lineOfText;

	while (getline(input, lineOfText))
	{
		cout << lineOfText << endl;
	}
	input.close();
}

void SearchFile(string filename, string searchFor)
{
	int lineCount = 0;
	ifstream input;
	input.open(filename);

	string lineOfText;

	while (getline(input, lineOfText))
	{
		if (lineOfText.find(searchFor) != string::npos)
		{
			cout << "Text found at " << lineCount << ": " << lineOfText << endl;
		}
		lineCount++;
	}
	input.close();
}

void LoadNouns(string nouns[100], int & nounCount)
{
	nounCount = 0;
	ifstream input;
	input.open("nouns.txt");
	string lineOfText;
	while (getline(input, lineOfText))
	{
		nouns[nounCount] = lineOfText;
		nounCount++;
	}
	input.close();
}

void LoadAdjectives(string adjectives[100], int & adjectiveCount)
{
	adjectiveCount = 0;
	ifstream input;
	input.open("adjectives.txt");
	string lineOfText;
	while (getline(input, lineOfText))
	{
		adjectives[adjectiveCount] = lineOfText;
		adjectiveCount++;
	}
	input.close();
}

string GeneratePoem(string nouns[100], int nounCount, string adjectives[100], int adjectiveCount)
{
	string poem = "";
	int randomNoun;
	int randomAdjective;
	
	for (int i = 0; i < 3; i++)
	{
		poem += nouns[rand() % nounCount] + " are " + adjectives[rand() % adjectiveCount] + ", \n";
	}
	poem += "and so are you!";
	return poem;
}

int LoadClasses(string classes[100])
{
	ifstream input("courses.txt");
	int classCount = 0;
	string buffer;
	while (input >> buffer)
	{
		classes[classCount] = buffer;
		classCount++;
	}
	input.close();
	return classCount;
}

void SaveClasses(string classes[100], int classCount)
{
	ofstream output("courses.txt");
	for (int i = 0; i < classCount; i++)
	{
		output << classes[i] << endl;
	}
	output.close();
}

void programOne()
{
	int votes[3] = { 0, 0, 0 };
	string options[3] = { "dogs", "cats", "birds" };

	bool done = false;

	while (!done)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << i << ". " << options[i] << endl;
		}
		cout << "3. Exit" << endl;

		cout << "Choice? ";
		int choice;
		cin >> choice;

		if (choice == 3)
		{
			done = true;
		}
		else
		{
			votes[choice]++;
		}
	}

	ofstream output;
	output.open("results.txt");

	for (int i = 0; i < 3; i++)
	{
		output << options[i] << " = " << votes[i] << endl;
	}

	output.close();
}

void programTwo()
{
	ReadFile("text.txt");
}

void programThree()
{
	string searchFor;
	cout << "Search: ";
	cin >> searchFor;
	SearchFile("text.txt", searchFor);
	}

void programFour()
{
	string nouns[100];
	int nounCount;
	string adjectives[100];
	int adjectiveCount;
	LoadNouns(nouns, nounCount);
	LoadAdjectives(adjectives, adjectiveCount);

	string poem = GeneratePoem(nouns, nounCount, adjectives, adjectiveCount);

	cout << "Poem!" << endl;
	cout << poem << endl;
}

void programFive()
{
	string classes[100];
	int classCount = LoadClasses(classes);

	for (int i = 0; i < classCount; i++)
	{
		cout << i << ". " << classes[i] << endl;
	}

	cout << "Edit which class? ";
	int edit;
	cin >> edit;

	cout << "New class name? ";
	cin >> classes[edit];

	SaveClasses(classes, classCount);
}

int main()
{
	srand(time(NULL));
	bool done = false;
	while (!done)
	{
		int runProgram = 0;
		cout << "Run which program?" << endl << "[1 -5] 6 to exit: ";
		cin >> runProgram;
		switch (runProgram)
		{
		case 1:
			programOne();
			break;
		case 2:
			programTwo();
			break;
		case 3:
			programThree();
			break;
		case 4:
			programFour();
			break;
		case 5:
			programFive();
			break;
		case 6:
			done = true;
			break;
		}
	}

	return 0;
}