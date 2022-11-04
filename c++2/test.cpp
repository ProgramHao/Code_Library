#include"string.h"

int main()
{
	try
	{
		bit::test_string1;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}