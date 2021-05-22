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

        int getAge() const{
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
        Father() : Human(getName(), getGender(), getAge()){}

        void ate() override{
            std::cout << "Father ate" << std::endl;
        }

        void speak() override{
            std::cout << "Father speak" << std::endl;
        }

        void walk() override{
            std::cout << "Father walk" << std::endl;
        }
};

int main(){
    Father father;
    father.setName("Test");
    father.setGender("Man");
    father.setAge(22);

    father.walk();
    father.speak();
    father.ate();

    std::cout << father.getName() << std::endl;
    std::cout << father.getGender() << std::endl;
    std::cout << father.getAge() << std::endl;
}