#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Cube.h"
#include "Solver.h"
#include "Match.h"


using namespace std;


// Check mystery word to see if it can be solved by scrambler.
void checkStrings(string x, vector<Cube> y, vector<Match> z)
{
	
	int letterIndex = 0;
	int matchedLetters = 0;
	bool solutionFound = false;
	
	Solver probSolver;
	probSolver.letterMatched = false;
	
	z.clear();
	
	// Traverse cubes to find matching letters for mystery word
	for (int i = 0; i < y.size(); i++) {
		
		if (matchedLetters < x.length())
		{
			probSolver.loopThroughCube(x.at(letterIndex), y[i]);
		}
		
		if (probSolver.letterMatched == true)
		{
			//cout << "Matched " << x.at(letterIndex) << " with " << i + 1 << endl;
			Match aMatch (x.at(letterIndex), i+1);
			z.push_back(aMatch);
			letterIndex++;
			matchedLetters++;
			probSolver.letterMatched = false;
			
		}							
		
	} // End of traversal
	
	
	// Determines if string can be solved or not.
	if ( matchedLetters == x.length() )
	{
		
		cout << "Solution found with following matches:" << endl;
		solutionFound = true;
		for (int i = 0; i < z.size(); i++)
		{
			cout << "Letter " << z[i].letterOfWord << " and cube " << z[i].matchingCube << endl; // Displays matches
		}
	}
	else {
		
		if (std::next_permutation(x.begin(), x.end()) == true)
		{
			
			checkStrings(x, y, z);
		}
	}
	
	
	if (std::next_permutation(x.begin(), x.end()) == false && solutionFound == false)
	{
		cout << "Solution was not found" << endl;
	}
	
	
}

// Commands show up when user asks for help
void displayCommands()
{
	cout << "r - Problem reset" << endl;
	cout << "c - Enter new cube" << endl << "a - Show all cubes" << endl;
	cout << "w - Enter new word" << endl << "s - Solve problem" << endl;
	cout << "q - Quit" << endl;
	
}




int main (int argc, char * const argv[]) {
    
	char theSides[6];
	string command, word;
	
	
	std::vector<Cube> cubes;
	
	string line;
	
	/** Optional command line argument that reads in cubes from a text file
	 The text file must be in a specific format. Six alphabet characters on every line with no spaces.
	 **/
	
	ifstream myfile (argv[1]);
	
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			char cube [6];
			strcpy(cube, line.c_str());
			Cube inputCube(cube);
			cubes.push_back(inputCube);
		}
		myfile.close();
	}
	
	//else cout << "Unable to open file"; 
	
	// The game starts here
	cout << "Welcome to the cube scrambler game! You can choose from any of the following";
	cout << " commands below. Press 'h' at any time to display them again." << endl;
	displayCommands();
	
	
	// Used to show which letters got matched to which cube
	std::vector<Match> matches;
	
	// Menu for the game
	do {
		
		cout << "Enter in a command:";
		
		std::cin >> command;
		
		if ( command.compare("c") == 0) {
			
			cout << "Enter six characters for sides of the cube:";
			cin >> theSides;
			
			Cube aCube(theSides);
			cubes.push_back(aCube);
			
			
		}
		
		else if ( command.compare("a") == 0)  {
			
			for (int i = 0; i < cubes.size(); i++) {
				cout << i + 1 << "\t";
				cubes[i].showSides();
				cout << endl;
			}
			
			cout << "Current word: " << word << "\n";
			
		}
		
		else if ( command.compare("w") == 0)  {
			
			cout << "Enter in a word to be solved:";
			cin >> word;
			
		}
		
		else if ( command.compare("r") == 0)  {
			
			cubes.clear();
			word = "";
			cout << "Cubes deleted" << "\n";
			
		}
		
		else if ( command.compare("s") == 0)  {
			
			Solver probSolver;
			probSolver.letterMatched = false;
			
			string originalWord = word;
			
			sort(word.begin(), word.end());
			
			checkStrings(word, cubes, matches); // recursive method for solving word		
			
			word = originalWord;
			
		}
		
		else if ( command.compare("h") == 0)  {
			displayCommands();
		}
		
		
	} while ( command.compare("q") != 0) ; // End of program
	
	
    return 0;
}
