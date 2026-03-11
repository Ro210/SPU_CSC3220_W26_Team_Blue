//
// Created by Noel Mehari on 2/25/26.
//
#include "CurrentUser.h"
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>



CurrentUser::CurrentUser(string email, string password, string username, int user_id, string created_on) {
Email = email;
Password = password;
 Username = username;
 UserId = user_id;
 this->created_on = created_on;

}

void CurrentUser::ChangeEmail(string email) {
Email = email;
 }

void CurrentUser::ChangePassword(string password) {
 Password = password;
 }

void CurrentUser::ChangeUsername(string username) {
Username = username;

 }

int CurrentUser::getUserId() {
return UserId;
 }

string CurrentUser::getCreated_on() {

 return created_on;
}

string CurrentUser::getPassword() {
return Password;
 }

string CurrentUser::getUsername() {
return Username;
 }

string CurrentUser::getEmail() {
return Email;
 }


