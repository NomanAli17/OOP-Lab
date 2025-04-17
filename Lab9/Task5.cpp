#include <iostream>
using namespace std;

class Shape{
    public:
    virtual void getarea() = 0;
};

class Rectangle: public Shape{
    int length;
    int width;

    public:
    Rectangle(int l , int w): length(l), width(w){}

    void getarea()
    {
        cout<<"Area = "<<length*width<<endl;
    }
};

class Triangle: public Shape{
    int base, height;

    public:
    Triangle(int b, int h): base(b), height(h){}

    void getarea(){
        cout<<"Area = "<<0.5*base*height<<endl;
    }
};

int main()
{
    Rectangle r1(2, 5);
    r1.getarea();
    Triangle t1(2, 4);
    t1.getarea();

    return 0;
}