#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int x,y;
	printf("enter the size of string : ");
	scanf("%d",&x);
	printf("enter the size of substring : ");
	scanf("%d",&y);
	if(x <=0 || y<=0)
	{
		printf("enter valid input");
	}
	else
	{
	char str1[x];
	scanf("%s",str1);
	char str2[y];
	scanf("%s",str2);
	int lps[y];
	int i=0,j,k;
	lps[0]=0;
	for(j=1;j<y;)
	{
		if(str2[i]==str2[j])
		{
			lps[j]=i+1;
			i++;
			j++;
		}
		else
		{
			if(i==0)
			{
				lps[j]=0;
				j++;
			}
			else
			i=lps[i-1];
		}
	}
	/*for(i=0;i<y;i++)
	{
		printf("%d   ",lps[i]);
	}*/
	j=0;
	for(i=0;i<(x+1);)
	{
		if(j>=y)
		{
		printf("found");
		break;	
		}
		if(str1[i]!=str2[j])
		{
			if(j==0)
			{
				i++;
			}
			else
			j=lps[j-1];
		}
		else
		{
			j++;
			i++;	
		}
	}
	if(j<y)
	printf("NOO");
	}
	return 0;
}
