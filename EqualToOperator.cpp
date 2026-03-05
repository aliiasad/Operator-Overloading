// // Declaration (inside class)
// Student& operator=(const Student& other);

// // Definition (outside class)
// Student& Student::operator=(const Student& other) {

//     cout << "operator= called" << endl;

//     // STEP A: Self-assignment check
//     // Why? If someone writes s1 = s1, without this check
//     // you'd delete s1's name, then try to copy from deleted memory!
//     if (this == &other) return *this;

//     // STEP B: Clean up OLD data
//     // Why? 'this' object already has a 'name' allocated
//     // If we don't delete it, that memory is LEAKED forever
//     delete[] name;

//     // STEP C: Allocate NEW memory and copy
//     // Why new memory? We want a DEEP copy, not both pointing to same memory
//     name = new char[mystrlen(other.name) + 1];  // +1 for '\0'
//     mystrcpy(other.name, name);
//     age = other.age;

//     // STEP D: Return *this
//     // Why? So you can chain: s1 = s2 = s3
//     // s2 = s3 runs first, returns s2, then s1 = s2 runs
//     return *this;

# include <iostream>
using namespace std;   

int strlen(const char* str);
void strcpy(const char* src, char* dest);

class Student {
    private:
        char* name;
        int age;
    public: 
        Student(); //copy constructor
        Student(const char* , int); // parameterized constructor
        Student(const Student& n); // copy constructor
        ~Student(); // destructor

        Student& operator=(const Student& ); // overloading (=) operator

        void display();
};

Student :: Student()    {
    cout << "Default Constructor" << endl;
    name = new char[strlen("Unknown") + 1];
    strcpy("Unknown", name);

    age = 0;
}

Student :: Student(const char* n, int a)    {
    cout << "Parameterized Constructor" << endl;
    name = new char[strlen(n) + 1];
    strcpy(n, name);

    age = a;
}

Student :: Student(const Student& dummy)    {
    cout << "Copy Constructor" << endl;
    name = new char[strlen(dummy.name) + 1]; //obj.member
    strcpy(dummy.name, name);

    age = dummy.age;
}

Student& Student :: operator=(const Student& dummy)  {

    //step 1 --> self check
    if (this == &dummy) return *this;

    //step2 --> deallocate previous memory
    delete[] name;

    //new memory
    name = new char[strlen(dummy.name) + 1];
    strcpy(dummy.name, name);

    age = dummy.age;

    //step 4: return type (*this --> in this case)

    return *this;
}

Student :: ~Student()   {
    delete[] name;
}

int strlen(const char* str) {
    int i = 0;
    while(str[i] != '\0')   i++;
    return i;
}

void Student::display() {
    cout << "Name: " << name << ", Age: " << age << endl;
}

void strcpy(const char* src, char* dest) {
    int i = 0;
    while (src[i] != '\0')  {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return;
}

//main is ai generated just to test te above 

int main() {


    // TEST 1: Default Constructor
    cout << "=== TEST 1: Default Constructor ===" << endl;
    Student s1;
    s1.display();
    // Expected: Name: Unknown, Age: 0
    cout << endl;

    // TEST 2: Parameterized Constructor
    cout << "=== TEST 2: Parameterized Constructor ===" << endl;
    Student s2("Asad", 18);
    Student s3("Ali", 19);
    s2.display();
    s3.display();
    // Expected: Name: Asad, Age: 18
    // Expected: Name: Ali, Age: 19
    cout << endl;

    // TEST 3: Copy Constructor
    cout << "=== TEST 3: Copy Constructor ===" << endl;
    Student s4(s2);
    s4.display();
    // Expected: Name: Asad, Age: 18  (copied from s2)
    cout << endl;

    // TEST 4: Copy Constructor (= syntax)
    cout << "=== TEST 4: Copy Constructor (= syntax) ===" << endl;
    Student s5 = s3;
    s5.display();
    // Expected: Name: Ali, Age: 19  (copied from s3)
    cout << endl;

    // TEST 5: Assignment Operator
    cout << "=== TEST 5: Assignment Operator ===" << endl;
    cout << "BEFORE:" << endl;
    s1.display();
    // Expected: Name: Unknown, Age: 0
    s1 = s2;
    cout << "AFTER s1 = s2:" << endl;
    s1.display();
    // Expected: Name: Asad, Age: 18
    cout << endl;

    // TEST 6: Self Assignment
    cout << "=== TEST 6: Self Assignment ===" << endl;
    s1 = s1;
    s1.display();
    // Expected: Name: Asad, Age: 18  (unchanged, no crash)
    cout << endl;

    // TEST 7: Chaining Assignment
    cout << "=== TEST 7: Chaining ===" << endl;
    Student s6;
    Student s7;
    s6 = s7 = s3;
    cout << "s6: ";  s6.display();
    cout << "s7: ";  s7.display();
    // Expected: both show Name: Ali, Age: 19
    cout << endl;

    // TEST 8: Deep Copy Proof (changing original doesn't affect copy)
    cout << "=== TEST 8: Deep Copy Proof ===" << endl;
    Student s8("Charlie", 25);
    Student s9(s8);             // copy of s8
    s8 = Student("David", 30); // change s8 to something else
    cout << "s8 (changed): ";  s8.display();
    cout << "s9 (should still be Charlie): ";  s9.display();
    // Expected: s8 = David, 30
    // Expected: s9 = Charlie, 25  (deep copy = independent)
    cout << endl;

    cout << "=== PROGRAM ENDING ===" << endl;
    return 0;
}