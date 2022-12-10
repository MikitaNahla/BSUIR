#include <iostream>
#include "TableOfYounglib.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int Menu()
{
	system("cls");
	int q = 0;
	cout << "Choose variant:\n";
	cout << "(1)Input element\n";
	cout << "(2)Delete element\n";
	cout << "(3)Output table in file\n";
	cout << "(4)Exit the program\n";
	cout << "\n--------------------------\n\n";
	cin >> q;
	return q;
}

void OutputFile(TableYoung* Table, int n, int m)
{
	int l = n * m;
	int o = 1;
	ofstream out;
	out.open("Text.txt");
	if (out.is_open())
	{
		for (int i = 0; i < l; i++)
		{
			if (Table[i].Element == 0)
			{
				out << "- ";
			}
			else
			{
				out << Table[i].Element << " ";
			}
			if ((i+1)/m == o)
			{
				out << "\n";
				o++;
			}
		}
	}
	out.close();
}

void SortInsert(TableYoung* Table, int g, int l)
{
	for (int j = 0; j < l; j++)
	{
		int pos = j;
		if (Table[j].Line_Num == (g - 1) && Table[j].Element < Table[pos].Element && Table[j].Line_Num != g)
		{
			int a = Table[pos].Element;
			int b = Table[j].Element;
			Table[pos].Element = b;
			Table[j].Element = a;
			j = pos - 1;
		}
	}
}

void SortRemoval(TableYoung* Table, int g, int l)
{
	for (int i = 0; i < l; i++)
	{
		if (Table[i].Line_Num == (g - 1) && Table[i].Element == 0 && Table[i + 1].Line_Num != g)
		{
			int sec;
			sec = Table[i + 1].Element;
			Table[i].Element = sec;
			Table[i + 1].Element = 0;
		}
	}
}

int main()
{
	int n = 0, m = 1, g = 0, h = 0, element = 0;
	string line, Temp_Char;
	ifstream InputFile("TableOfYoung.txt");
	vector<vector<int>> Temp_TableOfYoung;
	while (getline(InputFile, line))
	{
		stringstream temp_line(line);
		vector<int> Temp_Vector;
		while (getline(temp_line, Temp_Char, ' '))
		{
			if (Temp_Char == "-")
			{
				Temp_Vector.push_back(0);
			}
			else
			{
				Temp_Vector.push_back(stoi(Temp_Char));
			}
			m = Temp_Vector.size();
		}
		Temp_TableOfYoung.push_back(Temp_Vector);
		n++;
	}
	InputFile.close();

	int l = m * n;

	TableYoung* Table = new TableYoung[l];

	for (int i = 0, k = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Table[k].Line_Num = i;
			Table[k].Column_Num = j;
			Table[k].Element = Temp_TableOfYoung[i][j];
			//cout << Table[k].Element << "(" << Table[k].Line_Num << " , " << Table[k].Column_Num << ")" << " ";
			k++;
		}
	}

	while (true)
	{
		switch (Menu())
		{
		case 1:
			cout << "Where and what to insert? (Line number, element)\n";
			cin >> g >> element;
			TableOfYoung::Actions::Insert(Table, l, g, element);
			SortInsert(Table, g, l);
			break;

		case 2:
			cout << "Which element to delete? (Row number, then column number)\n";
			cin >> g >> h;
			TableOfYoung::Actions::Removal(Table, l, g, h);
			SortRemoval(Table, g, l);
			break;

		case 3:
			cout << "...Output file...\n";
			OutputFile(Table, n, m);
			break;

		case 4:
			cout << "...Completing the program...";
			return 0;
		}
	}
	//delete[]Temp_TableOfYoung;
	delete[]Table;
}