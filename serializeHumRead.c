#include <stdio.h>

const char* PERSON_FORMAT_OUT = "(%s, %d, %c)\n";
const char* PERSON_FORMAT_IN = "(%[^,], %d, %c)";

// Serialize in JSON FORMAT
//const char* PERSON_FORMAT_IN = "{\"name\": \"%[^\"]\", \"age\":%d, \"gender\": \"%c\"}";
//const char* PERSON_FORMAT_OUT = "{\"name\": \"%s\", \"age\":%d, \"gender\": \"%c\"}\n";

typedef struct Person {
    char    name[20];
    int     age;
    char    gender;
} Person;

int main(void) {

    // Initialization of Person objects
    Person p1 = {
        .name = "Max Mustermann",
        .age = 36,
        .gender = 'M',
    };
    printf("Name: %s, Age: %d, Gender: %c\n", p1.name, p1.age, p1.gender);
    Person p2;

    // Open file
    FILE *f;
    f = fopen("people.dat", "w+");
    if (f == NULL) {
        return 1;
    }

    // Serialization - Write data to file from memory
    fprintf(f, PERSON_FORMAT_OUT, p1.name, p1.age, p1.gender);
    fseek(f, 0, SEEK_SET);

    // Deserialization - Read data from file to memory
    fscanf(f, PERSON_FORMAT_IN, p2.name, &p2.age, &p2.gender);
    printf("Person p2: (Name: %s, Age: %d, Gender: %c)\n", p2.name, p2.age, p2.gender);

    // Close file
    fclose(f);

    return 0;
}
