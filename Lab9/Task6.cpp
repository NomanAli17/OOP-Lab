#include <iostream>
using namespace std;

class Car{
    protected:
    string model;
    int price;

    public:
    Car(string m): model(m){}

    void setmodel(string m)
    {
        model = m;
    }
    string getmodel()
    {
        return model;
    }

    virtual void setprice(int pric) = 0;
    virtual int getprice() = 0;

};

class Color: public Car{
    string color;

    public:
    Color(string m, string c): Car(m), color(c){}

    void setprice(int pric){
        if(color == "black")
        {
            price = pric*2;
        }
        else
        {
            price = pric;
        }
    }

    int getprice()
    {
        return price;
    }
};

class Company: public Car{
    string name;

    public:
    Company(string m, string n): Car(m), name(n){}

    void setprice(int pric){
        if(name == "toyota")
        {
            price = pric*2;
        }
        else
        {
            price = pric;
        }
    }

    int getprice()
    {
        return price;
    }
};

int main()
{
    Color c1("1996", "black");
    c1.setprice(10);
    Company comp("2006", "toyota");
    comp.setprice(20);

    cout<<c1.getmodel()<<" model price = "<<c1.getprice()<<endl;
    cout<<comp.getmodel()<<" model price = "<<comp.getprice()<<endl;
}