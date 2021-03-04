//
// Created by pzdf on 2021/3/4.
//

#ifndef MYXPLAY_XLOG_H
#define MYXPLAY_XLOG_H

#ifdef ANDROID
#define TAG "MY_X_PLAY_TAG"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)
#include <android/log.h>
#else

#endif

class XLog {

};




#endif //MYXPLAY_XLOG_H
