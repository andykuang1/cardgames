//
//  card.hpp
//  cardgames
//
//  Created by Andy Kuang on 1/17/19.
//  Copyright © 2019 Andy Kuang. All rights reserved.
//

#ifndef card_hpp
#define card_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Card{
public:
    //constructors
    Card();
    Card(string cardname);
    //accessors
    void showCard();
    string getName();
    //destructor
    ~Card();

protected:
    string m_name;
    string cardfront;
    string cardback;
};

#endif /* card_hpp */
