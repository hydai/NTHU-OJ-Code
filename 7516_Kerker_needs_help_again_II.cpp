#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct group {
  char id_num[15];
  char name_sp[30];
};

queue <group> q[3];

int main()
{
  int n, length[3], tmp_len;
  char unuseful[150];
  group tmp_in;

  while(~scanf("%d", &n))
  {
    if (n==0) break;
    tmp_len = 0;
    length[0] = length[1] = length[2] = 0;
    while(n--)
    {
      scanf("%s%s", tmp_in.id_num, tmp_in.name_sp);
      gets(unuseful);
      tmp_len = strlen(tmp_in.id_num);
      if (tmp_len<=3 && tmp_len >= 1)
      {
        length[0] = (length[0]>tmp_len)?length[0]:tmp_len;
        q[0].push(tmp_in);
      }
      else if (tmp_len<=6 && tmp_len >= 4)
      {
        length[1] = (length[1]>tmp_len)?length[1]:tmp_len;
        q[1].push(tmp_in);
      }
      else
      {
        length[2] = (length[2]>tmp_len)?length[2]:tmp_len;
        q[2].push(tmp_in);
      }
    }
    printf("<326>\n");
    while(!q[0].empty())
    {
      tmp_in = q[0].front();
      printf("%*s %s\n", length[0], tmp_in.id_num, tmp_in.name_sp);
      q[0].pop();
    }
    printf("<328>\n");
    while(!q[1].empty())
    {
      tmp_in = q[1].front();
      printf("%*s %s\n", length[1], tmp_in.id_num, tmp_in.name_sp);
      q[1].pop();
    }
    printf("<mac>\n");
    while(!q[2].empty())
    {
      tmp_in = q[2].front();
      printf("%*s %s\n", length[2], tmp_in.id_num, tmp_in.name_sp);
      q[2].pop();
    }
    putchar('\n');
  }
  return 0;
}
