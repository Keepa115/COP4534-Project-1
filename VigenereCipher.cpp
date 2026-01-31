/***************************************************************
  Student Name: Jerome Ball
  File Name: VigenereCipher.cpp
  Assignment number: Project 1

  This file implements the Vigenere cipher encryption function.
***************************************************************/

#include "VigenereCipher.hpp"
using namespace std;

string encrypt(const string& plaintext, const string& key) {
    string ciphertext = plaintext;
    for (size_t i = 0; i < plaintext.length(); ++i) {
        int shift = key[i % key.length()] - 'a';
        ciphertext[i] = ((plaintext[i] - 'a' + shift) % 26) + 'a';
    }
    return ciphertext;
}