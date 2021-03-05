//
// Created by pzdf on 2021/3/5.
//

#ifndef MYXPLAY_FFDECODE_H
#define MYXPLAY_FFDECODE_H


#include "IDecode.h"

struct AVCodecContext;
struct AVFrame;
class FFDecode:public IDecode
{
public:
    static void InitHard(void *vm);

    virtual bool Open(XParameter para,bool isHard=false);
    virtual void Close();
    virtual void Clear();
    //future模型 发送数据到线程解码
    virtual bool SendPacket(XData pkt);

    //从线程中获取解码结果，再次调用会复用上次空间，线程不安全
    virtual XData RecvFrame();

protected:
    AVCodecContext *codec = 0;
    AVFrame *frame = 0;
    std::mutex mux;
};

#endif //MYXPLAY_FFDECODE_H
