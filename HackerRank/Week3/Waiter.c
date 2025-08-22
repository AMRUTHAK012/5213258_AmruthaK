#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 * 1. INTEGER_ARRAY number
 * 2. INTEGER q
 */

/*
 * To return the integer array from the function, you should:
 * - Store the size of the array to be returned in the result_count variable
 * - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 * *result_count = 5;
 *
 * static int a[5] = {1, 2, 3, 4, 5};
 *
 * return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 * *result_count = 5;
 *
 * int *a = malloc(5 * sizeof(int));
 *
 * for (int i = 0; i < 5; i++) {
 * *(a + i) = i + 1;
 * }
 *
 * return a;
 * }
 *
 */
 void sieve(int* primes, int q) {
    int max_val = 10000;
    int* is_prime = (int*)malloc((max_val + 1) * sizeof(int));
    for (int i = 0; i <= max_val; i++) {
        is_prime[i] = 1;
    }
    is_prime[0] = is_prime[1] = 0;
    for (int p = 2; p * p <= max_val; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= max_val; i += p) {
                is_prime[i] = 0;
            }
        }
    }
    int count = 0;
    int num = 2;
    while (count < q) {
        if (is_prime[num]) {
            primes[count++] = num;
        }
        num++;
    }
    free(is_prime);
}
int* waiter(int number_count, int* number, int q, int* result_count) {
    int* primes = (int*)malloc(q * sizeof(int));
    sieve(primes, q);
    
    int* current_A = number;
    int current_A_count = number_count;
    
    int* ans = (int*)malloc(number_count * sizeof(int));
    *result_count = 0;

    for (int i = 0; i < q; i++) {
        int prime = primes[i];
        
        int* new_A = (int*)malloc(number_count * sizeof(int));
        int new_A_count = 0;
        
        int* B = (int*)malloc(number_count * sizeof(int));
        int B_count = 0;
        
        for (int j = current_A_count - 1; j >= 0; j--) {
            if (current_A[j] % prime == 0) {
                B[B_count++] = current_A[j];
            } else {
                new_A[new_A_count++] = current_A[j];
            }
        }
        
        for (int j = B_count - 1; j >= 0; j--) {
            ans[(*result_count)++] = B[j];
        }
        
        if (i > 0) {
            free(current_A);
        }
        current_A = new_A;
        current_A_count = new_A_count;
        free(B);
    }
    
    for (int j = current_A_count - 1; j >= 0; j--) {
        ans[(*result_count)++] = current_A[j];
    }
    
    if (q > 0) {
        free(current_A);
    }
    free(primes);

    return ans;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));
    int q = parse_int(*(first_multiple_input + 1));

    char** number_temp = split_string(rtrim(readline()));

    int* number = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int number_item = parse_int(*(number_temp + i));
        *(number + i) = number_item;
    }
    
    int result_count;
    int* result = waiter(n, number, q, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));
        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
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

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }
    if (!*str) {
        return str;
    }
    while (*str != '\0' && isspace(*str)) {
        str++;
    }
    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }
    if (!*str) {
        return str;
    }
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }
    return value;
}
