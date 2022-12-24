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
private:
};

class COrdinaryPoint:public CCollectionStation{
public:
    std::queue<COrdinaryPerson> queue;

};

class CDedicatedPoint:public CCollectionStation{
public:
    std::queue<CPolice> queue;
};

#endif //FINALEXAM_CCOLLECTIONSTATION_H
