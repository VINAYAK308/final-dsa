#include<iostream>
#include<climits>
using namespace std;

class tree
{
    int a[20][20], start, end, weight, vertex, edge, visited[20];
public:
    void input();
    void display();
    void minimum();
};

void tree::input()
{
    cout << "\nEnter the number of branches: ";
    cin >> vertex;

    for (int i = 0; i < vertex; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < vertex; j++)
        {
            a[i][j] = INT_MAX;
        }
    }

    cout << "Enter the number of connections: ";
    cin >> edge;

    for (int i = 0; i < edge; i++)
    {
        cout << "Enter the end branches of connection (e.g., 1 2): ";
        cin >> start >> end;
        cout << "Enter the phone company charges for this connection: ";
        cin >> weight;
        a[start - 1][end - 1] = a[end - 1][start - 1] = weight;
    }
}

void tree::display()
{
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            if (a[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void tree::minimum()
{
    int from = 0, to = 0, totalCost = 0, minCost;

    for (int i = 0; i < vertex; i++)
        visited[i] = 0;

    visited[0] = 1; // Start from node 0

    for (int count = 0; count < vertex - 1; count++)
    {
        minCost = INT_MAX;

        for (int i = 0; i < vertex; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < vertex; j++)
                {
                    if (!visited[j] && a[i][j] < minCost)
                    {
                        minCost = a[i][j];
                        from = i;
                        to = j;
                    }
                }
            }
        }

        if (minCost == INT_MAX)
        {
            cout << "Graph is disconnected. MST not possible.\n";
            return;
        }

        visited[to] = 1;
        totalCost += minCost;
        cout << "Minimum cost connection: " << from + 1 << " -> " << to + 1 << " with charge: " << minCost << endl;
    }

    cout << "Total minimum cost to connect all branches: " << totalCost << endl;
}

int main()
{
    int ch;
    tree t;
    do
    {
        cout << "\n******** Prim's Algorithm ********" << endl;
        cout << "1. Input\n2. Display\n3. Minimum\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            t.input();
            break;
        case 2:
            t.display();
            break;
        case 3:
            t.minimum();
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (ch != 4);

    return 0;
}



// ******** Prim's Algorithm ********
// 1. Input
// 2. Display
// 3. Minimum
// 4. Exit
// Enter your choice: 1

// Enter the number of branches: 4
// Enter the number of connections: 5
// Enter the end branches of connection (e.g., 1 2): 1 2
// Enter the phone company charges for this connection: 5
// Enter the end branches of connection (e.g., 1 2): 1 3
// Enter the phone company charges for this connection: 10
// Enter the end branches of connection (e.g., 1 2): 2 3
// Enter the phone company charges for this connection: 3
// Enter the end branches of connection (e.g., 1 2): 2 4
// Enter the phone company charges for this connection: 2
// Enter the end branches of connection (e.g., 1 2): 3 4
// Enter the phone company charges for this connection: 6

// ******** Prim's Algorithm ********
// 1. Input
// 2. Display
// 3. Minimum
// 4. Exit
// Enter your choice: 2

// Adjacency Matrix:
// INF 5 10 INF 
// 5 INF 3 2 
// 10 3 INF 6 
// INF 2 6 INF 

// ******** Prim's Algorithm ********
// 1. Input
// 2. Display
// 3. Minimum
// 4. Exit
// Enter your choice: 3
// Minimum cost connection: 1 -> 2 with charge: 5
// Minimum cost connection: 2 -> 4 with charge: 2
// Minimum cost connection: 2 -> 3 with charge: 3
// Total minimum cost to connect all branches: 10

// ******** Prim's Algorithm ********
// 1. Input
// 2. Display
// 3. Minimum
// 4. Exit
// Enter your choice: 4
// Exiting program.