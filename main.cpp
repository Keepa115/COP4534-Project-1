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
#include "FILEManager.hpp"
#include "VigenereCipher.hpp"

#include <random>
#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>

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

//shifts first character by 1 to make it incorrect
static string modifyPassword(const string& password) {
    if(password.empty()) return password;
    string modifiedPassword = password;
    if(modifiedPassword[0] == 'z')
        modifiedPassword[0] = 'a';
    else
        modifiedPassword[0] = (modifiedPassword[0] - 'a' + 1) % 26 + 'a';
    return modifiedPassword;
}

static void printHeader(const string& title){
    cout << "\n" << title << ":\n";
    cout << left << setw(15) << "Userid" 
         << setw(20) << "Password(given)" 
         << setw(20) << "Password(table)" 
         << "Result\n";
    cout << string(65, '-') << "\n";
}

int main(){
    const string namesFile = "names.txt";
    const string rawDataFile = "rawdata.txt";
    const string encryptedDataFile = "encrypteddata.txt";

    //read name
    vector<string> userIDs = readNames(namesFile);

    if(userIDs.empty()){
        cout << "names.txt is empty or missing.\n";
        return 1;
    }

    //use first userID as key
    const string cipherKey = userIDs[0]; 

    //create rawdata.txt
    vector<pair<string,string>> rawData;
    rawData.reserve(userIDs.size());
    for(const string& id : userIDs){
        rawData.push_back({id, generateRandomPassword()});
    }
    writeRawData(rawDataFile, rawData);

    //encrypt passwords and create encrypteddata.txt
    vector<pair<string,string>> encryptedData;
    encryptedData.reserve(rawData.size());
    for(const auto& pair : rawData){
         encryptedData.push_back({pair.first, encrypt(pair.second, cipherKey)});
    }
    writeEncryptedData(encryptedDataFile, encryptedData);

    //add encrypted data to hashtable
    HashTable table(101);
    for(const auto& pair : encryptedData){
        table.insert(pair.first, pair.second);
    }

    //test if encrypted passwords are correct
    vector<pair<string,string>> testData = readRawData(rawDataFile);
    //tests all names
    vector<int> testIndex = {0,1,2,3,4};

    printHeader("Legal");
    for(int index : testIndex){
        if(index >= (int)testData.size()) continue;

        const string& userid = testData[index].first;
        const string& givenPassword = testData[index].second;

        string encryptedPassword = encrypt(givenPassword, cipherKey);
        string tablePassword = table.find(userid);

        string result = (encryptedPassword == tablePassword) ? "match" : "no match";
        cout << left << setw(15) << userid 
             << setw(20) << givenPassword 
             << setw(20) << tablePassword 
             << result << "\n";
    }

    printHeader("Illegal");
    for(int index : testIndex){
        if(index >= (int)testData.size()) continue;

        const string& userid = testData[index].first;
        const string& givenPassword = modifyPassword(testData[index].second);

        string encryptedPassword = encrypt(givenPassword, cipherKey);
        string tablePassword = table.find(userid);

        string result = (encryptedPassword == tablePassword) ? "match" : "no match";
        cout << left << setw(15) << userid 
             << setw(20) << givenPassword 
             << setw(20) << tablePassword 
             << result << "\n";
    }

    return 0;
}

