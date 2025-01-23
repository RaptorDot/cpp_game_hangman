#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;

vector<string> loadWords(){
    vector<string> words;
    string line;
    ifstream fin("wordList.txt");
    while (getline(fin, line))
    {
        if (line.length()>0)
        {
            words.push_back(line);
        }   
    }
    return words;
}


string chooseWord(){
    vector<string> word_list = loadWords();
    srand(time(0));

    int random_index = rand()%word_list.size();

    return word_list[random_index];

}
bool displayWords(string word,const vector<char>guessedL){

    bool winStatus = true;
    for (char c: word)
    {
        if (find(guessedL.begin() , guessedL.end(), c)!=guessedL.end())
        {
            cout<<c<<" ";
            winStatus = false;
        }
        
    }
        cout<<endl;

    return winStatus;
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