#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
#include <vector>
using namespace std;
vector<int> card;

struct state {
    vector<int> pile[7];
    vector<int> currentCard;
    bool use[7];
    int pileNum;
    int cycle;
    state() {
        for (int i = 0; i < 7; i++) {
            use[i] = false;
        }
        pileNum = -1;
        cycle = -1;
    }
};

void DispatchOneCard(state &s);
bool check10(state &s);
bool check20(state &s);
bool check30(state &s);
bool check(state &s);

int main(int argc, char *argv[])
{
    int tmp;
    while (~scanf("%d", &tmp) && tmp != 0) {
        set<state> Set;
        card.clear();
        card.push_back(tmp);
        for (int i = 1; i < 52; i++) {
            scanf("%d", &tmp);
            card.push_back(tmp);
        }
        state s;
        while (1) {
            DispatchOneCard(s);
            while(check(s));
            if (Set.find(s) == Set.end()) {
                Set.insert(s);
            }
            else {
                if (card.size() == 0) {
                    if (strtmp.length() == 7) {
                        printf("Win : ");
                    }
                    else {
                        printf("Loss: ");
                    }
                }
                else {
                    printf("Draw: ");
                }
                printf("%d\n", s.cycle - Set.find(s)->cycle + 1);
                break;
            }
        }
    }
    return 0;
}
void DispatchOneCard(state &s) {
    s.pileNum = (s.pileNum+1)%7;
    s.cycle++;
    s.pile[s.pileNum].push_back(card.front());
    vector<int>::iterator iter = card.begin();
    card.erase(iter);
}
bool check10(state &s) {
    int tmp = s.pile[s.pileNum][0]
            + s.pile[s.pileNum][1]
            + s.pile[s.pileNum][s.pile[s.pileNum].size()-1];
    if (tmp == 10) {
        card.push_back(s.pile[s.pileNum][0]);
        card.push_back(s.pile[s.pileNum][1]);
        card.push_back(s.pile[s.pileNum][s.pile[s.pileNum].size()-1]);
        vector<int>::iterator iter = s.pile[s.pileNum].begin();
        s.pile[s.pileNum].erase(iter);
        iter = s.pile[s.pileNum].begin();
        s.pile[s.pileNum].erase(iter);
        s.pile[s.pileNum].pop_back();
        return true;
    }
    return false;
}
bool check20(state &s) {
    int tmp = s.pile[s.pileNum][0]
            + s.pile[s.pileNum][s.pile[s.pileNum].size()-2]
            + s.pile[s.pileNum][s.pile[s.pileNum].size()-1];
    if (tmp == 20) {
        card.push_back(s.pile[s.pileNum][0]);
        card.push_back(s.pile[s.pileNum][s.pile[s.pileNum].size()-2]);
        card.push_back(s.pile[s.pileNum][s.pile[s.pileNum].size()-1]);
        vector<int>::iterator iter = s.pile[s.pileNum].begin();
        s.pile[s.pileNum].erase(iter);
        s.pile[s.pileNum].pop_back();
        s.pile[s.pileNum].pop_back();
        return true;
    }
    return false;
}
bool check30(state &s) {
    int tmp = s.pile[s.pileNum][s.pile[s.pileNum].size()-3]
            + s.pile[s.pileNum][s.pile[s.pileNum].size()-2]
            + s.pile[s.pileNum][s.pile[s.pileNum].size()-1];
    if (tmp == 30) {
        card.push_back(s.pile[s.pileNum][s.pile[s.pileNum].size()-3]);
        card.push_back(s.pile[s.pileNum][s.pile[s.pileNum].size()-2]);
        card.push_back(s.pile[s.pileNum][s.pile[s.pileNum].size()-1]);
        s.pile[s.pileNum].pop_back();
        s.pile[s.pileNum].pop_back();
        s.pile[s.pileNum].pop_back();
        return true;
    }
    return false;
}
bool check(state &s) {
    bool status = false;
    if (s.pile[s.pileNum].size() < 3) {
        return;
    }
    status = check10(s) | status;
    if (s.pile[s.pileNum].size() < 3) {
        return;
    }
    status = check20(s) | status;
    if (s.pile[s.pileNum].size() < 3) {
        return;
    }
    status = check30(s) | status;
    return status;
}
