#pragma once
#include "iostream"
#include "vector"
using namespace std;

enum Walkability {
    noDisability,
    crutches,
    sticks,
    wheelchairs,
    blind,
};
class Personality {
    int lambda;
    double positiveEmotionThreshold;
    double negativeEmotionThreshold;
};

class Emotion {
    double pleasure = 0.75;
    double surprise = 0.5;
    double anger = -0.2;
    double fear = -0.2;
    double hate = -0.4;
    double sad = -0.4;
};

class Event {
    double intensity;           //chua hieu ?
    double time;
};

class AVGEvent : public Event {
    // no code    
};

class Point{
    double x;
    double y;
};
class Ward {
    string name;
    Point entrance;
    Point exit;
    Point A, B, C, D;        //4 diem cua buc tuong
    /* A--------B
       |        |
       D--------C*/
};


class Pedestrian {
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
    AVGEvent impactOfAGV;
    Point tempPoints;
};

class Patient : public Pedestrian{};

class Visitor: public Pedestrian{};

class Personel : public Pedestrian{};