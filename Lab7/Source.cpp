#include "Panel.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Panel panel;
	while (true)
	{
		panel.ShowPanel();
	}
	return 0;
}