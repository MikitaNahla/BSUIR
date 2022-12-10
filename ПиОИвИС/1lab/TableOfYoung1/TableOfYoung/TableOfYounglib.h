#pragma once

using namespace std;

struct TableYoung
{
	int Element;
	int Line_Num;
	int Column_Num;
};

namespace TableOfYoung
{
	class Actions
	{
	public:

		static void Insert(TableYoung* Table, int l, int g, int element);

		static void Removal(TableYoung* Table, int l, int g, int h);

	};
}