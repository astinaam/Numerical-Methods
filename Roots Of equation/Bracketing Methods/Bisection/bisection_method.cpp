#include<bits/stdc++.h>

using namespace std;

double Function(double x)
{
    //here i am using f(x)=4x^3-6x^2+7x-2.3
    //return 4*pow(x,3) - 6*pow(x,2) + 7*x - 2.3;
    return pow(x,2) - 3.0;
}

int iteration;

double bisection(double a,double b)
{
    double x = (a+b)/2.0;
    cout<<"Iteration "<<setw(4)<<iteration++<<" : X = "<<setw(4)<<x<<endl;
    return x;
}

int main()
{
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Bisection Method>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    double a,b,Es,x=0;
    int max_itr;
    cout<<"Enter Initial guesses (xi<xu) : ";
    cin>>a>>b;
    //cerr<<a<<" "<<b<<endl;
    cout<<"Maximum iterations (default=100, to set default enter 0) : ";
    cin>>max_itr;
    if(max_itr==0) max_itr=100;
    cout<<"Allowed error in % (Es) : ";
    cin>>Es;
    cout<<"------------------------------------------------------------------------------"<<endl;
    iteration = 1;
    do
    {
        double newx = bisection(a,b);
        //cerr<<Function(x)<<" "<<Function(a)<<endl;
        double f = Function(newx)*Function(b);
        //cerr<<f<<endl;
        if(f < 0.0)
        {
            a = newx;
        }
        else
        {
            b = newx;
        }
        //cerr<<"a = "<<a<<" b = "<<b<<endl;
        double err = abs(newx - x)/newx;
        err *= 100.0;
        x = newx;
        cerr<<"Estimated Error after iteration "<<iteration-1<<" : "<<setw(4)<<err<<" %"<<endl;
        if(err <= Es)
        {
            cout<<"------------------------------------------------------------------------------"<<endl;
            cout<<"Root = "<<setw(4)<<newx<<" after "<<iteration<<" iterations."<<endl;
            return 0;
        }
    }
    while(iteration <= max_itr);
    cout<<"Not converge or increase iterations"<<endl;
}

