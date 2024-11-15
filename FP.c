#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>

bool (*stringStartsWithAnyCharpredicateGenerator(char startsWithChar))(const char *item) {
    
		bool startsWith(const char  *item){
			 if (item == NULL) {
                    return false;
                }
             return item[0] == startsWithChar;
		}
		return startsWith;
}

bool endsWithB(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return false;
    }
    return str[strlen(str) - 1] == 'b';
}
int fliterString(char *names[], int arrayLength, bool (*predicate) (const char*), char *result[], int maxResults) {
    int count = 0;
    for (int i = 0; i < arrayLength; i++) {
        // Compare the first char of the names with the given alphabet
        if(predicate(names[i])) {
            if (count < maxResults) {
                result[count] = names[i];
                count++;
            }
        }
    }
    return count;
}

int main() {
    char *names[10] = {"bosch", "Robert", "Lenovo", "Bengaluru", "Rubic"};
    int arrayLength = sizeof(names) / sizeof(names[0]);
    char* result[arrayLength];
    int maxResults = arrayLength;
    bool (*predicate)(const char *item);
    predicate=stringStartsWithAnyCharpredicateGenerator('R');
    int count = fliterString(names, arrayLength, predicate, result, maxResults);

    printf("Filtered names:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", result[i]);
    }
     count = fliterString(names, arrayLength, stringStartsWithAnyCharpredicateGenerator('B'), result, maxResults);

    return 0;
}
