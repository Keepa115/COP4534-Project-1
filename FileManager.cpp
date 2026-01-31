/***************************************************************
  Student Name: Jerome Ball
  File Name: FileManager.cpp
  Assignment number: Project 1

  This file implements file management functions for reading and writing data.
***************************************************************/

#include "FileManager.hpp"
#include <fstream>
using namespace std;

vector<string> readNames(const string& filename) {
    vector<string> names;
    ifstream file(filename);
    if (file.is_open()) {
        string name;
        while (file >> name) {
            names.push_back(name);
            string dummy;
            getline(file, dummy); // Skip the rest of the line (numbers)
        }
        file.close();
    }
    return names;
}

void writeRawData(const string& filename, const vector<pair<string, string>>& data) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& pair : data) {
            file << pair.first << " " << pair.second << "\n";
        }
        file.close();
    }
}

void writeEncryptedData(const string& filename, const vector<pair<string, string>>& data) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& pair : data) {
            file << pair.first << " " << pair.second << "\n";
        }
        file.close();
    }
}

vector<pair<string, string>> readRawData(const string& filename) {
    vector<pair<string, string>> data;
    ifstream file(filename);
    if (file.is_open()) {
        string userid, password;
        while (file >> userid >> password) {
            data.push_back({userid, password});
        }
        file.close();
    }
    return data;
}