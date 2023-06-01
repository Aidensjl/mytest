// speechManeger类的函数实现
#include "speechManeger.h"

SpeachManager::SpeachManager()
{
    this->speaker_init();
    this->creat_speaker();
}

// 初始化菜单
void SpeachManager::show_Menu()
{
    cout << "     演讲比赛" << endl;
    cout << "【1】开始演讲比赛" << endl;
    cout << "【2】查看往届记录" << endl;
    cout << "【3】清空比赛记录" << endl;
    cout << "【0】退出比赛程序" << endl;
}

// 退出
void SpeachManager::exit_sys()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}
// 按按任意键继续
void SpeachManager::hold()
{
    cout << endl;
    cout << "按任意键继续...";

    int a;
    cin >> a;
    cin.clear();
    cin.ignore(10, '\n');
}

// 输入有误c_str()是将string转为字符串数组
int SpeachManager::return_res(string &s)
{
    string seed("0123");
    for (int i = 0; i < seed.size(); i++)
    {
        if (s.c_str()[0] == seed[i])
        {
            return stoi(s);
        }
    }
    return 99;
}

// 创建选手
void SpeachManager::creat_speaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        string name = "选手";
        name += nameSeed[i];

        Speaker sp;
        // 名字
        sp.m_name = name;

        // 编号
        this->v1.push_back(i + 10001);

        this->m_speaker.insert(make_pair(i + 10001, sp));
    }
}

// 选手初始化
void SpeachManager::speaker_init()
{
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_speaker.clear();
    this->m_Record.clear();
}
/*
开始比赛流程
第一轮比赛
抽签
比赛
显示晋级结果
第二轮比赛
抽签
比赛
显示晋级结果
保存分数
*/
// 比赛总流程框架
void SpeachManager::speech()
{
    this->speaker_init();
    this->creat_speaker();
    // 抽签
    this->speech_choose();
    // 比赛
    this->start_speech();
    // 显示晋级结果
    this->show_winspeaker();
    // 第二轮
    this->m_index++;

    // 抽签
    this->speech_choose();
    // 比赛
    this->start_speech();
    // 显示晋级结果
    this->show_winspeaker();
    // 保存文件
    this->saveRecord();
    this->flag = true;
    this->m_index = 1;

}

// 抽签
void SpeachManager::speech_choose()
{
    // 第一轮比赛
    // 抽签
    if (this->m_index == 1)
    {
        cout << "第" << this->m_index << "轮比赛开始,正在抽签..." << endl;
        cout << "----------------抽签结果----------------" << endl;
        random_shuffle(this->v1.begin(), this->v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << "编号:" << (*it) << endl;
        }
    }
    else if (this->m_index == 2)
    {
        cout << "第" << this->m_index << "轮比赛开始,正在抽签..." << endl;
        cout << "----------------抽签结果----------------" << endl;
        random_shuffle(this->v2.begin(), this->v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << (*it) << " ";
        }
    }
    this->hold();
}

// 比赛过程
void SpeachManager::start_speech()
{
    cout << "第" << this->m_index << "轮比赛正式开始" << endl;
    // 分组，6人一组，建立一个从大到小临时multimap容器，成绩作为key，编号作为value
    multimap<double, int, greater<double>> groupScore;
    int num = 0; // 记录人员个数

    // 判断第几轮
    vector<int> v_src;

    if (m_index == 1)
    {
        v_src = v1;
    }
    else
    {
        v_src = v2;
    }
    // 计算每个选手的平均分(除去最高,最低)
    for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
    {
        num++;
        deque<double> d;
        // 10个评委打分
        // cout << "========原始分========" << endl;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.00; //[60.00,100.00]
            // cout << score << "\t";
            d.push_back(score);
        }
        // cout << endl;
        // 除去最高,最低
        sort(d.begin(), d.end(), greater<int>()); // 降序
        d.pop_front();
        d.pop_back();
        // 计算平均
        double sum = accumulate(d.begin(), d.end(), 0.0);
        double avg = sum / (double)d.size();
        // cout << fixed << setprecision(2) << avg <<endl;//均分

        // 将分数放入map容器,通过map[x]key访问value
        this->m_speaker[*it].m_score[this->m_index - 1] = avg;

        // 将打分数据放入临时小组容器中
        groupScore.insert(make_pair(avg, *it));

        if (num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组成绩名次：" << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "编号：" << (*it).second << "\t 名字：" << this->m_speaker[(*it).second].m_name
                     << "\t 分数" << (*it).first << endl;
            }
            // 获取每组的前3名
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
            {
                if (this->m_index == 1)
                {
                    this->v2.push_back((*it).second);
                }
                else
                {
                    this->vVictory.push_back((*it).second);
                }
            }
            groupScore.clear();
        }
    }
    cout << "===============第" << this->m_index << "轮结束===============" << endl;
    this->hold();
}

// 显示第一轮晋级信息
void SpeachManager::show_winspeaker()
{
    cout << "===============第" << this->m_index << "轮晋级信息如下===============" << endl;

    vector<int> v;

    if (this->m_index == 1)
    {
        v = this->v2;
    }
    else
    {
        v = this->vVictory;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "编号:" << (*it) << "\t姓名:" << this->m_speaker[*it].m_name
             << "\t成绩:" << this->m_speaker[*it].m_score[this->m_index - 1] << endl;
    }
    this->hold();
}

// 保存分数
void SpeachManager::saveRecord()
{
    ofstream ofs;                                   // 写文件
    ofs.open("../speech.cvs", ios::out | ios::app); // 文件写入，追加的方式

    if (this->flag) // 文件换行操作,由于stringstream流出现奇怪bug,换行后会报错,因此添加标志,需要追加数据的时候才进行换行
    {
        ofs << endl;
    }

    // 数据写入
    for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end(); it++)
    {
        ofs << "编号:"
            << *it
            << "  "
            << fixed << setprecision(2) << this->m_speaker[*it].m_name
            << "  成绩:"
            << fixed << setprecision(2) << this->m_speaker[*it].m_score[1] << "  ";
    }

    // 关闭文件
    ofs.close();
    cout << "文件已经保存..." << endl;
    cout << "本届比赛结束" << endl;
    this->hold();
}

// 加载分数
void SpeachManager::loadRecord()
{
    // 第几届
    int index = 0;
    // 读文件
    ifstream ifs("../speech.cvs", ios::in);

    // 判断文件是否存在
    if ((!(ifs.is_open())))
    {
        this->fileIsempty = true;
        cout << "文件打开失败" << endl;
        ifs.close();
        this->hold();
        return;
    }
    // 文件清空的情况
    char ch;
    ifs >> ch; // 读取一个字符

    if (ifs.eof())
    {
        this->fileIsempty = true;
        cout << "文件为空" << endl;
        ifs.close();
        this->hold();
        return;
    }

    // 文件不为空
    this->fileIsempty = false;
    // 将刚刚读取的一个字符放回
    ifs.putback(ch);

    // 解析字符串
    while (!ifs.eof())
    {
        // 编号：10010  名字：选手J  成绩:88.4  编号：10004  名字：选手D  成绩:85.3  编号：10001  名字：选手A  成绩:84.85
        string data;
        stringstream ss;
        getline(ifs, data);
        ss << data;
        vector<string> v;
        string str;
        while (!ss.eof())
        {
            ss >> str;
            v.push_back(str);
            // cout << str<<endl;;
            str.clear();
        }
        // for(auto i:v)
        // {
        //     cout<<i<<endl;
        // }
        this->m_Record.insert(make_pair(index, v));
        index++;
        // cout << index << endl;
    }
    ifs.close();
    // // 检查和读取map容器中的
    // for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end(); it++)
    // {
    //     // for(int i=0;i<9;i++)
    //     //     cout << it->first << it->second[i] <<" ";
    //     // cout<<endl;
    // }

    // this->hold();
}

// 显示保存的信息
void SpeachManager::show_record()
{
    for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end(); it++)
    {
        {
            cout << "=====第" << it->first << "届=====" << endl;
            cout << "冠军:" << it->second[1] << " "
                 << it->second[2] << endl;
            cout << "亚军:" << it->second[4] << " "
                 << it->second[5] << endl;
            cout << "季军:" << it->second[7] << " "
                 << it->second[8] << endl;
        }
        cout << endl;
    }
    this->hold();
}

// 清空cvs记录中的信息
void SpeachManager::clearcvsfile()
{
    cout << "确认清空数据" << endl;
    cout << "[1]确认  [2]返回:";
    int select = 0;

    cin >> select;

    if (select == 1)
    {
        // 打开模式ios::trunc,如果存在该文件,先删除后重新创建
        ofstream ofs("../speech.cvs", ios::trunc);
        ofs.close();
        this->speaker_init();
        this->creat_speaker();
        
        cout<<"清空成功"<<endl;
    }
    this->loadRecord();
  

}

SpeachManager::~SpeachManager()
{
}