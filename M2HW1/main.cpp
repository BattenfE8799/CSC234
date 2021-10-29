// M2HW1- Adventure Call(second iteration)
// CSC-234-0901
// Elizabeth Battenfield
#include <iostream>

using namespace std;
/*
Goal is to get inside storm shelter before the tornado hits.
version 1.1 log:
2.1 added a function and tornado function works (minimum)
--implemented without global variables
*/

//declare room functions
int frontYard(int hasKey, int counter);
int sideOfHouse(int hasKey, int counter);
int backYard(int hasKey, int counter);
int stormShelter(int hasKey, int counter);
int shed(int hasKey, int counter);
//declares function to check tornado
int tornado(int counter);


int main()
{
    char again;
    bool firstPlay = true; // first playthrough?
    int hasKey = 0; // have key?
    int counter = 0; //counts the amount of times asked about tornado

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
        backYard(hasKey,counter);
        firstPlay = false;
        //loops back around to play again
        main();
    }
    else { //if they don't want to play/play again.
        cout << "Goodbye!" << endl;
    }

    return 0;
}

int frontYard(int hasKey, int counter)
{/* front yard- leads to side of house */
    counter += 1;
    if (counter >= 10){
        tornado(counter);
    }
    cout << "You are in the front yard." << endl;
    cout << "The front door is locked." << endl;
    cout << "The path goes to the side of the house, to the EAST." << endl;
    cout << "On the ground is the key you dropped." << endl;
    cout << "You need to hurry, the TORNADO is coming!" << endl;
    string command;
    cin >> command;
    if (command == "east"){
        sideOfHouse(hasKey, counter);
    }
    //else if (command == "tornado"){
    //    tornado(counter);
    //}
    else if (command == "key"){
        if (hasKey == 0){
            cout << "You pick up the key. You need to get to safety." << endl;
            frontYard(hasKey, counter);
        }
        else{
            cout << "You have the key. Get to safety." << endl;
            frontYard(hasKey, counter);}
}
}
int sideOfHouse(int hasKey, int counter)
{
    /* side of house- leads to front yard and back yard */
    counter += 1;
    if (counter >= 10)
    {
        tornado(counter);
    }
    cout << "You are at the side of the house." << endl;
    cout << "There is a path surrounded by rocks." << endl;
    cout << "The front yard is to the WEST." << endl;
    cout << "The back yard is to the EAST." << endl;
    string command;
    cin >> command;
    if (command == "east")
    {
        backYard(hasKey, counter);
    }
    else if (command == "west")
    {
        frontYard(hasKey, counter);
    }
    else if (command == "rock")
    {
        cout << "Mom's gonna be so mad if you mess up her rock patterns." << endl;
        sideOfHouse(hasKey, counter);
    }
    else if (command == "key")
    {
        if (hasKey == 0)
            {
            cout << "You don't see the key. You must have dropped it somewhere." << endl;
            sideOfHouse(hasKey, counter);
            }
        else{
            cout << "You have the key. Get to safety." << endl;
            sideOfHouse(hasKey, counter);
            }
    }
    //else if (command == "tornado"){
    //    tornado(counter);
    //}
}



int backYard(int hasKey,int counter)
{
    /* back yard- goes to the side of the house, the shed, and the storm shelter
    checklist
    -key
    -north
    -south
    tornado
     */
    counter += 1;
    if (counter >= 10)
    {
        tornado(counter);
    }
    cout << "You are in the back yard." << endl;
    cout << "The path goes to the side of the house, to the WEST." << endl;
    cout << "The shed is to the NORTH." << endl;
    cout << "The storm shelter is to the SOUTH." << endl;
    cout << "The back door is locked." << endl;
    string command;
    cin >> command;
    if (command == "west")
    {
        sideOfHouse(hasKey, counter);
    }
    else if (command == "south")
    {
        stormShelter(hasKey, counter);
    }
    else if (command == "north")
    {
        shed(hasKey, counter);
    }
    else if (command == "key")
    {
        if (hasKey == 0)
        {
            cout << "You don't see the key. You must have dropped it somewhere." << endl;
            backYard(hasKey, counter);
        }
        else{
            cout << "You have the key. Get to safety." << endl;
            backYard(hasKey, counter);
    }}
    //else if (command == "tornado"){
    //    tornado(counter);
    //}
    }


int tornado(int counter)
{ //can't get this to not go to main
    /* tornado- checks the status of the tornado depending on the counter
    if (counter == 1){
        cout << "You cannot see the tornado yet." << endl;
        return counter;
    }
    else if (counter == 2){
        cout << "You can hear the tornado sirens blaring!" << endl;
        return counter;
    }
    else if (counter == 3){
        cout << "Is it night time? The sky has turned black." << endl;
        return counter;
    }
    else if (counter == 4){
        cout << "Is that a train you hear?" << endl;
        return counter;
    }*/
    if (counter >= 5){
        cout << "Its quiet...Too quiet..." << endl;
        cout << "You look up to see the wind tear your house up and fling part of the roof at you." << endl;
        cout << "You lose." << endl;
        main();
    }
}


int stormShelter(int hasKey, int counter)
{
    /* storm shelter- goes to the back yard. get inside to win.  */
    counter += 1;
    if (counter >= 10){
        tornado(counter);
    }
    cout << "You are at the storm shelter." << endl;
    cout << "This will keep you safe from the Tornado" << endl;
    cout << "The back yard is to the NORTH." << endl;
    string command;
    if (hasKey > 0){
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
        backYard(hasKey, counter);
    }
    else if (command == "key"){
        cout << "You don't see the key. You must have dropped it somewhere." << endl;
        stormShelter(hasKey, counter);
    }
    //else if (command == "tornado"){
    //    tornado(counter);
    //}


}
int shed(int hasKey, int counter)
{
    /* storm shelter- goes to the back yard. get inside to win.
    checking
    -key
    -south
     */
    counter += 1;
    if (counter >= 10){
        tornado(counter);
    }
    cout << "You are at the shed." << endl;
    cout << "This has all the tools in it." << endl;
    cout << "The back yard is to the SOUTH." << endl;
    cout << "The TORNADO is coming! You have to get to the shelter." << endl;

    string command;
    cin >> command;
    if (command == "south"){
        backYard(hasKey, counter);
    }
    else if (command == "key"){
        if (hasKey == 0){
            cout << "You don't see the key. You must have dropped it somewhere." << endl;
            shed(hasKey, counter);
        }
        else{
            cout << "You have the key. Get to safety." << endl;
            shed(hasKey, counter);}
    }
    //else if (command == "tornado"){
    //    tornado(counter);
    //}
}

