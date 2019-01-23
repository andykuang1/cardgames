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
#include "playingcard.hpp"
#include "deck.cpp"

class Blackjack{
public:
    Blackjack();
    void createStartingDeck();
    void dealStartingHand();
    //before dealer reveal
    void displayGameState();
    //after dealer reveal
    void displayGameState2();
    void decideWinner();
    
private:
    void startgame();
    void playgame();
    Deck<PlayingCard> m_deck;
    Deck<PlayingCard> m_hand;
    Deck<PlayingCard> dealer_hand;
};

#endif /* blackjack_hpp */
