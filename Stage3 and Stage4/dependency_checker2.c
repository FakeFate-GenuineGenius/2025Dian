// dependency_checker.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "rule_parser.h"

#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES] = {0};
int inDegree[MAX_VERTICES] = {0};
int vertexCount = 0;

// 查找目标在顶点数组中的索引
int findVertexIndex(const char *target) {
    for (int i = 0; i < vertexCount; i++) {
        if (strcmp(rules[i].target, target) == 0) {
            return i;
        }
    }
    return -1;
}

// 构建依赖图
void buildDependencyGraph() {
    for (int i = 0; i < rule_count; i++) {
        int targetIndex = findVertexIndex(rules[i].target);
        if (targetIndex == -1) {
            targetIndex = vertexCount++;
        }
        for (int j = 0; j < rules[i].dependency_count; j++) {
            int depIndex = findVertexIndex(rules[i].dependencies[j]);
            if (depIndex == -1) {
                depIndex = vertexCount++;
            }
            graph[depIndex][targetIndex] = 1;
            inDegree[targetIndex]++;
        }
    }
}

// 拓扑排序
void topologicalSort() {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    for (int i = 0; i < vertexCount; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    while (front < rear) {
        int current = queue[front++];
        printf("%s ", rules[current].target);
        for (int i = 0; i < vertexCount; i++) {
            if (graph[current][i]) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }
    printf("\n");
}