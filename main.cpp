#include <string>
#include <iostream>

class Human {
    public:
        virtual void ate() = 0;
        virtual void speak() = 0;
        virtual void walk() = 0;

        Human (std::string name, std::string gender, int age){
            this->name = name;
            this->gender = gender;
            this->age = age;
        }

        std::string getName(){
            return this->name;
        }

        void setName(std::string name){
            this->name = name;
        }

        std::string getGender(){
            return this->gender;
        }

        void setGender(std::string gender){
            this->gender = gender;
        }

        int getAge(){
            return this->age;
        }

        void setAge(int age){
            this->age = age;
        }

    private:
        std::string name, gender;
        int age;
};

class Father: public Human{
    public:
        Father() : Human(name, gender, age), name(name), gender(gender), age(age) {}

        void ate(){
            std::cout << "Father ate" << std::endl;
        }

        void speak(){
            std::cout << "Father speak" << std::endl;
        }

        void walk(){
            std::cout << "Father walk" << std::endl;
        }

        private:
            std::string name, gender;
            int age;
};

int main(){
    Father * father, afather;
    father = &afather;
    father->setName("Paul");
    father->setGender("Man");
    father->setAge(40);
    father->ate();
    father->speak();
    father->walk();
}