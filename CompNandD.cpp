/* Даны натуральное число n и вещественные числа
d1, d2, …, d8. Верно ли, что произведение вещественных
чисел больше n? */

#include <iostream>
#include <cassert>

using namespace std;

double calculateProd(double numbers[], int size) {
	double Prod = 1.0;
	for (int i = 0; i < size; i++) {
		Prod *= numbers[i];
	}
	return Prod;
}

void Test1() {
	double numbers[] = { 2,2,2,2,2,2,2,2 };
	assert(calculateProd(numbers, 8) == 256);
	cout << "Тест 1 пройден успешно" << endl;
}

void Test2() {
	double numbers[] = { 0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5 };
	assert(calculateProd(numbers, 8) == 0.00390625);
	cout << "тест 2 пройден успешно" << endl;

}

void Test3() {
	double numbers[] = { 0,5,5,5,1,1,1,1 };
	assert(calculateProd(numbers, 8) == 0);
	cout << "Тест 3 пройден успешно" << endl;
}

void Test4() {
	double numbers[] = { 2,4,2,2,4,2,2,2 };
	assert(calculateProd(numbers, 8) > 1000);
	assert((calculateProd(numbers, 8) > 3000) == false);
	cout << "Тест 4 пройден успешно" << endl;
}

void Test5() {
	double numbers[] = { 1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0 };
	assert(calculateProd(numbers, 8) == 1);
	assert((calculateProd(numbers, 8) > 1) == false);
	cout << "Тест 5 пройден успешно" << endl;
}

void RunAllTest() {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	cout << "все тесты выполнены успешно" << endl;
}

int main() {
	setlocale(LC_ALL, "russian");
	int choice;
	cout << "1 - Программа, 2 - Тесты:";
	cin >> choice;
	if (choice == 2) {
		RunAllTest();
		return 0;
	}
	else if (choice == 1) {
		int n;
		const int size = 8;
		double numbers[size];

		cout << "Введите n" << endl;
		cin >> n;

		if (n < 1) {
			cout << "Ошибка: число должно быть натуральным (>= 1)" << endl;
			return 1;
		}
		cout << "Введите " << size << " вещественнных чисел" << endl;
		for (int i = 0; i < size; i++)
			cin >> numbers[i];
		double prod = calculateProd(numbers, size);
		cout << "Произведение = " << prod << endl;
		if (prod > n) cout << "Верно: произведение больше " << n << endl;
		else cout << "Неверно: произведение не больше " << n << endl;
	}
	else cout << "неверный выбор" << endl;
	return 0;
}