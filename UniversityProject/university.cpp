#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Department
{

protected:
    string name_dep;
    int capacity;
    double required_gpa;

public:
    Department()
    {
        name_dep = "";
        capacity = 0;
        required_gpa = 0;
    }

    Department(string dep_name, int dep_capacity, double dep_required_gpa)
    {
        name_dep = dep_name;
        capacity = dep_capacity;
        required_gpa = dep_required_gpa;
    }

    void set_name(string s)
    {

        name_dep = s;
    }
    void set_capacity(int c)
    {

        capacity = c;
    }
    void set_gpa(double g)
    {

        required_gpa = g;
    }

    string get_name(void)
    {

        return name_dep;
        ;
    }
    int get_capacity(void)
    {

        return capacity;
    }
    double get_gpa(void)
    {

        return required_gpa;
    }


    ~Department(){}
};


class Person
{
protected:
    string name;
    int ID;
    string gender;
    int age;

public:
    Person(){};

    Person( int ID,const string name, int age, string gender)
            : ID(ID),name(name), age(age),gender(gender) {}

    string get_name() const
    {
        return name;
    }

    int get_iD() const
    {
        return ID;
    }

    string get_gender() const
    {
        return gender;
    }

    int getAge() const
    {
        return age;
    }

    void display_details() const
    {
        cout << "Person Details:" << std::endl;
        cout << "Name: " << name << std::endl;
        cout << "ID: " << ID << std::endl;
        cout << "Gender: " << gender << std::endl;
        cout << "Age: " << age << std::endl;
    }
    ~Person(){};
};

class Student : public Person
{
private:
    int level;
    double GPA;

public:
    Student() {}
    Student(int id,string name,int age, char gender,int level ,double gpa)
    {
        this->ID=id;
        this->name=name;
        this->age=age;
        this->gender=gender;
        this->level=level;
        this->GPA=gpa;


    }
    void set_level(int l)
    {
        level = l;
    }

    int get_level() const
    {
        return level;
    }

    double get_gPA() const
    {
        return GPA;
    }

    void display_details() const
    {
        Person::display_details();
        cout << "Level: " << level << endl;
        cout << "GPA: " << GPA << endl;
    }
    ~Student(){};

};

class Professor : public Person
{
private:
    double salary;
    string degree;
    Department *department;

public:
    Professor(){}

    Professor(int id,string name,int age,char gendre,Department *department,double salary,string degree)
    {
        this->ID=id;
        this->name=name;
        this->age=age;
        this->gender=gender;
        this->department=department;
        this->salary=salary;


    }


    void set_salary(double s)
    {
        salary = s;
    }

    double get_salary() const
    {
        return salary;
    }

    string get_degree() const
    {
        return degree;
    }

    void display_details() const
    {
        Person::display_details();
        cout << "Salary: " << salary << endl;
        cout << "Degree: " << degree << endl;
    }
    ~Professor(){};

};

class Course
{
private:
    string name;
    string code;
    int hours;
    vector<Course*> prerequisites; // vector<course>
    vector<Student*> students;
    Professor *professor;

public:
    Course()
    {
        name = "";
        code = "";
        hours = 0;
        prerequisites = {};
    };
    Course(string name, string code, int hours, vector<Course*> pre,  Professor *pro, vector<Student*> students)
    {

        this->name = name;
        this->code = code;
        this->hours = hours;
        this->prerequisites = pre;
        this->students = students;
        this->professor = professor;
    };
    void set_name(string s)
    {
        name = s;
    }
    void set_code(string s)
    {
        code = s;
    }
    void set_hours(int a)
    {
        hours = a;
    }
    void set_professor(Professor *p)
    {
        professor = p;
    }

    void set_students(vector<Student*> s)
    {
        students = s;
    }
    void set_prerequisites(vector<Course*>c)
    {
        prerequisites=c;

    }

    string get_name()
    {
        return name;
    }
    string get_code()
    {
        return code;
    }
    int get_hours()
    {
        return hours;
    }
    Professor *get_professor()
    {
        return professor;
    }
    vector<Student*> get_students()
    {
        return students;
    }
    vector<Course*> get_prerequisites()
    {

        return prerequisites;
    }
    void print_name()
    {
        cout << name << endl;
    }
    void print_code()
    {
        cout << code << endl;
    }
    void print_hours()
    {
        cout << hours << endl;
    }



    ~Course(){}
};

class university
{
private:
    static university *ptr;
    university(){addData();};

    vector<Student> students;
    vector<Professor> professors;
    vector<Course> courses;
    vector<Department> departments;


public:
    //course
    university(const university &obj) = delete;
    static university *get_ptr()
    {
        if (ptr == NULL)
        {
            ptr = new university();
        }

        return ptr;
    }

    void add_course(string n, string co, int h, vector<Course*> pre, vector<Student*> s, Professor *p)
    {
        Course c(n, co, h, pre, p, s);

        courses.push_back(c);
    }
    void remove_course(string c)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].get_code() == c)
            {
                courses.erase(courses.begin() + i);
            }
        }
    }
    void update_course(string c, int h)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].get_code() == c)
            {
                courses[i].set_hours(h);
            }
        }
    }
    void add_student(int ID,string name,int age,char gender, int level, double GPA)
    {
        Student student(ID, name,  age,gender,  level,  GPA);
        students.push_back(student);
    }
    void remove_student(int id)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].get_iD() == id)
            {
                students.erase(students.begin() + i);
            }
        }
    }
    void updateStudent(int ID,int level)
    {

        for (int i=0;i<students.size();i++)
        {
            if (students[i].get_iD() == ID) // here
            {
                students[i].set_level(level);

                return;
            }
        }


        cout << "Student with ID " << ID << " not found." << endl;

    }

    void add_professor(int ID,string name, int age,char gender,Department *department,  double salary, string degree)
    {
        Professor professor(ID, name, age, gender, department,salary, degree);
        professors.push_back(professor);
    }
    void remove_professor(int id)
    {
        for (int i = 0; i < professors.size(); i++)
        {
            if (professors[i].get_iD() == id)
            {
                professors.erase(professors.begin() + i);
            }
        }
    }
    void update_professor(int id, int s)
    {
        for (int i = 0; i < professors.size(); i++)
        {
            if (professors[i].get_iD() == id)
            {
                professors[i].set_salary(1);
            }
        }
    }
    void add_department(string name, int capacity, double required_gpa)
    {
        Department department(name,capacity,required_gpa);
        departments.push_back(department);
    }
    void remove_department(string n)
    {
        for (int i = 0; i < departments.size(); i++)
        {
            if (departments[i].get_name() == n)
            {
                departments.erase(departments.begin() + i);
            }
        }
    }
    void update_department(string n, int c)
    {
        for (int i = 0; i < departments.size(); i++)
        {
            if (departments[i].get_name() == n)
            {
                professors[i].set_salary(c);
            }
        }
    }


    void addData()
    {
        Department d1("Web Development", 50, 3.2);
        departments.push_back(d1);
        Department d2("Cyber Security", 33, 3.5);
        departments.push_back(d2);
        Department d3("Artificial Intelligence", 20, 3.0);
        departments.push_back(d3);
        Department d4("Information Systems", 125, 2.5);
        departments.push_back(d4);

        Student s1(1,"Ahmed Ali", 19, 'M', 2, 2.74);
        students.push_back(s1);
        Student s2(2,"Mirna Hussein", 22, 'F', 4, 3.68);
        students.push_back(s2);
        Student s3(3,"Hamada Hossam", 28, 'M', 3, 2.37);
        students.push_back(s3);
        Student s4(4,"Taghreed Mohsen", 20, 'F', 3, 3);
        students.push_back(s4);
        Student s5(5,"Yasmin Belal", 18, 'F', 1, 3.71);
        students.push_back(s5);
        Student s6(6,"Amr Diab", 50, 'M', 4, 2.01);
        students.push_back(s6);
        Student s7(7,"Tamer Hosny", 30, 'M', 3, 2.02);
        students.push_back(s7);
        Student s8(8,"Ahmed Alaa", 21, 'M', 2, 2.49);
        students.push_back(s8);

        Professor p1(1,"Mohamed Ali", 56, 'M', &d1, 12000, "Masters");
        professors.push_back(p1);
        Professor p2(2,"Ehsan Ahmed", 43, 'M', &d2, 8500, "Masters");
        professors.push_back(p2);
        Professor p3(3,"Ahmed Mohsen", 68, 'M', &d3, 19380, "Masters");
        professors.push_back(p3);
        Professor p4(4,"Abdelhady", 61, 'M', &d4, 22728, "Masters");
        professors.push_back(p4);
        Professor p5(5,"Taghreed Mohsen", 49, 'F', &d2, 11068, "Masters");
        professors.push_back(p5);


        vector<Student*> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student*> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1("HTML", "HTML123", 12, vector<Course*>(), &p1, st1);
        courses.push_back(c1);
        vector<Course*> crs1;
        crs1.push_back(&c1);
        Course c2("CSS", "CSS123", 9, crs1,&p3, st2);
        courses.push_back(c2);
        Course c3("Networks", "Net521", 18, crs1, &p5, st2);
        courses.push_back(c3);
    }

    void printAll()
    {
        for(int i=0; i<departments.size(); i++)
        {
            cout<<"Department: "<<departments[i].get_name()<<endl;
        }
        for(int i=0; i<professors.size(); i++)
        {
            cout<<"Professor Name: "<<professors[i].get_name()<<endl;
        }
        for(int i=0; i<students.size(); i++)
        {
            cout<<"Student Name: "<<students[i].get_name()<<endl;
        }
        for(int i=0; i<courses.size(); i++)
        {
            cout<<"Course Name: "<<courses[i].get_name()<<endl;
        }
    }
    ~university(){};
};
university *university ::ptr = NULL;

int main()
{
    university *ptr=university::get_ptr();
    ptr->printAll();
    return 0;
}
