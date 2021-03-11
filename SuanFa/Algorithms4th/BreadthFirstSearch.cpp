//
//  BreadthFirstSearch.cpp
//  SuanFa
//
//  Created by fengqingsong on 2019/3/27.
//  Copyright © 2019 fqs. All rights reserved.
//

#include "BreadthFirstSearch.hpp"
#include <iostream>

void testBreadthFirstSearch()
{
    map<string, list<string>> graph;
    graph["金台路"] = {"朝阳公园", "呼家楼", "大望路", "十里堡"};
    graph["朝阳公园"] = {"枣营", "金台路"};
    graph["呼家楼"] = {"团结湖", "东大桥", "金台夕照", "金台路"};
    graph["东大桥"] = {"朝阳门", "呼家楼"};
    graph["十里堡"] = {"青年路", "金台路"};
    graph["大望路"] = {"金台路", "国贸", "九龙山", "四惠"};
    breadthFirstSearch(graph, "金台路", "东大桥");
}

void breadthFirstSearch(map<string, list<string>> graph, string start, string end) {
    list<string> checked;
    deque<string> workflow;
    workflow.push_back(start);
    
    while (!workflow.empty()) {
        string current = workflow.front();
        workflow.pop_front();
        bool contain = find(checked.begin(), checked.end(), current) != checked.end();
        
        if(contain) {
            continue;
        }
        
        cout << current << endl;
        
        if (current == end) {
            break;
        } else {
            list<string> nextLevel = graph[current];
            for (list<string>::const_iterator iter = nextLevel.begin(); iter != nextLevel.end(); iter++) {
                workflow.push_back(*iter);
            }
            checked.push_back(current);
        }
    }
}
