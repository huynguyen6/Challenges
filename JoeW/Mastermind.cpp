#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    string easyWords[] = {"tune", "bald", "unit", "care", "slab"};
    string medWords[] = {"steward", "diamond", "seminar", "central", "council"};
    string hardWords[] = {"vegetarian", "particular", "acceptance", "background", "relinquish"};
    string vHardWords[] = {"concentration", "communication", "embarrassment", "demonstration", "constellation"};
    int usrDifficulty, correctLetters, len;
    int guesses = 4;
    string chosenWord, usrGuess;

    srand((unsigned)time(0));
    int randomInteger;
    for(int index=0; index<5; index++){
        randomInteger = (rand()%5);
    }

    cout << "What level of word would you like to guess? (1-4, where Easy = 1 and Very Hard = 4)" << endl;
    cin >> usrDifficulty;

    if(usrDifficulty == 1) {
        chosenWord = easyWords[randomInteger];

        while(guesses > 0) {
            cout << "Guess? (" << guesses << " left)?" << " (Easy words have 4 letters)" << endl;
            cin >> usrGuess;

            len = usrGuess.length();
            for(int i = 0; i < len; ++i) {
                if(chosenWord[i] == usrGuess[i])
                    ++correctLetters;

                if(correctLetters == len) {
                    cout << "Congratulations!";
                    break;
                } else {
                    guesses--;
                }
            }
        }
    } else if(usrDifficulty == 2) {
        chosenWord = medWords[randomInteger];

        while(guesses > 0) {
            cout << "Guess? (" << guesses << " left)?" << " (Medium words have 7 letters)" << endl;
            cin >> usrGuess;

            len = usrGuess.length();
            for(int i = 0; i < len; ++i) {
                if(chosenWord[i] == usrGuess[i])
                    ++correctLetters;

                if(correctLetters == len) {
                    cout << "Congratulations!";
                    break;
                } else {
                    guesses--;
                }
            }
        }
    } else if(usrDifficulty == 3) {
        chosenWord = hardWords[randomInteger];

        while(guesses > 0) {
            cout << "Guess? (" << guesses << " left)?" << " (Medium words have 10 letters)" << endl;
            cin >> usrGuess;

            len = usrGuess.length();
            for(int i = 0; i < len; ++i) {
                if(chosenWord[i] == usrGuess[i])
                    ++correctLetters;

                if(correctLetters == len) {
                    cout << "Congratulations!";
                    break;
                } else {
                    guesses--;
                }
            }
        }
    } else if(usrDifficulty == 4) {
        chosenWord = vHardWords[randomInteger];

        while(guesses > 0) {
            cout << "Guess? (" << guesses << " left)?" << " (Medium words have 13 letters)" << endl;
            cin >> usrGuess;

            len = usrGuess.length();
            for(int i = 0; i < len; ++i) {
                if(chosenWord[i] == usrGuess[i])
                    ++correctLetters;

                if(correctLetters == len) {
                    cout << "Congratulations!";
                    break;
                } else {
                    guesses--;
                }
            }
        }
    }

    return 0;
}
