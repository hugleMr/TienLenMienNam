//
//  CardSort.cpp
//  GameVina
//
//  Created by Black3rry on 3/29/16.
//
//

#include "CardSort.hpp"

void CardSort::BubbleSort(vector<Card> cards)
{
    for (int i = 0; i < cards.size() - 1; i++)
    {
        for (int j = i + 1; j < cards.size(); j++)
        {
            if (cards.at(j).number < cards.at(i).number)
            {
                CardSort::Swap(i, j, cards);
            }
        }
    }
}

void CardSort::BubbleSortByIndex(vector<Card> cards)
{
    for (int i = 0; i < cards.size() - 1; i++)
    {
        for (int j = i + 1; j < cards.size(); j++)
        {
            if (cards.at(j).number < cards.at(i).number)
            {
                CardSort::Swap(i, j, cards);
            }
        }
    }
}

// Selectionsort Algorithm
void CardSort::SelectionSort(vector<Card> cards)
{
    int min = 0;
    for (int i = 0; i < cards.size() - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < cards.size(); j++)
        {
            if (cards.at(j).number < cards.at(min).number)
            {
                min = j;
                CardSort::Swap(i, min, cards);
            }
        }
    }
}

// Swap 2 card
void CardSort::Swap(int i, int j, vector<Card> cards)
{
    Card temp = cards.at(i);
    cards.at(i) = cards.at(j);
    cards.at(j) = temp;
}