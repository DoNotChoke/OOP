#include "bai4.cpp"

void bai5(vector<Pedestrian>& pd, vector<Ward> w) {
    int single = count_if(pd.begin(), pd.end(), [](Pedestrian& p) { return dynamic_cast<Visitor*>(&p) != nullptr; });
    int triple = pd.size() - single;

    map<Ward, int> dict;
    bool all_used = all_of(dict.begin(), dict.end(),
        [](const pair<Ward, int>& a) {
            return a.second == 0;
        });

    while (!all_used) {
        Ward w1[w.size()];
        for (int i = 0; i < w.size(); ++i) w1[i] = w[i];
        vector<pair<Ward, int>> pairs = ex4(w1, triple, single);
        
        for (auto& pair : pairs) {
            dict[pair.first] += pair.second;
        }

        for (auto& p : pd) {
            Visitor* v = dynamic_cast<Visitor*>(&p);
            if (v) {
                auto max_it = max_element(dict.begin(), dict.end(),
                    [](const pair<Ward, int>& a, const pair<Ward, int>& b) {
                        return a.second < b.second;
                    });
                v->journey.push_back(max_it->first);
                max_it->second--;
            }
            else {
                for (int i = 0; i < 3; ++i) {
                    auto max_it = max_element(dict.begin(), dict.end(),
                        [](const pair<Ward, int>& a, const pair<Ward, int>& b) {
                            return a.second < b.second;
                        });
                    p.journey.push_back(max_it->first);
                    max_it->second--;
                }
            }
        }
    }
}