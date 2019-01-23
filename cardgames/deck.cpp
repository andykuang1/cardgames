//
//  deck.cpp
//  cardgames
//
//  Created by Andy Kuang on 1/17/19.
//  Copyright © 2019 Andy Kuang. All rights reserved.
//

#include "deck.hpp"

template<class T>
Deck<T>::Deck(){
}

template<class T>
Deck<T>::~Deck(){
    
}

template<class T>
T Deck<T>::getTop(){
    return m_deck[0];
}

template<class T>
void Deck<T>::shuffle(){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(m_deck.begin(), m_deck.end(), default_random_engine(seed));
}

template<class T>
void Deck<T>::insert_card(T cardToInsert){
    m_deck.push_back(cardToInsert);
}

template<class T>
int Deck<T>::decksize(){
    return m_deck.size();
}

template<class T>
T Deck<T>::getCard(int i){
    return m_deck[i];
}

template<class T>
T Deck<T>::remove_card(int i){
    T temp_item = m_deck[i];
    m_deck.erase(m_deck.begin() + i);
    return temp_item;
}

//deals card from top of deck to a different deck
template<class T>
void Deck<T>::dealCard(Deck& otherDeck){
    otherDeck.insert_card(m_deck[0]);
    remove_card(0);
}
