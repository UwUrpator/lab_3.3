#pragma once

#include "../source/Graph/Graph.hpp"
#include "../source/Dijkstra/Dijkstra.hpp"
#include "basic/SelectorUI.hpp"
#include "basic/SingleField.hpp"
#include "basic/MultiField.hpp"

class GraphUI {
private:
    Graph graph;

    int count, start, finish;
    int** matrix;

    void enterGraph();
    void enterParameters();
    int graphSelector();
    void DijkstraUI();

public:
    GraphUI();
};

GraphUI::GraphUI() {
    cout << endl;

    enterGraph();

    while (true) {
        int choice = this->graphSelector();
        switch (choice) {
            case 1:
                this->DijkstraUI();
                break;
            case 2:
                return;
        }
    }
}

void GraphUI::enterParameters() {
    this->start = SingleField<int>("Enter start node").item;
    this->finish = SingleField<int>("Enter finish node").item;
}

void GraphUI::enterGraph() {
    this->count = SingleField<int>("Enter amount of nodes").item;

    cout << endl << "Enter matrix of graph:" << endl;

    this->matrix = new int* [this->count];
    for (int i = 0; i < this->count; ++i) {
        this->matrix[i] = new int[this->count];
    }

    int node;

    for (int i = 0; i < this->count; ++i) {
        for (int j = 0; j < this->count; ++j) {
            cin >> node;
            if (node == -1) {
                this->matrix[i][j] = constants::GLOBAL_INF;
            }
            else {
                this->matrix[i][j] = node;
            }
        }
    }

    this->graph = Graph(this->count, this->matrix);
}

int GraphUI::graphSelector() {
    string answers[2] = {"Length of shortest path", "Exit"};
    return SelectorUI("What do you want to do", 2, answers).choice;
}

void GraphUI::DijkstraUI() {
    this->enterParameters();

    int dist = Dijkstra(this->graph, this->start).getDistance(this->finish);

    if (dist == constants::GLOBAL_INF) {
        cout << "No way between nodes" << endl;
    }
    else {
        cout << "Distance from " << this->start << " node to "
             << this->finish << " node is " << dist << endl;
    }
}
