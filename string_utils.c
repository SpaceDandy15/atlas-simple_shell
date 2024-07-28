#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *_strdup(const char *s) {
    return strdup(s);
}

char *trtok(char *str, const char *delim) {
    static char *buffer = NULL;

    if (str) {
        buffer = str;
    }

    if (!buffer) {
        return NULL;
    }

    char *token = buffer;
    while (*buffer && !strchr(delim, *buffer)) {
        ++buffer;
    }

    char *new_token = malloc(strlen(token) + 1);
    strcpy(new_token, token);

    while (*buffer && !strchr(delim, *buffer)) {
        ++buffer;
    }

    *buffer = '\0';

    buffer += strlen(token) + 1;
    
    return new_token;
}

int _strcmp(const char *a, const char *b) {
    return strcmp(a, b);
}

char *pathstr(char *path) { /** Adjusted to remove unused parameter 'first'*/
    char *result = malloc(strlen(path) + 1);
    strcpy(result, path);
    return result;
}
