#pragma once

#include "node.h"
#include <iostream>
#include <fstream>
#include <set>
#include <list>
#include <vector>
#include <algorithm>
#include "cstring"

using namespace std;

class GraphList {
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
                if ((dist[min_index] + (it->cost)) < dist[it->dest]) {
                    dist[it->dest] = (dist[min_index] + (it->cost));
                }
            }
        }
    }

    void addEdge(int source, int dest, int cost) {
        node newNode;
        newNode.dest = dest;
        newNode.cost = cost;
        adjList[source].push_back(newNode);
    }

public:
    GraphList() {
        ifstream fin("Testing/graph.txt");
        string temp;
        getline(fin, temp);
        int number = 0;
        int order = 1;
        for (char i : temp) {
            number += (i - 48) * order;
            order *= 10;
        }
        number = 0;
        order = 1;
        this->vertices_num = number;
        temp.clear();
        while (getline(fin, temp)) {
            int num_of_spaces = 0;
            int first_index, second_index;
            for (char i : temp) {
                if (i == ' ') {
                    number = 0;
                    order = 1;
                    ++num_of_spaces;
                    continue;
                }
                number += (i - 48) * order;
                order *= 10;
                if (num_of_spaces == 0) {
                    first_index = number;
                } else if (num_of_spaces == 1) {
                    second_index = number;
                } else if (num_of_spaces == 2) {
                    this->addEdge(first_index, second_index, number);
                }
            }
            temp.clear();
        }
        fin.close();
    }

    int getVerticesNum() const {
        return this->vertices_num;
    }

    void Search(int* dist, int start) {
        dijkstra(dist, start);
    }
};
