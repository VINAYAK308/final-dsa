#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

struct node {
    string vertex;
    int time;
    node* next;
};

class adjmatlist {
    int m[20][20], n;
    string v[20];
    node* head[20];

public:
    adjmatlist() {
        for (int i = 0; i < 20; i++) {
            head[i] = NULL;
        }
    }

    void getgraph();
    void adjlist();
    void displaym();
    void displaya();
};

void adjmatlist::getgraph() {
    cout << "\nEnter number of cities (max 20): ";
    cin >> n;

    cout << "Enter names of cities:\n";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "\nIs there a path between " << v[i] << " and " << v[j] << "? (y/n): ";
            cin >> ch;

            if (ch == 'y') {
                cout << "Enter time (in minutes) to reach " << v[j] << " from " << v[i] << ": ";
                cin >> m[i][j];
            } else if (ch == 'n') {
                m[i][j] = 0;
            } else {
                cout << "Invalid input! Defaulting to 0.\n";
                m[i][j] = 0;
            }
        }
    }

    adjlist(); // Convert to adjacency list after input
}

void adjmatlist::adjlist() {
    for (int i = 0; i < n; i++) {
        // Create head node for each city
        node* p = new node;
        p->vertex = v[i];
        p->time = 0; // Head node represents the city itself
        p->next = NULL;
        head[i] = p;

        // Add connections as linked nodes
        for (int j = 0; j < n; j++) {
            if (m[i][j] != 0) {
                node* newNode = new node;
                newNode->vertex = v[j];
                newNode->time = m[i][j];
                newNode->next = NULL;

                node* temp = head[i];
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode;
            }
        }
    }
}

void adjmatlist::displaym() {
    cout << "\nAdjacency Matrix:\n\t";
    for (int j = 0; j < n; j++) {
        cout << v[j] << "\t";
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << v[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
}

void adjmatlist::displaya() {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < n; i++) {
        node* temp = head[i];
        while (temp != NULL) {
            cout << temp->vertex;
            if (temp->time > 0)
                cout << " [" << temp->time << " min]";
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << "\n";
    }
}

int main() {
    int choice;
    adjmatlist graph;

    while (1) {
        cout << "\n\nMenu:\n";
        cout << "1. Enter Graph\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Display Adjacency List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: graph.getgraph();
                    break;
            case 2: graph.displaym();
                    break;
            case 3: graph.displaya();
                    break;
            case 4: exit(0);
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}



// Menu:
// 1. Enter Graph
// 2. Display Adjacency Matrix
// 3. Display Adjacency List
// 4. Exit
// Enter your choice: 1

// Enter number of cities (max 20): 3    
// Enter names of cities:
// Pune 
// Mumbai
// Nashik

// Is there a path between Pune and Pune? (y/n): n

// Is there a path between Pune and Mumbai? (y/n): y
// Enter time (in minutes) to reach Mumbai from Pune: 120

// Is there a path between Pune and Nashik? (y/n): y
// Enter time (in minutes) to reach Nashik from Pune: 180

// Is there a path between Mumbai and Pune? (y/n): y
// Enter time (in minutes) to reach Pune from Mumbai: 120

// Is there a path between Mumbai and Mumbai? (y/n): n

// Is there a path between Mumbai and Nashik? (y/n): y
// Enter time (in minutes) to reach Nashik from Mumbai: 90

// Is there a path between Nashik and Pune? (y/n): y
// Enter time (in minutes) to reach Pune from Nashik: 180

// Is there a path between Nashik and Mumbai? (y/n): y
// Enter time (in minutes) to reach Mumbai from Nashik: 90

// Is there a path between Nashik and Nashik? (y/n): n


// Menu:
// 1. Enter Graph
// 2. Display Adjacency Matrix
// 3. Display Adjacency List
// 4. Exit
// Enter your choice: 2

// Adjacency Matrix:
//         Pune    Mumbai  Nashik
// Pune    0       120     180
// Mumbai  120     0       90
// Nashik  180     90      0


// Menu:
// 1. Enter Graph
// 2. Display Adjacency Matrix
// 3. Display Adjacency List
// 4. Exit
// Enter your choice: 3

// Adjacency List:
// Pune -> Mumbai [120 min] -> Nashik [180 min]
// Mumbai -> Pune [120 min] -> Nashik [90 min]
// Nashik -> Pune [180 min] -> Mumbai [90 min]


// Menu:
// 1. Enter Graph
// 2. Display Adjacency Matrix
// 3. Display Adjacency List
// 4. Exit
// Enter your choice: 4
