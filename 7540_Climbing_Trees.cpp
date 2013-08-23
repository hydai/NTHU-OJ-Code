#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
struct NODE {int nPar; int nPos; vector<int> Chi;};
vector<NODE> Tree;
//分別用於存儲RQM的遍例次序和深度
vector<int> Order, Depth;
//由樹建立RQM表，遞歸方式
void BuildRMQTable(int nNode, int nDepth) {
    //進入當前節點，存儲其編號和深度
    Order.push_back(nNode);
    Depth.push_back(nDepth);
    NODE &Node = Tree[nNode];
    //第一次遍例該節點，記錄節點在表中的位置
    Node.nPos = Node.nPos == -1 ? (Order.size() - 1) : Node.nPos;
    //多叉樹的標準深度遍例方式，依次訪問所有子節點
    for (vector<int>::iterator i = Node.Chi.begin(); i != Node.Chi.end();) {
        BuildRMQTable(*i++, nDepth + 1);
        //回到當前節點，存儲其編號和深度
        Order.push_back(nNode);
        Depth.push_back(nDepth);
    }
}
//主函數
int main(void) {
    //姓名Hash
    map<string, int> NameTbl;
    //新節點的初始值，父為-1，RMQ表位置為-1
    NODE NewNode = {-1, -1};
    //循環輸入所有的姓名，str1為子，str2為父
    for (string str1, str2; cin >> str1 >> str2 && str1 != "no.child";) {
        //不存在給定名稱，則加入該名稱
        if (NameTbl.end() == NameTbl.find(str2)) {
            NameTbl[str2] = Tree.size();
            Tree.push_back(NewNode);
        }
        if (NameTbl.end() == NameTbl.find(str1)) {
            NameTbl[str1] = Tree.size();
            Tree.push_back(NewNode);
        }
        //建立父子關係
        Tree[NameTbl[str2]].Chi.push_back(NameTbl[str1]);
        Tree[NameTbl[str1]].nPar = NameTbl[str2];
    }
    //為避免出現"多樹"的情況，建立虛擬的總根，放在列表最後
    Tree.push_back(NewNode);
    //遍例所有節點
    for (vector<NODE>::iterator i = Tree.begin(); i != Tree.end() - 1; ++i ) {
        //找出沒有父的節點，即父為-1的節點
        if (i->nPar == -1) {
            //令父其父節點為總根
            i->nPar = Tree.size() - 1;
            //在總根的子節點列表中加入該節點
            Tree.back().Chi.push_back(i - Tree.begin());
        }
    }
    //從總根開始遞歸建立RMQ表
    BuildRMQTable(Tree.size() - 1, 0);
    //循環輸入每一組查詢
    for (string str1, str2; cin >> str1 >> str2;) {
        map<string, int>::iterator i1 = NameTbl.find(str1);
        map<string, int>::iterator i2 = NameTbl.find(str2);
        //如果兩個名子中有任一個沒有記錄，認為無關
        if (i1 == NameTbl.end() || i2 == NameTbl.end()) {
            cout << "no relation" << endl;
            continue;
        }
        //得到兩個名子在查詢表中的位置
        int n1 = Tree[i1->second].nPos, n2 = Tree[i2->second].nPos;
        //保持位置較小者在前
        if (Depth[n1] > Depth[n2]) {
            swap(n1, n2);
        }
        //RQM查詢
        vector<int>::iterator iAnc = min_element(Depth.begin() + min(n1, n2), Depth.begin() + max(n1, n2) + 1);
        //如果小最共同祖先(LCS)為總根，認為無關
        if (Tree[Order[iAnc - Depth.begin()]].nPar == -1) {
            cout << "no relation" << endl;
            continue;
        }
        //nRemoved為隔代數，nCousin為二者與LCS距離的最小值
        int nRemoved = Depth[n2] - Depth[n1];
        int nCousin = Depth[n1] - *iAnc;
        //二者中有一人為LCS的情況
        if(nCousin == 0) {
            for (; nRemoved > 2; --nRemoved) {
                cout << "great ";
            }
            if (nRemoved > 1) {
                cout << "grand ";
            }
            cout << (Tree[i1->second].nPos == n1 ? "parent" : "child") << endl;
        }
        //LCS為二者生父
        else if (nCousin == 1 && nRemoved == 0) {
            cout << "sibling" << endl;
        }
        //堂親
        else {
            cout << nCousin - 1 << " cousin";
            if (nRemoved > 0) {
                cout << " removed " << nRemoved;
            }
            cout << endl;
        }
    }
    return 0;
}
