#include <stdio.h>
#include <string.h>

int main() {

FILE *file = fopen("input.txt", "r"); // "r" is for reading, *file declares a file pointer


if(file == NULL){
    perror("Error opening file");
    return 1;
}

//Word counter
int word_count = 0;
char word[50]; //Assume a word wont be longer than 50 characters

// while "reading up to 49 characters (or until a whitespace is encountered) from input.txt into the word array":
while(fscanf(file, "%49s", word) == 1) { 
    word_count ++;
}

//Character counter
rewind(file);

int character_count = 0;
int ch;

// while "taking one character at a time and comparing if it equals end of file, if not: increase character count"
while ((ch = fgetc(file)) != EOF) {
    if(isspace(ch) == 0) { //if "isspace == false, increase character_count"
        character_count++;
    }
}

//Specific word counter
rewind(file);

char input[50];
int specific_word_counter = 0;

printf("Enter a word: ");
fflush(stdout);
scanf("%49s", input);

while(fscanf(file, "%49s", word) == 1) { 
    if(strcmp(word, input) == 0) {
        specific_word_counter ++;
    }
}

printf("The number of words in the file is: %d\n", word_count);
printf("The number of characters in the file is: %d\n", character_count);
printf("# of Times your specific word is in the file is: %d\n", specific_word_counter);


fclose(file);

return 0;
}