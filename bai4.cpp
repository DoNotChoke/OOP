#include <iostream>
#include <vector>
#include <random>
#include <string>
using namespace std;
vector<int> result;
class Ward
{
    double entranceX,entranceY,exitX,exitY;
    double wallX1,wallX2,wallY1,wallY2;
    string name;
};
vector<int> process(Ward human[],int triple,int single)
{
    double limit=3*triple+single;
    vector<int> result;
    default_random_engine generator;
    normal_distribution<double> distribution(limit/100,1.0);
    int r=0;
    for (int i=0;i<1000;i++){
        double number=distribution(generator);
        int temp=round(number);
        r+=temp;
        result.push_back(temp);
        if (r>=limit) {
            result.push_back(limit-r);
            break;
        }
    }
    // cout<<endl<<r<<endl;
    return result;
}
int main()
{
    Ward a[100];
    int x;
    cin>>x;
    int sum=0;
    vector<int> result=process(a,x,100-x);
    for(int i=0;i<result.size();i++){
        sum+=result[i];
        cout<<result[i]<<" ";
    }
    cout<<endl<<sum;
}