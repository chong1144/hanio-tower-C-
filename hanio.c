#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
//system("CLS"); // ���� 
//system("pause");//��ͣ5��
// fflush(stdin);������뻺���
int N = 3;
//���ݴ洢����

int a_key; int b_key; int c_key;
//��¼����λ��
int a_k; int b_k; int c_k;//��¼�����ɹ�ʱ����λ��
int exchange;

int a[10];
int b[10];
int c[10];
void han(int n, int a, int b, int c, FILE *Fp)
{
	void textmove(int x, int y, FILE *Fp);
	if (n == 1)textmove(a, c, Fp);
	else
	{
		han(n - 1, a, c, b, Fp);
		textmove(a, c, Fp);
		han(n - 1, b, a, c, Fp);

	}
}

void textmove(int x, int y, FILE *Fp)
{
	//Fp = fopen("solution", "a+");
	//int err = 1;
	//fopen_s(&Fp, "solution.txt", "a+");
	//printf("Fp = %d\n", Fp);
	//printf("%d+%d\n", x, y);
	/*
	if (!err)
	{
	printf("Connot open the file!\n");
	exit(0);
	}
	*/
	/*
	fputc(x, Fp);
	fputc('+', Fp);
	fputc(y, Fp);
	fputc('\n', Fp);error
	*/
	fprintf_s(Fp, "%d+%d\n", x, y);
	//fclose(Fp);


}

void initialize_fc(int an[], int bn[], int cn[])
{
	int t;
	for (t = 0; t < N; t++)
	{
		an[t] = t + 1;
		bn[t] = 0;
		cn[t] = 0;

	}

}

void printf_fc()  //���ˢ��
{
	int i;
	for (i = 0; i <N; i++)
	{
		printf("%4d     %4d     %4d\n", a[i], b[i], c[i]);
	}
	printf("_______  _______  _______\n");
	printf("stack_1  stack_2  strck_3\n\n");
}

int move_fc(int an, int bn)
{
	if (an == bn&&an!=4)
	{
		printf("Are you kidding me!How can you do this?\n");
		system("pause"); return 0;
	}
	if (!((an >= 1 && an <= 4) && (bn >= 1 && bn <= 4)))
	{
		printf("Input error!\nThe stcak_%d or stack_%d don't exist!\n",an,bn);
		system("pause");
		return 0;
	}
	if (an == 1)
	{
		if (bn == 2)
		{
			if (b[N - 1] == 0)
			{//printf("a[%d] = %d\n",a_k,a[a_k]);
				a[a_k] = 0;
				b[b_key] = exchange;
				return 1;
			}
			else
			{
				if (exchange != 0)
				{
					if (exchange < b[b_key + 1])
					{
						a[a_k] = 0;
						//printf("a[%d] = %d\n",a_k,a[a_k]);
						b[b_key] = exchange; return 1;
					}
					else
					{
						printf("Input Error: Movement disobeyed the hanio's rules!\n");
						printf("      The moved number > arrive stack_%d top number!\n", bn);
						system("pause");
						return 0;
					}
				}
				else
				{
					printf("Input Error: Movement disobeyed the hanio's rules!\n");
					printf("      Stack_%d don't have numbers!\n", an);
					system("pause"); return 0;
				}
			}
		} //if bn==2 over
		else if (bn == 3)
		{
			if (c[N - 1] == 0)
			{
				a[a_k] = 0;
				//printf("a[%d] = %d\n",a_k,a[a_k]);
				c[c_key] = exchange; return 1;
			}
			else
			{
				if (exchange != 0)
				{
					if (exchange < c[c_key + 1])
					{
						a[a_k] = 0;
						//printf("a[%d] = %d\n",a_k,a[a_k]);
						c[c_key] = exchange; return 1;
					}
					else
					{
						printf("Input Error: Movement disobeyed the hanio's rules!\n");
						printf("      The moved number > arrive stack_%d top number!\n", bn);
						system("pause"); return 0;
					}
				}
				else
				{
					printf("Input Error: Movement disobeyed the hanio's rules!\n");
					printf("      Stack_%d don't have numbers!\n", an);
					system("pause"); return 0;
				}
			}
		}//if bn == 3 over;
	} //an over
	else if (an == 2)
	{
		if (bn == 1)
		{
			if (a[N - 1] == 0)
			{
				b[b_k] = 0;
				//printf("b[%d] = %d\n",b_k,b[b_k]);
				a[a_key] = exchange; return 1;
			}
			else
			{
				if (exchange != 0)
				{
					if (exchange < a[a_key + 1])
					{
						b[b_k] = 0;
						//printf("b[%d] = %d\n",b_k,b[b_k]);
						a[a_key] = exchange; return 1;
					}
					else
					{
						printf("Input Error: Movement disobeyed the hanio's rules!\n");
						printf("      The moved number > arrive stack_%d top number!\n", bn);
						system("pause"); return 0;
					}
				}
				else
				{
					printf("Input Error: Movement disobeyed the hanio's rules!\n");
					printf("      Stack_%d don't have numbers!\n", an);
					system("pause"); return 0;
				}
			}
		}//bn==1 over
		else if (bn == 3)
		{
			if (c[N - 1] == 0)
			{
				b[b_k] = 0;
				//printf("b[%d] = %d\n",b_k,b[b_k]);
				c[c_key] = exchange; return 1;
			}
			else
			{
				if (exchange != 0)
				{
					if (exchange < c[c_key + 1])
					{
						b[b_k] = 0;
						//printf("b[%d] = %d\n",b_k,b[b_k]);
						c[c_key] = exchange; return 1;
					}
					else
					{
						printf("Input Error: Movement disobeyed the hanio's rules!\n");
						printf("      The moved number > arrive stack_%d top number!\n", bn);
						system("pause"); return 0;
					}
				}
				else
				{
					printf("Input Error: Movement disobeyed the hanio's rules!\n");
					printf("      Stack_%d don't have numbers!\n", an);
					system("pause"); return 0;
				}
			}
		}//bn ==3 over
	}// an ==2 over
	else if (an == 3)
	{
		if (bn == 1)
		{
			if (a[N - 1] == 0)
			{
				c[c_k] = 0;
				//printf("c[%d] = %d\n",c_k,c[a_k]);
				a[a_key] = exchange; return 1;
			}
			else
			{
				if (exchange != 0)
				{
					if (exchange < a[a_key + 1])
					{
						c[c_k] = 0;
						//printf("a[%d] = %d\n",a_k,a[a_k]);
						a[a_key] = exchange; return 1;
					}
					else
					{
						printf("Input Error: Movement disobeyed the hanio's rules!\n");
						printf("      The moved number > arrive stack_%d top number!\n", bn);
						system("pause"); return 0;
					}
				}
				else
				{
					printf("Input Error: Movement disobeyed the hanio's rules!\n");
					printf("      Stack_%d don't have numbers!\n", an);
					system("pause"); return 0;
				}
			}
		}//bn == 1 over
		else if (bn == 2)
		{
			if (b[N - 1] == 0)
			{
				c[c_k] = 0;
				//printf("a[%d] = %d\n",a_k,a[a_k]);
				b[b_key] = exchange; return 1;
			}
			else
			{
				if (exchange != 0)
				{
					if (exchange < b[b_key + 1])
					{
						c[c_k] = 0;
						//printf("a[%d] = %d\n",a_k,a[a_k]);
						b[b_key] = exchange; return 1;
					}
					else
					{
						printf("Input Error: Movement disobeyed the hanio's rules!\n");
						printf("      The moved number > arrive stack_%d top number!\n", bn);
						system("pause"); return 0;
					}
				}
				else
				{
					printf("Input Error: Movement disobeyed the hanio's rules!\n");
					printf("      Stack_%d don't have numbers!\n", an);
					system("pause"); return 0;
				}
			}
		}
	}//an ==3 over
}


void search(int ax, int bx)
{
	int i = 0;
	if (ax == 1)
	{
		do
		{
			exchange = a[i];
			//printf("exchange = %d\n",exchange);
			i = i + 1;
			a_k = i - 1;
			if (exchange != 0)break;
		} while (i<N);//ȷ������a[]��ʼ��ֵ

		i = 0;
		//	printf("a_k =%d\n",a_k);//��¼�����ɹ�ʱ����λ��a[a_k]
		//	printf("a[a_k] = exchange= %d\n",a[a_k]);
		if (bx == 2)
		{
			do
			{
				b_key = i;
				i = i + 1;
				if (b[i] != 0)break;
			} while (i<N);
			i = 0;
			//	printf("b_key = %d\n",b_key);//ȷ������b[]�����

		}
		else if (bx == 3)
		{
			do
			{
				c_key = i;
				i++;
				if (c[i] != 0)break;
			} while (i<N);
			i = 0;
			//		printf("c_key =%d\n",c_key);//ȷ������C[]�����
		}
	}//if(an ==1) over
	else if (ax == 2)
	{
		do
		{
			exchange = b[i];
			//  printf("exchange = %d\n",exchange);
			i++;
			b_k = i - 1;//i++ and b_k = i-1 can be writen as b_k = i++;
			if (exchange != 0)break;
		} while (i<N);//ȷ������b[]��ʼ��ֵ

		i = 0;
		//	  printf("b_k = %d\n",b_k);//��¼�����ɹ�ʱ����λ��b[b_k]
		//	  printf("b[b_k] = %d\n",b[b_k]);
		if (bx == 1)
		{
			do
			{
				a_key = i;
				i++;
				if (a[i] != 0)break;
			} while (i<N);//ȷ������A[]�����
			i = 0;
			//		printf("a_key = %d\n",a_key);
		}
		else if (bx == 3)
		{
			do
			{
				c_key = i;
				i++;
				if (c[i] != 0)break;
			} while (i<N);//ȷ������b[]�����
			i = 0;
			//		printf("c_key = %d\n",c_key);
		}
	}//if(an==2) over	
	else if (ax == 3)
	{
		i = 0;
		do
		{
			exchange = c[i];
			//printf("exchange = %d\n",exchange);
			i++;
			c_k = i - 1;
			if (exchange != 0)break;
		} while (i<N);//ȷ������b[]��ʼ��ֵ
		i = 0;
		//		printf("c_k = %d\n",c_k);//��¼�����ɹ�ʱ����λ��c[c_k]
		//		printf("c[a_k] = %d\n",c[a_k]);
		if (bx == 1)
		{
			do
			{
				a_key = i;
				i++;
				if (a[i] != 0)break;
			} while (i<N);//ȷ������A[]�����
			i = 0;
			//			printf("a_key = %d\n",a_key);
		}
		else if (bx == 2)
		{
			do
			{
				b_key = i;
				i++;
				if (b[i] != 0)break;
			} while (i<N);//ȷ������b[]�����
			i = 0;
			//		printf("b_key = %d\n",b_key);
		}
	}// if(an == 3 )over
}//fuction search

void pr_table()
{
	printf("          Hanio Tower\n");
	printf(" ________________________________\n");
	printf("|   1.Start/Retart the game!     |\n");
	printf("|   2.Select level of the game!  |\n");
	printf("|   3.For help and information!  |\n");
	printf("|   4.solution of hanio tower!   |\n");
	printf("|   5.Exit the game!             |\n");
	printf("|________________________________|\n\n");

}

void pr_help()
{
	printf("Hanio-Two's rule:\n");
	printf("  1.��stack_1 �����з������ƶ���stack_3����˳��һ��,������Ϸ!\n");
	printf("   Input A-B to move the number!\n   E.g.:'1+3'means move the stack_1's number to stack_3.\n");
	printf("  2.��ֵ��С�������ڴ���֮�ϵ��ƶ�Ϊһ�γɹ����ƶ�!\n");
	printf("  3.��stack_*ȫΪ0,��Ϊ��,����������������stack�ķ���ֵ!\n");
	printf("  4.The intial leavl is level_3,and the highest level is level_9!\n");
	printf("  5.�����̴����solution.txt��,Ҫ�鿴���ֶ���!\n");
	printf("  6.Made by һ����T_T\n");

}

void main()
{
	int ai, bi, table_key; float aii = 0, bii = 0; char quit = 'n';
	//extern void textmove(int x, int y, FILE *Fp);
	//extern void han(int n, int a, int b, int c, FILE *Fp);
	//N = 5;
 initialize_fc(a, b, c);
	pr_table();
	printf_fc();

table_error: printf("Select the menu number to do sth!\nYou selected number is:");

	scanf_s("%d", &table_key); fflush(stdin);
	fflush(stdin);
	table_key = (int)table_key;
	if (table_key >= 1 && table_key <= 5)
	{
		switch (table_key)
		{
		case 1:{
			while (1)
			{
			move_error:	system("CLS");
				
				printf_fc();
				printf("Input A+B to move the number!---Gaming---Level %d---\nE.g.:'1+3'means move the stack_1's number to stack_3!\n", N);
				printf("Input 4+4 toback to main menu!\n");
				scanf_s("%f+%f", &aii, &bii); fflush(stdin);
				ai = (int)aii; bi = (int)bii;
				//printf("ai =%d,bi =%d\n",ai,bi);
				search(ai, bi);
				if (ai == 4 && bi == 4)
				{
					printf("Do you want to quit and initialize the game?\nInput :Y or y to quit,others to continue!---:");
					
					quit = getchar(); fflush(stdin);
				//	printf("quit = %c\n", quit); system("pause");
					if (quit == 'Y' || quit == 'y')
					{
						initialize_fc(a,b,c);
						pr_table();
						goto table_error;
					}

				}
					if (move_fc(ai, bi)){}
					else goto move_error;
				
				if (c[0] != 0)
				{
					system("CLS");
					printf("This level has complete!\n");
					printf_fc();
					N = N + 1;
					printf("Level has auto upgrade!\n");
					initialize_fc(a, b, c);
					printf_fc();
					pr_table();
					goto table_error;
				}

			}//while over
		}
		case 2:{	system("CLS"); // ���� 		 
			printf("Input a number from 3 to 9 to change the level!\n");
		lv_out:  printf("The level is:");
			scanf_s("%d", &N); fflush(stdin);
			if (N >= 3 && N <= 9)
			{
				printf("The level has changed!\n");
				initialize_fc(a, b, c);
				printf_fc();
			}
			else
			{
				printf("Input Error: The level that inputed was out of range(3~9)!\n");
				printf("Reinput a number from 3 to 9 to change the level!\n");
				goto lv_out;
			}
			pr_table();
			goto table_error;
		}
		case 3:{pr_help(); goto table_error; }
		case 4:{printf("�����̻�д��һ����Ϊsolution.txt���ĵ���!\n");
				printf("�ļ�·����hanio.exe·��һ��!\n");
				int m = 0; errno_t err; FILE *Fp;
				err = fopen_s(&Fp, "solution.txt", "a+");
				//printf("err = %d\n Fp = %x\n", err, Fp);
				//	fclose(fp);
			merr:	printf("������Ҫ���ĺ�ŵ������:");
				scanf_s("%d", &m); fflush(stdin);
				if (!(m >= 3 && m <= 9))
				{
					printf("�����������,��������!\n");
						goto merr;
				}
				fprintf_s(Fp, "%d �㺺ŵ��������:\n", m);

				han(m, 1, 2, 3, Fp);
				fclose(Fp);
				goto table_error;
				}
		case 5:{break; }

		}
	}
	else
	{
		printf("Input Error: Don't exit the option!\n");
		printf("Please reinput the option number:");
		goto table_error;

	}
}
