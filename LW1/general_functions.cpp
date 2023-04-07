#include "general_functions.h"
using namespace std;

bool checkMode(int argc, char** argv, bool* mode)
{
	if (argc != 3)
		return false;

	string flag = argv[1];
	string check_mode = argv[2];

	if (flag != "-mode")
		return false;

	if (check_mode == "FilePointer")
	{
		*mode = false;
	}
	else if (check_mode == "FileStream")
	{
		*mode = true;
	}
	else
	{
		return false;
	}

	return true;
}

string enterNameOfFile()
{
	string name_of_file;
	cout << "Eneter name of file: ";
	cin >> name_of_file;
	return name_of_file;
}