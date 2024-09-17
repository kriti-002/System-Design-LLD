#include<bits/stdc++.h>

using namespace std;

class Drive{
public:
    virtual void drive();
};
class BaseModel : public Drive{
    public:
    virtual void drive(){
        cout<<"Base Model Drive Method"<<"\n";
    }
};
class SedanModel : public Drive{
public:
    virtual void drive(){
        cout<<"Sedan Model Drive Method"<<"\n";
    }
};

class Vehicle{
    public:
    Drive *d;
    void setDrive(Drive *drive){
    this->d= drive;
    }
    void drive(){
        d->drive();
    }
};

int main(){
    SedanModel s;
    BaseModel b;
    Vehicle v1;
    v1.setDrive(&b);
    v1.drive();

    Vehicle v2;
    v2.setDrive(&s);
    v2.drive();
    return 0;
}
