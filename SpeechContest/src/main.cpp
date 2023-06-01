#include "iostream"
#include "stdlib.h"
#include "speechManeger.h"

using namespace std;

void test(map<int, Speaker> &p)
{
    for (auto i : p)
    {
        cout << "编号:" << i.first << "\t" << i.second.m_name
             << "分数1:" << fixed << setprecision(2) << i.second.m_score[0]
             << "\t分数2:" << i.second.m_score[1] << endl;
    }
}

void choose()
{
    string num;
    int res = 0;
    SpeachManager sm;
    while (true)
    {
        sm.show_Menu();
        cout << "输入您的选择：";
        cin >> num;
        res = sm.return_res(num);
        switch (res)
        {
        case 0: // 退出
            sm.exit_sys();

        case 1: // 开始
            sm.speech();
            // test(sm.m_speaker);
            break;

        case 2: // 查看
            sm.loadRecord();
            sm.show_record();
            break;

        case 3: // 清空
            sm.clearcvsfile();
            break;

        default:
            cout << "输入错误，重新输入（按任意键继续）";
            sm.hold();
            break;
        }

        cin.clear();

        // cin.ignore(10,'\n');

        system("clear");
    }
}

int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));
    choose();
    return 0;
}
