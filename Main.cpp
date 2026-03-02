//
// Created by Noel Mehari on 2/28/26.
//
//
// Created by Noel Mehari on 2/25/26.
//
#include <mysqlx/xdevapi.h>
#include "User.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <string_view>
#include <cctype>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::cerr;
using std::isspace;


void PasswordValidation() {
    cout <<
        "Password must be between 10-50 characters\n"
        "Password must contain at least one number\n"
        "Password must contain at least one uppercase letter\n"
        "Password must contain at least one lowercase letter\n"
        "Enter password here: ";
}


int main() {
    try {
        mysqlx::Session session("127.0.0.1", 33060, "root", "noelmehari1");

        session.sql("CREATE DATABASE IF NOT EXISTS PantryPal").execute();
        session.sql("USE PantryPal").execute();

        session.sql(
            "CREATE TABLE IF NOT EXISTS User ("
            "  Userid INT AUTO_INCREMENT PRIMARY KEY,"
            "  Username VARCHAR(255) NOT NULL,"
            "  created_on TIMESTAMP DEFAULT CURRENT_TIMESTAMP,"
            "  Email VARCHAR(255) UNIQUE NOT NULL,"
            "  Password VARCHAR(50) NOT NULL"
            ")"
        ).execute();

        mysqlx::SqlResult result =
            session.sql("SELECT Userid, Username, created_on, Email, Password "
                        "FROM User "
                        "ORDER BY Userid DESC LIMIT 1")
                   .execute();


        auto row = result.fetchOne();
        if (row) {
            std::cout << "Wrote row: Userid=" << int(row[0])
                      << ", Username=" << std::string(row[1])
                      << ", created_on=" << std::string(row[2])
                      << ",Email=" <<std::string(row[3])
                      << ",Password=" << std::string(row[4])
                      << std::endl;
        }

        // Quick sanity check that SQL works:
        session.sql("SELECT 1").execute();

        std::cout << "Connected successfully!" << std::endl;

        session.close();
    }


    catch (const mysqlx::Error &err) {
        std::cerr << "Connection error: " << err.what() << std::endl;
    }


    bool validpassword = false;
    bool validEmail = false;
    char UsersResponse;
    bool UsingApp = true;
    string Username, Email, Password;


    while (UsingApp) {

        cout << "Welcome to PantryPal" << endl;
        cout << "Would you like to create an account? (Y/N)" << endl;
        cin >> UsersResponse;
        if ((UsersResponse == 'Y') || (UsersResponse == 'y')) {
            cout << "Please create a username (Maximum characters is 254):" << endl;
            cin >> Username;
            while (Username.length() > 254) {
                cout << "Invalid username" << endl;
                cout << "Please create a username (Maximum characters is 254): ";
                cin >> Username;
            }


            PasswordValidation();
            cin >> Password;

            while (!validpassword) {
                bool hasDigit = false;
                bool hasUpper = false;
                bool hasLower = false;

                if (Password.length() < 10 || Password.length() > 50) {
                    validpassword = false;
                } else {

                    for (size_t i = 0; i < Password.size(); i++) {
                        if (isdigit(Password[i]))  hasDigit = true;
                        if (isupper(Password[i]))  hasUpper = true;
                        if (islower(Password[i]))  hasLower = true;}

                    validpassword = hasDigit && hasUpper && hasLower;
                }

                if (!validpassword) {
                    cout << "Please enter a valid password: ";
                    cin >> Password;}
            }



        cout << "Please enter your email: " << endl;
        cin >> Email;

        while (!validEmail) {

            validEmail = true;


            if (Email.length() > 254) {
                validEmail = false;}


            if (count(Email.begin(), Email.end(), '@') != 1) {
                validEmail = false;}

            if (Email.find('.') == -1) {
                validEmail = false;}


            size_t atPos = Email.find('@');
            if (atPos == 0 || atPos == -1) {
                validEmail = false;}

            for (size_t i = 0; i < Email.size(); i++) {
                if (isspace(Email[i])) {
                    validEmail = false;
                    break;}
            }

            if (validEmail) {
                if (!(Email.ends_with("@gmail.com") ||
                      Email.ends_with("@yahoo.com") ||
                      Email.ends_with("@hotmail.com") ||
                      Email.ends_with("@outlook.com"))) {

                    validEmail = false;}
            }

            if (!validEmail) {
                cout << "Invalid email\n";
                cout << "Valid email example: johnsmith@outlook.com\n";
                cout << "Please enter your email: ";
                cin >> Email;}
        }

            //mysqlx::Session session("127.0.0.1", 33060, "root", "noelmehari1");

            //Create Account and add to database later

            cout << "Account created successfully!" << endl;
            cout << "Welcome to The Pantry Pal: " << Username << endl;

      UsingApp = false;
    }


else if (UsersResponse == 'N' || UsersResponse == 'n') {
    while (UsingApp) {
        cout << "Would you like to log into an existing account (Y/N)";
        cin >> UsersResponse;
        if (UsersResponse == 'Y' || UsersResponse == 'y') {
            cout << "Please enter your email: ";
            cin >> Email;

            //mysqlx::Session session("127.0.0.1", 33060, "root", "noelmehari1");

            //log into existing account and do later


            cout << "\nPlease enter your password: ";
            cin >> Password;

            cout << "Account logged in successfully!" << endl;
            cout << "Welcome back to The Pantry Pal: " << Username << endl;

            UsingApp = false; //change later
        }
        else if (UsersResponse == 'N' || UsersResponse == 'n') {
            UsingApp = false;
        }
    }
}       else {UsingApp = false;}
}




    return 0;
};