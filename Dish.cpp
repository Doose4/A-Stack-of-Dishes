#include <string>
#include "Dish.hpp"

using namespace std;

Dish::Dish(string description) {
    this->description = description;
}

string Dish::get_description() {
    return this->description;
}