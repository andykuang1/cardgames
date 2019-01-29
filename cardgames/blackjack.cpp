//
//  blackjack.cpp
//  cardgames
//
//  Created by Andy Kuang on 1/17/19.
//  Copyright © 2019 Andy Kuang. All rights reserved.
//

#include "blackjack.hpp"

Blackjack::Blackjack(){
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
//for split aces testing
//    tempDeck.insert_card(PlayingCard("AS"));
//    tempDeck.insert_card(PlayingCard(5,1));
//    tempDeck.insert_card(PlayingCard("AD"));
//    tempDeck.insert_card(PlayingCard(6,2));
//    tempDeck.insert_card(PlayingCard("TS"));
//    tempDeck.insert_card(PlayingCard("AC"));
//    tempDeck.insert_card(PlayingCard("5S"));
//    tempDeck.insert_card(PlayingCard("7D"));
    
    m_deck = tempDeck;
}

void Blackjack::dealStartingHand(){
    m_deck.shuffle();
    m_deck.dealCard(m_hand[0]);
    m_deck.dealCard(dealer_hand);
    m_deck.dealCard(m_hand[0]);
    m_deck.dealCard(dealer_hand);
}

void Blackjack::startgame(){
    //standard 52 card playing deck
    clearHands();
    createStartingDeck();
    cout << "You currently own $" << m_money << endl;
    cout << "How much would you like to place as a starting bet?" << endl;
    string betInput;
    getline(cin, betInput);
    currentBet = stoi(betInput);
    while ((currentBet < 0) || (currentBet > m_money)){
        if (currentBet < 0)
            cout << "The bet cannot be a negative value. Please enter another bet." << endl;
        else if (currentBet > m_money)
            cout << "The bet is greater than the amount you have. Please enter another bet." << endl;
        getline(cin, betInput);
        currentBet = stoi(betInput);
    }
    m_money -= currentBet;
    cout << "You have bet $" << currentBet << ". Your money is now $" << m_money << endl;
    dealStartingHand();
}

//before dealer reveal
void Blackjack::displayGameState(){
    cout << "Dealer's cards: ";
    cout << " __ ";
    showCard(dealer_hand, 1);
    cout << "\nYour cards:" << endl;
    for (int i = 0; i < numHands; i++){
        cout << "Hand " + to_string(i+1) + ":          ";
        showDeck(m_hand[i]);
        int valueOfHand = getValueOfDeck(m_hand[i]);
        cout << "(" + to_string(valueOfHand) + ")" << endl;
    }
}

//after dealer reveal
void Blackjack::displayGameState2(){
    cout << "Dealer's cards: ";
    showDeck(dealer_hand);
    int dealerHand = getValueOfDeck(dealer_hand);
    cout << "(" + to_string(dealerHand) + ")";
    cout << "\nYour value: ";
    cout << to_string(maxValue) << endl;
}

void enterContinue(){
    cout << "Press enter to continue." << endl;
    while (cin.get() != '\n')
        ;
}

//compare value at end of game
void Blackjack::decideWinner(){
    updateMaxValue();
    if (maxValue > getValueOfDeck(dealer_hand))
    {
        cout << "Your value (" + to_string(maxValue) << ") is greater than the dealer's (" + to_string(getValueOfDeck(dealer_hand)) << "). You win!" << endl;
        m_money += currentBet * 2;
        cout << "Your money is now $" << m_money << endl;
    }
    else if (getValueOfDeck(dealer_hand) > maxValue){
        cout << "Your value (" + to_string(maxValue) << ") is less than the dealer's (" + to_string(getValueOfDeck(dealer_hand)) << "). Unfortunately, you've lost this round." << endl;
        cout << "Your money is now $" << m_money << endl;
    }
    else{
        cout << "Your value and the dealer's are both " + to_string(maxValue) + ". You tied!" << endl;
        m_money += currentBet;
        cout << "Your money is now $" << m_money << endl;
    }
    
}

void Blackjack::updateMaxValue(){
    for (int i = 0; i < numHands; i++){
        if ((getValueOfDeck(m_hand[i]) <= 21) && getValueOfDeck(m_hand[i]) > maxValue)
            maxValue = getValueOfDeck(m_hand[i]);
    }
}

void Blackjack::clearHands(){
    numHands = 1;
    maxValue = 0;
    Deck<PlayingCard> tempDeck;
    for (int i = 0; i < 4; i++){
        m_hand[i] = tempDeck;
    }
    dealer_hand = tempDeck;
}

void Blackjack::playgame(){
    bool gameOn = true;
    string getMoney;
    cout << "Hello! You have chosen Blackjack. Let's get started." << endl;
    cout << "How much money would you like to start with?" << endl;
    getline(cin, getMoney);
    m_money = stoi(getMoney);
    while (gameOn){
        startgame();
        bool playing = true;
        bool allowSplit = false;
        bool specialCase = false;
        bool dealer_turn = false;
        string filler;
        int currentHand = 0;
        //playerturn
        cout << "It is your turn!" << endl;
        while (playing){
            displayGameState();
            string optionC;
            cout << "\nCurrently playing Hand " + to_string(currentHand+1) << endl;
            //same card, allow split
            if ((m_hand[currentHand].getCard(0).getValue() == m_hand[currentHand].getCard(1).getValue())){
                cout << "Would you like to [H]it, [S]tand, or Split [P]airs?" << endl;
                allowSplit = true;
            }
            //blackjack
            else if (((m_hand[currentHand].decksize() == 2) && (getValueOfDeck(m_hand[currentHand]) == 21)) || ((dealer_hand.decksize() == 2) && (getValueOfDeck(dealer_hand) == 21))){
                enterContinue();
                cout << "Blackjack!" << endl;
                maxValue = getValueOfDeck(m_hand[currentHand]);
                cout << "The dealer's cards were : ";
                showDeck(dealer_hand);
                cout << "(" + to_string(getValueOfDeck(dealer_hand)) + ")." << endl;
                decideWinner();
                specialCase = true;
                playing = false;
            }
            else
                cout << "Would you like to [H]it or [S]tand?" << endl;
            
            if (playing){
                getline(cin, optionC);
                char option = optionC[0];
                if ((option == 'H') || option == 'h'){
                    cout << "Hit!" << endl;
                    m_deck.dealCard(m_hand[currentHand]);
                    //bust
                    if (getValueOfDeck(m_hand[currentHand]) > 21){
                        displayGameState();
                        cout << "Your value (" + to_string(getValueOfDeck(m_hand[currentHand])) + ") is a bust. Unfortunately, you've lost this hand." << endl;
                        currentHand += 1;
                        //only one hand
                        if ((numHands == 1) && (currentHand == numHands)){
                            cout << "All your hands are bust. You lost this round." << endl;
                            cout << "The dealer's cards were : ";
                            showDeck(dealer_hand);
                            cout << "(" + to_string(getValueOfDeck(dealer_hand)) + ")." << endl;
                            cout << "Your money is now $" << m_money << endl;
                            specialCase = true;
                            playing = false;
                        }
                        //multiple hands
                        else if (currentHand == numHands){
                            //multiple hands all bust
                            if (maxValue > 21){
                                cout << "All your hands are bust. You have lost this round." << endl;
                                cout << "The dealer's cards were : ";
                                showDeck(dealer_hand);
                                cout << "(" + to_string(getValueOfDeck(dealer_hand)) + ")." << endl;
                                cout << "Your money is now $" << m_money << endl;
                                specialCase = true;
                                playing = false;
                            }
                            //not all bust, previously legal hand
                            playing = false;
                        }
                        //bust and no previous legal hands
                        else if (maxValue == 0)
                            maxValue = getValueOfDeck(m_hand[currentHand-1]);
                    }
                }
                else if ((option == 'S') || (option == 's')){
                    cout << "Stand! Your final value for this hand is " + to_string(getValueOfDeck(m_hand[currentHand])) << endl;
                    if ((getValueOfDeck(m_hand[currentHand]) > maxValue) || maxValue > 21)
                        maxValue = getValueOfDeck(m_hand[currentHand]);
                    currentHand += 1;
                    if (currentHand == numHands){
                        playing = false;
                        dealer_turn = true;
                    }
                }
                else if ((option == 'P') || (option == 'p')){
                    if (allowSplit == true){
                        m_hand[numHands].insert_card(m_hand[currentHand].remove_card(1));
                        m_deck.dealCard(m_hand[currentHand]);
                        m_deck.dealCard(m_hand[numHands]);
                        numHands++;
                        if (m_hand[currentHand].getCard(0).getValue() == 1){
                            displayGameState();
                            cout << "You have split Aces!" << endl;
                            playing = false;
                            dealer_turn = true;
                        }
                    }
                    allowSplit = false;
                }
            }
        }
        
        //dealerturn
        if (dealer_turn){
            cout << "\nIt is now the dealer's turn! We will proceed card by card." << endl;
        }
        while (dealer_turn){
            displayGameState2();
            if (getValueOfDeck(dealer_hand) < 17){
                m_deck.dealCard(dealer_hand);
                enterContinue();
                if (getValueOfDeck(dealer_hand) > 21){
                    displayGameState2();
                    enterContinue();
                    cout << "The dealer has bust. You have won!" << endl;
                    m_money += (currentBet * 2);
                    cout << "Your money is now $" << m_money << endl;
                    specialCase = true;
                }
            }
            else
                dealer_turn = false;
        }
        
        if (!specialCase){
            enterContinue();
            decideWinner();
        }
        
        cout << "Would you like to continue playing Blackjack?" << endl;
        cout << "[Y]es" << endl << "[N]o" << endl;
        string continueGame;
        while ((continueGame != "Y") && (continueGame != "y") && (continueGame != "N") && (continueGame != "n")){
            getline(cin, continueGame);
            if ((continueGame == "N") || (continueGame == "n"))
                gameOn = false;
            else if ((continueGame == "Y") || (continueGame == "y"))
                clearHands();
            else
                cout << "Your choice was not recognized. Please try again." << endl;
        }
    }
}
