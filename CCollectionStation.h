//
// Created by YuKung on 2022/12/24.
//

#ifndef FINALEXAM_CCOLLECTIONSTATION_H
#define FINALEXAM_CCOLLECTIONSTATION_H

#include <queue>
#include "CPeople.h"


class CCollectionStation {
public:
    CCollectionStation();
    ~CCollectionStation();
    const int acquisitionSpeed=5;
    virtual void printfInfo(int index);
};

class COrdinaryPoint:public CCollectionStation{
public:
    std::queue<CPeople*> queue;  // 因为每分钟生成的排队的人被存储在同一个基类指针数组中，这里queue类型定义为基类指针是为了排队的人能够正常入队，不然编译不通过！！！ 编译时多态
    virtual void printfInfo(int index);
};

class CDedicatedPoint:public CCollectionStation{
public:
    std::queue<CPeople*> queue;
    virtual void printfInfo(int index);
};

#endif //FINALEXAM_CCOLLECTIONSTATION_H
