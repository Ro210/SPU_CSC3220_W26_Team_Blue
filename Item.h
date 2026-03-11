//
// Created by Linh Bui on 3/3/2026.
//

#ifndef SPU_CSC3220_W26_TEAM_BLUE_ITEM_H
#define SPU_CSC3220_W26_TEAM_BLUE_ITEM_H
#endif //SPU_CSC3220_W26_TEAM_BLUE_ITEM_H

#include <string>
#include <ctime>
using std::string;

class Item {

private:
    int ItemId;
    time_t created_on = NULL;

public:
    Item();
    string ItemName;
    int ItemQuant;
    string ItemDesc;
    void setItemName(string item_name);
    void setItemQuant(int item_quantity);
    void setItemDesc(string item_desc);
    int getItemId();
    string getItemName();
    int getItemQuant();
    string getItemDesc();
    time_t getCreatedOn();

};