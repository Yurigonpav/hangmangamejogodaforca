#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

vector<string> words = {"PROGRAMMING", "DEVELOPMENT", "LANGUAGE", "COMPUTER", "HARDWARE", "BACKUP"};

string chooseRandomWord() {
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

string hideWord(const string& word) {
    string hiddenWord(word.length(), '_');
    return hiddenWord;
}

bool isValidAttempt(const string& word, char letter, string& hiddenWord) {
    bool correct = false;
    char upperCaseLetter = toupper(letter); // Convert to uppercase
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == upperCaseLetter) {
            hiddenWord[i] = upperCaseLetter;
            correct = true;
        }
    }
    return correct;
}

bool isWordComplete(const string& hiddenWord) {
    return hiddenWord.find('_') == string::npos;
}

int main() {
    string word = chooseRandomWord();
    string hiddenWord = hideWord(word);
    int maxAttempts = 6;
    int attempts = 0;
    vector<char> attemptedLetters;

    cout << "Welcome to the Hangman Game!\n";
    
    while (attempts < maxAttempts) {
        cout << "Word: " << hiddenWord << "\n";
        cout << "Remaining attempts: " << maxAttempts - attempts << "\n";
        cout << "Attempted letters: ";
        for (char letter : attemptedLetters) {
            cout << letter << " ";
        }
        cout << "\n";

        char letter;
        cout << "Enter a letter: ";
        cin >> letter;

        letter = toupper(letter); // Convert to uppercase

        if (find(attemptedLetters.begin(), attemptedLetters.end(), letter) != attemptedLetters.end()) {
            cout << "You've already tried that letter. Try another one.\n";
            continue;
        }

        attemptedLetters.push_back(letter);

        if (isValidAttempt(word, letter, hiddenWord)) {
            cout << "Correct letter!\n";
            if (isWordComplete(hiddenWord)) {
                cout << "Congratulations! You guessed the word: " << word << "\n";
                break;
            }
        } else {
            cout << "Incorrect letter. Try again.\n";
            attempts++;
        }
    }

    if (attempts == maxAttempts) {
        cout << "You've reached the maximum number of attempts. The word was: " << word << "\n";
    }

    return 0;
}
