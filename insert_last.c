//
// Created by Sky Truong on 2020-03-05.
//

// This function inserts elements to the end of the list
/* Source: https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/ */

#include "decode.h"

void insert_last ( Node ** head, char main_letter ) {
    Node * new_node = malloc(sizeof(Node));
    Node * last = *head;

    /* Put in letter */
    new_node->letter = main_letter;

    /* This new_node will be the last node */
    new_node->next = NULL;

    /* If the Linked List is empty, then new node is head  */
    if ( *head == NULL ) {
        *head = new_node;
        return;
    }

    /* Else traverse until the last node */
    while ( last->next != NULL ) {
        last = last->next;
    }

    /* Change the next of the last node */
    last->next = new_node;
    return;
}