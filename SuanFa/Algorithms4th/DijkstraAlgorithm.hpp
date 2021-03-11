//
//  DijkstraAlgorithm.hpp
//  SuanFa
//
//  Created by fengqingsong on 2019/3/28.
//  Copyright © 2019 fqs. All rights reserved.
//

#ifndef DijkstraAlgorithm_hpp
#define DijkstraAlgorithm_hpp

#include <stdio.h>
#include <string>

using namespace std;

// 记录起点到每个顶点的最短路径的信息
struct Dis {
    string path;
    int value;
    bool visit;
    Dis() {
        visit = false;
        value = 0;
        path = "";
    }
};

class Graph_GD {
private:
    int vexnum;
    int edge;
    int **arc;
    Dis *dis;
public:
    // 初始化顶点和边
    Graph_GD(int vexnum, int edge);
    // 析构函数
    ~Graph_GD();
    // 创建随机图
    void createGraph();
    // 打印图
    void printGraph();
    // 迪杰斯特拉算最短路径
    void dijkstra(int begin);
};

void test_dijkstraAlgorithm();


#endif /* DijkstraAlgorithm_hpp */
