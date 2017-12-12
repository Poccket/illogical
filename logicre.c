// logicre.c
// (c) www.seamuspotter.com or whatever
// version 0.6.0
// Logic-based puzzle game.
// Might get turned into something bigger within the future.
// If a makefile was included, you can run it to compile this into an executable file as long as
// you have GCC 4.8 or higher installed currently.
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h>
#include <limits>
using namespace std;
int gatebuff(int iA);												//Logic gates-
int gatenot(int iA);												//Explained at actual function
int gateor(int iA, int iB);
int gatenor(int iA, int iB);
int gateand(int iA, int iB);
int gatenand(int iA, int iB);
int gatexor(int iA, int iB);
int gatexnor(int iA, int iB);
int codecheck(string lvlnum, int lvl);								//Checks if input is a level code, and if so, pushes to lvlcode()
int lvlcode(int lvlcode, int lvl, string grocode);					//Prompt to see if user is sure about the level code they entered previously
int codenoprompt(string lvlnum, int lvl);							//codecheck(), but it skips through lvlcode(), used for savedata
int promptlvl(int status, string curcode, string nexcode, int lvl);	//NEEDS CLEANING- Prompt for checking the users status at the end of the level.
int level1();														//Levels-
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
int startgame(int lvl);												//Picks which level to run
int menu(int lvl, int complete);									//Main menu prompt
int gateinput(string inp);											//Takes input for logic gates from levels
void savedelete();													//Deletes save file with prompt

int main(int argc, char* argv[])	// argc = number of arguments sent to script, argv[] = all the arguments in the array
{
	int lvl = 1, complete = 0;		// Define these here to avoid messing things up if we define them in menu()
	string version = "0.6";			// Only here cause I got annoyed picking it out of the cout function below.
	cout<<"Illogical "<<version<<"\nmade in C++, compiled in G++\n";// Basic startup info
	if(argc>2){cout<<"---------------------------------------\n"	// If there are more than 2 arguments then the game lets you know and kindly quits
		<<"Ran into an error: Too many arguments in command\n"
		<<"---------------------------------------\n";
		return 0;}
	else if(argc==2){codecheck(argv[1],lvl); return 0;}				// If there are exactly 2, then we can assume the player entered the first argument as a level code and push it to codecheck()
	ifstream my_file("lgcsav");										// Open a stream in the directory to "lgcsav" (the savedata file)
	if (my_file.good())												// Check if it's good, then tell the script to put us at a certain level using codenoprompt() and the level code in the file
	{ofstream savefile;				
	string argg; getline(my_file, argg);		
	codenoprompt( argg, lvl );}
	else {ofstream savefile;										// If it doesn't exist, then create it and put the first level's level code inside the file.		
	savefile.open ("lgcsav"); savefile<<"b8"; savefile.close();						
	menu(lvl, complete);}											// Go to the menu.
	return 0;
}
int menu(int lvl, int complete)
{
	cout<<"---------------------------------------\n";
	int input;
	string lvlnum = "";
	cout<<"0. Help\n"
		<<"1. Play\n"
		<<"2. Code\n"
		<<"3. Reset\n"
		<<"4. Exit\n";
	while ((cout << "> ") && !(cin >> input)){
		cout<<"---------------------------------------\n"
			<<"Please select from the menu\n"
			<<"---------------------------------------\n" 
			<<"0. Help\n"
			<<"1. Play\n"
			<<"2. Code\n"
			<<"3. Reset\n"
			<<"4. Exit\n";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
	cout<<"---------------------------------------\n";
	switch (input)
	{
		case 0:cout<<"Illogical is a puzzle game based around logic gates and en\ntering positive or negative inputs to recieve certain outp\nuts required to complete the level\n";
		menu(lvl, complete); break;
		case 1: startgame(lvl); break;
		case 2: cout<<"> "; cin >> lvlnum;
		codecheck(lvlnum, lvl);
		break;
		case 3:savedelete();
		return 0;
		break;
		case 4: return 0;
		break;
		default:cout<<"Please select from the menu\n";
		menu(lvl, complete);
		break;
	}
	return 0;
}
void savedelete()
{
	string prompt="";
	cout<<"Delete savedata file?\n> ";
	cin>>prompt;
	while((prompt != "y") && (prompt != "n")){cout<<"Bad input.\n> ";cin>>prompt;}
		 if(prompt=="y"){remove("lgcsav"); return;}
	else if(prompt=="n"){cout<<"Cancelled delete\n"; return;}
	else {cout<<"Ran into an error: 'prompt' changed after while loop\n"; return;}
	return;
}
int codecheck(string lvlnum, int lvl)	
{											
		 if (lvlnum == "b8") {lvlcode( 1, lvl, lvlnum);}
	else if (lvlnum == "mz") {lvlcode( 2, lvl, lvlnum);}
	else if (lvlnum == "hx") {lvlcode( 3, lvl, lvlnum);}
	else if (lvlnum == "aq") {lvlcode( 4, lvl, lvlnum);}
	else if (lvlnum == "jl") {lvlcode( 5, lvl, lvlnum);}
	else if (lvlnum == "hu") {lvlcode( 6, lvl, lvlnum);}
	else if (lvlnum == "si") {lvlcode( 7, lvl, lvlnum);}
	else if (lvlnum == "ok") {lvlcode( 8, lvl, lvlnum);}
	else if (lvlnum == "wt") {lvlcode( 9, lvl, lvlnum);}
	else if (lvlnum == "no") {lvlcode(10, lvl, lvlnum);}
	else if (lvlnum == "9a") {lvlcode(11, lvl, lvlnum);}
	else if (lvlnum == "jk") {lvlcode(12, lvl, lvlnum);}
	else if (lvlnum == "pi") {lvlcode(13, lvl, lvlnum);}
	else if (lvlnum == "re") {lvlcode(14, lvl, lvlnum);}
	else if (lvlnum == "za") {lvlcode(15, lvl, lvlnum);}
	else if (lvlnum == "qs") {lvlcode(16, lvl, lvlnum);}
	else if (lvlnum == "or") {lvlcode(17, lvl, lvlnum);}
	else if (lvlnum == "fg") {lvlcode(18, lvl, lvlnum);}
	else if (lvlnum == "1z") {lvlcode(19, lvl, lvlnum);}
	else if (lvlnum == "6q") {lvlcode(20, lvl, lvlnum);}
	else {cout<<"Ran into an error: level code is invalid.\n";}
	return 0;
}
int codenoprompt(string lvlnum, int lvl)
{
		 if (lvlnum == "b8") {menu( 1, 0);}
	else if (lvlnum == "mz") {menu( 2, 0);}
	else if (lvlnum == "hx") {menu( 3, 0);}
	else if (lvlnum == "aq") {menu( 4, 0);}
	else if (lvlnum == "jl") {menu( 5, 0);}
	else if (lvlnum == "hu") {menu( 6, 0);}
	else if (lvlnum == "si") {menu( 7, 0);}
	else if (lvlnum == "ok") {menu( 8, 0);}
	else if (lvlnum == "wt") {menu( 9, 0);}
	else if (lvlnum == "no") {menu(10, 0);}
	else if (lvlnum == "9a") {menu(11, 0);}
	else if (lvlnum == "jk") {menu(12, 0);}
	else if (lvlnum == "pi") {menu(13, 0);}
	else if (lvlnum == "re") {menu(14, 0);}
	else if (lvlnum == "za") {menu(15, 0);}
	else if (lvlnum == "qs") {menu(16, 0);}
	else if (lvlnum == "or") {menu(17, 0);}
	else if (lvlnum == "fg") {menu(18, 0);}
	else if (lvlnum == "1z") {menu(19, 0);}
	else if (lvlnum == "6q") {menu(20, 0);}
	else {cout<<"Your save file contains bad data.\n";
		  savedelete();}
	return 0;
}
int lvlcode(int lvlcode, int lvl, string grocode)
{
	string prompt="";
	cout<<"---------------------------------------\n"
		<<"This will put you from level "<<lvl<<" to level "<<lvlcode<<".\n"
		<<"Are you sure you want to do this? [y/n]\n> "; cin>>prompt;
	while((prompt != "y") && (prompt != "n")){cout<<"Bad input.\n> ";cin>>prompt;}
		 if(prompt=="y"){ofstream savefile; savefile.open("lgcsav"); savefile<<grocode; savefile.close(); cout<<"Done.\n"; menu(lvlcode, 0);}
	else if(prompt == "n") {cout<<"Cancelled.\n"; menu(lvl, 0);}
	else {cout<<"Ran into an error: 'prompt' changed after while loop";}
	return 0;
}
int promptlvl(int status, string curcode, string nexcode, int lvl)
{
	string prompt = "";				
	if (status == 1) {						
			ofstream savefile;			
			savefile.open ("lgcsav");		
			savefile << nexcode;				
			savefile.close();					
			lvl++;							
			cout
				<< "Level complete."		
				<< endl
				<< "Next level? [y/n]"		
				<< endl
				<< "user: ";				
			cin
				>> prompt;					
			if ( prompt == "y" ) {			
				startgame(lvl);				
			}
			else if ( prompt == "n" ) {		
				cout
					<< "level code: "		
					<< nexcode
					<< endl;
				menu(lvl, 1);			
			}
			else {							
				cout					
					<< "Please enter 'y' or 'n'"
					<< endl;			
				promptlvl(status, curcode, nexcode, lvl);
			}
		}
		else if (status == 0) {				
			cout
				<< "Level failed."			
				<< endl
				<< "Try again? [y/n]"		
				<< endl
				<< "user: ";				
			cin
				>> prompt;					
			if ( prompt == "y" ) {			
				startgame(lvl);				
			}	
			else if ( prompt == "n" ) {		
				cout
					<< "level code: "		
					<< curcode
					<< endl;			
				menu(lvl, 1);			
			}
			else {							
				cout					
					<< "Please enter 'y' or 'n'"
					<< endl;			
				promptlvl(status, curcode, nexcode, lvl);
			}
		}
}
int startgame(int lvl)						
{
	int complete;							
	string prompt="";				
	if(lvl==0){lvl = 1;}										
		 if(lvl== 1){complete=level1(); 			promptlvl(complete, "b8", "mz", lvl);}
	else if(lvl== 2){complete=gatenot(level2());	promptlvl(complete, "mz", "hx", lvl);}
	else if(lvl== 3){complete=level3();				promptlvl(complete, "hx", "aq", lvl);}
	else if(lvl== 4){complete=level4();				promptlvl(complete, "aq", "jl", lvl);}
	else if(lvl== 5){complete=level5();				promptlvl(complete, "jl", "hu", lvl);}
	else if(lvl== 6){complete=gatenot(level6());	promptlvl(complete, "hu", "si", lvl);}
	else if(lvl== 7){complete=gatenot(level7());	promptlvl(complete, "si", "ok", lvl);}
	else if(lvl== 8){complete=gatenot(level8());	promptlvl(complete, "ok", "wt", lvl);}
	else if(lvl== 9){complete=level9();				promptlvl(complete, "wt", "no", lvl);}
	else if(lvl==10){complete=gatenot(level10());	promptlvl(complete, "no", "9a", lvl);}
	else if(lvl==11){complete=level11();			promptlvl(complete, "9a", "jk", lvl);}
	else if(lvl==12){/*complete=level12();			promptlvl(complete, "jk", "pi", lvl);}*/}
	else if(lvl==13){/*complete=level13();			promptlvl(complete, "pi", "re", lvl);}*/}
	else if(lvl==14){/*complete=level14();			promptlvl(complete, "re", "za", lvl);}*/}
	else if(lvl==15){/*complete=level15();			promptlvl(complete, "za", "qs", lvl);}*/}
	else if(lvl==16){/*complete=level16();			promptlvl(complete, "qs", "or", lvl);}*/}
	else if(lvl==17){/*complete=level17();			promptlvl(complete, "or", "fg", lvl);}*/}
	else if(lvl==18){/*complete=level18();			promptlvl(complete, "fg", "1z", lvl);}*/}
	else if(lvl==19){/*complete=level19();			promptlvl(complete, "1z", "6q", lvl);}*/}
	else if(lvl==20){/*complete=level20();			promptlvl(complete, "6q", "??", lvl);}*/}
	else if(lvl==21){/*youwin();*/}
	else			{cout<<"Ran into an error: 'lvl' current status ("<<lvl<<") is not accounted for!\n";}
	return 0;
}
int level1()						
{
	int iA = 0, iB = 0, oA = 0;
	cout
		<< "Level 1"<< endl 
		<< "Introduction to the basics of simple concepts."<< endl 
		<< "+ Goal: Positive output."<< endl 
		<< "- AND Gates: Give positive output with two positive inputs"<< endl 
		<< "- I: Input / O: Output"<< endl 
		<< "- 1: Postive / 0: Negative"<< endl 
		<< "[  I I  ]"<< endl 
		<< "[  AND  ]"<< endl 
		<< "[   O   ]"<< endl
		<< endl
		<< "There are two inputs (I) and one output (O)"<< endl
		<< "You have to give the inputs (I) to get the required output (O) [+]"<< endl
		<< "Try it out below."<< endl
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
		<< "Level 2"<< endl 
		<< "Do OR, do NOT."<< endl 
		<< "+ Goal: Negative output."<< endl 
		<< "- OR Gates: Gives positive output with any positive input"<< endl 
		<< "- NOT Gates: Gives positive output with negative input, only accepts one input."<< endl 
		<< "- I: Input / O: Output"<< endl 
		<< "- 1: Postive / 0: Negative"<< endl 
		<< "[  I I  ]"<< endl 
		<< "[  OR   ]"<< endl 
		<< "[  NOT  ]"<< endl 
		<< "[   O   ]"<< endl
		<< endl
		<< "Different gates interact differently to inputs"<< endl
		<< "For example, the OR gate takes in two inputs, and sends"<< endl
		<< "a positive (1) output with any positive input,"<< endl
		<< "while a NOT gate takes in a single input, and sends a"<< endl
		<< "positive (1) output with a negative (0) input"<< endl
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
		<< "Level 3"<< endl 
		<< "Dynamic Duo"<< endl 
		<< "+ Goal: Positive output."<< endl 
		<< "- AND Gates: Give positive output with two positive inputs"<< endl 
		<< "- OR Gates: Gives positive output with any positive input"<< endl 
		<< "[ I I   I I ]"<< endl 
		<< "[ AND   OR  ]"<< endl 
		<< "[    AND    ]"<< endl 
		<< "[     O     ]"<< endl
		<< endl
		<< "When a gate gives an output, it either goes into the level output (O)"<< endl
		<< "or it goes into the next gate on the layer below"<< endl
		<< endl
		<< "For example, the AND and OR gates will give two outputs, which will"<< endl
		<< "put into the AND gate below them, and used at it's input."<< endl
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
		<< "Level 4"<< endl
		<< "NOR vs. OR"<< endl
		<< "+ Goal: Positive output."<< endl 
		<< "- AND Gates: Give positive output with two positive inputs"<< endl 
		<< "- NOR Gates: Gives positive output with no positive input"<< endl 
		<< "- OR Gates: Gives positive output with any positive input"<< endl
		<< "[ I I   I I ]"<< endl
		<< "[ NOR   OR  ]"<< endl
		<< "[    AND    ]"<< endl
		<< "[     O     ]"<< endl
		<< endl
		<< "Have fun! :)"<< endl;
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
		<< "Level 5"<< endl
		<< "AND NAND too."<< endl
		<< "+ Goal: Positive output."<< endl 
		<< "- AND Gates: Give positive output with two positive inputs"<< endl 
		<< "- NAND Gates: Gives positive output with any negative input"<< endl 
		<< "- NOR Gates: Gives positive output with no positive input"<< endl
		<< "[ I I   I I ]"<< endl
		<< "[ AND   NAND]"<< endl
		<< "[    NOR    ]"<< endl
		<< "[     O     ]"<< endl;
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
		<< "Level 6"<< endl 
		<< "NOT AND NOR OR"<< endl 
		<< "+ Goal: Negative output."<< endl 
		<< "- AND Gates: Give positive output with two positive inputs"<< endl 
		<< "- NOR Gates: Gives positive output with no positive input"<< endl 
		<< "- OR Gates: Gives positive output with any positive input"<< endl 
		<< "- NOT Gates: Gives positive output with negative input, only accepts one input."<< endl 
		<< "[ I I  I I   I I ]"<< endl 
		<< "[ AND  NOR   OR  ]"<< endl 
		<< "[   AND     NOT  ]"<< endl
		<< "[       AND      ]"<< endl
		<< "[       NOT      ]"<< endl 
		<< "[        O       ]"<< endl;
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
		<< "Level 7"<< endl
		<< "Transport"<< endl
		<< "+ Goal: Negative output"<< endl
		<< "- AND Gates: Give positive output with two positive inputs"<< endl
		<< "- NOT Gates: Gives positive output with negative input, only accepts one input."<< endl
		<< "- BUFF Gates: Gives positive output with positive input, only accepts one input."<< endl
		<< "[ I I   I I ]"<< endl
		<< "[ AND   AND ]"<< endl
		<< "[ NOT   BUFF]"<< endl
		<< "[ BUFF  BUFF]"<< endl
		<< "[ NOT   NOT ]"<< endl
		<< "[ BUFF  NOT ]"<< endl
		<< "[ BUFF  BUFF]"<< endl
		<< "[ BUFF  NOT ]"<< endl
		<< "[    AND    ]"<< endl
		<< "[    NOT    ]"<< endl
		<< "[     O     ]"<< endl;
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
		<< "Level 8"<< endl
		<< "Exclusively Exclusive"<< endl
		<< "+ Goal: Negative output"<< endl
		<< "- AND Gates: Give positive output with two positive inputs"<< endl
		<< "- XOR Gates: Gives positive output when the inputs are different."<< endl
		<< "- XNOR Gates: Gives positive output when the inputs are the same."<< endl
		<< "[ I I   I I ]"<< endl
		<< "[ XOR   XNOR]"<< endl
		<< "[    AND    ]"<< endl
		<< "[     O     ]"<< endl;
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
		<< "Level 9"<< endl
		<< "V.I.P. Only"<< endl
		<< "+ Goal: Positive output"<< endl
		<< "- XOR Gates: Gives positive output when the inputs are different."<< endl
		<< "- XNOR Gates: Gives positive output when the inputs are the same."<< endl
		<< "[ I I   I I ]"<< endl
		<< "[ XNOR  XNOR]"<< endl
		<< "[    XOR    ]"<< endl
		<< "[     O     ]"<< endl;
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
		<< "Level 10"<< endl
		<< "The Second Level"<< endl
		<< "+ Goal: Negative output"<< endl
		<< "- XOR Gates: Gives positive output when the inputs are different."<< endl
		<< "- AND Gates: Give positive output with two positive inputs"<< endl
		<< "- XNOR Gates: Gives positive output when the inputs are the same."<< endl 
		<< "- NOR Gates: Gives positive output with no positive input"<< endl
		<< "- NOT Gates: Gives positive output with negative input, only accepts one input."<< endl
		<< "[ I I   I I   I I   I I ]"<< endl
		<< "[ XOR   XNOR  NOR   XOR ]"<< endl
		<< "[     AND       NOR     ]"<< endl
		<< "[          XOR          ]"<< endl
		<< "[          NOT          ]"<< endl
		<< "[           O           ]"<< endl;
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
		<< "Level 11"<< endl 
		<< "'You just did that to confuse me'"<< endl 
		<< "+ Goal: Positive output."<< endl 
		<< "- AND Gates: Give positive output with two positive inputs"<< endl 
		<< "- NOR Gates: Gives positive output with no positive input"<< endl
		<< "- NOT Gates: Gives positive output with negative input, only accepts one input."<< endl
		<< "- XOR Gates: Gives positive output when the inputs are different."<< endl
		<< "- BUFF Gates: Gives positive output with positive input, only accepts one input."<< endl 
		<< "- NAND Gates: Gives positive output with any negative input"<< endl 
		<< "[ I I   I I   I I   I I ]"<< endl 
		<< "[ NAND  XOR   NOR   XOR ]"<< endl 
		<< "[ BUFF  BUFF  NOT   BUFF]"<< endl
		<< "[     AND        XOR    ]"<< endl
		<< "[     NOT        BUFF   ]"<< endl
		<< "[          AND          ]"<< endl
		<< "[           O           ]"<< endl;
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
int gatebuff(int iA)										// Buffer gate, 1 input(s), 1 output(s)
{
	return iA;												// Return input
}
int gatenot(int iA)											// NOT gate, 1 input(s), 1 output(s)
{
	return iA == 0 ? 1 : 0;									// If input is 0, return 1, if not, return 0
}
int gateand(int iA, int iB)									// AND gate, 2 input(s), 1 output(s)
{
	return iA & iB ? 1 : 0;									// If both inputs are 1, return 1, if not, return 0
}
int gatenand(int iA, int iB)								// NAND gate, 2 input(s), 1 output(s)
{
	return iA & iB ? 0 : 1;									// If any inputs are 0, return 1, if not, return 0
}
int gateor(int iA, int iB)									// OR gate, 2 input(s), 1 output(s)
{
	return iA | iB ? 1 : 0;									// If any inputs are 1, return 1, if not, return 0
}
int gatenor(int iA, int iB)									// NOR gate, 2 input(s), 1 output(s)
{
	return iA | iB ? 0 : 1;									// If both inputs are 0, return 1, if not, return 0
}
int gatexor(int iA, int iB)									// XOR gate, 2 input(s), 1 output(s)
{
	return iA != iB ? 1 : 0;								// If the inputs are different, return 1, if not, return 0
}
int gatexnor(int iA, int iB)								// XNOR gate, 2 input(s), 1 output(s)
{
	return iA == iB ? 1 : 0;								// If the inputs are identical, return 1, if not, return 0
}
int gateinput(string inp) {									// Grabs input
	int input = 0;											// 	Create the integer $input
	while ((cout << "Enter " << inp << ": ")				// 	while ( print "Enter $inp: "
		&& !(cin >> input)) {								// 	and not taking input into $input ) do
		cout 												// 		print
			<< "A number please!";							// 		"A number please!"
		cin.clear();										// 		clear input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// 		ignore input until newline
	}
	if (input > 1)											//	if $input is bigger than 1
		input = 1;											//		set $input to 1
	if (input < 0)											//	if $input is smaller than 0
		input = 0;											//		set $input to 0
	return input;											//	return $input to parent
}
