#include <iostream>
using namespace std;
int mat[7][7] = {   {0, 1, 1, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 1},
                    {1, 0, 0, 0, 1, 0, 0}
                };
int path[7][7];
int n = 7;

void pathMatrix()
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(path[i][j]==1)
			{
				for(k=0;k<n;k++)
				{
					if(path[j][k]==1)
					{
						path[i][k]=1;
					}
				}
			}
		}
	}
}
int cycle()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(path[i][i]==1)
			return 1;
	}
	return 0;
}
int main()
{
	int i,j,c;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			path[i][j]=mat[i][j];
		}
	}
	pathMatrix();
	pathMatrix();
	c=cycle();
	if(c==1)
		printf("Cycle Exists!!");
	else
		printf("No cycle exists");
}
