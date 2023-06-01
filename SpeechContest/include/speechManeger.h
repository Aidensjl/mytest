#pragma once
#include "iostream"
#include "vector"
#include "map"
#include "deque"
#include "algorithm"
#include "numeric"
#include "speaker.h"
#include "iomanip"
#include "fstream"

using namespace std;

// 设计演讲者管理类
class SpeachManager
{
public:
    // 构造函数,只要声明,实现在cpp中
    SpeachManager();
    // 展示界面
    void show_Menu();
    // 退出
    void exit_sys();

    // 按按任意键继续
    void hold();

    // 输入有误
    int return_res(string &s);

    // 创建选手
    void creat_speaker();

    // 选手初始化
    void speaker_init();

    // 比赛总流程框架
    void speech();
    // 开始抽签
    void speech_choose();

    // 开始比赛
    void start_speech();

    // 显示晋级信息
    void show_winspeaker();

    // 显示保存的信息
    void show_record();

    // 保存分数
    void saveRecord();

    // 加载分数
    void loadRecord();

    // 判断文件是否为空
    bool fileIsempty;

    // 追加数据的换行符
    bool flag=false;

    // 存放往届记录
    map<int,vector<string>> m_Record;

    // 清空记录
    void clearcvsfile();

    // 析构函数,只要声明,实现在cpp中
    ~SpeachManager();
    // 成员属性
    // 第一轮编号
    vector<int> v1;

    // 第一轮晋级选手
    vector<int> v2;

    // 胜出的前三名
    vector<int> vVictory;

    // 存放编号和选手
    map<int, Speaker> m_speaker;

    // 记录轮数
    int m_index = 1;
};