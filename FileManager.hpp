/***************************************************************
  Student Name: Jerome Ball
  File Name: FileManager.hpp
  Assignment number: Project 1

  Manages read and write file operations.

  All functions are declared but are implemented in FileManager.cpp.
***************************************************************/

#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <vector>
#include <string>
using namespace std;

vector<string> readNames(const string& filename);
void writeRawData(const string& filename, const vector<pair<string,string>>& data);
vector<pair<string,string>> readRawData(const string& filename);
void writeEncryptedData(const string& filename, const vector<pair<string,string>>& data);
vector<pair<string,string>> readEncryptedData(const string& filename);

#endif // FILEMANAGER_HPP