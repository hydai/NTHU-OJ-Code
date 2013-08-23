#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int team[1000000]; // for 0-999999 number in which team
queue <int> queue_team[1010];
queue <int> queue_stage;

int main(int argc, char *argv[])
{
    int i, team_number, tmp_count, tmp_in, team_count, case_count;
    char oper[20];
    case_count = 0;
    while (~scanf("%d", &team_number) && team_number!=0) {
        memset(team, -1, sizeof(team));
        while (!queue_stage.empty()) {
            queue_stage.pop();
        }
        for (i = 0; i < 1010; i++) {
            while (!queue_team[i].empty()) {
                queue_team[i].pop();
            }
        }
        printf("Scenario #%d\n", ++case_count);
        /* input team member */
        for (i = 0; i < team_number; i++) {
            scanf("%d", &tmp_count);
            while (tmp_count--) {
                scanf("%d", &tmp_in);
                team[tmp_in] = i;
            }
        }
        /* get op */
        while (scanf("%s", oper)) {
            if (oper[0]=='S') {
                putchar('\n');
                break;
            }
            else if (oper[0]=='E') {
                scanf("%d", &tmp_in);
                if (queue_team[team[tmp_in]].empty()) {
                    queue_stage.push(team[tmp_in]);
                    //printf("EEE#######team[tmp_in] = %d\n", team[tmp_in]);
                }
                queue_team[team[tmp_in]].push(tmp_in);
            }
            else if (oper[0]=='D') {
                team_count = queue_stage.front();
                //printf("DDD#######team_count = %d\n", team_count);
                //tmp_in = queue_team[team_count].front();
                //printf("DDD#######queue_team[team_count].front() = %d\n", tmp_in);

                while (queue_team[team_count].empty()) {
                    queue_stage.pop();
                    team_count = queue_stage.front();
                }
                tmp_in = queue_team[team_count].front();
                printf("%d\n", tmp_in);
                queue_team[team_count].pop();
            }
        }
    }
    return 0;
}
