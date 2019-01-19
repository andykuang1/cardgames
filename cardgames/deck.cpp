//
//  deck.cpp
//  cardgames
//
//  Created by Andy Kuang on 1/17/19.
//  Copyright © 2019 Andy Kuang. All rights reserved.
//

#include "deck.hpp"

Deck::Deck(){
}

void Deck::showTop(){
    m_deck[0].showCard();
}

void Deck::shuffle(){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(m_deck.begin(), m_deck.end(), default_random_engine(seed));
}

void Deck::insert_card(Card card){
    m_deck.push_back(card);
}

int Deck::decksize(){
    return m_deck.size();
}

void Deck::showCard(int i){
    m_deck[i].showCard();
}
