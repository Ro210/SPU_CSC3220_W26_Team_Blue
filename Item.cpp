//
// Created by Linh Bui on 3/3/2026.
//

#include "Item.h"
#include <ctime>
#include <iostream>

Item::Item() {

}

void Item::setItemName(string item_name) {
    ItemName = item_name;
}

void Item::setItemQuant(int item_quantity) {
    ItemQuant = item_quantity;
}

void Item::setItemDesc(string item_desc) {
    ItemDesc = item_desc;
}

int Item::getItemId() {
    return ItemId;
}

string Item::getItemName() {
    return ItemName;
}

int Item::getItemQuant() {
    return ItemQuant;
}

string Item::getItemDesc() {
    return ItemDesc;
}

time_t Item::getCreatedOn() {
    return created_on;
}