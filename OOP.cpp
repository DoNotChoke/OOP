#include <bits/stdc++.h>
using namespace std;
class Ward{
    string name;
    double entranceX, entranceY;
    double exitX, exitY;
    double wallX1, wallY1, wallX2, wallY2;
};
class Point{
public:
    double x,y;
};
class Event{
    double intensity;
    double time;
};
enum Walkability{
    noDisability,
    crutches,
    sticks,
    wheelchairs,
    blind
};
class Personality{
public:
    double lambda;
    double positiveEmotionThreshold;
    double negativeEmotionThreshold;
};
class Emotion{
public:
    double pleasure = 0.75;
    double surprise = 0.5;
    double anger = -0.2;
    double fear = -0.2;
    double hate = -0.4;
    double sad = -0.4;
};
class AGVEvent{};
class Pedestrian{
public:
    int ID;
    Ward start, end;
    vector<Ward> journey;
    double velocity;
    Personality personality;
    Emotion emotion;
    vector<Event> events;
    double walktingTime;
    double distance;
    double age;
    AGVEvent impactOfAGV;
    Point tempPoints;
};
class Patient : public Pedestrian {
public:
    Walkability walkability;
};
class Visitor : public Pedestrian {
public:
    Walkability walkability;
};

class Personel : public Pedestrian {};
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}