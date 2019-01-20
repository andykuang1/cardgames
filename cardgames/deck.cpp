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

Card Deck::getTop(){
    return m_deck[0];
}

void Deck::shuffle(){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(m_deck.begin(), m_deck.end(), default_random_engine(seed));
}

void Deck::insert_card(Card cardToInsert){
    m_deck.push_back(cardToInsert);
}

int Deck::decksize(){
    return m_deck.size();
}

void Deck::showCard(int i){
    m_deck[i].showCard();
}

Card Deck::getCard(int i){
    return m_deck[i];
}

void Deck::dealCard(Deck& otherDeck){
    otherDeck.insert_card(m_deck[0]);
    m_deck.erase(m_deck.begin());
}

void Deck::showDeck(){
    for (int i = 0; i < m_deck.size(); i++){
        m_deck[i].showCard();
        cout << " ";
    }
    cout << endl;
}

void Deck::showCards(int start, int end){
    for (int i = 0; i < end; i++){
        m_deck[i].showCard();
        cout << " ";
    }
    cout << endl;
}
