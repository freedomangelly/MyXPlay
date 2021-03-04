//
// Created by pzdf on 2021/3/4.
//

#ifndef MYXPLAY_IDEMUX_H
#define MYXPLAY_IDEMUX_H

#include "XData.h"


class IDemux {
    //打开文件或者流媒体
virtual bool Open(const char *url) = 0;
    //读取一帧数据，数据由调用者清理，这块空间是需要清理的
virtual XData Read() = 0;
};



#endif //MYXPLAY_IDEMUX_H
