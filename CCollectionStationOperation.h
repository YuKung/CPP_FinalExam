//
// Created by YuKung on 2022/12/25.
//

#ifndef FINALEXAM_CCOLLECTIONSTATIONOPERATION_H
#define FINALEXAM_CCOLLECTIONSTATIONOPERATION_H

#include <vector>
#include "CCollectionPoint.h"

/* 该类封装了整个核酸检测站所需要的一些操作及静态变量 */

class CCollectionStationOperation {
    public:
    static int ordinaryPersonCount;            // 用以统计每个相应队列排队普通人的数量
    static int policeCount;                      // 用以统计每个相应队列排队警察的数量
    static int totalCount;                      // 统计所有队列排队的总数
    static int acquisitionSpeed;              // 每个核酸站点每分钟的检测速度
    static int ordinaryPointCount;            // 当前所具有的普通检测点的总数
    static std::vector<CPeople*> GeneratePeople(int GenerateNum, std::vector<CPeople*> &peoplePerMin);    // 该函数用来生成每分钟来排队的人
    static int FindTheShortestQueue(std::vector<COrdinaryPoint*> ordinaryPoints, int min);   // 该函数用来寻找队列最短的普通检测点
    static void AddOneNewPoint(std::vector<COrdinaryPoint*> &ordinaryPoints);       // 该函数用来添加一个普通检测点
    static void PrintQueueInfoAndPop(std::vector<COrdinaryPoint*> &ordinaryPoints,std::vector<CDedicatedPoint*> &dedicatedPoints);  // 该函数用来打印所有检测点的队列信息并且删除已经做完核酸的人
};

#endif //FINALEXAM_CCOLLECTIONSTATIONOPERATION_H