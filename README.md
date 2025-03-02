[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

void addWaypointAtBeginning(T& data);
    This function inserts a new node at the begining of the list. It updates the 
    head pointer so that it points to the new node. The new node's next pointer 
    points to the old head, and its previous pointer points to null. If the list 
    was empty, it creates the first node, which is both the head and the tail.

    The time complexity is O(1). The location of the first node is already known by head, 
    so there is no traversing needed to add the new node. All other commands have O(1) time.


void addWaypointAtEnd(T& data);
    This function inserts a new node at the end of the list. It updates the tail pointer so that
    it points to the new node. The new node's previous pointer points to the old tail, and 
    its next pointer points to null. If the list was empty, it creates the first node, which is 
    both the head and the tail.

    The time complexity is O(1). The location of the last node is already known by tail,
    so there is no traversing needed to add the new node. All other commands have O(1) time.

void addWaypointAtIndex(int index, T& data);
    This function inserts a new node at a user-specified index in the list. If the given index 
    is less than 0, or greater than the preexisting list's length, an error message will be printed.
    The new node's next pointer points to the node that was previously in the specified index.

    The time complexity is O(n). The function calls the getWaypoint() function, which traverses 
    through the array up to the given index, which could be up to the last node in the worst case 
    scenario. That yields an O(n) time complexity. Every other command in the function runs to O(1)
    so only the O(n) is considered. 

void removeWaypointAtBeginning();
void removeWaypointAtEnd();
void removeWaypointAtIndex(int index);
void traverseForward();
void traverseBackward();
Node<T>* getWaypoint(int index);
void setWaypoint(int index, T& data);
void print();
