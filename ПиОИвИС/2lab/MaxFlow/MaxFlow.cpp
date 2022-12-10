#include <iostream>
#include <fstream>

using namespace std;

int INF = 1231231313;

int Find_Max_Weight_Edge(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else return b;
}

int Find_Min_Weight_Edge(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else return b;
}

int Ford_Falkerson(int** Graph, int QuantityOfVertex, int *path, int path_size, int* visited, int Stock, int Source, int result, int MIN)
{
	if (visited[Source] == true)
	{
		return 0;
	}
	if (visited[Source] != true)
	{
		visited[Source] = true;
		path[path_size] = Source;
		path_size++;
	}
	if (Source == Stock)
	{
		for (int i = 1; i < path_size; i++)
		{
			int m = i - 1;
			int n = i;
			if (m != 0 && n != 0 && Graph[path[m]][path[n]] > 0 && Graph[path[m]][path[n]] != INF)
			{
				MIN = Find_Min_Weight_Edge(Graph[path[m]][path[n]], MIN);
			}
		}
		for (int i = 1; i < path_size; i++)
		{
			int m = i - 1;
			int n = i;
			if (m != 0 && n != 0 && Graph[path[m]][path[n]] > 0 && Graph[path[m]][path[n]] != INF)
			{
				Graph[path[m]][path[n]] -= MIN;
			}
		}
		return MIN;
	}
	else
	{
		for (int i = 0; i < QuantityOfVertex; i++)
		{
			if (Graph[Source][i] != INF && Graph[Source][i] > 0 && Graph[Source][i] != Graph[Source][Source])
			{
				result = Ford_Falkerson(Graph, QuantityOfVertex, path, path_size, visited, Stock, i, result, MIN);
				if (result > 0)
				{
					break;
				}
			}
		}
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	ifstream input("input.txt");
	ofstream output("output.txt");
	int QuantityOfVertex = 0;
	int QuantityOfEdges = 0;
	int **Graph;
	int *Visited_Vertex;
	int Source;
	int Stock;
	int MaxFlow = 0;

	input.is_open();
	input >> QuantityOfVertex;
	input >> QuantityOfEdges;
	Graph = new int*[QuantityOfVertex];

	for (int i = 0; i < QuantityOfVertex; i++)
	{
		Graph[i] = new int[QuantityOfVertex];
	}
	for (int i = 0; i < QuantityOfVertex; i++)
	{
		for (int j = 0; j < QuantityOfVertex; j++)
		{
			Graph[i][j] = INF;
		}
	}

	Visited_Vertex = new int[QuantityOfVertex];

	for (int k = 0; k < QuantityOfEdges; k++)
	{
		int FirstVertex;
		int SecondVertex;
		int Edge_Weight;
		input >> FirstVertex;
		FirstVertex--;
		input >> SecondVertex;
		SecondVertex--;
		input >> Edge_Weight;
		Graph[FirstVertex][SecondVertex] = Edge_Weight;
	}

	int Temp_Source = 0;
	int Temp_Stock = 0;
	input >> Temp_Source;
	input >> Temp_Stock;
	input.close();
	
	int Max_Flow = 0;
	int *path;
	int path_size = 0;
	path = new int[QuantityOfVertex];
	
	for (int k = 0; k < QuantityOfVertex; k++)
	{
		Source = Temp_Source - 1;
		Stock = Temp_Stock - 1;
		if (Graph[Source][k] != INF && Graph[Source][k] > 0)
		{
			for (int i = 0; i < QuantityOfVertex; i++)
			{
				path[i] = 0;
				Visited_Vertex[i] = 0;
			}
			int MIN = INF;
			path_size = 1;
			int result;
			result = 0;
			result = Ford_Falkerson(Graph, QuantityOfVertex, path, path_size, Visited_Vertex, Stock, Source, result, MIN);
			if (result > 0)
			{
				Max_Flow += result;
				k = 0;
			}
		}
	}

	output << Max_Flow;

	delete[]Visited_Vertex;
	delete[]Graph;
}