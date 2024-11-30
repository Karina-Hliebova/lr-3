#include <iostream>
#include "windows.h"
#include <cmath>
using namespace std;

//If5.Дано три цілих числа. Знайти кількість додатних та від'ємних чисел в початковому наборі
void task_if5(); //завдання 1, декларація функції

// Дано координати точки на площині (х, у).
// Визначити, чи потрапляє точка в фігуру заданого кольору (або групу фігур)
// і вивести відповідне повідомлення.
void task_geom4(); //завдання 2, декларація функції

int main()
{
	SetConsoleOutputCP(1251);
	int menu;
	cout << "Номер завдання:";
	cin >> menu;
	// перемикання між завданнями
	switch (menu)
	{
	case 1: task_if5(); break; // Завдання 1
	case 2: task_geom4(); break; // Завдання 2
	default: cout << "Помилка! (Тільки 1,2)" << endl; // Повідомлення про помилку
	}
	system("pause");
	return 0;
}

// Завдання 1 реалізація
void task_if5()
{
	int a, b, c;
	cout << "**************** If 5 ****************" << endl;
	cout << "Введіть три цілих числа:"; // введення чисел
	cin >> a >> b >> c;
	int positiveCount = 0, negativeCount = 0; // ініціалізація змінних

	if (a > 0) positiveCount++; // перевірка кожного числа окремо
	if (a < 0) negativeCount++;
	if (b > 0) positiveCount++;
	if (b < 0) negativeCount++;
	if (c > 0) positiveCount++;
	if (c < 0) negativeCount++; 

	cout << "Кількість додатніх чисел:" << positiveCount << endl; // виведення результату
	cout << "Кількість від'ємних чисел:" << negativeCount << endl;
}

// Завдання 2, реалізація
void task_geom4()
{
	float x, y, r, a;
	const double pi = 3.141592;
	double theta_deg = 90; //центральний кут у градусах, утворений хордою
	cout << "**************** Point in geometry region 4 ****************" << endl;
	cout << "Введіть координати точки:"; //введення координат точки 
	cin >> x >> y;
	cout << "Введіть радіус кола:"; //введення радіуса кола
	cin >> r;
	cout << "Введіть сторону трикутника:"; //введення сторони трикутника
	cin >> a;

	float area_circle = pi * r * r; //обчислення площі кола 
	float cath_small_yell_tris = r / 4; //знаходимо відрізок жовтої частини на колі
	float dist_2_chord = r - cath_small_yell_tris; //обчислюємо відстань до хорди

	//знаходимо площу повної хорди
	//розкладаємо на зменшуване та від'ємник 
	double zmensh = r * r * acos(dist_2_chord / r);
	double vdmk = dist_2_chord * sqrt(r * r - dist_2_chord * dist_2_chord);

	double S_chord = zmensh - vdmk;

	double area_yellow = S_chord / 2; //знаходимо площу жовтої частини на колі
	float real_circle = area_circle - area_yellow; //знаходимо площу червоної частини кола

	if (r <= 0 || a <= 0) //перевірка коректності даних
		cout << "Повинно бути додатнім!";
	else {
		if (x >= 0 && y >= 0 && (x * x + y * y <= r * r)) {
			//перевірка на належність точки до 1-ї чверті кола
			cout << "Точка належить до 1-ї чверті." << endl; //виведення результатів
		}
		else if ((x <= 0 && y >= 0 && (x * x + y * y <= r * r)) && (x * x + y * y <= area_yellow)) {
			//перевірка на належність до 2-ї чверті
			cout << "Точка належить до 2-ї чверті." << endl; //виведення результатів 
		}
		else if (x <= 0 && y <= 0 && (x * x + y * y <= r * r)) {
			//перевірка на належність до 3-ї чверті
			cout << "Точка належить до 3-ї чверті." << endl; //виведення результатів  
		}
		else if (x >= 0 && y <= 0 && (x * x + y * y <= r * r)) {
			//перевірка на належність до 4-ї чверті кола
			cout << "Точка належить до 4-ї чверті." << endl; //виведення результатів
		}
		else {
			cout << "Точка не належить колу." << endl;
		}
	} 
	double L_chord = 2 * sqrt(r * r - dist_2_chord * dist_2_chord); //обчислення периметру фігури, яку утворює хорда
	double theta_rad = theta_deg * pi / 180; //переведення кута в радіани
	double L_arc = r * theta_rad; //обчислення довжини дуги
	double P_chord = (L_chord + L_arc) / 2; //обчислення периметру жовтої частини кола(фігури, яку утворює хорда)

	double perimeter = 2 * pi * r - P_chord; //обчислення периметру червоної частини кола

	cout << "Площа фігури:" << real_circle << endl; //виведення результату 
	cout << "Периметер фігури:" << perimeter << endl;
}
