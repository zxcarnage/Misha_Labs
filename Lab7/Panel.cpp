#include "Panel.h"

void Panel::CallCurrent(int answer)
{
	switch (answer)
	{
	case 1:
		_delivery.Order();
		break;
	case 2:
		_delivery.Delete();
		break;
	case 3:
		_delivery.Show();
		break;
	case 4:
		_delivery.Edit();
		break;
	case 5:
		exit(0);
		break;
	}
}

void Panel::ShowPanel()
{
	float answer;
	cout << "================= Выберите =================" << endl;
	cout << "1.Заказать доставку" << endl;
	cout << "2.Удалить заказ" << endl;
	cout << "3.Показать очередь" << endl;
	cout << "4.Редактировать заказ" << endl;
	cout << "5.Выйти" << endl;
	cout << "============================================" << endl;
	Input(&answer, " ответ", Answer, 5);
	system("cls");
	CallCurrent((int)answer);
}