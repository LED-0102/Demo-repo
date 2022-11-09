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
float lssthan360(float n){
    int i = n/360;
    n = n - i*360;
    return n;
}
float sin(float n){
    float s = 0;
    float j = lssthan360(n);
    if (j>=0 && j<=90){
        float rad = j*(3.142)/180;
        for (int k=1; k<=10; k++){
            s = s + pow(-1, k+1)*(pow(rad, 2*k-1)/fact(2*k-1));
        }
    }
    if (j>90 && j<=180){
        float l = 180 - j;
        float rad = l*(3.142)/180;
        for (int k=1; k<=10; k++){
            s = s + pow(-1, k+1)*(pow(rad, 2*k-1)/fact(2*k-1));
        }
    }
    if (j>180 && j<=270){
        float l = j - 180;
        float t= 0;
        float rad = l*(3.142)/180;
        for (int k=1; k<=10; k++){
            t = t + pow(-1, k+1)*(pow(rad, 2*k-1)/fact(2*k-1));
        s = (-1)*t;
        }
    }
    if (j>270 && j<360){
        float l = 360 - j;
        float t= 0;
        float rad = l*(3.142)/180;
        for (int k=1; k<=10; k++){
            t = t + pow(-1, k+1)*(pow(rad, 2*k-1)/fact(2*k-1));
        s = (-1)*t;
        }
    }
    return s;
}
float cos(float n){
    float s=1;
    float j = lssthan360(n);
    if (j>=0 && j<=90){
        float rad = j*(3.142)/180;
        for (int k=2; k<=10; k++){
            s = s + pow(-1, k+1)*(pow(rad, 2*k-2)/fact(2*k-2));
        }
    }
    if (j>90 && j<=180){
        float l = 180 - j;
        float t = 1;
        float rad = l*(3.142)/180;
        for (int k=2; k<=10; k++){
            t = t + pow(-1, k+1)*(pow(rad, 2*k-2)/fact(2*k-2));
        }
        s = (-1)*t;
    }
    if (j>180 && j<=270){
        float l = j - 180;
        float t = 1;
        float rad = l*(3.142)/180;
        for (int k=2; k<=10; k++){
            t = t + pow(-1, k+1)*(pow(rad, 2*k-2)/fact(2*k-2));
        }
        s = (-1)*t;
    }
    if (j>270 && j<360){
        float l = 360 - j;
        float rad = l*(3.142)/180;
        for (int k=2; k<=10; k++){
            s = s + pow(-1, k+1)*(pow(rad, 2*k-2)/fact(2*k-2));
        }
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
    float dup = n;
    if (n<0){
        n = (-1)*n;
    }
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
    if (dup<n){
        nem = (-1)*nem;
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
                    cout<<"Enter the angle in degrees: ";
                    cin>>a;
                    cout<<roundof(sin(a), 3)<<endl;
                    goto label;
                case 2:
                    cout<<"Enter the angle in degrees: ";
                    cin>>a;
                    cout<<roundof(cos(a), 3)<<endl;
                    goto label;
                case 3:
                    cout<<"Enter the angle in degrees: ";
                    cin>>a;
                    cout<<roundof(tan(a), 3)<<endl;
                    goto label;
                case 4:
                    cout<<"Enter the angle in degrees: ";
                    cin>>a;
                    cout<<roundof(1/sin(a),5)<<endl;
                    goto label;
                case 5:
                    cout<<"Enter the angle in degrees: ";
                    cin>>a;
                    cout<<roundof(1/cos(a),5)<<endl;
                    goto label;
                case 6:
                    cout<<"Enter the angle in degrees: ";
                    cin>>a;
                    cout<<roundof(1/tan(a), 5)<<endl;
                    goto label;
            }
         
    }
    return 0;
}
