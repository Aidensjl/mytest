#include"myadd.h"

#include <opencv2/opencv.hpp>

#include <sys/stat.h>




void test()
{
    cv::VideoCapture cap(0);

    // 检查摄像头是否成功打开
    if (!cap.isOpened()) {
        std::cerr << "无法打开摄像头。" << std::endl;
    }

    while (true) {
        // 读取摄像头的帧
        cv::Mat frame;
        cap >> frame;

        // 如果成功读取帧
        if (!frame.empty()) {
            // 在窗口中显示帧
            cv::imshow("Camera", frame);
        }

        // 按下 'q' 键退出循环
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    // 释放摄像头资源
    cap.release();

    // 关闭窗口
    cv::destroyAllWindows();

}


int main(int argc ,char* argv[])
{
    std::cout<<"aaaaaaaa"<<std::endl;
    int a = 10, b = 20;
    std::cout<<Myadd(a,b)<<std::endl;

    test();

    return 0;
}

