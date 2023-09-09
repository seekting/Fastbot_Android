#include <fstream>
#include <asm/fcntl.h>
#include <fcntl.h>
#include <unistd.h>
#include <thread>
#include "jni.h"
#include "android/log.h"

#include "android/log.h"
#include "pthread.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/prctl.h>
#include <sys/resource.h>
using std::string;
using std::fstream;
using std::ios;
std::string str_file_path = "";
#define CLASS com_seekting_jni_NativeHandler
#define NAME3(CLASS3, FUNC3) Java_##CLASS3##_##FUNC3
#define NAME2(CLASS2, FUNC2) NAME3(CLASS2, FUNC2)
#define NAME(FUNC) NAME2(CLASS, FUNC)

extern "C" {
#define LOG_TAG "MyNDK"
#define LOGD(format, ...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, format, ##__VA_ARGS__)

void test() {
  int num = 20;
  LOGD("The num is %d", num);
}
void *set_thread_priority(void *p) {
  prctl(PR_SET_NAME, "koom-looper");
  setpriority(PRIO_PROCESS, gettid(), -20);
  for (int i = 0; i < 1000; i++) {
    sleep(1);
    if (i % 2 == 1) {
      setpriority(PRIO_PROCESS, gettid(), -11);
    } else {
      setpriority(PRIO_PROCESS, gettid(), -19);
    }
    LOGD("The num is %d %d", gettid(), getpriority(PRIO_PROCESS,gettid()));
  }
  return nullptr;
}
void startThread() {
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_t worker;
  pthread_create(&worker, &attr, set_thread_priority, nullptr);
}
JNIEXPORT jlong JNICALL
NAME(test)(JNIEnv *env, jclass clazz, jstring file_path) {
  const char *file_path_char = env->GetStringUTFChars(file_path, (jboolean *) JNI_FALSE);
  str_file_path = file_path_char;
//  StartWrite();
  env->ReleaseStringUTFChars(file_path, file_path_char);
//  NativeThreadWrite();
  startThread();
  return 1;

}

}