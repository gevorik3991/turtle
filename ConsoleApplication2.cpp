#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int to_int(string str)
{
    int num = 0;
    int k = 1;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        num += (str[i] - '0') * k;
        k *= 10;
    }
    return num;
}

void read(const char* path)
{
    ifstream in(path);
    string str;
    vector<string> file;
    vector<string> maze;
    while (getline(in, str))
    {
        file.push_back(str);
    }
    for (int i = 0; i < file.size() - 2; i++)
    {
        maze.push_back(file[i]);
    }
    int y = to_int(file[file.size() - 2]);
    int x = to_int(file[file.size() - 1]);
}
int main()
{
    cout << "Hello World!\n";
}
