/*
Author: Jesus Cardenas
Date: 4/18/2020
Class: COSC-1437
Sensei: Dr_T
*/

#include "classes.h" 
#include <iostream>

using namespace std; 




 //A void function to instantiate and control scoreboard data 
void scoreboardControls()
{
  Scoreboard s; //instantiate the the scoreboard object s
  Team tOneMain; //team Object that will become a member of scoreboard S
  Team tTwoMain; //team Object that will become a member of scoreboard S
  char decision = '\0';
  int newScore = 0; 
  string newName = ""; 
  string orange = "\x1b[33;1m"; //Orange
  string red = "\x1b[91;1m"; //red 
  string reset = "\x1b[0m";
  s.setTeam1(tOneMain); // placed update Team1 object in s
  s.setTeam1(tTwoMain); // placed update Team2 object in s

system ("clear");
cout <<orange<< "\t\t\tWelcome to a new experience\n\n\n"<<reset;

sleep(3);

cout << "Who is the"<<orange<<" HOME"<<reset<<" team? > ";
cin >> newName; 
tOneMain.setName(newName);      
cout << "Who is the"<<orange<<" VISITOR"<<reset<<" team? > ";
cin >> newName; 
tTwoMain.setName(newName);
cout <<red<< "\nConnecting to server..."<< endl;
sleep(3); //pause 3 seconds.

system ("clear");

cout<< "Testing your internet connection... "<<reset<<endl;

sleep(8);


s.setTeam1(tOneMain); //setTeam1 to the latest data 
s.setTeam2(tTwoMain); //setTeam2 to the latest data 


  //work with the scoreboard and menu 
  do
  {
        //show the scoreboard and clear the screen each time 
        s.showScoreboard();
        
       
       //Menu options for the user 
        cout << "\nMenu: " << endl; 
        cout << "A. Update "<<tOneMain.getName()<<" score" << endl; 
        cout << "B. Update "<<tTwoMain.getName()<<" score" << endl; 
        cout << "C. Automatic quater switch"<<endl;
        cout << "D. Automatic ball possesion switch"<<endl;
        cout << "X. To Exit" << endl; 
        cin >> decision; 

        if(decision == 'a' || decision == 'A')
          {
            cout << "What is the new score? > ";
            cin >> newScore; 
            tOneMain.setScore(newScore);
            cout <<red<< "\nConnecting to server..."<<reset<< endl;
            sleep(3); //pause 3 seconds. 
          
          }
        else if(decision == 'b' || decision == 'B')
          {
            cout << "What is the new score? > ";
            cin >> newScore; 
            tTwoMain.setScore(newScore);
            cout <<red<< "\nConnecting to server..."<<reset<< endl;
            sleep(3); //pause 3 seconds. 
          
          }

        else if(decision == 'c' || decision == 'C')
          {
            int updater;
            updater=s.getPeriod(); 
            if (updater<5)
              {
              s.setPeriod((updater+1));
              }
            cout <<red<< "\nConnecting to server..."<<reset<< endl;
            sleep(3); //pause 3 seconds. 
          }


        else if(decision == 'd' || decision == 'C')
          {
            if (s.getPoss() == true)
              s.setPoss(false);
            else 
              s.setPoss(true);
          }

        else if(decision == 'x' || decision == 'X')
          {
            system("clear");

            cout<<red<<"Disconnecting from server..."<<reset<<endl;
            sleep(3);
            cout <<orange<< "\nDisconnected" <<reset<< endl; 
            
          }

        s.setTeam1(tOneMain); //setTeam1 to the latest data 
        s.setTeam2(tTwoMain); //setTeam2 to the latest data 
      
  }while(decision != 'x' && decision != 'X');     


}

int main() 
{

  
 
   
   scoreboardControls(); //run the scoreboard processes and menus

  return 0; 
}