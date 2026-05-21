//
// Created by acer_ on 21.05.2026.
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Human
{
    vector<string> knownHumans = vector<string>();
    string name;
public:
    Human(string& name) : name(name)
    {
        cout << "Created Human" << endl;
    }

    ~Human()
    {
        cout << "Removed Human" << endl;
    }

    string& getName()
    {
        return name;
    }

    vector<string> getKnownHumans()
    {
        return knownHumans;
    }

    void addFriend(string& otherName)
    {
        knownHumans.push_back(otherName);
    }

    bool knowsHuman(const std::string& otherName) {
        const std::vector<std::string>& known = getKnownHumans();
        return std::find(known.begin(), known.end(), otherName) != known.end();
    }

    virtual void reaction(Human& other) = 0;
};

class Woman : public Human
{
public:
    Woman(string& name) : Human(name)
    {
        cout << "Created Woman" << endl;
    }

    ~Woman()
    {
        cout << "Destroyed Woman" << endl;
    }

    void reaction(Human& other) override
    {
        if (knowsHuman(other.getName())) {
            cout << "Oh, " << other.getName() << ", Hello friend!" << endl;
        }
        else
        {
            cout << "Hello, who are you?" << endl;
            addFriend(other.getName());
        }
    }
};

class YoungMan : public Human
{
public:
    YoungMan(string& name) : Human(name)
    {
        cout << "Created YoungMan" << endl;
    }

    ~YoungMan()
    {
        cout << "Destroyed YoungMan" << endl;
    }

    void reaction(Human& other) override
    {
        if (knowsHuman(other.getName())) {
            cout << "Oh, " << other.getName() << ", Hello bro!" << endl;
        }
        else
        {
            cout << "Hello, " << other.getName() << endl;
            addFriend(other.getName());
        }
    }
};

void task2()
{
    cout << "Give a name to a Young Man" << endl;

    string youngManName;
    cin >> youngManName;

    YoungMan man = YoungMan(youngManName);
    cout << "Young Man has the name of - " << man.getName() << endl << endl;

    string womanName = "Eve";
    Woman eve = Woman(womanName);
    cout << "Woman has the name of - " << eve.getName() << endl;

    cout << endl << "Does Woman know of Young Man? " << eve.knowsHuman(youngManName) << endl;
    eve.reaction(man);
    cout << "Does Woman know Young Man now? " << eve.knowsHuman(youngManName) << endl << endl;
}

