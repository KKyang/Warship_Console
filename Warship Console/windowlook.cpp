#include "stdafx.h"
#include <iostream>
#include "consola.h"
using namespace std;

void Mainwindowlook(){                                //the main menu's display
	settitle("WARSHIP by B99611008");
	textbackground(BLACK);
	for(int i=1;i<=(80*35);i++)
	  cout<<" ";
	gotoxy(1,10);
	textcolor(LIGHTRED);

	cout<<"   ■            ■    ■      ■■■■  ■■■■  ■    ■  ■■■  ■■■■   ";
	cout<<"    ■    ■    ■    ■■     ■    ■  ■        ■    ■    ■    ■    ■   ";
	cout<<"     ■  ■■  ■    ■  ■    ■■■■  ■■■■  ■■■■    ■    ■■■■   ";
	cout<<"      ■■  ■■    ■    ■   ■  ■          ■  ■    ■    ■    ■         ";
	cout<<"       ■    ■    ■      ■  ■    ■  ■■■■  ■    ■  ■■■  ■         ";
	textcolor(WHITE);
	cout<<"                       ■■■  ■  ■  ■■■     ■■■   ■   ■  ■ ■■■";
	cout<<"                            ■    ■■■  ■■■     ■      ■■  ■■■ ■■■";
	cout<<"                            ■    ■  ■  ■■■     ■■■ ■  ■ ■  ■ ■■■";
	cout<<"                                                         ■                     ";

     }

void Welcome(){                                      //the game play display
	
	textbackground(LIGHTCYAN);
	for(int i=1;i<=(80*35);i++)
	  cout<<" ";

	gotoxy(1,1);
	textcolor(LIGHTRED);
	textbackground(GREEN);
	cout<<"   ■            ■    ■      ■■■■  ■■■■  ■    ■  ■■■  ■■■■   ";
	cout<<"    ■    ■    ■    ■■     ■    ■  ■        ■    ■    ■    ■    ■   ";
	cout<<"     ■  ■■  ■    ■  ■    ■■■■  ■■■■  ■■■■    ■    ■■■■   ";
	cout<<"      ■■  ■■    ■    ■   ■  ■          ■  ■    ■    ■    ■         ";
	cout<<"       ■    ■    ■      ■  ■    ■  ■■■■  ■    ■  ■■■  ■         ";
	
    textbackground(BLACK);                        //the life bar of both player
	gotoxy(9,7);
	cout<<"                  ";
	gotoxy(53,7);
	cout<<"                  ";
    gotoxy(9,8);
	cout<<"                  ";
	gotoxy(53,8);
	cout<<"                  ";
	gotoxy(9,9); 
	cout<<"                  ";
	gotoxy(53,9);
	cout<<"                  ";
     
	 textbackground(LIGHTCYAN);
	 textcolor(BLACK);
	 gotoxy(9,27);                                //the selection in the game play
	 cout<<"Choose your ship type: ";
	 gotoxy(9,28);
	 cout<<"1. 航空母艦(五格)";
	 gotoxy(9,29);
	 cout<<"2. 巡洋艦(四格)";
	 gotoxy(9,30);
	 cout<<"3. 驅逐艦(三格)";
	 gotoxy(9,31);
	 cout<<"4. 砲艇(二格)";
	 gotoxy(9,32);
	 cout<<"5. 潛水艇(兩格)";
	 gotoxy(9,33);
	 cout<<"每個船艦只能選一次";


	


	
}
void Block(){                                     //the display of two map blocks
	int count=0;
	gotoxy(9,10);
	for(int i=1;i<=225;i++){		
	  cout<<"□";
	  if(i%15==0){                                //15 blocks a row
		  count++;
		  gotoxy(9,10+count);
	  }
	}

	count=0;

	gotoxy(41,10);
	for(int i=1;i<=225;i++){	
	  cout<<"□";
	  if(i%15==0){
		  count++;
		  gotoxy(41,10+count);
	  }
	}
    //two player position starts at(9,10),(41,10), all language in this program is written
	//based on this logical
}
