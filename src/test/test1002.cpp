#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string line;    //读取的每一行消息
    int count = 0;  //用于统计 “无中生带” 情况的出现次数
    bool f = false; //用于标记是否期望收到回复，初始值为 false

    while (getline(cin, line)) {
        auto pos = line.find(' ');         //查找当前行中第一个空格的位置
        if (pos == string::npos) continue; // 判断是不是无效行 则跳过当前循环，继续读取下一行

        string sender = line.substr(0, pos);   //提取发送者的名字，即从行首到第一个空格的部分
        string content = line.substr(pos + 1); //提取消息内容，即第一个空格之后的部分

        // 处理回复消息
        //如果 f 为 true，说明之前有消息触发了期望回复，将 f 置为 false，表示回复已收到。
        //如果 f 为 false，说明没有之前的消息触发期望回复，这种情况属于 “无中生带”，将 count 加 1。
        if (sender == "xiaoA" && content == "nengdaima") {
            if (f) {
                f = false;
            } else {
                count++; // 无中生带
            }
        }

        // 检查是否触发
        //如果消息内容中包含 “吃” 这个字，将 f 置为 true，表示期望收到回复。
        if (content.find("chi") != string::npos) {
            f = true;
        }
    }

    // 处理最后未回复的触发
    //循环结束后，如果 f 仍然为 true，说明最后一个触发消息没有得到回复，将 count 加 1
    if (f) {
        count++;
    }

    cout << count << endl;
    return 0;
}