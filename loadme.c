#include "jni.h"

char* some_function() {
	return "Hello World";
}


jint JNI_OnLoad(JavaVM *vm, void *reserved) {

	some_function();

	return JNI_VERSION_1_6;
}
