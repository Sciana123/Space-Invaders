#include "Game.h"
#include "UIKit.h"
#include <conio.h>

//### TODO FUNCTIONS ***************************************
//-----------------------------------------------------
void Game::Ship_Laser_Create() 
{
	int x = My_Ship.coord.X;
	int y = My_Ship.coord.Y-1;
	for (int i = 0; i < Nb_ShipLasers; i++)
	{
		if (Ship_Lasers[i]->isAlive == false)
		{
			Ship_Lasers[i]->restart(x,y);
			return;
		}
	}
	Ship_Lasers[Nb_ShipLasers] = new Laser_Ship(x,y);
	Nb_ShipLasers++;
}

//-----------------------------------------------------
void Game::Enemy_Lasers_Move_All()
{

	for (int i = 0; i < Nb_EnemyLasers; i++)
	{
		Enemy_Lasers[i]->move();
	}

}
//-----------------------------------------------------
bool Game::Check_Ship_Killed() {
	
	for (int i = 0; i < Nb_EnemyLasers; i++)
	{
		if ((Enemy_Lasers[i]->coord.X == My_Ship.coord.X) && (Enemy_Lasers[i]->coord.Y == My_Ship.coord.Y))
		{
			return true;
		}

	}
	return false;
}

//-------------------------------------------------------
void Game::Ship_Lasers_Move_All() 
{
	for (int i = 0; i < Nb_ShipLasers; i++)
	{
		if (Ship_Lasers[i]->isAlive == true)
		{
			Ship_Lasers[i]->move();
		}
	}

}

//-------------------------------------------------------
void Game::Create_Enemy_Laser(int x, int y) 
{
	for (int i = 0; i < Nb_EnemyLasers; i++)
	{
		if (Enemy_Lasers[i]->isAlive==false)
		{
			Enemy_Lasers[i]->restart(x, y);
			return;
		}
	}
	Enemy_Lasers[Nb_EnemyLasers] = new Laser_Enemies(x, y);
	Nb_EnemyLasers++;
}

//-------------------------------------------------------
void Game::ETs_Move_All() {
	//To move ET
	for (int i = 0; i < Nb_ETs; i++)
	{
		if (ET_List[i]->isAlive == true)
		{
			ET_List[i]->move();
			
		}
	}
}

//-------------------------------------------------------
void Game::Check_ETs_Killed()
{
	for (int i = 0; i < Nb_ShipLasers; i++)
	{
		for (int j = 0; j < Nb_ETs; j++)
		{
 			if ((Ship_Lasers[i]->coord.X == ET_List[j]->coord.X) && (Ship_Lasers[i]->coord.Y == ET_List[j]->coord.Y) && ET_List[j]->isAlive)
			{
				score = score + ET_List[j]->kill();
				if (score %500==0)
				{
					level++;
					
				}

			}
		}

	}

	
}



void Game::Check_Monsters_Killed()
{
	for (int i = 0; i < Nb_ShipLasers; i++)
	{
		for (int j = 0; j < Nb_Monsters; j++)
		{
			if ((Ship_Lasers[i]->coord.X == Monster_List[j]->coord.X) && (Ship_Lasers[i]->coord.Y == Monster_List[j]->coord.Y ) && Monster_List[j]->isAlive)
			{
				score = score + Monster_List[j]->kill();


			}
		}

	}


}
//-------------------------------------------------------

void Game::Monsters_Create()
{
	clock_t t;
	t = clock() - last_Monster_time;
	if ((((float)t) / CLOCKS_PER_SEC) > Monster_Period)
	{
		last_Monster_time = clock();
		for (int i = 0; i < Nb_Monsters; i++)
		{
			if (Monster_List[i]->isAlive == false)
			{
				Monster_List[i]->isAlive = true;
				return;
			}
		}

		Monster_List[Nb_Monsters] = new Monsters;
		Nb_Monsters++;
	}
}
//-------------------------------------------------------
void Game::Enemies_Create() {
	clock_t t;

	t = clock() - last_ET_time;
	if ((((float)t) / CLOCKS_PER_SEC) > ET_Period)
	{
		last_ET_time = clock();
		for (int i = 0; i < Nb_ETs; i++) 
		{
			if (ET_List[i]->isAlive == false) 
			{
				ET_List[i]->isAlive = true;
				return;
			}
		}
		ET_List[Nb_ETs] = new Enemy_Fast;
		Nb_ETs++;
	}
}
//-------------------------------------------------------
int Game::Monsters_Get_Total_Alive()
{
	int count = 0;
	for (int i = 0; i < Nb_Monsters; i++)
	{
		if (Monster_List[i]->isAlive)
		{
			count++;
		}

	}
	return count;
	// none were ever created, so don't return 0
}

//-------------------------------------------------------
int Game::Enemies_Get_Total_Alive()
{
	int count = 0;
	for (int i = 0; i < Nb_ETs; i++)
	{
		if (ET_List[i]->isAlive)
		{
			count++;
		}
	
	}
	return count;
	// none were ever created, so don't return 0
}
//-------------------------------------------------------
bool Game::Monsters_Check_All_Killed()
{
	if (Monsters_Get_Total_Alive() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//-------------------------------------------------------
bool Game::Enemies_Check_All_Killed()
{
	if (Enemies_Get_Total_Alive() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//-------------------------------------------------------
void Game::Monsters_Move_All()
{
	//To move Monster
	for (int i = 0; i < Nb_Monsters; i++)
	{
		if (Monster_List[i]->isAlive == true)
		{
			Monster_List[i]->move();

		}
	}

}


//-------------------------------------------------------
void Game::Create_Monster_Laser(int x, int y)
{
	for (int i = 0; i < Nb_MonsterLasers; i++)
	{
		if (MLasers[i]->isAlive == false)
		{
			MLasers[i]->restart(x, y);
			return;
		}
	}
	MLasers[Nb_MonsterLasers] = new Monster_Lasers(x, y);
	Nb_MonsterLasers++;
}

//------------------------------------------------------
void Game::Monster_Lasers_Move_All()
{
	for (int i = 0; i < Nb_MonsterLasers; i++)
	{
		MLasers[i]->move();
	}
}

//*****************************************************************8
// Constructor --------------------------------------------------
Game::Game()
{
	// initialize game variables
	score = 0;
	level = 1;
	Nb_ShipLasers = 0;
	Nb_EnemyLasers = 0;
	Nb_MonsterLasers = 0;
	Nb_ETs = 0;
	Nb_Monsters = 0;
	ET_Period = 3;
	Monster_Period = 8;// seconds
}

// destructor --------------------------------------
Game::~Game()
{
	// delete the ETs Ennemy_Fast  --------------------------
	for (int i = 1; i <= Nb_ETs; i++) {
		delete ET_List[i - 1];
	}

	// delete the ship lasers --------------------------
	for (int i = 1; i <= Nb_ShipLasers; i++) {
		delete Ship_Lasers[i - 1];
	}

	// delete the enemy lasers --------------------------
	for (int i = 1; i <= Nb_EnemyLasers; i++) {
		delete Enemy_Lasers[i - 1];
	}

	// delete the Monsters --------------------------
	for (int i = 1; i <= Nb_Monsters; i++) {
		delete Monster_List[i - 1];
	}

	

	// delete the monster lasers --------------------------
	for (int i = 1; i <= Nb_MonsterLasers; i++) {
		delete MLasers[i - 1];
	}
}

int Game::getScore() {
	return score;
}

int Game::getLevel() {
	return level;
}

// ---------------------------------------------------------------
// Play() function starts and ends the game
// return: 0=>Game Over, 1=>You win, 2=>You Quit
// type e to quit/exit game
// --------------------------------------------------------------
int Game::Play() {

	char Key_Pressed; // key pressed by player on keyboard
	clock_t t; //Timer
	
	//----------------------------------------------------
	// set window dimension 100 columns, 42 lines
	system("CLS");
	UIKit::setWindowDimensions(0, 0, 210, 45);
	//UIKit::setWindowDimensions(0, 0, 100, 42);

	// left game frame with ship etc... 
	// the game field is 40 columns X 40 lines
	// so make the frame around 41 columns, 43 lines, color 15
	UIKit::frame(0, 0, 41, 42, 15);

	// right frame for level display, color 11
	UIKit::frame(49, 4, 70, 6, 11);

	// right frame for score display, color 11
	UIKit::frame(49, 6, 70, 8, 11);

	// show the ship
	My_Ship.show();

	

	// create at least 1 ET (Enemy_Fast), those move from left to right
	ET_List[0] = new Enemy_Fast;
	Nb_ETs = 1;
	Create_Enemy_Laser(ET_List[0]->coord.X, ET_List[0]->coord.Y + 1);
	last_ET_time = clock();// time when the last enemy was created
	last_laser_time = last_ET_time;

	
	
	

	

	Game_Paused = false;

	// MASTER GAME LOOP ---------------------------------------------
	while (true) {

		Sleep(60); // slow down the game loop

		//Read keyboard input -----------------------
		if (_kbhit()) {
			Key_Pressed = _getch();
		}
		else {
			Key_Pressed = 0;
		}

		if (Key_Pressed == 'h') {
			// pause the game
			Game_Paused = true;
			continue; // skip the rest and restart from top of while loop
		}
		else if (Key_Pressed == 0 and Game_Paused) {
			// no key pressed, stay paused
			continue; // skip the rest and restart from top of while loop
		}
		else {
			// key was pressed, resume game
			Game_Paused = false;
		}

		switch (Key_Pressed) {
		case 'e':
			return(2);// User quit the game before the end

		case 32:
			// spacebar ASCII code = 32
			// Create new ship lasers
			// ### TODO
			Ship_Laser_Create();
			break;

		case 'k':
		case 'l':
			// Move ship ---------------------------------
			My_Ship.move(Key_Pressed);
			
			break;
		}
		// end of switch ------------------------------------------


		// move the enemy lasers ----------------------------
		// ### TODO
		Enemy_Lasers_Move_All();
		

		// check if ship killed by enemy fire ---------------
		// ### TODO
		if (Check_Ship_Killed())
		{
			return(0);
		}// game over

		// move the ship lasers -----------------------------
		// ### TODO
		Ship_Lasers_Move_All();

		// move the ETs (Enemy_Fast) ------------------------
		// ### TODO
		ETs_Move_All();
		

		
		// check ETs killed ---------------------------------
		// ### TODO

		Check_ETs_Killed();
		

		// Count how many enemies are alive
		// stop game if 15 enemies alive (as per problem requirement)
		// ### TODO
		if (Enemies_Get_Total_Alive() >= 15)
		{
			return(0); // Game Over
		}
		

		// Check if all enemies were killed
		// End game or change level
		// ### TODO
		if (Enemies_Check_All_Killed() && Monsters_Check_All_Killed())
		{
			
				return(1); // you win
			
			
		}

		
		// periodically create more ETs  ---------------------
		// ### TODO 
		Enemies_Create();

		//Periodically to ET shoots
		t = clock() - last_laser_time;
		if ((((float)t) / CLOCKS_PER_SEC) > ET_Period)
		{
			last_laser_time = clock();
			for (int i = 0; i < Nb_ETs; i++)
			{
				if (ET_List[i]->isAlive)
				{
					Create_Enemy_Laser(ET_List[i]->coord.X, ET_List[i]->coord.Y + 1);
				}
			}
		}


		

		if (level > 1)
		{
			Monsters_Create();
		}
		
		Monster_Lasers_Move_All();

		if (Monsters_Get_Total_Alive() >= 15)
		{
			return(0); // Game Over
		}
		Check_Monsters_Killed();
		Monsters_Move_All();
		
		

		// Update game info in the right frame ---------------
		UIKit::color(Game_Info_Color);

		// level 
		UIKit::gotoXY(50, 5); // go in level box
		std::cout << "LEVEL    : " << level;

		// score
		UIKit::gotoXY(50, 7); // go in score box
		std::cout << "SCORE    : " << score;

		

		
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
	system("pause");

}


