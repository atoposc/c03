
#include<stdio.h>
#include<string.h>
int main()
{
	char ss[256],pp[256];
	char *s = 0;
	char *p = 0;
	char ch[3];//判断用户是否区分大小写
	int i = 0,j = 0,n = 0,word = 0;//n表示*中的字母个数，word表示p中的符号个数
	int flag1 = 0,flag2 = 0;//辅助判断s,p输入是否正确
	int time=0;
	s = ss;
	p = pp;
	while (flag1 == 0)//s的输入限制
	{
		printf("please input s=");
		gets(s);
		printf("\n");
		while (*s != '\0')
		{
			if (((*s >= 'a') && (*s <= 'z')) || ((*s >= 'A') && (*s <= 'Z')))
			{
				*s++;
			}
			else
			{
				printf("Error\n");
				break;
			}
			if(*s=='\0')
            {
                flag1 = 1;
            }
		}
	}
	while (flag2 == 0)//p的输入限制
	{
		printf("please input p=");
		gets(p);
		printf("\n");
		while (*p != '\0')
		{
			if (((*p >= 'a') && (*p <= 'z')) || ((*p >= 'A') && (*p <= 'Z')) || (*p == '.'))
			{
				p++;
				word++;//算出p的个数
			}
			else if (*p == '*')
			{
				p++;
			}
			else
			{
				printf("Error\n");
				break;
			}
			if(*p=='\0')
            {
                flag2 = 1;
            }
		}
	}
	printf("please choose 0 or 1(0代表不区分大小写，1代表区分大小写)");
	gets(ch);
	if(atoi(ch)==0)
    {
        strlwr(ss);
        strlwr(pp);
    }
	s = ss;
	p = pp;
	while (*s != '\0')//比较
	{
		while ((*p == *s)||(*p == '.')&&(*p!='\0'))
		{
			*p++;
			*s++;
			i++;
			j++;
			/*if ((*p == '.') && (((*s > 'a') && (*s < 'z')) || ((*s > 'A') && (*s < 'Z'))))
			{
				continue;
			}*/
			if (*p == '*'&&*s!='\0')
			{
				*p++;
				while(*p=='.'||*p=='*')
				{
				    if(*p=='.')
                    {
                        *p++;
                        *s++;
                        j++;
                    }
                    if(*p=='*')
                    {
                        *p++;
                    }
				}

				while ((*p != *s)&&(*s!='\0'))
				{
					*s++;
					i++;
					n++;
					j++;
				}

			}
			if (*p == '\0')
			{
				printf("the location is %d\n", j-word-n+1);
				time++;
				n = 0;

			}
			if(*s=='\0')
            {
                break;
            }
		}
		if (i != 0)
		{
            p=pp;
			s = s - i;
			j = j - i;
			i = 0;
		}
		*s++;
		j++;
	}
	if(time==0)
    {
        printf("No match is found");
    }
	getchar();
	return 0;
}
