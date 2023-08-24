//HM_ex_1_24.03.2023_
#include <iostream>
using namespace std;
struct WashingMachine 
{
    string manufacturer;
    string color;
    double width;
    double height;
    int power;
    int spin_speed;
};
void print_washer(WashingMachine washer) 
{
    cout << "Manufacturer: " << washer.manufacturer << endl;
    cout << "Color: " << washer.color << endl;
    cout << "Width: " << washer.width << " cm" << endl;
    cout << "Height: " << washer.height << " cm" << endl;
    cout << "Power: " << washer.power << " W" << endl;
    cout << "Spin speed: " << washer.spin_speed << " rpm" << endl;
}
int main() 
{
    WashingMachine my_washer;
    my_washer.manufacturer = "Samsung";
    my_washer.color = "Black";
    my_washer.width = 67.0;
    my_washer.height = 89.0;
    my_washer.power = 2400;
    my_washer.spin_speed = 2000;

    cout << "My washing machine: " << endl;
    print_washer(my_washer);

    return 0;
}