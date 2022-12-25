#include <iostream>
#include <random>
#include <vector>
#include <thread>
#include "CPeople.h"
#include "CCollectionPoint.h"
#include "CCollectionStationOperation.h"

using namespace std;

int main() {
    int simulation = 0;
    while (true){
        cout << "/***This is a program which simulates the queues of a collection station conducts nucleic acid collection for 30 minutes***/" << endl;
        cout << "/***Please enter any number (except 0) to conduct one stimulation and enter 0 to end the program***/" <<endl;
        int flag;
        cin >> flag;
        switch (flag) {
            case 0: {
                cout << "\nGoodbye！You have conducted " << simulation << " simulation(s) in total!" << endl;
                exit(0);
            };
            default:{
                simulation++;
                cout << "\n************************" << "Start of the NO." << simulation << " stimulation***************************" << endl;
                cout<<"\n\n"<<endl;

                int min = 0;       // min用来传递给FindTheShortestQueue函数 用来存储当前人数最少的ordinaryPoint在ordinaryPoints中的下标

                vector<COrdinaryPoint*> ordinaryPoints;             // 用一个ordinaryPoints类指针类型的vector存储ordinaryPoint
                auto firstOrdinaryPoint= new COrdinaryPoint;        // 初始化一个ordinaryPoint，每个COrdinaryPoint类对象都含有一个queue成员，被STL相关函数自动初始化为空
                ordinaryPoints.push_back(firstOrdinaryPoint);       // 将初始化的ordinaryPoint添加到ordinaryPoints中
                CCollectionStationOperation::ordinaryPointCount++;

                vector<CDedicatedPoint*> dedicatedPoints;           // 和上面同理，这里是存储给警察做测试的dedicatedPoint
                auto firstDedicatedPoint = new CDedicatedPoint;     //  (实际上我们只在里面存一个dedicatedPoint，这样做是为了操作统一和普适性)
                dedicatedPoints.push_back(firstDedicatedPoint);

                for (int i = 0; i < 30; ++i) {                      // 循环1次代表1分钟的情况，30次模拟总共30分钟的的情况

                    cout << "================"<< "This is the NO." << i+1 << " minutes of the total 30 minutes" << "================\n" << endl;
                    cout << "~~~~~~~~~Now there are " << CCollectionStationOperation::ordinaryPointCount << " ordinary points and 1 dedicated point in total~~~~~~~~~" << endl;
                    vector<CPeople*> peoplePerMin;         // peoplePerMin这个基类指针类型vector用来存储COrdinaryPerson和CPolice这两个派生类  多态！！！

                    int generateNum;
                    static default_random_engine engine;
                    uniform_int_distribution<int> numGenerator(10,50);        // generateNum的范围是1~50
                    generateNum = numGenerator(engine);                  // 我们这里借助random库中的整数均匀分布类来生成generateNum，用来模拟每分钟来做核酸的人数不同

                    CCollectionStationOperation::GeneratePeople(generateNum,peoplePerMin);   // GeneratePeople一次性生成总共
                                                                                                             // generateNum个COrdinaryPerson和CPolice类对象，并且存储到peoplePerMin中
                    // 每分钟先将生成的人数全部分配给相应的检测点
                    for (int j = 0; j < generateNum; ++j) {       // 这里一次循环将一个人分配到相应的检测点一次
                        if (peoplePerMin[j]->GetClassType() == "Police"){           // 若该人的身份为警察
                            dedicatedPoints[0]->queue.push((peoplePerMin[j]));  // 将所有的警察都分配到唯一的特殊检测点 队列中存储的是基类指针！！！ 因为使用了多态要这样才能编译通过
                        }
                        else if (peoplePerMin[j]->GetClassType() == "Ordinary Person"){     // 若该人的身份为普通人

                            min = CCollectionStationOperation::FindTheShortestQueue(ordinaryPoints, min);        // 查询当前排队人数最少的ordinaryPoint的队列
                            ordinaryPoints[min]->queue.push(peoplePerMin[j]);                               // 将该普通人分配到当前人数最少的ordinaryPoint
                            min = CCollectionStationOperation::FindTheShortestQueue(ordinaryPoints, min);      // 更新min
                            if (ordinaryPoints[min]->queue.size() > 9){                         // 若所有的队列人数都满了10人（等价于人数最少的队列突破10人）
                                CCollectionStationOperation::AddOneNewPoint(ordinaryPoints);    // 添加一个新的ordinaryPoint
                                CCollectionStationOperation::ordinaryPointCount++;
                            }
                        }
                    }

                    CCollectionStationOperation::PrintQueueInfoAndPop(ordinaryPoints,dedicatedPoints);  // 打印该分钟所有的队列信息以及删除掉以及做完核酸的人数

                    cout << "\n============"<< "This is the end of NO." << i+1 << " minutes of the total 30 minutes" << "=============" << endl;
                    cout<<"\n\n\n\n"<<endl;
                }
                cout << "****************************" << "End of the NO." << simulation << " simulation***************************" << endl;
                cout<<"\n\n\n\n"<<endl;
            }

        }

    }

}

