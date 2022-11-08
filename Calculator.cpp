#include<iostream>
extern const float pi = 3.142;
using namespace std;


float pow(float a, float b){
    float d = a;
    for (int k=1; k<b; k++){
        d = d*a;
    }
    return d;
}
int fact(int n){
    int i=1;
    for (int k=1; k<=n; k++){
        i = i*k;
    }
    return i;
}
float sin(float n){
    
    float s=0;
    for (int k=1; k<=10; k++){
        s = s + pow(-1, k+1)*(pow(n, 2*k-1)/fact(2*k-1));
    }
    return s;
}
float cos(float n){
    float s=1;
    for (int k=2; k<=10; k++){
        s = s + pow(-1, k+1)*(pow(n, 2*k-2)/fact(2*k-2));
    }
    return s;
}
float truncate(float n, int z){
    int y = pow(10,z);
    int s = n*(pow(10, z));
    int m = s/(pow(10, z));
    int d = s%y;
    float de = d/(pow(10, z));
    return m+de;
}
float roundof(float n, int z){
    float nem;
    float num = n*(pow(10, z));
    int e = num*10;
    if(e%10 == 5 && (e/10)%2==0){
        int d = (int)num;
        nem = (float)d/(pow(10, z));
    }
    else {
        num = num+0.5;
        int d = (int)num;
        nem = (float)d/(pow(10, z));
    }
    return nem;
}
float tan(float n){
    float t = sin(n)/cos(n);
    return t;
}

int main()
{
    float a, b;
    int n, na;
    label:
    cout<<"Press 1 for addition\nPress 2 for subtraction\nPress 3 for multiplication\nPress 4 for division\nPress 5 for exponential\nPress 6 for trigonometric functions\nPress 7 to exit\n";
    cin>>n;
    switch (n){
        case 1:
            cout<<"Enter two numbers: "<<endl;
            cin>>a>>b;
            cout<<a+b<<endl;
            goto label;
        case 2:
            cout<<"Enter first number: ";
            cin>>a;
            cout<<"Enter second number: ";
            cin>>b;
            cout<<a-b<<endl;
            goto label;
        case 3:
            cout<<"Enter two numbers: "<<endl;
            cin>>a>>b;
            cout<<a*b<<endl;
            goto label;
        case 4:
            cout<<"Enter numerator: ";
            cin>>a;
            cout<<"Enter denominator: ";
            cin>>b;
            cout<<a/b<<endl;
            goto label;
        case 5:
            cout<<"Enter the base: ";
            cin>>a;
            cout<<"Enter the exponent: ";
            cin>>b;
            cout<<pow(a, b)<<endl;
            goto label;
        case 6:
            cout<<"Press 1 for sine\nPress 2 for cosine\nPress 3 for tangent\nPress 4 for cosecant\nPress 5 for secant\nPress 6 for cotangent\n";
            cin>>na;
            switch (na){
                case 1:
                    lab1:
                    cout<<"Enter the angle in radian: ";
                    cin>>a;
                    if (a>=0 && a<=pi/2){
                    cout<<roundof(sin(a), 5)<<endl;
                    goto label;
                    }
                    else{
                        cout<<"Please enter angle between 0 and pi\n";
                        goto lab1;
                    }
                case 2:
                    lab2:
                    cout<<"Enter the angle in radian: ";
                    cin>>a;
                    if (a>0 && a<=pi/2){
                    cout<<roundof(cos(a), 5)<<endl;
                    goto label;
                    }
                    else{
                        cout<<"Please enter angle between 0 and pi\n";
                        goto lab2;
                    }
                case 3:
                    lab3:
                    cout<<"Enter the angle in radian: ";
                    cin>>a;
                    if (a>0 && a<=pi/2){
                    cout<<roundof(tan(a), 5)<<endl;
                    goto label;
                    }
                    else{
                        cout<<"Please enter angle between 0 and pi\n";
                        goto lab3;
                    }
                case 4:
                    lab4:
                    cout<<"Enter the angle in radian: ";
                    cin>>a;
                    if (a>0 && a<=pi/2){
                    cout<<roundof(1/sin(a),5)<<endl;
                    goto label;
                    }
                    else{
                        cout<<"Please enter angle between 0 and pi\n";
                        goto lab4;
                    }
                case 5:
                    lab5:
                    cout<<"Enter the angle in radian: ";
                    cin>>a;
                    if (a>0 && a<=pi/2){
                    cout<<roundof(1/cos(a),5)<<endl;
                    goto label;
                    }
                    else{
                        cout<<"Please enter angle between 0 and pi\n";
                        goto lab5;
                    }
                case 6:
                    lab6:
                    cout<<"Enter the angle in radian: ";
                    cin>>a;
                    if (a>0 && a<=pi/2){
                    cout<<roundof(1/tan(a), 5)<<endl;
                    goto label;
                    }
                    else{
                        cout<<"Please enter angle between 0 and pi\n";
                        goto lab6;
                    }
            }
         
    }
    return 0;
}
