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

PlayingCard::PlayingCard(){
    name = "";
}

PlayingCard::PlayingCard(int cardvalue, int cardsuit){
    name = cardvalues[cardvalue-1] + cardsuits[cardsuit-1];
    m_value = cardvalue;
    m_suit = cardsuit;
}

PlayingCard::PlayingCard(char cardvalue, int cardsuit){
    name = cardvalue + cardsuits[cardsuit-1];
    if (cardvalue == 'A')
        m_value = 1;
    else if (cardvalue == 'T')
        m_value = 10;
    else if (cardvalue == 'J')
        m_value = 11;
    else if (cardvalue == 'Q')
        m_value = 12;
    else if (cardvalue == 'K')
        m_value = 13;
    m_suit = cardsuit;
}
