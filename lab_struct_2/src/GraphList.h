#pragma once

#include <iostream>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

typedef struct nodes {
    int dest;
    int cost;
} node;

class Graph {
    int vertices_num;
    list <node>* adjList;
private:
    void dijkstra(int* dist, int start) {
        int verticesNum = this->vertices_num;

        for (int u = 0; u < verticesNum; u++) {
            dist[u] = 9999;
        }
        dist[start] = 0;

        list<int> elements;
        for (int u = 0; u < verticesNum; u++) {
            elements.push_back(u);
        }

        set<int> set;
        while (!elements.empty()) {
            int min = INT_MAX;
            int min_index;
            int i;
            for (i = 0; i < verticesNum; ++i) {
                bool is_in_set = set.find(i) != set.end();
                if (dist[i] < min && !is_in_set) {
                    min = dist[i];
                    min_index = i;
                }
            }
            set.insert(min_index);

            elements.remove(min_index);

            list<node>::iterator it;
            for (it = this->adjList[min_index].begin(); it != this->adjList[min_index].end(); it++) {
                if ((dist[min_index]+(it->cost)) < dist[it->dest]) {
                    dist[it->dest] = (dist[min_index]+(it->cost));
                }
            }
        }
    }

public:
    Graph() {
        vertices_num = 0;
    }

    Graph(int nodeCount) {
        vertices_num = nodeCount;
        adjList = new list<node>[vertices_num];
    }

    void addEdge(int source, int dest, int cost) {
        node newNode;
        newNode.dest = dest;
        newNode.cost = cost;
        adjList[source].push_back(newNode);
    }

    void Search(int* dist, int start) {
        dijkstra(dist, start);
    }
};
