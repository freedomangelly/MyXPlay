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
    this->totalMs=ic->duration/(AV_TIME_BASE/1000);
    LOGI("total ms = %d!",totalMs);

    return true;
}
//获取视频参数
XParameter FFDemux::GetVPara()
{
    mux.lock();
    if (!ic) {
        mux.unlock();
        LOGI("GetVPara failed! ic is NULL！");
        return XParameter();
    }
    //获取了视频流索引
    int re = av_find_best_stream(ic, AVMEDIA_TYPE_VIDEO, -1, -1, 0, 0);
    if (re < 0) {
        mux.unlock();
        LOGI("av_find_best_stream failed!");
        return XParameter();
    }
    videoStream = re;
    XParameter para;
    para.para = ic->streams[re]->codecpar;
    mux.unlock();
    return para;
}
//获取音频参数
XParameter FFDemux::GetAPara()
{
    mux.lock();
    if (!ic) {
        mux.unlock();
        LOGI("GetVPara failed! ic is NULL！");
        return XParameter();
    }
    //获取了音频流索引
    int re = av_find_best_stream(ic, AVMEDIA_TYPE_AUDIO, -1, -1, 0, 0);
    if (re < 0) {
        mux.unlock();
        LOGI("av_find_best_stream failed!");
        return XParameter();
    }
    audioStream = re;
    XParameter para;
    para.para = ic->streams[re]->codecpar;
    para.channels = ic->streams[re]->codecpar->channels;
    para.sample_rate = ic->streams[re]->codecpar->sample_rate;
    mux.unlock();
    return para;
}

XData FFDemux::Read(){
    if(!ic)return XData();
    XData d;

    AVPacket  *pkt=av_packet_alloc();
    int re = av_read_frame(ic,pkt);
    if(re != 0 ){
        av_packet_free(&pkt);
        return XData();
    }
    LOGI("pack size is %d ptss %lld",pkt->size,pkt->pts);
    d.data=pkt->data;
    d.size=pkt->size;
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
