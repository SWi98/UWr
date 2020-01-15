#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person{
    string name;
    int weight;
    int age;
    int height;
    Person(string name, int weight, int age, int height):
        name(name), weight(weight), age(age), height(height) {};
};

ostream& operator<<(ostream& os, const Person& person){
    os << person.name << ", wiek: " << person.age << ", waga: " << person.weight << ", wzrost: " << person.height;
    return os;
}

void print(vector<Person>& reg){
    for(int i = 0; i < reg.size(); i++){
        cout << reg[i] << endl;
    }
    cout << endl;
}

int main(){
    vector<Person> reg;
    reg.push_back(Person("Jan Kowalski", 60, 40, 170));
    reg.push_back(Person("Joanna Kowalska", 70, 30, 175));
    reg.push_back(Person("Andrzej Nowak", 120, 20, 200));
    reg.push_back(Person("Jakub Kwiatkowski", 100, 30, 173));
    reg.push_back(Person("Janina Kowalczyk", 55, 60, 165));
    reg.push_back(Person("Daniel Wojcik", 70, 21, 178));

    sort(reg.begin(), reg.end(), [](Person one, Person two){
        return one.weight < two.weight;
    });

    cout << "Posortowane wg wagi: \n";
    print(reg);

    sort(reg.begin(), reg.end(), [](Person one, Person two){
        return one.height < two.height;
    });

    cout << "Posortowane wg wzrostu: \n";
    print(reg);

    sort(reg.begin(), reg.end(), [](Person one, Person two){
        return one.age < two.age;
    });

    cout << "Posortowane wg wieku: \n";
    print(reg);

    sort(reg.begin(), reg.end(), [](Person one, Person two){
        return one.weight / ((double)one.height * (double)one.height) < two.weight / ((double)two.height * (double)two.height);
    });

    cout << "Posortowane wg BMI: \n";
    print(reg);

    cout << "Osoba o maks. wadze: " << *max_element(reg.begin(), reg.end(), [](Person one, Person two){
        return one.weight < two.weight;
    }) << endl;
    cout << "Osoba o maks. wzroscie: " << *max_element(reg.begin(), reg.end(), [](Person one, Person two){
        return one.height < two.height;
    }) << endl;
    cout << "Osoba o maks. wieku: " << *max_element(reg.begin(), reg.end(), [](Person one, Person two){
        return one.age < two.age;
    }) << endl;

}