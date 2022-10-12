#include <iostream>

using namespace std;

struct Queue_Element
{
	int value;
	Queue_Element* next;
	Queue_Element* previous;
};

struct Queue
{
	Queue_Element* p_top;
	Queue_Element* p_end;
};

void Push_End(Queue *Name, int number)
{
	Queue_Element* Temp = new Queue_Element;				
	Temp->value = number;					
	if (Name->p_top == NULL)						
	{
		Temp->previous = Temp->next = NULL;	
		Name->p_end = Name->p_top = Temp;					
	}
	else									
	{
		Temp->next = NULL;								
		Temp->previous = Name->p_end;					
		Name->p_end->next = Temp;						
		Name->p_end = Temp;						
	}
}

void Push_Top(Queue* Name, int number)
{
	Queue_Element* Temp = new Queue_Element;				
	Temp->value = number;					
	if (Name->p_end == NULL)
	{
		Temp->previous = Temp->next = NULL;	
		Name->p_end = Name->p_top = Temp;					
	}
	else									
	{
		Temp->previous = NULL;				
		Temp->next = Name->p_top;					
		Name->p_top->previous = Temp;					
		Name->p_top = Temp;							
	}
}

void View_End(Queue* Name)
{
	Queue_Element* Temp = Name->p_end;
	while (Temp != NULL)
	{
		cout << " " << Temp->value;
		Temp = Temp->previous;
	}
	cout << endl;
}

void View_Top(Queue * Name)
{
	Queue_Element* Temp = Name->p_top;
	while (Temp != NULL)
	{
		cout << " " << Temp->value;
		Temp = Temp->next;
	}
	cout << endl;
}

void Delete_Memory(Queue*& Name)
{
	Queue_Element* temp;
	while (Name->p_top != NULL)
	{
		temp = Name->p_top;
		Name->p_top = Name->p_top->next;
		delete temp;
	}
}

void Personal_Task(Queue* Name, Queue* Odd_Name, Queue* Even_Name)
{
	Queue_Element* temp = Name->p_end;
	while (temp != NULL)
	{
		if ((temp->value%2) == 0)
		{
			Push_End(Even_Name, temp->value);
		}
		else
		{
			Push_End(Odd_Name, temp->value);
		}
		temp = temp->previous;
	}
}

int Menu()
{
	system("cls");
	int x;
	cout << "(1)Create queue" << endl;
	cout << "(2)Add elements to queue" << endl;
	cout << "(3)View queue" << endl;
	cout << "(4)View all queue's" << endl;
	cout << "(5)Delete memory" << endl;
	cout << "(6)Personal task" << endl;
	cout << "(0)Quit the program" << endl;
	cin >> x;
	return x;
}

int Menu_Push()
{
	system("cls");
	int x;
	cout << "(1)Add element to top" << endl;
	cout << "(2)Add element to end" << endl;
	cout << "(0)Quit the creating" << endl;
	cin >> x;
	return x;
}

int Menu_View()
{
	system("cls");
	int x;
	cout << "(1)View queue from top" << endl;
	cout << "(2)View queue from end" << endl;
	cout << "(0)Quit the viewing" << endl;
	cin >> x;
	return x;
}

int main()
{
	srand(time(NULL));
	Queue* QU = new Queue;
	QU->p_top = NULL;
	Queue* Q_Odd = new Queue;
	Q_Odd->p_top = NULL;
	Queue* Q_Even = new Queue;
	Q_Even->p_top = NULL;
	int quantity = 0;
	while (true)
	{
		switch(Menu())
		{
		case 1:
			system("cls");
			Delete_Memory(QU);
			QU->p_top = NULL;
			Delete_Memory(Q_Odd);
			Q_Odd->p_top = NULL;
			Delete_Memory(Q_Even);
			Q_Even->p_top = NULL;
			cout << "Input quantity of elements: ";
			cin >> quantity;
			for (int i = 0; i < quantity; i++)
			{
				Push_End(QU, rand()%21 -11);
			}
			break;

		case 2:
			system("cls");
			bool a;
			a = true;
			while (a)
			{
				switch (Menu_Push())
				{
				case 1:
					system("cls");
					cout << "Input quantity of additive elements: ";
					cin >> quantity;
					for (int i = 0; i < quantity; i++)
					{
						Push_Top(QU, rand()%21 -11);
					}
					break;

				case 2:
					system("cls");
					cout << "Input quantity of additive elements: ";
					cin >> quantity;
					for (int i = 0; i < quantity; i++)
					{
						Push_End(QU, rand() % 21 - 11);
					}
					break;

				case 0:
					system("cls");
					a = false;
					break;
				}
			}
			break;

		case 3:
			system("cls");
			bool b;
			b = true;
			while (b)
			{
				switch (Menu_View())
				{
				case 1:
					system("cls");
					cout << "Your queue is : ";
					View_Top(QU);
					system("pause");
					break;
				case 2:
					system("cls");
					cout << "Your queue is : ";
					View_End(QU);
					system("pause");
					break;
				case 0:
					system("cls");
					b = false;
					break;
				}
			}
			break;
		
		case 4:
			system("cls");
			bool z;
			z = true;
			while (z)
			{
				switch (Menu_View())
				{
				case 1:
					system("cls");
					cout << "Your queue is : ";
					View_Top(QU);
					cout << "Your odd queue is: ";
					View_Top(Q_Odd);
					cout << "Your even queue is: ";
					View_Top(Q_Even);
					system("pause");
					break;
				case 2:
					system("cls");
					cout << "Your queue is : ";
					View_End(QU);
					cout << "Your odd queue is: ";
					View_End(Q_Odd);
					cout << "Your even queue is: ";
					View_End(Q_Even);
					system("pause");
					break;
				case 0:
					system("cls");
					z = false;
					break;
				}
			}
			break;

		case 5:
			system("cls"); 
			Delete_Memory(QU);
			QU->p_top = NULL;
			Delete_Memory(Q_Odd);
			Q_Odd->p_top = NULL;
			Delete_Memory(Q_Even);
			Q_Even->p_top = NULL;
			break;

		case 6:
			system("cls");
			Personal_Task(QU, Q_Odd, Q_Even);
			break;

		case 0:
			system("cls");
			Delete_Memory(QU);
			QU->p_top = NULL;
			Delete_Memory(Q_Odd);
			Q_Odd->p_top = NULL;
			Delete_Memory(Q_Even);
			Q_Even->p_top = NULL;
			cout << "...Exiting the program..." << endl;
			return 0;
			break;
		}
	}
}