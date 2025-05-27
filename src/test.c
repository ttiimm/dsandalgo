#include <assert.h>
#include <stdio.h>
// use quotes for local headers
#include "linkedlist.h"

void test_init()
{
    struct Node *node = Node_init();
    assert(node->head == NULL);
    // printf("head = %zx\n", (size_t)node->head);
    // printf("tail = %zx\n", (size_t)node->tail);
    // printf("contents = %s\n", node->contents);
}

void test_delete()
{
    struct Node *node = Node_init();
    struct LList list = (struct LList){
        .head = node, .tail = node};
    assert(Node_delete(&list, ""));
}

int main(void)
{
    test_init();
    test_delete();
    printf("tests passed\n");
    return 0;
}