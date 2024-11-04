#include <iostream>
#include <vector>
#include <string>



class Person {
public:
    std::string name;
    Person* mom;
    Person* dad;
    std::vector<Person*> siblings;

    int* p = nullptr
    Person(std::string name) : name(name), mom(nullptr), dad(nullptr) {}

    void addParents(std::string father_name, std::string mother_name) {
        dad = new Person(father_name);
        mom = new Person(mother_name);
    }

    void addSibling(Person* sibling) {
        siblings.push_back(sibling);
        sibling->siblings.push_back(this);
    }

    int count() {
        int sum = 1;  // Counting this person
        if (mom != nullptr) sum += mom->count();
        if (dad != nullptr) sum += dad->count();
        return sum;
    }

    bool isRelated(std::string person_name) {
        if (name == person_name) return true;
        if (mom != nullptr && mom->isRelated(person_name)) return true;
        if (dad != nullptr && dad->isRelated(person_name)) return true;
        for (Person* sibling : siblings) {
            if (sibling->name == person_name) return true;
        }
        return false;
    }

    void printFamilyTree(int generation = 0) {
        std::string prefix = std::string(generation * 2, ' ');  // Indentation
        std::cout << prefix << name << std::endl;
        if (mom != nullptr) {
            std::cout << prefix << "Mom: ";
            mom->printFamilyTree(generation + 1);
        }
        if (dad != nullptr) {
            std::cout << prefix << "Dad: ";
            dad->printFamilyTree(generation + 1);
        }
        for (Person* sibling : siblings) {
            std::cout << prefix << "Sibling: " << sibling->name << std::endl;
        }
    }
};

int main() {
    Person me("Jun Lau");
    me.addParents("Father Lau", "Mother Lau");
    me.mom->addParents("Grandfather on Mom's side", "Grandmother on Mom's side");
    me.dad->addParents("Grandfather on Dad's side", "Grandmother on Dad's side");

    Person* uncle = new Person("Uncle Lau");
    me.dad->addSibling(uncle);

    me.printFamilyTree();  // Print the whole family tree

    std::cout << "The tree has " << me.count() << " people in it." << std::endl;
    std::cout << "Is related to Grandfather on Mom's side: " << me.isRelated("Grandfather on Mom's side") << std::endl;
    std::cout << "Is related to Someone else: " << me.isRelated("Someone else") << std::endl;

    return 0;
}
