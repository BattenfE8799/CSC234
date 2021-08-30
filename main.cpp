// CSC 234
// M1HW - Rock Paper Scissors
// Elizabeth Battenfield
// 8/30/2021

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//declare functions
int getUserChoice(); //gets player's choice
int getGameChoice(); //gets computer's choice
 string whoWins(int userChoice, int gameChoice); //gets winner

int main()
{
    // Single round of rock, paper, scissors against user
    // declare variables
    int userChoice, gameChoice;
    string winner;

    userChoice = getUserChoice();    // user make selection
    gameChoice = getGameChoice();  // program makes random selection

    // winner or tie is announced
    winner = whoWins(userChoice,gameChoice);
    if (winner == "user"){
        cout << "You win!"<< endl;
    }
    else if (winner == "game"){
        cout << "You Lose!" << endl;
    }
    else if (winner == "tie"){
        cout << "It's a Tie!" << endl;
    }
    return 0;
}

int getUserChoice()
{//gets player's choice
    int playerChoice;
    cout << "Pick one: Rock(1) Paper(2) Scissors(3): " << endl;
    cin >> playerChoice;
    return playerChoice;
}

int getGameChoice()
{//gets computer's choice
    int gameChoice;
    srand(time(0));
    gameChoice = (rand() % 3) + 1;
    return gameChoice;
}
string whoWins(int userChoice, int gameChoice){
    //calculates who wins

    if ((userChoice == 1) && (gameChoice == 2))
    {//rock does not beat paper. game wins
        return "game";
    }
    else if ((userChoice == 1) && (gameChoice == 3))
    {//rock beats scissors. user wins
        return "user";
    }
    else if ((userChoice == 2) && (gameChoice == 3))
    {//paper does not beat scissors. game wins
        return "game";
    }
    else if ((userChoice == 2) && (gameChoice == 1))
    {//paper beats rock. user wins
        return "user";
    }
    else if ((userChoice == 3) && (gameChoice == 1))
    {//scissors do not beat rock. game wins
        return "game";
    }
    else if ((userChoice == 3) && (gameChoice == 2))
    {//scissors beats paper. user wins
        return "user";
    }
    else if (userChoice == gameChoice)
    {//tie
        return "tie";
    }




}


