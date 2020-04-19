#include <iostream>
#include <unistd.h> //for sleep command
#include <string>
#include <iomanip> //for setw
using namespace std; 

class Team
{
  private: 
    int score; 
    int fouls; 
    string name; 
   
  public: 
    Team()//default constructor  
    {
      score = 0;
      fouls = 0; 
      name = "";
    }  
    void setScore(int s) { score = s; }
    void setFouls(int f) { fouls = f; }
    void setName(string n) { name = n; }
    double getScore() const { return score; }
    double getFouls() const { return fouls; }
    string getName() const { return name; }
    
};

class Scoreboard
{
  private: 
    int period;
    bool poss; //true = home, false = visitor 
    Team team1; //double dot notation to get its data
    Team team2; //double dot notation to get its data
    int playerNumber;
    int playerFouls; 
    int minutes;
    int seconds; 
  public:
    Scoreboard() //default constructor 
    {
      period = 1;
      poss = true; //home team has the ball intially 
      playerNumber = 0;
      playerFouls = 0; 
      minutes = 11;
      seconds = 59; 
    }  
    void setPeriod(int p) { period = p; }
    void setPoss(bool po) { poss = po; }
    void setTeam1(Team t1) { team1 = t1; } //remember when the object changes
    void setTeam2(Team t2) {team2 = t2; } //remember when the object changes
    void setPlayerNumber(int pn) { playerNumber = pn; }
    void setPlayerFouls(int pf) { playerFouls = pf; }
    void setMinutes(int m) { minutes = m; }
    void setSeconds(int s) { seconds = s; }
    int getPeriod() const { return period; }
    bool getPoss() const { return poss; }
    Team getTeam1() const { return team1; }
    Team getTeam2()  const { return team2; }
    int getPlayerNumber() const { return playerNumber; }
    int getPlayerFouls() const { return playerFouls; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }
    
    void showScoreboard()
    { 
      string color = "\x1b[33;1m";
      string bold = "\x1b[" + to_string(50) + ";1m" ;
      string reset = "\x1b[0m";
        
        system("clear");
        
        
        //Show Scoreboard
        cout<<reset;
        for(int i = 0; i < 45; i++) { cout << "_"; }
        cout << endl; 
        cout << color << "\n\t\t2020 Corona Virus Bowl\n"<< reset;
        for(int i = 0; i < 45; i++) { cout << "_"; }
        cout << endl; 
        cout << "     (H)\t\t\t\t\t\t(V)" << endl; 
        cout << setw(10) << team1.getName() << "\t\t\t\t" << setw(12) << team2.getName()<< endl;
        color = "\x1b[91;1m"; //red 
        cout << color << setw(7) << team1.getScore() << "\t\t\t\t\t\t" << setw(6) <<  team2.getScore()  << reset<< endl;
        cout << "\t\t\t\tQTR: ";
        if (period<5)
        { cout<< period << endl; }
        else
        cout<<"OT"<<endl;

        //dealing with Boolean data
        if(poss == true)
        {
          cout <<bold<< team1.getName()<<reset<<" have the ball" << endl; 
        }
        else
        {
          cout <<bold<< team2.getName()<<reset<< " have the ball" << endl; 
        }
      for(int i = 0; i < 45; i++) { cout << "_"; }
    }
};