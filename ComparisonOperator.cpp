# include <iostream>
using namespace std;

int strlen(const char* str);
bool strcmp(const char* str1, const char* str2);
void strcpy(const char* src, char* dest);

class Student   {
    private:
        char* name;
        int age;
    public:
        Student(); //default constructor
        Student(const char* , int); // parameterized constructor
        Student(const Student&); // copy constructor
        ~Student(); // destructor

        Student& operator=(const Student& ); // overloading (=) operator
        bool operator==(const Student& dummy);  // overloading (==) operator

        void display();
};

Student :: Student()    {
    cout << "Default Constructor\n" << endl;

    name = new char[strlen("Unknown") + 1];
    strcpy("Unknown", name);

    age = 0;
}

Student :: Student(const char* n, int a)    {

    name = new char[strlen(n) + 1];
    strcpy(n, name);

    age = a;
}

Student :: Student(const Student& dummy)    {

    name = new char[strlen(dummy.name) + 1];
    strcpy(dummy.name, name);

    age = dummy.age;
}

Student :: ~Student()   {
    delete[] name;
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

bool Student :: operator==(const Student& dummy)    {

    return (strcmp(name, dummy.name) && age == dummy.age);
}  

void Student :: display()   {
    cout << "Name : " << name << " , Age : " << age << endl;

    return;
}


int strlen(const char* str)   {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

bool strcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')  {
        if (str1[i] != str2[i]) return false;
        else i++;
    }

    return str1[i] == str2[i];
}

void strcpy(const char* src, char* dest)    {
    int i(0);
    while (src[i] != '\0')  {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return;
}