#include "TableOfYounglib.h"

using namespace std;

namespace TableOfYoung
{
	void Actions::Insert(TableYoung* Table, int l, int g, int element)
	{
		for (int j = 0; j < l; j++)
		{
			if (Table[j].Line_Num == (g - 1) && Table[j].Element == 0)
			{
				Table[j].Element = element;
				break;
			}
		}
	}

	void Actions::Removal(TableYoung* Table, int l, int g, int h)
	{
		for (int j = 0; j < l; j++)
		{
			if (Table[j].Line_Num == (g - 1) && Table[j].Column_Num == (h - 1))
			{
				Table[j].Element = 0;
			}
		}
	}
}