#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int Roll_no;
    float CGPA;
    string enrolled_courses[5];
    int course_count = 6;

public:
    Student()
    {
        cout << "you are in default constructor" << endl;
        name = "unknown";
        Roll_no = 0;
        CGPA = 0.0;
        string default_courses[] = {"english", "maths", "focp", "beee", "egd"};
        for (int i = 0; i < 5; i++)
        {
            enrolled_courses[i] = default_courses[i];
        }
    }

    Student(string n, int r, float p, string courses[])
    {
        cout << "you are in parameterized constructor" << endl;
        name = n;
        Roll_no = r;
        CGPA = p;
        for (int i = 0; i < 5; i++)
        {
            enrolled_courses[i] = courses[i];
        }
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << Roll_no << endl;
        cout << "CGPA: " << CGPA << endl;
        cout << "Enrolled Courses: ";
        for (int i = 0; i < course_count; i++)
        {
            cout << enrolled_courses[i] << " ";
        }
        cout << endl;
    }

    void addCourse(string course)
    {
        if (course_count < 6)
        {
            enrolled_courses[course_count] = course;

            cout << "Course " << course << " added successfully!" << endl;
        }
        else
        {
            cout << "Cannot add more than 6 courses." << endl;
        }
    }

    void updateCGPA(float newCGPA)
    {
        if (newCGPA >= 0.0 && newCGPA <= 10.0)
        {
            CGPA = newCGPA; 
            cout << "CGPA updated successfully!" << endl;
        }
        else
        {
            cout << "Invalid CGPA! Enter a value between 0 and 10." << endl;
        }
    }
};

int main()
{
    Student s1;
    s1.display();

    cout << endl;
    string courses[] = {"english", "maths", "focp", "beee", "egd"};
    Student s2("vidhi", 100, 7.5, courses);
    s2.display();

    cout << endl;
    s2.addCourse("physics");
    s2.updateCGPA(8.2);
    s2.display();

    return 0;
}