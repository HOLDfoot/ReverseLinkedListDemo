//
// Created by Zhu Mingren on 2018/3/15.
//
#include "linkedlist.h"
#include <jni.h>
#include "mylog.h"
#include <malloc.h>

void testLinkedList() {
    LOGD("testLinkedList");
    struct Node
    {
        int id;
        struct Node *next;
    };

    struct Node node0 = {
            .id = 0,
            .next = NULL
    };
    struct Node *head = &node0;
    struct Node *tempNext = head;
    for (int i = 1; i < 4; i++) {
        struct Node *node = (struct Node*) malloc(sizeof(struct Node));
        node->id = i;
        node->next = NULL;
        LOGD("node init i = %d", node->id);
        if (node->next != NULL) {
            LOGE("node node = %d", node->id);
        } else {
            LOGE("node node->next = null");
        }

        tempNext->next = node;
        if (node->next != NULL) {
            LOGD("node node = %d", node->id);
            LOGE("node node.next->id = %d", node->next->id);
        } else {
            LOGD("node node->next = null");
        }

        tempNext = node;

        if (tempNext->next != NULL) {
            LOGD("node tempNext = %d", tempNext->id);
        } else {
            LOGD("node tempNext->next = null");
        }
        LOGE("node get i = %d", node->id);
    }

    struct Node *tempPoint = head;
    while (tempPoint != NULL) {
        LOGD("tempPoint node i = %d", tempPoint->id);
        tempPoint = tempPoint->next;
    }
}
