#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

const char *words[10] = {"watch", "patriots", "massachusetts", "blue", "apple", "hello", "laptop", "python", "better", "sublime"};

int main(){
	srand(time(NULL));
	int wordIndex = rand()%10;
	const char* secretWord = words[wordIndex];
	int wordLen = strlen(secretWord);


	int numGuesses = 6;
	char guesses[30];
	int guessesLoc = 0;

	int won = 0;

	printf("%s\n", "You are playing hangman." );


	while(numGuesses > 0 && won == 0){
		printf("You have %d wrong guesses left. \n", numGuesses );
		printf("\n");
		printf("%s", "Your secretWord: " );
		for(int i=0; i < wordLen; i++){
			char currentChar = secretWord[i];
			if (memchr(guesses, currentChar, sizeof(guesses))){
				printf("%c",currentChar);
			}else{
				printf("_");
			}
			
		}
		printf("\n");

		char *c;

		printf("Guess a letter:");
		scanf("%s", c);
		printf("\n");
		guesses[guessesLoc] = tolower(*c);
		guessesLoc += 1;

		if (!memchr(secretWord, *c, sizeof(secretWord))){
			numGuesses -=1;
		}

		for(int i=0; i < wordLen; i++){
			char currentChar = secretWord[i];
			if(memchr(guesses, currentChar, sizeof(guesses))){
				won = 1;
			}else{
				won = 0;
				break;
			}

		}
	}
	
	if(won == 1){
		printf("Congrats you won! The secret word was: %s\n", secretWord );
	}else{
		printf("Sorry you lost. The secret word was: %s\n", secretWord );
	}

	return 0;
}
