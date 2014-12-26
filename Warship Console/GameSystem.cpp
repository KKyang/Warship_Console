//In this .cpp there are some function been called by other function inside this .cpp
//but not used in other .cpps
#include "stdafx.h"
#include "consola.h"
#include "fstream"
#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include "iostream"
#include "conio.h"
#include "string"
#include "iomanip"
using namespace std;

void Shipcolor(int Shiptype){                 //Change the display of the ship color
	if(Shiptype==5||Shiptype==10){            //used in main and here
		textcolor(WHITE);                     //Shiptype numbers will be explain down at playerShip part
	}
	else if(Shiptype==4||Shiptype==9){
		textcolor(GREEN);
	}
	else if(Shiptype==3||Shiptype==8){
		textcolor(YELLOW);
	}
	else if(Shiptype==2||Shiptype==7){
		textcolor(BROWN);
	}
	else if(Shiptype==1||Shiptype==6){
		textcolor(LIGHTGRAY);
	}
	cout<<"¡½";
	textcolor(BLACK);

}

void saveGame(int count, int Player[15][15], int Enemy[15][15]){
	 time_t rawtime;
	 struct tm * timeinfo;                    //use to get system time
	 string DATE;                             //save date
	 gotoxy(1,20);
	 for(int i=1;i<=(80*7);i++)               //erase the words on the main menu page
	   cout<<" ";

	 gotoxy(10,20);
	 cout<<"Saved DATA";
	 
	 ifstream openfile("warshipsaved data.dll");
	 
	 if(!openfile.fail()){
		getline(openfile, DATE);
		gotoxy(10,21);
		cout<<"   "<<DATE<<"   WARSHIP SAVED DATA";
		gotoxy(15,23);
		cout<<"Saved file exist. Do you want to overwrite?";
		
	 }
	 
	 else{
		gotoxy(10,21);
		cout<<"   EMPTY";
		gotoxy(10,23);
		cout<<"Save Game?";
	 }
	 
	 gotoxy(16,24);
	 cout<<"YES";
	 gotoxy(59,24);
	 cout<<"NO";
	 gotoxy(15,24);
	 int x=15;

	 int key=0;
	 while(key!=0xD){                         //keyboard selection
	 key = _getch();                        //use to capture the keyboard cin
	 switch(key){
		  case 0x4b:
			   x=15;
			   gotoxy(x,24);
			   break;
		  case 0x4d:
			   x=58;
			   gotoxy(x,24);
		}
	 }
	 if(x==15){
												  //if No is choose, exit savefile
	 //the function of save
	 ofstream savefile("warshipsaved data.dll");  //save file


	 time ( &rawtime );
	 timeinfo = localtime ( &rawtime );
	 savefile<<asctime (timeinfo)<<endl;  //save system time into the saved data
	 savefile<<count<<endl;                       //save round
	 for(int i=0;i<15;i++){
		for(int k=0;k<15;k++){
		savefile<<Player[i][k]<<"\t";            //save player data
		}
	  }
	 savefile<<endl;
	 for(int i=0;i<15;i++){
		  for(int k=0;k<15;k++){
			 savefile<<Enemy[i][k]<<"\t";             //save enemy data
		  }
	 }

	 gotoxy(1,20);
	 for(int i=1;i<=(80*6);i++)               //erase the words on the main menu page
		cout<<" ";
	 gotoxy(25,23);
	 cout<<"Your game is successfully saved.";
	 delay(500);
	 }

}

void loadGame(int optselect[1]){
	 string DATE;
	 gotoxy(1,20);
	 for(int i=1;i<=(80*7);i++)               //erase the words on the main menu page
	   cout<<" ";

	 gotoxy(10,20);
	 cout<<"Load DATA";

	 ifstream openfile("warshipsaved data.dll");
	 
	 if(!openfile.fail()){
		getline(openfile, DATE);
		gotoxy(10,21);
		cout<<"   "<<DATE<<"   WARSHIP SAVED DATA";
		gotoxy(15,23);
		cout<<"Saved file exist. Do you want to load the game?";  
	 }
	 gotoxy(16,24);
	 cout<<"YES";
	 gotoxy(59,24);
	 cout<<"NO";
	 gotoxy(15,24);
	 int x=15;

	 int key=0;
	 while(key!=0xD){                         //keyboard selection
	 key = _getch();                        //use to capture the keyboard cin
	 switch(key){
		  case 0x4b:
			   x=15;
			   gotoxy(x,24);
			   break;
		  case 0x4d:
			   x=58;
			   gotoxy(x,24);
		}
	 }
	 if(x==15){
		optselect[0]=2;
	 }


}

class readSaveFile{
  public:
	string PlayerName;
	int PlayerRound;
	int EnemyRound;
};

void HighScore(){
	 gotoxy(1,20);
	 for(int i=1;i<=(80*7);i++)               //erase the words on the main menu page
	   cout<<" ";

	 while(1){
	 ifstream openfile("warshipsaved HighScore.dll");


	  if(openfile.fail()){                                    //if highscore doesn't exist
		 ofstream savefile("warshipsaved HighScore.dll");    //create it
		 for(int i=1;i<=5;i++)
		   savefile<<"None"<<endl;
		 for(int i=1;i<=10;i++)
		   savefile<<16<<"\t";

		 savefile.close();
		 continue;
	  }
	  break;
	 }

	 ifstream openfile("warshipsaved HighScore.dll");

	 readSaveFile file[6];

	 for(int i=0;i<5;i++)
	  getline(openfile,file[i].PlayerName);
	 
	 for(int i=0;i<5;i++){
	  openfile>>file[i].PlayerRound;
	  openfile>>file[i].EnemyRound;
	 }

	 gotoxy(1,20);
	 cout<<"  High Score:Name      Player's Left   Enemy's Left";
	 for(int i=0;i<5;i++){
	  gotoxy(1,22+i);
	  cout<<"           "<<i+1<<"."<<setw(10)<<file[i].PlayerName<<"       "<<setw(2)<<file[i].PlayerRound<<"            "<<setw(2)<<file[i].EnemyRound;
	 }

	 int key=0;
	 while(key!=0xD){
		key = _getch();                        //if press ENTER, then go back to main menu
	 }


}

void HowToPlay(){                             //the function of how to play
	 gotoxy(1,20);
	 for(int i=1;i<=(80*7);i++)               //erase the words on the main menu page
	   cout<<" ";
	 gotoxy(10,20);
	 cout<<"How To Play: ";
	 gotoxy(10,21);
	 cout<<"   1. Choose boat with number pad and ENTER.";
	 gotoxy(10,22);
	 cout<<"   2. Use Direction Pad to move your ship or to attack.";
	 gotoxy(10,23);
	 cout<<"   3. Press SPACE for turning directions.";
	 gotoxy(10,24);
	 cout<<"   4. Press ENTER to confirm or leave this page.";
	 gotoxy(10,25);
	 cout<<"   5. Press ESC when you're attack to pause.";
	 gotoxy(10,26);
	 cout<<"   6. Load Game only appears when you saved before.";
	 gotoxy(10,27);
	 cout<<"   7. When the end of the game press ENTER to go back to main menu.";
	 int key=0;
	 while(key!=0xD){
		key = _getch();                        //if press ENTER, then go back to main menu
	 }
}

void MainWindowsystem(int optselect[1], int PressPauseCheck[1], int count, int Player[15][15], int Enemy[15][15]){
											  //The main menu selection
	 int stock=0;                             //used to check if the saved data existed
	 int checkloadDATA=0;
	 int check=0;                             //used to check if to enter the game or go back to main menu
	 int x,y;
	while(check==0){
	 gotoxy(1,20);
	 for(int i=1;i<=(80*10);i++)              //use to erase words
	   cout<<" ";
	   
	 ifstream openfile("warshipsaved data.dll");
	 
	 if(PressPauseCheck[0]==1){
	   stock=20;
	   gotoxy(50,20);
	   cout<<"CONTIUNE";
	   gotoxy(50,21);
	   cout<<"SAVE GAME";
	   if(!openfile.fail()){                     //if load file failed, the LOAD GAME won't appeared
		 gotoxy(50,22);
		 cout<<"LOAD GAME";
		 checkloadDATA=1;                      //check if there's a load data
	   }
	 }
	 else{
	  if(openfile.fail()){                     //if load file failed, the LOAD GAME won't appeared
		stock=23;
	   }
	  else{
		stock=22;
		gotoxy(50,22);
		cout<<"LOAD GAME";
		checkloadDATA=1;
	   }
	 }

	 gotoxy(50,23);
	 cout<<"Game Start";
	 gotoxy(50,24);
	 cout<<"High Score";
	 gotoxy(50,25);
	 cout<<"How To Play";
	 gotoxy(50,26);
	 cout<<"Exit Game";
	 gotoxy(49,stock);                        //the variable is used to check the position of the cursor
	 x=49;
	 y=stock;
	 int key=0;
	 while(key!=0xD){                         //keyboard selection
		key = _getch();                        //use to capture the keyboard cin

		switch(key)
		{
		case 0x48:
				if((y-1)<stock)               //if moved out of range then move back
				   y=stock;
				else if((y-1)==22&&checkloadDATA==0)
				   y=21;
				else
				   y=y-1;
				gotoxy(x,y);
				break;
		case 0x50:
				if((y+1)>26)
				  y=26;
				else if((y+1)==22&&checkloadDATA==0)
				   y=23;
				else
				  y=y+1;
				gotoxy(x,y);
				break;
		}
	}
	if(y==20){
	 optselect[0]=0;
	 check=1;
	}
	else if(y==21){
	 saveGame(count, Player, Enemy);
			  }
	else if(y==22){                                //position pointing to selection
	 loadGame(optselect);
	 if(optselect[0]==2)
	   check=1;                               //changing check to 1 makes jumping
	}                                         //out of the loop
	
	else if(y==23){
	 optselect[0]=1;
	 check=1;
	}
	else if(y==24){
	  HighScore();
	}
	else if(y==25){
	  HowToPlay();
	}
	else if(y==26){
	 optselect[0]=3;
	 check=1;
	}
  }
}

void setdefault(int Player[15][15], int Enemy[15][15]){
	 for(int i=0;i<15;i++)
	   for(int j=0;j<15;j++){
			   Player[i][j]=0;
			   Enemy[i][j]=0;
			   }
	 }
	 
int check(int Enemy[15][15], int ShipChoose, int j,int k, int SwitchSelect){
	int ReturnValue=1;                        //Use to check if the enemy ship crush
	switch(SwitchSelect){                     //into the same position
	 case 1:
	   for(int i=1;i<ShipChoose;i++)     
		 if(Enemy[j][k+i]>1)
			 ReturnValue=0;                   //if ship is detected
	   break;                                 //a false value is return.
	case 2:
	   for(int i=1;i<ShipChoose;i++)
		 if(Enemy[j+i][k]>1)
			 ReturnValue=0;
	   break;
	case 3:
	   for(int i=1;i<ShipChoose;i++)
		 if(Enemy[j-i][k]>1)
			 ReturnValue=0;
	   break;
	 case 4:
	   for(int i=1;i<ShipChoose;i++)
		 if(Enemy[j][k-i]>1)
			 ReturnValue=0;
	   break;
	}

	return ReturnValue;
}

int random(){                                //use to random the opportunity
	int ReturnValue=rand()%2;                //of direction below

	return ReturnValue;
}


void putShip(int Enemy[15][15]){             //enemy's putShip
	srand(time(NULL));
	int EnemyShip[6]={0,5,4,3,2,2};          //five type of enemy's ship
	int used[6]={1,0,0,0,0,0};               //check if the ship is used
	int ShipChoose;                          //choose ship type

	for(int i=0;i<5;i++){                    //choose ship type
		ShipChoose=0;                        //set ShipChoose to 0
		ShipChoose=rand()%5+1;               //random ShipChoose

		int j=0;                             //define j,k position
		int k=0;
		j=rand()%15;                         //random j,k
		k=rand()%15;
		if(used[ShipChoose]||Enemy[j][k]){   //if the ship is chose i--
			i--;
			continue;
		}
		  used[ShipChoose]=1;                //if choose used++
		  Enemy[j][k]=10;                    //set the ship's head to 10
	   
		   
			if(((k+(EnemyShip[ShipChoose]-1))<15)&&check(Enemy,EnemyShip[ShipChoose],j,k,1)&&random())
			  for(int count=0;count<EnemyShip[ShipChoose];count++) //if range and random are all true
				Enemy[j][k+count]=ShipChoose;                      //put the ship inside
			else if((j+(EnemyShip[ShipChoose]-1))<15&&check(Enemy,EnemyShip[ShipChoose],j,k,2)&&random())
			  for(int count=0;count<EnemyShip[ShipChoose];count++) 
				Enemy[j+count][k]=ShipChoose;
			else if((j-(EnemyShip[ShipChoose]-1))>-1&&check(Enemy,EnemyShip[ShipChoose],j,k,3)&&random())
			  for(int count=0;count<EnemyShip[ShipChoose];count++)
				Enemy[j-count][k]=ShipChoose;
			else if((k-(EnemyShip[ShipChoose]-1))>-1&&check(Enemy,EnemyShip[ShipChoose],j,k,4))
			  for(int count=0;count<EnemyShip[ShipChoose];count++)
				Enemy[j][k-count]=ShipChoose;
			else{
				used[ShipChoose]=0;
				Enemy[j][k]=0;
				i--;
			}
			//above are the four directions down, right, left, up, last one is used for if above condition
			//is all false, then i-- and also cancel the used ship and set ship head position to 0
		 
	   }
		

}

int playercheck(int x, int y, int shiplength, int Player[15][15], char direction){
	int ReturnValue=1;          //check if the player's ship crush togehter
	switch(direction){          //same as enemy's logical
	 case 'R':                  //right direction
	   for(int i=0;i<shiplength;i++)
		 if(Player[(x-9)/2+i][y-10]>0)
			 ReturnValue=0;
	   break;
	 case 'D':                  //down direction
	   for(int i=0;i<shiplength;i++)
		 if(Player[(x-9)/2][y-10+i]>0)
			 ReturnValue=0;
	   break;
	 case 'L':                  //left direction
	   for(int i=0;i<shiplength;i++)
		 if(Player[(x-9)/2-i][y-10]>0)
			 ReturnValue=0;
	   break;
	 case 'U':                  //up direction
	   for(int i=0;i<shiplength;i++)
		 if(Player[(x-9)/2][y-10-i]>0)
			 ReturnValue=0;
	   break;
	}
	return ReturnValue;
}

void Display(int x, int y, int shiplength, int Player[15][15], char direction, int Rangecheckint[1]){
									 //instant display the preplace ship

			if(direction=='R'){      //right direction cout
				  gotoxy(9,26);
				  cout<<"                 ";  //used for erase

				  if((x+(shiplength)*2)<=39&&playercheck(x, y, shiplength, Player, direction)){
					gotoxy(x,y);
					for(int i=0;i<shiplength;i++){
					  textcolor(LIGHTRED);
					  cout<<"¡½";
					  textcolor(BLACK);  //cout the ship
					  }
					Rangecheckint[0]=1;  //if the ship isn't out of range, then change check to true
				  }
				  else{
					gotoxy(9,26);
					textcolor(LIGHTRED);
					cout<<"OUT OF RANGE!!"; //if out of range change check to false
					Rangecheckint[0]=0;
					textcolor(BLACK);
					}

				 for(int i=0;i<15;i++)      //cout the placed ship again due to the erase of the instant display
				   for(int j=0;j<15;j++)
					 if(Player[i][j]){
					   gotoxy(9+2*i,10+j);
					   Shipcolor(Player[i][j]);
					   }
					gotoxy(x,y);            //go back to the cursor position
				}
			  else if(direction=='D'){      //right direction cout
				  gotoxy(9,26);
				  cout<<"                 ";

				  if((y+shiplength)<=25&&playercheck(x, y, shiplength, Player, direction)){
					for(int i=0;i<shiplength;i++){
					  gotoxy(x,y+i);
					  textcolor(LIGHTRED);
					  cout<<"¡½";
					  textcolor(BLACK);
					}
					Rangecheckint[0]=1;
					}
				  else{
					gotoxy(9,26);
					textcolor(LIGHTRED);
					cout<<"OUT OF RANGE!!";
					Rangecheckint[0]=0;
					textcolor(BLACK);
					}

				 for(int i=0;i<15;i++)
				   for(int j=0;j<15;j++)
					 if(Player[i][j]){
					   gotoxy(9+2*i,10+j);
					   Shipcolor(Player[i][j]);
					   }
					gotoxy(x,y);
					}
			   else if(direction=='L'){      //right direction cout
					gotoxy(9,26);
					cout<<"                 ";

				  if((x-(shiplength)*2)>=7&&playercheck(x, y, shiplength, Player, direction)){
					for(int i=0;i<shiplength;i++){
					  gotoxy(x-(i*2),y);
					  textcolor(LIGHTRED);
					  cout<<"¡½";
					  textcolor(BLACK);
					}
					Rangecheckint[0]=1;
					}
				  else{
					gotoxy(9,26);
					textcolor(LIGHTRED);
					cout<<"OUT OF RANGE!!";
					Rangecheckint[0]=0;
					textcolor(BLACK);
					}

				 for(int i=0;i<15;i++)
				   for(int j=0;j<15;j++)
					 if(Player[i][j]){
					   gotoxy(9+2*i,10+j);
					   Shipcolor(Player[i][j]);
					   }
					gotoxy(x,y);
					}
			   else if(direction=='U'){      //right direction cout
				  gotoxy(9,26);
				  cout<<"                 ";

				  if((y-shiplength)>=9&&playercheck(x, y, shiplength, Player, direction)){
					for(int i=0;i<shiplength;i++){
					  gotoxy(x,y-i);
					  textcolor(LIGHTRED);
					  cout<<"¡½";
					  textcolor(BLACK);
					}
					Rangecheckint[0]=1;
					}
				  else{
					gotoxy(9,26);
					textcolor(LIGHTRED);
					cout<<"OUT OF RANGE!!";
					Rangecheckint[0]=0;
					textcolor(BLACK);
					}

				  for(int i=0;i<15;i++)
				   for(int j=0;j<15;j++)
					 if(Player[i][j]){
					   gotoxy(9+2*i,10+j);
					   Shipcolor(Player[i][j]);
					   }
					gotoxy(x,y);
					}
	 }

void playerShip(int Player[15][15]){      //used to place player's ship
	int PlayerShip[6]={0,5,4,3,2,2};      //player's ship type
	int used[6]={1,0,0,0,0,0};            //check if used or not
	int x,y;                              //the x,y position
	int check=0;                          //five turns of putting ship allowed
	int Rangecheckint[1]={1};             //the click for checking range or not
	char Rangecheck='N';                  //the click change to Y when the int above changed to 1
	char direction='R';                   //change the display and putting directions
	int choose=0;                         //the selection of the ship by player
	string choosecheck;                   //used for getting the players insert object
										  //avoiding invalid input
	while(check<5){                       //5 ship putting limit



	 while(used[choose]!=0){              //if ship is used, then reinsert
	  gotoxy(31,27);
	  cout<<"     ";
	  gotoxy(31,27);
	  getline(cin,choosecheck);           //use getline to avoid player pressing ENTER without input
	  choose=atoi(choosecheck.c_str());   //changing string to int
	  if(choose<1||choose>5)              //if out of range, re-enter the selection
		choose=0;
	 }
	 
	 used[choose]++;                      //if ship is chose, used++

	 Rangecheck='N';                      //set clicks to default
	 Rangecheckint[0]=1;
	 
	 gotoxy(9,10);                        //set positions to default
	 x=9;
	 y=10;
	 int key=0;
	 while(key!=0xD||Rangecheck=='N'){
		Display(x, y, PlayerShip[choose], Player, direction,Rangecheckint);
		key = _getch();                    //instant display ship

		switch(key)                       //keyboard enter
		{
		case 0x48:
				if((y-1)<10)
				   y=10;
				else
				   y=y-1;
				gotoxy(x,y);              //if out of range, move it back

				  gotoxy(9,y+1);          //erased the pre-display ship
				  for(int i=1;i<=15;i++)
				   cout<<"¡¼";
					for(int i=0;i<=14;i++){
				   gotoxy(x,10+i);
				   cout<<"¡¼";
				  }
				Display(x, y, PlayerShip[choose], Player, direction,Rangecheckint);
				break;
		case 0x50:
				if((y+1)>24)
				  y=24;
				else
				  y=y+1;
				gotoxy(x,y);
				

				  gotoxy(9,y-1);
				  for(int i=1;i<=15;i++)
				   cout<<"¡¼";
					for(int i=0;i<=14;i++){
				   gotoxy(x,10+i);
				   cout<<"¡¼";
				  }
				Display(x, y, PlayerShip[choose], Player, direction,Rangecheckint);
				break;
		case 0x4b:
				if((x-1)<9)
				  x=9;
				else
				  x=x-2;
				gotoxy(x,y);


				gotoxy(9,y);
				for(int i=1;i<=15;i++)
				  cout<<"¡¼";
				for(int i=0;i<=14;i++){
				  gotoxy(x+2,10+i);
				  cout<<"¡¼";
				}
				Display(x, y, PlayerShip[choose], Player, direction,Rangecheckint);
				break;
		case 0x4d:
				if((x+1)>37)
				  x=37;
				else
				  x=x+2;
				gotoxy(x,y);

				
				gotoxy(9,y);
				for(int i=1;i<=15;i++)
				   cout<<"¡¼";
				for(int i=0;i<=14;i++){
				   gotoxy(x-2,10+i);
				   cout<<"¡¼";
				  }
				Display(x, y, PlayerShip[choose], Player, direction,Rangecheckint);
				break;
		case 32:

				if(direction=='R')
				  direction='D';
				else if(direction=='D')
				  direction='L';
				else if(direction=='L')
				  direction='U';
				else if(direction=='U')
				  direction='R';

				gotoxy(9,y);
				for(int i=1;i<=15;i++)
				   cout<<"¡¼";
				for(int i=0;i<=14;i++){
				   gotoxy(x,10+i);
				   cout<<"¡¼";
				  }
				Display(x, y, PlayerShip[choose], Player, direction,Rangecheckint);
				break;
		}
		if(key==0xD&&Rangecheckint[0]==1){
		  Rangecheck='Y';             //if click is true then change the Rangecheck
		}                             //to jump out of the loop
	 }

				if(direction=='R')    //save the ship into the array(play map)
					for(int i=0;i<PlayerShip[choose];i++){
					 if(i==0)
					  Player[(x-9)/2+i][y-10]=choose+5;
					 else
					  Player[(x-9)/2+i][y-10]=choose;
					}
				else if(direction=='D')
					for(int i=0;i<PlayerShip[choose];i++){
					 if(i==0)
					  Player[(x-9)/2][y-10+i]=choose;
					 else
					  Player[(x-9)/2][y-10+i]=choose;
					}
				else if(direction=='L')
					for(int i=0;i<PlayerShip[choose];i++){
					 if(i==0)
					  Player[(x-9)/2-i][y-10]=choose+5;
					 else
					  Player[(x-9)/2-i][y-10]=choose;
					}
				else if(direction=='U')
					for(int i=0;i<PlayerShip[choose];i++){
					 if(i==0)
					  Player[(x-9)/2][y-10-i]=choose+5;
					 else
					  Player[(x-9)/2][y-10-i]=choose;
					}
	  check++;                           //counting add
	  for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
		   if(Player[i][j]){
			gotoxy(9+2*i,10+j);
			Shipcolor(Player[i][j]);     //display the result
	}

					   }
}

void Blood(int x,int y){                 //show life bar
  for(int i=0;i<x;i++){
	gotoxy(69-i,8);
	 textbackground(YELLOW);             //life bar
	 cout<<" ";
	 textbackground(LIGHTCYAN);
  }

   for(int i=0;i<y;i++){
	   gotoxy(10+i,8);
	   textbackground(LIGHTRED);         //life bar
	   cout<<" ";
	   textbackground(LIGHTCYAN);
   }
}

void BloodCut(int x, int y){             //renew life bar
  for(int i=0;i<(16-x);i++){
	gotoxy(54+i,8);
	 textbackground(LIGHTGRAY);          //renew by minus
	 cout<<" ";
	 textbackground(LIGHTCYAN);
  }

   for(int i=0;i<(16-y);i++){
	   gotoxy(25-i,8);
	   textbackground(LIGHTGRAY);
	   cout<<" ";
	   textbackground(LIGHTCYAN);
   }
}

void ShowLoadShip(int Player[15][15], int Enemy[15][15]){
	 for(int i=0;i<15;i++)                       //show out player location
	   for(int j=0;j<15;j++){
		  gotoxy(9+2*i,10+j);
		   if(Player[i][j]>0){
				Shipcolor(Player[i][j]);
			 }
			else if(Player[i][j]==-1){
				textcolor(LIGHTRED);
				cout<<"£A";
				}
			else if(Player[i][j]==-2){
				textcolor(LIGHTBLUE);
				cout<<"¡´";
			}
			else if(Player[i][j]==0){
				textcolor(BLACK);
				cout<<"¡¼";
			}

		   gotoxy(41+2*i,10+j);                   //only show enemy's distroyed ship and misses

			if(Enemy[i][j]==-1){
				textcolor(LIGHTRED);
				cout<<"£A";
				}
			else if(Enemy[i][j]==-2){
				textcolor(LIGHTBLUE);
				cout<<"¡´";
			}
			else if(Enemy[i][j]>=0){
				textcolor(BLACK);
				cout<<"¡¼";
			}



		  }

	 int blood[2]={0};
	 for(int i=0;i<15;i++)
	  for(int j=0;j<15;j++)
	   if(Enemy[i][j]>0)
		 blood[0]++;                              //checking how many ships are left


	 for(int i=0;i<15;i++)
	  for(int j=0;j<15;j++)
	   if(Player[i][j]>0)
		 blood[1]++;                              //checking how many ships are left

	 Blood(blood[0],blood[1]);                    //show out the left life of both player
	 BloodCut(blood[0],blood[1]);
}

void PlayerAttack(int Enemy[15][15], int PressPauseCheck[1]){
	int x,y;                             //player attack
	int PressCheck=1;                    //check if the block is used before
	 gotoxy(41,10);                      //set position to default
	 x=41;
	 y=10;
	 int key=0;
	 while(key!=0xD||PressCheck==1){     //the gate of the switch

		key = _getch();

		switch(key)
		{
		case 0x48:
				if((y-1)<10)
				   y=10;
				else
				   y=y-1;
				gotoxy(x,y);
				if(Enemy[(x-41)/2][y-10]==-1||Enemy[(x-41)/2][y-10]==-2)
					PressCheck=1;        //if the block is hit before, then ENTER is not allowed
				else
					PressCheck=0;
				break;
		case 0x50:
				if((y+1)>24)
				  y=24;
				else
				  y=y+1;
				gotoxy(x,y);
				if(Enemy[(x-41)/2][y-10]==-1||Enemy[(x-41)/2][y-10]==-2)
					PressCheck=1;
				else
					PressCheck=0;
				break;
		case 0x4b:
				if((x-1)<41)
				  x=41;
				else
				  x=x-2;
				gotoxy(x,y);
				if(Enemy[(x-41)/2][y-10]==-1||Enemy[(x-41)/2][y-10]==-2)
					PressCheck=1;
				else
					PressCheck=0;
				break;
		case 0x4d:
				if((x+1)>69)
				  x=69;
				else
				  x=x+2;
				gotoxy(x,y);
				if(Enemy[(x-41)/2][y-10]==-1||Enemy[(x-41)/2][y-10]==-2)
					PressCheck=1;
				else
					PressCheck=0;
				break;
		case 27:
				/*ofstream savefile("warshipcontinue.txt");  //save file
				savefile<<count<<endl;                       //save round
				for(int i=0;i<15;i++){
					for(int k=0;k<15;k++){
					savefile<<Player[i][k]<<"\t";            //save player data
					}
				}
				savefile<<endl;
				for(int i=0;i<15;i++){
				  for(int k=0;k<15;k++){
					savefile<<Enemy[i][k]<<"\t";             //save enemy data
				  }
				}*/
				PressPauseCheck[0]=1;
		}
		if(key==0xD){            //the gate of checking ENTER press
			if(Enemy[(x-41)/2][y-10]==-1||Enemy[(x-41)/2][y-10]==-2)
				PressCheck=1;
			else
				PressCheck=0;
		}
		else if(PressPauseCheck[0]==1)
		   break;
	 }
	 if(PressPauseCheck[0]==0){
	   if(Enemy[(x-41)/2][y-10]>0){    //if hit, cout X
		 gotoxy(x,y);
		 textcolor(LIGHTRED);
		 cout<<"£A";
		 textcolor(BLACK);
		 Enemy[(x-41)/2][y-10]=-1;
	   }
	   else{                           //else cout ¡´
		 gotoxy(x,y);
		 textcolor(LIGHTBLUE);
		 cout<<"¡´";
		 textcolor(BLACK);
		 Enemy[(x-41)/2][y-10]=-2;
	   }
	 }

}

void EnemyAI(int Player[15][15]){    //enemyAI
	int i,j;                         //set position i,j


	while(1){
	 i=rand()%15;
	 j=rand()%15;

	 if(Player[i][j]==-1||Player[i][j]==-2)
		 continue;                   //if hit before, then re-choose
	 else
		 break;
	}
 
	if(Player[i][j]>0){              //if hit, cout X
	  gotoxy(i*2+9,j+10);
	  textcolor(LIGHTRED);
	  cout<<"£A";
	  textcolor(BLACK);
	  Player[i][j]=-1;
	  }
	else{                            //else cout ¡´
	  gotoxy(i*2+9,j+10);
	  textcolor(LIGHTBLUE);
	  cout<<"¡´";
	  textcolor(BLACK);
	  Player[i][j]=-2;
	}
}


