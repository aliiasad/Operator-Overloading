# include <iostream>
using namespace std;

int strlen(const char* str);
void strcpy(const char* src, char* dest);

class Student {
    private:
        int age;
        char* name;
    public:
        Student();  //default constructor
        Student(const char* , int ); //parameterized constructor
        Student(const Student&); //copy contructor
        ~Student(); //destructor
};

Student :: Student()    {
    cout << "Default Contructor" << endl;
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

Student :: Student(const Student& dummy)   {
    name = new char[strlen(dummy.name) + 1];
    strcpy(dummy.name, name);
    age = dummy.age;
}



Student :: ~Student()   {
    delete[] name;
}

int strlen(const char* str)    {
    int i = 0;
    while (str[i] != '\0')  {
        i++;
    }
    return i;
}

void strcpy(const char* src, char* dest)    {
    int i = 0;
    while (src[i] != '\0')  {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return;
}