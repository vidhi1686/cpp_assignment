#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string fullName;
    int age;
    string personID;
    string contactNumber;

public:
    Person(string n = "", int a = 18, string id = "", string c = "") {
        setName(n);
        setAge(a);
        personID = id;
        contactNumber = c;
    }

    virtual void displayDetails() {
        cout << "Name: " << fullName << ", Age: " << age
             << ", ID: " << personID << ", Contact: " << contactNumber << endl;
    }

    virtual double calculatePayment() { return 0.0; }

    void setName(string n) { fullName = n.empty() ? "Unknown" : n; }
    void setAge(int a) { age = (a > 0 && a < 100) ? a : 18; }
    string getName() { return fullName; }
    int getAge() { return age; }
};
class Student : public Person {
    string programName;
    string dateOfEnrollment;
    float gradePointAverage;

public:
    Student(string n = "", int a = 18, string id = "", string c = "",
            string e = "", string p = "", float g = 0.0f)
        : Person(n, a, id, c), dateOfEnrollment(e), programName(p) {
        setGPA(g);
    }

    void setGPA(float g) { gradePointAverage = (g >= 0.0f && g <= 4.0f) ? g : 0.0f; }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Program: " << programName << ", GPA: " << gradePointAverage << endl;
    }

    double calculatePayment() override { return 1000.0; }
};
class Professor : public Person {
    string departmentName;
    string fieldOfExpertise;
    string joiningDate;

public:
    Professor(string n = "", int a = 30, string id = "", string c = "",
              string d = "", string s = "", string h = "")
        : Person(n, a, id, c), departmentName(d), fieldOfExpertise(s), joiningDate(h) {}

    void displayDetails() override {
        Person::displayDetails();
        cout << "Department: " << departmentName << ", Specialization: " << fieldOfExpertise << endl;
    }

    double calculatePayment() override { return 5000.0; }
};

class Course {
    string courseCode, courseTitle, courseDescription;
    int creditHours;

public:
    Course(string c = "", string t = "", int cr = 3, string d = "")
        : courseCode(c), courseTitle(t), courseDescription(d) {
        setCredits(cr);
    }

    void setCredits(int c) { creditHours = (c > 0) ? c : 1; }

    void display() {
        cout << "Course: " << courseCode << " - " << courseTitle
             << ", Credits: " << creditHours << endl;
    }
};
class Department {
    string departmentTitle, departmentLocation;
    float allocatedBudget;

public:
    Department(string n = "", string l = "", float b = 0.0f)
        : departmentTitle(n), departmentLocation(l), allocatedBudget(b) {}

    void display() {
        cout << "Department: " << departmentTitle << ", Location: " << departmentLocation
             << ", Budget: $" << allocatedBudget << endl;
    }
};
class GradeBook {
    string studentIDs[10];
    float studentGrades[10];
    int totalEntries = 0;

public:
    void addGrade(string id, float grade) {
        if (totalEntries < 10) {
            studentIDs[totalEntries] = id;
            studentGrades[totalEntries++] = grade;
        }
    }

    float calculateAverageGrade() {
        float total = 0;
        for (int i = 0; i < totalEntries; i++) total += studentGrades[i];
        return totalEntries ? total / totalEntries : 0.0f;
    }

    float getHighestGrade() {
        float max = 0;
        for (int i = 0; i < totalEntries; i++)
            if (studentGrades[i] > max) max = studentGrades[i];
        return max;
    }

    void getFailingStudents() {
        cout << "Failing students (grade < 50):\n";
        for (int i = 0; i < totalEntries; i++)
            if (studentGrades[i] < 50)
                cout << studentIDs[i] << " with grade " << studentGrades[i] << endl;
    }
};
class EnrollmentManager {
    string enrolledCourses[10], enrolledStudents[10];
    int enrollmentCount = 0;

public:
    void enrollStudent(string courseCode, string studentID) {
        if (enrollmentCount < 10) {
            enrolledCourses[enrollmentCount] = courseCode;
            enrolledStudents[enrollmentCount++] = studentID;
        }
    }

    void dropStudent(string studentID) {
        for (int i = 0; i < enrollmentCount; i++) {
            if (enrolledStudents[i] == studentID) {
                enrolledCourses[i] = enrolledCourses[enrollmentCount - 1];
                enrolledStudents[i] = enrolledStudents[enrollmentCount - 1];
                enrollmentCount--;
                break;
            }
        }
    }

    int getEnrollmentCount() { return enrollmentCount; }
};

int main() {
    
    Student st1("Anita Desai", 19, "ST101", "anita@mail.com", "2024", "Computer Science", 3.8f);
    Student st2("Vikram Patel", 20, "ST102", "vikram@mail.com", "2024", "Electrical", 2.9f);


    Professor pr1("Dr. Asha Rao", 48, "PR301", "asha@university.edu", "Computer Science", "AI", "2010");
    Professor pr2("Dr. Mohan Iyer", 52, "PR302", "mohan@university.edu", "Mathematics", "Statistics", "2001");


    Course crs1("CS201", "Data Structures", 4, "Fundamentals of data structures");
    Department dept1("Technology", "Building A", 85000.0f);

    
    st1.displayDetails();
    st2.displayDetails();
    pr1.displayDetails();
    pr2.displayDetails();
    crs1.display();
    dept1.display();

    
    GradeBook gb;
    gb.addGrade("ST101", 82);
    gb.addGrade("ST102", 43); 
    cout << "Average Grade: " << gb.calculateAverageGrade() << endl;
    cout << "Highest Grade: " << gb.getHighestGrade() << endl;
    gb.getFailingStudents();

    
    EnrollmentManager em;
    em.enrollStudent("CS201", "ST101");
    em.enrollStudent("CS201", "ST102");
    cout << "Enrolled Students: " << em.getEnrollmentCount() << endl;
    em.dropStudent("ST102");
    cout << "After drop: " << em.getEnrollmentCount() << endl;

    Person* people[2] = { &st1, &pr1 };
    for (int i = 0; i < 2; i++) {
        people[i]->displayDetails();
        cout << "Calculated Payment: $" << people[i]->calculatePayment() << "\n\n";
    }

    return 0;
}
