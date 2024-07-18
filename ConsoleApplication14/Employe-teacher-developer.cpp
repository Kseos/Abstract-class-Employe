#include <iostream>
using std::string;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
private:  
    int Age;
protected:
    string Name;
    string Company;
public:
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
    void setName(string name) {
        Name = name;
    }
    void setCompany(string company) {
        Company = company;
    }
    void setAge(int age) {
        Age = age;
    }
    void IntroduceYourself() {
        std::cout << "Name is" << Name << std::endl;
        std::cout << "Company is" << Company << std::endl;
        std::cout << "Age is" << Age << std::endl;
    }
    void AskForPromotion() {
        if (Age > 25) {
            std::cout << Name << " got promoted!";
        }
        else std::cout << Name << " didn't get a promotion.";
    }
    virtual void Work() {
        std::cout << Name << " is working" << std::endl;
    }
};
class Developer:public Employee {
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string fpl)
        :Employee(name, company, age) {
        FavProgrammingLanguage = fpl;
    }
    void Work() {
        std::cout << Name << " is writing " << FavProgrammingLanguage << " code in " << Company << std::endl;
    }
};
class Teacher:public Employee {
public:
    string Subject;
    void PrepareLesson() {
        std::cout << Name << " is preparing a " << Subject << " lesson.";
    }
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age) {
        Subject = subject;
    }
    void Work() {
        std::cout << Name << " is teaching " << Subject << " in " << Company << std::endl;
    }
};
int main()
{
    Developer d = Developer("Denny", "Amazon", 24, "C++");
    Teacher t = Teacher("Jack", "High School", 30, "History");

    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->Work();
    e2->Work();
}
