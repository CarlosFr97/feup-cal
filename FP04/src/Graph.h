/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
using namespace std;

template <class T> class Edge;
template <class T> class Graph;

template <class T>
class Vertex {
	T info;
	vector<Edge<T>  > adj;
	bool visited;
public:
	Vertex(T in);
	friend class Graph<T>;
};


template <class T>
Vertex<T>::Vertex(T in): info(in), visited(false){}


template <class T>
class Edge {
	Vertex<T> * dest;
	double weight;
public:
	Edge(Vertex<T> *d, double w);
	friend class Graph<T>;
	friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w){}

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;
public:
	vector<Vertex<T> * > getVertexSet() const;
	int getNumVertex() const;
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	vector<T> dfs() const;
	void dfs(Vertex<T> *v, vector<T> &res) const;
	vector<T> bfs(Vertex<T> *v) const;
	vector<T> bfs(Vertex<T> *v, vector<T> &res) const;

};

template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}
template <class T>
vector<Vertex<T> * > Graph<T>::getVertexSet() const {
	return vertexSet;
}

template <class T>
bool Graph<T>::addVertex(const T &in)
{

	for(int i=0; i< vertexSet.size(); i++)
	{
		if(vertexSet[i]->info == in)
		{
			return false;
		}
	}
	Vertex<T> *v1 = new Vertex<T>(in);
	vertexSet.push_back(v1);
	return true;

}

template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w)
{
	int foundsrc { -1 };
	int founddest { -1 };

	for(unsigned int i=0; i < vertexSet.size(); i++)
	{
		if(vertexSet[i]->info == sourc)
		{

			foundsrc = i;
		}
		else if(vertexSet[i]->info == dest)
		{
			founddest = i;
		}

	}
	Vertex<T> *v1 = vertexSet[foundsrc];
	if(foundsrc == -1 || founddest == -1)
		return false;

	for(unsigned int j=0; j<v1->adj.size(); j++)
	{
		if(v1->adj[j].dest == vertexSet[founddest])
		return false;
	}
	Edge<T> e1(vertexSet[founddest], w);
	v1->adj.push_back(e1);
	return true;
}

template <class T>
vector<T> Graph<T>::dfs() const
{
	for(int i=0; i<vertexSet.size(); i++)
	{
		vertexSet[i]->visited = false;
	}

	typename vector<Vertex<T>*>::const_iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::const_iterator ite = vertexSet.end();

	vector<T> res;

	for(;it!= ite; it++)
	{
		if((*it)->visited == false)
		{
			dfs(*it, res);
		}
	}
	return res;
}

template <class T>
vector<T> Graph<T>::bfs(Vertex<T> *v) const
{
	for(int i=0; i<vertexSet.size(); i++)
	{
			vertexSet[i]->visited = false;
	}

	vector<T> res;

	typename vector<Vertex<T>*>::const_iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::const_iterator ite = vertexSet.end();
	for(;it!= ite; it++)
	{

	}

	dfs(v, res);
	return res;

}

template <class T>
vector<T> Graph<T>::bfs(Vertex<T> *v, vector<T> &res) const



template <class T>
void Graph<T>::dfs(Vertex<T> *v, vector<T> &res) const
{

	v->visited = true;
	res.push_back(v->info);
	typename vector<Edge<T>>::const_iterator it = v->adj.begin();
	typename vector<Edge<T>>::const_iterator ite = v->adj.end();

	for(;it != ite; it++)
	{
		if(it->dest->visited == false)
			dfs(it->dest, res);
	}

}


#endif /* GRAPH_H_ */
