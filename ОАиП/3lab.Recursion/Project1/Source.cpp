#include <iostream>
#include <math.h>

using namespace std;

double Function_Recursion(int n)
{
	int i = 2 * n;
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return pow(i,2)/(pow(i,2) - 1) * Function_Recursion(n - 1);
	}
}

int main()
{
	int n;
	cout << "Input quantity of elements\n";
	cin >> n;
	cout << "\nWith recursion : " << Function_Recursion(n) << "\n\n";

	double result = 1;
	int Chisl = 2;
	for (int i = 0; i < n; i++)
	{
		result *= pow(Chisl,2)/(pow(Chisl,2) - 1) ;
		Chisl += 2;
	}

	cout << "With no recursion: " << result << "\n\n";

	if (Function_Recursion(n) == result)
	{
		cout << "All is good, function of recursion works right!\n\n";
	}
}