#include<iostream>
#include<string.h>
using namespace std;

struct node {
    char name[20];
    node *next;
    node *down;
    int flag;
};

class Gll {
    char ch[20];
    int n, i;
    node *head = NULL, *temp = NULL, *t1 = NULL, *t2 = NULL;

public:
    node *create();
    void insertb();
    void insertc();
    void inserts();
    void insertss();
    void displayb();
};

node *Gll::create() {
    node *p = new node;
    p->next = NULL;
    p->down = NULL;
    p->flag = 0;
    cout << "\nEnter the name: ";
    cin >> p->name;
    return p;
}

void Gll::insertb() {
    if (head == NULL) {
        t1 = create();
        head = t1;
    } else {
        cout << "\nBook already exists.";
    }
}

void Gll::insertc() {
    if (head == NULL) {
        cout << "\nThere is no book.";
    } else {
        cout << "\nHow many chapters you want to insert: ";
        cin >> n;
        for (i = 0; i < n; i++) {
            t1 = create();
            if (head->flag == 0) {
                head->down = t1;
                head->flag = 1;
            } else {
                temp = head->down;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = t1;
            }
        }
    }
}

void Gll::inserts() {
    if (head == NULL) {
        cout << "\nThere is no book.";
    } else {
        cout << "\nEnter the name of chapter on which you want to enter the section: ";
        cin >> ch;

        temp = head;
        if (temp->flag == 0) {
            cout << "\nThere are no chapters in the book.";
        } else {
            temp = temp->down;
            while (temp != NULL) {
                if (strcmp(ch, temp->name) == 0) {
                    cout << "\nHow many sections you want to enter: ";
                    cin >> n;
                    for (i = 0; i < n; i++) {
                        t1 = create();
                        if (temp->flag == 0) {
                            temp->down = t1;
                            temp->flag = 1;
                        } else {
                            t2 = temp->down;
                            while (t2->next != NULL)
                                t2 = t2->next;
                            t2->next = t1;
                        }
                    }
                    return;
                }
                temp = temp->next;
            }
            cout << "\nChapter not found.";
        }
    }
}

void Gll::insertss() {
    if (head == NULL) {
        cout << "\nThere is no book.";
        return;
    }

    char chapterName[20], sectionName[20];
    cout << "\nEnter the name of chapter on which you want to enter the section: ";
    cin >> chapterName;

    temp = head;
    if (temp->flag == 0) {
        cout << "\nThere are no chapters in the book.";
        return;
    }

    temp = temp->down;
    while (temp != NULL) {
        if (strcmp(chapterName, temp->name) == 0) {
            if (temp->flag == 0) {
                cout << "\nThere are no sections in this chapter.";
                return;
            }

            node *chapter = temp;
            cout << "\nEnter name of section in which you want to enter the sub section: ";
            cin >> sectionName;

            temp = chapter->down;
            while (temp != NULL) {
                if (strcmp(sectionName, temp->name) == 0) {
                    cout << "\nHow many subsections you want to enter: ";
                    cin >> n;
                    for (i = 0; i < n; i++) {
                        t1 = create();
                        if (temp->flag == 0) {
                            temp->down = t1;
                            temp->flag = 1;
                        } else {
                            t2 = temp->down;
                            while (t2->next != NULL)
                                t2 = t2->next;
                            t2->next = t1;
                        }
                    }
                    return;
                }
                temp = temp->next;
            }

            cout << "\nSection not found.";
            return;
        }
        temp = temp->next;
    }

    cout << "\nChapter not found.";
}

void Gll::displayb() {
    if (head == NULL) {
        cout << "\nBook does not exist.";
    } else {
        temp = head;
        cout << "\nNAME OF BOOK: " << temp->name;
        if (temp->flag == 1) {
            temp = temp->down;
            while (temp != NULL) {
                cout << "\n\tCHAPTER: " << temp->name;
                t1 = temp;
                if (t1->flag == 1) {
                    t1 = t1->down;
                    while (t1 != NULL) {
                        cout << "\n\t\tSECTION: " << t1->name;
                        t2 = t1;
                        if (t2->flag == 1) {
                            t2 = t2->down;
                            while (t2 != NULL) {
                                cout << "\n\t\t\tSUBSECTION: " << t2->name;
                                t2 = t2->next;
                            }
                        }
                        t1 = t1->next;
                    }
                }
                temp = temp->next;
            }
        }
    }
}

int main() {
    Gll g;
    int x;
    while (1) {
        cout << "\n\nEnter your choice:";
        cout << "\n1. Insert Book";
        cout << "\n2. Insert Chapter";
        cout << "\n3. Insert Section";
        cout << "\n4. Insert Subsection";
        cout << "\n5. Display Book";
        cout << "\n6. Exit\n";
        cin >> x;
        switch (x) {
            case 1: g.insertb(); break;
            case 2: g.insertc(); break;
            case 3: g.inserts(); break;
            case 4: g.insertss(); break;
            case 5: g.displayb(); break;
            case 6: exit(0);
            default: cout << "\nInvalid choice.";
        }
    }
    return 0;
}





//  enter your choice
//  1.insert book
//  2.insert chapter
//  3.insert section
//  4.insert subsection
//  5.display book
//  6.exit
// > 1

//  enter the name: DataStructures

//  enter your choice
// > 2

//  how many chapters you want to insert: 2

//  enter the name: Arrays
//  enter the name: LinkedLists

//  enter your choice
// > 3

//  Enter the name of chapter on which  you want to enter the section: Arrays
//  how many sections you want to enter: 2

//  enter the name: Static
// ******
//  enter the name: Dynamic
// #####

//  enter your choice
// > 4

//  Enter the name of chapter on which  you want to enter the section: Arrays
//  enter name of section in which you want to enter the sub section: Static
//  how many subsections you want to enter: 2

//  enter the name: Declaration
// ******
//  enter the name: Initialization
// #####

//  enter your choice
// > 5

//  NAME OF BOOK:  DataStructures
// 		NAME OF CHAPTER:  Arrays
// 			NAME OF SECTION:  Static
// 				NAME OF SUBSECTION:  Declaration
// 				NAME OF SUBSECTION:  Initialization
// 			NAME OF SECTION:  Dynamic
// 		NAME OF CHAPTER:  LinkedLists

//  enter your choice
// > 6
