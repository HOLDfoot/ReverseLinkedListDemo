//
// Created by Zhu Mingren on 2018/3/15.
//
#include "linkedlist.h"
#include <jni.h>
#include "mylog.h"
#include <malloc.h>

struct Node
{
    int id;
    struct Node *next;
};

void printLinkedList(struct Node *tempPoint);
struct Node* reverseLikedList(struct Node *head);

void testLinkedList() {
    LOGD("testLinkedList");

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

        tempNext->next = node;

        tempNext = node;
    }

    printLinkedList(head);

    struct Node *newHead = reverseLikedList(head);
    printLinkedList(newHead);
}

void printLinkedList(struct Node *tempPoint) {
    while (tempPoint != NULL) {
        LOGD("tempPoint node i = %d", tempPoint->id);
        tempPoint = tempPoint->next;
    }
}

struct Node* reverseLikedList(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node *pre, *cur, *ne;
    pre = head;
    cur = head->next;
    while (cur) {
        ne = cur->next; //保存会更改的变量

        cur->next = pre; //更改

        //设置新的状态
        pre = cur; // 移动下一个指向的变量
        cur = ne; // 保存的下一个节点会变成新的节点
    }

    head->next = NULL;
    head = pre;

    return head;
}

/*

 struct Node* reverseLikedList(struct Node *head) {
    struct Node *tail;

    struct Node *tempNode = head;
    struct Node *nextNode = tempNode->next;
    struct Node *nextNextNode;
    tempNode->next = NULL; // 第一个变成最后一个后next需要置空

    int i = 0;
    while (nextNode != NULL) {
        i++;
        nextNextNode = nextNode->next; // may be null
        if (nextNextNode == NULL) {
            tail = nextNode;
        }

        nextNode->next = tempNode;

        tempNode = nextNode;
        nextNode = nextNextNode;
        if (nextNode->next != NULL) {
            LOGD("node nextNode->next = %d", nextNode->next->id);
        } else {
            LOGD("node nextNode->next = null");
        }
        LOGE("node nextNode %d = %d", i, nextNode->id);
    }


    return tail;
}

 */