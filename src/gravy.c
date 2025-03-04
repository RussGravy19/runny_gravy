#include <stdio.h>
#include <stdlib.h>

extern char **environ;

void gravy(void) {
    printf("I am completely evil, and will now print all of your environment variables!\n");

    char **env = environ;
    
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}
