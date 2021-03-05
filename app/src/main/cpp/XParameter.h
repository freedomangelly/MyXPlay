//
// Created by pzdf on 2021/3/5.
//

#ifndef MYXPLAY_XPARAMETER_H
#define MYXPLAY_XPARAMETER_H

struct AVCodecParameters;
class XParameter {

public:
    AVCodecParameters *para = 0;
    int channels = 2;
    int sample_rate = 44100;
};


#endif //MYXPLAY_XPARAMETER_H
