#include "pointer_mode.h"
#include "stream_mode.h"
#include "general_functions.h"

int main(int argc, char* argv[])
{
	bool mode;

	if (!checkMode(argc, argv, &mode))
	{
		cout << "Incorrect input data!";
		return 0;
	}

	switch (mode)
	{
	case false:
		{
			cout << "You are working in FilePointer mode..." << endl << endl;
			pointerMode();
			break;
		}
	case true:
		{
			cout << "You are working in FileStream mode..." << endl << endl;
			streamMode();
			break;
		}
	}

	return 0;
}