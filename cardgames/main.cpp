//
//  main.cpp
//  cardgames
//
//  Created by Andy Kuang on 1/17/19.
//  Copyright © 2019 Andy Kuang. All rights reserved.
//

#include <iostream>
#include "blackjack.hpp"
#include <string>
#include <algorithm>
using namespace std;

string continueGameOptions[] = {"Y", "y", "N", "n"};

int playgame(int option){
    switch(option){
        case 1:{
            Blackjack object;
            object.playgame();
//                cout << "Would you like to continue playing Blackjack?" << endl;
//                cout << "[Y]es" << endl << "[N]o" << endl;
//                string continueGame;
//                while ((continueGame != "Y") && (continueGame != "y") && (continueGame != "N") && (continueGame != "n")){
//                    cin >> continueGame;
//                    if ((continueGame == "N") || (continueGame == "n"))
//                        playing = false;
//                    else if ((continueGame == "Y") || (continueGame == "y"))
//                        continue;
//                    else
//                        cout << "Your choice was not recognized. Please try again." << endl;
//                }
            break;
        }
        case 2:{
            return 0;
            break;
        }
        default:{
            cout << "Sorry, your choice was not recognized." << endl;
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    bool playing = true;
    while (playing){
        cout << "Choose the game you would like to play. The options are displayed below:" << endl;
        cout << "[1]Blackjack" << endl;
        cout << "[2]Exit" << endl;
        string option = "";
        getline(cin, option);
        try{
        if (playgame(stoi(option)) == 0)
            playing = false;
        } catch(invalid_argument){
            cout << "Sorry, your choice was not recognized." << endl;
        }
    }
    return 0;
}
