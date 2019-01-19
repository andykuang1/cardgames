//
//  blackjack.cpp
//  cardgames
//
//  Created by Andy Kuang on 1/17/19.
//  Copyright © 2019 Andy Kuang. All rights reserved.
//

#include "blackjack.hpp"

Blackjack::Blackjack(){
    createStartingDeck();
    startgame();
}

void Blackjack::createStartingDeck(){
    for (int i = 1; i < 14; i++){
        for (int j = 1; j < 5; j++){
            m_deck.insert_card(PlayingCard(i, j));
        }
    }
}

void Blackjack::startgame(){
    cout << "Hello! You have chosen Blackjack. Let's get started!" << endl;
    
}
