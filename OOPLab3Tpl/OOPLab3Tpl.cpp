#include <iostream>
#include <locale>
#include<cstring>
using namespace ::std;

class Date {
private:
    int m_day;
    int m_month;
    int m_year;
public:
    Date() {
        m_day = 1;
        m_month = 1;
        m_year = 2000;
    }

    void set_day(int day) {
        if (day > 31) {
            cout << "Day isnt correct!" << endl;
        }
        else {
            m_day = day;
        }
    }
    Date(int day, int month) {
        m_day = day;
        m_month = month;
        m_year = 2024;
    }
    void set_month(int month) {
        if (month > 12) {
            cout << "Month isnt correct!" << endl;
        }
        else {
            m_month = month;
        }
    }
    void set_year(int year) {
        m_year = year;
    }

    void get_day() {
        cout << m_day << endl;
    }
    void get_year() {
        cout << m_year << endl;
    }
    void get_month() {
        cout << m_month << endl;
    }
    void print_date() {
        cout << m_day << "." << m_month << "." << m_year << endl;
    }

    void char_date() {
        setlocale(LC_CTYPE, "ukr");
        switch (m_month) {
        case 1: cout << m_day << " Сiчня " << m_year << " Року " << endl; break;
        case 2: cout << m_day << " Лютого " << m_year << " Року " << endl; break;
        case 3: cout << m_day << " Березня " << m_year << " Року " << endl; break;
        case 4: cout << m_day << " Квiтня " << m_year << " Року " << endl; break;
        case 5: cout << m_day << " Травня " << m_year << " Року " << endl; break;
        case 6: cout << m_day << " Червня " << m_year << " Року " << endl; break;
        case 7: cout << m_day << " Липня " << m_year << " Року " << endl; break;
        case 8: cout << m_day << " Серпня " << m_year << " Року " << endl; break;
        case 9: cout << m_day << " Вересня " << m_year << " Року " << endl; break;
        case 10: cout << m_day << " Жовтня " << m_year << " Року " << endl; break;
        case 11: cout << m_day << " Листопада " << m_year << " Року " << endl; break;
        case 12: cout << m_day << " Грудня " << m_year << " Року " << endl; break;
        }
    }

};
void task1() {
    Date date1;

    cout << "Default date: ";
    date1.print_date();
    cout << "Formatted as 'day month year': ";
    date1.char_date();
    cout << endl;

    date1.set_day(15);
    date1.set_month(6);
    date1.set_year(2022);

    cout << "Updated date: ";
    date1.print_date();
    cout << "Formatted as 'day month year': ";
    date1.char_date();
    cout << endl;


    Date date2(25, 12);

    cout << "Specialized date: ";
    date2.print_date();
    cout << "Formatted as 'day month year': ";
    date2.char_date();
    cout << endl;
}

class Vector {
private:
    int m_size;
    int* vector;

public:
    Vector() {
        vector = new int[1];
        vector[0] = 0;
        m_size = 1;
    }

    Vector(int size) {
        vector = new int[size];
        m_size = size;
        for (int i = 0; i < size; i++) {
            vector[i] = 0;
        }
    }

    Vector(int size, int init_value) {
        vector = new int[size];
        m_size = size;
        for (int i = 0; i < size; i++) {
            vector[i] = init_value;
        }
    }

    Vector(const Vector& other) {
        m_size = other.m_size;
        vector = new int[m_size];
        for (int i = 0; i < m_size; i++) {
            vector[i] = other.vector[i];
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] vector;
            m_size = other.m_size;
            vector = new int[m_size];
            for (int i = 0; i < m_size; i++) {
                vector[i] = other.vector[i];
            }
        }
        return *this;
    }

    ~Vector() {
        cout << "Deleting vector" << endl;
        delete[] vector;
    }

    void get_vector() {
        for (int i = 0; i < m_size; i++) {
            cout << vector[i] << endl;
        }
    }

    void get_elem(int num = 0) {
        if (num >= 0 && num < m_size) {
            cout << "Vector[" << num << "]=" << vector[num] << endl;
        }
        else {
            cout << "Index out of bounds." << endl;
        }
    }

    void set_elem(int n_elem, int numb = 0) {
        if (n_elem >= 0 && n_elem < m_size) {
            vector[n_elem] = numb;
        }
        else {
            cout << "Index out of bounds." << endl;
        }
    }

    void get_size() {
        cout << m_size << endl;
    }

    void minus(int num) {
        for (int i = 0; i < m_size; i++) {
            vector[i] -= num;
        }
    }

    void plus(int num) {
        for (int i = 0; i < m_size; i++) {
            vector[i] += num;
        }
    }

    void multiply(int num) {
        for (int i = 0; i < m_size; i++) {
            vector[i] *= num;
        }
    }

    auto more(int elem_1, int elem_2) {
        return vector[elem_1] > vector[elem_2];
    }

    auto less(int elem_1, int elem_2) {
        return vector[elem_1] < vector[elem_2];
    }

    auto equal(int elem_1, int elem_2) {
        return vector[elem_1] == vector[elem_2];
    }
};


void task2() {
    cout << "Creating vectors:" << endl;
    Vector v1;
    Vector v2(5);
    Vector v3(3, 10);
    Vector v4(v3);

    cout << "Vector v1 (default): ";
    v1.get_vector();
    cout << "Vector v2 (5 elements, initialized to 0): ";
    v2.get_vector();
    cout << "Vector v3 (3 elements, initialized to 10): ";
    v3.get_vector();
    cout << "Vector v4 (copy of v3): ";
    v4.get_vector();

    cout << "\nTesting access and modification functions:" << endl;
    v1.set_elem(0, 5);
    cout << "Modified vector v1: ";
    v1.get_vector();

    v2.set_elem(2, 77);
    cout << "Modified vector v2: ";
    v2.get_vector();

    cout << "\nTesting assignment operator:" << endl;
    v2 = v3;
    cout << "Vector v2 after assigning v3: ";
    v2.get_vector();

    cout << "\nTesting arithmetic operations:" << endl;
    v3.plus(5);
    cout << "v3 after adding 5: ";
    v3.get_vector();

    v3.minus(2);
    cout << "v3 after subtracting 2: ";
    v3.get_vector();

    v3.multiply(2);
    cout << "v3 after multiplying by 2: ";
    v3.get_vector();

    cout << "\nTesting comparisons:" << endl;
    cout << "v3[0] > v3[1]: " << (v3.more(0, 1)) << endl;
    cout << "v3[0] < v3[1]: " << (v3.less(0, 1)) << endl;
    cout << "v3[0] == v3[1]: " << (v3.equal(0, 1)) << endl;

    cout << "\nDestroying objects and exiting." << endl;
}
int main()
{
    int choice;
    cout << "Choose task" << endl;
    cout << "1.Task 1 (with class Date)" << endl;
    cout << "2.Task 2 (with class Vector)" << endl;
    cout << "3.Exit" << endl;

    cin >> choice;

    switch (choice) {
    case 1: task1(); break;
    case 2: task2(); break;
    case 3: return 0;
    default: cout << "Error" << endl;
    }
}

