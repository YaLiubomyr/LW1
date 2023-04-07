#pragma once
//#define INPUT_FILE "input.txt"
//#define OUTPUT_FILE "output.txt"
#include <fstream>
#include <iostream>
#include <string>
//#define MAXSIZE 256
using namespace std;

void streamMode();
void outputTextStream(string INPUT_FILE, string OUTPUT_FILE);

string enterNameOfInputFileStream();
string enterNameOfOutputFileStream();
//int getWordLengthStream(int i, string str);
string chooseOpenModeStream();

void enterInputFile(string INPUT_FILE, string file_mode);
void writeInOutputFile(string INPUT_FILE, string OUTPUT_FILE);

string deleteWords(string s, int* word_counter);
string deleteSymbols(string s, int* comma_counter, int* dot_counter, int* space_counter);
string deleteSymbol(string s, int* comma_counter, char symbol);

void printTitle(string title_name, string input_file_name);
void printLine(string title);
//void writeOutputStream(string str, int* global_space_counter, int* global_dot_counter, int* global_comma_counter, int* global_word_counter);
//
//int sumCountersStream(int space, int dot, int comma);
//int sumCountersStream(int space, int dot, int comma, int word);
//
//int countSpaceStream(int* length, string str);
//int countDotStream(int* length, string str);
//int countCommaStream(int* length, string str);
//
//void outputTextStream();