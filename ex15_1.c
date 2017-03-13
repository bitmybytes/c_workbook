#include <stdio.h>

int main(int argc, char *argv[])
{
    //create two arrays we care about
    int ages[] = { 23, 43, 12, 89, 2 };
    int *agesP = ages;

    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };
   
    char **namesP = names;
 
    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way using indexing
    for(i = count - 1; i >= 0; i--) {
        printf("%s has %d years alive.\n", namesP[i], agesP[i]);
    }

    printf("---\n");

    // setup the pointers to the start of the arrays
    int *cur_age = agesP;
    char **cur_name = namesP;
    
    // second way of using pointers
    for(i = count - 1; i >= 0; i--) {
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");

    // third way, pointers are just arrays
    for(i = count - 1; i >= 0; i--) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // fourth way with pointers in a stupid complex way
    for(cur_name = namesP, cur_age = agesP;
            (cur_age - ages) < count; cur_name++, cur_age++) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }      
    
    return 0;
}
