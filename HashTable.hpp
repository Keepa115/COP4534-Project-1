/***************************************************************
  Student Name: Jerome Ball
  File Name: HashTable.hpp
  Assignment number: Project 1

  This file holds the HashTable class which will contain an array of Node pointers.
  The HashTable class will be used to store and retrieve encrypted passwords for users.

  All functions are declared but are implemented in HashTable.cpp.
***************************************************************/

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "Node.hpp"

class HashTable {
private:
    Node** table;
    int size;
public:
    //Constructor and Destructor
    HashTable(int size);
    ~HashTable();

    //Methods
    void insert(const string& userid, const string& encryptedPassword);
    string find(const string& userid) const;
    int hash(const string& userid) const;

};
#endif // HASHTABLE_HPP