//
// Created by YuKung on 2022/12/25.
//

#include "CCollectionStationOperation.h"
#include "CCollectionPoint.h"
#include <random>

using namespace std;

int CCollectionStationOperation::ordinaryPersonCount = 0;
int CCollectionStationOperation::policeCount = 0;
int CCollectionStationOperation::totalCount = 0;
int CCollectionStationOperation::acquisitionSpeed = 5;
int CCollectionStationOperation::ordinaryPointCount = 0;


std::vector<CPeople*> CCollectionStationOperation:: GeneratePeople(int GenerateNum, std::vector<CPeople*> &peoplePerMin)   // vector类型是基类指针用来存储每分钟产生的两种People的指针
{
    static default_random_engine engine;      // 将随机数引擎设置为静态的，确保每次运行函数产生的数来自同一个随机数引擎的不同序列
    bool IsPolice[GenerateNum];
    for (int i = 0; i < GenerateNum; ++i) {
        bernoulli_distribution IsPoliceBool(0.15);    // 伯努利试验,因为警察相比普通人肯定更少，所以p我们不妨设为0.15（经试验该概率不会造成警察和普通人排队拥挤）
        IsPolice[i] = IsPoliceBool(engine);           // 将每次的布尔值记录下来
    }
    for (int i = 0; i < GenerateNum; ++i) {                                 // 生成两种people
        uniform_int_distribution<int> id(100000,200000);            // 利用均匀分布生成ID号，范围在100000~200000之间
        uniform_int_distribution<int> age(1,150);                   // 利用均匀分布生成年龄，范围在1~150之间
        bernoulli_distribution isMale(0.5);                         // 生成判断性别的布尔值 两种性别等概率
        if (IsPolice[i] == 0){                                      //  如果不是警察
            auto *ordinaryPerson = new COrdinaryPerson(id(engine),isMale(engine),age(engine));
            peoplePerMin.push_back(ordinaryPerson);                     // 将生成的对象指针存储
            // delete ordinaryPerson;
            ordinaryPersonCount++;
            totalCount++;
        }
        else if (IsPolice[i] == 1){         // 如果生成的是警察
            uniform_int_distribution<int> policeNumber(1000,2000);  // 均匀整数分布生成警号
            auto  *police = new CPolice(id(engine),isMale(engine),age(engine),policeNumber(engine));
            peoplePerMin.push_back(police);
            // delete police;
            policeCount++;
            totalCount++;
        }
    }
    return peoplePerMin;    // 将所有的对象指针都存在数组中返回
}


int CCollectionStationOperation:: FindTheShortestQueue(std::vector<COrdinaryPoint*> ordinaryPoints, int min){
    for (int i = 0; i < ordinaryPoints.size(); ++i) {           // 遍历所有的ordinaryPoints
        if (ordinaryPoints[i]->queue.size() < ordinaryPoints[min]->queue.size() ){    // 若该ordinaryPoint人更少则更新min
            min = i;
        }
    }
    return min;
};

void CCollectionStationOperation::AddOneNewPoint(std::vector<COrdinaryPoint*> &ordinaryPoints){
    auto ordinaryPoint = new COrdinaryPoint;
    ordinaryPoints.push_back(ordinaryPoint);
};


void CCollectionStationOperation::PrintQueueInfoAndPop(std::vector<COrdinaryPoint*> &ordinaryPoints,std::vector<CDedicatedPoint*> &dedicatedPoints){
    for (int j = 0; j < ordinaryPoints.size(); ++j) {                           // 对于所有的ordinaryPoints
        ordinaryPoints[j]->printfInfo(j);                                // 打印当前检测点排队信息
        if (ordinaryPoints[j]->queue.size() > acquisitionSpeed){                // 若排队人数大于速度（这里是5人)
            for (int k = 0; k < acquisitionSpeed; ++k) {                       // 则出队相应的人数
                ordinaryPoints[j]->queue.pop();
            }
        }
        else                                                                 // 排队人数暂时小于每分钟能做的人数
        {
            while (!ordinaryPoints[j]->queue.empty()){                      // 则将该队列置空
                ordinaryPoints[j]->queue.pop();
            }
        }
    }

    // 对于警察排队的dedicatedPoints
    dedicatedPoints[0]->printfInfo(0);                             // 打印当前检测点的排队信息
    if (dedicatedPoints[0]->queue.size() > acquisitionSpeed){           // 和上面同理
        for (int k = 0; k < acquisitionSpeed; ++k) {
            dedicatedPoints[0]->queue.pop();
        }
    }
    else
    {
        while (!dedicatedPoints[0]->queue.empty()){
            dedicatedPoints[0]->queue.pop();
        }
    }
}