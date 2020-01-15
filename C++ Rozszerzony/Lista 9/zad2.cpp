#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct Point{
    string name;
    int x;
    int y;
    int R;
    int G;
    int B;
    Point(string name, int x, int y, int R, int G, int B):
        name(name), x(x), y(y), R(R), G(G), B(B) {};
};

ostream& operator<<(ostream& os, const Point& point){
    os << point.name << " = (" << point.x << "; " << point.y << "), RGB: (" << point.R << "; " << point.G << "; " << point.B << ")";
    return os;
}

void print(list<Point> points){
    for(auto x: points){
        cout << x << endl;
    }
    cout << endl;
}

double Luma(int r, int g, int b){
    return 0.299 * r + 0.587 * g + 0.114 * b; 
}

int main(){
    list<Point> points;
    points.push_back(Point("A", 1, 1, 100, 200, 300));
    points.push_back(Point("B", 3, 123, 0, 12, 813));
    points.push_back(Point("C", -5, 99, 99, 123, 11));
    points.push_back(Point("D", -1, -32, 740, 213, 983));
    points.push_back(Point("E", 7, -100, 0, 1, 2));
    points.push_back(Point("F", -80, 0, 821, 82, 800));
    points.push_back(Point("G", -8, 723, 600, 600, 600));
    points.push_back(Point("H", -324, 4, 631, 111, 111));
    points.push_back(Point("I", 29, -333, 123, 321, 670));
    points.push_back(Point("J", -8, -11, 0, 222, 0));
    points.push_back(Point("K", 5, 6, 100, 0, 100));

    list<Point> first;
    list<Point> second;
    list<Point> third;
    list<Point> fourth;

    copy_if(points.begin(), points.end(), back_inserter(first), [](Point point){
        return point.x > 0 && point.y > 0;
    });
    copy_if(points.begin(), points.end(), back_inserter(second), [](Point point){
        return point.x < 0 && point.y > 0;
    });
    copy_if(points.begin(), points.end(), back_inserter(third), [](Point point){
        return point.x < 0 && point.y < 0;
    });
    copy_if(points.begin(), points.end(), back_inserter(fourth), [](Point point){
        return point.x > 0 && point.y < 0;
    });

    cout << "Pierwsza cw:\n";
    print(first);
    cout << "Druga cw:\n";
    print(second);
    cout << "Trzecia cw:\n";
    print(third);
    cout << "Czwarta cw:\n";
    print(fourth);

    auto minmax = minmax_element(points.begin(), points.end(), [](Point one, Point two){
        return Luma(one.R, one.G, one.B) > Luma(two.R, two.G, two.B);
    });
    cout << "Najjasniejszy punkt: " << *minmax.first << endl;
    cout << "Najciemniejszy punkt: " << *minmax.second << endl;
}