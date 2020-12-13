#pragma once

class NodesStates {
private:
    struct NodeState {
        int distance;
        int parent;
        bool state;

        NodeState() {
            this->distance = constants::GLOBAL_INF;
            this->parent = -1;
            this->state = false;
        }
    };

    NodeState* states;

public:
    NodesStates();

    NodesStates(int count);

    int getDistanceTo(int nodeIndex);

    void setDistanceTo(int nodeIndex, int newDistance);

    int getParentOf(int nodeIndex);

    void setParentOf(int nodeIndex, int newParent);

    bool getStateOf(int nodeIndex);

    void setStateOf(int nodeIndex, bool newState);
};

NodesStates::NodesStates() {
    this->states = nullptr;
}

NodesStates::NodesStates(int count) {
    this->states = new NodeState[count];
}

int NodesStates::getDistanceTo(int nodeIndex) {
    return this->states[nodeIndex].distance;
}

void NodesStates::setDistanceTo(int nodeIndex, int newDistance) {
    this->states[nodeIndex].distance = newDistance;
}

int NodesStates::getParentOf(int nodeIndex) {
    return this->states[nodeIndex].parent;
}

void NodesStates::setParentOf(int nodeIndex, int newParent) {
    this->states[nodeIndex].parent = newParent;
}

bool NodesStates::getStateOf(int nodeIndex) {
    return this->states[nodeIndex].state;
}

void NodesStates::setStateOf(int nodeIndex, bool newState) {
    this->states[nodeIndex].state = newState;
}
