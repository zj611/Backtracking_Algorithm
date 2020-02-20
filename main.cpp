#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> // for ostream_iterator<>

//问题很简单，输入一个不包含重复数字的数组，要求算法输出这些数字的所有子集。
//vector<vector<int>> subsets(vector<int>& nums);
//比如输入 nums = [1,2,3]，你的算法应输出 8 个子集，包含空集和本身，顺序可以不同：
//[ [],[1],[2],[3],[1,3],[2,3],[1,2],[1,2,3] ]
using namespace std;

template <class T>
void show(const T& x){cout << x << " ";}

vector<vector<int>> res;

void backtrack(vector<int>& nums, int start, vector<int>& track) {
    res.push_back(track);
    // 注意 i 从 start 开始递增
    for (int i = start; i < nums.size(); i++) {
        // 做选择
        track.push_back(nums[i]);
        // 回溯
        backtrack(nums, i + 1, track);
        // 撤销选择
        track.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    // 记录走过的路径
    vector<int> track;
    backtrack(nums, 0, track);
    return res;
}

int main() {
    vector<int> v{1,2,3};
    vector<vector<int> > res;
    res = subsets(v);

    for(int i = 0; i < res.size(); i++ ){
        cout <<"[";
        copy(res[i].begin(),res[i].end(),ostream_iterator<int>(cout," "));
        //for_each(res[i].begin(),res[i].end(),show<int>);
        cout <<"]";
    }
    return 0;
}
