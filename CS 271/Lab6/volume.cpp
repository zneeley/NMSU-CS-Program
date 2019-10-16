#include <iostream>

using namespace std;

int main() {
    int width, height, length, volume;
    
    cout << "Ender the width of the box: ";
    cin >> width;
    
    cout << "Enter the height of the box: ";
    cin >> height;
    
    cout << "Ender the length of the box: ";
    cin >> length;
    
    volume = width * height * length;
    
    cout << endl << endl << "The volume of a box with length " << length
         << ", width " << width << " and height " << height << " is: "
         << volume << "." << endl; 
         
} // end main
