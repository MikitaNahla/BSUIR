#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <io.h>

using namespace std;

struct Race
{
	int Number_Of_Race;
	char Type_Of_Airplane[15];
	char Destination[15];
	int Departure_Hour;
	int Departure_Minute;
}_Race;

void OutputAllRaces(Race _Race, int Quantity, FILE* file)
{
	int i = 1;
	int Esc = 1;
	while (Esc != 0)
	{
		while (true)
		{
			if (!fread(&_Race, sizeof(Race), 1, file))
			{
				break;
			}
			cout << "------------------------------------" << endl 
				<< "Номер рейса: " << _Race.Number_Of_Race << endl
				<< "Тип самолёта: " << _Race.Type_Of_Airplane << endl
				<< "Пункт назначения: " << _Race.Destination << endl
				<< "Время отправления: " << _Race.Departure_Hour ;
			if (_Race.Departure_Minute > 0)
			{
				cout << ":" << _Race.Departure_Minute << endl;
			}
			else
			{
				cout << ":00" << endl;
			}
			cout << "------------------------------------" << endl;
		}
		cout << "Нажмите 0 если хотите выйти\n";
		cin >> Esc;
	}
}

int Add_Races(Race _Race, int QuantityBefore, FILE* file)
{
	cout << "Сколько рейсов хотите добавить?\n";
	int QuantityAfter;
	cin >> QuantityAfter;
	for (int i = QuantityBefore; i < QuantityAfter + QuantityBefore; i++)
	{
		fflush(stdin);
		cout << "Введите номер рейса: ";
		cin >> _Race.Number_Of_Race;
		cout << "Введите тип самолёта: ";
		cin >> _Race.Type_Of_Airplane;
		cout << "Введите пункт назначения: ";
		cin >> _Race.Destination;
		cout << "Введите время вылета(сначала часы, потом минуты): ";
		cin >> _Race.Departure_Hour;
		cin >> _Race.Departure_Minute;

		while (_Race.Number_Of_Race <= 0)
		{
			cout << "Повторите ввод номера рейса: ";
			cin >> _Race.Number_Of_Race;
		}

		while (_Race.Departure_Hour >= 24 || _Race.Departure_Hour < 0 || _Race.Departure_Minute >= 60 || _Race.Departure_Minute < 0)
		{
			cout << "Повторите ввод времени вылета(сначала часы, потом минуты): ";
			cin >> _Race.Departure_Hour;
			cin >> _Race.Departure_Minute;
		}

		fwrite(&_Race, sizeof(Race), 1, file);
	}
	return QuantityBefore = QuantityAfter + QuantityBefore;
}

void Linear_Search(Race *R, int QuantityBefore, char Key[])
{
	int n;
	n = 0;
	for (int i = 0; i < QuantityBefore; i++)
	{
		if (strcmp(R[i].Destination, Key) == 0)
		{
			cout << "------------------------------------" << endl
				<< "Номер рейса: " << R[i].Number_Of_Race << endl
				<< "Тип самолёта: " << R[i].Type_Of_Airplane << endl
				<< "Пункт назначения: " << R[i].Destination << endl
				<< "Время отправления: " << R[i].Departure_Hour;
			if (R[i].Departure_Minute > 0)
			{
				cout << ":" << R[i].Departure_Minute << endl;
			}
			else
			{
				cout << ":00" << endl;
			}
			cout << "------------------------------------" << endl;
			n++;
		}
	}
	if (n == 0)
	{
		cout << "Рейсов с заданным ключом не обнаружено" << endl;
	}
}

int Binary_Search(Race* R, int QuantityBefore, char Key[])
{
	int i = 0, j = QuantityBefore - 1, m;
	while (i < j)
	{
		m = (i + j) / 2;
		if (strcmp(R[m].Destination, Key) != 0)
		{
			i = m + 1;
		}
		else
		{
			j = m;
		}
	}
	if (strcmp(R[i].Destination, Key) != 0)
	{
		return -1;
	}
	else return i;
}

void DSM(Race* R, int QuantityBefore)
{
	for (int i = 0; i < QuantityBefore - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < QuantityBefore; j++)
		{
			if (R[j].Departure_Hour < R[min].Departure_Hour || (R[j].Departure_Hour == R[min].Departure_Hour && R[j].Departure_Minute < R[min].Departure_Minute))
			{
				min = j;
			}
		}
		Race Temp = R[i];
		R[i] = R[min];
		R[min] = Temp;
	}
}

void QuickSort(Race *R, int begin, int end)
{
	int left = begin;
	int right = end;
	int middle = (left + right) / 2;
	do
	{
		while (R[middle].Departure_Hour > R[left].Departure_Hour || (R[middle].Departure_Hour == R[left].Departure_Hour && R[middle].Departure_Minute > R[left].Departure_Minute))
		{
			left++;
		}
		while (R[middle].Departure_Hour < R[right].Departure_Hour || (R[middle].Departure_Hour == R[right].Departure_Hour && R[middle].Departure_Minute < R[right].Departure_Minute))
		{
			right--;
		}
		if (left <= right)
		{
			Race Temp = R[left];
			R[left] = R[right];
			R[right] = Temp;
			left++;
			right--;
		}
	} while (left <= right);
	if (begin < right) 
	{
		QuickSort(R, begin, right);
	}
	if (end > left)
	{
		QuickSort(R, left, end);
	}
}

void Personal_Task(Race* R, int QuantityBefore, char Key[])
{
	for (int i = 0; i < QuantityBefore - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < QuantityBefore; j++)
		{
			if (R[j].Departure_Hour < R[min].Departure_Hour || (R[j].Departure_Hour == R[min].Departure_Hour && R[j].Departure_Minute < R[min].Departure_Minute))
			{
				min = j;
			}
		}
		Race Temp = R[i];
		R[i] = R[min];
		R[min] = Temp;
	}
	for (int i = 0; i < QuantityBefore; i++)
	{
		if (strcmp(R[i].Destination, Key) == 0)
		{
			cout << "------------------------------------" << endl
				<< "Номер рейса: " << R[i].Number_Of_Race << endl
				<< "Тип самолёта: " << R[i].Type_Of_Airplane << endl
				<< "Пункт назначения: " << R[i].Destination << endl
				<< "Время отправления: " << R[i].Departure_Hour;
			if (R[i].Departure_Minute > 0)
			{
				cout << ":" << R[i].Departure_Minute << endl;
			}
			else
			{
				cout << ":00" << endl;
			}
			cout << "------------------------------------" << endl;
		}
	}
}

int Menu()
{
	system("cls");
	int q;
	cout << "Выберите действие :\n";
	cout << "(1)Создать новый файл или открыть уже существующий\n";
	cout << "(2)Вывести данные о рейсах\n";
	cout << "(3)Добавить новые данные\n";
	cout << "(4)Линейный поиск в файле\n";
	cout << "(5)Сортировка\n";
	cout << "(6)Двоичный поиск в отсортированном массиве\n";
	cout << "(7)Персональное задание\n";
	cout << "(0)Выход из программы\n";
	cin >> q;
	return q;
}

int Menu_Sort()
{
	system("cls");
	int q;
	cout << "Выберите действие: " << endl;
	cout << "(1)Сортировка прямым выбором" << endl;
	cout << "(2)Сортировка методом QuickSort" << endl;
	cout << "(0)Выход из меню сортировки" << endl;
	cin >> q;
	return q;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Race* R;
	FILE* file;
	int QuantityBefore = 0;
	int a = 1;
	char File_name[] = "Races.txt";
	file = fopen(File_name, "rb+");
	char Destination[] = "New-York";
	int s = 0;
	while (TRUE)
	{
		switch (Menu())
		{
		case 1:
			system("cls");
			fclose(file);
			cout << "Хотите создать новый файл?\n";
			cout << "(1)Создать новый файл\n";
			cout << "(2)Открыть существующий файл\n";
			cout << "(0)Выход из программы\n";
			int z;
			cin >> z;
			switch (z)
			{
			case 1:
				system("cls");
				cout << "Введите имя файла:\n";
				file = NULL;
				while (file == NULL)
				{
					cin.getline(File_name, 1111);
					file = fopen(File_name, "wb+");
				}
				break;

			case 2:
				system("cls");
				cout << "Введите имя файла:\n";
				file = NULL;
				while (file == NULL)
				{
					cin.getline(File_name, 1111);
					file = fopen(File_name, "rb+");
				}
				break;

			case 0:
				system("cls");
				cout << "Выход из программы...";
				return 0;
				break;
			}

			while (1)
			{
				if (!fread(&_Race, sizeof(Race), 1, file))
				{
					break;
				}
				QuantityBefore++;
			}

			cout << QuantityBefore;
			break;

		case 2:
			system("cls");
			file = fopen(File_name, "rb+");
			OutputAllRaces(_Race, QuantityBefore, file);
			fclose(file);
			break;

		case 3:
			system("cls");
			file = fopen(File_name, "a+b");
			Add_Races(_Race, QuantityBefore, file);
			fclose(file);
			break;

		case 4:
			system("cls");
			file = fopen(File_name, "rb+");
			QuantityBefore = _filelength(_fileno(file)) / sizeof(Race);
			R = new Race[QuantityBefore];
			for (int i = 0; i < QuantityBefore; i++)
			{
				fread((R+i), sizeof(Race), 1, file);
			}
			fclose(file);
			cout << "Введите место назначения: ";
			cin >> Destination;
			Linear_Search(R, QuantityBefore, Destination);
			delete[] R;
			system("pause");
			system("cls");
			break;

		case 5:
			bool a;
			a = true;
			file = fopen(File_name, "rb+");
			QuantityBefore = _filelength(_fileno(file)) / sizeof(Race);
			R = new Race[QuantityBefore];
			for (int i = 0; i < QuantityBefore; i++)
			{
				fread((R + i), sizeof(Race), 1, file);
			}
			fclose(file);
			while (a)
			{
				switch (Menu_Sort())
				{
				case 1:
					system("cls");
					DSM(R, QuantityBefore);
					for (int i = 0; i < QuantityBefore; i++)
					{
						cout << "------------------------------------" << endl
							<< "Номер рейса: " << R[i].Number_Of_Race << endl
							<< "Тип самолёта: " << R[i].Type_Of_Airplane << endl
							<< "Пункт назначения: " << R[i].Destination << endl
							<< "Время отправления: " << R[i].Departure_Hour;
						if (R[i].Departure_Minute > 0)
						{
							cout << ":" << R[i].Departure_Minute << endl;
						}
						else
						{
							cout << ":00" << endl;
						}
						cout << "------------------------------------" << endl;
					}
					cout << "Хотите перезаписать файл?\n (1)Да\n (2)Нет" << endl;
					int r;
					cin >> r;
					if (r == 1)
					{
						s++;
						file = fopen(File_name, "wb+");
						for (int i = 0; i < QuantityBefore; i++)
						{
							fflush(stdin);
							fwrite(&R[i], sizeof(Race), 1, file);
						}
						fclose(file);
					}
					break;

				case 2:
					system("cls");
					QuickSort(R, 0, QuantityBefore - 1);
					for (int i = 0; i < QuantityBefore; i++)
					{
						cout << "------------------------------------" << endl
							<< "Номер рейса: " << R[i].Number_Of_Race << endl
							<< "Тип самолёта: " << R[i].Type_Of_Airplane << endl
							<< "Пункт назначения: " << R[i].Destination << endl
							<< "Время отправления: " << R[i].Departure_Hour;
						if (R[i].Departure_Minute > 0)
						{
							cout << ":" << R[i].Departure_Minute << endl;
						}
						else
						{
							cout << ":00" << endl;
						}
						cout << "------------------------------------" << endl;
					}
					cout << "Хотите перезаписать файл?\n (1)Да\n (2)Нет" << endl;
					int z;
					cin >> z;
					if (z == 1)
					{
						s++;
						file = fopen(File_name, "wb+");
						for (int i = 0; i < QuantityBefore; i++)
						{
							fflush(stdin);
							fwrite(&R[i], sizeof(Race), 1, file);
						}
						fclose(file);
					}
					if (z == 2)
					{
						continue;
					}
					break;

				case 0:
					system("cls");
					a = false;
					cout << "Выход из меню сортировки..." << endl;
					system("pause");
					delete[] R;
					break;

				}
			}
			break;

		case 6:
			system("cls");
			file = fopen(File_name, "rb+");
			QuantityBefore = _filelength(_fileno(file)) / sizeof(Race);
			R = new Race[QuantityBefore];
			for (int i = 0; i < QuantityBefore; i++)
			{
				fread((R + i), sizeof(Race), 1, file);
			}
			fclose(file);
			int result;

			cout << "Введите место назначения: ";
			cin >> Destination;
			if (s != 0)
			{
				result = Binary_Search(R, QuantityBefore, Destination);
				if (result == -1)
				{
					cout << "Рейс не найден" << endl;
				}
				else
				{
					cout << "------------------------------------" << endl
						<< "Номер рейса: " << R[result].Number_Of_Race << endl
						<< "Тип самолёта: " << R[result].Type_Of_Airplane << endl
						<< "Пункт назначения: " << R[result].Destination << endl
						<< "Время отправления: " << R[result].Departure_Hour;
					if (R[result].Departure_Minute > 0)
					{
						cout << ":" << R[result].Departure_Minute << endl;
					}
					else
					{
						cout << ":00" << endl;
					}
					cout << "------------------------------------" << endl;
				}
			}
			else
			{
				cout << "Выполните сортировку! " << endl;
			}
			delete[]R;
			system("pause");
			break;

		case 7:
			system("cls");
			file = fopen(File_name, "rb+");
			QuantityBefore = _filelength(_fileno(file)) / sizeof(Race);
			R = new Race[QuantityBefore];
			for (int i = 0; i < QuantityBefore; i++)
			{
				fread((R + i), sizeof(Race), 1, file);
			}
			fclose(file);
			cout << "Введите место назначения: ";
			cin >> Destination;
			Personal_Task(R, QuantityBefore, Destination);
			delete[]R;
			system("pause");
			break;

		case 0:
			system("cls");
			cout << "Выходим из программы...";
			return 0;
		}
	}
}