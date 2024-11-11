#include "impls.h"
#include <algorithm>

float compute_iou(const cv::Rect& a, const cv::Rect& b) {
    /**
     * 要求：
     *      有一个重要的指标叫做“交并比”，简称“IOU”，可以用于衡量
     * 两个矩形的重合程度，本练习要求自行学习交并比的计算方式，计算输入
     * 的两个矩形的交并比。
     * 
     * 提示：
     * (1) 注意OpenCV中规定的xy坐标系方向跟平常的xy坐标系不一样。
     * (2) 注意矩形的x, y, width, height四个属性在坐标系内的含义。
     * (3) 注意分母不要除以0（不过我们不会测试这一点）
     * 
     * 通过条件：
     * 运行测试点，显示通过就行，不通过会告诉你哪一组矩形错了。
    */
    // IMPLEMENT YOUR CODE HERE
    float iou;
    float w,h,lx,rx,uy,dy,lw,rw,uh,dh;
    if(a.x>=b.x){rx=a.x;lx=b.x;lw=b.width;rw=a.width;}
    else{rx=b.x;lx=a.x;lw=a.width;rw=b.width;}
    if(a.y>=b.y){dy=a.y;uy=b.y;uh=b.height;dh=a.height;}
    else{dy=b.y;uy=a.y;uh=a.height;dh=b.height;}
    w=lw-rx+lx;
    if(w<0){w=0;}else if(w>rw){w=rw;}
    h=uh-dy+uy;
    if(h<0){h=0;}else if(h>dh){h=dh;}
    float s1,s2;
    s1=w*h;
    s2=a.width*a.height+b.width*b.height-s1;
    iou=s1/s2;
    return iou;
}