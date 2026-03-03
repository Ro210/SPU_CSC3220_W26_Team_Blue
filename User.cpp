//
// Created by Noel Mehari on 2/25/26.
//
#include "User.h"
#include <ctime>
#include <iostream>


User::User() {

}

void User::setEmail(string email) {
Email = email;
 }

void User::setPassword(string password) {
 Password = password;
 }

void User::setUsername(string username) {
Username = username;

 }

int User::getUserId() {
return UserId;
 }

time_t User::getCreated_on() {
return created_on;
 }

string User::getPassword() {
return Password;
 }

string User::getUsername() {
return Username;
 }

string User::getEmail() {
return Email;
 }


