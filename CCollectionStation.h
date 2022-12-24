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
    //virtual printinfo;
private:
};

class COrdinaryPoint:public CCollectionStation{
public:
    std::queue<CPeople> queue;

};

class CDedicatedPoint:public CCollectionStation{
public:
    std::queue<CPeople> queue;
};

#endif //FINALEXAM_CCOLLECTIONSTATION_H
