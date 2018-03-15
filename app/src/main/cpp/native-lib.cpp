#include <jni.h>
#include <string>
#include "mylog.h"
#include "linkedlist.h"


extern "C" void testLinkedList();

extern "C"
JNIEXPORT jstring


JNICALL
Java_com_zhumingren_reverselinkedlistdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    testLinkedList();

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

