//
//  blackjack.cpp
//  cardgames
//
//  Created by Andy Kuang on 1/17/19.
//  Copyright © 2019 Andy Kuang. All rights reserved.
//

#include "blackjack.hpp"

Blackjack::Blackjack(){
    startgame();
}

void Blackjack::createStartingDeck(){
    for (int i = 1; i < 14; i++){
        for (int j = 1; j < 5; j++){
            m_deck.insert_card(PlayingCard(i, j));
        }
    }
}

void Blackjack::dealStartingHand(){
    m_deck.shuffle();
    m_deck.dealCard(m_hand);
    m_deck.dealCard(dealer_hand);
    m_deck.dealCard(m_hand);
    m_deck.dealCard(dealer_hand);
}

void Blackjack::startgame(){
    createStartingDeck();
    cout << "Hello! You have chosen Blackjack. Let's get started!" << endl;
    dealStartingHand();
    cout << "Dealer has cards: ";
    dealer_hand.showCard(1);
    cout << " __ " << endl;
    cout << "Your cards are:   ";
    m_hand.showDeck();
}
