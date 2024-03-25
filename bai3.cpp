#include <iostream>
using namespace std;
class Ward
{
    double x_in,y_in,x_out,y_out;
    double length;
    char name;
};
class Emotion
{
    double pleasure=0.75,surprise=0.5,anger=-0.2,fear=-0.2,hate=-0.4,sad=-0.4;
};
class Event
{
    double itensity;
};
class AGVEvent :public Event
{

};
class Enum
{
    double noDisability,crutches,sticks,wheelchair,blind;
};
class Point
{
    double x,y;
};
class Personality
{
    double lambda,positiveEmotionThreshold,negativeEmotionThreshold;
};
class Pedestrian
{
    int id;
    Ward start;
    Ward end;
    Ward journey[100];
    double velocity,walkingTime,distance,age;
    Emotion emotion;
    Event events;
    Point tempPoints;
};
class Patient: public Pedestrian
{
    Enum walkability;
};
class Visitor: public Pedestrian
{
    Enum walkability;
};
class Personal: public Pedestrian
{
    
};
int main()
{

}