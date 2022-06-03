#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace System;
using namespace System::Windows::Forms;
std::string& Convert_String_to_string(String^ s, std::string& os); //конвертируем System::string^ в std::string
String^ Convert_string_to_String(std::string& os, String^ s); //конвертируем std::string в System::string^
std::string Convert_String_to_string(String^ s); //конвертируем System::string^ в std::string
String^ Convert_string_to_String(std::string& os); //конвертируем std::string в System::string^
System::String^ Convert_char_to_String(char* ch); //конвертируем char* в System::string^
char* Convert_String_to_char(System::String^ string); //конвертируем System::string^ в char*
bool isInputValid(int var, int leftBorder, int rightBorder, int errorNum);
bool isInputValid(double var, double leftBorder, double rightBorder, int errorNum);
long double fact(int N);
std::string getVectorInt(std::vector<int> vec, std::string name);