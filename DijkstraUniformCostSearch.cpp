//============================================================================
// Name        : Dijkstra(Uniform-Cost)Search.cpp
// Author      : Vladimir Plagov
// Version     : v1.0
// Copyright   : Your copyright notice
// Description : Dijkstra's Shortest Path or Uniform Cost Search algorithm
//============================================================================

#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>

using namespace std;

#define INF INT_MAX;


template<typename T>
class Graph {

	unordered_map<T, list<  pair<T, int> > > m;
	map<T, bool> visited;

public:

	void addEdge(T e1, T e2, int weight) {
		m[e1].push_back( make_pair(e2, weight) );
		m[e2].push_back( make_pair(e1, weight) );
	}

	void printNeighbors() {

		cout << "Adjacent cities and distances: \n";
		for (auto city:m){
			cout << city.first << " -> ";

			for(auto neighbor:city.second) {
				cout << "(" << neighbor.first << ", Distance: " << neighbor.second << ") ";
			}

			cout << "\n";
		}
	}

	void dijkstra(T src, T goal){

		//A table which will store information about the shortest distance to the node and its parent
		//distance[NODE].first - shortest distance to NODE from src
		//distance[NODE].second - NODE's parrent with the shortest path coming from src
		unordered_map<T, pair <int, T> > distance;

		//Set all the distances to infinity
		for (auto city:m) {
			distance[city.first].first = INF;
		}

		//Set all the nodes to be unvisited
		for(auto city:m){
			T node = city.first;
			visited[node] = false;
		}

		//Create a set, which will always be sorted and will tell us what city to go next
		set<pair<int, T> > next;

		distance[src].first = 0;
		distance[src].second = src;

		next.insert(make_pair(0,src));

		while(!next.empty()) {

			auto p = *(next.begin());

			T node = p.second;
			int currDist = p.first;

			next.erase(p);
			visited[node] = true;

			for (auto neighbor:m[node]) {
				if ( (neighbor.second + currDist < distance[neighbor.first].first) && !visited[neighbor.first] ) {
					distance[neighbor.first] = make_pair(neighbor.second + currDist, node);
					next.insert(make_pair(neighbor.second + currDist, neighbor.first));
				}
			}

		}

		cout << "Shortest distances from " << src << " to every city: \n";

		cout << "From " << src << " to: \n";

		for (auto city:distance) {
			cout << city.first << " the distance is " << city.second.first << " coming from " << city.second.second << endl;
		}

		cout << "\nThe shortest path from " << src << " to " << goal <<  ": " ;
		string path = "";

		T current = goal;
		stack<T> stack;
		stack.push(goal);

		while (current != src){
			stack.push(distance[current].second);
			current = distance[current].second;
		}

		while(!stack.empty()) {
			path += stack.top() + "->";
			stack.pop();
		}

		cout << path.substr(0, path.length()-2);

	}

};


int main() {

	Graph<string> md;

	md.addEdge("Drochia", "Soroca", 4);
	md.addEdge("Drochia", "Balti", 2);
	md.addEdge("Balti", "Soroca", 5);
	md.addEdge("Balti", "Chisinau", 4);
	md.addEdge("Chisinau", "Tiraspol", 5);
	md.addEdge("Chisinau", "Orhei", 6);
	md.addEdge("Chisinau", "Cimislia", 7);
	md.addEdge("Chisinau", "Cazaclia", 8);
	md.addEdge("Cimislia", "Cazaclia", 3);
	md.addEdge("Cimislia", "Taraclia", 7);
	md.addEdge("Cazaclia", "Taraclia", 2);
	md.addEdge("Taraclia", "Vulcanesti", 5);


	md.printNeighbors();
	cout << endl;

	md.dijkstra("Drochia", "Taraclia");
}
