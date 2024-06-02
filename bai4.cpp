#pragma once
#include "bai3.cpp"

vector<pair<Ward, int>> ex4(Ward a[], int triple, int single){
    default_random_engine generator(time(0));
    normal_distribution<double> distribution(0.0, 1.0);

    int size_of_a = triple*3 + single;
    vector<double> num(size_of_a);

    double sum = 0;
    for (int i = 0; i < size_of_a; ++i) {
        num[i] = distribution(generator);
        sum += num[i];
    }

    for (int i = 0; i < size_of_a; ++i) {
        num[i] = num[i] / sum * size_of_a;
    }
    vector<pair<Ward, int>> res(size_of_a);
    for (int i = 0; i < size_of_a; ++i) {
        res[i] = make_pair(a[i], round(num[i]));
    }
    return res;
}

int main(){
    
}
