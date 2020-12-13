#pragma once

class Graph {
private:
    int count;
    int** matrix;

public:
    Graph();
    Graph(int count, int** matrix);

    int getEdge(int node1, int node2);

    int getCount();

    void operator=(const Graph graph);
};

Graph::Graph() {
    this->count = 0;
    this->matrix = nullptr;
}

Graph::Graph(int count, int **matrix) {
    this->count = count;
    this->matrix = matrix;
}

int Graph::getEdge(int node1, int node2) {
    return this->matrix[node1][node2];
}

int Graph::getCount() {
    return this->count;
}

void Graph::operator=(const Graph graph) {
    this->count = graph.count;
    this->matrix = graph.matrix;
}

