#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    int id;
    string name;

public:
    Person(int id, string name) : id(id), name(name) {}

    int getID() { return id; }
    string getName() { return name; }

    virtual void display() = 0;
};

class Course
{
private:
    string courseCode;
    string courseName;

public:
    Course(string code, string name) : courseCode(code), courseName(name) {}

    string getCode() { return courseCode; }
    string getName() { return courseName; }

    void display()
    {
        cout << "Code: " << courseCode << ", Name: " << courseName << endl;
    }

    string toString()
    {
        return courseCode + "," + courseName;
    }
};

class Student : public Person
{
private:
    vector<string> enrolledCourses;

public:
    Student(int id, string name) : Person(id, name) {}

    void enroll(string courseCode)
    {
        enrolledCourses.push_back(courseCode);
    }

    void display() override
    {
        cout << "Student - Name: " << name << ", ID: " << id << endl;
        cout << "Courses Enrolled: ";
        for (const auto &course : enrolledCourses)
        {
            cout << course << " ";
        }
        cout << endl;
    }

    string toString()
    {
        stringstream ss;
        ss << id << "," << name;
        for (const auto &course : enrolledCourses)
        {
            ss << "," << course;
        }
        return ss.str();
    }
};
class Instructor : public Person
{
private:
    vector<string> coursesTeaching;

public:
    Instructor(int id, string name) : Person(id, name) {}

    void assignCourse(string courseCode)
    {
        coursesTeaching.push_back(courseCode);
    }

    void display() override
    {
        cout << "Instructor - Name: " << name << ", ID: " << id << endl;
        cout << "Courses Teaching: ";
        for (const auto &course : coursesTeaching)
        {
            cout << course << " ";
        }
        cout << endl;
    }

    string toString()
    {
        stringstream ss;
        ss << id << "," << name;
        for (const auto &course : coursesTeaching)
        {
            ss << "," << course;
        }
        return ss.str();
    }
};

class UniversitySystem
{
private:
    vector<Course> courses;
    vector<Student> students;
    vector<Instructor> instructors;

public:
    void addCourse(string code, string name)
    {
        courses.push_back(Course(code, name));
        cout << "Course added successfully!\n";
    }

    void enrollStudent(int id, string name, string courseCode)
    {
        students.push_back(Student(id, name));
        students.back().enroll(courseCode);
        cout << "Student enrolled successfully!\n";
    }

    void assignInstructor(int id, string name, string courseCode)
    {
        instructors.push_back(Instructor(id, name));
        instructors.back().assignCourse(courseCode);
        cout << "Instructor assigned successfully!\n";
    }

    void displayData()
    {
        cout << "Courses:\n";
        for (auto &course : courses)
        {
            course.display();
        }
        cout << "\nStudents:\n";
        for (auto &student : students)
        {
            student.display();
        }
        cout << "\nInstructors:\n";
        for (auto &instructor : instructors)
        {
            instructor.display();
        }
    }

    void saveData()
    {
        ofstream courseFile("courses.txt");
        for (auto &course : courses)
        {
            courseFile << course.toString() << endl;
        }
        courseFile.close();

        ofstream studentFile("students.txt");
        for (auto &student : students)
        {
            studentFile << student.toString() << endl;
        }
        studentFile.close();

        ofstream instructorFile("instructors.txt");
        for (auto &instructor : instructors)
        {
            instructorFile << instructor.toString() << endl;
        }
        instructorFile.close();

        cout << "Data saved to files!\n";
    }

    void loadData()
    {
        ifstream courseFile("courses.txt");
        if (!courseFile)
        {
            cout << "No previous course data found.\n";
        }
        else
        {
            courses.clear();
            string line, code, name;
            while (getline(courseFile, line))
            {
                stringstream ss(line);
                getline(ss, code, ',');
                getline(ss, name, ',');
                courses.push_back(Course(code, name));
            }
            courseFile.close();
            cout << "Courses loaded successfully!\n";
        }

        ifstream studentFile("students.txt");
        if (!studentFile)
        {
            cout << "No previous student data found.\n";
        }
        else
        {
            students.clear();
            string line;
            while (getline(studentFile, line))
            {
                stringstream ss(line);
                int id;
                string name, course;
                ss >> id;
                getline(ss, name, ',');
                Student s(id, name);
                while (getline(ss, course, ','))
                {
                    s.enroll(course);
                }
                students.push_back(s);
            }
            studentFile.close();
            cout << "Students loaded successfully!\n";
        }

        ifstream instructorFile("instructors.txt");
        if (!instructorFile)
        {
            cout << "No previous instructor data found.\n";
        }
        else
        {
            instructors.clear();
            string line;
            while (getline(instructorFile, line))
            {
                stringstream ss(line);
                int id;
                string name, course;
                ss >> id;
                getline(ss, name, ',');
                Instructor i(id, name);
                while (getline(ss, course, ','))
                {
                    i.assignCourse(course);
                }
                instructors.push_back(i);
            }
            instructorFile.close();
            cout << "Instructors loaded successfully!\n";
        }
    }
};

int main()
{
    UniversitySystem system;
    int choice;

    do
    {
        cout << "\n1. Add Course\n"
             << "2. Enroll Student\n"
             << "3. Assign Instructor\n"
             << "4. Display Data\n"
             << "5. Save Data\n"
             << "6. Load Data\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string code, name;
            cout << "Enter course code: ";
            cin >> code;
            cout << "Enter course name: ";
            cin.ignore();
            getline(cin, name);
            system.addCourse(code, name);
        }
        else if (choice == 2)
        {
            int id;
            string name, courseCode;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter course code: ";
            cin >> courseCode;
            system.enrollStudent(id, name, courseCode);
        }
        else if (choice == 3)
        {
            int id;
            string name, courseCode;
            cout << "Enter instructor ID: ";
            cin >> id;
            cout << "Enter instructor name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter course code: ";
            cin >> courseCode;
            system.assignInstructor(id, name, courseCode);
        }
        else if (choice == 4)
        {
            system.displayData();
        }
        else if (choice == 5)
        {
            system.saveData();
        }
        else if (choice == 6)
        {
            system.loadData();
        }
        else if (choice == 7)
        {
            cout << "Exiting program...\n";
        }
        else
        {
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
