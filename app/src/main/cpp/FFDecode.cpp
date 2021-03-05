//
// Created by pzdf on 2021/3/5.
//

#include <list>
#include "IObserver.h"
#include "XParameter.h"
#include "FFDecode.h"
#include "XLog.h"

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavcodec/jni.h>
}

bool FFDecode::Open(XParameter para,bool isHard)
{
    Close();
    if(!para.para) return false;
    AVCodecParameters *p = para.para;

    //1 查找解码器
    AVCodec *cd = avcodec_find_decoder(p->codec_id);
    if(isHard)
    {
        cd = avcodec_find_decoder_by_name("h264_mediacodec");
    }

    if(!cd)
    {
        LOGI("avcodec_find_decoder %d failed!  %d",p->codec_id,isHard);
        return false;
    }
    LOGI("avcodec_find_decoder success %d!",isHard);

    mux.lock();
    //2 创建解码上下文，并复制参数
    codec = avcodec_alloc_context3(cd);
    avcodec_parameters_to_context(codec,p);

    codec->thread_count = 8;
    //3 打开解码器
    int re = avcodec_open2(codec,0,0);
    if(re != 0)
    {
        mux.unlock();
        char buf[1024] = {0};
        av_strerror(re,buf,sizeof(buf)-1);
        LOGI("%s",buf);
        return false;
    }

//    if(codec->codec_type == AVMEDIA_TYPE_VIDEO)
//    {
//        this->isAudio = false;
//    }
//    else
//    {
//        this->isAudio = true;
//    }
//    mux.unlock();
//    XLOGI("avcodec_open2 success!");
    return true;
}