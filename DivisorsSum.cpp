/* Найти все целые числа из промежутка от 100 до
300, у которых сумма делителей равна 50.  */


#include <iostream>
#include <cassert>

using namespace std;

int SumOfDiv(int n) {//функция для назождения суммы делителей числа n
	int sum = 0;
	for (int j = 1; j < n; j++) {
		if (n % j == 0) {
			sum += j;
		}
	}
	return sum;
}

void TestSumOfDiv() {
	assert(SumOfDiv(6) == 6);
	assert(SumOfDiv(12) == 16);
	assert(SumOfDiv(28) == 28);
	assert(SumOfDiv(13) == 1);
	assert(SumOfDiv(1) == 0);
	cout << "Тест 1 пройжен усппешно" << endl;
}

void TestOriginalTask() {//тестирования оригинального уловия
	cout << "Проверка исхожного задания с диапазоном 100-300 и суммой 50" << endl;
	int count = 0;
	for (int i = 100; i <= 300; i++) {
		if (SumOfDiv(i) == 50) {
			count++;
		}
	}
	assert(count == 0);
	cout << "найдено чисел: " << count << endl;
	cout << "Тест 2 пройжен упсещно" << endl;
}

void Test1to30() {
	cout << "Проверка диапащона 1-30" << endl;

	int count = 0;
	int FirstDivSum = -1;
	for (int i = 1; i <= 30; i++) {
		if (SumOfDiv(i) == 6) {
			if (FirstDivSum == -1) FirstDivSum = i;
			count++;
		}
	}
	assert(count == 2);
	assert(FirstDivSum == 6);
	cout << "Найдено " << count << " чисел, первое - " << FirstDivSum << endl;
	cout << "Тест 3 пройден успешно" << endl;
}

void TestBorder() {
	cout << "Проверка граничных случаев" << endl;
	assert(SumOfDiv(28) == 28);
	int count = 0;
	for (int i = 300; i < 100; i++) {
		if (SumOfDiv(i) == 50) count++;
	}
	assert(count == 0);
	assert(SumOfDiv(1) == 0);
	int countIf1 = 0;
	for (int i = 1; i <= 10; i++) {
		if (SumOfDiv(i) == 0) countIf1++;
	}
	assert(countIf1 == 1);
	cout << "тест 4 выполнен успешно" << endl;
}

void TestSimpleNum() {
	cout << "проверка простыз чсиел" << endl;
	assert(SumOfDiv(17) == 1);
	assert(SumOfDiv(19) == 1);
	cout << "Тест 5 пройжен успешно" << endl;
}

void RunAllTests() {
	TestSumOfDiv();
	TestOriginalTask();
	Test1to30();
	TestBorder();
	TestSimpleNum();
	cout << "все тесты успешно пройдены" << endl;
}

int main() {
	setlocale(LC_ALL, "russian");
	int choice;
	cout << "1 - Запустить поиск чисел, 2 - Запустить тесты" << endl;
	cin >> choice;
	if (choice == 1) {
		int start, end, expSum;
		cout << "Введите диапазон через пробел" << endl;
		cin >> start >> end;
		cout << "Введие нуджную сумму делителей" << endl;
		cin >> expSum;
		bool found = false;
		for (int i = start; i <= end; i++) {
			if (SumOfDiv(i) == expSum) {
				cout << i << " ";
				found = true;
			}
		}
		if (!found) cout << "Такиз чсиел нет" << endl;
	}
	else if (choice == 2) RunAllTests();
	else cout << "неверный выбор" << endl;

	return 0;
}
