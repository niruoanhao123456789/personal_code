#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

// 如何理解递归
// 1、递归展开的细节图
// 2、二叉树中的题目
// 3、宏观看待递归的过程
//		1、不要在意递归细节展开图的细枝末节
//		2、把递归函数当成一个黑盒
//		3、相信这个黑盒一定能完成任务

// 如何写好一个递归
// 1、先找到相同的子问题 -> 函数头的设计
// 2、只关心某个一个子问题是如何解决的 -> 函数体的设计
// 3、注意递归函数的出口


// 搜索
// 深度优先遍历 vs 深度优先搜索
// 宽度优先遍历 vs 宽度优先搜索
// 暴搜：暴力枚举一遍所有情况


// 拓展搜索
// 全排列、利用树状图  -> 决策树


// 回溯与剪枝
// 回溯本质是深搜    迷宫问题