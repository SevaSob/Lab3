#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;
    double averageScore;

public:
    Student(const std::string& n, int a, double avg)
        : name(n), age(a), averageScore(avg) {}

    void display() const {
        std::cout << "Студент: " << name
            << ", возраст: " << age
            << ", средний балл: " << averageScore << std::endl;
    }

    void setAverageScore(double avg) {
        averageScore = avg;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Student student1("Иванов Иван", 20, 4.5);
    Student student2("Петрова Анна", 19, 4.8);

    std::cout << "Информация о студентах:\n";
    student1.display();
    student2.display();

    student1.setAverageScore(4.7);
    std::cout << "\nПосле изменения среднего балла:\n";
    student1.display();

    return 0;
}