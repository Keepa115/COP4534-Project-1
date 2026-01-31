/***************************************************************
  Student Name: Jerome Ball
  File Name: VigenereCipher.hpp
  Assignment number: Project 1

  This file holds the VigenereCipher class which will be used to encrypt passwords.

  All functions are declared but are implemented in VigenereCipher.cpp.
***************************************************************/


#ifndef VIGENERECIPHER_HPP
#define VIGENERECIPHER_HPP

#include <string>
using namespace std;

string encrypt(const string& password, const string& key);

#endif // VIGENERECIPHER_HPP