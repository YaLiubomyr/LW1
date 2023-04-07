#include "stream_mode.h"

using namespace std;

void streamMode()
{
	string INPUT_FILE, OUTPUT_FILE;
	string file_mode;

	INPUT_FILE = enterNameOfInputFileStream();
	OUTPUT_FILE = enterNameOfOutputFileStream();

	file_mode = chooseOpenModeStream();

	enterInputFile(INPUT_FILE, file_mode);
	writeInOutputFile(INPUT_FILE, OUTPUT_FILE);
	outputTextStream(INPUT_FILE, OUTPUT_FILE);
}

string enterNameOfInputFileStream()
{
	string INPUT_FILE;
	cout << "Enter name of input file: ";
	cin >> INPUT_FILE;

	return INPUT_FILE;
}

string enterNameOfOutputFileStream()
{
	string OUTPUT_FILE;
	cout << "Enter name of output file: ";
	cin >> OUTPUT_FILE;

	return OUTPUT_FILE;
}

string chooseOpenModeStream()
{
	string file_mode;
	cout << "Choose mode for open file[enter \"a\" or \"w\"]: ";
	cin >> file_mode;

	while (file_mode != "w" && file_mode != "a")
	{
		cout << "You entered incorrect mode. Try again.[enter \"a\" or \"w\"]: ";
		cin >> file_mode;
		cout << "file_mode == " << file_mode;
	}

	return file_mode;
}

void enterInputFile(string INPUT_FILE, string file_mode)
{
	ofstream in_file;

	if (file_mode == "w")
	{
		in_file.open(INPUT_FILE);
	}
	else
	{
		in_file.open(INPUT_FILE, ios::app);
		if (!in_file)
		{
			cout << "Can`t open file!\n";
			return;
		}
	}

	cout << "\n\nEnter text: ";

	string s;
	cin.ignore();

	while (true)
	{
		getline(cin, s);
		if (s == "\0")
			break;

		in_file << s << endl;
	}

	in_file.close();
}

void writeInOutputFile(string INPUT_FILE, string OUTPUT_FILE)
{
	int global_space_counter = 0,
		global_dot_counter = 0,
		global_comma_counter = 0,
		global_word_counter = 0;

	ifstream in_file(INPUT_FILE);
	if (!in_file)
	{
		cout << "Can`t open file!\n";
		return;
	}
	ofstream out_file(OUTPUT_FILE);

	string s;

	while (!in_file.eof())
	{
		getline(in_file, s);
		s = deleteSymbols(s, &global_comma_counter, &global_dot_counter, &global_space_counter);
		s = deleteWords(s, &global_word_counter);
		out_file << s << endl;
	}

	out_file << "Number of deleted words - " << global_word_counter << endl;
	out_file << "Number of deleted spaces - " << global_space_counter << endl;
	out_file << "Number of deleted commas - " << global_comma_counter << endl;
	out_file << "Number of deleted dots - " << global_dot_counter << endl;

	out_file.close();
	in_file.close();
}

string deleteWords(string s, int* word_counter)
{
	int pos1 = 0,
		pos2 = 0;

	while (pos1 != string::npos)
	{

		pos2 = s.find_first_of(" .,\n\0", pos1 + 1);

		if (pos2 - pos1 == 2 || s.length() + pos2 - 1 == pos1)
		{
			s.erase(pos1 + 1, 1);
			pos1 = pos2 - 1;
			(*word_counter)++;
		}
		else
		{
			pos1 = pos2;
		}
	}
	return s;
}

string deleteSymbols(string s, int* comma_counter, int* dot_counter, int* space_counter)
{
	s = deleteSymbol(s, comma_counter, ',');
	s = deleteSymbol(s, dot_counter, '.');
	s = deleteSymbol(s, space_counter, ' ');

	return s;
}

string deleteSymbol(string s, int* counter, char symbol)
{
	int pos1 = 0,
		pos2 = 0;

	while (pos1 != string::npos)
	{
		pos2 = s.find(symbol, pos1 + 1);

		if (pos2 - pos1 == 1)
			{
				s.erase(pos1, 1);
				pos1 = pos2 - 1;
				(*counter)++;
			}
		else
		{
			pos1 = pos2;
		}
	}
	return s;
}

void outputTextStream(string INPUT_FILE, string OUTPUT_FILE)
{
	string s;

	ifstream in_file(INPUT_FILE);
	if (!in_file)
	{
		cout << "Can`t open file!\n";
		return;
	}

	printTitle("INPUT FILE - ", INPUT_FILE);

	while (getline(in_file, s))
	{
		cout << s << endl;
	}

	in_file.close();

	ifstream out_file(OUTPUT_FILE);
	if (!out_file)
	{
		cout << "Can`t open file!\n";
		return;
	}

	printTitle("OUTPUT FILE - ", OUTPUT_FILE);

	while (getline(out_file, s))
	{
		cout << s << endl;
	}

	out_file.close();
}

void printTitle(string title_name, string input_file_name)
{
	string title = title_name + input_file_name;

	printLine(title);
	cout << endl << title << endl;
	printLine(title);
	cout << endl;
}

void printLine(string title)
{
	for (int i = 0; i < title.length(); i++)
		cout << "-";
}










//string deleteSymbols(string s, int* comma_counter, int* dot_counter, int* space_counter)
//{
//	s = deleteSymbol(s, comma_counter, ',');
//	s = deleteSymbol(s, comma_counter, '.');
//	s = deleteSymbol(s, comma_counter, ' ');
//	//int pos1 = 0,
//	//	pos2 = 0;
//
//	//while (pos1 != string::npos)
//	//{
//	//	
//
//
//	//	//pos1 = s.find_first_of(" .,\n", pos1 + 1);
//
//	//	//pos2 = s.find_first_of(" .,\n\0", pos1 + 1);
//
//	//	//cout << "pos1 == " << pos1 << endl;
//	//	//cout << "pos2 == " << pos2 << endl;
//
//	//	//if (pos2 - pos1 == 2 || s.length() + pos2 - 1 == pos1)
//	//	//{
//	//	//	s.erase(pos1 + 1, 1);
//	//	//	pos1 = pos2 - 1;
//	//	//	(*word_counter)++;
//	//	//}
//	//	//else
//	//	//{
//	//	//	pos1 = pos2;
//	//	//}
//	//	///*if (pos2 - pos1 == 1)
//	//	//	s.erase(pos1, pos2);*/
//
//	//	//cout << "s == " << s << endl << endl;
//
//
//	//	/*if (pos1 == string::npos)
//	//		break;*/
//
//
//	//}
//	return s;
//}

//string deleteSymbols(string s, int* global_comma_counter, int* global_dot_counter, int* global_space_counter)

//int getWordLengthStream(int i, string str)
//{
//	string newstr;
//	/*int length = 0;
//	cout << "str2 = " << str << endl;
//	for (length; str[i] != '\n' && str[i] != '.' && str[i] != ',' && str[i] != ' ' && str[i] != '\0' && str[i] != EOF; length++, i++);
//	cout << "str3 = " << str << endl;*/
//	newstr = str.find_first_of(" ,.\n");
//	int length = newstr.length();
//	if (length > 1)
//		return (length);
//}
//
//void enterInputStream()
//{
//	ofstream file_in(INPUT_FILE);
//	ofstream file_out(OUTPUT_FILE);
//
//	int global_space_counter = 0,
//		global_dot_counter = 0,
//		global_comma_counter = 0,
//		global_word_counter = 0;
//
//	cout << "\n\nEnter text: ";
//	string s;
//	//cin.ignore();
//	while (true)
//	{
//		getline(cin, s);
//		cout << s << endl;
//		writeOutputStream(s, &global_space_counter, &global_dot_counter, &global_comma_counter, &global_word_counter);
//
//		/*if (s[0] == '\n' || s[1] == '\0')
//			break;*/
//		if (s[0] == '\0') 
//			break;
//
//		file_in << s;
//
//		string s;
//		cin.ignore();
//	}
//
//	file_out.close();
//
//	file_out.open(OUTPUT_FILE, ios::app);
//
//	file_out << "Number of deleted words - \n" << global_word_counter;
//	file_out << "Number of deleted spaces - \n" << global_space_counter;
//	file_out << "Number of deleted commas - \n" << global_comma_counter;
//	file_out << "Number of deleted dots - \n" << global_dot_counter;
//
//	file_out.close();
//	file_in.close();
//}
//
//void writeOutputStream(string str, int* global_space_counter, int* global_dot_counter, int* global_comma_counter, int* global_word_counter)
//{
//	string new_arr;
//
//	int space_counter = 0,
//		dot_counter = 0,
//		comma_counter = 0,
//		word_counter = 0;
//	int i;
//	int word_length;
//	cout << "str = " << str << endl;
//	for (i = 0; str[i] != '\n'; i++)
//	{
//		if (str[i] == ' ')
//		{
//			space_counter += countSpaceStream(&i, str);
//			new_arr[i - sumCountersStream(space_counter, dot_counter, comma_counter, word_counter)] = ' ';
//		}
//		else
//		if (str[i] == '.')
//		{
//			dot_counter += countDotStream(&i, str);
//			new_arr[i - sumCountersStream(space_counter, dot_counter, comma_counter, word_counter)] = '.';
//		}
//		else
//		if (str[i] == ',')
//		{
//			comma_counter += countCommaStream(&i, str);
//			new_arr[i - sumCountersStream(space_counter, dot_counter, comma_counter, word_counter)] = ',';
//		}
//		/*else
//		{
//			new_arr[i - sumCounters(space_counter, dot_counter, comma_counter)] = arr[i];
//		}*/
//		else if ((word_length = getWordLengthStream(i, str)) > 1)
//		{
//			cout << "i1 = " << i << endl;
//			for (int j = 0; j < word_length; j++)
//			{
//				new_arr[i - sumCountersStream(space_counter, dot_counter, comma_counter, word_counter)] = str[i];
//				cout << "new_arr1 = " << new_arr << endl;
//				cout << "i2 = " << i << endl;
//				i++;
//			}
//			i--;
//			cout << "i3 = " << i << endl;
//		}
//		else if (str[i] != '\n' && str[i] != '\0')
//		{
//			word_counter++;
//		}
//		cout << "new_arr = " << new_arr << endl;
//	}
//	/*new_arr[i - sumCountersStream(space_counter, dot_counter, comma_counter, word_counter)] = '\n';
//	new_arr[i - sumCountersStream(space_counter, dot_counter, comma_counter, word_counter) + 1] = '\0';*/
//
//	*global_space_counter += space_counter;
//	*global_dot_counter += dot_counter;
//	*global_comma_counter += comma_counter;
//	*global_word_counter += word_counter;
//
//	fstream file_out(OUTPUT_FILE, ios::app);
//	file_out << new_arr;
//	file_out.close();
//}
//
//
//void writeOutputStreamTwo(string str, int* global_space_counter, int* global_dot_counter, int* global_comma_counter, int* global_word_counter)
//{
//	int space_counter = 0,
//		dot_counter = 0,
//		comma_counter = 0,
//		word_counter = 0;
//
//	checkWords(str);
//}
//
//void checkWords(string str)
//{
//	int pos;
//	while (pos != str.rfind("\n"))
//	{
//		pos = str.find_first_of(" ,.\n");
//	}
//	
//}
//
//int sumCountersStream(int space, int dot, int comma)
//{
//	return (space + dot + comma);
//}
//int sumCountersStream(int space, int dot, int comma, int word)
//{
//	return (space + dot + comma + word);
//}
//
//int countSpaceStream(int* length, string str)
//{
//	int counter = 0;
//
//	for (counter; str[*length + 1] == ' '; (*length)++, counter++);
//
//	return counter;
//}
//
//int countDotStream(int* length, string str)
//{
//	int counter = 0;
//
//	for (counter; str[*length + 1] == '.'; (*length)++, counter++);
//
//	return counter;
//}
//
//int countCommaStream(int* length, string str)
//{
//	int counter = 0;
//
//	for (counter; str[*length + 1] == ','; (*length)++, counter++);
//
//	return counter;
//}
//
//void outputTextStream()
//{
//	string s;
//
//	ofstream file_in(INPUT_FILE);
//
//	printf("----------");
//	printf("INPUT FILE");
//	printf("----------");
//
//	while (getline(cin, s))
//	{
//		cout << s;
//		string s;
//	}
//
//	file_in.close();
//
//	ofstream file_out(OUTPUT_FILE);
//
//	printf("----------");
//	printf("OUTPUT FILE");
//	printf("----------");
//
//	while (getline(cin, s))
//	{
//		cout << s;
//		string s;
//	}
//
//	file_out.close();
//}