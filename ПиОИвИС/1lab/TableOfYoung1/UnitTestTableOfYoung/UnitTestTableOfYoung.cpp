#include "pch.h"
#include "CppUnitTest.h"
#include "../TableOfYoung/TableOfYounglib.h"
#include "../TableOfYoung/TableOfYoung.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTableOfYoung
{
	TEST_CLASS(UnitTestTableOfYoung)
	{
	public:
		
		TEST_METHOD(TestInput)
		{
			int l = 9, n = 3, m = 3, quality1 = 0, QualityOfZero1 = 0, quality2 = 0, QualityOfZero2 = 0;

			int Temp_TableOfYoung[3][3] = { {1,2,3}, {4,5,0}, {6,7,0} };

			TableYoung* Table = new TableYoung[l];

			for (int i = 0, k = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					Table[k].Column_Num = j;
					Table[k].Line_Num = i;
					Table[k].Element = Temp_TableOfYoung[i][j];
					if (Table[k].Element != 0)
					{
						quality1++;
					}
					else
					{
						QualityOfZero1++;
					}
					k++;
				}
			}

			TableOfYoung::Actions::Insert(Table, l, 2, 25);

			for (int i = 0, k = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (Table[k].Element != 0)
					{
						quality2++;
					}
					else
					{
						QualityOfZero2++;
					}
					k++;
				}
			}

			Assert::AreEqual(quality1, quality2 - 1);

			Assert::AreNotEqual(Table[6].Element, 0);

			Assert::AreEqual(QualityOfZero1, QualityOfZero2 + 1);

			for (int i = 0, k = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (Temp_TableOfYoung[1][2] != Table[6].Element)
					{
						j++;
					}
					else
					{
						Assert::AreEqual(Temp_TableOfYoung[i][j], Table[k].Element);
					}
					k++;
				}
			}

		}

		TEST_METHOD(TestRemoval)
		{
			int l = 9, n = 3, m = 3, quality1 = 0, QualityOfZero1 = 0, quality2 = 0, QualityOfZero2 = 0;

			int Temp_TableOfYoung[3][3] = { {2,3,4}, {3,6,0}, {5,7,0} };

			TableYoung* Table = new TableYoung[l];

			for (int i = 0, k = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					Table[k].Column_Num = j;
					Table[k].Line_Num = i;
					Table[k].Element = Temp_TableOfYoung[i][j];
					if (Table[k].Element != 0)
					{
						quality1++;
					}
					else
					{
						QualityOfZero1++;
					}
					k++;
				}
			}

			TableOfYoung::Actions::Removal(Table, l, 3, 2);

			for (int i = 0, k = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (Table[k].Element != 0)
					{
						quality2++;
					}
					else
					{
						QualityOfZero2++;
					}
					k++;
				}
			}

			Assert::AreEqual(quality1, quality2 + 1);

			Assert::AreEqual(Table[8].Element, 0);

			Assert::AreEqual(QualityOfZero1, QualityOfZero2 - 1);

			for (int i = 0, k = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (Temp_TableOfYoung[2][1] != Table[8].Element)
					{
						j++;
					}
					else
					{
						Assert::AreEqual(Temp_TableOfYoung[i][j], Table[k].Element);
					}
					k++;
				}
			}

		}
	};
}
