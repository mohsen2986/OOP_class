#include <iostream>
using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(){
        this->x = 0;
        this->y = 0;
    }
    Point(int x , int y){
        this->x = x;
        this->y =y;
    }
//        Point operator+(Point point2){
//        Point temp;
//        temp.x = point2.x + this->x;
//        temp.y = point2.y + this->y;
//        return temp;
//    }
// todo (x = y)
    Point operator=(Point pointTwo){
        this->x = pointTwo.x;
        this->y = pointTwo.y;
        return *this;
    }
    friend Point operator+(Point pointOne, Point pointTwo);
//    friend Point operator=(Point pointOne , Point PointTwo);
    // todo ++a
    Point operator++(){
        this->x++;
        this->y++;
        return *this;
    }
    // todo a++
    Point operator++(int){
        Point temp = *this;
        temp.x++;
        temp.y++;
        return temp;
    }
    // todo a == b
    bool operator==(Point pointTwo){
        return this->x == pointTwo.x && this->y == pointTwo.y;
    }

    friend ostream &operator << (ostream &out , const Point &point);
    friend istream &operator >> (istream &in , Point &point);

    void print(){
        cout<< "(" << this->x <<" , " << this->y << ")";
    }
};
// todo (5 , 4) (10 , 8)
Point operator+(Point pointOne , Point pointTwo){
    Point temp;
    temp.x = pointOne.x + pointTwo.x;
    temp.y = pointOne.y + pointTwo.y;
    return temp;
}
// todo cout << a << b << c
ostream & operator << (ostream &out , const Point &point){
    out <<  "(" <<point.x << " , " << point.y << ")";
    return out;
}
istream & operator >> (istream &in , Point &point){
    cout<< "enter the x value:";
    in>> point.x;
    cout<< "enter the y value:";
    in >> point.y;
    return in;
}
//Point operator=(Point pointOne , Point pointTwo){
//
//}
int main() {
    Point pointOne(5 , 4);
    Point pointTwo(10 , 8);
    Point result;
//    result = pointOne + pointTwo;

//    result = pointOne;
//    result.print();
    cin>> result;
    cout<< result;

    cin.get();
    return 0;
}