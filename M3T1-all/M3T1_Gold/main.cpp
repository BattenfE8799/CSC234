#include <iostream>

using namespace std;
/*
M3T1-Gold
CSC 234
M3T1
Elizabeth Battenfield
*/
// box class declaration
class Box
{
    private:
        double width;
        double length;
        double height;
    public:
        void setWidth(double);
        void setLength(double);
        void setHeight(double);
        double getWidth() const;
        double getLength() const;
        double getHeight() const;
        double getVolume() const;


};
///setWidth assigns a value to the width member.

void Box::setWidth(double w)
{
    width = w;
}

///setLength assigns a value to the length member.

void Box::setLength(double len)
{
    length = len;
}

///setHeight assigns a value to the height member.

void Box::setHeight(double h)
{
    height = h;
}



///getWidth returns the value in the width member.

double Box::getWidth() const
{
    return width;
}

///getLength returns the value in the length member.

double Box::getLength() const
{
    return length;
}

///getHeight returns the value in the height member.

double Box::getHeight() const
{
    return height;
}

///getVolume returns the product of the length times width times height.

double Box::getVolume() const
{
    return length * width * height;
}

///function main

int main()
{
    Box box;     // Define an instance of the Box class
    double boxWidth;  // Local variable for width
    double boxLength; // Local variable for length
    double boxHeight; // Local variable for height


    //Get the rectangle's width and length from the user
    cout << "This program will calculate the area of a\n";
    cout << "box. What is the width? ";
    cin >> boxWidth;
    while(1)
    {
        if(boxWidth <= 0)
        {
            cin.clear();
            cout << "Invalid input. Cannot place negative numbers or zero." << endl;
            cin >> boxWidth;
        }
        if(boxWidth > 0)
            break;
    }
    cout << "What is the length? ";
    cin >> boxLength;
    while(1)
    {
        if(boxLength <= 0)
        {
            cin.clear();
            cout << "Invalid input. Cannot place negative numbers or zero." << endl;
            cin >> boxLength;
        }
        if(boxLength > 0)
            break;
    }
    cout << "What is the height? ";
    cin >> boxHeight;
    while(1)
    {
        if(boxHeight <= 0)
        {
            cin.clear();
            cout << "Invalid input. Cannot place negative numbers or zero." << endl;
            cin >> boxHeight;
        }
        if(boxHeight > 0)
            break;
    }
    // Store the width and length of the rectangle
    // in the box object.
    box.setWidth(boxWidth);
    box.setLength(boxLength);
    box.setHeight(boxHeight);

    //Display the rectangle's data
    cout << "Here is the rectangle's data:\n";
    cout << "Width: " << box.getWidth() << endl;
    cout << "Length: " << box.getLength() << endl;
    cout << "Height: " << box.getHeight() << endl;
    cout << "Volume: " << box.getVolume() << endl;
    return 0;
}

