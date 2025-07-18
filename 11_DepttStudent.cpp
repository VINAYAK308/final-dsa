#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class student
{
    typedef struct stud
    {
        int roll;
        char name[50];  
        char div;
        char add[100];  
    } stud;

    stud rec;

public:
    void create();
    void display();
    int search();
    void Delete();
};

void student::create()
{
    char ans;
    ofstream fout;
    fout.open("stud.txt", ios::out | ios::binary);  
    do
    {
        cout << "\n\tEnter Roll No of Student    : ";
        cin >> rec.roll;
        cout << "\n\tEnter a Name of Student     : ";
        cin >> rec.name;
        cout << "\n\tEnter a Division of Student : ";
        cin >> rec.div;
        cout << "\n\tEnter a Address of Student  : ";
        cin >> rec.add;
        fout.write((char*)&rec, sizeof(stud));
        cout << "\n\tDo You Want to Add More Records: ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    fout.close();
}

void student::display()
{
    ifstream fin;
    fin.open("stud.txt", ios::in | ios::binary);  
    fin.seekg(0, ios::beg);
    cout << "\n\tThe Content of File are:\n";
    cout << "\n\tRoll\tName\tDiv\tAddress";
    while (fin.read((char*)&rec, sizeof(stud)))
    {
        if (rec.roll != -1)
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
    }
    fin.close();
}

int student::search()
{
    int r, i = 0;
    ifstream fin;
    fin.open("stud.txt", ios::in | ios::binary);  
    fin.seekg(0, ios::beg);
    cout << "\n\tEnter a Roll No: ";
    cin >> r;
    while (fin.read((char*)&rec, sizeof(stud)))
    {
        if (rec.roll == r)
        {
            cout << "\n\tRecord Found...\n";
            cout << "\n\tRoll\tName\tDiv\tAddress";
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
            return i;
        }
        i++;
    }
    fin.close();
    return 0;
}

void student::Delete()
{
    int pos;
    pos = search();
    fstream f;
    f.open("stud.txt", ios::in | ios::out | ios::binary);  // Changed to .txt extension
    f.seekg(0, ios::beg);
    if (pos == 0)
    {
        cout << "\n\tRecord Not Found";
        return;
    }
    int offset = pos * sizeof(stud);
    f.seekp(offset);
    rec.roll = -1;
    strcpy(rec.name, "NULL");
    rec.div = 'N';
    strcpy(rec.add, "NULL");
    f.write((char*)&rec, sizeof(stud));
    f.seekg(0);
    f.close();
    cout << "\n\tRecord Deleted";
}

int main()
{
    student obj;
    int ch, key;
    char ans;
    do
    {
        cout << "\n\t***** Student Information *****";
        cout << "\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit";
        cout << "\n\t..... Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.create();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.Delete();
            break;
        case 4:
            key = obj.search();
            if (key == 0)
                cout << "\n\tRecord Not Found...\n";
            break;
        case 5:
            break;
        }
        cout << "\n\t..... Do You Want to Continue in Main Menu: ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 1;
}



  // ***** Student Information *****
// 1. Create
// 2. Display
// 3. Delete
// 4. Search
// 5. Exit
// ..... Enter Your Choice: 1

// 	Enter Roll No of Student    : 101
// 	Enter a Name of Student     : Alice
// 	Enter a Division of Student : A
// 	Enter a Address of Student  : Pune

// 	Do You Want to Add More Records: y

// 	Enter Roll No of Student    : 102
// 	Enter a Name of Student     : Bob
// 	Enter a Division of Student : B
// 	Enter a Address of Student  : Mumbai

// 	Do You Want to Add More Records: n

// ..... Do You Want to Continue in Main Menu: y


// ***** Student Information *****
// 1. Create
// 2. Display
// 3. Delete
// 4. Search
// 5. Exit
// ..... Enter Your Choice: 2

// 	The Content of File are:

// 	Roll	Name	Div	Address
// 	101	Alice	A	Pune
// 	102	Bob	B	Mumbai

// ..... Do You Want to Continue in Main Menu: y

// ***** Student Information *****
// 1. Create
// 2. Display
// 3. Delete
// 4. Search
// 5. Exit
// ..... Enter Your Choice: 4

// 	Enter a Roll No: 102

// 	Record Found...

// 	Roll	Name	Div	Address
// 	102	Bob	B	Mumbai

// ..... Do You Want to Continue in Main Menu: y


// ***** Student Information *****
// 1. Create
// 2. Display
// 3. Delete
// 4. Search
// 5. Exit
// ..... Enter Your Choice: 3

// 	Enter a Roll No: 101

// 	Record Found...

// 	Roll	Name	Div	Address
// 	101	Alice	A	Pune

// 	Record Deleted

// ..... Do You Want to Continue in Main Menu: y

// ***** Student Information *****
// 1. Create
// 2. Display
// 3. Delete
// 4. Search
// 5. Exit
// ..... Enter Your Choice: 2

// 	The Content of File are:

// 	Roll	Name	Div	Address
// 	102	Bob	B	Mumbai

// ..... Do You Want to Continue in Main Menu: n


