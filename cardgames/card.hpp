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
    Card();
    Card(string cardname);
    void showCard();
    string getName();
    
protected:
    string name;
    string cardfront;
    string cardback;
};

#endif /* card_hpp */
