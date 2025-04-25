#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 1) Insert new name on Pth position where, P<N
void insert_name(char*** names, int *length, char* name, int p) {
    (*length)++;
    *names = (char**)realloc(*names, (*length)*sizeof(char*));
    for (int i = *length-1; i > p; i--)
    {
        (*names)[i] = (*names)[i-1];
    }
    (*names)[p] = (char*)malloc(20*sizeof(char));
    strcpy((*names)[p], name);
}

// 2) Append new name
void append_name(char*** names, int *length, char* name) {
    (*length)++;
    *names = (char**)realloc(*names, (*length)*sizeof(char*));
    (*names)[*length-1] = (char*)malloc(20*sizeof(char));
    strcpy((*names)[*length-1], name);
}


// 3) search the name
int search_name(char** names, int length, char* name) {
    int index = -1;
    for (int i = 0; i < length; i++)
    {
        if (!strcmp(names[i], name))
        {
            printf("Found at index %d", i);
            index = i;
            break;
        }
    }
    return index;
}

// 4 deleting name
void delete_name(char*** names, int* length, char* name) {
    int index = search_name(*names, *length, name);
    for (int i = index; i < *length-1; i++)
    {
        (*names)[i] = (*names)[i-1];
    }
    (*length)--;
    *names = (char**)realloc(*names, (*length)*sizeof(char*));
}

int main() {
    int n;
    printf("Enter how many names you wanna enter? ");
    scanf("%d", &n);

    // creating dynamic memory allocation
    char** str_arr = (char**)malloc(n*sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        str_arr[i] = (char*)malloc(20*sizeof(char));
    }

    // Entering values from user
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str_arr[i]);
    }

    // 1) Insert new name on Pth position where, P<N
    insert_name(&str_arr, &n, "inserted_elem", 2);
    delete_name(&str_arr, &n, "inserted_elem");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", str_arr[i]);
    }


    return 0;
}