#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int after_arg = 0;

    if (argc == 1) { return 1; }

    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] != '-' || after_arg == 1) {      // Arguments
            after_arg = 1;
            printf("Argument: %s\n", argv[i]);
        } else if (strlen(argv[i]) > 1) {
            if (argv[i][1] != '-') {
                // printf("Option courte: %s\n", argv[i]);

                for (int j = 1; j < (int) strlen(argv[i]); ++j) {
                    printf("Option courte: -%c\n", argv[i][j]);
                }

            } else if (strlen(argv[i]) == 2) {
                after_arg = 1;  // --
            } else if (strlen(argv[i]) > 2) {
                printf("Option longue: %s\n", argv[i]);
            }
        } else {
            printf("Unknown: %s\n", argv[i]);
        }
    }

    return 1;
}
