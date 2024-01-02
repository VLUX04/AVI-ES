/**
 * @file Graph.h
 * @brief Header file that contains the implementation of a graph and all its wanted functionalities.
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <cstddef>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

/**
 * @class Vertex
 * @brief Represents a vertex of a graph.
 */
template <class T>
class Vertex {
    T info;                ///< contents
    vector<Edge<T> > adj;  ///< list of outgoing edges
    bool visited;          ///< auxiliary field
    bool processing;       ///< auxiliary field
    int indegree = 0;          ///< auxiliary field
    int num;               ///< auxiliary field
    int low;               ///< auxiliary field

    void addEdge(Vertex<T> *dest, basic_string<char> w);
public:
    Vertex(T in);
    T getInfo() const;
    bool isVisited() const;
    void setVisited(bool v);
    const vector<Edge<T>> &getAdj() const;

    int getIndegree() const;

    void setIndegree(int indegree);

    int getNum() const;

    void setNum(int num);

    int getLow() const;

    void setLow(int low);

    friend class Graph<T>;
};

/**
 * @class Edge
 * @brief Represents an edge of a graph.
 */
template <class T>
class Edge {
    Vertex<T> * dest;      ///< destination vertex
    string weight;         ///< edge weight
public:
    Edge(Vertex<T> *d, string w);
    Vertex<T> *getDest() const;
    string getWeight() const;
    friend class Graph<T>;
    friend class Vertex<T>;
};

/**
 * @class Graph
 * @brief Represents a graph and all its wanted functionalities.
 */
template <class T>
class Graph {
    vector<Vertex<T> *> vertexSet;      ///< vertex set
    int _index_;                        ///< auxiliary field
    stack<Vertex<T>> _stack_;           ///< auxiliary field
    list<list<T>> _list_sccs_;        ///< auxiliary field
public:
    Vertex<T> *findVertex(const T &in) const;
    bool addVertex(const T &in);
    bool addEdge(const T &sourc, const T &dest, string w);
    vector<Vertex<T> * > getVertexSet() const;
    vector<string> nodesAtDistanceBFS(const string &source, int k);
};

/****************** Provided constructors and functions ********************/

template <class T>
Vertex<T>::Vertex(T in): info(in) {}

template <class T>
Edge<T>::Edge(Vertex<T> *d, string w): dest(d), weight(w) {}

template <class T>
vector<Vertex<T> * > Graph<T>::getVertexSet() const {
    return vertexSet;
}

template<class T>
T Vertex<T>::getInfo() const {
    return info;
}

template<class T>
Vertex<T> *Edge<T>::getDest() const {
    return dest;
}


template<class T>
string Edge<T>::getWeight() const {
    return weight;
}


/**
 * @brief Auxiliary function to find a vertex with a given content.
 * @param in The vertex to search for.
 * @return A pointer to the vertex with the matching info, or nullptr if not found.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
}

template <class T>
bool Vertex<T>::isVisited() const {
    return visited;
}

template<class T>
int Vertex<T>::getIndegree() const {
    return indegree;
}

template<class T>
void Vertex<T>::setIndegree(int indegree) {
    Vertex::indegree = indegree;
}

template<class T>
int Vertex<T>::getNum() const {
    return num;
}

template<class T>
void Vertex<T>::setNum(int num) {
    Vertex::num = num;
}

template<class T>
int Vertex<T>::getLow() const {
    return low;
}

template<class T>
void Vertex<T>::setLow(int low) {
    Vertex::low = low;
}

template <class T>
void Vertex<T>::setVisited(bool v) {
    Vertex::visited = v;
}

template<class T>
const vector<Edge<T>> &Vertex<T>::getAdj() const {
    return adj;
}

/**
 *  @brief Adds a vertex with a given content or info (in) to a graph (this).
 *  @param in Vertex to add.
 *  @return Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
    if ( findVertex(in) != NULL)
        return false;
    vertexSet.push_back(new Vertex<T>(in));
    return true;
}


/**
 * @brief Adds an edge to a graph (this), given the contents of the source and
 *  destination vertices and the edge weight (w).
 * @param sourc The value of the source vertex.
 * @param dest The value of the destination vertex.
 * @param w The weight of the edge.
 * @return Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, string w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2,w);
    return true;
}

/**
 * @brief Auxiliary function to add an outgoing edge to a vertex (this),
 *  with a given destination vertex (d) and edge weight (w).
 * @param d Pointer to the destination vertex.
 * @param w The weight of the edge.
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, string w) {
    adj.push_back(Edge<T>(d, w));
}

template<class T>
vector<string> Graph<T>::nodesAtDistanceBFS( const string &source, int k) {

    vector<string> res;
    int count=0;
    for (auto b: getVertexSet()){
        b->setVisited(false);
    }
    auto a=findVertex(source);
    queue<Vertex<string>*> b;
    b.push(a);
    int s=1;
    int l=0;
    while(!b.empty()){
        auto d=b.front();
        b.pop();
        s--;
        if(k==count){
            res.push_back(d->getInfo());
        }
        for (auto e: d->getAdj()){
            auto q=e.getDest();
            if(!q->isVisited()){
                l++;
                q->setVisited(true);
                b.push(q);
            }
        }
        if (s==0){
            s=l;
            l=0;
            count++;
            if(count>k){
                break;
            }
        }
    }
    return res;
}

#endif /* GRAPH_H_ */
