#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T& data;
    Node* next;
    Node* prev;

    Node(T& d) : data(d), next(nullptr), prev(nullptr) {}
    void print() { cout << data << " "; }
};

class CelestialNode {
private:
    string name;
    double distance_from_earth;
    string mission_log;

public:
    CelestialNode(const string& n, double d, const string& log);
    const string& getName() const;
    double getDistance() const;
    const string& getMissionLog() const;
    void print() const { cout << name << " (" << distance_from_earth << " AU) - " << mission_log << endl; }
};

template <typename T>
class SpaceRoute {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    SpaceRoute()  // Constructor
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~SpaceRoute() // Destructor
    {
        Node<T> *current = this->head;
        while (head) {
            head = head->next;
            delete current;
            current = head;
        }
    }

    void addWaypointAtBeginning(T& data) {
        Node<T> *newNode = new Node<T>(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            newNode->prev = nullptr;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addWaypointAtEnd(T& data) {
        Node<T> *newNode = new Node<T>(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = nullptr;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addWaypointAtIndex(int index, T& data) {
        if (index < 0) {
            cout << "Invalid index." << endl;
            return;
        }

        if (index == 0) {
            addWaypointAtBeginning(data);
            return;
        }

        Node<T> *current = head;
        Node<T> *newNode = new Node<T>(data);

        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Invalid index." << endl;
            return;
        }

        if (current == tail) {
            addWaypointAtEnd(data);
            return;
        }

        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    void removeWaypointAtBeginning() {
        if (head == nullptr) {
            cout << "Journey has not started. No waypoints yet." << endl;
            return;
        }

        Node<T> *current = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete current;

    }

    void removeWaypointAtEnd() {
        if (head == nullptr) {
            cout << "Journey has not started. No waypoints yet." << endl;
            return;
        }

        Node<T> *current = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        delete current;
    }

    void removeWaypointAtIndex(int index);
    void traverseForward();
    void traverseBackward();
    Node<T>* getWaypoint(int index);

    void setWaypoint(int index, T& data) {

    }


    void print(){
    /*
        Node<T>* current = head;
        while (current) {
            current->print();
            current = current->next;
        }
        cout << endl;
        */

        Node<T> *current = this->head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

};

