#include <stdio.h>
#include <string.h>

#define MAX 15 

int splitCommand(char *cmd, char *args[], int max_args) {
    int count = 0;
    char *argPiece = strtok(cmd, " ");
    
    while (argPiece != NULL && count < max_args - 1) {
        args[count++] = argPiece;
        argPiece = strtok(NULL, " ");
    }
    
    args[count] = NULL; 
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: redir <inp> <cmd> <out>\n");
        return 1;
    }

    char *inp = argv[1];
    char *cmd = argv[2];
    char *out = argv[3];

    printf("Input file: %s\n", inp);
    printf("Command: %s\n", cmd);
    printf("Output file: %s\n", out);

    char *args[MAX];
    int arg_count = splitCommand(cmd, args, MAX);

    printf("Parsed command arguments:\n");
    for (int i = 0; i < arg_count; i++) {
        printf("  arg[%d]: %s\n", i, args[i]);
    }

    return 0;
}
