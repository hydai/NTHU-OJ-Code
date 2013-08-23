#include <cstdio>
#include <string>

using namespace std;
string str[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe"};
int main(int argc, char *argv[])
{
    int input;
    while (~scanf("%d", &input)) {
        printf("%s\n", str[input-1].c_str());
    }
    return 0;
}
