#include<iostream>
using namespace std;

class OptimalBST {
    int keys[10], root[10][10], numKeys;
    float successProb[10], failureProb[10], weight[10][10], cost[10][10];

public:
    void acceptInput();
    void constructOBST();
    int findOptimalRoot(int, int);
    void displayTree(int, int);
};

void OptimalBST::acceptInput() {
    cout << "Enter number of keys: ";
    cin >> numKeys;

    cout << "Enter the " << numKeys << " keys in sorted order:\n";
    for (int i = 1; i <= numKeys; i++) {
        cin >> keys[i];
    }

    cout << "Enter the " << numKeys << " success probabilities for each key:\n";
    for (int i = 1; i <= numKeys; i++) {
        cin >> successProb[i];
    }

    cout << "Enter the " << numKeys + 1 << " failure probabilities (between keys):\n";
    for (int i = 0; i <= numKeys; i++) {
        cin >> failureProb[i];
    }
}

void OptimalBST::constructOBST() {
    for (int i = 0; i < numKeys; i++) {
        weight[i][i] = failureProb[i];
        cost[i][i] = 0;
        root[i][i] = 0;

        weight[i][i + 1] = failureProb[i] + failureProb[i + 1] + successProb[i + 1];
        cost[i][i + 1] = weight[i][i + 1];
        root[i][i + 1] = i + 1;
    }

    weight[numKeys][numKeys] = failureProb[numKeys];
    cost[numKeys][numKeys] = 0;
    root[numKeys][numKeys] = 0;

    for (int length = 2; length <= numKeys; length++) {
        for (int i = 0; i <= numKeys - length; i++) {
            int j = i + length;
            weight[i][j] = weight[i][j - 1] + successProb[j] + failureProb[j];

            int optimalRoot = findOptimalRoot(i, j);
            cost[i][j] = weight[i][j] + cost[i][optimalRoot - 1] + cost[optimalRoot][j];
            root[i][j] = optimalRoot;
        }
    }

    cout << "Root of OBST is key: " << keys[root[0][numKeys]] << "\n";
    cout << "Left child of root:\n";
    displayTree(0, root[0][numKeys] - 1);
    cout << "Right child of root:\n";
    displayTree(root[0][numKeys], numKeys);
}

int OptimalBST::findOptimalRoot(int i, int j) {
    int minCost = 999;
    int optimalRoot = 0;

    for (int k = root[i][j - 1]; k <= root[i + 1][j]; k++) {
        int currentCost = cost[i][k - 1] + cost[k][j];
        if (currentCost < minCost) {
            minCost = currentCost;
            optimalRoot = k;
        }
    }
    return optimalRoot;
}

void OptimalBST::displayTree(int i, int j) {
    if (root[i][j] == 0) {
        cout << "NULL\n";
        return;
    }

    int rootIndex = root[i][j];
    cout << "Key: " << keys[rootIndex] << "\n";

    cout << "Left child of " << keys[rootIndex] << ":\n";
    displayTree(i, rootIndex - 1);

    cout << "Right child of " << keys[rootIndex] << ":\n";
    displayTree(rootIndex, j);
}

int main() {
    OptimalBST obst;
    obst.acceptInput();
    obst.constructOBST();
    return 0;
}




// Enter number of keys: 3
// Enter the 3 keys in sorted order:
// 10 20 30 
// Enter the 3 success probabilities for each key:
// 0.3 0.2 0.1
// Enter the 4 failure probabilities (between keys):
// 0.1 0.1 0.1 0.1
// Root of OBST is key: 10
// Left child of root:
// NULL
// Right child of root:
// Key: 20
// Left child of 20:
// NULL
// Right child of 20:
// Key: 30
// Left child of 30:
// NULL
// Right child of 30:
// NULL
