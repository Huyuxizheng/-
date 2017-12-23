#include"to2048moni.h"
#include"2048SJK.h"

code uchar HB_anniu_1[] =  { 0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00 };/*��ɫ1*/
code uchar HB_anniu_2[] =  { 0x00, 0x18, 0x3C, 0x7E, 0x7E, 0x3C, 0x18, 0x00 };/*��ɫ2*/
code uchar HB_anniu_3[] =  { 0xFF, 0x99, 0xBD, 0xFF, 0xFF, 0xBD, 0x99, 0xFF };/*��ɫ3*/
code uchar HB_anniu_4[] =  { 0x00, 0x00, 0x00, 0x14, 0x1C, 0x14, 0x00, 0x00 };/*��Ƥ1*/
code uchar HB_anniu_5[] =  { 0x00, 0x00, 0x24, 0x3C, 0x24, 0x24, 0x00, 0x00 };/*��Ƥ2*/
code uchar HB_anniu_6[] =  { 0xFF, 0x81, 0xA5, 0xBD, 0xA5, 0xA5, 0x81, 0xFF };/*��Ƥ3*/
code uchar HB_anniu_7[] =  { 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00 };/*��11*/
code uchar HB_anniu_8[] =  { 0xFF, 0x81, 0x81, 0x89, 0x81, 0x81, 0x81, 0xFF };/*��12*/
code uchar HB_anniu_10[] = { 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00 };/*��21*/
code uchar HB_anniu_11[] = { 0xFF, 0x81, 0x81, 0x99, 0x99, 0x81, 0x81, 0xFF };/*��22*/
code uchar HB_anniu_12[] = { 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00 };/*��31*/
code uchar HB_anniu_13[] = { 0xFF, 0x81, 0x81, 0xB9, 0xB9, 0xB9, 0x81, 0xFF };/*��32*/
code uchar HB_anniu_14[] = { 0x01 };/*��1*/
code uchar HB_anniu_15[] = { 0x03, 0x03 };/*��2*/
code uchar HB_anniu_16[] = { 0x07, 0x07, 0x07 };/*��3*/
  //  ****��ť�ṹ****  //
 ANNIU lv =     { 0, 0, 8, 8, HB_anniu_1, SE_LVTOU, HB_anniu_2, SE_LVTOU, HB_anniu_3, SE_LVTOU, 8, 1, 1 };
 ANNIU hong =   { 0, 8, 8, 16, HB_anniu_1, SE_HONGTOU, HB_anniu_2, SE_HONGTOU, HB_anniu_3, SE_HONGTOU, 8, 1, 1 };
 ANNIU cheng =  { 0, 16, 8, 24, HB_anniu_1, SE_CHENG, HB_anniu_2, SE_CHENG, HB_anniu_3, SE_CHENG, 8, 1, 1 };
 ANNIU hc =     { 0, 24, 8, 32, HB_anniu_4, SE_CHENG, HB_anniu_5, SE_HONGTOU, HB_anniu_6, SE_CHENG, 8, 1, 1 };
 ANNIU xi =     { 0, 32, 8, 40, HB_anniu_7, SE_LVTOU, HB_anniu_7, SE_HONGTOU, HB_anniu_8, SE_CHENG, 8, 1, 1 };
 ANNIU zhong =  { 0, 40, 8, 48, HB_anniu_10, SE_LVTOU, HB_anniu_10, SE_HONGTOU, HB_anniu_11, SE_CHENG, 8, 1, 1 };
 ANNIU cu =     { 0, 48, 8, 56, HB_anniu_12, SE_LVTOU, HB_anniu_12, SE_HONGTOU, HB_anniu_13, SE_CHENG, 8, 1, 1 };
 //***********//
 
 //��ϰ�ť�ṹ//
 ZANNIU hbanniu[] = { &lv, &hong, &hc, &cheng};
 ZANNIU hbanniu2[] = { &xi, &zhong, &cu};
 
 //��������ָ�� ��ѯ��
 uchar *hbt[] = { HB_anniu_14, HB_anniu_15, HB_anniu_16 };
 uchar hbh[] = { 1, 2, 3 };
 
 //��Ӧ��ר�ñ�־λ
uchar z1 = NOP;
uchar z2 = NOP;
void hubandicen()
{//����ײ�
	 shuaping(SE_HEI);
	zuheanniu(hbanniu, NOP, NOP, NOP, 4, &z1);//��ʼ����ϰ���
	zuheanniu(hbanniu2, NOP, NOP, NOP, 3, &z2);
	
	fuweizhuangtaibiao();//��ʼ��״̬���־λ
	 z1 = NOP;
   z2 = NOP;
	
	xiugaizhuangtaibiao(NOP, 7);//ռ��״̬�����λ ��Ϊ��Ӧ�ñ�־����
	xiugaizhuangtaibiao(NOP, 6);
	
		dalogo();//��LOGO
	
		tuichujian(NOP, NOP, NOP, NOP);//��ʼ���˳���
	
		tongbujiemian(J_Z);//��ɵײ���� ͬ������
}
void huabanxiaoxichuliceng(uchar xiaoxi,char x,char y)
{//������Ϣ�����
	zuheanniu(hbanniu, xiaoxi, x, y, 4, &z1);//��Ӧ��ϰ�����Ϣ
	zuheanniu(hbanniu2, xiaoxi, x, y, 3, &z2);
	
	//������Ԫ���Ƿ�������
	if (z1 != NOP && z2 != NOP)
	if (xiaoxi == 5)
	if (gjjuxingjiance(x,y,9,0,64,56))
	if (chaxunzhuangtaibiao(6) != x || chaxunzhuangtaibiao(7) != y)
	{
		//�������λ������
		shezhihuizhiquyu(9, 0, 64, 57);
		shezhihuabiyanse(z1);
		huizhiex(x, y, hbt[z2],hbh[z2] , 1 );
		xiugaizhuangtaibiao(NOP, 7);
		xiugaizhuangtaibiao(NOP, 6);
	}
	
		tuichujian(xiaoxi, x, y, 1);//��Ӧ�˳�����Ϣ
	
		morenchuli(xiaoxi);//������Ϣ��ϵͳĬ�Ϸ�������
}
void huabanfudongceng1()
{//���帡����1
//������������Ҫ��APP�����һ�����񶼲����ڴ˲����
}
void huabanfudongceng2()
{//���帡����2
//������������Ҫ��APP�����һ�����񶼲����ڴ˲����
}