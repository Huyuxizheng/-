#include"to2048moni.h"
extern void huizhidianqufan(uchar(*huanchong)[MAXH][MAXW / 8], char x, char y);

JIAODIAN _jiaodianA = { 4, 4 },//1�Ž���
_jiaodianB = { 0, 0 };//2�Ž���
uchar _jdA_1[] = { 0x00, 0x06, 0x02 };

uchar _jdA_lv[3];
uchar _jdA_hv[3];

//��ѯ1�Ž�������,��ϵͳ�Զ�����
uint _chaxunjiaodianA()
{
	uint a = 0;

	a |= _jiaodianA.x<<8;
	a |= _jiaodianA.y;

	return a;
}



//��ѯ1�Ž�������
void chaxunjiaodianA(ZJIAODIAN temp)
{
	temp->x = _jiaodianA.x;
	temp->y = _jiaodianA.y;
}

//��ʾ1�Ž���
void huizhijiaodianA(uchar *zt)
{
	huizhiqufan(huanchonghong, _jiaodianA.x - 1, _jiaodianA.y - 1,zt,3,1);
	huizhiqufan(huanchonglv, _jiaodianA.x - 1, _jiaodianA.y - 1, zt, 3, 1);
}

//����1�Ž���
void ggjiaodianA(char x, char y)
{
	if (x>=0 && x<MAXW)
	_jiaodianA.x = x;
	if (y >= 0 && y<MAXH)
	_jiaodianA.y = y;
}

//����ǰ
void huizhijdA_ONE()
{
	baocunquyu(_jiaodianA.x - 1, _jiaodianA.y - 1, _jdA_lv, _jdA_hv, 3, 1);

}

//���ƺ�
void huizhijdA_END()
{
	tanchuquyu(_jiaodianA.x - 1, _jiaodianA.y - 1, _jdA_lv, _jdA_hv, 3, 1);

}