#include "Card.hpp"
#include "URL.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "json.hpp"
#include <vector>
#include <algorithm>

using json = nlohmann::json;
using namespace std;

// insertionSortArrayList returns a new vector, Im sure theres a way to do it
// where it just changes the original vector, but because vectors are passed by
// value instead of address, it wasn't working the way I thought it should.
// This is very inefficient (creating a new array), but it gets the job done.

void displayArrayList(vector<Card*> ar)
{
    for(int i = 0; i < ar.size(); i++)
    {
        ar[i]->display();
    }
}

vector<Card*> insertionSortArrayList(vector<Card*> ar)
{
    Card* tempSwap;
    int theFollower;
    for(int currSart = 0; currSart < ar.size(); currSart++)
    {
        theFollower = currSart;
        while(theFollower > 0 && ar[theFollower]->getDefense() < ar[theFollower - 1]->getDefense())
        {
            tempSwap = ar[theFollower];
            ar[theFollower] = ar[theFollower - 1];
            ar[theFollower - 1] = tempSwap;
            theFollower--;
        }
    }
    vector<Card*> newAR;
    for(int i = 0; i < ar.size(); i++)
    {
        newAR.push_back(ar[i]);
    }
}

void insertionSort(vector<int> ar) // for testing purposes
{
    int tempSwap;
    int theFollower;
    for(int currSart = 0; currSart < ar.size(); currSart++)
    {
        theFollower = currSart;
        while(theFollower > 0 && ar[theFollower] < ar[theFollower - 1])
        {
            tempSwap = ar[theFollower];
            ar[theFollower] = ar[theFollower - 1];
            ar[theFollower - 1] = tempSwap;
            theFollower--;
        }
    }
    for(int i = 0; i < ar.size(); i++)
    {
        cout << ar[i] << endl;
    }
}

int main(int argc, char** argv)
{
    URL* u1 = new URL("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
    string jsonString = u1->getContents();
    json parsedJson = json::parse(jsonString);
    Card* theCards[parsedJson.size()];
    std::vector<Card*> deck;
    std::vector<int> ar;

    if(parsedJson.is_array())
    {
        for(int i = 0; i < parsedJson.size(); i++)
        {
            json currValue = parsedJson[i];
            if(currValue.is_object())
            {
                string name = currValue.value("name", "N/A");
                int attack = currValue.value("attack", -1);
                int defense = currValue.value("health", -1);
                int manaCost = currValue.value("cost", -1);
                string type = currValue.value("type", "N/A");
                theCards[i] = new Card(name, manaCost, attack, defense, type);
                if(theCards[i]->getType() == "MINION")
                {
                    deck.push_back(theCards[i]);
                }
            }
        }
    }

    displayArrayList(deck);
    displayArrayList(insertionSortArrayList(deck));
    return 0;
}