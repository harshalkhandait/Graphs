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

int motherVertex()
{
	int count,i,j;
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(path[i][j]==0)
				{
					break;
				}
				else
					count++;
			}
		}
		if(count==n-1)
		{
			return i;
		}
	}
}

int main(){
	int i,j,m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			path[i][j]=mat[i][j];
		}
	}
	pathMatrix();
	pathMatrix();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",path[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	m=motherVertex();
	printf("Mother Vertex is: %d ",m);
}
