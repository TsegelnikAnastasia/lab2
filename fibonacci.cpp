#include <iostream>
#include <chrono>

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
	return 0;
}

