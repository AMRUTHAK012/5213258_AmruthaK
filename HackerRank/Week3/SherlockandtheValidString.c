#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char* readline();
char* isValid(char* s);

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = isValid(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);
    free(s);

    return 0;
}
char* isValid(char* s) {
    int freq[26] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    int count_freq[100001] = {0};
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            count_freq[freq[i]]++;
        }
    }
    int unique_freqs = 0;
    int first_freq = 0;
    int second_freq = 0;
    int first_freq_count = 0;
    int second_freq_count = 0;

    for (int i = 1; i <= 100000; i++) {
        if (count_freq[i] > 0) {
            unique_freqs++;
            if (first_freq == 0) {
                first_freq = i;
                first_freq_count = count_freq[i];
            } else if (second_freq == 0) {
                second_freq = i;
                second_freq_count = count_freq[i];
            }
        }
    }
    if (unique_freqs == 1) {
        return "YES";
    }

    if (unique_freqs == 2) {
        if (first_freq_count == 1 && (first_freq == 1 || first_freq == second_freq + 1)) {
            return "YES";
        }
        if (second_freq_count == 1 && (second_freq == 1 || second_freq == first_freq + 1)) {
            return "YES";
        }
    }
    return "NO";
}
char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }
        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if (!data) {
            data = '\0';
            break;
        }
    }
    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length);
        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);
        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }
    return data;
}
