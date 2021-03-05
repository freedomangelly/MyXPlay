//
// Created by pzdf on 2021/3/5.
//

#ifndef MYXPLAY_IOBSERVER_H
#define MYXPLAY_IOBSERVER_H


#include "XData.h"
#include "XThread.h"
#include <vector>
#include <mutex>
class IObserver :public XThread{

    //观察者主体部分的函数
    virtual void Update(XData data){};

    //主体函数,添加观察者
    void AddObs(IObserver *obs);

public:
    void Notify(XData data);

protected:
    std::vector<IObserver *>obss;
    std::mutex mux;

};


#endif //MYXPLAY_IOBSERVER_H
