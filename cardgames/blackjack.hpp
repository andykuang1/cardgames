//
//  blackjack.hpp
//  cardgames
//
//  Created by Andy Kuang on 1/17/19.
//  Copyright © 2019 Andy Kuang. All rights reserved.
//

#ifndef blackjack_hpp
#define blackjack_hpp

#include <stdio.h>
#include "deck.hpp"
#include "playingcard.hpp"

class Blackjack{
public:
    Blackjack();
    void createStartingDeck();
    void dealStartingHand();
    
private:
    void startgame();
    Deck m_deck;
    Deck m_hand;
    Deck dealer_hand;
};

#endif /* blackjack_hpp */
