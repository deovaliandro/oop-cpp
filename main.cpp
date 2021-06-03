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
        this->age = new int(age);
    }

    // Add destructor
    ~Human() {
        std::cout << "Destructor" << std::endl;
    }

    std::string getName(){
        return this->name;
    }

    void setName(const std::string& setname){
        this->name = std::move(name);
    }

    std::string getGender(){
        return this->gender;
    }

    void setGender(std::string setgender){
        this->gender = std::move(setgender);
    }

    [[nodiscard]] int getAge() const{
        return *age;
    }

    void setAge(int lage){
        *age = lage;
    }

private:
    std::string name, gender;
    int * age;
};

class Father: public Human{
    public:
        Father(std::string name1, std::string gender1, int age1)
                : Human(std::move(name1), std::move(gender1), age1) {
        }

        // Destructor
        ~Father() = default;

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
        Mother(std::string name1, std::string gender1, int age1)
                : Human(std::move(name1), std::move(gender1), age1) {
        }

        ~Mother() = default;

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
    auto * father = new Father("Len", "Man", 34);
    father->setName("Yuri");
    father->setGender("Man2");
    father->setAge(22);

    auto * mother = new Mother("nanno", "man", 33);

    father->setName("Papi");
    father->setGender("Man");
    father->setAge(32);

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