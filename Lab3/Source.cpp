#include "Panel.h"
#include <Windows.h>

void termFunc() {
	cout << "Функция termFunc() вызвана функцией terminate().\n";
	exit(-1);
}

int main()
{
	Hospital hospital;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set_terminate(termFunc);
	while (true)
	{
		ShowPanel(&hospital);
	}
	return 0;
}