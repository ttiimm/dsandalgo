#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

struct Node *Node_init()
{
    struct Node *node = malloc(sizeof(struct Node));
    *node = (struct Node){
        .head = NULL, .tail = NULL, .contents = ""};
    return node;
}

bool Node_delete(struct LList *list, const char *contents)
{
    struct Node *n = list->head;
    // while n is not null
    while (n)
    {
        // XXX: consider using strncmp
        if (strcmp(n->contents, contents) == 0)
        {
            // 1. glue head to tail
            struct Node *prev = n->head;
            struct Node *next = n->tail;

            // 2. free n
            // TODO: if string heap allocated, free it too

            return true;
        }
        n = n->tail;
    }
    return false;
}
