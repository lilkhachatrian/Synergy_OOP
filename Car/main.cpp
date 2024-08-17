#include <iostream>
#include "car.cpp"

int main(){
    Car car_sample("BMW", "X5", 2019, 4);
    Car car_second = car_sample;
    car_sample.drive(5);
    car_sample.displayInfo();
    car_second.displayInfo();

}