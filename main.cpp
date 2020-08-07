#include <iostream>
#include "UIKit.h"
#include "Menu.h"
#include "Game.h"

using namespace std;

//Displays How to play the game
void Help() {

	system("CLS");
	UIKit::frame(60, 5, 125, 25, 13);
	UIKit::color(14);
	UIKit::gotoXY(80, 8);
	cout << "--------HOW TO PLAY--------" << endl;
	UIKit::color(11);
	UIKit::gotoXY(80, 10);
	cout << "K        -> MOVE LEFT" << endl;
	UIKit::gotoXY(80, 12);
	cout << "L        -> MOVE RIGHT" << endl;
	UIKit::gotoXY(80, 14);
	cout << "SPACEBAR -> SHOOT ETs" << endl;
	UIKit::gotoXY(80, 16);
	cout << "H        -> PAUSE THE GAME" << endl;
	UIKit::gotoXY(80, 18);
	cout << "E        -> EXIT GAME" << endl;
	UIKit::gotoXY(76, 20);
	cout <<"**** KILL ALL ENEMIES TO WIN ****" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	system("pause");
	return;
}

//Displays the details about the project
void About() {

	system("CLS");
	UIKit::frame(60, 5, 130, 25, 13);
	UIKit::color(14);
	UIKit::gotoXY(80, 10);
	cout << "------------ABOUT------------" << endl;
	UIKit::color(11);
	UIKit::gotoXY(80, 12);
	cout << "PROJECT SUBMITTED BY:" << endl;
	UIKit::gotoXY(80, 14);
	cout << "-> SCIANA ELISHA QUADROS - 3045" << endl;
	UIKit::gotoXY(80, 16);
	cout << "-> KARAMPREET KAUR SIDHU - 3384" << endl;
	
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	system("pause");
	return;
}
//Display Space Invaders on the screen
void screen()
{
	system("CLS");
	
	UIKit::color(11);
	UIKit::setWindowDimensions(0, 0, 210, 45);
	UIKit::frame(25,10, 175, 30, 20);
	UIKit::color(11);
	UIKit::gotoXY(55, 15);

	cout<<  "                                                                                                                       " << endl;
	cout << "\t\t\t\t       _______  _______  _______  _______  _______  \t  ___   __    _  __   __  _______  ______   _______  ______    _______   " << endl;
	cout << "\t\t\t\t      |       ||       ||   _   ||       ||       | \t |   | |  |  | ||  | |  ||   _   ||      | |       ||    _ |  |       |  " << endl;
	cout << "\t\t\t\t      |  _____||    _  ||  |_|  ||       ||    ___| \t |   | |   |_| ||  |_|  ||  |_|  ||  _    ||    ___||   | ||  |  _____|  " << endl;
	cout << "\t\t\t\t      | |_____ |   |_| ||       ||       ||   |___  \t |   | |       ||       ||       || | |   ||   |___ |   |_||_ | |_____   " << endl;
	cout << "\t\t\t\t      |_____  ||    ___||       ||      _||    ___| \t |   | |  _    ||       ||       || |_|   ||    ___||    __  ||_____  |  " << endl;
	cout << "\t\t\t\t       _____| ||   |    |   _   ||     |_ |   |___  \t |   | | | |   | |     | |   _   ||       ||   |___ |   |  | | _____| |  " << endl;
	cout << "\t\t\t\t      |_______||___|    |__| |__||_______||_______| \t |___| |_|  |__|  |___|  |__| |__||______| |_______||___|  |_||_______|  " << endl;
	cout << "                                                                                                                       " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	

}

int main() 
{
	
	int Selection;
	screen();
	// Create main menu, 3 items, top left corner on line 5, column 8;
	// see Menu.h
	system("pause");
	system("CLS");

	
	
	UIKit::color(13);
	string Choices[] = { "EXIT","HELP","PLAY" ,"ABOUT"};
	Menu Main_Menu("WELCOME TO SPACE INVADERS", Choices, 4, 15, 90);

	while(true) {
		system("CLS");
		Selection = Main_Menu.displayMenu();
		
		switch (Selection) {
		case 1:
			// end program
			exit(0);
			

		case 2:
			// display help
			Help();
			break;

		case 4:
			//display about
			About();
			break;

		case 3:
			// play the game
			Game new_game;

			int game_result;
			game_result = new_game.Play();

			// ### TODO Better display after game
			system("CLS");
			UIKit::frame(60, 5, 130, 25, 20);
			UIKit::color(14);
			UIKit::gotoXY(80, 10);
			cout<<"--------GAME RESULT--------" << endl;
			UIKit::color(13);
			UIKit::gotoXY(80, 12);
			cout << "YOUR SCORE = " << new_game.getScore() << endl;
			UIKit::gotoXY(80, 14);
			cout << "YOUR LEVEL = " << new_game.getLevel() << endl;

			UIKit::gotoXY(80, 16);
			switch (game_result) {
			case 0:
				cout << "GAME OVER ! :( " << endl;
				break;
			case 1:
				cout << "YOU WIN ! :)" << endl;
				break;
			case 2:
				cout << "YOU QUIT ! " << endl;
				break;
			}
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			system("pause");
			break;
		}
	}
	
	return(0);
}