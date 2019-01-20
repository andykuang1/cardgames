//
//  playingcard.cpp
//  cardgames
//
//  Created by Andy Kuang on 1/17/19.
//  Copyright © 2019 Andy Kuang. All rights reserved.
//

#include "playingcard.hpp"

string cardvalues[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
string cardsuits[] = {"D", "C", "H", "S"};

int letterToValue(char cardvalue){
    if (cardvalue == 'A')
        return 1;
    else if (cardvalue == '2')
        return 2;
    else if (cardvalue == '3')
        return 3;
    else if (cardvalue == '4')
        return 4;
    else if (cardvalue == '5')
        return 5;
    else if (cardvalue == '6')
        return 6;
    else if (cardvalue == '7')
        return 7;
    else if (cardvalue == '8')
        return 8;
    else if (cardvalue == '9')
        return 9;
    else if (cardvalue == 'T')
        return 10;
    else if (cardvalue == 'J')
        return 11;
    else if (cardvalue == 'Q')
        return 12;
    else if (cardvalue == 'K')
        return 13;
    return 0;
}

int suitToValue(char cardsuit){
    if (cardsuit == 'D')
        return 1;
    else if (cardsuit == 'C')
        return 2;
    else if (cardsuit == 'H')
        return 3;
    else if (cardsuit == 'S')
        return 4;
    return cardsuit;
}

PlayingCard::PlayingCard(){
    m_name = "";
    cardback = "http://images.penguinmagic.com/images/products/original/8007b.jpg";
}

PlayingCard::~PlayingCard(){
    
}

//using a name such as AS (for ace of spades)
PlayingCard::PlayingCard(string cardname){
    m_name = cardname;
    m_value = letterToValue(cardname[0]);
    m_suit = suitToValue(cardname[1]);
}

//using value and suit such as 1,4 for ace of spades)
PlayingCard::PlayingCard(int cardvalue, int cardsuit){
    m_name = cardvalues[cardvalue-1] + cardsuits[cardsuit-1];
    m_value = cardvalue;
    m_suit = cardsuit;
}

//using char and suit such as A,4 for ace of spades)
PlayingCard::PlayingCard(char cardvalue, int cardsuit){
    m_name = cardvalue + cardsuits[cardsuit-1];
    m_value = letterToValue(cardvalue);
    m_suit = cardsuit;
}

int PlayingCard::getValue(){
    return m_value;
}

string PlayingCard::getSuit(){
    return cardsuits[m_suit-1];
}

