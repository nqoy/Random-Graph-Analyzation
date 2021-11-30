#include <iostream>
#include <vector>
#include <queue>
#include <String>
#include <ctime>
#include <fstream>
using namespace std;
#define k_num_of_graphs 200

//Class for creating a vertex 
class Vertex
{
public:
	int vertex_number;
	vector<int> neighbors;
	string color = "White";
	int distance_from_start_vertex = -1;

	Vertex() {}; //default constructor
	Vertex(int vertex_number) // constructor that inputs the vertex number
	{
		this->vertex_number = vertex_number;
	};

};

// function decleration
vector<Vertex*> build_random_graph(int v, double p);
int Is_Isolated(vector<Vertex*> graph);
void call_bfs(vector<Vertex*> graph, int s);
int connectivity(vector<Vertex*> graph);
int diameter(vector<Vertex*> graph);
void AttributeFileNumber1();
void AttributeFileNumber2();
void AttributeFileNumber3();
void freeGraph(vector<Vertex*> graph);

int main()
{
	srand(time(NULL));
	AttributeFileNumber1(); // - connectivity
	AttributeFileNumber2(); // - diameter
	AttributeFileNumber3(); // - Isolated Vertex
}


// Creating a graph of type vector<Vertex*> with the possebility of p for connection between each vertex (adding neighbors).
vector<Vertex*> build_random_graph(int v, double p)
{

	double random_val;

	vector<Vertex*> graph;
	for (int i = 0; i < v; i++)
	{
		graph.push_back(new Vertex(i));
	}

	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < i; j++)
		{
			random_val = (double)rand() / RAND_MAX;
			if (random_val <= p)
			{
				graph[i]->neighbors.push_back(j);
				graph[j]->neighbors.push_back(i);
			}
		}
	}

	return graph;
}

// Chacking if there is a vertex with no nighbors.
int Is_Isolated(vector<Vertex*> graph)
{
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i]->neighbors.size() == 0)
			
			return 1;
	}
	return 0;
}

// BFS to get diameter and connectivity (from psuado to code).
void call_bfs(vector<Vertex*> graph, int s)
{

	int curr_v = s;
	for (int i = 0; i < graph.size(); i++)
	{
		graph[i]->distance_from_start_vertex = 0;
		graph[i]->color = "white";
	}

	queue<int> q;
	graph[s]->color = "black";
	q.push(graph[s]->vertex_number);

	while (q.size() != 0)
	{
		curr_v = q.front();
		for (int i = 0; i < graph[curr_v]->neighbors.size(); i++)
		{
			if (graph[graph[curr_v]->neighbors[i]]->color == "white")
			{
				graph[graph[curr_v]->neighbors[i]]->color = "black";
				graph[graph[curr_v]->neighbors[i]]->distance_from_start_vertex = graph[curr_v]->distance_from_start_vertex + 1;
				q.push(graph[curr_v]->neighbors[i]);
			}
		}

		q.pop();
		if (q.size() == 0)
			break;
	}
}

// Runing BFS to check connectivity via changes in vertex color from white to black.
int connectivity(vector<Vertex*> graph)
{
	if (Is_Isolated(graph) == 1)
		return 0;

	call_bfs(graph, 0);
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i]->color == "white")
			return 0;
	}
	return 1;
}

//Running BFS and compering each diameter of the graph if it is connected and return it.
int diameter(vector<Vertex*> graph)
{
	double diameter = 0;
	if (connectivity(graph) == 0)
		return INFINITY;

	for (int i = 0; i < graph.size(); i++)
	{
		call_bfs(graph, i);
		for (int j = 0; j < graph.size() ; j++)
			if (graph[j]->distance_from_start_vertex > diameter)
				diameter = graph[j]->distance_from_start_vertex;
	}
	return diameter;
}

//Open a file with the first attribute according to threshold1
void AttributeFileNumber1()
{
	printf("\nWorking on Connectivity cvs data file, please wait..");
	double threshold_test_p[] = { 0.001,0.002,0.003,0.004,0.005 , 0.0075,0.008,0.009,0.01,0.02 }; // thresh - 0.0069, connectivity + Isolated Vertex;
	ofstream myFile;
	myFile.open("Attribute_1_Connectivity.csv");
	myFile << "P" << endl;
	for (int j = 0; j < 10; j++)
	{
		myFile << threshold_test_p[j];
		for (int i = 0; i < k_num_of_graphs; i++)
		{
			vector<Vertex*> graph = build_random_graph(1000, threshold_test_p[j]);

			if (connectivity(graph) == 1)
			{
				myFile << "," << 1;
			}
			else
			{
				myFile << "," << 0;
			}
			freeGraph(graph);
		}
		myFile << endl;
	}
	myFile.close();
}

//Open a file with the second attribute according to threshold2
void AttributeFileNumber2()
{
	printf("\nWorking on diameter cvs data file..this may take around 12 minutes..");
	double threshold_test_p[] = { 0.01,0.03,0.06,0.09,0.1 , 0.12,0.13,0.14,0.15,0.16 }; // thresh - 0.1175 - daiameter
	ofstream myFile;
	myFile.open("Attribute_2_Diameter.csv");
	myFile << "P" << endl;
	for (int j = 0; j < 10; j++)
	{
		myFile << threshold_test_p[j];
		for (int i = 0; i < k_num_of_graphs; i++)
		{
			vector<Vertex*> graph = build_random_graph(1000, threshold_test_p[j]);

			if (connectivity(graph) == 1)
			{
				int diam = diameter(graph);
				myFile << "," << diam;
			}
			else
			{
				myFile << ",infinity";
			}
			freeGraph(graph);
		}
		myFile << endl;
	}
	myFile.close();
}

//Open a file with the third attribute according to threshold3
void AttributeFileNumber3()
{
	printf("\nWorking on Isolated Vertices cvs data file..");
	double threshold_test_p[] = { 0.001,0.002,0.003,0.004,0.005 , 0.0075,0.008,0.009,0.01,0.02 }; // thresh - 0.0069, connectivity + Isolated Vertex;
	ofstream myFile;
	myFile.open("Attribute_3_Isolated_vertex.csv");
	myFile << "P" << endl;
	for (int j = 0; j < 10; j++)
	{
		myFile << threshold_test_p[j];
		for (int i = 0; i < k_num_of_graphs; i++)
		{
			vector<Vertex*> graph = build_random_graph(1000, threshold_test_p[j]);

			if (Is_Isolated(graph) == 1)
			{
				myFile << "," << 1;
			}
			else
			{
				myFile << "," << 0;
			}
		freeGraph(graph);
		}
		myFile << endl;
	}
	myFile.close();
}

// Deleting objects -vertex- in the graph and freeing the memory so it wont accumulate.
void freeGraph(vector<Vertex*> graph)
{
	for (int i = 0; i < graph.size(); i++)
	{
		delete graph[i];
	}
	graph.clear();
	graph.shrink_to_fit();
}