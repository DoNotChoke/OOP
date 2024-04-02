#include<bits/stdc++.h>
#include "bai3.cpp"
using namespace std;

vector<pair<Ward, int>> generatePairs(vector<Ward> wards, int triple, int single) {
    vector<pair<Ward, int>> pairs;
    int limit = 3 * triple + single;
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double> distribution(limit/100.0, 1.0); //Mean = limit/numOfAgents, deviation = 1.0

    int curNum = 100; //numOfAgents = 100

    // Tạo các pair cho mảng có 3 phần tử
    for (int i = 0; i < triple; ++i) {
        if (wards.empty()) break;
        Ward ward = wards.back();
        int agents_in_ward = round(distribution(gen)); // Lấy số lượng phần tử theo phân phối chuẩn
        agents_in_ward = min(agents_in_ward, curNum); // Giới hạn số lượng phần tử theo số lượng còn lại
        pairs.emplace_back(ward, agents_in_ward);
        wards.pop_back();
        curNum -= agents_in_ward;
    }

    // Tạo các pair cho mảng có 1 phần tử
    for (int i = 0; i < single; ++i) {
        if (wards.empty()) break;
        Ward ward = wards.back();
        int agents_in_ward = round(distribution(gen)); // Lấy số lượng phần tử theo phân phối chuẩn
        agents_in_ward = min(agents_in_ward, curNum); // Giới hạn số lượng phần tử theo số lượng còn lại
        pairs.emplace_back(ward, agents_in_ward);
        wards.pop_back();
        curNum -= agents_in_ward;
    }

    return pairs;
}