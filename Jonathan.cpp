#include"iostream"
#include"vector"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;


bool judge(int x,int y,char (*maze)[7]);
bool walk(int x,int y,char(*maze)[7]);


int count = 0;
vector<pair<int, int>>p;


int main() {
	char maze[][7] = { {'#','#', '#', '#', '#', '#', '#' },{ '#', '.','#', '.','.','.','#'},{ '#', '.','#', '.','#', '#', '#'},
	{'#', '.','.','.','.', '.','#'},{ '#','.','#','.','.','.','#'},{ '#', '.','#', '.','#', '@','#'},{ '#', '#', '#', '#', '#', '#', '#'} };
	for (int i = 0; i < 7;i++) {
		for (int j = 0; j < 7;j++) {
			cout << maze[i][j]<<" ";
		}
		cout << endl;
	}

	walk(1, 1, maze);

}


bool judge(int x,int y,char(*maze)[7]) {
	if ('.' == maze[x][y]||'@'==maze[x][y])
		return true;
	else
		return false;
}


bool walk(int x, int y, char(*maze)[7]) {
	if ('@' == maze[x][y])
	{
		count++;
		cout << "第" << count << "种路线：";
		for(auto x:p){
			cout << "(" << x.first << "," << x.second << ")";
		}
		cout << "(5,5)"<<endl;
		return true;
	}
	else {
		maze[x][y] = '1';
		p.push_back(pair<int,int>(x,y));
		if (judge(x + 1, y, maze))
			walk(x + 1, y ,maze);
		if (judge(x - 1, y, maze))
			walk(x-1,y,maze);
		if (judge(x, y - 1, maze))
			walk(x,y-1,maze);
		if (judge(x, y + 1, maze))
			walk(x , y+1,maze);
		p.pop_back();
		maze[x][y] = '.';
	}
}
