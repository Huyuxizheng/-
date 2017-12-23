#include"to2048moni.h"
#include"2048SJK.h"

//检测重叠图
char _jiancechongdietujiance(uchar(*huanchong)[MAXH][MAXW / 8], char x, char y, uchar(*temp)[], char h, char w)
{
	char i, chicun,
		xy, xs,
		ihs, ihy;
	//开始绘制
	chicun = (h*w);
	xy = (x >= 0 ? (x % 8) : 8 + (x % 8));
	xs = (x >= 0 ? (x / 8) : (x / 8 - 1));
	for (i = 0; i < chicun; i++)
	{
		ihy = (i % h);
		if ((y + ihy) >= 0 && (y + ihy) < MAXH)
		{
			ihs = (i / h);

			if ((xs + ihs) >= 0 && (xs + ihs) < (MAXW / 8))
			{
				
				if (
					(char)(~(*huanchong)[y + ihy][xs + ihs])
					&
					(char)((*temp)[i] << xy)
					)
					return 1;
			}

			if ((xs + ihs + 1) >= 0 && (xs + ihs + 1) < (MAXW / 8))
			{
				if (
					(char)(~(*huanchong)[y + ihy][xs + ihs + 1])
					&
					(char)((*temp)[i] >> (8 - xy))
					)return 1;
			}
		}
	}
	return 0;
}
char jiancechongdietu(char x, char y, uchar(*temp)[], char h, char w, char yanse)
{
	if (yanse == 2)
	{
		return (!_jiancechongdietujiance(&huanchonghong, x, y, temp, h, w))
			||
			(!_jiancechongdietujiance(&huanchonglv, x, y, temp, h, w));
	}
	else if (yanse == 0)
	{
		return _jiancechongdietujiance(&huanchonglv, x, y, temp, h, w);
	}
	else if (yanse == 1)
	{
		return _jiancechongdietujiance(&huanchonghong, x, y, temp, h, w);
	}
	else if (yanse == 3)
	{
		return _jiancechongdietujiance(&huanchonghong, x, y, temp, h, w) 
			|| 
			   _jiancechongdietujiance(&huanchonglv, x, y, temp, h, w);
	}


}


//检测重叠点
char _jiancechongdiedianjiance(uchar(*huanchong)[MAXH][MAXW / 8], char x, char y)
{
	if (y >= _huizhiquyu.n && y < _huizhiquyu.s && x >= _huizhiquyu.w && x < _huizhiquyu.e)
	{
		if ((char)(~(*huanchong)[y][x >> 3]) & (char)(1 << (x & 7)))
			return 1;
	}
	return 0;
}
char jiancechongdiedian(char x, char y, char yanse)
{
	if (yanse == 2)
	{
		return (!_jiancechongdiedianjiance(&huanchonghong, x, y))
			||
			(!_jiancechongdiedianjiance(&huanchonglv, x, y));
	}
	else if (yanse == 0)
	{
		return _jiancechongdiedianjiance(&huanchonglv, x, y);
	}
	else if (yanse == 1)
	{
		return _jiancechongdiedianjiance(&huanchonghong, x, y);
	}
	else if (yanse == 3)
	{
		return _jiancechongdiedianjiance(&huanchonghong, x, y)
			||
			_jiancechongdiedianjiance(&huanchonglv, x, y);
	}

}


//工具网格检测 输入限制 为提高效率XY必须在最大区域之内 
uint gjwanggejiance(uchar x,uchar y,uchar wx,uchar hy)
{
	x = (x / wx);
	y = (y / hy);
	return WGJC(x,y);
}

//工具矩形检测
char gjjuxingjiance(char x, char y, char w, char n, char e, char s)
{
	if (x >= w && y >= n && x <= e && y <= s)
		return 1;
	return 0;
}

//消息的默认处理方式以便程序整洁
void morenchuli(uchar xiaoxi)
{
	if(chaxunzhuangtaibiao(0))
	switch (xiaoxi)
	{
	case 1:
		gbjiaodian(&JDA_Z, 0, 1);
		break;
	case 2:
		gbjiaodian(&JDA_Z, -1, 0);
		break;
	case 3:
		gbjiaodian(&JDA_Z, 0, -1);
		break;
	case 4:
		gbjiaodian(&JDA_Z, 1, 0);
		break;
	}


}


uchar tuichu_123[] = { 0x11, 0x0A, 0x04, 0x0A, 0x11 };
ANNIU tuichu = { 59, 59, 64, 64, tuichu_123, SE_CHENG, tuichu_123, SE_HONGTOU, tuichu_123, SE_HEI, 5, 1 ,1};
//退出按钮
void tuichujian(uchar xiaoxi,char x,char y,uchar q)
{
	kjanniu(&tuichu, xiaoxi, x, y);
	if (tuichu.xz == 3)
	{
		xiugaijiemian(q, J_Z);
	}
}

uchar logo2048_1[] =
{ 0xFE, 0x0C, 0xFF, 0xB0, 0xE0, 0x40, 0x0F, 0xC6, 0x1F, 0xC1, 0x40, 0xC0, 0x00, 0x5D, 0x55, 0xD5,
0x14, 0x1D, 0x00, 0x5D, 0x55, 0x5D, 0x55, 0x9D, 0x00, 0x3A, 0x12, 0x12, 0x12, 0x39 };/*"LOGO",LOGO*/
uchar logo2048_2[] =
{ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07 };/*"LOGO",LOGO*/
//最下6行 2048 的LOGO
void dalogo()
{
	shezhihuabiyanse(SE_LVTOU);
	huizhi(0, 58, logo2048_1, 6, 5);
	shezhihuabiyanse(SE_HONGTOU);
	huizhi(13, 58, logo2048_2, 1, 7);
}