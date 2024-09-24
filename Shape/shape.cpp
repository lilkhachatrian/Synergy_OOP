#include <iostream>

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw(){
        std::cout << "Drawing a circle.\n";
    }

};

class Rectangle : public Shape {
public:
    void draw(){
        std::cout << "Drawing a rectangle.\n";
    }
};

class Triangle : public Shape {
public:
    void draw(){
        std::cout << "Drawing a triangle." << std::endl;
    }
};

int main(){
    Shape* shapes[3] = {
        new Circle(),
        new Rectangle(),
        new Triangle(),
    };

    for(int i = 0; i < 3; ++i){
        shapes[i]->draw();
    }

    for(int i = 0; i < 3; ++i){
        delete shapes[i];
    }
    return 0;
}