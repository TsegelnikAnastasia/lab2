
#include <iostream>
#include <string>

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


int main() {
	setlocale(LC_ALL, "russian");
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

	return 0;
}
