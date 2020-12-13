#pragma once

#include "../Graph/NodesStates.hpp"
#include "../Graph/Graph.hpp"

extern const int infinity;

class Dijkstra {
private:
    Graph graph;
    NodesStates nodesStates;

    void init(int node);

    void relax(int node);

    int findMin();

public:
    Dijkstra(Graph graph, int node);

    int getDistance(int node);
};

Dijkstra::Dijkstra(Graph graph, int node) {
    node--;

    this->graph = graph;

    this->init(node);
    this->relax(node);
    for (int i = this->findMin(); i != -1; i = this->findMin()) {
        this->nodesStates.setState(i, true);
        this->relax(i);
    }
}

void Dijkstra::init(int node) {
    this->nodesStates = NodesStates(graph.getCount());

    this->nodesStates.setDistanceTo(node, 0);
    this->nodesStates.setStateOf(node, true);
}

void Dijkstra::relax(int node) {
    for (int i = 0; i < this->graph.getCount(); ++i) {
        if (this->nodesStates.getDistanceTo(i) > this->nodesStates.getDistanceTo(node) + this->graph.getEdge(node, i))
            this->nodesStates.setDistanceTo(i, this->nodesStates.getDistanceTo(node) + this->graph.getEdge(node, i));
    }
}

int Dijkstra::findMin() {
    int min = -1;
    int dist = infinity;

    for (int i = 0; i < this->graph.getCount(); ++i) {
        if (this->nodesStates.getDistanceTo(i) < dist && !this->nodesStates.getStateOf(i)) {
            min = i;
            dist = this->nodesStates.getDistanceTo(i);
        }
    }

    return min;
}

int Dijkstra::getDistance(int node) {
    node--;

    return this->nodesStates.getDistanceTo(node);
}
