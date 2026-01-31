/***************************************************************
  Student Name: Jerome Ball
  File Name: Node.hpp
  Assignment number: Project 1

  This file holds the Node class which will contain the userid as well as
  encrypted passwords created by the VigenereCipher class. This class will be used
  for the linked list implementation in the HashTable class.
***************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include <string>
using namespace std;

class Node {
public:
    string userid;
    string encryptedPassword;
    Node* next;

    Node(const string& userid, const string& encryptedPassword){
        this->userid = userid;
        this->encryptedPassword = encryptedPassword;
        this->next = nullptr;
    }
};

#endif // NODE_HPP