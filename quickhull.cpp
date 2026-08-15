#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

int side(point a, point b, point p) {
    return (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
}

int distance(point a, point b, point p) {
    return abs(side(a, b, p));
}

void findhull(vector<point> points, point a, point b) {
    if (points.empty()) {
        return;
    }
    
    int farthest = 0;
    for (size_t i = 1; i < points.size(); i++) {
        if (distance(a, b, points[i]) > distance(a, b, points[farthest])) {
            farthest = i;
        }
    }
    
    point c = points[farthest];
    cout << '(' << c.x << ',' << c.y << ')' << endl;

    vector<point> set1, set2;
    for (point p : points) {
        if (p.x == c.x && p.y == c.y) {
            continue;
        }
        if (side(a, c, p) > 0) {
            set1.push_back(p);
        }
        if (side(c, b, p) > 0) {
            set2.push_back(p);
        }
    }

    findhull(set1, a, c);
    findhull(set2, c, b);
}

void quickhull(vector<point> points) {
    int n = points.size();
    if (n < 3) {
        cout << "at least 3 points needed" << endl;
        return;
    }
    
    point left = points[0];
    point right = points[0];
    for (point p : points) {
        if (p.x < left.x) left = p;
        if (p.x > right.x) right = p;
    }
    
    vector<point> upper, lower;
    for (point p : points) {
        int value = side(left, right, p);
        if (value > 0)
            upper.push_back(p);
        else if (value < 0)
            lower.push_back(p);
    }
    
    cout << "convex hull points:" << endl;
    cout << '(' << left.x << ',' << left.y << ')' << endl;
    cout << '(' << right.x << ',' << right.y << ')' << endl;
    
    findhull(upper, left, right);
    findhull(lower, right, left);
}

int main() {
    vector<point> points = {
        {3, 0}, {2, 2}, {4, 6}, {-1, 3},
        {3, -6}, {11, 4}, {23, -24}, {26, 7}
    };
    
    quickhull(points);
    return 0;
}