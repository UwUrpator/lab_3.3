#pragma once

class NodesStates {
private:
    struct NodeState {
        int distance;
        bool state;

        NodeState() {
            this->distance = constants::GLOBAL_INF;
            this->state = false;
        }
    };

    NodeState* states;

public:
    NodesStates();

    NodesStates(int count);

    int getDistanceTo(int nodeIndex);

    void setDistanceTo(int nodeIndex, int newDistance);

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

bool NodesStates::getStateOf(int nodeIndex) {
    return this->states[nodeIndex].state;
}

void NodesStates::setStateOf(int nodeIndex, bool newState) {
    this->states[nodeIndex].state = newState;
}
