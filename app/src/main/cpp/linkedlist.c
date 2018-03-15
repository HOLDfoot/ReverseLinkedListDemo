//
// Created by Zhu Mingren on 2018/3/15.
//
#include "linkedlist.h"
#include <jni.h>
#include "mylog.h"

void testLinkedList() {
    LOGD("testLinkedList");
    struct Node
    {
        int id;
        struct Node *next;
    };

    struct Node node = {
            .id = 0,
            .next = NULL
    };
    struct Node *head = &node;
    struct Node *tempNext = head;
    for (int i = 1; i < 4; i++) {
        struct Node node = {
                .id = i,
                .next = NULL
        };

        struct Node *next = &node;

        tempNext->next = next;

        tempNext = next;
    }



}
