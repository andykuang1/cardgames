//
//  playingcard.hpp
//  cardgames
//
//  Created by Andy Kuang on 1/17/19.
//  Copyright © 2019 Andy Kuang. All rights reserved.
//

#ifndef playingcard_hpp
#define playingcard_hpp

#include <stdio.h>
#include "card.hpp"

class PlayingCard : public Card{
public:
    //constructors
    PlayingCard();
    //example: "AS" for ace of spades
    PlayingCard(string cardname);
    //1 for ace, 11 for J, 12 for Q, 13 for K, 1 for diamonds, 2 for clubs, 3 for hearts, 4 for spades
    //example: 1,4 for ace of spades
    PlayingCard(int cardvalue, int cardsuit);
    //allows A/T/J/Q/K for Ace and 10 to king
    //example: A4 for ace of spades
    PlayingCard(char cardvalue, int cardsuit);
    
    //accessors
    int getValue();
    string getSuit();
    
    //destructor
    ~PlayingCard();
private:
    int m_value = 1;
    int m_suit = 1;
};

#endif /* playingcard_hpp */
