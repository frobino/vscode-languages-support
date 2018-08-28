#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]){
    printf("Hello world!\n");
   
    if (argc>1) {
        char *inputString;
        inputString = argv[1];
        printf("Input string: %s \n", inputString);

        size_t str_size= strlen(inputString);
        printf("String size: %d", str_size);
    } else {
        /* code */
        printf("No param passed!\n");
    }

    return 0;
}