//============================================================================
// Name        : BreadthFirstSearch.cpp
// Author      : Vladimir Plagov
// Version     : v1.0
// Copyright   : Your copyright notice
// Description : Breadth First Search algorithm
//============================================================================

#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;


template<typename T>
class Graph {

	map<T,list<T> > l;

public:

	void addEdge(T e1, T e2) {
		l[e1].push_back(e2);
		l[e2].push_back(e1);
	}

	void bfs(T src, T goal) {

		map<T, bool> visited; //map<T, int> ???
		queue<T> queue;

		queue.push(src);
		visited[src] = true;

		while (!queue.empty()) {

			T node = queue.front();
			queue.pop();
			cout << "To " << node << " ";
			if (node == goal) break;

			for (T neighbor:l[node]) {
				if(!visited[neighbor]) {
					queue.push(neighbor);
					visited[neighbor] = true;
				}
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


	graph.bfs("Taraclia", "Tiraspol");

}
