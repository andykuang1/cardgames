//
//  card.cpp
//  cardgames
//
//  Created by Andy Kuang on 1/17/19.
//  Copyright © 2019 Andy Kuang. All rights reserved.
//

#include "card.hpp"

Card::Card(){
    m_name = "";
}

Card::~Card(){
    
}

Card::Card(string cardname){
    m_name =  cardname;
}

void Card::showCard(){
    cout << m_name;
}

string Card::getName(){
    return m_name;
}
