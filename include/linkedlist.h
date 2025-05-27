#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

struct Node
{
    struct Node *head;
    struct Node *tail;
    // TODO does order matter?
    const char *contents;
};

struct LList
{
    struct Node *head;
    struct Node *tail;
};

struct Node *
Node_init();
void Node_insert(struct LList *, const char *);
struct Node *Node_find(struct LList *, const char *);
bool Node_delete(struct LList *, const char *);

#endif // LINKEDLIST_H