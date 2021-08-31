// CSC 234
// M1HW - Rock Paper Scissors-Silver
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
int askGoAgain(); // asks user if they want to go again
int callGame(); //plays the game 5 times
int whoWinsAll(int player, int computer, int tie);//gets the winner of all

int main()
{// 5 rounds of rock paper scissors and then announce the winner.
    // declare variables
    int count, player, computer, whoWon, tie;
    //initializing variables
    count = 1;
    player = 0;
    computer = 0;
    tie = 0;
    while (count <= 5)
    {// loops until game has been played 5 times
        count ++;
        whoWon = callGame();
        if (whoWon == 1){
            player ++;
        }
        else if (whoWon == 2){
            computer ++;
        }
        else if (whoWon == 3) {
            tie ++;
        }
    }
    whoWinsAll(player,computer,tie);
    askGoAgain();
    return 0;
}
int callGame()
{


    // declare variables
    int userChoice, gameChoice;
    string winner;

    userChoice = getUserChoice();    // user make selection
    gameChoice = getGameChoice();  // program makes random selection

    // winner or tie is announced
    winner = whoWins(userChoice,gameChoice);
    if (winner == "user"){

        return 1;
    }
    else if (winner == "game"){

        return 2;
    }
    else if (winner == "tie"){

        return 3;
    }
}

int askGoAgain()
{// ask user if they want to go again
    string goAgain;
    cout << "Do you want to go again? Y/N " << endl;
    cin >> goAgain;

    if ((goAgain == "y") || (goAgain == "Y"))
    {
        main();
    }
    else if ((goAgain == "n") || (goAgain == "N"))
    {
        cout << "Bye!\n Thanks for Playing!";
        return 0;
    }
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

int whoWinsAll(int player, int computer, int tie)
{// declares the winner overall
    if (player == computer)
    {
        cout << "Its a tie!" << endl;
        cout <<"You won " << player << " times and the computer won " << computer << " times." << endl;
        cout << "There were " << tie << " ties. " << endl;
    }
    else if (player < computer){
        cout << "You lost!" << endl;
        cout <<"You won " << player << " times and the computer won " << computer << " times." << endl;
        cout << "There were " << tie << " ties. " << endl;
    }
    else if (player > computer){
        cout << "You Won!" << endl;
        cout <<"You won " << player << " times and the computer won " << computer << " times." << endl;
        cout << "There were " << tie << " ties. " << endl;
    }
}


