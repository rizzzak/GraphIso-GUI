#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace System;
using namespace System::Windows::Forms;
std::string& Convert_String_to_string(String^ s, std::string& os); //������������ System::string^ � std::string
String^ Convert_string_to_String(std::string& os, String^ s); //������������ std::string � System::string^
std::string Convert_String_to_string(String^ s); //������������ System::string^ � std::string
String^ Convert_string_to_String(std::string& os); //������������ std::string � System::string^
System::String^ Convert_char_to_String(char* ch); //������������ char* � System::string^
char* Convert_String_to_char(System::String^ string); //������������ System::string^ � char*
bool isInputValid(int var, int leftBorder, int rightBorder, int errorNum);
bool isInputValid(double var, double leftBorder, double rightBorder, int errorNum);
long double fact(int N);
std::string getVectorInt(std::vector<int> vec, std::string name);