//
// Created by pzdf on 2021/3/4.
//

#ifndef MYXPLAY_IDEMUX_H
#define MYXPLAY_IDEMUX_H

#include "XData.h"
#include "XThread.h"
#include "IObserver.h"

class IDemux: public IObserver {
public:
    //打开文件，或者流媒体 rmtp http rtsp
    virtual bool Open(const char *url) = 0;
    //seek 位置 pos 0.0~1.0
    virtual bool Seek(double pos) = 0;
    virtual void Close() = 0;
//    //获取视频参数
//    virtual XParameter GetVPara() = 0;
//
//    //获取音频参数
//    virtual XParameter GetAPara() = 0;

    //读取一帧数据，数据由调用者清理
    virtual XData Read() = 0;

    //总时长（毫秒）
    int totalMs = 0;
protected:
    virtual void Main();
};


#endif //MYXPLAY_IDEMUX_H
