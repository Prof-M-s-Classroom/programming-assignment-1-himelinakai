#include <iostream>
#include <string>
#include "SpaceRoute.cpp"

using namespace std;

int main() {
    string mars = "Mars";
    string jupiter = "Jupiter";
    string saturn = "Saturn";
    string earth = "Earth";
    string venus = "Venus";

    SpaceRoute<string> voyagerRoute;

    voyagerRoute.addWaypointAtEnd(mars);

    voyagerRoute.addWaypointAtEnd(jupiter);
    voyagerRoute.addWaypointAtEnd(saturn);
    voyagerRoute.addWaypointAtBeginning(earth);
    voyagerRoute.addWaypointAtIndex(2, venus);

    // i added
    /*
    voyagerRoute.print();

    voyagerRoute.setWaypoint(2, earth);


    /*
    Node<string> *test = voyagerRoute.getWaypoint(2);
    if (test != NULL) {
        test->print();
    }
    cout << endl;

    /*
    voyagerRoute.removeWaypointAtBeginning();
    voyagerRoute.removeWaypointAtEnd();
    voyagerRoute.removeWaypointAtIndex(2);
    */

    //voyagerRoute.removeWaypointAtIndex(-1);

    // i added



    cout << "Voyager Route (Forward):\n";
    voyagerRoute.traverseForward();

    cout << "\nVoyager Route (Backward):\n";
    voyagerRoute.traverseBackward();

    cout << "\nPrinting Route: \n";
    voyagerRoute.print();

    voyagerRoute.removeWaypointAtIndex(2);
    cout << "\nAfter Removing Venus: \n";

    voyagerRoute.print();

    return 0;
}