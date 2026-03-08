//
// Created by Linh Bui on 3/3/2026.
//

#ifndef SPU_CSC3220_W26_TEAM_BLUE_CATEGORY_H
#define SPU_CSC3220_W26_TEAM_BLUE_CATEGORY_H
#endif //SPU_CSC3220_W26_TEAM_BLUE_CATEGORY_H

#include <string>
using std::string;

class Category {

private:
    int CatId;

public:
    Category();
    string CatName;
    int getCatId();
    void setCatName(string catName);
    string getCatName();

};