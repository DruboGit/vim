#include <iostream>
#include <string>

std::string word;
int lives = 10;
std::string guesses[99];
bool status = true;
std::string guess;
bool changed = false;
int wrongs = 0;
bool death = false;
std::string trash;
int correctLetters = 0;

int main(void) {
	std::system("clear");
	std::cout << "You may want to hide the screen from anyone guessing your word\n";
	std::cout << "Enter desired guessing word: ";
	std::cin >> word;
	std::string shownWord[size(word)];
	for (int i = 0; i < size(word); i++){
		word[i] = toupper(word[i]);
	}
	for (int i = 0; i < size(word); i++){
		shownWord[i] = "_";
	}
	for (int i = 0; true ; i++) {
		std::system("clear");
		std::cout << "Word: ";
		for (int i = 0; i < size(word); i++){
			std::cout << shownWord[i] << " ";
		}
		std::cout << "   Lives left: " << lives << "   Guesses: ";
		for (int i = 0; i < sizeof(guesses)/sizeof(guesses[0]); i++){
	       		std::cout << guesses[i];
		}
		std::cout << std::endl << "Your guess: ";
		std::cin >> guess;
		if (size(guess) > 1){
			std::cout << "Can only accept single letters, please try again (please input something and press enter to continue, yanky code shit going on :( )\n";
			status = false;
			std::cin >>trash;
			i--;
		} else {
			guess = toupper(guess[0]);
			changed = false;
			for (int i = 0; i < size(word); i++){
				if (guess[0] == word[i]){
					shownWord[i] = guess[0];
					changed = true;
					correctLetters++;
				}
				if (i == size(word)-1 and changed == false){
					lives--;
					guesses[wrongs] = guess[0];
					wrongs++;
				}
				if (lives == 0){
					std::cout << "Sorry, you lose :(";
					death = true;
					break;
				}
			}
		}
		if (correctLetters == size(word)){
			std::cout << "Congratulations! You won! :D";
			std::cin >> trash;
			break;
		}
		if (death == true){
			std::cin >> trash;
			break;
		}
	}
}
