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

        // Add destructor
        ~Human() {
            std::cout << "Destructor" << std::endl;
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

        // Destructor
        ~Father();

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

class Mother: public Human{
    public:
        Mother() : Human(getName(), getGender(), getAge()) {}

        void ate() override{
            std::cout << "Mother ate" << std::endl;
        }

        void speak() override{
            std::cout << "Mother ate" << std::endl;
        }

        void walk() override{
            std::cout << "Mother walk" << std::endl;
        }
};

int main(){
    Father * father = new Father;
    // father = &thefather;

    Mother * mother = new Mother;
    // mother = &themother;

    father->setName("Papi");
    father->setGender("Man");
    father->setAge(32);

    mother->setName("Mami");
    mother->setGender("Woman");
    mother->setAge(30);

    father->walk();
    father->speak();
    father->ate();

    std::cout << father->getName() << std::endl;
    std::cout << father->getGender() << std::endl;
    std::cout << father->getAge() << std::endl;

    std::cout << mother->getName() << std::endl;
    std::cout << mother->getGender() << std::endl;
    std::cout << mother->getAge() << std::endl;
}