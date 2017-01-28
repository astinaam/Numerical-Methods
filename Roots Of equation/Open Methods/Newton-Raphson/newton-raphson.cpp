#include<bits/stdc++.h>

using namespace std;

double Function(double x)
{
    return exp(-x)-x;
    //return 4*pow(x,3)-6*pow(x,2)+7*x-2.3;     //f(x)=4x^3-6x^2+7x-2.3
    //return pow(x,2) - 3.0;                    //f(x)=x^2-3;
    //return 3*x+sin(x)-exp(x);                 //f(x)=3x+sin(x)-e^x;
    //return cos(x)-x*exp(x);                   //f(x)=cos(x)-x*e^x;
    //return x-exp(-x);                         //f(x)=x-e^-x;
    //return exp(-x)*(pow(x,2)+5*x+2)+1;        //f(x)=exp(-x) * (x2+5x+2) + 1;
    //return x-sin(x)-.5;                       //f(x)=x - sin(x) - (1/2);
    //return exp(-x)-3*log(x);                  //f(x)=exp(-x)=3log(x);
    //return cos(x);
}

double derivative(double x)
{
    return -exp(-x)-1;
}

int iteration;

double newton_raphson(double a)
{
    double x = a - (Function(a)/derivative(a));
    cout<<"Iteration "<<setw(23)<<iteration++<<" : X = "<<setw(4)<<x<<endl;
    return x;
}

int main()
{
    cout<<fixed<<setprecision(10);
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<Newton-Raphson Method>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    double a,b,Es,x=0;
    int max_itr;
    cout<<"Enter Initial guess (X0) : ";
    cin>>x;
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
        double newx = newton_raphson(x);
        double err = abs(newx - x)/abs(newx);
        err *= 100.0;
        x = newx;
        cerr<<"Estimated error after iteration "<<iteration-1<<" : "<<setw(20)<<setprecision(20)<<err<<" %"<<endl;
        //cerr<<Es<<" "<<err<<endl;
        if(abs(Es-err) <= 1e-6)
        {
            cout<<"------------------------------------------------------------------------------"<<endl;
            cout<<"Root = "<<setw(8)<<newx<<" after "<<iteration-1<<" iterations."<<endl;
            main();
        }
    }
    while(iteration <= max_itr);
    cout<<"Root = "<<setw(4)<<x<<" after "<<iteration-1<<" iterations."<<endl;
    main();
}


