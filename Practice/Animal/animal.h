#ifndef __ANIMAL_H
#define __ANIMAL_H

class Animal {
public: 
    virtual void make_sound() = 0;
    virtual ~Animal(){};
};

class Dog : public Animal {
public:
    void make_sound();
};

class Cat : public Animal {
public:
    void make_sound();
};

class Cow : public Animal {
public:
    void make_sound();
};

#endif