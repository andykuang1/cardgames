//
//  card.cpp
//  cardgames
//
//  Created by Andy Kuang on 1/17/19.
//  Copyright © 2019 Andy Kuang. All rights reserved.
//

#include "card.hpp"

Card::Card(){
    name = "";
}

Card::Card(string cardname){
    name =  cardname;
}

void Card::showCard(){
    cout << name << endl;
}
