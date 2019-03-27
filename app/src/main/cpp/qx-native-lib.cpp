#include <jni.h>

#include <unistd.h>
#include <malloc.h>
#include <android/log.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>

struct test_data
{
    char name[256];
    int  num;
    double average;
    bool revb;
    char text[256];
};



extern "C" JNIEXPORT jobject  JNICALL
Java_com_getcharmsmart_testjniobject_MainActivity_call(JNIEnv * env, jobject obj, jobject classobj)
{
    jclass objectClass = env->FindClass("com/getcharmsmart/testjniobject/test_data");

    jfieldID name = env->GetFieldID(objectClass, "name", "Ljava/lang/String;");
    jfieldID num = env->GetFieldID(objectClass, "num", "I");
    jfieldID average = env->GetFieldID(objectClass, "average", "D");
    jfieldID revb = env->GetFieldID(objectClass, "revb", "Z");
    jfieldID text = env->GetFieldID(objectClass, "text", "[B");


    env->SetObjectField(classobj, name, env->NewStringUTF("hello world"));
    env->SetIntField(classobj, num, 10);
    env->SetDoubleField(classobj, average, 2.5);
    env->SetBooleanField(classobj, revb, false);



    jbyte a[] = {1,2,3,4,5,6};
    jbyteArray ret = env->NewByteArray(6);


    int len = 6;
    if (len > 0) {

        env->SetByteArrayRegion (ret, 0, 6, a);

        jbyte * tempData = env->GetByteArrayElements(ret, 0);
     //   memcpy(tempData, text, len);
        env->ReleaseByteArrayElements(ret, tempData, 0);
        env->SetObjectField(classobj, text, ret);
    }


    return classobj;

}
