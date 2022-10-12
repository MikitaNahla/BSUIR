#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <io.h>

using namespace std;

struct Student
{
	int Number;
	char Surname[15];
	char FirstName[15];
	char SecondName[15];
	int BirthYear;
	int Num_Group;
	int Physics_Grade, Maths_Grade, Informatics_Grade, Chemistry_Grade;
	double GPA;
}_Stud;

void OutputAllStudents(Student _Stud, int Quantity, FILE * file)
{
	int i = 1;
	int Esc = 1;
	while (Esc != 0)
	{
		cout << "Фамилия Имя Отчество ";
		cout << "Год Группа Физика Математика Информатика Химия Ср.балл:\n";
		while (true)
		{
			if (!fread(&_Stud, sizeof(Student), 1, file))
			{
				break;
			}
			cout 
				<< _Stud.Surname << " "
				<< _Stud.FirstName << " "
				<< _Stud.SecondName << " "
				<< _Stud.BirthYear << " "
				<< _Stud.Num_Group
				<< " \t\t" << _Stud.Physics_Grade
				<< " \t\t" << _Stud.Maths_Grade
				<< " \t\t" << _Stud.Informatics_Grade
				<< " \t\t" << _Stud.Chemistry_Grade
				<< " \t\t" << _Stud.GPA << "\n";
		}
		cout << "Нажмите 0 если хотите выйти\n";
		cin >> Esc;
	}
}

int MenuCorrect()
{
	int r;
	cout << "\nЧто хотите изменить?\n";
	cout << "(1)Фамилию\n";
	cout << "(2)Имя\n";
	cout << "(3)Отчество\n";
	cout << "(4)Год рождения\n";
	cout << "(5)Номер группы\n";
	cout << "(6)Оценку по физике\n";
	cout << "(7)Оценку по математике\n";
	cout << "(8)Оценку по информатике\n";
	cout << "(9)Оценку по химии\n";
	cout << "(0)Выйти из меню коррекции\n";
	cin >> r;
	return r;
	system("cls");
}

void PersTask(Student* Stud, int Quantity)
{
	int Esc = 1;
	while (Esc == 1)
	{ 
		for (int i = 0; i < Quantity; i++)
		{
			if ((Stud[i].Physics_Grade == 7 || Stud[i].Physics_Grade == 8) && (Stud[i].Maths_Grade == 9 || Stud[i].Maths_Grade == 10))
			{
				cout << "Номер студента в списке " << i + 1 << "\n";
				cout << "ФИО: " << Stud[i].Surname << " " << Stud[i].FirstName << " " << Stud[i].SecondName << "\n";
				cout << "Год рождения: " << Stud[i].BirthYear << "\n";
				cout << "Номер группы: " << Stud[i].Num_Group << "\n";
				cout << "Оценка по физике: " << Stud[i].Physics_Grade << "\n";
				cout << "Оценка по математике: " << Stud[i].Maths_Grade << "\n";
				cout << "Оценка по информатике: " << Stud[i].Informatics_Grade << "\n";
				cout << "Оценка по химии: " << Stud[i].Chemistry_Grade << "\n";
				cout << "Средний балл: " << Stud[i].GPA << "\n";
				cout << "\n---------------------------------\n\n";
			}
			if (i == Quantity - 1)
			{
				cout << "Нажмите 0, если хотите выйти в меню\n";
				cin >> Esc;
			}
		}
	}
}

int Menu()
{
	system("cls");
	int q;
	cout << "Выберите действие :\n";
	cout << "(1)Создать новый файл или открыть уже существующий\n";
	cout << "(2)Вывести данные о студентах\n";
	cout << "(3)Коррекция\n";
	cout << "(4)Персональное задание\n";
	cout << "(0)Выход из программы\n";
	cin >> q;
	return q;
}

int _Menu()
{
	system("cls");
	int p;
	cout << "Что хотите сделать:\n";
	cout << "(1)Добавить новых студентов\n";
	cout << "(2)Редактировать данные уже существующих\n";
	cout << "(0)Выход из меню коррекции\n" ;
	cin >> p;
	return p;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Student* Stud;
	FILE* file;
	int QuantityBefore = 0;
	int a = 1;
	char File_name[] = "Students.txt";
	file = fopen(File_name, "rb+");
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
				if (!fread(&_Stud, sizeof(Student), 1, file))
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
				OutputAllStudents(_Stud, QuantityBefore, file);
				fclose(file);
				break;

		case 3:
			bool A;
			A = true;
			while (A)
			{
				switch (_Menu())
				{
				case 1:
					system("cls");
					file = fopen(File_name, "a+b");
					cout << "Сколько студентов хотите добавить?\n";
					int QuantityAfter;
					cin >> QuantityAfter;
					for (int i = QuantityBefore; i < QuantityAfter + QuantityBefore; i++)
					{
						fflush(stdin);
						_Stud.Number = i + 1;
						cout << "Введите ФИО студента №" << i + 1 << "\n";
						cin >> _Stud.Surname;
						cin >> _Stud.FirstName;
						cin >> _Stud.SecondName;
						cout << "Введите год рождения студента ";
						cin >> _Stud.BirthYear;
						cout << "Введите номер группы студента ";
						cin >> _Stud.Num_Group;
						cout << "Введите оценки студента по физике ";
						cin >> _Stud.Physics_Grade;
						cout << "Введите оценки студента по математике ";
						cin >> _Stud.Maths_Grade;
						cout << "Введите оценки студента по информатике ";
						cin >> _Stud.Informatics_Grade;
						cout << "Введите оценки студента по химии ";
						cin >> _Stud.Chemistry_Grade;

						while (_Stud.Physics_Grade > 10 || _Stud.Physics_Grade <= 0)
						{
							cout << "Повторите ввод оценки студента по физике ";
							cin >> _Stud.Physics_Grade;
						}

						while (_Stud.Maths_Grade > 10 || _Stud.Maths_Grade <= 0)
						{
							cout << "Повторите ввод оценки студента по математике ";
							cin >> _Stud.Maths_Grade;
						}

						while (_Stud.Informatics_Grade > 10 || _Stud.Informatics_Grade <= 0)
						{
							cout << "Повторите ввод оценки студента по информатике ";
							cin >> _Stud.Informatics_Grade;
						}

						while (_Stud.Chemistry_Grade > 10 || _Stud.Chemistry_Grade <= 0)
						{
							cout << "Повторите ввод оценки студента по химии ";
							cin >> _Stud.Chemistry_Grade;
						}

						_Stud.GPA = (_Stud.Physics_Grade + _Stud.Maths_Grade + _Stud.Informatics_Grade + _Stud.Chemistry_Grade) / 4.;
						cout << "Средний балл равен: " << _Stud.GPA << "\n";
						fwrite(&_Stud, sizeof(Student), 1, file);
					}
					QuantityBefore = QuantityAfter + QuantityBefore;
					fclose(file);
					break;

				case 2:
					file = fopen(File_name, "rb+");
					QuantityBefore = _filelength(_fileno(file)) / sizeof(Student);
					Stud = new Student[QuantityBefore];
					for (int i = 0; i < QuantityBefore; i++)
					{
						fread((Stud + i), sizeof(Student), 1, file);
					}
					fclose(file);
					cout << "Введите номер студента, у которого хотитие что-нибудь изменить\n";
					int number;
					cin >> number;
					for (int i = 0; i < QuantityBefore; i++)
					{
						if (Stud[i].Number == number)
						{
							cout << "ФИО студента: " << Stud[i].Surname << " " << Stud[i].FirstName << " " << Stud[i].SecondName << "\n"
								<< "Год Рождения: " << Stud[i].BirthYear << "\nНомер группы: " << Stud[i].Num_Group <<
								"\nОценка по физике: " << Stud[i].Physics_Grade << "\nОценка по математике: " << Stud[i].Physics_Grade
								<< "\nОценка по информатике: " << Stud[i].Informatics_Grade << "\nОценка по химии: " << Stud[i].Chemistry_Grade
								<< "\nСредний балл: " << Stud[i].GPA;
							bool b;
							b = true;
							while (b)
							{
								switch (MenuCorrect())
								{
								case 1:
									cout << "Введите другую фамилию: \n";
									cin >> Stud[i].Surname;
									system("cls");
									break;

								case 2:
									cout << "Введите другое имя: \n";
									cin >> Stud[i].FirstName;
									system("cls");
									break;

								case 3:
									cout << "Введите дргуое отчество: \n";
									cin >> Stud[i].SecondName;
									system("cls");
									break;

								case 4:
									cout << "Введите другой год рождения: \n";
									cin >> Stud[i].BirthYear;
									system("cls");
									break;

								case 5:
									cout << "Введите другой номер группы: \n";
									cin >> Stud[i].Num_Group;
									system("cls");
									break;

								case 6:
									cout << "Введите другую оценку по физике: \n";
									cin >> Stud[i].Physics_Grade;
									while (Stud[i].Physics_Grade > 10 || Stud[i].Physics_Grade <= 0)
									{
										cout << "Повторите ввод оценки студента по физике ";
										cin >> Stud[i].Physics_Grade;
									}
									Stud[i].GPA = (Stud[i].Physics_Grade + Stud[i].Maths_Grade + Stud[i].Informatics_Grade + Stud[i].Chemistry_Grade) / 4.;
									system("cls");
									break;

								case 7:
									cout << "Введите другую оценку по математике: \n";
									cin >> Stud[i].Maths_Grade;
									while (Stud[i].Maths_Grade > 10 || Stud[i].Maths_Grade <= 0)
									{
										cout << "Повторите ввод оценки студента по математике ";
										cin >> Stud[i].Maths_Grade;
									}
									Stud[i].GPA = (Stud[i].Physics_Grade + Stud[i].Maths_Grade + Stud[i].Informatics_Grade + Stud[i].Chemistry_Grade) / 4.;
									system("cls");
									break;

								case 8:
									cout << "Введите другую оценку по информатике: \n";
									cin >> Stud[i].Informatics_Grade;
									while (Stud[i].Informatics_Grade > 10 || Stud[i].Informatics_Grade <= 0)
									{
										cout << "Повторите ввод оценки студента по информатике ";
										cin >> Stud[i].Informatics_Grade;
									}
									Stud[i].GPA = (Stud[i].Physics_Grade + Stud[i].Maths_Grade + Stud[i].Informatics_Grade + Stud[i].Chemistry_Grade) / 4.;
									system("cls");
									break;

								case 9:
									while (Stud[i].Chemistry_Grade > 10 || Stud[i].Chemistry_Grade <= 0)
									{
										cout << "Повторите ввод оценки студента по химии ";
										cin >> Stud[i].Chemistry_Grade;
									}
									cout << "Введите другую оценку по химии: \n";
									cin >> Stud[i].Chemistry_Grade;
									Stud[i].GPA = (Stud[i].Physics_Grade + Stud[i].Maths_Grade + Stud[i].Informatics_Grade + Stud[i].Chemistry_Grade) / 4.;
									system("cls");
									break;

								case 0:
									cout << "Выход из коррекции...\n";
									b = 0;
									system("cls");
									break;
								}
							}
						}
					}
					file = fopen(File_name, "wb+");
					fwrite(Stud, sizeof(Student), QuantityBefore, file);
					fclose(file);
					delete[]Stud;
					system("pause");
					system("cls");
					break;

				case 0:
					system("cls");
					A = false;
					cout << "Выходим из меню коррекции...";
					break;
				}
				break;
			}
			break;

		case 4:
				system("cls");
				file = fopen(File_name, "rb+");
				QuantityBefore = _filelength(_fileno(file)) / sizeof(Student);
				Stud = new Student[QuantityBefore];
				for (int i = 0; i < QuantityBefore; i++)
				{
					fread((Stud + i), sizeof(Student), 1, file);
				}
				fclose(file);
				int n ;
				n = 0;
				file = fopen("Result.txt", "wb+");
				fclose(file);
				for (int i = 0; i < QuantityBefore; i++)
				{
					if ((Stud[i].Physics_Grade == 7 || Stud[i].Physics_Grade == 8) && (Stud[i].Maths_Grade == 9 || Stud[i].Maths_Grade == 10))
					{
						cout << "Номер студента в списке " << i + 1 << "\n";
						cout << "ФИО: " << Stud[i].Surname << " " << Stud[i].FirstName << " " << Stud[i].SecondName << "\n";
						cout << "Год рождения: " << Stud[i].BirthYear << "\n";
						cout << "Номер группы: " << Stud[i].Num_Group << "\n";
						cout << "Оценка по физике: " << Stud[i].Physics_Grade << "\n";
						cout << "Оценка по математике: " << Stud[i].Maths_Grade << "\n";
						cout << "Оценка по информатике: " << Stud[i].Informatics_Grade << "\n";
						cout << "Оценка по химии: " << Stud[i].Chemistry_Grade << "\n";
						cout << "Средний балл: " << Stud[i].GPA << "\n";
						cout << "\n---------------------------------\n\n";
						file = fopen("Result.txt", "ab+"); 
						fprintf(file, "\n %20s %20s %20s %6d %6d %6d %6d %6d %6d %6.2lf", Stud[i].Surname, Stud[i].FirstName, Stud[i].SecondName, Stud[i].BirthYear, Stud[i].Num_Group, Stud[i].Physics_Grade, Stud[i].Maths_Grade, Stud[i].Informatics_Grade, Stud[i].Chemistry_Grade, Stud[i].GPA);
						fclose(file);
					}
				}
				delete[]Stud;
				system("pause");
				system("cls");
				break;

			case 0:
				fclose(file);
				system("cls");
				cout << "Выходим из программы...";
				return 0;
				break;
		}
	}
}