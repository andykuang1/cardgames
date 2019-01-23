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
using namespace std;

template<class T>
class Deck{
public:
    //constructors
    Deck();
    //accessors
    int decksize();
    T getTop();
    T getCard(int i);
    //modifiers
    void shuffle();
    void insert_card(T cardToInsert);
    T remove_card(int i);
    void dealCard(Deck<T>& otherDeck);
    //destructor
    ~Deck();
    
private:
    vector<T> m_deck;
};

#endif /* deck_hpp */
