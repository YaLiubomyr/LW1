#pragma once
#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
#include <string>
#include <iostream>
//#define INPUT_FILE "input.txt"
//#define OUTPUT_FILE "output.txt"
#define MAXSIZE 256
//using namespace std;

void pointerMode();

void enterNameOfInputFile(char INPUT_FILE[MAXSIZE]);
void enterNameOfOutputFile(char OUTPUT_FILE[MAXSIZE]);

void chooseOpenMode(char* file_mode);

int getWordLength(int length, char* word);

void enterInput(char INPUT_FILE[MAXSIZE], char* file_mode);

void changeOutput(char INPUT_FILE[MAXSIZE], char OUTPUT_FILE[MAXSIZE]);

void writeOutput(char* arr, int* global_space_counter, int* global_dot_counter, int* global_comma_counter, int* global_word_counter, char OUTPUT_FILE[MAXSIZE]);

int sumCounters(int space, int dot, int comma);
int sumCounters(int space, int dot, int comma, int word);

int countSpace(int* length, char* arr);
int countDot(int* length, char* arr);
int countComma(int* length, char* arr);

void outputText(char INPUT_FILE[MAXSIZE], char OUTPUT_FILE[MAXSIZE]);