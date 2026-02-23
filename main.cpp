#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int StrToInt(string binaryStr) {
	int result = 0;
	int power = 1;

	for (int i = binaryStr.length() - 1; i >= 0; i--) {
		if (binaryStr[i] == '1')
			result += power;//если 1 - добавляем текущую степень двойки
		power *= 2;//увеличиваемм степень
	}
	return result;
}

void BubbleSort(string* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			string first = arr[j].substr(2);//начиная с индекса 2
			string second = arr[j + 1].substr(2);

			int NumFirst = StrToInt(first);//переводим в двочиное число
			int NumSecond = StrToInt(second);

			if (NumFirst > NumSecond) {
				string temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void TestBubbleSort() {
	cout << "Тестирование сортировки: " << endl;
	int AllTests = 5;
	int DoneTests = 0;
	{
		//тест 1 - обычный случай
		string data[3] = { "0b1100100", "0b100101", "0b100" };
		string expected[3] = { "0b100", "0b100101", "0b1100100" };
		int size = 3;
		BubbleSort(data, size);

		bool ok;
		for (int i = 0; i < size; i++)
			assert(data[i] == expected[i]);
		DoneTests++;
	}
	{
		//тест 2 - один элемент
		string data[1] = { "0b1010" };
		string expected[1] = { "0b1010" };
		int size = 1;
		BubbleSort(data, size);
		assert(data[0] == expected[0]);
		DoneTests++;
	}
	{
		//тест 3 - уже отсортирован
		string data[] = { "0b1", "0b10", "0b11" };
		string expected[] = { "0b1", "0b10", "0b11" };
		int size = 3;

		BubbleSort(data, size);

		for (int i = 0; i < size; i++) {
			assert(data[i] == expected[i]);
		}
		DoneTests++;
	}
	{
		//тест 4 - одинаковые числа
		string data[] = { "0b101", "0b1", "0b101", "0b1" };
		string expected[] = { "0b1", "0b1", "0b101", "0b101" };
		int size = 4;

		BubbleSort(data, size);

		for (int i = 0; i < size; i++) {
			assert(data[i] == expected[i]);
		}
		DoneTests++;
	}
	{
		//тест 5 - обратный порядок
		string data[] = { "0b111", "0b110", "0b101", "0b100" };
		string expected[] = { "0b100", "0b101", "0b110", "0b111" };
		int size = 4;

		BubbleSort(data, size);

		for (int i = 0; i < size; i++) {
			assert(data[i] == expected[i]);
		}
		DoneTests++;
	}
	cout << "Пройдено: " << DoneTests << " из " << AllTests << endl;
}



int main() {
	setlocale(LC_ALL, "russian");

	int choice;
	cout << "Что хотите сделать? 1 - Запустить сортировку, 2 - Запустить тесты ";
	cin >> choice;

	if (choice == 1) {

		int count;
		string* BinuryNum;
		cout << "Сколько строк с двоичными числами хотит ввеести? " << endl;
		cin >> count;
		while (count < 1) {
			cout << "Введите положительное число!" << endl;
			cin >> count;
		}
		BinuryNum = new string[count];
		cout << "Ввндите " << count << " cтрок в формате 0b1010 (с префиксом 0b):" << endl;
		for (int i = 0; i < count; i++) {
			cout << "Строка " << i + 1 << ":";
			cin >> BinuryNum[i];

			while (BinuryNum[i].length() < 2 || BinuryNum[i].substr(0, 2) != "0b") {
				cout << "Ошибка! Строка должна начинаться с '0b'. Повторите ввод:";
				cin >> BinuryNum[i];
			}
		}
		cout << endl;
		cout << "Вы ввели:" << endl;
		for (int i = 0; i < count; i++) {
			cout << BinuryNum[i] << " ";
		}
		cout << endl;

		BubbleSort(BinuryNum, count);

		cout << "После соортировки оп возрастанию: " << endl;
		for (int i = 0; i < count; i++)
			cout << BinuryNum[i] << " ";
		cout << endl;
		delete[]BinuryNum;


	}
	else if (choice == 2) {
		TestBubbleSort();
	}
	else {
		cout << "Не существует такого варианта!";
		return 1;
	}
	return 0;

