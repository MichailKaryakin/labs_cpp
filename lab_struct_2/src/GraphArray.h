#pragma once

#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include "cstring"

using namespace std;

class GraphArray {
    int vertices_num;
    int** adjMatrix;
private:
    void dijkstra(int* dist, int start) {
        int i, v, w, S[5] = {0};
        S[start] = 1;
        for (i = 0; i < this->vertices_num; i++) {
            dist[i] = this->adjMatrix[start][i];
        }
        dist[start] = 9999;
        for (i = 2; i < this->vertices_num; i++) {
            for (w = start, v = 0; v < vertices_num; v++) {
                if (!S[v] && dist[v] < dist[w]) w = v;
            }
            S[w] = 1;
            for (v = 0; v < vertices_num; v++) {
                if (dist[w] + this->adjMatrix[w][v] < dist[v]) {
                    dist[v] = dist[w] + this->adjMatrix[w][v];
                }
            }
        }
        dist[start] = 0;
    }

public:
    GraphArray() {
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
        adjMatrix = new int* [vertices_num];
        for (int i = 0; i < vertices_num; i++) {
            adjMatrix[i] = new int[vertices_num];
        }
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
                    adjMatrix[first_index][second_index] = number;
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
