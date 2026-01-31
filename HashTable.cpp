/***************************************************************
  Student Name: Jerome Ball
  File Name: HashTable.cpp
  Assignment number: Project 1

  This file implements the HashTable class which will contain an array of Node pointers.
  The HashTable class will be used to store and retrieve encrypted passwords for users.
***************************************************************/

#include "HashTable.hpp"

class HashTable {
private:
    Node** table;
    int size;
public:
    //Constructor and Destructor
    HashTable(int size){
        this->size = size;
        table = new Node*[size];
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }

    ~HashTable(){
        for (int i = 0; i < size; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
        delete[] table;
    }
    
    //Methods
    void insert(const string& userid, const string& encryptedPassword){
        int index = hash(userid);
        Node* newNode = new Node(userid, encryptedPassword);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    string find(const string& userid) const{
        int index = hash(userid);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->userid == userid) {
                return current->encryptedPassword;
            }
            current = current->next;
        }
        return ""; // Return empty string if userid not found
    }
    int hash(const string& userid) const{
        int hashValue = 0;
        for (char ch : userid) {
            hashValue += static_cast<int>(ch);
        }
        return hashValue % size;
    }

};