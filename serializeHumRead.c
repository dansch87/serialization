#include <stdio.h>

const char* PERSON_FORMAT_OUT = "(%s, %d, %c)\n";

typedef struct Person {
    char    name[20];
    int     age;
    char    gender;
} Person;

int main(void) {

    Person p1 = {
        .name = "Max Mustermann",
        .age = 36,
        .gender = 'M',
    };
    printf("Name: %s, Age: %d, Gender: %c\n", p1.name, p1.age, p1.gender);

    // Open file
    FILE *f;
    f = fopen("people.dat", "w+");
    if (f == NULL) {
        return 1;
    }

    // Serialization - Write data to file from memory
    fprintf(f, PERSON_FORMAT_OUT, p1.name, p1.age, p1.gender);
    fseek(f, 0, SEEK_SET);

    // Close file
    fclose(f);

    return 0;
}
