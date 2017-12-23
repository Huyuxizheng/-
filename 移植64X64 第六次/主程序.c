
#include"to2048moni.h"
#include"2048SJK.h"
#include"2048HBAPP.h"
#include"TDXRAPP.h"
JIAODIANS jiaodian_b = {jb_t_1,11,2,0,0,0,0,0,0};

ZANCUN i = {{ 0 }, { 0 } };


void Main_Xiaoxi()
{
if(!S1)
charuxiaoxi(END,1);

if(!S2)
charuxiaoxi(END,2);

if(!S3)
charuxiaoxi(END,3);

if(!S4)
charuxiaoxi(END,4);

if(!S5)
{ if(chaxunzhuangtaibiao(1) == 0)
		{charuxiaoxi(END,6);xiugaizhuangtaibiao(1,1);}
	charuxiaoxi(END,5);
}
if(chaxunzhuangtaibiao(1))
	if(S5)
	{charuxiaoxi(END,7);xiugaizhuangtaibiao(0,1);}
	
}
void MainPing_D(char dizhi)
{
	switch (dizhi)
	{
	case 1:
		shuaping(SE_HEI);
		shezhihuabiyanse(SE_LVTOU);
		huizhi(2, 2, t_mnu_0, 7, 1);
		huizhi(12, 2, t_mnu_1, 7, 1);
		huizhi(22, 2, t_mnu_2, 7, 1);
		huizhi(32, 2, t_mnu_3, 7, 1);
		huizhi(2, 13, t_mnu_4, 7, 1);
		huizhi(12, 13, t_mnu_5, 7, 1);
		huizhi(22, 13, t_mnu_6, 7, 1);
	  huizhi(32, 13, t_mnu_7, 7, 1);
		huizhi(2, 24, t_mnu_8, 7, 1);
		huizhi(12, 24, t_mnu_9, 7, 1);
		dalogo();
	  fuweizhuangtaibiao();
	  xiugaizhuangtaibiao(NOP,7);
		xiugaizhuangtaibiao(0,6);
		tongbujiemian(J_Z);
		break;
	case 2:

			hubandicen();

		break;
	case 3:

		tuodongappdc();

		break;
	case 4:
		shuaping(SE_HEI);
		huizhi(28, 28, t_mnu_2, 7, 1);
		dalogo();
		tuichujian(NOP, NOP, NOP, NOP);
		tongbujiemian(J_Z);
		break;
	case 5:
		shuaping(SE_HEI);
		huizhi(28, 28, t_mnu_3, 7, 1);
		dalogo();
		tuichujian(NOP, NOP, NOP, NOP);
		tongbujiemian(J_Z);
		break;
	case 6:
		shuaping(SE_HEI);
		huizhi(28, 28, t_mnu_4, 7, 1);
		dalogo();
		tuichujian(NOP, NOP, NOP, NOP);
		tongbujiemian(J_Z);
		break;
	case 7:
		shuaping(SE_HEI);
		huizhi(28, 28, t_mnu_5, 7, 1);
		dalogo();
		tuichujian(NOP, NOP, NOP, NOP);
		tongbujiemian(J_Z);
		break;
	case 8:
		shuaping(SE_HEI);
		huizhi(28, 28, t_mnu_6, 7, 1);
		dalogo();
		tuichujian(NOP, NOP, NOP, NOP);
		tongbujiemian(J_Z);
		break;
	case 9:
		shuaping(SE_HEI);
		huizhi(28, 28, t_mnu_7, 7, 1);
		dalogo();
		tuichujian(NOP, NOP, NOP, NOP);
		tongbujiemian(J_Z);
		break;
	case 10:
		shuaping(SE_HEI);
		huizhi(28, 28, t_mnu_8, 7, 1);
		dalogo();
		tuichujian(NOP, NOP, NOP, NOP);
		tongbujiemian(J_Z);
		break;
	case 11:
		shuaping(SE_HEI);
		huizhi(28, 28, t_mnu_9, 7, 1);
		dalogo();
		tuichujian(NOP, NOP, NOP, NOP);
		tongbujiemian(J_Z);
		break;
	}
}
void MainPing_Z(char dizhi, uchar x_xiaoxi, uint JA_XY)
{
	uint z;
	char x = (JA_XY >> 8), y = JA_XY;
	switch (dizhi)
	{
	case 1:
		//´¦ÀíÊó±ê
		switch (x_xiaoxi)
		{
		case 7:
			switch (z = gjwanggejiance(x, y, 10, 11))
			{
			case WGJC(0, 0):
			case WGJC(1, 0):
			case WGJC(2, 0):
			case WGJC(3, 0):
			case WGJC(0, 1):
			case WGJC(1, 1):
			case WGJC(2, 1):
			case WGJC(3, 1):
			case WGJC(0, 2):
			case WGJC(1, 2):
				xiugaijiemian(WGJCY(z) * 4 + WGJCX(z) + 2, J_Z);
				break;
			}

		}
		
		morenchuli(x_xiaoxi);
		break;
	case 2:
		huabanxiaoxichuliceng(x_xiaoxi, x, y);

		break;
	case 3:
		tuodongappzc(x_xiaoxi, x, y);

		break;
	case 4:
		tuichujian(x_xiaoxi, x, y, 1);
		morenchuli(x_xiaoxi);
		break;
	case 5:
		tuichujian(x_xiaoxi, x, y, 1);
		morenchuli(x_xiaoxi);
		break;
	case 6:
		tuichujian(x_xiaoxi, x, y, 1);
		morenchuli(x_xiaoxi);
		break;
	case 7:
		tuichujian(x_xiaoxi, x, y, 1);
		morenchuli(x_xiaoxi);
		break;
	case 8:
		tuichujian(x_xiaoxi, x, y, 1);
		morenchuli(x_xiaoxi);
		break;
	case 9:
		tuichujian(x_xiaoxi, x, y, 1);
		morenchuli(x_xiaoxi);
		break;
	case 10:
		tuichujian(x_xiaoxi, x, y, 1);
		morenchuli(x_xiaoxi);
		break;
	case 11:
		tuichujian(x_xiaoxi, x, y, 1);
		morenchuli(x_xiaoxi);
		break;
	}


}

void xjdb2()
{
	if(chaxunzhuangtaibiao(6))
{
		huizhijd_END(&jiaodian_b, &i.lvdata, &i.hongdata);
					xiugaizhuangtaibiao(0,6);
}	

}
void xjdb(uint z)
{
	if(chaxunzhuangtaibiao(7) != WGJCX(z)+WGJCY(z)*4)
	{
    xjdb2();
		ggjiaodian(&jiaodian_b, WGJCX(z) * 10, WGJCY(z) * 11);
    huizhijd_ONE(&jiaodian_b, &i.lvdata, &i.hongdata);
    huizhijiaodian(&jiaodian_b, SE_HONGTOU);
		xiugaizhuangtaibiao(WGJCX(z)+WGJCY(z)*4,7);
	  xiugaizhuangtaibiao(1,6);
	}
}

void MainPing_FY_ONE(char dizhi, uint JA_XY)
{

	uchar x = (JA_XY >> 8), y = JA_XY;
	uint z;
	switch (dizhi)
	{
	case 1:
		switch (z = gjwanggejiance(x, y, 10, 11))
		{
		case WGJC(0,0):
		case WGJC(1,0):
		case WGJC(2,0):
		case WGJC(3,0):
		case WGJC(0,1):
		case WGJC(1,1):
		case WGJC(2,1):
		case WGJC(3,1):
		case WGJC(0,2):
		case WGJC(1,2):
			xjdb(z);
			break;
		default:xjdb2();	xiugaizhuangtaibiao(NOP,7);
		}
		break;
	case 2:

		break;
	case 3:

		break;

	case 4:

		break;
	case 5:

		break;
	case 6:

		break;
	case 7:

		break;
	case 8:

		break;
	case 9:

		break;
	case 10:

		break;
	case 11:

		break;
	}


}

void MainPing_FY_END(char dizhi, uint JA_XY)
{

	switch (dizhi)
	{
	case 1:


		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	case 6:

		break;
	case 7:

		break;
	case 8:

		break;
	case 9:

		break;
	case 10:

		break;
	case 11:

		break;
	}



}
  
  