#include <cstdio>
#include <map>

using namespace std;

struct Object {
    int id, times, local;
    bool operator < (const Object &right) const {
        if (this->times != right.times) {
            return times > right.times;
        }
        else {
            return local < right.local;
        }
    }
};

int main(int argc, char *argv[])
{
    int limit, n, Case = 1;
    while (~scanf("%d%d", &limit, &n) && (limit+n)) {
        int size = 0, ct = 0, ans = 0;
        map<Object, int> Map;
        map<int, Object> Rev;
        Map.clear(); Rev.clear();
        while (n--) {
            Object pack;
            int tmp;
            scanf("%d", &tmp);

            if (Rev.find(tmp) == Rev.end()) {
                pack.id = tmp;
                pack.local = ct++;
                pack.times = 1;
                
                Rev[tmp] = pack;
                Map[pack] = 1;
            }
            else {
                Map.erase(Rev[tmp]);
                pack = Rev[tmp];
                pack.times++;
                Rev.erase(tmp);
                
                Rev[tmp] = pack;
                Map[pack] = 1;
            }
            if (Map.size() > limit) {
                pack = Map.begin()->first;
                Rev.erase(pack.id);
                Map.erase(pack);
                ans++;
            }
        }
        printf("Case %d: %d\n", Case++, ans);
    }
    return 0;
}
