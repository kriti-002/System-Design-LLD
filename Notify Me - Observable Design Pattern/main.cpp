#include<bits/stdc++.h>

using namespace std;

//notify me implementation in a e-commerce store
class StockObservable{
    public:
    virtual void add(int x) =0;
    virtual int remove(int x) =0;
    virtual void notify() =0;
    virtual int getStock()=0;
    virtual void setStock(int s)=0;
};
class StockObserver{
    public:
    void update();

};
class IPhoneObservable : public StockObservable{
private:
    int stock=100;
public:
    int getStock(){
        return stock;
    }
    void setStock(int s){
        stock=s;
    }
    void add(int x){
        stock+=x;
    }
    int remove(int x){
        stock-=x;
        return stock;
    }
    void notify(){
        cout<<"IPhone Stock present: "<<stock<<"\n";
    }

};
class EarplugsObservable: public StockObservable{
private:
    int stock=0;
public:
    int getStock(){return stock;}
    void setStock(int s){
        stock=s;
    }
    void add(int x){
        stock+=x;
    }
    int remove(int x){
        stock-=x;
        return stock;
    }
    void notify(){
        cout<<"Earplugs Stock present: "<<stock<<"\n";
    }

};
class EmailAlert : public StockObserver{
public:
    string email;
    StockObservable *so;
    EmailAlert(string e, StockObservable *ss){
        email=e;
        so=ss;
    }
    void update(){
        if(so->getStock() >0){
            so->notify();
            //cout<<"Have stock"<<"\n";
        }else cout<<"Out of Stock"<<"\n";
    }

};
class MobileAlert: public StockObserver{
public:
    string mobileNumber;
    StockObservable *so;
    MobileAlert(string mobile, StockObservable *ss){
        if(mobile.length() == 10 ) mobileNumber= mobile;
        so= ss;
    }
    void update(){
        if(so->getStock() >0){
            so->notify();
            //cout<<"Stock present"<<"\n";
        }else cout<<"Out of Stock"<<"\n";
    }
};
int main(){
    StockObservable *so= new IPhoneObservable();
    StockObservable *sp= new EarplugsObservable();
    EmailAlert *e= new EmailAlert("xyz@test.com", so);
    e->update();

    MobileAlert *m= new MobileAlert("1234567890", sp);
    m->update();

    return 0;
}
