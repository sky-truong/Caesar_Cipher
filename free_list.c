//
// Created by Sky Truong on 2020-03-05.
//

// This function frees the linked list

#include "decode.h"

void free_list ( Node * head ) {
    Node * new_head = head, * old_node = NULL;
    while ( new_head != NULL ) {
        old_node = new_head;
        new_head = new_head->next;
        free(old_node);
    }
}