//
// Created by pzdf on 2021/3/4.
//

#ifndef MYXPLAY_XDATA_H
#define MYXPLAY_XDATA_H



enum XDataType
{
    AVPACKET_TYPE = 0,
    UCHAR_TYPE = 1
};


struct XData
{
    int type = 0;
    int pts = 0;
    unsigned char *data = 0;
    unsigned char *datas[8] = {0};
    int size = 0;
    bool isAudio = false;
    int width = 0;
    int height = 0;
    int format = 0;
    bool Alloc(int size,const char *data=0);
    void Drop();
};



#endif //MYXPLAY_XDATA_H
