#include "pointer_mode.h"

using namespace std;

void pointerMode()
{
	char INPUT_FILE[MAXSIZE];
	enterNameOfInputFile(INPUT_FILE);

	char OUTPUT_FILE[MAXSIZE];
	enterNameOfOutputFile(OUTPUT_FILE);

	char file_mode[2];
	chooseOpenMode(file_mode);

	enterInput(INPUT_FILE, file_mode);
	changeOutput(INPUT_FILE, OUTPUT_FILE);
	outputText(INPUT_FILE, OUTPUT_FILE);
}

void enterNameOfInputFile(char INPUT_FILE[MAXSIZE])
{
	printf("Enter name of input file: ");
	scanf("%s", INPUT_FILE);
}

void enterNameOfOutputFile(char OUTPUT_FILE[MAXSIZE])
{
	printf("Enter name of output file: ");
	scanf("%s", OUTPUT_FILE);
}

void chooseOpenMode(char* file_mode)
{
	printf("Choose mode for open file[enter \"a\" or \"w\"]: ");
	scanf("%s", file_mode);
}

int getWordLength(int i, char* arr)
{
	int length = 0;

	for (length; arr[i] != '\n' && arr[i] != '.' && arr[i] != ',' && arr[i] != ' ' && arr[i] != '\0' && arr[i] != EOF; length++, i++);

	return (length);
}

void enterInput(char INPUT_FILE[MAXSIZE], char* file_mode)
{
	FILE* file_in = fopen(INPUT_FILE, file_mode);
	if (file_in == NULL)
	{
		cout << "Can`t open file!\n";
		return;
	}
	
	char s[MAXSIZE];
	while (getchar() != '\n');

	cout << "\n\nEnter text: ";

	while (true)
	{
		fgets(s, MAXSIZE, stdin);
		

		if (s[0] == '\n' || s[1] == '\0')
			break;

		fputs(s, file_in);

		char s[MAXSIZE];
	}

	
	fclose(file_in);
}

void changeOutput(char INPUT_FILE[MAXSIZE], char OUTPUT_FILE[MAXSIZE])
{
	FILE* file_in = fopen(INPUT_FILE, "r");
	if (file_in == NULL)
	{
		cout << "Can`t open file!\n";
		return;
	}
	FILE* file_out = fopen(OUTPUT_FILE, "w");

	char s[MAXSIZE];

	int global_space_counter = 0,
		global_dot_counter = 0,
		global_comma_counter = 0,
		global_word_counter = 0;

	while (fgets(s, MAXSIZE, file_in))
	{
		writeOutput(s, &global_space_counter, &global_dot_counter, &global_comma_counter, &global_word_counter, OUTPUT_FILE);
	}

	fclose(file_out);

	file_out = fopen(OUTPUT_FILE, "a");

	fprintf(file_out, "Number of deleted words - %d\n", global_word_counter);
	fprintf(file_out, "Number of deleted spaces - %d\n", global_space_counter);
	fprintf(file_out, "Number of deleted commas - %d\n", global_comma_counter);
	fprintf(file_out, "Number of deleted dots - %d\n", global_dot_counter);

	fclose(file_out);
	fclose(file_in);
}

void writeOutput(char* arr, int *global_space_counter, int *global_dot_counter, int *global_comma_counter, int *global_word_counter, char OUTPUT_FILE[MAXSIZE])
{
	char new_arr[MAXSIZE];

	int space_counter = 0,
		dot_counter = 0,
		comma_counter = 0,
		word_counter = 0;
	int i;
	int word_length;

	for (i = 0; arr[i] != '\n'; i++)
	{
		if (arr[i] == ' ')
		{
			space_counter += countSpace(&i, arr);
			new_arr[i - sumCounters(space_counter, dot_counter, comma_counter, word_counter)] = ' ';
		} else
		if (arr[i] == '.')
		{
			dot_counter += countDot(&i, arr);
			new_arr[i - sumCounters(space_counter, dot_counter, comma_counter, word_counter)] = '.';
		} else
		if (arr[i] == ',')
		{
			comma_counter += countComma(&i, arr);
			new_arr[i - sumCounters(space_counter, dot_counter, comma_counter, word_counter)] = ',';
		}
		/*else
		{
			new_arr[i - sumCounters(space_counter, dot_counter, comma_counter)] = arr[i];
		}*/
		else if ((word_length = getWordLength(i, arr)) > 1)
		{
			for (int j = 0; j < word_length; j++)
			{
				new_arr[i - sumCounters(space_counter, dot_counter, comma_counter, word_counter)] = arr[i];
				i++;
			}
			i--;
		}
		else if (arr[i] != '\n' && arr[i] != '\0')
		{
			word_counter++;
		}
	}
	new_arr[i - sumCounters(space_counter, dot_counter, comma_counter, word_counter)] = '\n';
	new_arr[i - sumCounters(space_counter, dot_counter, comma_counter, word_counter) + 1] = '\0';

	*global_space_counter += space_counter;
	*global_dot_counter += dot_counter;
	*global_comma_counter += comma_counter;
	*global_word_counter += word_counter;

	FILE* file_out = fopen(OUTPUT_FILE, "a");
	if (file_out == NULL)
	{
		cout << "Can`t open file!\n";
		return;
	}
	fputs(new_arr, file_out);
	fclose(file_out);
}

int sumCounters(int space, int dot, int comma)
{
	return (space + dot + comma);
}
int sumCounters(int space, int dot, int comma, int word)
{
	return (space + dot + comma + word);
}

int countSpace(int* length, char* arr)
{
	int counter = 0;

	for (counter; arr[*length + 1] == ' '; (*length)++, counter++);

	return counter;
}

int countDot(int* length, char* arr)
{
	int counter = 0;

	for (counter; arr[*length + 1] == '.'; (*length)++, counter++);

	return counter;
}

int countComma(int* length, char* arr)
{
	int counter = 0;

	for (counter; arr[*length + 1] == ','; (*length)++, counter++);

	return counter;
}

void outputText(char INPUT_FILE[MAXSIZE], char OUTPUT_FILE[MAXSIZE])
{
	char s[MAXSIZE];

	FILE* file_in = fopen(INPUT_FILE, "r");
	if (file_in == NULL)
	{
		cout << "Can`t open file!\n";
		return;
	}

	printf("----------");
	printf("INPUT FILE");
	printf("----------");

	while (fgets(s, MAXSIZE, file_in))
	{
		fputs(s, stdout);
		char s[MAXSIZE];
	}

	fclose(file_in);

	FILE* file_out = fopen(OUTPUT_FILE, "r");
	if (file_in == NULL)
	{
		cout << "Can`t open file!\n";
		return;
	}

	printf("----------");
	printf("OUTPUT FILE");
	printf("----------");

	while (fgets(s, MAXSIZE, file_out))
	{
		fputs(s, stdout);
		char s[MAXSIZE];
	}

	fclose(file_out);
}







//void enterInput(FILE* file)
//{
//
//	file = fopen(INPUT_FILE, "w");
//
//	cout << "\n\nEnter text: ";
//	char s[MAXSIZE];
//	fflush(stdin);
//	while (fgets(s, MAXSIZE, stdin))
//	{
//		if (s[0] == '\n' || s[1] == '\0')
//			break;
//
//		char s[MAXSIZE];
//		fflush(stdin);
//		//printf("s = ", s);
//		fputs(s, file);
//	}
//	/*char* text = new char[MAXSIZE];
//	while (true)
//	{
//		cin.getline(text, MAXSIZE);
//		if (text[0] == '\n' || text[0] == '\0')
//			break;
//		fprintf(file, "%s\n", text);
//	}*/
//
//	//delete[] text;
//
//	fclose(file);
//}
//
//void copyText(FILE* file)
//{
//	file = fopen(INPUT_FILE, "r");
//	FILE* file1 = fopen(OUTPUT_FILE, "w");
//	char s[MAXSIZE];
//
//	while (fgets(s, MAXSIZE, file) != NULL)
//	{
//		fputs(s, file1);
//	}
//	//fread(s, sizeof(s), 1, file);//
//	//while (fwrite(s, sizeof(s), 1, file1) != EOF);
//
//
//	fclose(file1);
//	fclose(file);
//}
//
//void deleteSingleLetters(FILE* in_file)
//{
//	in_file = fopen(INPUT_FILE, "r");
//	FILE* out_file = fopen(OUTPUT_FILE, "w");
//
//	int r;
//	char s[MAXSIZE];
//	/*while (!(feof(file)))
//	{
//		fgets(s, 256, file);
//		for (int i = 1; i < strlen(s); i++)
//				{
//					if (s[i - 1] == ' ' || s[i - 1] == ',' || s[i - 1] == '.' || s[i - 1] == '\n' && s[i + 1] == ' ' || s[i + 1] == ',' || s[i + 1] == '.' || s[i + 1] == '\n')
//					{
//						for (int j = i; j < strlen(s) - 1; j++)
//							s[j] = s[j + 1];
//					}
//
//				}
//				printf("s = %s", s);
//	}*/
//
//	/*while (fgets(s, 256, file) != NULL)
//	{
//		while (fscanf(file, "%s", s) != '\n')
//		if (getWordSize(s, MAXSIZE) > 1)
//		{
//
//		}
//	}*/
//
//	while (!feof(in_file))
//	{
//		fscanf(in_file, "%s", s);
//		if (getWordSize(s, MAXSIZE) == 1)
//			continue;
//		fprintf(out_file, "s", s);
//
//	}
//
//
//	//checkLengthWord();
//
//	fclose(out_file);
//	fclose(in_file);
//}




//void enterInputTwo(FILE* file_in)
//{
//	file_in = fopen(INPUT_FILE, "w");
//	FILE* file_out = fopen(OUTPUT_FILE, "w");
//
//	cout << "\n\nEnter text: ";
//	char s[MAXSIZE];
//	fflush(stdin);
//	/*while (true)
//	{*/
//	getWordSizeTwo(s, MAXSIZE);
//
//	/*if (s[0] == '\n' || s[1] == '\0')
//		break;*/
//
//		//fputs(s, file_in);
//
//		/*char s[MAXSIZE];
//		fflush(stdin);*/
//		//printf("s = ", s);
//
//	//}
//
//	fclose(file_out);
//	fclose(file_in);
//}
//
//char* getWordSizeTwo(char* arr, int max)
//{
//	char cymbol,
//		new_arr[MAXSIZE];
//	int length,
//		space_counter = 0,
//		dot_counter = 0,
//		comma_counter = 0;
//
//	for (length = 0; (cymbol = getchar()) != EOF && cymbol != '\n' && cymbol != '.' && cymbol != ',' && cymbol != ' '; length++)
//	{
//		arr[length] = cymbol;
//	}
//	//word[length] = '\0';
//
//	if (cymbol == ' ')
//	{
//		space_counter += countSpace(&length, arr);
//		new_arr[length] = ' ';
//	}
//	new_arr[length] = '\0';
//
//	FILE* file_out = fopen(OUTPUT_FILE, "w");
//	fprintf(file_out, "%s", new_arr);
//	fclose(file_out);
//
//	return new_arr;
//}