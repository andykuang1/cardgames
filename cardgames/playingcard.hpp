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
    PlayingCard(string cardname);
    PlayingCard(int cardvalue, int cardsuit);
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
