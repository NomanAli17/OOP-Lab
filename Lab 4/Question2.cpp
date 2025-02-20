#include <iostream>
#include <cmath>
using namespace std;
class Polynomial{
    double *coefficients;
    int degree;
public:
    Polynomial(){
        this->degree=0;
        coefficients=new double[1]{0};
    }
    Polynomial(int degree,double coefficients[]){
        this->degree=degree;
        this->coefficients=new double[degree+1];
        for(int i=0;i<=degree;i++){
            this->coefficients[i]=coefficients[i];
        }
    }
    Polynomial(const Polynomial &other){
        this->degree=other.degree;
        coefficients=new double[degree+1];
        for(int i=0;i<=degree;i++) coefficients[i]=other.coefficients[i];
    }
    Polynomial(Polynomial &&other){
        this->degree=other.degree;
        this->coefficients=other.coefficients;
        other.coefficients=nullptr;
        other.degree=0;
    }
    int getDegree() const{
        return degree;
    }
    double evaluate(double x) const{
        double result=0;
        for(int i=0;i<=degree;i++){
            result+=coefficients[i]*pow(x,i);
        }
        return result;
    }
    Polynomial add(const Polynomial& other) const{
        int maxDegree=max(this->degree,other.degree);
        double *newCoefficients=new double[maxDegree+1]{0};
        for(int i=0;i<=this->degree;i++) newCoefficients[i]+=this->coefficients[i];
        for(int i=0;i<=other.degree;i++) newCoefficients[i]+=other.coefficients[i];
        Polynomial sum(maxDegree,newCoefficients);
        delete[] newCoefficients;
        return sum;
    }
    Polynomial multiply(const Polynomial& other) const{
        int newDegree=this->degree+other.degree;
        double *newCoefficients=new double[newDegree+1]{0};
        for(int i=0;i<=this->degree;i++){
            for(int j=0;j<=other.degree;j++){
                newCoefficients[i+j]+=this->coefficients[i]*other.coefficients[j];
            }
        }
        Polynomial product(newDegree,newCoefficients);
        delete[] newCoefficients;
        return product;
    }
    ~Polynomial(){
        delete[] coefficients;
    }
};
int main(){
    double coeffs[]={1.0,2.0,3.0};
    Polynomial p1;
    Polynomial p2(2,coeffs);
    Polynomial p3=p2;
    Polynomial p4=move(p2);
    cout<<"Degree of p4: "<<p4.getDegree()<<endl;
    cout<<"Evaluation of p4 at x=2: "<<p4.evaluate(2)<<endl;
    return 0;
}
