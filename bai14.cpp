#include<bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

void cau_a() {
    Point a, b, c, d; // 4 dinh
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    int m, n; // so khoa/ vien tren cung hang ngang va hang doc
    cin >> m >> n;
    double chieungang, chieusau; // cua moi khoa/vien tren
    cin >> chieungang >> chieusau;


    double d1 = b.x - a.x; //chieu dai tong
    double d2 = c.y - b.y; //chieu rong tong

    double cn_khoa = d1 / m - a.x;
    double cs_khoa = d2 / n - b.y;


    int so_khoa = m * n;
    vector<Point> v(so_khoa);
    vector<double> vx, vy;
    double k = a.x + cn_khoa/2;
    while(k < b.x) {
        vx.push_back(k);
        k += cn_khoa;
    }
    k = a.y + cs_khoa/2;
    while(k < d.y) {
        vy.push_back(k);
        k += cs_khoa;
    }
    for(int i=0;i<vx.size();++i) {
        for(int j=0;j<vy.size();++j) {
            v[m * i + j] = {vx[i], vy[j]};  
        }
    }
    
    for(auto it : v) {
        cout << it.x << ',' << it.y << ',' << cn_khoa << ',' << cs_khoa << '\n';
    }
}

void cau_b() {
    
}

int main() {
    cau_a();

}