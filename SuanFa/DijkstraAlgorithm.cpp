//
//  DijkstraAlgorithm.cpp
//  SuanFa
//
//  Created by fengqingsong on 2019/3/28.
//  Copyright © 2019 fqs. All rights reserved.
//

#include "DijkstraAlgorithm.hpp"
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>

// 初始化顶点和边
Graph_GD::Graph_GD(int vexnum, int edge) {
    this->vexnum = vexnum;
    this->edge = edge;
    arc = new int*[this->vexnum];
    dis = new Dis[this->vexnum];
    
    for (int row = 0; row < this->vexnum; row++) {
        arc[row] = new int[this->vexnum];
        for (int col = 0; col < this->vexnum; col++) {
            arc[row][col] = INT_MAX;
        }
    }
}

// 析构函数
Graph_GD::~Graph_GD() {
    delete[] dis;
    for (int i = 0; i < vexnum; i++) {
        delete[] arc[i];
    }
    delete[] arc;
}

// 创建随机图
void Graph_GD::createGraph() {
    //通过随机数设置边的权重
    srand((unsigned)time(NULL));
    
    for (int row = 0; row < this->vexnum; row++) {
        for (int col = 0; col < this->vexnum; col++) {
            if (col == row) {
                arc[row][col] = 0;
                continue;
            }
            
            arc[row][col] = rand() % 3;
            if (arc[row][col]) {
                //正常权重
                arc[row][col] = rand() % 20;
            } else {
                //不能到达
                arc[row][col] = INT_MAX;
            }
        }
    }
}

// 打印图
void Graph_GD::printGraph() {
    for (int row = 0; row < this->vexnum; row++) {
        for (int col = 0; col < this->vexnum; col++) {
            if (arc[row][col] == INT_MAX) {
                cout << " ∞" << "  ";
            } else {
                cout << setw(2) << right << arc[row][col] << "  ";
            }
        }
        cout << endl;
    }
}

// 迪杰斯特拉算最短路径
void Graph_GD::dijkstra(int begin) {
    for (int i = 0; i < vexnum; i++) {
        dis[i].path = "v" + to_string(begin) + "-->v" + to_string(i);
        dis[i].value = arc[begin][i];
    }
    
    dis[begin].value = 0;
    dis[begin].visit = true;
    
    for (int i = 0; i < vexnum; i++) {
        //找到最短路径的顶点
        int minValue = INT_MAX;
        int minIndex = -1;
        
        for (int j = 0; j < vexnum; j++) {
            Dis distance = dis[j];
            if (!distance.visit && distance.value < minValue) {
                minValue = distance.value;
                minIndex = j;
            }
        }
        
        if (minIndex == -1) {
            break;
        }
        
        dis[minIndex].visit = true;
        
        //扩展到该顶点的相邻顶点
        for (int k = 0; k < vexnum; k++) {
            if (arc[minIndex][k] != INT_MAX && !dis[k].visit && minValue + arc[minIndex][k] < dis[k].value) {
                dis[k].value = arc[minIndex][k] + minValue;
                dis[k].path = dis[minIndex].path + "-->v" + to_string(k);
            }
        }
    }
    
    for (int i = 0; i < vexnum; i++) {
        string pathValue = dis[i].value == INT_MAX ? "∞" : to_string(dis[i].value);
        cout << "路径：" << dis[i].path + "  长度：" + pathValue << endl;
    }
}


void test_dijkstraAlgorithm() {
    Graph_GD *graph = new Graph_GD(5, 5);
    graph->createGraph();
    graph->printGraph();
    graph->dijkstra(0);
    delete graph;
}
