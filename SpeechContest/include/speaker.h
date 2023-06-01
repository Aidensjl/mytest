#pragma once
#include "iostream"
#include "stdlib.h"

using namespace std;

class Speaker
{
public:
    // 参赛人员
    Speaker();

    ~Speaker();

    string m_name;
    double m_score[2]={0.0,0.0}; // 比赛两轮
};