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
using namespace std;

void playgame(int option){
    switch(option){
        case 1:
            Blackjack object;
    }
}

int main(int argc, const char * argv[]) {
    cout << "Choose the game you would like to play. The options are displayed below:" << endl;
    cout << "[1]Blackjack" << endl;
    string option = "";
    cin >> option;
    playgame(stoi(option));
    return 0;
}
