#include <stdio.h>
#include <string.h>

int main() {

FILE *file = fopen("input.txt", "r"); // "r" is for reading, *file declares a file pointer
FILE *tempFile = fopen("temp.txt", "w"); // "w" is for writing
char wordToReplace[50];
char newWord[50];
char word[50];
int numberOfWordsChanged = 0;

printf("Enter the word you want to replace: ");
fflush(stdout);
scanf("%49s", wordToReplace);

printf("Enter the new word: ");
fflush(stdout);
scanf("%49s", newWord);

if(file == NULL || tempFile == NULL){
    perror("Error opening file");
    return 1;
}

while (fscanf(file, "%49s", word) == 1) {
    if (strcmp(word, wordToReplace) == 0) { 
        fprintf(tempFile, "%s ", newWord); //if "word equals wordToReplace, write newWord in the tempFile"
        numberOfWordsChanged ++;
        } 
        else {
            fprintf(tempFile, "%s ", word); //else "write the original word"
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("input.txt");
    rename("temp.txt", "input.txt");

    printf("File has now been updated, number of times your word was replaced: %d\n", numberOfWordsChanged);

}