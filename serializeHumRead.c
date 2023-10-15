#include <stdio.h>

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

    return 0;
}