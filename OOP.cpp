#include <bits/stdc++.h>
using namespace std;
class Point{
    double x, y;
};
class Ward{
    char name;
    Point p;
};
class Personality{
    int lambda;
    double positiveEmotionThreshold, negativeEmotionThreshold;
};
class Open : public Personality{
public:
    Open(){}
};
class Neurotic: public Personality{
public:
    Neurotic(){}
};
class Emotion{
    double pleasure, surprise, anger, fear, hate, sad;
public:
};
class Event{

};
class AGVEvent: public Event{
};
class Pedestrian{
    int ID;
    Ward start, end;
    vector<Ward> journey;
    double velocity, walkingTime, distance, age;
    Personality personality;
    Emotion emotion;
    vector<Event> events;
    AGVEvent impactOfAGV;
    Point tempPoints;
};
class Patient: public Pedestrian{
    enum Walkability {
        noDisability,
        crutches,
        sticks,
        wheelchairs,
        blind
    };
};
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}
