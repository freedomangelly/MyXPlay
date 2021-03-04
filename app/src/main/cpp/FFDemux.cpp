//
// Created by pzdf on 2021/3/4.
//

#include "FFDemux.h"
#include "XLog.h"
extern "C"{
#include <libavformat/avformat.h>
}

bool FFDemux::Open(const char* url){
    LOGI("Open File %s ",url);

    int re = avformat_open_input(&ic,url,0,0);

    if(re!=0){
        char buf[1024] = {0};
        av_strerror(re,buf,sizeof(buf));
        LOGE("FFDemux open file %s ",url);
        return false;
    }

    return true;
}

XData FFDemux::Read(){
    XData d;
    return d;
}

FFDemux::FFDemux() {
    static bool isFirst = true;
    if(isFirst){
        isFirst = false;
        //注册解封装起
        av_register_all();
        //注册解码器
        avcodec_register_all();
        //初始化网络
        avformat_network_init();
    }
}
