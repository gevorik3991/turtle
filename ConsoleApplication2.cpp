#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool stop = false;

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

void print_v(vector<string>& a)
{
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

void move(int y, int x, vector<string> maze, int kol)
{
    if (!stop) {

        // end
        if ((y == 0 || y == maze.size() - 1 || x == 0 || x == maze[0].size() - 1) && maze[y][x] == ' ') {
            maze[y][x] = '@';
            print_v(maze);
            cout << "Finish: y = " << y << " x = " << x << endl;
            cout << kol << " moves completed" << endl;
            stop = true;
            return;
        }

        maze[y][x] = '@';

        // move
        if (y + 1 < maze.size() && maze[y + 1][x] == ' ')
            move(y + 1, x, maze, kol + 1);
        if (x - 1 >= 0 && maze[y][x - 1] == ' ')
            move(y, x - 1, maze, kol + 1);
        if (y - 1 >= 0 && maze[y - 1][x] == ' ')
            move(y - 1, x, maze, kol + 1);
        if (x + 1 < maze[0].size() && maze[y][x + 1] == ' ')
            move(y, x + 1, maze, kol + 1);
    }
}

void read(const char* path)
{
    ifstream in(path);
    string str;
    vector<string> file;
    vector<string> maze;
    while (getline(in, str))
        file.push_back(str);
    for (int i = 0; i < file.size() - 2; i++)
        maze.push_back(file[i]);
    int y = to_int(file[file.size() - 2]);
    int x = to_int(file[file.size() - 1]);

    move(y, x, maze, 0);
}

int main()
{
    read("C:/Users/Gevor/source/repos/turtle/l4_2.txt");
    return 0;
}