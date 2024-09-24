#include <bits/stdc++.h>

using namespace std;
class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    int radius;
    Circle(int r){
        radius= r;
    }
    virtual void draw() {
        cout << "Drawing a circle of radius " << radius << "\n";
    }
};

class Square : public Shape {
public:
    int side;
    Square(int s){
        side =s;
    }
    virtual void draw() {
        cout << "Drawing a square of side " << side << "\n";
    }
};
class NullObject: public Shape{
public:
    virtual void draw(){
        cout<<"Invalid shape to draw, go grab something and we will draw"<<"\n";
    }
};

class ShapeFactory {
public:
    Shape* getShape(char ch) {
        switch (ch) {
            case 'C': {
                int r;
                cout << "Input the Radius: ";
                cin >> r;
                return new Circle(r);
            }
            case 'S': {
                int s;
                cout << "Input the side of Square: ";
                cin >> s;
                return new Square(s);
            }
            default:
                return new NullObject();
        }
    }
};



int main() {
    ShapeFactory *shapeFactory = new ShapeFactory();
    char ch;
    cout<<"Enter C for drawing a Circle and S for drawing a square: ";
    cin>>ch;
    Shape *s = shapeFactory->getShape(ch);
    s->draw();

    return 0;
}
