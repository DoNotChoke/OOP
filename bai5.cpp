#include<bits/stdc++.h>
#include "bai4.cpp"
using namespace std;

int countVisitors(vector<Pedestrian>& pedestrians) { // dem Visitors
    int cnt = 0;
    for(const auto& pedestrian : pedestrians) {
        if (dynamic_cast<const Visitor*>(&pedestrian)) {
            cnt++;
        }
    }
    return cnt;
}

void assignJourney(vector<Pedestrian> pedestrians, vector<Ward> wards) {
    int single = countVisitors(pedestrians);
    int triple = pedestrians.size() - single;
    auto genPairs = generatePairs(wards, triple, single);
    
    unordered_map<char, int> charCount;

    bool useAllCharacters = false;
    while(!useAllCharacters) {
        useAllCharacters = true;
        
        for(auto &pair: genPairs) {
            for(char c : pair.first)
                charCount[c]++; //dem so lan xuat hien
        }

        for(auto &pedestrian : pedestrians) {
            if(auto visitor = dynamic_cast<const &Visitor*>(&pedestrian)) {
                char c = max_element(charCount.beign(), charCount.end(), [](const auto &a, const auto &b){
                    return a.second < b.second;
                })->first;
                visitor->journey.push_back(Ward(c));
                charCount[c]--;
                if (charCount[c] == 0) {
                    charCount.erase(c);
                }
            } else if (auto personnel = dynamic_cast<Personnel*>(&pedestrian)) {
                for (int i = 0; i < 3; ++i) {
                    char c = max_element(charCount.begin(), charCount.end(), [](const auto& a, const auto& b) { 
                        return a.second < b.second; 
                    })->first;
                    personnel->journey.push_back(Ward(c));
                    charCount[c]--;
                    if (charCount[c] == 0) {
                        charCount.erase(c);
                    }
                }
            } else if (auto patient = dynamic_cast<Patient*>(&pedestrian)) {
                for (int i = 0; i < 3; ++i) {
                    char c = max_element(charCount.begin(), charCount.end(), [](const auto& a, const auto& b) {
                        return a.second < b.second; 
                    })->first;
                    patient->journey.push_back(Ward(c));
                    charCount[c]--;
                    if (charCount[c] == 0) {
                        charCount.erase(c);
                    }
                }
            }
        }

        if(!charCount.empty()) {
            useAllCharacters = false;
        }
    }

}