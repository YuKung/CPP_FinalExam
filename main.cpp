#include <iostream>
#include <random>
#include <vector>
#include <thread>
#include "CPeople.h"
#include "CCollectionStation.h"

#define ACQUISITION_SPEED_PER_MIN 5;

using namespace std;

int policeCount = 0, OrdinaryPersonCount = 0, totalCount = 0;  // 计数的全局变量

vector<CPeople*> GeneratePeople(int GenerateNum, vector<CPeople*> &peoplePerMin);    // 用来生成每分钟的人
int findTheShortestQueue(vector<COrdinaryPoint*> ordinaryPoints);
void addOneNewPoint();
// void GeneratePoints();

int main() {
    vector<COrdinaryPoint*> ordinaryPoints;             // 用一个类指针vector存储同一类检测点，并各初始化一个检测点queue的STL会被自动初始化为空
    auto firstOrdinaryPoint= new COrdinaryPoint;
    ordinaryPoints.push_back(firstOrdinaryPoint);

    vector<CDedicatedPoint*> dedicatedPoints;           // 同上
    auto firstDedicatedPoint = new CDedicatedPoint;
    dedicatedPoints.push_back(firstDedicatedPoint);

    for (int i = 0; i < 30; ++i) {         // 30循环30次代表30分钟
        // sleep！
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));    // 阻塞线程 使屏幕每秒输出有间隔
        vector<CPeople*> peoplePerMin;
        int generateNum;                      // 控制每分钟生成的人数
        static default_random_engine engine;
        uniform_int_distribution<int> numGenerator(10,50);
        generateNum = numGenerator(engine);
        GeneratePeople(generateNum,peoplePerMin);

        // 每分钟先将生成的人数全部分配给相应的检测点
        for (int j = 0; j < generateNum; ++j) {       // 这里一次循环分配一个待排队的人
            if (peoplePerMin[j]->GetClassType() == "Police"){
                dedicatedPoints[0]->queue.push((peoplePerMin[j]));      // 将所有的警察都分配到第一个特殊检测点 队列中存储的是人的指针！！！ 因为使用了多态要这样才能编译通过
            }
            else if (peoplePerMin[j]->GetClassType() == "Ordinary Person"){
                int min = 0;
                min = findTheShortestQueue(ordinaryPoints);// sort返回人最少的平民站的下标 ,min
                // if ordinaryPoints[min].size > 10; add new 向新的站中加
                ordinaryPoints[min]->queue.push((peoplePerMin[j]));       // 将所有普通人分配到第一个普通检测点   ！！！ 后面会动态优化！！！
            }
        }


        for (int j = 0; j < ordinaryPoints.size(); ++j) {                           // 每分钟每个站排完队五个人
            ordinaryPoints[j]->printfInfo(j);                                // 平民打印当前排队信息
            // Point.queue.pop() 5次
        }

        dedicatedPoints[0]->printfInfo(0);

    }
    return 0;
}

vector<CPeople*> GeneratePeople(int GenerateNum, vector<CPeople*> &peoplePerMin)    // vector类型是基类指针用来存储每分钟产生的两种People的指针
{
    static default_random_engine engine;      // 将随机数引擎设置为静态的，确保每次运行函数产生的数来自同一个随机数引擎的不同序列
    bool IsPolice[GenerateNum];
    for (int i = 0; i < GenerateNum; ++i) {
        bernoulli_distribution IsPoliceBool(0.2);    // 伯努利试验,因为警察相比普通人肯定更少，所以p我们不妨设为0.3
        IsPolice[i] = IsPoliceBool(engine);           // 将每次的布尔值记录下来
    }
    for (int i = 0; i < GenerateNum; ++i) {                                 // 生成两种people
        uniform_int_distribution<int> id(100000,200000);            // 利用均匀分布生成ID号，范围在100000~200000之间
        uniform_int_distribution<int> age(1,150);                   // 利用均匀分布生成年龄
        bernoulli_distribution isMale(0.5);                         // 生成判断性别的布尔值
        if (IsPolice[i] == 0){                                      //  如果不是警察
            auto *ordinaryPerson = new COrdinaryPerson(id(engine),isMale(engine),age(engine));
            peoplePerMin.push_back(ordinaryPerson);                     // 将生成的对象指针存储
            // delete ordinaryPerson;
            OrdinaryPersonCount++;
            totalCount++;
        }
        else if (IsPolice[i] == 1){
            uniform_int_distribution<int> policeNumber(1000,2000);  // 生成警号
            auto  *police = new CPolice(id(engine),isMale(engine),age(engine),policeNumber(engine));
            peoplePerMin.push_back(police);
            // delete police;
            policeCount++;
            totalCount++;
        }
    }
    return peoplePerMin;
}


int findTheShortestQueue(vector<COrdinaryPoint*> ordinaryPoints){
    int min = 0;   // min代表人最少的ordinaryPoint的下标
    for (int i = 0; i < ordinaryPoints.size(); ++i) {           // 遍历所有的ordinaryPoints
        if (ordinaryPoints[i]->queue.size() < ordinaryPoints[min]->queue.size() ){    // 若该ordinaryPoint人更少则更新min
            min = i;
        }
    }
    return min;
};

void addOneNewPoint(){

};