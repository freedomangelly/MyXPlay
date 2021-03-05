#include <jni.h>
#include <string>
#include "IDemux.h"
#include "FFDemux.h"
#include "XLog.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_liuy_myxplay_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

class TestObs:public IObserver
{
public:
    void Update(XData d)
    {
        LOGI("TestObs Update data size is %d",d.size);
    }
};



extern "C"
JNIEXPORT jstring

JNICALL
Java_xplay_xplay_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    //XLOGI("S begin!");
    //XSleep(3000);
    //XLOGI("S end!");
    //return env->NewStringUTF(hello.c_str());

    ///////////////////////////////////
    ///测试用代码
    TestObs *tobs = new TestObs();
    IDemux *de = new FFDemux();
    de->AddObs(tobs);
    de->Open("/sdcard/1080.mp4");
    de->Start();
    XSleep(3000);
    de->Stop();
    /*for(;;)
    {
        XData d = de->Read();
        XLOGI("Read data size is %d",d.size);


    }*/

    return env->NewStringUTF(hello.c_str());
}