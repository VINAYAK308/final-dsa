#include <iostream>
#include <string>
using namespace std;

struct node {
    string k; // keyword
    string m; // meaning
    node* left;
    node* right;
};

class dict {
public:
    node* root;

    dict() {
        root = nullptr;
    }

    void create();
    void disp(node*);
    void insert(node* root, node* temp);
    int search(node* root, const string& key);
    int update(node* root, const string& key);
    node* del(node* root, const string& key);
    node* min(node* root);
};


void dict::create() {
    int ch;
    do {
        node* temp = new node;
        cout << "\nEnter Keyword: ";
        cin >> temp->k;
        cout << "Enter Meaning: ";
        cin.ignore(); // To flush newline character
        getline(cin, temp->m);

        temp->left = temp->right = nullptr;

        if (root == nullptr) {
            root = temp;
        } else {
            insert(root, temp);
        }

        cout << "Do you want to add more (y=1/n=0): ";
        cin >> ch;
    } while (ch == 1);
}

// Insert a node into BST
void dict::insert(node* root, node* temp) {
    if (temp->k < root->k) {
        if (root->left == nullptr)
            root->left = temp;
        else
            insert(root->left, temp);
    } else {
        if (root->right == nullptr)
            root->right = temp;
        else
            insert(root->right, temp);
    }
}

// Display dictionary in lexicographical order
void dict::disp(node* root) {
    if (root != nullptr) {
        disp(root->left);
        cout << "\nKeyword: " << root->k << " \tMeaning: " << root->m;
        disp(root->right);
    }
}

// Search keyword and count comparisons
int dict::search(node* root, const string& key) {
    int c = 0;
    while (root != nullptr) {
        c++;
        if (key == root->k) {
            cout << "\nNumber of Comparisons: " << c;
            return 1;
        } else if (key < root->k) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return -1;
}

// Update meaning of a keyword
int dict::update(node* root, const string& key) {
    while (root != nullptr) {
        if (key == root->k) {
            cout << "Enter new meaning for \"" << root->k << "\": ";
            cin.ignore();
            getline(cin, root->m);
            return 1;
        } else if (key < root->k) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return -1;
}

// Delete a node
node* dict::del(node* root, const string& key) {
    if (root == nullptr) {
        cout << "\nKeyword not found!";
        return nullptr;
    }

    if (key < root->k) {
        root->left = del(root->left, key);
    } else if (key > root->k) {
        root->right = del(root->right, key);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        } else {
            node* temp = min(root->right);
            root->k = temp->k;
            root->m = temp->m;
            root->right = del(root->right, temp->k);
        }
    }
    return root;
}

// Find minimum node in BST
node* dict::min(node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}


int main() {
    dict d;
    int ch;

    do {
        cout << "\n\n--- Dictionary Menu ---";
        cout << "\n1. Create";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Update";
        cout << "\n5. Delete";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                d.create();
                break;
            case 2:
                if (d.root == nullptr)
                    cout << "\nDictionary is empty!";
                else
                    d.disp(d.root);
                break;
            case 3: {
                if (d.root == nullptr) {
                    cout << "\nDictionary is empty!";
                    break;
                }
                string key;
                cout << "Enter keyword to search: ";
                cin >> key;
                if (d.search(d.root, key) == 1)
                    cout << "\nKeyword Found!";
                else
                    cout << "\nKeyword Not Found!";
                break;
            }
            case 4: {
                if (d.root == nullptr) {
                    cout << "\nDictionary is empty!";
                    break;
                }
                string key;
                cout << "Enter keyword to update: ";
                cin >> key;
                if (d.update(d.root, key) == 1)
                    cout << "\nMeaning Updated!";
                else
                    cout << "\nKeyword Not Found!";
                break;
            }
            case 5: {
                if (d.root == nullptr) {
                    cout << "\nDictionary is empty!";
                    break;
                }
                string key;
                cout << "Enter keyword to delete: ";
                cin >> key;
                d.root = d.del(d.root, key);
                break;
            }
            default:
                cout << "\nInvalid Choice!";
        }
    } while (ch >= 1 && ch <= 5);

    return 0;
}

// --- Dictionary Menu ---
// 1. Create
// 2. Display
// 3. Search
// 4. Update
// 5. Delete
// Enter your choice: 1

// Enter Keyword: apple
// Enter Meaning: a fruit
// Do you want to add more (y=1/n=0): 1

// Enter Keyword: banana
// Enter Meaning: yellow fruit
// Do you want to add more (y=1/n=0): 0


// --- Dictionary Menu ---
// 1. Create
// 2. Display
// 3. Search
// 4. Update
// 5. Delete
// Enter your choice: 2

// Keyword: apple 	Meaning: a fruit
// Keyword: banana 	Meaning: yellow fruit

// --- Dictionary Menu ---
// 1. Create
// 2. Display
// 3. Search
// 4. Update
// 5. Delete
// Enter your choice: 3
// Enter keyword to search: banana

// Number of Comparisons: 2
// Keyword Found!

// --- Dictionary Menu ---
// 1. Create
// 2. Display
// 3. Search
// 4. Update
// 5. Delete
// Enter your choice: 4
// Enter keyword to update: banana
// Enter new meaning for "banana": rich in potassium

// Meaning Updated!

// --- Dictionary Menu ---
// 1. Create
// 2. Display
// 3. Search
// 4. Update
// 5. Delete
// Enter your choice: 2 

// Keyword: apple 	Meaning: a fruit
// Keyword: banana 	Meaning: rich in potassium

// --- Dictionary Menu ---
// 1. Create
// 2. Display
// 3. Search
// 4. Update
// 5. Delete
// Enter your choice: 5
// Enter keyword to delete: banana


// --- Dictionary Menu ---
// 1. Create
// 2. Display
// 3. Search
// 4. Update
// 5. Delete
// Enter your choice: 2

// Keyword: apple 	Meaning: a fruit

// --- Dictionary Menu ---
// 1. Create
// 2. Display
// 3. Search
// 4. Update
// 5. Delete
// Enter your choice: 

