#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
	printf("速度测试程序v0.01\n");
	clock_t start,finish;
	double cycle=100000000;//一亿次加法
	double i=0,j=0;
	double elapse;
	start=clock();
		for(i=0;i<cycle;i++)
		{
			j++;
		}
	finish=clock();
	elapse=(double)(1000*(finish-start)/CLOCKS_PER_SEC);
	printf("1 billion add ops time elapse:%5.1fms\n",elapse);
//-----------------------------------------------------------
	start=clock();
		for(i=0;i<cycle;i++)
		{
			j=19999.09*12000.01;
		}
	finish=clock();
	elapse=(double)(1000*(finish-start)/CLOCKS_PER_SEC);
	printf("1 billion fp mul ops time elapse:%5.1fms\n",elapse);
	//printf("%10.4f",j);
//-----------------------------------------------------------
	start=clock();
	srand(time(0));
		for(i=0;i<cycle;i++)
		{
			j=rand()*rand();
		}
	finish=clock();
	elapse=(double)(1000*(finish-start)/CLOCKS_PER_SEC);
	printf("1 billion 2 random num mul ops time elapse:%5.1fms\n",elapse);
	//printf("%d",j);
	//-----------------------------------------------------------
	double*p=NULL;
	start=clock();
		for(i=0;i<cycle;i++)
		{
			p=(double*)malloc(sizeof(double)*1000);
			free(p);
		}
	finish=clock();
	elapse=(double)(1000*(finish-start)/CLOCKS_PER_SEC);
	printf("1 billion malloc() ops time elapse:%5.1fms\n",elapse);
//--------------------------------------------------------------------
	p=(double*)malloc(sizeof(double)*1000);
	*p=100.09;
	*(p+1)=100.9;
	printf("%f\n",*p);
	printf("%f\n",*(p+1));
	printf("0x%X\n",p);
	printf("0x%X\n",p+1);
	free(p);

}
