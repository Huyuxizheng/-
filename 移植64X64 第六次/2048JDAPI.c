#include"to2048moni.h"
extern void huizhicachu(uchar(*huanchong)[MAXH][MAXW / 8], char x, char y, uchar(*temp)[], char h, char w);
extern void huizhihuizhi(uchar(*huanchong)[MAXH][MAXW / 8], char x, char y, uchar(*temp)[], char h, char w);
extern void huizhiqufan(uchar(*huanchong)[MAXH][MAXW / 8], char x, char y, uchar(*temp)[], char h, char w);
JIAODIANS _jiaodianA = { _jdA_1, 3, 1, 3, 3, 4, 4, -1, -1 };//1�Ž���
uchar _jdA_1[] = { 0x00, 0x06, 0x02 };
uchar _jdA_2[] = { 0x02, 0x07, 0x02 };
uchar _jdA_lv[3];
uchar _jdA_hong[3];

//��ѯ1�Ž�������,��ϵͳ�Զ�����
uint chaxunjiaodian_A()
{
	uint a = 0;
	a |= _jiaodianA.x<<8;
	a |= _jiaodianA.y;

	return a;
}



//��ѯ1�Ž�������
void chaxunjiaodianA(ZJIAODIANS temp)
{
	temp->x = _jiaodianA.x;
	temp->y = _jiaodianA.y;
}

//��ʾ����
void huizhijiaodian(ZJIAODIANS temp,uchar se)
{
	//��������ɫ��Ϣ
	switch (se)
	{
	case 8:

		huizhiqufan(huanchonghong, temp->xi, temp->yi, temp->ysi, temp->h, temp->w);
		huizhiqufan(huanchonglv, temp->xi, temp->yi, temp->ysi, temp->h, temp->w);
		break;

	case 0:
		huizhicachu(huanchonghong, temp->xi, temp->yi, temp->ysi, temp->h, temp->w);
		huizhihuizhi(huanchonglv, temp->xi, temp->yi, temp->ysi, temp->h, temp->w);
		break;

	case 1:

		huizhihuizhi(huanchonghong, temp->xi, temp->yi, temp->ysi, temp->h, temp->w);
		huizhicachu(huanchonglv, temp->xi, temp->yi, temp->ysi, temp->h, temp->w);
		break;
	case 3:

		huizhihuizhi(huanchonghong, temp->xi, temp->yi, temp->ysi, temp->h, temp->w);
		huizhihuizhi(huanchonglv, temp->xi, temp->yi, temp->ysi, temp->h, temp->w);
		break;
	case 4:

		huizhihuizhi(huanchonglv, temp->xi, temp->yi, temp->ysi, temp->h, temp->w);
		break;
	case 5:

		huizhihuizhi(huanchonghong, temp->xi, temp->yi, temp->ysi, temp->h, temp->w);
		break;
	case 6:

		huizhiqufan(huanchonglv, temp->xi, temp->yi, temp->ysi, temp->h, temp->w);
		break;
	case 7:

		huizhiqufan(huanchonghong, temp->xi, temp->yi, temp->ysi, temp->h, temp->w);
		break;
	}

}

//�ı佹����ʽ
void ggysijiaodian(ZJIAODIANS temp, uchar(*ysi)[], uchar h, uchar w)
{
	temp->ysi = ysi;
	temp->h = h;
	temp->w = w;
}

//���Ľ����е�
void ggzongdian(ZJIAODIANS temp, char qzx, char qzy)
{
	temp->qzx = qzx;
	temp->qzy = qzy;
	temp->xi = temp->x + qzx;
	temp->yi = temp->y + qzy;
}

//���Ľ���
void ggjiaodian(ZJIAODIANS temp, char x, char y)
{
	if (x >= 0 && x < MAXW)
	{
		temp->x = x;
		temp->xi = x + temp->qzx;
	}
	if (y >= 0 && y < MAXH)
	{		
		temp->y = y;
		temp->yi = y + temp->qzy;
	}
}

//ͨ��ƫ�����ı佹��
void gbjiaodian(ZJIAODIANS temp, char xi, char yi)
{
	if (temp->x + xi >= 0 && temp->x + xi < MAXW)
	{
		temp->x += xi;
		temp->xi += xi;
	}
	if (temp->y + yi >= 0 && temp->y + yi  < MAXH)
	{
		temp->y += yi;
		temp->yi += yi;
	}
}
//����ǰ
void huizhijd_ONE(ZJIAODIANS temp, uchar (*tutemplv)[], uchar (*tutemphong)[])
{
	baocunquyu(temp->xi, temp->yi, tutemplv, tutemphong, temp->h, temp->w);

}

//���ƺ�
void huizhijd_END(ZJIAODIANS temp, uchar(*tutemplv)[], uchar(*tutemphong)[])
{
	tanchuquyu(temp->xi, temp->yi, tutemplv, tutemphong, temp->h, temp->w);

}