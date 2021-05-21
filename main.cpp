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

        std::string getName();
        void setName(std::string name);
        std::string getGender();
        void setGender(std::string gender);
        int getInt();
        void setInt(int age);
    
    private:
        std::string name, gender;
        int age;
};

std::string Human::getName(){
    return this->name;
}

void Human::setName(std::string name){
    this->name = name;
}

std::string Human::getGender(){
    return this->gender;
}

int main(){
    
}