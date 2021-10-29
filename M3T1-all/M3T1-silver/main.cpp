#include <iostream>

using namespace std;
/*
M3T1-Silver
CSC 234
M3T1
Elizabeth Battenfield
*/
// Rectangle class declaration
class Rectangle
{
    private:
        double width;
        double length;
    public:
        void setWidth(double);
        void setLength(double);
        double getWidth() const;
        double getLength() const;
        double getArea() const;

};
///setWidth assigns a value to the width member.

void Rectangle::setWidth(double w)
{
    width = w;
}

///setLength assigns a value to the length member.

void Rectangle::setLength(double len)
{
    length = len;
}

///getWidth returns the value in the width member.

double Rectangle::getWidth() const
{
    return width;
}

///getLength returns the value in the length member.

double Rectangle::getLength() const
{
    return length;
}

///getArea returns the product of the width times length.

double Rectangle::getArea() const
{
    return width * length;
}

///function main

int main()
{
    Rectangle box;     // Define an instance of the Rectangle class
    double rectWidth;  // Local variable for width
    double rectLength; // Local variable for length

    //Get the rectangle's width and length from the user
    cout << "This program will calculate the area of a\n";
    cout << "rectangle. What is the width? ";
    cin >> rectWidth;
    while(1)
    {
        if(rectWidth <= 0)
        {
            cin.clear();
            cout << "Invalid input. Cannot place negative numbers or zero." << endl;
            cin >> rectWidth;
        }
        if(rectWidth > 0)
            break;
    }
    cout << "What is the length? ";
    cin >> rectLength;
    while(1)
    {
        if(rectLength <= 0)
        {
            cin.clear();
            cout << "Invalid input. Cannot place negative numbers or zero." << endl;
            cin >> rectLength;
        }
        if(rectLength > 0)
            break;
    }

    // Store the width and length of the rectangle
    // in the box object.
    box.setWidth(rectWidth);
    box.setLength(rectLength);

    //Display the rectangle's data
    cout << "Here is the rectangle's data:\n";
    cout << "Width: " << box.getWidth() << endl;
    cout << "Length: " << box.getLength() << endl;
    cout << "Area: " << box.getArea() << endl;
    return 0;
}
