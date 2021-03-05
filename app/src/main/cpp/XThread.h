//
// Created by pzdf on 2021/3/5.
//

#ifndef MYXPLAY_XTHREAD_H
#define MYXPLAY_XTHREAD_H

void XSleep(int mis);

class XThread {
public:
    //启动线程
    virtual bool Start();

    //通过控制isExit安全停止线程（不一定成功）
    virtual void Stop();

    virtual void SetPause(bool isP);

    bool IsPause()
    {
        isPausing = isPause;
        return isPause;
    }

    //入口主函数
    virtual void Main() {}

public:
    bool isExit ;
    bool isRuning;
    bool isPause;
    bool isPausing;
private:
    void ThreadMain();
};


#endif //MYXPLAY_XTHREAD_H
