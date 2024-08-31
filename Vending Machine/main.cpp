#include<bits/stdc++.h>

using namespace std;

class State{
public:
    void pressInsertButton();
    void insertCoin();
    int selectProduct();
    void cancelTransaction();
    int returnChange();
    void getProduct();
};

class Idle : public State{
    void insertCoin(){
        cout<<"Inserted the coin"<<"\n";
    }
};

class hasMoney: public State{
    void insertCoin(){
        cout<<"Put more coins"<<"\n";
    }
    void selectProduct(){
        cout<<"Selected this product"<<"\n";
    }
    void cancelTransaction(){
        cout<<"Canceling the transaction"<<"\n";
        return;
    }
};

class ProductSelect : public State{
    void selectProduct(){
        cout<<"Selecting the products in the machine"<<"\n";
    }
    void cancelTransaction(){
        cout<<"Canceling the transaction"<<"\n";
        return;
    }
    int returnChange(){
        cout<<"Return the change"<<"\n";
        return 100;
    }
};

class Dispense : public State{
public:
    void getProduct(){
        cout<<"Get this Product"<<"\n";
    }
};

class Item{
    public:
    enum class ItemType{Coke, Juice, Soda, Chips};
    int price;
};

class ItemShelf: public Item{
public:
    Item item;
    bool soldOut;
};

class Inventory : public ItemShelf{
public:
    vector<ItemShelf> inventory;
};

class VendingMachine : public State, Inventory{
public:
    State s;
    Inventory invent;
    int coin;

};

int main(){
    cout<<"Hello World!"<<"\n";
    State s=
    VendingMachine v;

    return 0;
}
