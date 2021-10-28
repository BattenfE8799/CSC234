// M2Lab2- Adventure Call(first iteration)
// CSC-234-0901
// Elizabeth Battenfield
#include <iostream>

using namespace std;
/*
Goal is to get inside storm shelter before the tornado hits.
version 1.1 log:
1.1 added rooms
*/

//declare room functions
void frontYard();
void sideOfHouse();
void backYard();
void stormShelter();
//declares function to check tornado
int tornado();
//declare function to end game
void goodBye();

//declared global variables
bool firstPlay = true; // first playthrough?
bool hasKey = false; // have key?
int counter = 0; //counts the amount of times asked about tornado

int main()
{
    char again;
    cout << "Oh No! Theres a Tornado Coming Right Towards Your House!" << endl; //introduction to game
    if (firstPlay){ //for looping if to play again,
        cout << "Are you ready to get to safety(y/n)? ";
    }
    else {
        cout << "Another is headed your way! Would you like to run again(y/n)? ";
    }
    cin >> again; //users choice?
    //loop with choice to play or quit
    if (again == 'y' || again == 'Y') {
        //starts in back yard
        backYard();
        firstPlay = false;
        //loops back around to play again
        main();
    }
    else { //if they don't want to play/play again.
        cout << "Goodbye!" << endl;
    }

    return 0;
}

void frontYard()
{/* front yard- leads to side of house */
    cout << "You are in the front yard." << endl;
    cout << "The front door is locked." << endl;
    cout << "The path goes to the side of the house, to the EAST." << endl;
    cout << "On the ground is the key you dropped." << endl;
    cout << "You need to hurry, the TORNADO is coming!" << endl;
    string command;
    cin >> command;
    if (command == "east"){
        sideOfHouse();
    }
    else if (command == "key"){
        hasKey = true;
        frontYard();
    }
    //else if (command == "tornado"){
    //    tornado();
    //}
}

void sideOfHouse()
{/* side of house- leads to front yard and back yard */
    cout << "You are at the side of the house." << endl;
    cout << "There is a path surrounded by rocks." << endl;
    cout << "The front yard is to the WEST." << endl;
    cout << "The back yard is to the EAST." << endl;
    string command;
    cin >> command;
    if (command == "east"){
        backYard();
    }
    else if (command == "west"){
        frontYard();
    }
    else if (command == "rock"){
        cout << "Mom's gonna be so mad if you mess up her rock patterns." << endl;
        sideOfHouse();
    }
    //else if (command == "tornado"){
    //    tornado();
    //}
}

void backYard()
{
    /* back yard- goes to the side of the house, the shed, and the storm shelter  */
    cout << "You are in the back yard." << endl;
    cout << "The path goes to the side of the house, to the WEST." << endl;
    cout << "The storm shelter is to the SOUTH." << endl;
    cout << "The back door is locked." << endl;
    string command;
    cin >> command;
    if (command == "west"){
        sideOfHouse();
    }
    else if (command == "south"){
        stormShelter();
    }
    //else if (command == "tornado"){
    //    tornado();
    //}
}

/* To fix later
int tornado()
{
    /* tornado- checks the status of the tornado depending on the counter

    counter += 1; //adds to the counter each time they check

    if (counter == 1){
        cout << "You cannot see the tornado yet." << endl;
        return 0;
    }
    else if (counter == 2){
        cout << "You can hear the tornado sirens blaring!" << endl;
        return 0;
    }
    else if (counter == 3){
        cout << "Is it night time? The sky has turned black." << endl;
        return 0;
    }
    else if (counter == 4){
        cout << "Is that a train you hear?" << endl;
        return 0;
    }
    else if (counter == 5){
        cout << "Its quiet...Too quiet..." << endl;
        cout << "You look up to see the wind tear your house up and fling part of the roof at you." << endl;
        main();
    }
}
*/

void stormShelter()
{
    /* storm shelter- goes to the back yard. get inside to win.  */
    cout << "You are at the storm shelter." << endl;
    cout << "This will keep you safe from the Tornado" << endl;
    cout << "The back yard is to the NORTH." << endl;
    string command;
    if (hasKey){
        cout << "You unlock the lid and climb down the ladder, shutting the lid behind you." << endl;
        cout << "You are safe!" << endl;
        cout << "The tornado passed overhead, taking out your house and the shed." << endl;
        cout << "You won!" << endl;
        main();
    }
    else{
        cout << "The lid is locked, you grab for the key." << endl;
        cout << "You must have dropped it!" << endl;
    }
    cin >> command;
    if (command == "north"){
        backYard();
    }
    else if (command == "key"){
        cout << "You don't see the key. You must have dropped it somewhere." << endl;
        stormShelter();
    }
  //  else if (command == "tornado"){
   //     tornado();}


}
