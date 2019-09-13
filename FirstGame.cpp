#include<iostream>
#include<ctime>
#include<stdio.h>

using namespace std;
bool PlayGameAtDifferentDifficultyLevel(int difficulty){
    cout << "\nYou are secret agent breaking into Level "<< difficulty << " server room\n";
    cout << "\nYou need to enter the secret correct code to continue..." << endl;
    cout << "Your SuperHacker2020 tells you the following information";

    srand(time(0));//create random sequence based on time of the day

    const int randomCodeA = rand()%difficulty + difficulty;
    const int randomCodeB = rand()%difficulty + difficulty;
    const int randomCodeC = rand()%difficulty + difficulty;

    const int sum = randomCodeA + randomCodeB + randomCodeC;
    const int product = randomCodeA * randomCodeB * randomCodeC;

    cout << endl;
    cout << "\n-> You have three numbers in the code\n";
    cout << "+ the code multiply to give = " << product << endl;
    cout << "+ the code add to give = " << sum << endl; 
    cout << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout << endl;
    cout << "Enter the three numbers code followed by x\n";
    cout << endl;

    int Guess, sumOfTrialCode = 0, productOfTrialCode = 1;


    while(cin>>Guess){
        sumOfTrialCode = sumOfTrialCode + Guess;
        productOfTrialCode = productOfTrialCode * Guess;
    }

    cout << endl;

    if(sum == sumOfTrialCode && product == productOfTrialCode){
        cout << "Congratulations! You are IN. Now hurry before anyone finds you.\n";
        return true;
    }
    else{
        cout << "You have failed this city. You have to die.\n";
        cout << "BOOOOOOOOOOOOOOOOMMMMMM!!!!!!!!!!! \n";
        return false;
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    int difficulty = 1;
    const int maxDifficulty = 10;
    while(difficulty <= maxDifficulty){

    //For boolean data type Unreal follows this coding standard that variable name must start with 'b'
        bool bClearedTheLevel =  PlayGameAtDifferentDifficultyLevel(difficulty); 
        
        if(bClearedTheLevel){
            ++difficulty;
            cout << "\nReady for the next level\n";
        }
        else
            break;
        
        cin.clear(); //clears any errors
        cin.ignore(); //Discards the buffer
    }
    if(difficulty == 10)
        cout << "Wow! You are a master in coding\n";
    return 0;
}
