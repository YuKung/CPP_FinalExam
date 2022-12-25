//
// Created by YuKung on 2022/12/24.
//

/* 该头文件包含表示普通检测点的COrdinaryPoint类和表示特殊检测点的CDedicatedPoint类，以及他们的基类CCollectionPoint*/

#ifndef FINALEXAM_CCOLLECTIONPOINT_H
#define FINALEXAM_CCOLLECTIONPOINT_H

#include <queue>
#include "CPeople.h"

class CCollectionPoint {
public:
    CCollectionPoint();
    ~CCollectionPoint();
    virtual void printfInfo(int index);     // 用来打印相应检测点此刻的队列信息
};

class COrdinaryPoint:public CCollectionPoint{
public:
    std::queue<CPeople*> queue;  // 因为每分钟生成的排队的人被存储在同一个基类指针数组中，这里queue类型定义为基类指针是为了排队的人能够正常入队，不然编译不通过！！！ 编译时多态
    void printfInfo(int index) override;

};


class CDedicatedPoint:public CCollectionPoint{
public:
    std::queue<CPeople*> queue;
    void printfInfo(int index) override;
};



#endif //FINALEXAM_CCOLLECTIONPOINT_H
