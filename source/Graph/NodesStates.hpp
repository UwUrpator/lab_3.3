#pragma once

extern const int infinity;

class NodesStates {
private:
    struct NodeState {
        int distance;
        bool state;

        NodeState() {
            this->distance = 0;
            this->state = false;
        }
    };

    int size;
    NodeState* states;

public:
    NodesStates(int size);

    int getDistanceTo(int nodeIndex);

    void setDistanceTo(int nodeIndex, int newDistance);

    bool getStateOf(int nodeIndex);

    void setStateOf(int nodeIndex, bool newState);
};

NodesStates::NodesStates(int size) {
    this->size = size;
    this->states = new NodeState[size];
}

int NodesStates::getDistanceTo(int nodeIndex) {
    return this->states[nodeIndex].distance;
}

void NodesStates::setDistanceTo(int nodeIndex, int newDistance) {
    this->states[nodeIndex].distance = newDistance;
}

bool NodesStates::getStateOf(int nodeIndex) {
    return this->states[nodeIndex].state;
}

void NodesStates::setStateOf(int nodeIndex, bool newState) {
    this->states[nodeIndex].state = newState;
}
