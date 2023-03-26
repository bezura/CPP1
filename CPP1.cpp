#include <iostream>
#include<string>
#include <vector>
#include <algorithm>

using namespace std;


class person {
private:
    string name;
    unsigned int age{};
    double weight{};

public:

    string getData_of_name() {
        return name;
    }

    void getName() {
        cout << "Name is : " << name << "\n";
    }

    void getAge() {
        cout << "Age is : " << age << "\n";
    }

    void getWeight() {
        cout << "Weight is : " << weight << "\n";
    }

    void setName(string _name){
        name = _name;
    }

    void setAge(unsigned int _age) {
        age = _age;
    }

    void setWeight(double _weight) {
        weight = _weight;
    }

};

class people {

private:
    vector<person> students;

public:
    void add_front(string _name, int _age, double _weight) {
        //cout << "\nAdd at the beginning\nEnter name, age, weight - in that order.\n";

        person temp;
        temp.setName(_name);
        temp.setAge(_age);
        temp.setWeight(_weight);

        students.insert(students.begin(), temp);

    }

    void add_back(string _name, int _age, double _weight) {
        //cout << "\nAdd at the end\nEnter name, age, weight - in that order.\n";
        
        person temp;
        temp.setName(_name);
        temp.setAge(_age);
        temp.setWeight(_weight);

        students.push_back(temp);

    }
    
    void insert_after_of(string after_name, string _name, int _age, double _weight) {
        //cout << "\nAdd after of\nEnter the name to which to add\n";
        int index=-1;

        person temp;
        temp.setName(_name);
        temp.setAge(_age);
        temp.setWeight(_weight);

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getData_of_name() == after_name) {
                index = i;
            }
        }

        if (index!=-1) students.insert(students.begin() + index + 1,temp);
        else cout<<"No such name was found\n";

    }

    void insert_before_of(string before_name, string _name, int _age, double _weight) {
        //cout << "\nAdd before of\nEnter the name to which to add\n";
        int index=-1;

        person temp;
        temp.setName(_name);
        temp.setAge(_age);
        temp.setWeight(_weight);

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getData_of_name() == before_name) {
                index = i;
            }
        }

        if (index != -1) students.insert(students.begin() + index, temp);
        else cout << "No such name was found\n";
    }
    

    void delete_by_name(string delete_name) {
        vector<int> temp;
        bool Found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getData_of_name() == delete_name) {
                temp.push_back(i);
                Found = true;
            }
        }
        
        if (Found) {
            for (int i = temp.size() - 1; i >= 0; i--) {
                students.erase(students.begin() + temp[i]);
            }
        }
        else cout << "No such name was found\n";
    }
    
    void display_list() {
        for (int i = 0; i < students.size(); i++) {
            cout << i+1<<"\n";
            students[i].getName();
            students[i].getAge();
            students[i].getWeight();
            cout << endl;
        }
    }

};


int main()
{
    people rudn;
    while (true)
    {
        cout << "What should I do?\nEnter the action number\n1- Adding an item to the beginning of the list;\n2- Adding an item to the end of the list;\n3- Adding an item to the list after a given item;\n4- Adding an item to the list before a specified item;\n5- Deletes from the list the item with the given name;\n6- Display the contents of the list on the screen;\n7-EXIT\n";

        short n;
        cin >> n;
        cout << "\n";

        if (!(n >= 1 and n <= 7)) {

            cout << "\nError in the range, try again\n";
            cout << "Press any button to continue\n";
            cin.get();

            main();

        }

        switch (n)
        {
        case 1: {
            cout << "Add at the beginning\nEnter name, age, weight - in that order.\n";
            string name;
            unsigned int age;
            double weight;

            cin >> name >> age >> weight;
            cout << "\n";

            rudn.add_front(name, age, weight);
            break;
        }
        case 2: {
            cout << "Add at the end\nEnter name, age, weight - in that order.\n";
            string name;
            unsigned int age;
            double weight;

            cin >> name >> age >> weight;
            cout << "\n";

            rudn.add_back(name, age, weight);
            break;
        }
        case 3: {
            cout << "Add after of\nEnter the name after which you want to add\n";
            string after_name;
            string name;
            unsigned int age;
            double weight;

            cin >> after_name;
            cout << "\n";
            cout << "What to add?\nEnter name, age, weight - in that order.\n";
            cin >> name >> age >> weight;
            cout << "\n";

            rudn.insert_after_of(after_name, name, age, weight);
            break;
        }
        case 4: {
            cout << "Add before of\nEnter the name before which you want to add\n";
            string before_name;
            string name;
            unsigned int age;
            double weight;

            cin >> before_name;
            cout << "\n";
            cout << "What to add?\nEnter name, age, weight - in that order.\n";
            cin >> name >> age >> weight;
            cout << "\n";

            rudn.insert_before_of(before_name, name, age, weight);
            break;
        }
        case 5: {
            cout << "Delete by name\n Enter the name\n";
            string delete_name;
            cin >> delete_name;
            cout << "\n";

            rudn.delete_by_name(delete_name);
            break;
        }
        case 6: {
            cout << "List{\n";
            rudn.display_list();
            cout << "}\n";
            break;
        }
        case 7: {
            cout << "Thank";
            return 0;
            break;
        }
        }
    }
    
    
    
}
