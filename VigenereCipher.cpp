/***************************************************************
  Student Name: Jerome Ball
  File Name: VigenereCipher.cpp
  Assignment number: Project 1


  The VigenereCipher class will be used to encrypt passwords.
***************************************************************/

#include "VigenereCipher.hpp"
#include <string>
using namespace std;

class VigenereCipher {
public:
    static string encrypt(const string& password, const string& key) {
        string encryptedPassword;
        int keyLength = key.length();
        //cuts each character from the password and shifts according to the key
        for (size_t i = 0; i < password.length(); ++i) {
            char charPassword = password[i];
            char charKey = key[i % keyLength];
            char encryptedChar = ((charPassword - 'a') + (charKey - 'a')) % 26 + 'a';
            encryptedPassword += encryptedChar;
        }
        return encryptedPassword;
    }

};