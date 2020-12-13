#pragma once

#include "../source/Dijkstra/Dijkstra.hpp"
#include "../source/Graph/Graph.hpp"
#include "../tests/Informator/Informator.hpp"

class DijkstraTester {
private:
    Graph graph;

    void Test1();

public:
    DijkstraTester();
};

DijkstraTester::DijkstraTester() {
    int **matrix = new int*[3];
    for (int i = 0; i < 3; ++i) {
        matrix[i] = new int[3];
    }

    matrix[0][0] = 0;
    matrix[0][1] = 1;
    matrix[0][2] = 1;
    matrix[1][0] = 4;
    matrix[1][1] = 0;
    matrix[1][2] = 1;
    matrix[2][0] = 2;
    matrix[2][1] = 1;
    matrix[2][2] = 0;

    this->graph = Graph(3, matrix);

    this->Test1();
}

void DijkstraTester::Test1() {
    Dijkstra dijkstra = Dijkstra(this->graph, 2);

    Informator(
            (dijkstra.getDistance(1) == 3 && dijkstra.showPath(1) == "2 3 1 "),
            "Success: correct length and path",
            "Error: incorrect length and path"
            );
}
