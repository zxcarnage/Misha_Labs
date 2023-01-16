#include "Panel.h"
#include <Windows.h>

int main()
{
	Transaction<File> transaction;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		ShowPanel(&transaction);
	}
	return 0;
}