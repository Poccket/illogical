// gate.c
// Various logic gates.
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h>
#include <limits>
using namespace std;
int gatebuff(int iA);                 // Q: "how many functions can you define before it's moronic?"
int gatenot(int iA);                  // A: "too many."
int gateor(int iA, int iB);
int gatenor(int iA, int iB);
int gateand(int iA, int iB);
int gatenand(int iA, int iB);
int gatexor(int iA, int iB);
int gatexnor(int iA, int iB);
int codecheck(string lvlnum, int lvl);
int lvlcode(int lvlcode, int lvl, string grocode);
int codenoprompt(string lvlnum, int lvl);
int lvlcodenon(int lvlcode, int lvl);
int promptlvl(int status, string curcode, string nexcode, int lvl); // variable heaven
int level1();
int level2();
int level3();
int level4();
int level5();
int level6();
int level7();
int level8();
int level9();
int level10();
int level11();
int startgame(int lvl);
int menu(int lvl, int complete);
int gateinput(string inp);

int main(int argc, char* argv[])			// start it up, boys. argv = array of command arguments, argc = number of command arguments
{
	int lvl = 1;							// gotta define it here first, boys, or else it bugs out
	int complete = 0;						// same as above, but it might be fine otherwise.
	string version = "0.4";			// game version, boys.
	cout								// tell me, wise one
		<< "Illogical "						// what version am I running?
		<< version							// thanks
		<< "\nmade in C++, compiled in G++\n";
	if ( argc > 2 ) {						// if there's more than two arguments
		cout							// then gtfo
			<< "---------------------------------------\n"
			<< "Whoops!\n"
			<< "Please only give one input if you're running from the command line.\n"
			<< "This input should be a level code.\n"
			<< "---------------------------------------\n";
		return 0;							// bye bitch
	}
	else if ( argc == 2 ) {					// if there's two arguments (./logic [])
		codecheck( argv[1], lvl );			// run it, my man.
		return 0;
	}
	ifstream my_file("savedata");		// if nothing else interrupted you, please grab the file 'savedata'
	if (my_file.good())						// if you grabbed it and it existed
	{
		ofstream myfile;				// get ready to write to it.
		string argg;					// and make me a string called argg
		getline(my_file, argg);		// grab all data from the file into the string
		codenoprompt( argg, lvl );			// run it without prompt, my man.
	} else {
		ofstream myfile;				// if it don't exist
		myfile.open ("savedata");			// MAKE IT EXIST
		myfile << "b8";						// write savedata to it
		myfile.close();						// stop making it exist.
		menu(lvl, complete);
	}
	return 0;								// if nothing is happening, be done.
}
int menu(int lvl, int complete)
{
	cout
		<< "---------------------------------------\n";
	int input;
	string lvlnum = "";
	cout 
		<< "0. Help\n"
		<< "1. Play\n"
		<< "2. Code\n"
		<< "3. Reset\n"
		<< "4. Exit\n";
	while ((cout << "> ")
		&& !(cin >> input)) {
		cout 
			<< "---------------------------------------\n"
			<< "Please select from the menu\n"
			<< "---------------------------------------\n" 
			<< "0. Help\n"
			<< "1. Play\n"
			<< "2. Code\n"
			<< "3. Reset\n"
			<< "4. Exit\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout
		<< "---------------------------------------\n";
	switch (input)
	{
		case 0:
		cout
			<< "Illogical is a puzzle game based around logic gates and en\n"
			<< "tering positive or negative inputs to recieve certain outp\n"
			<< "uts required to complete the level\n";
		menu(lvl, complete);
		break;
		case 1:
		startgame(lvl);
		break;
		case 2:
		cout << "> ";
		cin >> lvlnum;
		codecheck(lvlnum, lvl);
		break;
		case 3:
		remove("savedata");
		cout
			<< "Please wait..."
			<< endl;
		return 0;
		break;
		case 4:
		return 0;
		break;
		default:
		cout 
			<< "Please select from the menu\n";
		menu(lvl, complete);
		break;
	}
	return 0;
}
int codecheck(string lvlnum, int lvl)	// this is where we proccess the level codes
{											// barren of comments....
	if (lvlnum == "b8") {					// if the level code entered equals this
		lvlcode(1, lvl, lvlnum);			// run the lvlcode function with this level
	}
	else if (lvlnum == "mz") {
		lvlcode(2, lvl, lvlnum);
	}
	else if (lvlnum == "hx") {
		lvlcode(3, lvl, lvlnum);
	}
	else if (lvlnum == "aq") {
		lvlcode(4, lvl, lvlnum);
	}
	else if (lvlnum == "jl") {
		lvlcode(5, lvl, lvlnum);
	}
	else if (lvlnum == "hu") {
		lvlcode(6, lvl, lvlnum);
	}
	else if (lvlnum == "si") {
		lvlcode(7, lvl, lvlnum);
	}
	else if (lvlnum == "ok") {
		lvlcode(8, lvl, lvlnum);
	}
	else if (lvlnum == "wt") {
		lvlcode(9, lvl, lvlnum);
	}
	else if (lvlnum == "no") {
		lvlcode(10, lvl, lvlnum);
	}
	else if (lvlnum == "9a") {
		lvlcode(11, lvl, lvlnum);
	}
	else if (lvlnum == "jk") {
		lvlcode(12, lvl, lvlnum);
	}
	else if (lvlnum == "pi") {
		lvlcode(13, lvl, lvlnum);
	}
	else if (lvlnum == "re") {
		lvlcode(14, lvl, lvlnum);
	}
	else if (lvlnum == "za") {
		lvlcode(15, lvl, lvlnum);
	}
	else if (lvlnum == "qs") {
		lvlcode(16, lvl, lvlnum);
	}
	else if (lvlnum == "or") {
		lvlcode(17, lvl, lvlnum);
	}
	else if (lvlnum == "fg") {
		lvlcode(18, lvl, lvlnum);
	}
	else if (lvlnum == "1z") {
		lvlcode(19, lvl, lvlnum);
	}
	else if (lvlnum == "6q") {
		lvlcode(20, lvl, lvlnum);
	}
	else if (lvlnum == "goodboy") {			// dog easter egg
		lvlcode(417, lvl, lvlnum);
	}
	else if (lvlnum == "http418") {			// teapot easter egg
		lvlcode(418, lvl, lvlnum);
	}
	else if (lvlnum == "credit") {			// credits easter egg
		lvlcode(419, lvl, lvlnum);
	}
	else if (lvlnum == "please") {			// smiley easter egg
		lvlcode(421, lvl, lvlnum);
	}
	else if (lvlnum == "hi") {				// hello world easter egg
		lvlcode(422, lvl, lvlnum);
	}
	else {
		cout 
			<< "Not a code, Sorry."			// if this pops up, it really isn't a code, don't try it again.
			<< endl;
	}
	return 0;
}
int codenoprompt(string lvlnum, int lvl)// for if the savedata exists, where we proccess that.
{
	if (lvlnum == "b8") {					// if the level code stored equals this
		lvlcodenon(1, lvl);					// set the level to this without prompt
	}
	else if (lvlnum == "mz") {
		lvlcodenon(2, lvl);
	}
	else if (lvlnum == "hx") {
		lvlcodenon(3, lvl);
	}
	else if (lvlnum == "aq") {
		lvlcodenon(4, lvl);
	}
	else if (lvlnum == "jl") {
		lvlcodenon(5, lvl);
	}
	else if (lvlnum == "hu") {
		lvlcodenon(6, lvl);
	}
	else if (lvlnum == "si") {
		lvlcodenon(7, lvl);
	}
	else if (lvlnum == "ok") {
		lvlcodenon(8, lvl);
	}
	else if (lvlnum == "wt") {
		lvlcodenon(9, lvl);
	}
	else if (lvlnum == "no") {
		lvlcodenon(10, lvl);
	}
	else if (lvlnum == "9a") {
		lvlcodenon(11, lvl);
	}
	else if (lvlnum == "jk") {
		lvlcodenon(12, lvl);
	}
	else if (lvlnum == "pi") {
		lvlcodenon(13, lvl);
	}
	else if (lvlnum == "re") {
		lvlcodenon(14, lvl);
	}
	else if (lvlnum == "za") {
		lvlcodenon(15, lvl);
	}
	else if (lvlnum == "qs") {
		lvlcodenon(16, lvl);
	}
	else if (lvlnum == "or") {
		lvlcodenon(17, lvl);
	}
	else if (lvlnum == "fg") {
		lvlcodenon(18, lvl);
	}
	else if (lvlnum == "1z") {
		lvlcodenon(19, lvl);
	}
	else if (lvlnum == "6q") {
		lvlcodenon(20, lvl);
	}
	else if (lvlnum == "goodboy") {    // dog easter egg
		lvlcodenon(417, lvl);
	}
	else if (lvlnum == "http418") {    // teapot easter egg
		lvlcodenon(418, lvl);
	}
	else if (lvlnum == "credit") {     // credits easter egg
		lvlcodenon(419, lvl);
	}
	else if (lvlnum == "please") {     // smiley easter egg
		lvlcodenon(421, lvl);
	}
	else if (lvlnum == "hi") {         // hello world easter egg
		lvlcodenon(422, lvl);
	}
	else {
		cout 
			<< "Not a code, Sorry." // if this pops up, it really isn't a code, don't try again.
			<< endl;
	}
	return 0;
}
int lvlcode(int lvlcode, int lvl, string grocode)// this is the prompt for the level codes.
{											// it's because I don't trust anybody.
	string prompt = "";				// string for input
	cout								// "hey user
		<< "---------------------------------------\n"
		<< "This will put you from level "	// this is gonna take you from
		<< lvl 								// the level you're on
		<< " to level " 					// to
		<< lvlcode 							// the level this code corresponds to
		<< "."								// period"
		<< endl						// new line please
		<< "Are you sure you want to do this? [y/n]";// ARE YOU SURE ABOUT THAT?
	cout 
		<< endl 
		<< "> ";						// ~input styling~
	cin 
		>> prompt;							// take that input.
	if (prompt == "y") {					// if they say yes
		ofstream myfile;				// get ready to write to file
		myfile.open ("savedata");			// this file, in specific.
		myfile << grocode;					// in fact, write this.
		myfile.close();						// get out of that file.
		cout
			<< "Done."						// tell them it's done
			<< endl;					// the contract is sealed
		menu(lvlcode, 0);
	}
	else if (prompt == "n") {				// if they say no
		cout
			<< "Cancelled."					// tell them they failed
			<< endl;
		menu(lvl, 0);					// and GTFO
	}
	else {
		cout
			<< "error";						// and if something else happens?
	}										// just die
}
int lvlcodenon(int lvlcode, int lvl) 		// change the level with prompt (used for the savedata)
{
	string prompt = "";				// not sure what this is for?
	menu(lvlcode, 0);					// gtfo
}
int promptlvl(int status, string curcode, string nexcode, int lvl)// this is where we see if they're a failure or not
{
	string prompt = "";				// get ready for input.
	if (status == 1) {						// if they didn't fail
			ofstream myfile;			// write to the file
			myfile.open ("savedata");		// this file
			myfile << nexcode;				// write this
			myfile.close();					// gtfo
			lvl++;							// go to next level
			cout
				<< "Level complete."		// tell them they win
				<< endl
				<< "Next level? [y/n]"		// next level?
				<< endl
				<< "user: ";				// ~*(Input Styling)*~
			cin
				>> prompt;					// let them speak!
			if ( prompt == "y" ) {			// if they say yes
				startgame(lvl);				// then let's GO boys
			}
			else if ( prompt == "n" ) {		// if not
				cout
					<< "level code: "		// tell them the level code and
					<< nexcode
					<< endl;
				menu(lvl, 1);			// GTFO
			}
			else {							// if they say something else
				cout					// "wtf dude"
					<< "Please enter 'y' or 'n'"
					<< endl;			// "that ain't right"
				promptlvl(status, curcode, nexcode, lvl);// try again
			}
		}
		else if (status == 0) {				// if they fail
			cout
				<< "Level failed."			// let them know ASAP
				<< endl
				<< "Try again? [y/n]"		// do you want to fail again?
				<< endl
				<< "user: ";				// ~*$!♥([Input Styling])♥!$*~
			cin
				>> prompt;					// LET THEM SPEAK
			if ( prompt == "y" ) {			// if they say yes
				startgame(lvl);				// let's go
			}	
			else if ( prompt == "n" ) {		// if not
				cout
					<< "level code: "		// tell them the level code
					<< curcode
					<< endl;			// (ps. you're a failure if you see this)
				menu(lvl, 1);			// and G T F O
			}
			else {							// if they say something else
				cout					// ask them about the weather
					<< "Please enter 'y' or 'n'"
					<< endl;			// sike tell them they stupid
				promptlvl(status, curcode, nexcode, lvl);// and try again
			}
		}
}
int startgame(int lvl)						// this is where we actually start the game
{
	int complete;							// the part that determines if you fail
	string prompt = "";				// the input
	if (lvl == 0) {							// from here on out it's
		lvl = 1;							// if the level is this
	}										// go to this level
	if (lvl == 1) {							// then run the prompt
		complete = level1();
		promptlvl(complete, "b8", "mz", lvl);
	}
	else if (lvl == 2) {
		complete = level2();
		complete = gatenot(complete);
		promptlvl(complete, "mz", "hx", lvl);
	}
	else if (lvl == 3) {
		complete = level3();
		promptlvl(complete, "hx", "aq", lvl);
	}
	else if (lvl == 4) {
		complete = level4();
		promptlvl(complete, "aq", "jl", lvl);
	}
	else if (lvl == 5) {
		complete = level5();
		promptlvl(complete, "jl", "hu", lvl);
	}
	else if (lvl == 6) {
		complete = level6();
		complete = gatenot(complete);
		promptlvl(complete, "hu", "si", lvl);
	}
	else if (lvl == 7) {
		complete = level7();
		complete = gatenot(complete);
		promptlvl(complete, "si", "ok", lvl);
	}
	else if (lvl == 8) {
		complete = level8();
		complete = gatenot(complete);
		promptlvl(complete, "ok", "wt", lvl);
	}
	else if (lvl == 9) {
		complete = level9();
		promptlvl(complete, "wt", "no", lvl);
	}
	else if (lvl == 10) {
		complete = level10();
		complete = gatenot(complete);
		promptlvl(complete, "no", "9a", lvl);
	}
	else if (lvl == 11) {
		complete = level11();
		promptlvl(complete, "9a", "jk", lvl);
	}
	else if (lvl == 12) {
		cout
			<< "Level not complete\n";
	}
	else if (lvl == 13) {
		cout
			<< "SLOW THE FUCK DOWN"
			<< endl;
	}
	else if (lvl == 14) {
		cout
			<< "STTOTPPPP"
			<< endl;
	}
	else if (lvl == 15) {
		cout
			<< "AAAAAAAAAH"
			<< endl;
	}
	else if (lvl == 16) {
		cout
			<< "AHGHAHGHHGA"
			<< endl;
	}
	else if (lvl == 17) {
		cout
			<< "get"
			<< endl;
	}
	else if (lvl == 18) {
		cout
			<< "the"
			<< endl;
	}
	else if (lvl == 19) {
		cout
			<< "fuck"
			<< endl;
	}
	else if (lvl == 20) {
		cout
			<< "out"
			<< endl;
	}// :-)
	return 0;
}
int level1()						// mostly levels from here on ooouuut
{
	int iA = 0, iB = 0, oA = 0;
	cout
		<< "Level 1"
		<< endl 
		<< "Introduction to the basics of simple concepts."
		<< endl 
		<< "+ Goal: Positive output."
		<< endl 
		<< "- AND Gates: Give positive output with two positive inputs"
		<< endl 
		<< "- I: Input / O: Output"
		<< endl 
		<< "- 1: Postive / 0: Negative" 
		<< endl 
		<< "[  I I  ]"
		<< endl 
		<< "[  AND  ]"
		<< endl 
		<< "[   O   ]"
		<< endl;
	cout
		<< "There are two inputs (I) and one output (O)"
		<< endl
		<< "You have to give the inputs (I) to get the required output (O) [+]"
		<< endl
		<< "Try it out below."
		<< endl
		<< endl;
	iA = gateinput("A");
	iB = gateinput("B");
	oA = gateand(iA, iB);
	cout 
		<< "Output: " 
		<< oA 
		<< endl;
	return oA;
}
int level2()
{
	int iA = 0, iB = 0, oA = 0;
	int iiA;
	cout
		<< "Level 2"
		<< endl 
		<< "Do OR, do NOT."
		<< endl 
		<< "+ Goal: Negative output."
		<< endl 
		<< "- OR Gates: Gives positive output with any positive input"
		<< endl 
		<< "- NOT Gates: Gives positive output with negative input, only accepts one input."
		<< endl 
		<< "- I: Input / O: Output"
		<< endl 
		<< "- 1: Postive / 0: Negative"
		<< endl 
		<< "[  I I  ]"
		<< endl 
		<< "[  OR   ]"
		<< endl 
		<< "[  NOT  ]"
		<< endl 
		<< "[   O   ]"
		<< endl;
	cout
		<< "Different gates interact differently to inputs"
		<< endl
		<< endl
		<< "For example, the OR gate takes in two inputs, and sends"
		<< endl
		<< "a positive (1) output with any positive input"
		<< endl
		<< endl
		<< "While a NOT gate takes in a single input, and sends a"
		<< endl
		<< "positive (1) output with a negative (0) input"
		<< endl
		<< endl;
	iA = gateinput("A");
	iB = gateinput("B");
	iiA = gateor(iA, iB);
	oA = gatenot(iiA);
	cout 
		<< "Output: " 
		<< oA 
		<< endl;
	return oA;
}
int level3()
{
	int iA = 0, iB = 0, oA = 0;
	int iiA, iiB;
	cout
		<< "Level 3"
		<< endl 
		<< "Dynamic Duo"
		<< endl 
		<< "+ Goal: Positive output."
		<< endl 
		<< "- AND Gates: Give positive output with two positive inputs"
		<< endl 
		<< "- OR Gates: Gives positive output with any positive input"
		<< endl 
		<< "[ I I   I I ]"
		<< endl 
		<< "[ AND   OR  ]"
		<< endl 
		<< "[    AND    ]"
		<< endl 
		<< "[     O     ]"
		<< endl;
	cout
		<< "When a gate gives an output, it either goes into the level output (O)"
		<< endl
		<< "or it goes into the next gate on the layer below"
		<< endl
		<< endl
		<< "For example, the AND and OR gates will give two outputs, which will"
		<< endl
		<< "put into the AND gate below them, and used at it's input."
		<< endl
		<< endl;
	iA = gateinput("A");
	iB = gateinput("B");
	iiA = gateand(iA, iB);
	iA = gateinput("C");
	iB = gateinput("D");
	iiB = gateor(iA, iB);
	oA = gateand(iiA, iiB);
	cout 
		<< "Output: " 
		<< oA 
		<< endl;
	return oA;
}
int level4()
{
	int iA = 0, iB = 0, oA = 0;
	int iiA, iiB;
	cout
		<< "Level 4"
		<< endl
		<< "NOR vs. OR"
		<< endl
		<< "+ Goal: Positive output."
		<< endl 
		<< "- AND Gates: Give positive output with two positive inputs"
		<< endl 
		<< "- NOR Gates: Gives positive output with no positive input"
		<< endl 
		<< "- OR Gates: Gives positive output with any positive input"
		<< endl
		<< "[ I I   I I ]"
		<< endl
		<< "[ NOR   OR  ]"
		<< endl
		<< "[    AND    ]"
		<< endl
		<< "[     O     ]"
		<< endl;
	cout
		<< "Have fun! :)"
		<< endl;
	iA = gateinput("A");
	iB = gateinput("B");
	iiA = gatenor(iA, iB);
	iA = gateinput("C");
	iB = gateinput("D");
	iiB = gateor(iA, iB);
	oA = gateand(iiA, iiB);
	cout 
		<< "Output: " 
		<< oA 
		<< endl;
	return oA;
}
int level5()
{
	int iA = 0, iB = 0, oA = 0;
	int iiA, iiB;
	cout
		<< "Level 5"
		<< endl
		<< "AND NAND too."
		<< endl
		<< "+ Goal: Positive output."
		<< endl 
		<< "- AND Gates: Give positive output with two positive inputs"
		<< endl 
		<< "- NAND Gates: Gives positive output with any negative input"
		<< endl 
		<< "- NOR Gates: Gives positive output with no positive input"
		<< endl
		<< "[ I I   I I ]"
		<< endl
		<< "[ AND   NAND]"
		<< endl
		<< "[    NOR    ]"
		<< endl
		<< "[     O     ]"
		<< endl;
	iA = gateinput("A");
	iB = gateinput("B");
	iiA = gateand(iA, iB);
	iA = gateinput("C");
	iB = gateinput("D");
	iiB = gatenand(iA, iB);
	oA = gatenor(iiA, iiB);
	cout 
		<< "Output: " 
		<< oA 
		<< endl;
	return oA;
}
int level6()
{
	int iA = 0, iB = 0, oA = 0;
	int iiA, iiB, iiC;
	int iiD, iiE;
	int iiF;
	cout
		<< "Level 6"
		<< endl 
		<< "NOT AND NOR OR"
		<< endl 
		<< "+ Goal: Negative output."
		<< endl 
		<< "- AND Gates: Give positive output with two positive inputs"
		<< endl 
		<< "- NOR Gates: Gives positive output with no positive input"
		<< endl 
		<< "- OR Gates: Gives positive output with any positive input"
		<< endl 
		<< "- NOT Gates: Gives positive output with negative input, only accepts one input."
		<< endl 
		<< "[ I I  I I   I I ]"
		<< endl 
		<< "[ AND  NOR   OR  ]"
		<< endl 
		<< "[   AND     NOT  ]"
		<< endl
		<< "[       AND      ]"
		<< endl
		<< "[       NOT      ]"
		<< endl 
		<< "[        O       ]"
		<< endl;
	iA = gateinput("A");
	iB = gateinput("B");
	iiA = gateand(iA, iB);
	iA = gateinput("C");
	iB = gateinput("D");
	iiB = gatenor(iA, iB);
	iA = gateinput("E");
	iB = gateinput("F");
	iiC = gateor(iA, iB);
	iiD = gateand(iiA, iiB);
	iiE = gatenot(iiC);
	iiF = gateand(iiD, iiE);
	oA = gatenot(iiF);
	cout 
		<< "Output: " 
		<< oA 
		<< endl;
	return oA;
}
int level7()
{
	int iA = 0, iB = 0, oA = 0;
	int iiA, iiB, iiC;
	cout
		<< "Level 7"
		<< endl
		<< "Transport"
		<< endl
		<< "+ Goal: Negative output"
		<< endl
		<< "- AND Gates: Give positive output with two positive inputs"
		<< endl
		<< "- NOT Gates: Gives positive output with negative input, only accepts one input."
		<< endl
		<< "- BUFF Gates: Gives positive output with positive input, only accepts one input."
		<< endl
		<< "[ I I   I I ]"
		<< endl
		<< "[ AND   AND ]"
		<< endl
		<< "[ NOT   BUFF]"
		<< endl
		<< "[ BUFF  BUFF]"
		<< endl
		<< "[ NOT   NOT ]"
		<< endl
		<< "[ BUFF  NOT ]"
		<< endl
		<< "[ BUFF  BUFF]"
		<< endl
		<< "[ BUFF  NOT ]"
		<< endl
		<< "[    AND    ]"
		<< endl
		<< "[    NOT    ]"
		<< endl
		<< "[     O     ]"
		<< endl;
	iA = gateinput("A");
	iB = gateinput("B");
	iiA = gateand(iA, iB);
	iA = gateinput("C");
	iB = gateinput("D");
	iiB = gateand(iA, iB);
	iiA = gatenot(iiA);  iiB = gatebuff(iiB);
	iiA = gatebuff(iiA); iiB = gatebuff(iiB);
	iiA = gatenot(iiA);  iiB = gatenot(iiB);
	iiA = gatebuff(iiA); iiB = gatenot(iiB);
	iiA = gatebuff(iiA); iiB = gatebuff(iiB);
	iiA = gatebuff(iiA); iiB = gatenot(iiB);
	iiC = gateand(iiA, iiB);
	oA = gatenot(iiC);
	cout 
		<< "Output: " 
		<< oA 
		<< endl;
	return oA;
}
int level8()
{
	int iA = 0, iB = 0, oA = 0;
	int iiA, iiB;
	cout
		<< "Level 8"
		<< endl
		<< "Exclusively Exclusive"
		<< endl
		<< "+ Goal: Negative output"
		<< endl
		<< "- AND Gates: Give positive output with two positive inputs"
		<< endl
		<< "- XOR Gates: Gives positive output when the inputs are different."
		<< endl
		<< "- XNOR Gates: Gives positive output when the inputs are the same."
		<< endl
		<< "[ I I   I I ]"
		<< endl
		<< "[ XOR   XNOR]"
		<< endl
		<< "[    AND    ]"
		<< endl
		<< "[     O     ]"
		<< endl;
	iA = gateinput("A");
	iB = gateinput("B");
	iiA = gatexor(iA, iB);
	iA = gateinput("C");
	iB = gateinput("D");
	iiB = gatexnor(iA, iB);
	oA = gateand(iiA, iiB);
	cout 
		<< "Output: " 
		<< oA 
		<< endl;
	return oA;
}
int level9()
{
	int iA = 0, iB = 0, oA = 0;
	int iiA, iiB;
	cout
		<< "Level 9"
		<< endl
		<< "V.I.P. Only"
		<< endl
		<< "+ Goal: Positive output"
		<< endl
		<< "- XOR Gates: Gives positive output when the inputs are different."
		<< endl
		<< "- XNOR Gates: Gives positive output when the inputs are the same."
		<< endl
		<< "[ I I   I I ]"
		<< endl
		<< "[ XNOR  XNOR]"
		<< endl
		<< "[    XOR    ]"
		<< endl
		<< "[     O     ]"
		<< endl;
	iA = gateinput("A");
	iB = gateinput("B");
	iiA = gatexnor(iA, iB);
	iA = gateinput("C");
	iB = gateinput("D");
	iiB = gatexnor(iA, iB);
	oA = gatexor(iiA, iiB);
	cout 
		<< "Output: " 
		<< oA 
		<< endl;
	return oA;
}
int level10()
{
	int iA = 0, iB = 0, iC = 0, iD = 0, iE = 0, iF = 0, iG = 0, iH = 0, oA = 0;
	int iiA, iiB, iiC, iiD;
	int iiE, iiF;
	int iiG;
	cout
		<< "Level 10"
		<< endl
		<< "The Second Level"
		<< endl
		<< "+ Goal: Negative output"
		<< endl
		<< "- XOR Gates: Gives positive output when the inputs are different."
		<< endl
		<< "- AND Gates: Give positive output with two positive inputs"
		<< endl
		<< "- XNOR Gates: Gives positive output when the inputs are the same."
		<< endl 
		<< "- NOR Gates: Gives positive output with no positive input"
		<< endl
		<< "- NOT Gates: Gives positive output with negative input, only accepts one input."
		<< endl
		<< "[ I I   I I   I I   I I ]"
		<< endl
		<< "[ XOR   XNOR  NOR   XOR ]"
		<< endl
		<< "[     AND       NOR     ]"
		<< endl
		<< "[          XOR          ]"
		<< endl
		<< "[          NOT          ]"
		<< endl
		<< "[           O           ]"
		<< endl;
	iA = gateinput("A");
	iB = gateinput("B");
	iiA = gatexor(iA, iB);
	iC = gateinput("C");
	iD = gateinput("D");
	iiB = gatexnor(iC, iD);
	iE = gateinput("E");
	iF = gateinput("F");
	iiC = gatexnor(iE, iF);
	iG = gateinput("G");
	iH = gateinput("H");
	iiD = gatexnor(iG, iH);
	iiE = gateand(iiA, iiB);
	iiF = gatenor(iiC, iiD);
	iiG = gatexor(iiE, iiF);
	oA = gatenot(iiG);
	cout 
		<< "Output: " 
		<< oA 
		<< endl;
	return oA;
}
int level11()
{
	int iA = 0, iB = 0, iC = 0, iD = 0, iE = 0, iF = 0, iG = 0, iH = 0, oA = 0;
	int iiA, iiB, iiC, iiD, iiE, iiF;
	cout
		<< "Level 11"
		<< endl 
		<< "'You just did that to confuse me'"
		<< endl 
		<< "+ Goal: Positive output."
		<< endl 
		<< "- AND Gates: Give positive output with two positive inputs"
		<< endl 
		<< "- NOR Gates: Gives positive output with no positive input"
		<< endl
		<< "- NOT Gates: Gives positive output with negative input, only accepts one input."
		<< endl
		<< "- XOR Gates: Gives positive output when the inputs are different."
		<< endl
		<< "- BUFF Gates: Gives positive output with positive input, only accepts one input."
		<< endl 
		<< "- NAND Gates: Gives positive output with any negative input"
		<< endl 
		<< "[ I I   I I   I I   I I ]"
		<< endl 
		<< "[ NAND  XOR   NOR   XOR ]"
		<< endl 
		<< "[ BUFF  BUFF  NOT   BUFF]"
		<< endl
		<< "[     AND        XOR    ]"
		<< endl
		<< "[     NOT        BUFF   ]"
		<< endl
		<< "[          AND          ]"
		<< endl
		<< "[           O           ]"
		<< endl;
	iA = gateinput("A");
	iB = gateinput("B");
	iC = gateinput("C");
	iD = gateinput("D");
	iE = gateinput("E");
	iF = gateinput("F");
	iG = gateinput("G");
	iH = gateinput("H");
	iiB = gatexor(iC, iD);
	iiC = gatenor(iE, iF);
	iiD = gatexor(iG, iH);
	iiC = gatenot(iiC);
	iiE = gateand(iiA, iiB);
	iiF = gatexor(iiC, iiD);
	iiE = gatenot(iiE);
	oA = gateand(iiE, iiF);
	cout 
		<< "Output: " 
		<< oA 
		<< endl;
	return oA;
}
int level12()
{
	
}
int gatebuff(int iA)					// Buffer gate, 1 input(s), 1 output(s)
{
	return iA;							// Return input
}
int gatenot(int iA)						// NOT gate, 1 input(s), 1 output(s)
{
	return iA == 0 ? 1 : 0;				// If input is 0, return 1, if not, return 0
}
int gateand(int iA, int iB)				// AND gate, 2 input(s), 1 output(s)
{
	return iA && iB == 1 ? 1 : 0;		// If both inputs are 1, return 1, if not, return 0
}
int gatenand(int iA, int iB)			// NAND gate, 2 input(s), 1 output(s)
{
	return iA || iB == 0 ? 1 : 0;		// If any inputs are 0, return 1, if not, return 0
}
int gateor(int iA, int iB)				// OR gate, 2 input(s), 1 output(s)
{
	return iA || iB == 1 ? 1 : 0;		// If any inputs are 1, return 1, if not, return 0
}
int gatenor(int iA, int iB)				// NOR gate, 2 input(s), 1 output(s)
{
	return iA && iB == 0 ? 1 : 0;		// If both inputs are 0, return 1, if not, return 0
}
int gatexor(int iA, int iB)				// XOR gate, 2 input(s), 1 output(s)
{
	return iA != iB ? 1 : 0;			// If the inputs are different, return 1, if not, return 0
}
int gatexnor(int iA, int iB)			// XNOR gate, 2 input(s), 1 output(s)
{
	return iA == iB ? 1 : 0;			// If the inputs are identical, return 1, if not, return 0
}
int gateinput(string inp) {
	int input = 0;
	while ((cout << "Enter " << inp << ": ")
		&& !(cin >> input)) {
		cout 
			<< "A number please!";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (input > 1)
		input = 1;
	if (input < 0)
		input = 0;
	return input;
}
