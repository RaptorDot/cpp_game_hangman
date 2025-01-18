#include<iostream>
#include<vector>
using namespace std;
string chooseWord(){

}
bool displayWords(string word,const vector<char>gussedL){

}
int main(){
    string wordToGuess = chooseWord();
    vector<char>guessedLetter;
    bool winsStatus= false;
    int lives =6;

    cout<<"Welcome To Hangman"<<endl;

    while(lives>0){
        cout<<"Lives Remaining: "<<lives<<endl;
        winsStatus = displayWords(wordToGuess, guessedLetter);

        if(winsStatus) cout<<"Congratulations you guessed the word right: "<<wordToGuess<<endl;
        break;

        char guess;
        cout<<"guess a letter: ";
        cin>>guess;
        guessedLetter.push_back(guess);

        if(wordToGuess.find(guess)!=string::npos){
            cout<<"Correct Guess!"<<endl;
        }else{
            cout<<"Whoops! Incorrect Guess.."<<endl;
            lives--;
        }



    }

    if(lives==0) cout<<"Oh NO..You Lost The Game!"<<endl<<"The Word Was: "<<wordToGuess;
    return 0;

}