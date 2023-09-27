// ** Author: Rawan khaled https://github.com/RawanKhaled20/Codsoft-cpp.git**

#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
  // Seed the random number generator with different random numbers
  srand(int (time(NULL)));

  // produce numbers between 0 to 100
  int random_number= (rand()%100)+1;

  // The user guess limited to 10 trials
  int guess=0;
  bool test=false;
  cout<<"  Welcome to number guessing game, You have 10 trials to guess the number corrcetly."<<endl;
  cout<<"                               Enjoy to the max!!"<<endl;
  cout<<"--------------------------------------------------------------------------------------"<<endl;
  for(int i=1; i<=10; i++)
  {
     cout<<"please guess a number between 0 to 100"<<endl;
     cin>>guess;
     if(guess==random_number)
     {  test=true;
        break;}
     else
     {  cout<<"wrong guess you have "<<10-i<<" trials left"<<endl;
        if(guess>random_number)
        cout<<"your guess is higher than the number"<<endl;
        else
        cout<<"your guess is lower than the number"<<endl;
     }
     cout<<endl;
  }

  // Test if the final guess is correct or not
  if(test)
    cout<<"Congrats!, you correctly guessed the number"<<endl;
  else
    cout<<"Hard luck!, Try the game again"<<endl;

  return 0;
}
