//
//  CardSort.hpp
//  GameVina
//
//  Created by Black3rry on 3/29/16.
//
//

#ifndef CardSort_hpp
#define CardSort_hpp

#include "CardSprite.hpp"
#include "cocos2d.h"

using namespace std;

class CardSort{
    
    public :
    static void BubbleSort(vector<Card> card);
    static void BubbleSortByIndex(vector<Card> card);
    static void SelectionSort(vector<Card> card);
    static void Swap(int i, int j, vector<Card> cards);
    
};

#endif /* CardSort_hpp */
