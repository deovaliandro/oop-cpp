#include <string>
#include <iostream>
#include <utility>

class Human {
    public:
        virtual void ate() = 0;
        virtual void speak() = 0;
        virtual void walk() = 0;

        Human (std::string name, std::string gender, int age){
            this->name = std::move(name);
            this->gender = std::move(gender);
            this->age = age;
        }

        std::string getName(){
            return this->name;
        }

        void setName(std::string name2){
            this->name = std::move(name2);
        }

        std::string getGender(){
            return this->gender;
        }

        void setGender(std::string gender2){
            this->gender = std::move(gender2);
        }

        [[nodiscard]] int getAge() const{
            return this->age;
        }

        void setAge(int age2){
            this->age = age2;
        }

    private:
        std::string name, gender;
        int age;
};

class Father: public Human{
    public:
        Father() : Human(name, gender, age), name(name), gender(gender), age(age) {}

        void ate() override{
            std::cout << "Father ate" << std::endl;
        }

        void speak() override{
            std::cout << "Father speak" << std::endl;
        }

        void walk() override{
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
    
    std::cout << father->getName() << std::endl;
    std::cout << father->getGender() << std::endl;
    std::cout << father->getAge() << std::endl;
}