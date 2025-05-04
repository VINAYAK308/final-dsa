#include<iostream>
using namespace std;

struct node {
    int data;
    node *L;
    node *R;
};

class bst {
    node *root;
    int count;

public:
    bst() {
        root = NULL;
        count = 0;
    }

    void create();
    void insert(node*, node*);
    void disin(node*);
    void dispre(node*);
    void dispost(node*);
    void search(node*, int);
    int height(node*);
    void mirror(node*);
    void min(node*);
    void menu(); // added for clarity
};

void bst::create() {
    char ans;
    node *temp;
    do {
        temp = new node;
        cout << "Enter the data: ";
        cin >> temp->data;
        temp->L = NULL;
        temp->R = NULL;

        if (root == NULL) {
            root = temp;
        } else {
            insert(root, temp);
        }

        cout << "Do you want to insert more value (y/n): ";
        cin >> ans;
        count++;
        cout << endl;
    } while (ans == 'y');

    cout << "The total number of nodes are: " << count << endl;
}

void bst::insert(node *root, node *temp) {
    if (temp->data > root->data) {
        if (root->R == NULL) {
            root->R = temp;
        } else {
            insert(root->R, temp);
        }
    } else {
        if (root->L == NULL) {
            root->L = temp;
        } else {
            insert(root->L, temp);
        }
    }
}

void bst::disin(node *root) {
    if (root != NULL) {
        disin(root->L);
        cout << root->data << "\t";
        disin(root->R);
    }
}

void bst::dispre(node *root) {
    if (root != NULL) {
        cout << root->data << "\t";
        dispre(root->L);
        dispre(root->R);
    }
}

void bst::dispost(node *root) {
    if (root != NULL) {
        dispost(root->L);
        dispost(root->R);
        cout << root->data << "\t";
    }
}

void bst::search(node *root, int key) {
    node *temp = root;
    int flag = 0;

    while (temp != NULL) {
        if (key == temp->data) {
            cout << "           KEY FOUND           \n";
            flag = 1;
            break;
        }
        if (key > temp->data) {
            temp = temp->R;
        } else {
            temp = temp->L;
        }
    }

    if (flag == 0) {
        cout << "            KEY NOT FOUND              " << endl;
    }
}

int bst::height(node *root) {
    if (root == NULL) {
        return 0;
    }

    int hl = height(root->L);
    int hr = height(root->R);
    return 1 + max(hl, hr);
}

void bst::min(node *root) {
    node *temp = root;
    if (temp == NULL) {
        cout << "Tree is empty!";
        return;
    }

    while (temp->L != NULL) {
        temp = temp->L;
    }
    cout << temp->data << endl;
}

void bst::mirror(node *root) {
    if (root != NULL) {
        mirror(root->L);
        mirror(root->R);
        node *temp = root->L;
        root->L = root->R;
        root->R = temp;
    }
}

void bst::menu() {
    int ch, key;
    char ans;

    do {
        cout << "\nMenu:\n";
        cout << "1) Insert new node\n2) Number of nodes in longest path\n3) Minimum\n4) Mirror\n";
        cout << "5) Search\n6) Inorder\n7) Preorder\n8) Postorder\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                cout << "\nNumber of nodes in longest path: " << height(root) << endl;
                break;
            case 3:
                cout << "\nThe min element is: ";
                min(root);
                break;
            case 4:
                mirror(root);
                cout << "\nThe mirror of the tree (inorder): ";
                disin(root);
                break;
            case 5:
                cout << "\nEnter your key: ";
                cin >> key;
                search(root, key);
                break;
            case 6:
                cout << "\n*************** INORDER **************\n";
                disin(root);
                break;
            case 7:
                cout << "\n*************** PREORDER **************\n";
                dispre(root);
                break;
            case 8:
                cout << "\n*************** POSTORDER **************\n";
                dispost(root);
                break;
            default:
                cout << "\nInvalid choice!";
        }

        cout << "\nDo you want to continue (y/n): ";
        cin >> ans;
    } while (ans == 'y');
}

int main() {
    bst tree;
    tree.menu();
    return 0;
}


// Menu:
// 1) Insert new node
// 2) Number of nodes in longest path
// 3) Minimum
// 4) Mirror
// 5) Search
// 6) Inorder
// 7) Preorder
// 8) Postorder
// Enter your choice: 1
// Enter the data: 50
// Do you want to insert more value (y/n): y

// Enter the data: 30
// Do you want to insert more value (y/n): y

// Enter the data: 70
// Do you want to insert more value (y/n): y

// Enter the data: 20
// Do you want to insert more value (y/n): y

// Enter the data: 40
// Do you want to insert more value (y/n): y

// Enter the data: 60
// Do you want to insert more value (y/n): y 

// Enter the data: 80
// Do you want to insert more value (y/n): n

// The total number of nodes are: 7

// Do you want to continue (y/n): y

// Menu:
// 1) Insert new node
// 2) Number of nodes in longest path
// 3) Minimum
// 4) Mirror
// 5) Search
// 6) Inorder
// 7) Preorder
// 8) Postorder
// Enter your choice: 5

// Enter your key: 60
//            KEY FOUND           

// Do you want to continue (y/n): y

// Menu:
// 1) Insert new node
// 2) Number of nodes in longest path
// 3) Minimum
// 4) Mirror
// 5) Search
// 6) Inorder
// 7) Preorder
// 8) Postorder
// Enter your choice: 6

// *************** INORDER **************
// 20      30      40      50      60      70      80
// Do you want to continue (y/n): y

// Menu:
// 1) Insert new node
// 2) Number of nodes in longest path
// 3) Minimum
// 4) Mirror
// 5) Search
// 6) Inorder
// 7) Preorder
// 8) Postorder
// Enter your choice: 7

// *************** PREORDER **************
// 50      30      20      40      70      60      80
// Do you want to continue (y/n): y

// Menu:
// 1) Insert new node
// 2) Number of nodes in longest path
// 3) Minimum
// 4) Mirror
// 5) Search
// 6) Inorder
// 7) Preorder
// 8) Postorder
// Enter your choice: 8

// *************** POSTORDER **************
// 20      40      30      60      80      70      50
// Do you want to continue (y/n): y

// Menu:
// 1) Insert new node
// 2) Number of nodes in longest path
// 3) Minimum
// 4) Mirror
// 5) Search
// 6) Inorder
// 7) Preorder
// 8) Postorder
// Enter your choice: 2

// Number of nodes in longest path: 3

// Do you want to continue (y/n): y

// Menu:
// 1) Insert new node
// 2) Number of nodes in longest path
// 3) Minimum
// 4) Mirror
// 5) Search
// 6) Inorder
// 7) Preorder
// 8) Postorder
// Enter your choice: 3

// The min element is: 20

// Do you want to continue (y/n): y

// Menu:
// 1) Insert new node
// 2) Number of nodes in longest path
// 3) Minimum
// 4) Mirror
// 5) Search
// 6) Inorder
// 7) Preorder
// 8) Postorder
// Enter your choice: 4

// The mirror of the tree (inorder): 80    70      60      50      40      30      20
// Do you want to continue (y/n): 