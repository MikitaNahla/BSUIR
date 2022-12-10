#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector> 
#include <queue>
using namespace std;

int MIN(int a, int b)
{
    return (a > b ? b : a);
}

queue <int> Queue;

int main()
{   
    setlocale(LC_ALL, "RUS");
    int i, j, k;
    int INF = 1000000000;
    int Diametr = 0;
    string line;
    ifstream in("Matr_sm.txt");
    vector<vector<int>> MatrA;
    string Temp_Char;
    while (getline(in, line))
    {
        stringstream temp_line(line);
        vector<int> Temp_Vector;
        while (getline(temp_line, Temp_Char, ' '))
        {
            Temp_Vector.push_back(stoi(Temp_Char));
        }
        MatrA.push_back(Temp_Vector);
    }
    in.close();
    
    cout << "Матрица смежности :" << endl;

    for (i = 0; i < MatrA.size(); i++)
    {
        for ( j = 0; j < MatrA.size(); j++)
        {
            cout << MatrA[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < MatrA.size(); i++)
    {
        for (int j = 0; j < MatrA.size(); j++)
        {          
            if (!MatrA[i][j])
            {
                MatrA[i][j] = INF;
            }
        }
    }

    vector<int> Visited_Vertex(MatrA.size());

    for ( i = 0; i < MatrA.size(); i++)
    {
        Visited_Vertex[i] = 0;
    }

    Queue.push(0);
    /*int l = Queue.size();
    cout << l*/;
    while (!Queue.empty())                                                                      //Для каждой вершины строим рёбра до каждой другой вершины
    {
        int Current_vertex = Queue.front();
        for (k = 0; k < MatrA.size(); k++)
        {
            for (j = 0; j < MatrA.size(); j++)
            {
                if (MatrA[Current_vertex][j] != 0 && Visited_Vertex[j] == 0)
                {
                    if (Current_vertex != j)
                    {
                        MatrA[Current_vertex][j] = MIN(MatrA[Current_vertex][j], MatrA[Current_vertex][k] + MatrA[k][j]);
                    }
                }
            }
        }
        Queue.pop();
        Visited_Vertex[Current_vertex] = 2;  
        for (j = 0; j < MatrA.size(); j++)
        {
            if (MatrA[Current_vertex][j] == 1 && Visited_Vertex[j] == 0)
            {
                Queue.push(j);
                Visited_Vertex[j] = 1;
            }
        }
    }

    for (int i = 0; i < MatrA.size(); i++)
    {
        for (int j = 0; j < MatrA.size(); j++)
        {
            if (MatrA[i][j] == INF)
            {
                MatrA[i][j] = 0;
            }
        }
    }

    Diametr = MatrA[0][1];

    for (i = 0; i < MatrA.size(); i++)                  //Выбираем наибольший из эксцентриситетов
    {
        for (j = 0; j < MatrA.size(); j++)
        {
            if (MatrA[i][j] > Diametr)
            {
                Diametr = MatrA[i][j];
            }
        }
    }

    for (i = 0; i < MatrA.size(); i++)
    {
        for (j = 0; j < MatrA.size(); j++)
        {
            cout << MatrA[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Диаметр графа равен = " << Diametr;
    cout << endl;
}