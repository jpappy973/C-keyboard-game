#include <iostream>
#include<vector>
#include<stdlib.h>
#include<random>
#include <ctime>
#include <unistd.h>
#include <thread> 
using namespace std;

//for whileloops
bool True = true;
// where the randomly genrated word from list is saved
string ranname;
//timer add to this varable
int GameoVerTimer;
int score =0;


string list_name[36]={
        "cat","bat","dog","aah","aal","aas","aba","abs","aby","ace","act","can",
        "pzazz","jazzy","whizz","zhuzh","abuzz","quake","zebud","zoppo",
        "bunjy","azoth","bunjy","chowk","quizzed","wazzock","buzzwig","fizzgig","drizzly","bazzing",
        "hzzies","mizzled","bezzant","zambuck","jezebel","sizzled",
        
};

//gAme frame


//game timer
int tiMeG(){

    while(True){
        //cout<<GameoVerTimer;
        GameoVerTimer++;

        if(GameoVerTimer == 5){
            True=false;
        }
        sleep(1);
        
    } 
    system("clear");

    return 0;
}



//main game logic
int GameLOop(){
    mt19937 generator;
    generator.seed(time(0));
    uniform_int_distribution<uint32_t> words(0,35);
    
    int random = words(generator);
    string guess_name;
    

    while(True){
        
        random = words(generator);
        ranname = list_name[random];
        cout<<"\n\n\n\n";
        cout<<"\t score: "<<score<<"\n";
        cout<<ranname<<"\n";
        cout<<"\n";
        getline(cin,guess_name); 

        if(guess_name == ranname){
            score++;
            system("clear");
            GameoVerTimer = 0;
        }else {
            score--;
        }
 
        if (GameoVerTimer == 5){
            system("clear");
            True=false;
        }
    
    }

    
    return 0;
}

int main()
{
/*allows both gamelogic and 
timer to be run at the same 
time by putting it on different thread*/

//runs games timer
    thread t1(tiMeG);
    
//runs gamelogic 
    thread t2(GameLOop);
    
//this is to part of the threading process
    t1.join();
    
    t2.join();
//when gameover the two threads above will break and display this 
    system("clear");
    cout<<"\n\n\n\n\n\n\n\n";
    cout<< "\t  GAMEOVER\n";
    cout<<"\t score:"<<score<<"\n";
    cout<<"\n\n\n\n\n\n\n\n\n\n";

    
    
    return 0;
}