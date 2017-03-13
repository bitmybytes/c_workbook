#include <stdio.h> /* input/output functions */ 
#include <assert.h> /* conditionally compiled macro that raises error when argument is zero */
#include <stdlib.h> /* general utilities: memory management */
#include <string.h> /* string handling */

/* Declare the structure Person with fields inside it */
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

/* create structure using malloc. Set name, age, height, weight.
    Return pointer to the initialized Person structure.  */
struct Person *Person_create(char *name, int age,
     int height, int weight)
{
    /* call malloc to create a chunck of memory in the heap RAM
        of size = struct Person and return the pointer to the start
        of this address  */
    struct Person *who = malloc(sizeof(struct Person));
    /* verify that the pointer returned is not invalid */
    assert(who != NULL);

    /* set the name by calling a string duplicate function
        which creates space in heap memory and copies the name into that
        and return the pointer to that address */
    who->name = strdup(name);
    /* set the age */
    who->age  = age;
    /* set the height */
    who->height = height;
    /* set the weight */
    who->weight = weight;

    /* return the pointer to the newly initialized Person struct */
    return who;
}

/* destroy the heap memory created for Person structure and its members
stored in heap memory */
void Person_destroy(struct Person *who)
{
    /* make sure the person pointer passed in argument is valid */
    assert(who != NULL);
    /* free memory pointed by name */
    free(who->name);
    /* free memory pointed by who (Person structure) */
    free(who);
}

/* print Person structure  */
void Person_print(struct Person *who)
{
    /* print name */
    printf("Name: %s\n", who->name);
    /* print age */
    printf("\tAge: %d\n", who->age);
    /* print height */
    printf("\tHeight: %d\n", who->height);
    /* print weight */
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    //make two people structures
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
