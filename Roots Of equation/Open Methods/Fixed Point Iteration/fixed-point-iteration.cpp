#include<bits/stdc++.h>

using namespace std;

double Function(double x)
{
    //format , x = f(x)
    return exp(-x);
}

int iteration;

int main()
{
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<Fixed-point iteration  Method>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    double a,b,Es,x=0,newx;
    int max_itr;
    cout<<"Enter Initial guess : ";
    cin>>x;
    cout<<"Maximum iterations (default=100, to set default enter 0) : ";
    cin>>max_itr;
    if(max_itr==0) max_itr=100;
    cout<<"Allowed error in % (Es) : ";
    cin>>Es;
    cout<<"------------------------------------------------------------------------------"<<endl;
    iteration = 1;
    do
    {
        newx = Function(x);
        cout<<"Iteration "<<setw(4)<<iteration++<<" : X = "<<setw(4)<<x<<endl;
        double err = abs(newx - x)/abs(newx);
        err *= 100.0;
        x = newx;
        cerr<<"Estimated error after iteration "<<iteration-1<<" : "<<setw(4)<<err<<" %"<<endl;
        //cerr<<Es<<" "<<err<<endl;
        if(abs(Es-err) <= 1e-6)
        {
            cout<<"------------------------------------------------------------------------------"<<endl;
            cout<<"Root = "<<setw(4)<<newx<<" after "<<iteration-1<<" iterations."<<endl;
            main();
        }
    }
    while(iteration <= max_itr);
    cout<<"Root = "<<setw(4)<<x<<" after "<<iteration-1<<" iterations."<<endl;
    main();
}

