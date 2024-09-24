#include "animal.cpp"
#include <vector>

int main(){
    Animal* animals[3]{
        new Dog(),
        new Cat(),
        new Cow(),
    };

for(int i = 0; i < 3; ++i){
    animals[i]->make_sound();
}

for(int i = 0; i < 3; ++i){
    delete animals[i];
}

}
