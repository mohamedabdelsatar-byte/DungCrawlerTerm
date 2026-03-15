#include <iostream>
#include <unistd.h>
#include <thread> 
#include <chrono>
#include <string>
using namespace std;


enum ItemIndex{
    KEY=0,
    //NONE=1,
    //NONE=2,
    //NONE=3,
    SNAKE_TOOL=4,
    //NONE=5,
    //NONE=6,
    //NONE=7,
};

bool Escaped = false;

struct Player{
    std::string name;
    char gender;
    bool hasKey = false;
    int Health = 5;
    bool inv [7] = {false, false, false, false, true, false, false};
};
struct GameState{
    bool visited[5] = {false, false, false, false, false};
    bool completed[4]= {false, false, false, false};
    bool Escaped = false;
    bool keepPlaying = true;
};

// RESET function
void Reset(Player &p, GameState &s);

// Text based functions
void slowPrint(string text, int speed);
void delayMs(int speed);

// ------DOOR functions--------
void Door1(Player &p, GameState &s);
void Exitroom(Player &p, GameState &s);
void Door3(Player &p, GameState &s);
void KeyRoom(Player &p, GameState &s);
void SnaketoolRoom(Player &p, GameState &s);


int main(){
    GameState St1;
    Player player1;
    int playChoice;
    
    

    cout<<"Name? ";
    cin>>player1.name;


    slowPrint(player1.name + " wakes up exhausted....", 100);
    delayMs(500);
    slowPrint(player1.name + " looks around and notices 5 doors", 100);
    delayMs(1000);
do{

    do{
    slowPrint("He ponders at which door to open? (1->5): ", 50);
    cin>>playChoice;

    switch(playChoice){
    case 1:
        slowPrint("Door 1 TEMP", 100);
        break;
    case 2:
         Exitroom(player1, St1);
        break;
    case 3:
        slowPrint("Door 3 TEMP", 100);
        break;
    case 4: 
        KeyRoom(player1, St1);
        break;
    case 5: 
        slowPrint("Door 5 TEMP", 100);
        break;
    default:
        break;

    };

}while(St1.Escaped==false);


slowPrint("game over", 450);
Reset(player1, St1);

cout<<"Wish to Replay?: ";
char ReplayChoice;
cin>>ReplayChoice;

if(ReplayChoice == 'n' || ReplayChoice == 'N'){
    St1.keepPlaying = false;
}

}while(St1.keepPlaying==true);



    return 0;
}



void slowPrint(string text, int speed) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
    cout << endl;
    // slowPrint("Hello", 100);
}
void delayMs(int speed){
this_thread::sleep_for(chrono::milliseconds(speed));
};
void Reset(Player &p, GameState &s){
    p.hasKey=false;
    p.Health=5;
    s.Escaped=false;
    s.keepPlaying=true;
    for(int i=0; i<5;i++){
    s.visited[i]=false;
    }
    for(int i=0; i<7;i++){
        p.inv[i]=false;
    }
    

}

void Door1(Player &p, GameState &s){
/*Chest combination Puzzle Location
Here is the location of the choest, this is where the player solves a puzzle
to get the right combination to open the chest.
the chest is located in the SnaketoolRoom.
*/
}
void Exitroom(Player &p, GameState &s){

    char choice;

    slowPrint("The door is large and locked...",50);
    delayMs(500);
    if(p.hasKey==true && s.visited[2]==false){ // CASE WITH KEY
        slowPrint("Do you wish to use the key?", 50);
        cin>>choice;

        if(choice == 'y' || choice == 'Y'){
                slowPrint(p.name + " unlocks the door, meeting a shining bright and finally escapes the hall of doors",50);
                delayMs(500);
                s.Escaped = true;
                s.visited[2] = true;
            }
        else if(choice == 'n' || choice == 'N'){
                slowPrint("Second guessing their action, they decided to step back from the door...",50);
                delayMs(500);
            }

}

    else if(p.hasKey==false && s.visited[2]==false){ // CASE WITHOUT KEY
        slowPrint("Requiring some kind of key, which " + p.name + " doesn't have..",50);
        s.visited[2] = true;
        delayMs(500);
    }
    else if(p.hasKey==false && s.visited[2]==true){ // CASE WITHOUT KEY
        slowPrint(p.name+" needs a key to enter this room...",50);
        delayMs(500);
    }

}

void Door3(Player &p, GameState &s){
//NO IDEA YET
}
void KeyRoom(Player &p, GameState &s){
   
    
    if(s.visited[3]==false && p.inv[SNAKE_TOOL]==false && s.completed[3]==false){
   
    slowPrint(p.name + " slowly opens the door.....", 75);
    delayMs(500);
    slowPrint("a smell punches "+p.name+" and a loud hissing noise spreads around the hall..", 75);
    delayMs(500);
    slowPrint("The room is surrounded with venomous snakes all around, guarding what seems to be the key for that mysterious door...", 75);
    delayMs(500);
    slowPrint("As one of the snakes rush to bite "+p.name+", they shut the door immediately....", 75);
    s.visited[3]=true;
    
    }

    else if(s.visited[3]==true && p.inv[SNAKE_TOOL]==false && s.completed[3]==false){
        slowPrint("This room contains the snakes, no hope with getting the key while the snakes are in the room...", 50);
    }

    else if(s.visited[3]==false && p.inv[SNAKE_TOOL]==true && s.completed[3]==false){
    slowPrint(p.name + " slowly opens the door.....", 75);
    delayMs(500);
    slowPrint("a smell punches "+p.name+" and a loud hissing noise spreads around the hall..", 75);
    delayMs(500);
    slowPrint("The room is surrounded with venomous snakes all around, but they all run away from "+p.name, 75);
    delayMs(500);
    slowPrint("They look around and noticed a key on a pedstal.",50);
    delayMs(500);
    slowPrint(p.name+" Obtained a Key",45);
    s.visited[3]=true;
    s.completed[3]=true;
    p.hasKey=true;
    p.inv[KEY]=true;


    }
    else if(s.visited[3]==true && p.inv[SNAKE_TOOL]==true && s.completed[3]==false){
       slowPrint(p.name + " slowly opens the door and the snakes run away from the strong smell...", 75);
       delayMs(500);
       slowPrint("As "+p.name+" looks around, they managed to get a hold off the key..",60);
       delayMs(500);
        slowPrint(p.name+" Obtained a Key",45);
        s.completed[3]=true;
        p.hasKey=true;
        p.inv[KEY]=true;

    }
    else{
        slowPrint("There's no need to enter this room again...",50);
        return;
    }
}
void SnaketoolRoom(Player &p, GameState &s){
/*Snake tool location IDEA

this room will contain the snake tool to help with obtaining the doorkey. 
To get the tool, player must have the right combination to open the chest which contains it.
this is where a puzzle must be solved. The combination will be located in a different room

*/

}


/*
EASTER EGG IDEAS
have some of the doors include an easter egg where when the user types a code
say "ecu", it opens up a secret passage way with some special items or something

*/