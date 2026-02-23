#include <iostream>
#include <chrono>
#include <cassert>

using namespace std;
using namespace std::chrono;

long long withRecursive(int n) {
	if (n <= 1) {
		return n;
	}
	return withRecursive(n - 1) + withRecursive(n - 2);
}

long long Iterative(int n) {
	if (n <= 1) {
		return n;
	}
	long long ago2Step = 0;
	long long ago1Step = 1;
	long long current = 0;

	for (int i = 2; i <= n; i++) {
		current = ago2Step + ago1Step;
		ago2Step = ago1Step;
		ago1Step = current;
	}
	return current;
}

void TestFen() {
	cout << "Тестирование : " << endl;
	int AllTests = 5;
	int DoneTests = 0;

	{
		//тест 1 - стандартный
		int n = 0;
		long long expected = 0;
		long long resultRec = withRecursive(n);
		long long resultIter = Iterative(n);
		assert(resultRec == expected);
		cout << "n=0" << endl;
		cout << "  Рекурсия верно " << resultRec << endl;
		assert(resultIter == expected);
		cout << "  Итеративно верно " << resultIter << endl;
		DoneTests++;
	}

	{
		//тест 2 - стнажратный случай
		int n = 1;
		long long expected = 1;
		long long resultRec = withRecursive(n);
		long long resultIter = Iterative(n);
		assert(resultRec == expected);
		cout << "n=1" << endl;
		cout << "  Рекурсия верно " << resultRec << endl;
		assert(resultIter == expected);
		cout << "  Итеративно врено " << resultIter << endl;
		DoneTests++;
	}

	{
		//тест 3 
		int n = 5;
		long long expected = 5;
		long long resultRec = withRecursive(n);
		long long resultIter = Iterative(n);
		assert(resultRec == expected);
		cout << "n=5" << endl;
		cout << "  Рекурсия верно " << resultRec << endl;
		assert(resultIter == expected);
		cout << "  Итеративно врено" << resultIter << endl;
		DoneTests++;
	}

	{
		//тест 4
		int n = 10;
		long long expected = 55;
		long long resultRec = withRecursive(n);
		long long resultIter = Iterative(n);
		assert(resultRec == expected);
		cout << "n=10" << endl;
		cout << "  Рекурсия верно " << resultRec << endl;
		assert(resultIter == expected);
		cout << "  Итеративно верно " << resultIter << endl;
		DoneTests++;
	}

	{
		//тест 5
		int n = 15;
		long long resultRec = withRecursive(n);
		long long resultIter = Iterative(n);
		assert(resultRec == resultIter);
		cout << "n=15" << endl;
		cout << "  Результаты совпадают " << endl;
		DoneTests++;
	}
}

void TimeComprasion(int n) {
	cout << "Вычисление " << n << "-го числа Фибоначчи" << endl;
	auto StartRec = high_resolution_clock::now();
	long long ResultRec = withRecursive(n);
	auto EndRec = high_resolution_clock::now();
	auto DifferenceRec = duration_cast<milliseconds>(EndRec - StartRec).count();

	cout << "Результат с рекурсией: " << endl;
	cout << ResultRec << endl;
	cout << "Время : " << DifferenceRec << " мс" << endl;
	cout << endl;


	auto StartIter = high_resolution_clock::now();
	long long resultIter = Iterative(n);
	auto EndIter = high_resolution_clock::now();
	auto DifIter = duration_cast<milliseconds>(EndIter - StartIter).count();

	cout << "Результат бзе рекурсии, итеративно: " << endl;
	cout << resultIter << endl;
	cout << "Время: " << DifIter << endl;
	cout << endl;

	cout << "Сравнение: " << endl;//Реурсия всегда будет медленнее для чисел Фибоначчи
	if (DifferenceRec == 0 && DifIter == 0)
		cout << "Обе версии выполнились мгновенно" << endl;
	else if (DifIter == 0 && DifferenceRec > 0)
		cout << "Рекурсия медленнее (итерация выполнилась мгновенно)" << endl;
	else cout << "Рекурсия медленнее в " << DifferenceRec / DifIter << " раз" << endl;
}

int main() {
	setlocale(LC_ALL, "russian");
	int n;

	int choice;
	cout << "Что хотите сделать? 1 - Запустить программу, 2 - Запустить тесты" << endl;
	cin >> choice;
	if (choice == 1) {
		cout << "Введите номер числа Фибоначчи (n): ";
		cin >> n;

		if (n < 0) {
			cout << "Ошибка! n должно быть больше или равно 0" << endl;
			return 1;
		}

		if (n > 40) {
			cout << "ВНИМАНИЕ: При n > 40 рекурсивная версия может работать очень долго!" << endl;
			cout << "Хотите продолжить? (1 - да, 0 - нет): ";
			int choice;
			cin >> choice;
			if (choice == 0) {
				cout << "Программа завершена!" << endl;
				return 1;
			}
		}
		TimeComprasion(n);
	}
	else if (choice == 2) TestFen();
	else {
		cout << "Неверный вариант!";
		return 1;
	}
	return 0;
}

