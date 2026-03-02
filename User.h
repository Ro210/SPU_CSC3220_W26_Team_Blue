//
// Created by Noel Mehari on 2/25/26.
//

#ifndef SPU_CSC3220_W26_TEAM_BLUE_TESTING_H
#define SPU_CSC3220_W26_TEAM_BLUE_TESTING_H
#endif //SPU_CSC3220_W26_TEAM_BLUE_TESTING_H

#include <string>
#include <ctime>
using std::string;


class User {

private:
    int UserId;
    time_t created_on;
    string Password;

public:
    User();
    string Username;
    string Email;
    void setEmail(string email);
    void setPassword(string password);
    void setUsername(string username);
    int getUserId();
    time_t getCreated_on();
    string getPassword();
    string getUsername();
    string getEmail();

};

