#include<bits/stdc++.h>
using namespace std;

enum Walkability {
    noDisability,
    crutches,
    sticks,
    wheelchairs,
    blind,
};

class Personality {
public:
    double lambda, positiveEmotionThreshold, negativeEmotionThreshold;
};

class Emotion {
public:
    double pleasure = 0.75;
    double surprise = 0.5;
    double anger = -0.2;
    double fear = -0.2;
    double hate = -0.4;
    double sad = -0.4;
};

class Event {
public:
    double intensity;
    double time;
};

class Point {
public:
    double x, y;
};

class Ward {
public:
    string name;
    Point entrance;
    Point exit;
    Point A, B, C, D; //4 dinh
    Ward(string name) {
        this->name = name;
    }
};

class AGVEvent : public Event {};

class Pedestrian {
public:
    int ID;
    Ward start;
    Ward end;
    vector<Ward> journey;
    double velocity;
    Personality personality;
    Emotion emotion;
    vector<Event> events;
    double walkingTime;
    double distance;
    double age;
    AGVEvent impactOfAGV;
    Point tempPoints;

    virtual ~Pedestrian() {}  // Virtual destructor
};

class Patient : public Pedestrian{ 
public:
    Walkability walkability;
};

class Visitor: public Pedestrian{ 
public:
    Walkability walkability;
};

class Personel : public Pedestrian{};

//Generate event
vector<Event> generateEvent(Pedestrian &pedestrian, vector<Event> &allEvents, vector<int> &allTimeDistances) {
    vector<Event> events;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, allEvents.size() - 1);

    for(int i=0;i<20;++i) {
        // tao index X ngau nhien
        int X = dis(gen);
        
        // create new Event object based on allEvent[X]
        Event newEvent = allEvents[X];
        int timeDistance = allTimeDistances[X];

        newEvent.time = timeDistance;
        events.push_back(newEvent);
    }
    pedestrian.events = events;
    return events;
}
// int main () {

// }