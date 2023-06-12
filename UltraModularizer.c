#include <stdio.h>
#include <stdlib.h>
#include <strings.h>



/**
 * Used to create the possibly nested directories to the modularized program.
 * <br></br>
 * @param path The path to the modularized file.
*/
void createDir(char* path) {
    char* sep = strrchr(path,'/'); // Search for the separator.
    // Checks if it is not null.
    if(sep != NULL) {
        // If it isn't, call itself to create the previous directory.
        *sep = 0;
        createDir(path);
        *sep = '/';
    }
    // Create itself.
    mkdir(path);
}

/**
 * Opens an instance of the modularized file after creating any possible nested directories.
 * <br></br>
 * @param path The path to the modularized file.
 * @param mode The mode to open the file on.
*/
FILE* openFileAfterMkdir(char *path,char *mode) {
    char* sep = strrchr(path,'/'); // Search for the separator.
    // Checks if it exists.
    if(sep) {
        // If it does, attempt to create the directory.
        char* path0 = strdup(path);
        path0[sep - path] = 0;
        createDir(path0);
        free(path0);
    }

    return fopen(path,mode); // Open the file in the given mode.
}

/**
 * Function that reads the contents of a file and passes them into a char* variable.
 * <br></br>
 * @param path The path of the file to analyze and get the contents from.
 */
char* getContents(char* path) {
    FILE* file = fopen(path,"r");
    if(file == NULL) {
        printf("File does not exist. I cannot perform miracles.");
        exit(1);
    }

    int i = 0; // Counter that begins at 0, used to determine the amount of characters.
    char character; // Variable storing the current character.

    // Iterates through every character in the file, incrementing the counter variable.
    while((character = fgetc(file)) != EOF) i++;
    fclose(file); // Closes the already used file.

    char* contents = malloc(i + 1); // Variable that will contain the file's contents.
    FILE* file2 = fopen(path,"r"); // Opens the file a second time.
    // Second counter to place each character in the right cell.
    int j = 0;
    // Iterates through each character once again, storing them instead.
    while((character = fgetc(file2)) != EOF) {
        contents[j] = character;
        j++;
    }
    contents[i] = '\0'; // Clears the last cell for accurate representation.
    fclose(file2); // Closes the file.

    return contents; // Returns the read contents.
}

int main(int argc,const char* argv[]) {
    // Checks if the program does not have any arguments, stopping the program if it doesn't.
    if(argc < 2) {
        printf("Too little arguments provided, please provide the path to the file to ultra modularize.");
        return 1;
    }
    // Checks if the program has more than one argument, stopping the program if it does.
    if(argc > 2) {
        printf("Too many arguments provided.");
        return 1;
    }

    char* srcPath = argv[1]; // Path to the file.
    // Replace all instances of \ with /.
    for(size_t i = 0; i < strlen(srcPath); i++) if(srcPath[i] == '\\') srcPath[i] = '/';
    // Get the file's contents.
    char* contents = getContents(srcPath);
    // Obtain the first line.
    char* token = strtok(contents,"\n");
    int i = 1;
    // Iterate through all lines.
    while(token != NULL) {
        char* iAsCharStr = malloc(300); // Allocates memory for the current line's index.
        sprintf(iAsCharStr,"%d",i); // Convert the line index into a string, storing it in the variable above.
        // Allocate memory for the file's path.
        char* linePath = malloc(strlen(srcPath) + strlen("-M/line.txt") + strlen(iAsCharStr) + 1);
        // Operate on the string to obtain the full path.
        strcpy(linePath,srcPath);
        strcat(linePath,"-M/line");
        strcat(linePath,iAsCharStr);
        strcat(linePath,".txt");

        // Create the file.
        FILE* lineFile = openFileAfterMkdir(linePath,"w");
        fprintf(lineFile,"%s",token); // Write the current line in.
        fclose(lineFile); // Close the file.

        // Free all memory allocated inside the loop.
        free(iAsCharStr);
        free(linePath);
        // Go to the next line.
        i++;
        token = strtok(NULL,"\n");
    }

    remove(srcPath); // Delete the original file.
    free(contents); // Free the memory allocated for it's contents.

    printf("All done! Enjoy ultra modularization!!!");

    return 0; // End the program successfully.
}
