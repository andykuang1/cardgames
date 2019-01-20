//
//  deck.hpp
//  cardgames
//
//  Created by Andy Kuang on 1/17/19.
//  Copyright © 2019 Andy Kuang. All rights reserved.
//

#ifndef deck_hpp
#define deck_hpp

#include <algorithm>
#include <stdio.h>
#include <vector>
#include <random>
#include <chrono>
#include "card.hpp"

class Deck{
public:
    //constructors
    Deck();
    //accessors
    void showTop();
    Card getTop();
    void showCard(int i);
    Card getCard(int i);
    void showDeck();
    void showCards(int start, int end);
    int decksize();
    //modifiers
    void shuffle();
    void insert_card(Card cardToInsert);
    void dealCard(Deck& otherDeck);
    
private:
    vector<Card> m_deck;
};

#endif /* deck_hpp */
