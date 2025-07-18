class TeleBook:
    def __init__(self, name, number):
        self.name = name
        self.number = number

def InsertionLP():
    hashtable = [None for _ in range(10)]
    records = int(input("Enter total no. of records: ")) 
    for _ in range(records):
        n = input("Enter the name: ")
        t = int(input("Enter the telephone no.: "))
        hashvalue = t % 10
        if hashtable[hashvalue] is None:
            hashtable[hashvalue] = TeleBook(n, t)
        else:
            j = 1
            while j < 10:
                new_hashvalue = (hashvalue + j) % 10
                if hashtable[new_hashvalue] is None:
                    hashtable[new_hashvalue] = TeleBook(n, t)
                    break
                j += 1
    return hashtable

def InsertionQP():
    hashtable = [None for _ in range(10)]
    records = int(input("Enter total no. of records: ")) 
    for _ in range(records):
        n = input("Enter the name: ")
        t = int(input("Enter the telephone no.: "))
        hashvalue = t % 10
        if hashtable[hashvalue] is None:
            hashtable[hashvalue] = TeleBook(n, t)
        else:
            j = 1
            while j < 10:
                new_hashvalue = (hashvalue + (j * j)) % 10
                if hashtable[new_hashvalue] is None:
                    hashtable[new_hashvalue] = TeleBook(n, t)
                    break
                j += 1
    return hashtable

def InsertionDH():
    hashtable = [None for _ in range(10)]
    records = int(input("Enter total no. of records: ")) 
    for _ in range(records):
        n = input("Enter the name: ")
        t = int(input("Enter the telephone no.: "))
        hashvalue = t % 10
        if hashtable[hashvalue] is None:
            hashtable[hashvalue] = TeleBook(n, t)
        else:
            j = 1
            hash2value = 7 - (t % 7)
            while j < 10:
                new_hashvalue = (hashvalue + (j * hash2value)) % 10
                if hashtable[new_hashvalue] is None:
                    hashtable[new_hashvalue] = TeleBook(n, t)
                    break
                j += 1
    return hashtable

def Display(A):
    print("\nIndex\tName\t\tTel.no")
    for idx, obj in enumerate(A):
        if obj is not None:
            print(f"{idx}\t{obj.name:10}\t{obj.number}")

def search(hash1, hash2):
    f1 = f2 = 0
    n = input("Enter the name to be searched: ")
    if hash1:
        for idx, obj in enumerate(hash1):
            if obj is not None and obj.name == n:
                print(f"{obj.name} found at index {idx} with telephone no. {obj.number}")
                f1 = 1
    if hash2:
        for idx, obj in enumerate(hash2):
            if obj is not None and obj.name == n:
                print(f"{obj.name} found at index {idx} with telephone no. {obj.number}")
                f2 = 1
    if f1 == 0 and f2 == 0:
        print("Element not found")

def main():
    hash1 = []
    hash2 = []
    hash3 = []
    
    while True:
        print("\n\t1. Linear Probing")
        print("\t2. Quadratic Probing")
        print("\t3. Double Hashing")
        print("\t4. Search")
        print("\t5. Exit")

        ch = int(input("Enter your choice: "))
        if ch == 1:
            hash1 = InsertionLP()
            Display(hash1)
        elif ch == 2:
            hash2 = InsertionQP()
            Display(hash2)
        elif ch == 3:
            hash3 = InsertionDH()
            Display(hash3)
        elif ch == 4:
            search(hash1, hash2)
        elif ch == 5:
            print("Thanks for using the program!")
            break
        else:
            print("Enter a valid choice.")

main()



#        1. Linear Probing
#         2. Quadratic Probing
#         3. Double Hashing
#         4. Search
#         5. Exit
# Enter your choice: 1
# Enter total no. of records: 5
# Enter the name: A
# Enter the telephone no.: 09
# Enter the name: B 
# Enter the telephone no.: 18
# Enter the name: C
# Enter the telephone no.: 39
# Enter the name: D
# Enter the telephone no.: 29
# Enter the name: E
# Enter the telephone no.: 08

# Index   Name            Tel.no
# 0       C               39
# 1       D               29
# 2       E               8
# 8       B               18
# 9       A               9

#         1. Linear Probing
#         2. Quadratic Probing
#         3. Double Hashing
#         4. Search
#         5. Exit
# Enter your choice: 2
# Enter total no. of records: 5
# Enter the name: A
# Enter the telephone no.: 09
# Enter the name: B
# Enter the telephone no.: 18
# Enter the name: C
# Enter the telephone no.: 39
# Enter the name: D
# Enter the telephone no.: 29
# Enter the name: E
# Enter the telephone no.: 08

# Index   Name            Tel.no
# 0       C               39
# 2       E               8
# 3       D               29
# 8       B               18
# 9       A               9

#         1. Linear Probing
#         2. Quadratic Probing
#         3. Double Hashing
#         4. Search
#         5. Exit
# Enter your choice: 3
# Enter total no. of records: 3
# Enter the name: A
# Enter the telephone no.: 12
# Enter the name: B
# Enter the telephone no.: 22
# Enter the name: C
# Enter the telephone no.: 32

# Index   Name            Tel.no
# 2       A               12
# 5       C               32
# 8       B               22

#         1. Linear Probing
#         2. Quadratic Probing
#         3. Double Hashing
#         4. Search
#         5. Exit
# Enter your choice: 