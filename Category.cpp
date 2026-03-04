//
// Created by Linh Bui on 3/3/2026.
//

#include "Category.h"
#include <string>
#include <iostream>

Category::Category() {

}

int Category::getCatId() {
    return CatId;
}
void Category::setCatName(string catName) {
    CatName = catName;
}

string Category::getCatName() {
    return CatName;
}