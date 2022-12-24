#include <iostream>
#include <random>
#include <vector>
#
#include "CPeople.h"
#include "CCollectionStation.h"

using namespace std;

int policeCount = 0, OrdinaryPersonCount = 0, totalCount = 0;  // 计数的全局变量

vector<CPeople*> GeneratePeople(int GenerateNum, vector<CPeople*> &peoplePerMin);
void GenratePoints();

int main() {
    vector<CPeople*> peoplePerMin;
    GeneratePeople(20,peoplePerMin);
    /*for (int i = 0; i < 20; ++i) {
        // cout << peoplePerMin[i]->age << endl;
        //cout << typeid(*peoplePerMin[i]).name() << endl;
        cout << peoplePerMin[i]->GetClassType() << endl;
    }*/

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
    for (int i = 0; i < GenerateNum; ++i) {        // 生成两种people
        uniform_int_distribution<int> id(100000,200000);    // 利用均匀分布生成ID号，范围在100000~200000之间
        uniform_int_distribution<int> age(1,150);           // 利用均匀分布生成年龄
        bernoulli_distribution isMale(0.5);      // 生成判断性别的布尔值
        if (IsPolice[i] == 0){                  //  如果不是警察
            auto *ordinaryPerson = new COrdinaryPerson(id(engine),isMale(engine),age(engine));
            peoplePerMin.push_back(ordinaryPerson);        // 将生成的对象指针存储
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