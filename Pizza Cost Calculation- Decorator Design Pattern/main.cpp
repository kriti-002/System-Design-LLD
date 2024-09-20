#include<bits/stdc++.h>

using namespace std;

class Pizza{
    public:
    virtual int cost()=0;
};
class VegDelight: public Pizza{
public:
    virtual int cost(){
        return 350;
    }
};
class CheeseCorn: public Pizza{
public:
    virtual int cost(){
        return 100;
    }
};
class Toppings: public Pizza{
};
class ExtraCheese: public Toppings{
public:
    Pizza *p;
    ExtraCheese(Pizza *pizza){
        p= pizza;
    }
    virtual int cost(){
        return 50 + p->cost();
    }
};
class Mushroom: public Toppings{
public:
    Pizza *p;
    Mushroom(Pizza *pizza){
        p= pizza;
    }
    virtual int cost(){
        return 80 + p->cost();
    }
};

class Sauce: public Toppings{
public:
    Pizza *p;
    Sauce(Pizza *pizza){
        p= pizza;
    }
    virtual int cost(){
        return 5 + p->cost();
    }
};


int main(){
    //cout<<"Hello World!"<<"\n";
    Pizza *p= new VegDelight();
    cout<<"Cost of Veg Delight Pizza: "<<p->cost()<<"\n";
    Pizza *newPizza= new Sauce(p);
    cout<<"Cost of Veg Delight Pizza with Sauce Packets: "<<newPizza->cost()<<"\n";
    Pizza *newPizza1= new Mushroom(p);
    cout<<"Cost of Veg Delight Pizza with Mushroom toppings: "<<newPizza1->cost()<<"\n";
    Pizza *newPizza2= new ExtraCheese(p);
    cout<<"Cost of Veg Delight Pizza with Extra Cheese: "<<newPizza2->cost()<<"\n";

    Pizza *p2= new CheeseCorn();
    cout<<"Cost of Cheese and Corn Pizza: "<<p2->cost()<<"\n";
    Pizza *newCCPizza= new Sauce(p2);
    cout<<"Cost of Chesse and Corn Pizza with Sauce Packets: "<<newCCPizza->cost()<<"\n";
    Pizza *newCCPizza2= new Mushroom(p2);
    cout<<"Cost of Cheese and Corn Pizza with Mushroom toppings: "<<newCCPizza2->cost()<<"\n";
    Pizza *newCCPizza3= new ExtraCheese(p2);
    cout<<"Cost of Cheese and Corn Pizza with Extra Cheese: "<<newCCPizza3->cost()<<"\n";
    return 0;
}
