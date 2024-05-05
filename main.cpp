#include <iostream>
#include <cstdlib>
using namespace std;
void Welcome()
{
    cout<<"Guess The Number\n";
    cout<<"-----Welcome-----\n\n";
}
int Level()
{
    cout<<"Choose Game Difficulty : \n1 - Easy\n2 - Normal\n3 - Hard\n";
    while(1){
    int LevelNumber;cin>>LevelNumber;
    switch(LevelNumber) {
        case 1:
            return 10;
            break;
        case 2:
            return 100;
            break;
        case 3:
            return 1000;
            break;
        default:
            cout << "Enter a valid number :\n";
            break;
    }
    }
}
int Random_Number(int level)
{
    srand((unsigned)time(nullptr));
    int RandomNumber=rand()%level;\
    return RandomNumber;
}
void BeginTheGame(int RandomNumber)
{
    bool win=false;
    cout<<"Time to play detective! What's your estimate?\n";
    while(!win)
    {
        int Number;cin>>Number;
        if (Number==RandomNumber)
        {
            cout<<"Great job! You've cracked the code. Thanks for playing!\n";
            win=true;
        }
        else if(Number<RandomNumber)
        {
            cout<<"You're getting warmer! Go up a notch.\n";
            cout<<"Giva a guess :\n";
        }
        else
        {
            cout<<"Cool it down! The answer is lower.\n";
            cout<<"Giva a guess :\n";
        }
    }
}
void UpForAChallenge()
{
    int level=Level();
    int RandomNumber= Random_Number(level);
    BeginTheGame(RandomNumber);
    cout<<"Game over! Up for another challenge? (Y/N)\n";
    char Again;cin>>Again;
    if(Again=='Y'||Again=='y')
    {
        return UpForAChallenge();
    }
    else if(Again=='N'||Again=='n')
    {
        cout<<"Thanks for participating!";
    }
    else
    {
        bool WhatAreYouDoing= false;
        while(!WhatAreYouDoing) {
            cout << "Enter (Y/N)\n";
            cin>>Again;
            if(Again=='Y'||Again=='y')
            {
                return UpForAChallenge();
            }
            else if(Again=='N'||Again=='n')
            {
                cout<<"Thanks for participating!";
                WhatAreYouDoing=true;
            }
        }
    }
}

int main() {
    Welcome();
    UpForAChallenge();
}
