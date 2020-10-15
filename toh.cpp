/*Implementation of Tower of Hanoi(Mathematical Puzzle)*/

#include<stdio.h>

void toh(int n, char rod1,char rod2,char rod3)
{
	if(n==1)
	{
		printf("\n Move disk 1 from rod %c to rod %c ",rod1,rod2);
		return;
	}
	toh(n-1,rod1,rod3,rod2);
	printf("\n Move disk %d from %c to rod %c",n,rod1,rod3);
	toh(n-1,rod3,rod2,rod1);
}
int main()
{
	int n;
	printf("Enter number of disks: ",n);
	scanf("%d",&n);
	toh(n,'A','B','C');
	return 0;
	
}
