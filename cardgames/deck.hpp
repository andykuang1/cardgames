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
    Deck();
    void showTop();
    void shuffle();
    void insert_card(Card card);
    int decksize();
    void showCard(int i);
private:
    vector<Card> m_deck;
};

#endif /* deck_hpp */
