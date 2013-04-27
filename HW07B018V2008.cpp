/*******************************************************/
/*PROGRAMER  : ¶À´­¤å                                  */
/*DATE       : 2011-01-05                              */
/*FILENAME   : HW07B018                                */
/*DESCRIPTION: WarShip the game                        */
/*******************************************************/

#include <iostream>
#include <fstream>
#include "stdafx.h"
#include "GameSystem.h"
#include "iostream"
#include "fstream"
#include "windowlook.h"
#include <windows.h>
#include "consola.h"
#include "iomanip"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string"
#include "time.h"
using namespace std;

class readSaveFile{
  public:
    string PlayerName;
	int PlayerRound;
	int EnemyRound;
};


int main()
{
  setsizexy(80,35);
  int Player[15][15]={0};   //Player Game Map
  int Enemy[15][15]={0};    //Enemy Game Map
  int check[2]={15};        //Check the left ship of both player
  char Win='E';             //The gate of checking who wins the game, setting E to default.
  int PressPauseCheck[1]={0};//if PressPauseCheck changed to 1 during the game will go to main menu
  int count=60;             //Counting the lefting rounds
  string Date;
  string HighScoreName;

  while(1){                 //The while is the gate of keeping the game to start over

   int optselect[1]={0};    //used to check the decision of a player from the main menu

   Mainwindowlook();        //the main menu look
   MainWindowsystem(optselect, PressPauseCheck, count, Player, Enemy); //main menu selection

   PressPauseCheck[0]=0;
   
  if(optselect[0]!=3){          //option 3 is the key of exit
    Welcome();                  //the game display
  
   if(optselect[0]==0){         //continue command
     /*ifstream openfile("warshipcontinue.txt"); //Loading saving files
     openfile>>count;                            //get round number
	 for(int i=0;i<15;i++)                       //get player ship location
		 for(int j=0;j<15;j++)
	      openfile>>Player[i][j];

	 for(int i=0;i<15;i++)                       //get enemy ship location
		 for(int j=0;j<15;j++)
           openfile>>Enemy[i][j];*/

     ShowLoadShip(Player ,Enemy);
   }
   
   else if(optselect[0]==1){         //If player press Game Start will come here
    count=60;
    setdefault(Player, Enemy);  //set both player's map to default
    Block();                    //cout the two block map
	Blood(16,16);               //cout the life bar
    putShip(Enemy);             //put the enemy's ship
    playerShip(Player);         //put the player's ship


    }

 

    else if(optselect[0]==2){   //If player press load game will go here
     ifstream openfile("warshipsaved data.dll"); //Loading saving files
     getline(openfile, Date);
     openfile>>count;                            //get round number
	 for(int i=0;i<15;i++)                       //get player ship location
		 for(int j=0;j<15;j++)
	      openfile>>Player[i][j];

	 for(int i=0;i<15;i++)                       //get enemy ship location
		 for(int j=0;j<15;j++)
           openfile>>Enemy[i][j];

     ShowLoadShip(Player ,Enemy);
     }
  
   while(count>0){                                //if round reach 0, the game ends
   
    gotoxy(37,9);
    cout<<"ROUND: "<<setw(2)<<count;              //show round on the screen
    PlayerAttack(Enemy,PressPauseCheck);             //function of player attack
    
    if(PressPauseCheck[0]==1)                     //if ESC is pressed, jump out of the loop
      break;

    check[0]=0;                                   //set check left ship to default
    for(int i=0;i<15;i++)
     for(int j=0;j<15;j++)
       if(Enemy[i][j]>0)
         check[0]++;                              //check left ship



    if(check[0]==0){
     Win='P';
     break;
    }                                             //if no ship left, the game ends
   
    EnemyAI(Player);                              //fucntion of enemy attack
    check[1]=0;                                   //set check left ship to default

    for(int i=0;i<15;i++)
     for(int j=0;j<15;j++)
       if(Player[i][j]>0)
         check[1]++;                              //check left ship

    BloodCut(check[0],check[1]);                  //show out the left ship life bar

    if(check[1]==0){
     Win='E';
     break;
    }                                             //if no ship left, the game ends
   
    count--;
   }
   
   if(PressPauseCheck[0]==1)
     continue;

    gotoxy(37,9);
    cout<<"ROUND: "<<setw(2)<<count;              //show no round left after the game

   if(Win=='P'){
	  gotoxy(32,29);
	  cout<<"YOU WIN!!";
   }                             
   else if(Win=='E'){
	  for(int i=0;i<15;i++)
		   for(int j=0;j<15;j++)
	         if(Enemy[i][j]>0){
				 gotoxy(41+2*i,10+j);
	             Shipcolor(Enemy[i][j]);
			 }                                    //as the rule, if the player didn't win, enemy did.
	gotoxy(32,29);
	  cout<<"Compuer wins!";
   }
   
   gotoxy(54,30);
   cout<<"Please Enter your Name: ";
   gotoxy(55,31);
   getline(cin,HighScoreName);



//the function of highscore
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


	  file[5].PlayerName=HighScoreName;
	  file[5].PlayerRound=check[0];
	  file[5].EnemyRound=check[1];


      ofstream savefile("warshipsaved HighScore.dll");  //save file

      readSaveFile temp;



	  for(int i=0;i<6;i++)                              //exchange place
		  for(int j=0;j<5;j++){
			  if(file[j].EnemyRound>file[j+1].EnemyRound||file[j].PlayerName=="None"){
				  temp=file[j];
				  file[j]=file[j+1];
				  file[j+1]=temp;
			  }
			  else if(file[j].EnemyRound==file[j+1].EnemyRound&&file[j].PlayerRound<file[j+1].PlayerRound){
				  temp=file[j];
				  file[j]=file[j+1];
				  file[j+1]=temp;
			  }
		  }

	  for(int i=0;i<5;i++){
          savefile<<file[i].PlayerName<<endl;
	  }

	  for(int i=0;i<5;i++){
	      savefile<<file[i].PlayerRound<<"\t"<<file[i].EnemyRound<<"\t";
	  }

  /*The High Score txt file acquired!! if lost, create a form like this
    None
	None
	None
	None
	None
	0	16	0	16	0	16	0	16	0	16
	and the function can be used*/
		  

 }
 if(optselect[0]==3)
	 break;                                       //the option select with 3 goes here and break the while
                                                  //loop then return 0
}
 

  return 0;
}



