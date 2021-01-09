//============================================================================
// Name        : DepthFirstSearch.cpp
// Author      : Vladimir Plagov
// Version     : v1.0
// Copyright   : Your copyright notice
// Description : Depth First Search algorithm
//============================================================================

#include <iostream>
#include <list>
#include <queue>
#include <map>
using namespace std;

template<typename T>
class Graph {

	map <T, list<T> > l;

public:
	void addEdge(T e1, T e2){
		l[e1].push_back(e2);
		l[e2].push_back(e1);
	}

	void dfs(T src){

		map<T, bool> visited;

		for (auto p:l) {
			T node = p.first;
			visited[node] = false;
		}

		dfs_helper(src, visited);


	}

	void dfs_helper(T src, map<T, bool> &visited){


		cout << "To " << src << " ";
		visited[src] = true;

		for (T neighbor : l[src]) {
			if(!visited[neighbor]) {
				dfs_helper(neighbor, visited);
			}
		}

	}


};


int main() {

	Graph<string> graph;

	graph.addEdge("Drochia", "Soroca");
	graph.addEdge("Drochia", "Balti");
	graph.addEdge("Balti", "Soroca");
	graph.addEdge("Balti", "Chisinau");
	graph.addEdge("Chisinau", "Tiraspol");
	graph.addEdge("Chisinau", "Orhei");
	graph.addEdge("Chisinau", "Cimislia");
	graph.addEdge("Chisinau", "Cazaclia");
	graph.addEdge("Cimislia", "Cazaclia");
	graph.addEdge("Cimislia", "Taraclia");
	graph.addEdge("Cazaclia", "Taraclia");
	graph.addEdge("Taraclia", "Vulcanesti");


	Graph<char> g;

	g.addEdge('A','B');
	g.addEdge('A','F');
	g.addEdge('A','L');
	g.addEdge('B','C');
	g.addEdge('B','D');
	g.addEdge('B','E');
	g.addEdge('F','G');
	g.addEdge('F','H');
	g.addEdge('F','K');
	g.addEdge('L','M');
	g.addEdge('L','N');
	g.addEdge('L','O');

	g.dfs('A');

}
