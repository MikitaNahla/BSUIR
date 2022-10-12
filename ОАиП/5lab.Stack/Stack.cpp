#include <iostream>

using namespace std;

struct Stack
{
	int value;
	Stack* next;
};

Stack* Push(Stack *Name, int n)
{
	Stack* temp = new Stack;
	temp->value = n;
	temp->next = Name;
	Name = temp;
	return Name;
}

Stack* Pop(Stack* Name)
{
	Stack* Temp = Name;
	Name = Temp->next;
	delete Temp;
	return Name;
}

void View(Stack* Name) 
{
	Stack* temp = Name;
	while (temp != NULL)
	{
		cout << "|" << temp->value << "|" << endl;
		temp = temp->next;
	}
}

void Sort_Adress(Stack** Name)
{
	Stack* Temp1 = NULL;
	Stack* Temp2;
	Stack* Temp;
	if ((*Name)->next->next == NULL) return;	
	do											
	{
		for (Temp2 = (*Name); Temp2->next->next != Temp1; Temp2 = Temp2->next)
		{
			if (Temp2->next->value > Temp2->next->next->value)
			{
				Temp = Temp2->next->next;
				Temp2->next->next = Temp->next;
				Temp->next = Temp2->next;
				Temp2->next = Temp;
			}								
		}	
		Temp1 = Temp2->next;
	} while ((*Name)->next->next != Temp1);
}

void Sort_Value(Stack* Name)
{
	Stack* Temp1, * Temp2;
	Temp1 = NULL;
	do 
	{
		for (Temp2 = Name; Temp2->next != Temp1; Temp2 = Temp2->next)
		{
			if (Temp2->value > Temp2->next->value) 
			{
				int temp;
				temp = Name->value;
				Name->value = Name->next->value;
				Name->next->value = temp;
			}
		}
		Temp1 = Temp2;
	} while (Name->next != Temp1);
}

void Free_Memory(Stack**Name)
{
	Stack* temp;
	while (*Name!=NULL)
	{
		temp =*Name;
		(*Name) = (*Name)->next;
		delete temp;
	}
}

int Menu()
{
	system("cls");
	int q;
	cout << "(1)Create Stack" << endl;
	cout << "(2)Add element for Stack" << endl;
	cout << "(3)View Stack" << endl;
	cout << "(4)View All Stacks" << endl;
	cout << "(5)Sort Stack" << endl;
	cout << "(6)Deliting memory" << endl;
	cout << "(7)Personal task" << endl;
	cout << "(0)Exit the program" << endl;
	cin >> q;
	return q;
}

int Menu_Sort()
{
	system("cls");
	int a;
	cout << "Choose variant to sort" << endl;
	cout << "(1)By adress" << endl << "(2)By info" << endl << "(0)Exit the Sort" << endl;
	cin >> a;
	return a;
}

int Menu_Sort_Stack()
{
	system("cls");
	int a;
	cout << "What stack would you like to sort?" << endl;
	cout << "(1)Main stack" << endl << "(2)Odd numbers stack" << endl << "(3)Even numbers stack" << endl << "(0)Exit the variant of sort" << endl;
	cin >> a;
	return a;
}

int main()
{
	/*srand(time(NULL));
	int *array;
	int n;

	cout << "Input size of array: ";
	cin >> n;

	array = new int[n];

	cout << "\nYour array is : ";

	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 21 - 11;
		cout << array[i] << " ";
		if ((array[i] % 2) == 0)
		{
		}
		else
		{
			OddNumbers.push(array[i]);
		}
	}

	cout << "\nEven Numbers are: ";

	while (!EvenNumbers.empty())
	{
		cout << EvenNumbers.top() << " ";
		EvenNumbers.pop();
	}

	cout << "\nOdd Numbers are: ";

	while (!OddNumbers.empty())
	{
		cout << OddNumbers.top() << " ";
		OddNumbers.pop();
	}*/
	int Quantity = 0, n = 0;
	Stack* St_Odd_Numbers = new Stack;
	St_Odd_Numbers = NULL;
	Stack* St_Even_Numbers = new Stack;
	St_Even_Numbers = NULL;
	Stack* ST = new Stack;
	ST = NULL;
	srand(time(NULL));
	while (true)
	{
		switch (Menu())
		{
		case 1:
			system("cls");
			Free_Memory(&ST);
			cout << "Input quantity of elements of stack: ";
			cin >> Quantity;
			for (int i = 0; i < Quantity; i++)
			{
				n = rand() % 21 - 11;
				ST = Push(ST, n);
			}
			break;

		case 2:
			system("cls");
			cout << "Input quantity of elements to add: ";
			int Quantity_To_Add;
			cin >> Quantity_To_Add;
			for (int i = 0; i < Quantity_To_Add; i++)
			{
				n = rand() % 21 - 11;
				ST = Push(ST, n);
			}
			Quantity += Quantity_To_Add;
			break;

		case 3:
			system("cls");
			cout << "Your stack is:" << endl;
			View(ST);
			system("pause");
			break;

		case 4:
			system("cls");
			cout << "The main stack is:" << endl;
			View(ST);
			cout << "Odd numbers stack is" << endl;
			View(St_Odd_Numbers);
			cout << endl << "Even numbers stack is" << endl;
			View(St_Even_Numbers);
			system("pause");
			break;

		case 5:
			system("cls");
			bool b ;
			b = true;
			while (b)
			{
				switch (Menu_Sort())
				{
					case 1:
						bool a ;
						a = 1;
						while (a)
						{
							switch (Menu_Sort_Stack())
							{
								case 1:
									system("cls");
									ST = Push(ST, rand()%21 -11);
									Sort_Adress(&ST);
									ST = Pop(ST);
									break;
								case 2:
									system("cls");
									St_Odd_Numbers = Push(St_Odd_Numbers, rand() % 21 - 11);
									Sort_Adress(&St_Odd_Numbers);
									St_Odd_Numbers = Pop(St_Odd_Numbers);
									break;
								case 3:
									system("cls");
									St_Even_Numbers = Push(St_Even_Numbers, rand() % 21 - 11);
									Sort_Adress(&St_Even_Numbers);
									St_Even_Numbers = Pop(St_Even_Numbers);
									break;
								case 0:
									system("cls");
									a = 0;
									break;
							}
						}

					break;
					case 2:
						bool z;
						z = 1;
						while (z)
						{
							switch (Menu_Sort_Stack())
							{
								case 1:
									system("cls");
									ST = Push(ST, rand() % 21 - 11);
									Sort_Value(ST);
									ST = Pop(ST);
									break;
								case 2:
									system("cls");
									St_Odd_Numbers = Push(St_Odd_Numbers, rand() % 21 - 11);
									Sort_Value(St_Odd_Numbers);
									St_Odd_Numbers = Pop(St_Odd_Numbers);
									break;
								case 3:
									system("cls");
									St_Even_Numbers = Push(St_Even_Numbers, rand() % 21 - 11);
									Sort_Value(St_Even_Numbers);
									St_Even_Numbers = Pop(St_Even_Numbers);
									break;
								case 0:
									system("cls");
									z = 0;
									break;
							}
						}
						break;
					case 0:
						system("cls");
						b = false;
					break;

				}
			}
			break;
		case 6:
			system("cls");
			cout << "Deliting memory and stack" << endl;
			Free_Memory(&ST);
			Quantity = 0;
			Free_Memory(&St_Odd_Numbers);
			Free_Memory(&St_Even_Numbers);
			system("pause");
			break;

		case 7:
			system("cls");
			Stack* Temp;
			Temp = ST;
			while (Temp!=NULL)
			{
				int i;
				i = (Temp->value) % 2;
				if (i == 0)
				{
					St_Even_Numbers = Push(St_Even_Numbers, Temp->value);
				}
				else
				{
					St_Odd_Numbers = Push(St_Odd_Numbers, Temp->value);
				}
				Temp = Temp->next;
			}
			cout << "Odd numbers stack is" << endl;
			View(St_Odd_Numbers);
			cout << endl << "Even numbers stack is" << endl;
			View(St_Even_Numbers);
			system("pause");
			break;

		case 0:	
			system("cls");
			Free_Memory(&ST);
			Free_Memory(&St_Odd_Numbers);
			Free_Memory(&St_Even_Numbers);
			cout << "Exiting the program..." << endl;
			return 0;
		}
	}
}