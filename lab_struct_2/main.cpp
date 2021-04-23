#include <iostream>
#include "src/GraphList.h"

#define num_of_cities 4

int main() {
    int n = num_of_cities;
    Graph graph(n);
    int dist[n];

    graph.addEdge(0, 1, 44);
    graph.addEdge(0, 2, 44);
    graph.addEdge(0, 3, 44);
    graph.addEdge(2, 0, 44);
    graph.addEdge(3, 0, 44);

    for (int i = 0; i < n; i++) {
        graph.Search(dist, i);
        bool check = true;
        for (int j : dist) {
            if (j > 100) {
                check = false;
                break;
            }
        }
        if (check) {
            printf("from city %d there is a path less than 100 km to any other city\n", i);
        }
    }
}
