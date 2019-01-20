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

void showCard(Deck<PlayingCard> deckToShow, int cardToShow){
    deckToShow.getCard(cardToShow).showCard();
}

void showDeck(Deck<PlayingCard> deckToShow){
    for (int i = 0; i < deckToShow.decksize(); i++){
        deckToShow.getCard(i).showCard();
        cout << " ";
    }
}

int getValueOfDeck(Deck<PlayingCard> playingdeck){
    int counter = 0;
    int numAces = 0;
    for (int i = 0; i < playingdeck.decksize(); i++){
        int value = playingdeck.getCard(i).getValue();
        if (value > 10)
            counter += 10;
        else if (value == 1)
            numAces++;
        else
            counter += value;
    }
    for (int i = 0; i < numAces; i++){
        if (counter + 11 <= 21)
            counter += 11;
        else
            counter += 1;
    }
    return counter;
}

void Blackjack::createStartingDeck(){
    for (int i = 1; i < 14; i++)
        for (int j = 1; j < 5; j++)
            m_deck.insert_card(PlayingCard(i, j));
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
    playgame();
}

void Blackjack::playgame(){
    bool playing = true;
    //playerturn
    while (playing){
        cout << "Dealer has cards: ";
        cout << " __ ";
        showCard(dealer_hand, 1);
        cout << "\nYour cards are:    ";
        showDeck(m_hand);
        int valueOfHand = getValueOfDeck(m_hand);
        cout << "(" + to_string(valueOfHand) + ")" << endl;
        char option;
        cout << "Would you like to [H]it or [S]tand?" << endl;
        cin >> option;
        if ((option == 'H') || option == 'h')
            m_deck.dealCard(m_hand);
        else if ((option == 'S') || option == 's')
            playing = false;
    }
    
    //dealerturn
}
