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