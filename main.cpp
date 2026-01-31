/***************************************************************
  Student Name: Jerome Ball
  File Name: main.cpp
  Assignment number: Project 1

  This file demonstrates and facilitates the use of hash tables and the vigenere cipher
  to create a password management system. In its current state, it will only create
  random nine character passwords which will later be used for encryption and later
  testing.
***************************************************************/

#include "HashTable.hpp"
#include <random>
#include <iostream>

using namespace std;

string generateRandomPassword() {
    const string characters = "abcdefghijklmnopqrstuvwxyz";
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(0, characters.size() - 1);

    string password;
    for (int i = 0; i < 9; ++i) {
        password += characters[distribution(generator)];
    }
    return password;
}

int main(){
    string password = generateRandomPassword();
    cout << "Generated 9-letter password: " << password << endl;
    return 0;
}

