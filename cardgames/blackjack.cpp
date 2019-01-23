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
        //deckToShow.getCard(i).showCard();
        showCard(deckToShow, i);
        cout << " ";
    }
}

//add up total value; all face cards are worth 10, A is worth 1 or 11, and rest are worth their value
int getValueOfDeck(Deck<PlayingCard> playingdeck){
    int counter = 0;
    int numAces = 0;
    for (int i = 0; i < playingdeck.decksize(); i++){
        int value = playingdeck.getCard(i).getValue();
        //face cards that aren't an ace
        if (value > 10)
            counter += 10;
        //count aces
        else if (value == 1)
            numAces++;
        //any other card
        else
            counter += value;
    }
    //count aces as 1 or 11 based on total value
    for (int i = 0; i < numAces; i++){
        if (counter + 11 <= 21)
            counter += 11;
        else
            counter += 1;
    }
    return counter;
}

void Blackjack::createStartingDeck(){
    Deck<PlayingCard> tempDeck;
    //1 is ace, 13 is king
    for (int i = 1; i < 14; i++)
        //1 is diamonds, 2 is clubs, 3 is hearts, 4 is spades
        for (int j = 1; j < 5; j++)
            tempDeck.insert_card(PlayingCard(i, j));
    m_deck = tempDeck;
}

void Blackjack::dealStartingHand(){
    m_deck.shuffle();
    m_deck.dealCard(m_hand);
    m_deck.dealCard(dealer_hand);
    m_deck.dealCard(m_hand);
    m_deck.dealCard(dealer_hand);
}

void Blackjack::startgame(){
    //standard 52 card playing deck
    createStartingDeck();
    cout << "Hello! You have chosen Blackjack. Let's get started." << endl;
    dealStartingHand();
    playgame();
}

//before dealer reveal
void Blackjack::displayGameState(){
    cout << "Dealer's cards: ";
    cout << " __ ";
    showCard(dealer_hand, 1);
    cout << "\nYour cards:    ";
    showDeck(m_hand);
    int valueOfHand = getValueOfDeck(m_hand);
    cout << "(" + to_string(valueOfHand) + ")" << endl;
}

//after dealer reveal
void Blackjack::displayGameState2(){
    cout << endl;
    cout << "Dealer's cards: ";
    showDeck(dealer_hand);
    int dealerHand = getValueOfDeck(dealer_hand);
    cout << "(" + to_string(dealerHand) + ")";
    cout << "\nYour value: ";
    int valueOfHand = getValueOfDeck(m_hand);
    cout << to_string(valueOfHand) << endl;
}

//compare value at end of game
void Blackjack::decideWinner(){
    if (getValueOfDeck(m_hand) > getValueOfDeck(dealer_hand))
        cout << "Your value (" + to_string(getValueOfDeck(m_hand)) << ") is greater than the dealer's (" + to_string(getValueOfDeck(dealer_hand)) << "). You win!" << endl;
    else if (getValueOfDeck(dealer_hand) > getValueOfDeck(m_hand))
        cout << "Your value (" + to_string(getValueOfDeck(m_hand)) << ") is less than the dealer's (" + to_string(getValueOfDeck(dealer_hand)) << "). Unfortunately, you've lost this round." << endl;
    else
        cout << "Your value and the dealer's are both " + to_string(getValueOfDeck(m_hand)) + ". You tied!";
    
}

void Blackjack::playgame(){
    bool playing = true;
    //playerturn
    cout << "It is your turn!" << endl;
    while (playing){
        displayGameState();
        char option;
        cout << "Would you like to [H]it or [S]tand?" << endl;
        cin >> option;
        if ((option == 'H') || option == 'h'){
            cout << "Hit!" << endl;
            m_deck.dealCard(m_hand);
            if (getValueOfDeck(m_hand) > 21){
                displayGameState();
                cout << "Your value (" + to_string(getValueOfDeck(m_hand)) + ") is a bust. Unfortunately, you've lost this round." << endl;
                cout << "The dealer's cards were : ";
                showDeck(dealer_hand);
                cout << "(" + to_string(getValueOfDeck(dealer_hand)) + ")." << endl;
                return;
            }
        }
        else if ((option == 'S') || (option == 's')){
            cout << "Stand! Your final value is " + to_string(getValueOfDeck(m_hand)) << endl;
            playing = false;
        }
    }
    
    playing = true;
    //dealerturn
    cout << "It is now the dealer's turn! We will proceed card by card." << endl;
    while (playing){
        cout << "Press enter to continue.";
        string filler = "";
        cin >> filler;
        cin.ignore();
        displayGameState2();
        if (getValueOfDeck(dealer_hand) < 17)
            m_deck.dealCard(dealer_hand);
        else
            playing = false;
    }
    
    decideWinner();
}
