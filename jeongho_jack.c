#include <stdio.h>
#include <stdlib.h>

typedef struct chipinfo {
	int total_chip;
	int bet;
	char name[30];
} CINFO;

int main(void) {

	int i;
	int peo_num;
	int total_score;
	int total_bet;
	int winner;
	int loser;
	char winner_name[30] = { 0 };
	CINFO* p;

	printf("몇명에서 플레이 하는가?");
	scanf_s("%d", &peo_num);
	p = (CINFO*)calloc(peo_num, sizeof(CINFO));

	printf("이름 입력 : \n");
	for (i = 0; i < peo_num; i++)
	{
		scanf_s("%s", p[i].name, sizeof(p[i].name));
	}

	printf("1인당 총 칩 갯수 : ");
	scanf_s("%d", &total_score);
	for (i = 0; i < peo_num; i++)
	{
		p[i].total_chip = total_score;
	}

	while (1)
	{
		if (peo_num == 2)
		{
			printf("\n\t%s \t%s\n", p[0].name, p[1].name);
			printf("칩 갯수 %d \t%d\n", p[0].total_chip, p[1].total_chip);

			printf("\n배팅 수\n");
			for (i = 0; i < peo_num; i++)
			{
				printf("%s : ", p[i].name);
				scanf_s("%d", &p[i].bet);
			}

			printf("이긴 사람 : ");
			scanf_s("%d", &winner);
			printf("\n");
			winner = winner - 1;
			total_bet = p[0].bet + p[1].bet - p[winner].bet;
			for (i = 0; i < 2; i++)
			{
				if (winner == i)
					p[winner].total_chip += total_bet;
				else
					p[i].total_chip -= p[i].bet;
			}

			for (i = 0; i < peo_num; i++)
			{
				if (p[i].total_chip == 0)
					break;
			}
		}
		if (peo_num == 3)
		{
			printf("\t%s \t%s \t%s\n", p[0].name, p[1].name, p[2].name);
			printf("칩 갯수 %d \t%d \t%d\n", p[0].total_chip, p[1].total_chip, p[2].total_chip);
			printf("배팅 수\n");
			for (i = 0; i < peo_num; i++)
			{
				printf("%s : ", p[i].name);
				scanf_s("%d", &p[i].bet);
			}
			printf("이긴 사람 : ");
			scanf_s("%d", &winner);
			printf("\n");
			winner = winner - 1;
			total_bet = p[0].bet + p[1].bet + p[2].bet - p[winner].bet;
			for (i = 0; i < 3; i++)
			{
				if (winner == i)
					p[winner].total_chip += total_bet;
				else
					p[i].total_chip -= p[i].bet;
			}

			for (i = 0; i < peo_num; i++)
			{
				if (p[i].total_chip == 0)
					break;
			}
		}
		if (peo_num == 4)
		{
			printf("\t%s \t%s \t%s \t%s\n", p[0].name, p[1].name, p[2].name, p[3].name);
			printf("칩 갯수 %d \t%d \t%d \t%d\n", p[0].total_chip, p[1].total_chip, p[2].total_chip, p[3].total_chip);
			printf("배팅 수\n");
			for (i = 0; i < peo_num; i++)
			{
				printf("%s : ", p[i].name);
				scanf_s("%d", &p[i].bet);
			}

			printf("이긴 사람 : ");
			scanf_s("%d", &winner);
			printf("\n");
			winner = winner - 1;
			total_bet = p[0].bet + p[1].bet + p[2].bet + p[3].bet - p[winner].bet;
			for (i = 0; i < 4; i++)
			{
				if (winner == i)
					p[winner].total_chip += total_bet;
				else
					p[i].total_chip -= p[i].bet;
			}

			for (i = 0; i < peo_num; i++)
			{
				if (p[i].total_chip == 0)
					break;
			}
		}
	}

	if (peo_num == 2)
	{
		if (p[0].total_chip < p[1].total_chip)
		{
			winner = 1;
			loser = 0;
		}
		else
		{
			winner = 0;
			loser = 1;
		}
	}
	else if (peo_num == 3)
	{
		if (p[0].total_chip < p[1].total_chip)
			winner = 1;
		else
			winner = 0;
		if (p[winner].total_chip < p[2].total_chip)
			winner = 2;
		for (i = 0; i < peo_num; i++)
		{
			if (p[i].total_chip == 0)
				loser = i;
		}
	}
	else if (peo_num == 4)
	{
		if (p[0].total_chip < p[1].total_chip)
			winner = 1;
		else
			winner = 0;
		if (p[winner].total_chip < p[2].total_chip)
			winner = 2;
		if (p[winner].total_chip < p[3].total_chip)
			winner = 3;
		for (i = 0; i < peo_num; i++)
		{
			if (p[i].total_chip == 0)
			loser = i;
		}
	}
	printf("++++++== winner ==++++++\n");
	printf("         %s\n", p[winner].name);
	printf("++++++== loser ==++++++\n");
	printf("         %s\n", p[loser].name);
	free(p);
	return 0;
}