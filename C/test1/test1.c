#include <stdio.h>  // scanf, etc.
#include <string.h> // strlen
#include <stdlib.h> // sort, search

#define ARRAYSIZE 6

void introduceMethod(char *introMsg);
void handleArgAndTestString(char *argv1);
void handleStdin();
void testFile();
void testSort();
void useStruct();
void useEnum();
void testLinkedList();

/*******************************************
 * Data structures
 *******************************************/
// enum
enum State
{
    Working = 1,
    Failed = 0
};
// enum with implicit assoc. (e.g. Mon=0, Tue=1, ...)
enum Weekday
{
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat,
    Sun
};
// struct (without variable defined)
struct Point
{
    int x, y;
};
// struct (with variable defined)
struct Person
{
    int age;
    char name[10];
} person1;
// struct with typedef (the proper way)
typedef struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} Book;
// linked list
typedef struct node
{
    int value;
    struct node *next;
} node_t;
// tree
// TODO

int main(int argc, char *argv[])
{
    printf("Hello world!\n");

    if (argc > 1)
    {
        introduceMethod("handleArgAndTestString");
        handleArgAndTestString(argv[1]);

        introduceMethod("handleStdin");
        handleStdin();

        introduceMethod("testFile");
        testFile();

        introduceMethod("testSort");
        testSort();

        introduceMethod("useStruct");
        useStruct();

        introduceMethod("useEnum");
        useEnum();

        introduceMethod("testLinkedList");
        testLinkedList();
    }
    else
    {
        /* code */
        printf("No param passed!\n");
    }

    return 0;
}

void introduceMethod(char *introMsg)
{
    printf("\n---------------\n");
    printf("-- %s\n", introMsg);
    printf("---------------\n");
}

void handleArgAndTestString(char *argv1)
{
    printf("Argument input string: %s \n", argv1);
    size_t str_size = strlen(argv1);
    printf("Argument string size: %ld \n", str_size);
    char strToAppend[10] = "0123456789";
    strncat(argv1, strToAppend, 5);
    printf("Argument input string appended: %s \n", argv1);
};

void handleStdin()
{
    char inputString2[10];
    printf("Insert a new string: \n");
    scanf("%s", inputString2);
    printf("Inserted new string: %s \n", inputString2);
};

void testFile()
{
    FILE *pFile;
    char stringFromFile[10];
    pFile = fopen("input/myfile.txt", "r");
    if (pFile == NULL)
    {
        printf("Error opening file! \n");
    }
    else
    {
        fscanf(pFile, "%s", stringFromFile);
        printf("Read from file: %s \n", stringFromFile);
    }
    fclose(pFile);
};

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
};

void testSort()
{
    int intArray[6] = {3, 4, 7, 9, 2, 5};

    /*
    qsort(intArray, ARRAYSIZE, sizeof(int), compare);
    for(size_t i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d", intArray[i]);
    }
    */

    int key = 9;
    int *pFoundInt = (int *)bsearch(&key, intArray, ARRAYSIZE, sizeof(int), compare);
    if (pFoundInt != NULL)
    {
        // Found something
        printf("Found value: %d \n", *pFoundInt);
    }
    else
    {
        printf("Value NOT found :( \n");
    }
};

void useEnum()
{
    enum Weekday day1 = Mon;
    switch (day1)
    {
    case Mon:
        printf("It's Monday");
        break;
    case Tue:
        printf("It's Tuesday");
        break;
    case Wed:
        printf("It's Wednesday");
        break;
    case Thu:
        printf("It's Thursday");
        break;
    case Fri:
        printf("It's Friday");
        break;
    case Sat:
        printf("It's Saturday");
        break;
    case Sun:
        printf("It's Sunday");
        break;

    default:
        break;
    }
};

void useStruct()
{
    // person 1 was already defined
    person1.age = 32;
    strcpy(person1.name, "Mario");
    printf("Global variable person age: %d, name: %s\n", person1.age, person1.name);
    // create a new local person2
    struct Person person2 = {23, "Gino"};
    printf("Local variable person age: %d, name: %s\n", person2.age, person2.name);
    // create new point
    struct Point point1 = {1, 3};
    printf("Local variable point x: %d, y: %d\n", point1.x, point1.y);
    // create new book (note absence of struct keyword)
    Book book;
    strcpy(book.title, "C Programming");
    strcpy(book.author, "Nuha Ali");
    strcpy(book.subject, "C Programming Tutorial");
    book.book_id = 6495407;
    printf("Book title : %s\n", book.title);
    printf("Book author : %s\n", book.author);
    printf("Book subject : %s\n", book.subject);
    printf("Book book_id : %d\n", book.book_id);
};

void printList(node_t *head)
{
    node_t *current = head;
    do
    {
        printf("Value in list element: %d\n", current->value);
        current = current->next;
    } while (current != NULL);
}

void testLinkedList()
{
    // list on stack
    node_t node1;
    node1.value = 1;
    node1.next = NULL;
    node_t node2;
    node2.value = 2;
    node2.next = NULL;
    node1.next = &node2;
    printList(&node1);

    // list on heap
    node_t *node3 = (node_t *)malloc(sizeof(node_t));
    node3->value = 3;
    node3->next = NULL;
    node_t *node4 = (node_t *)malloc(sizeof(node_t));
    node4->value = 4;
    node4->next = NULL;
    node3->next = node4;
    printList(node3);
    free(node3);
    free(node4);
}
