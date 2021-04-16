#include "Card.hpp"
#include "URL.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main(int argc, char** argv)
{
    URL* u1 = new URL("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
    string jsonString = u1->getContents();
    json parsedJson = json::parse(jsonString);
    Card* theCards[parsedJson.size()];

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
                theCards[i] = new Card(name, manaCost, attack, defense);
                theCards[i]->display();
            }
        }
    }
    cout << "Number of Cards: " << parsedJson.size() << endl;
    return 0;
}