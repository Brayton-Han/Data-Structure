#include <cstdio>
//定义一个类似于pair的数据结构，存储行列信息 
class node{
public:
	int x, y;
	node() {};
	node(int x, int y) :x(x), y(y) {};
};
node U[1002][1002], D[1002][1002], L[1002][1002], R[1002][1002]; //记录所有元素的上下左右坐标 
int f[1002][1002]; //记录数据的二维数组 

int main()
{
	int n, m, Q, i, j;
	node u, v, p, q;
	scanf("%d%d%d", &n, &m, &Q);
	//录入所有元素 
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			scanf("%d", &f[i][j]);
	//把现有元素的周围元素记录下来 
	for(i = 0; i <= n+1; ++i)
		for(j = 0; j <= m+1; ++j)
			U[i][j]=node(i-1, j), D[i][j]=node(i+1, j), L[i][j]=node(i, j-1), R[i][j]=node(i, j+1);
	while(Q--)
	{
		int a, b, c, d, h, w;
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &h, &w);
		u=node(a, 0); v=node(c, 0);
		//定位到两个子矩阵的左上角 
		for(i = 1; i <= b; ++i)
			u = R[u.x][u.y];
		for(i = 1; i <= d; ++i)
			v = R[v.x][v.y];
		//顺时针方向更新两个子矩阵最外圈的位置 
		for(i = 1; i <= w; ++i){
			p = U[u.x][u.y]; q = U[v.x][v.y];
			U[u.x][u.y] = q; U[v.x][v.y] = p; 
			D[p.x][p.y] = v; D[q.x][q.y] = u;
			if(i<w)	u = R[u.x][u.y], v = R[v.x][v.y];
		} //从左往右 
		for(i = 1; i <= h; ++i){
			p = R[u.x][u.y]; q = R[v.x][v.y];
			R[u.x][u.y] = q; R[v.x][v.y] = p; 
			L[p.x][p.y] = v; L[q.x][q.y] = u;
			if(i<h) u = D[u.x][u.y], v = D[v.x][v.y];
		} //从上往下 
		for(i = 1; i <= w; ++i){
			p = D[u.x][u.y], q = D[v.x][v.y];
			D[u.x][u.y] = q, D[v.x][v.y] = p; 
			U[p.x][p.y] = v, U[q.x][q.y] = u;
			if(i<w) u = L[u.x][u.y], v = L[v.x][v.y];
		} //从右往左 
		for(i = 1; i <= h; ++i){
			p = L[u.x][u.y], q = L[v.x][v.y];
			L[u.x][u.y] = q, L[v.x][v.y] = p; 
			R[p.x][p.y] = v, R[q.x][q.y] = u;
			if(i<h) u = U[u.x][u.y], v = U[v.x][v.y];
		} //从下往上 
	}
	//遍历输出 
	for(i = 1; i <= n; ++i){
		p.x = i, p.y = 0;
		for(j = 1; j <= m; ++j){
			p = R[p.x][p.y];
			printf("%d%c", f[p.x][p.y], j == m ? '\n' : ' ');
		}
	}
	return 0;
}
