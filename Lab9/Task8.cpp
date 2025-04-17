#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    virtual void gettution(string status, int credithours) = 0;
};

class GraduateStudent: public Student{
    int credithours;
    string status;
    int tution;
    string researchtopic;

    public:
    GraduateStudent(string s, int ch, string rt): status(s), credithours(ch), tution(0), researchtopic(rt){}

    string getstatus(){
        return status;
    }
    int getcredithours()
    {
        return credithours;
    }

    void setresearchtopic(string rt)
    {
        researchtopic = rt;
    }
    string getresearchtopic()
    {
        return researchtopic;
    }

    void gettution(string status, int credithours)
    {
        if(status == "Undergraduate")
        {
            tution = credithours*200;
            cout<<"Tution = " <<tution<<endl;
        }
        else if(status == "Graduate")
        {
            tution = credithours*300;
            cout<<"Tution = " <<tution<<endl;
        }
        else if(status == "Doctoral")
        {
            tution = credithours*400;
            cout<<"Tution = " <<tution<<endl;
        }
    }
};

int main()
{
    GraduateStudent g1("Undergraduate", 5, "ai");
    g1.gettution(g1.getstatus(), g1.getcredithours());

    return 0;
}