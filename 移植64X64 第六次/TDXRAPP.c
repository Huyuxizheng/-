#include"to2048moni.h"
#include"2048SJK.h"


uchar TD_1[] = { 0x18, 0x24, 0x18, 0x3C, 0x5A, 0xA5, 0x24, 0x24 };//�϶�1
uchar TD_2[] = { 0x58, 0x64, 0x58, 0x3C, 0x1A, 0x25, 0x24, 0x24 };//�϶�2
uchar TD_3[] = { 0x58, 0x64, 0x58, 0x3C, 0x1C, 0x1C, 0x18, 0x18 };//�϶�3


HUAKUAI xr = { 27, 27, 35, 35, 27, 27, 35, 35, TD_1, SE_LVTOU, TD_2, SE_LVTOU, TD_3, SE_LVTOU, 8, 1, 1};//����ṹ

//�϶��ײ����
void tuodongappdc()
{
		shuaping(SE_HEI);
	kjhuakuai(&xr, NOP, NOP, NOP);
	fuweizhuangtaibiao();
		dalogo();
		tuichujian(NOP, NOP, NOP, NOP);
		tongbujiemian(J_Z);
}

//�϶���Ϣ�����
char yucey[] = { 0, 1, 0, -1, 0 };
char yucex[] = { 0, 0, -1, 0, 1 };
void tuodongappzc(uchar xiaoxi, char x, char y)
{
	if(S5)
	{
	kjhuakuai(&xr, 7, x, y);
	}

	if ((xr.xz != 3) || gjjuxingjiance(x + yucex[xiaoxi], y + yucey[xiaoxi], 8, 0, 61, 48))
	{
	if (xiaoxi == 6 && gjjuxingjiance(x,y,xr.w,xr.n,xr.e,xr.s))
	ggjiaodian(&JDA_Z, xr.e - 2, xr.n - 2);
	
	kjhuakuai(&xr, xiaoxi, x, y);
	morenchuli(xiaoxi);
	}
	tuichujian(xiaoxi, x, y, 1);


}