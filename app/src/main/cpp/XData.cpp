//
// Created by pzdf on 2021/3/4.
//

extern "C"{
#include <libavcodec/avcodec.h>
}

#include "XData.h"

bool XData::Alloc(int size,const char *d)
{
    Drop();
    type = UCHAR_TYPE;
    if(size <=0)return false;
    this->data = new unsigned char[size];
    if(!this->data) return false;
    if(d)
    {
        memcpy(this->data,d,size);
    }
    this->size = size;
    return true;
}
void XData::Drop()
{
    if(!data) return;
    if(type == AVPACKET_TYPE)
        av_packet_free((AVPacket **)&data);
    else
        delete data;
    data = 0;
    size = 0;
}