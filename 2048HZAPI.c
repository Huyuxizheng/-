#include"to2048moni.h"
#define uchar unsigned char
#define uint unsigned int



/*绿色画板*/
uchar  huanchonglv[MAXH][MAXW / 8];
/*红色画板*/
uchar  huanchonghong[MAXH][MAXW / 8];
/*画笔标志*/
uchar  huabiyanse = 0;
/*绘制区域标志*/
JUXING _huizhiquyu = {0,0,MAXW,MAXH};

/*绘制矩形数据表*/
uchar _hui_juxing[] = { 0x01 , 0x03, 0x07 , 0x0f  , 0x1f, 0x3f, 0x7f, 0xff };

/*绘制补前表*/
uchar _huizhi_buhou[] = { 0x00 ,0x01, 0x03, 0x07,0x0f, 0x1f, 0x3f, 0x7f,0xff   };
/*绘制补后表*/
uchar _huizhi_buqian[] = { 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80};

 void shezhihuabiyanse(char yanse)
{
	huabiyanse = yanse;
}

 void shezhihuizhiquyu(char w, char n, char e, char s){
	 if (w >= 0 && w <= MAXW && e >= 0 && e <= MAXW && n >= 0 && s <= MAXH && n >= 0 && s <= MAXH)
	 {
		 _huizhiquyu.w = w;
		 _huizhiquyu.n = n;
		 _huizhiquyu.e = e;
		 _huizhiquyu.s = s;
	 }
 }

 void huizhihuizhi(uchar(*huanchong)[MAXH][MAXW / 8], char x, char y, uchar(*temp)[], char h, char w)
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
				 (*huanchong)[y + ihy][xs + ihs]
					 =
					 ~(
					 ~(*huanchong)[y + ihy][xs + ihs]
					 |
					 ((*temp)[i] << xy)
					 );
			 }

			 if ((xs + ihs + 1) >= 0 && (xs + ihs + 1) < (MAXW / 8))
			 {
				 (*huanchong)[y + ihy][xs + ihs + 1]
					 =
					 ~(
					 ~(*huanchong)[y + ihy][xs + ihs + 1]
					 |
					 ((*temp)[i] >> (8 - xy))
					 );
			 }
		 }
	 }
 }
 void huizhicachu(uchar(*huanchong)[MAXH][MAXW / 8], char x, char y, uchar(*temp)[], char h, char w)
 {
	 char i, chicun,
		 xy, xs,
		 ihs, ihy;

	 //开始擦除
	 chicun = (h*w);
	 xy = (x >= 0 ? (x % 8) : 8 + (x % 8));
	 xs = (x >= 0 ? (x >> 3) : ((x >> 3) - 1));
	 for (i = 0; i < chicun; i++)
	 {
		 ihy = (i % h);
		 if ((y + ihy) >= 0 && (y + ihy) < MAXH)
		 {
			 ihs = (i / h);
			 if ((xs + ihs) >= 0 && (xs + ihs) < (MAXW / 8))
			 {
				 (*huanchong)[y + ihy][xs + ihs]
					 =

					 (*huanchong)[y + ihy][xs + ihs]
					 |
					 ((*temp)[i] << xy)
					 ;
			 }

			 if ((xs + ihs + 1) >= -1 && (xs + ihs + 1) < (MAXW / 8))
			 {
				 (*huanchong)[y + ihy][xs + ihs + 1]
					 =

					 (*huanchong)[y + ihy][xs + ihs + 1]
					 |
					 ((*temp)[i] >> (8 - xy))
					 ;
			 }
		 }
	 }

 }
 void huizhiqufan(uchar(*huanchong)[MAXH][MAXW / 8], char x, char y, uchar(*temp)[], char h, char w)
 {
	 char i, chicun,
		 xy, xs,
		 ihs, ihy;

	 //开始取反
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
				 (*huanchong)[y + ihy][xs + ihs]
					 =
					 ~(
					 ~(*huanchong)[y + ihy][xs + ihs]
					 ^
					 ((*temp)[i] << xy)
					 );
			 }

			 if ((xs + ihs + 1) >= 0 && (xs + ihs + 1) < (MAXW / 8))
			 {
				 (*huanchong)[y + ihy][xs + ihs + 1]
					 =
					 ~(
					 ~(*huanchong)[y + ihy][xs + ihs + 1]
					 ^
					 ((*temp)[i] >> (8 - xy))
					 );
			 }
		 }
	 }

 }
 void huizhi(char x, char y, uchar(*temp)[], char h, char w)
 {
	 char i, chicun,
		 xy, xs,
		 ihs, ihy;

	 //处理画笔颜色信息

	 if (huabiyanse == 0)
	 {
		 huizhicachu(&huanchonghong, x, y, temp, h, w);
		 huizhihuizhi(&huanchonglv, x, y, temp, h, w);
	 }
	 else if (huabiyanse == 1)
	 {
		 huizhicachu(&huanchonglv, x, y, temp, h, w);
		 huizhihuizhi(&huanchonghong, x, y, temp, h, w);
	 }
	 else if (huabiyanse == 3)
	 {
		 huizhihuizhi(&huanchonghong, x, y, temp, h, w);
		 huizhihuizhi(&huanchonglv, x, y, temp, h, w);
		 return;
	 }
	 else if (huabiyanse == 4)
	 {
		 huizhihuizhi(&huanchonglv, x, y, temp, h, w);
	 }
	 else if (huabiyanse == 5)
	 {
		 huizhihuizhi(&huanchonghong, x, y, temp, h, w);
	 }
	 else if (huabiyanse == 6)
	 {
		 huizhiqufan(&huanchonglv, x, y, temp, h, w);
	 }
	 else if (huabiyanse == 7)
	 {
		 huizhiqufan(&huanchonghong, x, y, temp, h, w);
	 }
	 else if (huabiyanse == 8)
	 {
		 huizhiqufan(&huanchonglv, x, y, temp, h, w);
		 huizhiqufan(&huanchonghong, x, y, temp, h, w);
	 }


 }


 void huizhiexhuizhi(uchar(*huanchong)[MAXH][MAXW / 8],char x, char y, uchar(*temp)[], char h, char w)
{
	uchar i, chicun,
		xy, xs,
		ihs, ihy;
	//开始绘制
	chicun = (h*w);
	xy = (x >= 0 ? (x & 7) : 8 + (x & 7));
	xs = (x >= 0 ? (x >> 3) : ((x >> 3) - 1));
	for (i = 0; i < chicun; i++)
	{
		ihy = (i % h);
		if ((y + ihy) >= _huizhiquyu.n && (y + ihy) < _huizhiquyu.s)
		{
			ihs = (i / h);

			if ((xs + ihs) >= ((_huizhiquyu.w+7)>>3) && (xs + ihs) < (_huizhiquyu.e >> 3))
			{
				(*huanchong)[y + ihy][xs + ihs]
					=
					~(
					~(*huanchong)[y + ihy][xs + ihs]
					|
					((*temp)[i] << xy)
					);
			}
			else if ((xs + ihs) >= ((_huizhiquyu.w + 7) >> 3) && (xs + ihs) < ((_huizhiquyu.e + 7) >> 3))
			{ 
				(*huanchong)[y + ihy][xs + ihs]
					=
					~(
					~(*huanchong)[y + ihy][xs + ihs]
					|
					(((*temp)[i] << xy)&(_huizhi_buhou[(_huizhiquyu.e&7)]))
					);
			}
			else if ((xs + ihs) >= (_huizhiquyu.w >> 3) && (xs + ihs) < (_huizhiquyu.e >> 3))
			{
				(*huanchong)[y + ihy][xs + ihs]
					=
					~(
					~(*huanchong)[y + ihy][xs + ihs]
					|
					(((*temp)[i] << xy)&(_huizhi_buqian[(_huizhiquyu.w & 7)]))
					);
			}
			else if ((xs + ihs) == (_huizhiquyu.w >> 3 )&& (xs + ihs) == (_huizhiquyu.e >> 8))
			{
				(*huanchong)[y + ihy][xs + ihs]
					=
					~(
					~(*huanchong)[y + ihy][xs + ihs]
					|
					(((*temp)[i] << xy)&(_huizhi_buqian[(_huizhiquyu.w & 7)])&(_huizhi_buhou[(_huizhiquyu.e & 7)]))
					);
			}

			if ((xs + ihs + 1) >= ((_huizhiquyu.w+7)>>3) && (xs + ihs + 1) < (_huizhiquyu.e >> 3))
			{
				(*huanchong)[y + ihy][xs + ihs + 1]
					=
					~(
					~(*huanchong)[y + ihy][xs + ihs + 1]
					|
					((*temp)[i] >> (8 - xy))
					);
			}
			else if ((xs + ihs+1) >= ((_huizhiquyu.w + 7) >> 3) && (xs + ihs+1) < ((_huizhiquyu.e + 7) >> 3))
			{
				(*huanchong)[y + ihy][xs + ihs + 1]
					=
					~(
					~(*huanchong)[y + ihy][xs + ihs + 1]
					|
					(((*temp)[i] >> (8 - xy))&(_huizhi_buhou[(_huizhiquyu.e & 7)]))
					);
			}
			else if ((xs + ihs + 1) >= (_huizhiquyu.w >> 3) && (xs + ihs+1) < (_huizhiquyu.e >>3))
			{
				(*huanchong)[y + ihy][xs + ihs+1]
					=
					~(
					~(*huanchong)[y + ihy][xs + ihs+1]
					|
					(((*temp)[i] >> (8 - xy))&(_huizhi_buqian[(_huizhiquyu.w & 7)]))
					);
			}
			else if ((xs + ihs + 1) == (_huizhiquyu.w >> 3) && (xs + ihs + 1) == (_huizhiquyu.e >> 3))
			{
				(*huanchong)[y + ihy][xs + ihs + 1]
					=
					~(
					~(*huanchong)[y + ihy][xs + ihs + 1]
					|
					(((*temp)[i] >> (8 - xy))&(_huizhi_buqian[(_huizhiquyu.w & 7)])&(_huizhi_buhou[(_huizhiquyu.e & 7)]))
					);
			}
		}
	}
}
 void huizhiexcachu(uchar(*huanchong) [MAXH][MAXW / 8], char x, char y, uchar(*temp)[], char h, char w)
{
		char i, chicun,
		xy, xs,
		ihs, ihy;
		//开始绘制
		chicun = (h*w);
		xy = (x >= 0 ? (x & 7) : 8 + (x & 7));
		xs = (x >= 0 ? (x / 8) : (x / 8 - 1));
		for (i = 0; i < chicun; i++)
		{
			ihy = (i % h);
			if ((y + ihy) >= _huizhiquyu.n && (y + ihy) < _huizhiquyu.s)
			{
				ihs = (i / h);

				if ((xs + ihs) >= ((_huizhiquyu.w + 7) >> 3) && (xs + ihs) < (_huizhiquyu.e >> 3))
				{
					(*huanchong)[y + ihy][xs + ihs]
						=
						
						(*huanchong)[y + ihy][xs + ihs]
						|
						((*temp)[i] << xy)
						;
				}
				else if ((xs + ihs) >= ((_huizhiquyu.w + 7) >> 3) && (xs + ihs) < ((_huizhiquyu.e + 7) >> 3))
				{
					(*huanchong)[y + ihy][xs + ihs]
						=
						
						(*huanchong)[y + ihy][xs + ihs]
						|
						(((*temp)[i] << xy)&(_huizhi_buhou[(_huizhiquyu.e & 7)]))
						;
				}
				else if ((xs + ihs + 1) >= (_huizhiquyu.w >> 3) && (xs + ihs + 1) < (_huizhiquyu.e >> 3))
				{
					(*huanchong)[y + ihy][xs + ihs]
						=
						
						(*huanchong)[y + ihy][xs + ihs]
						|
						(((*temp)[i] << xy)&(_huizhi_buqian[(_huizhiquyu.w & 7)]))
						;
				}
				else if ((xs + ihs + 1) == (_huizhiquyu.w >> 3) && (xs + ihs + 1) == (_huizhiquyu.e >> 3))
				{
					(*huanchong)[y + ihy][xs + ihs]
						=
						
						(*huanchong)[y + ihy][xs + ihs]
						|
						(((*temp)[i] << xy)&(_huizhi_buqian[(_huizhiquyu.w & 7)])&(_huizhi_buhou[(_huizhiquyu.e & 7)]))
						;
				}

				if ((xs + ihs) >= ((_huizhiquyu.w + 7) >> 3) && (xs + ihs) < (_huizhiquyu.e >> 3))
				{
					(*huanchong)[y + ihy][xs + ihs + 1]
						=
						
						(*huanchong)[y + ihy][xs + ihs + 1]
						|
						((*temp)[i] >> (8 - xy))
						;
				}
				else if ((xs + ihs) >= ((_huizhiquyu.w + 7) >> 3) && (xs + ihs) < ((_huizhiquyu.e + 7) >> 3))
				{
					(*huanchong)[y + ihy][xs + ihs + 1]
						=
						
						(*huanchong)[y + ihy][xs + ihs + 1]
						|
						(((*temp)[i] >> (8 - xy))&(_huizhi_buhou[(_huizhiquyu.e & 7)]))
						;
				}
				else if ((xs + ihs + 1) >= (_huizhiquyu.w >> 3) && (xs + ihs + 1) < (_huizhiquyu.e >> 3))
				{
					(*huanchong)[y + ihy][xs + ihs + 1]
						=
					
						(*huanchong)[y + ihy][xs + ihs + 1]
						|
						(((*temp)[i] >> (8 - xy))&(_huizhi_buqian[(_huizhiquyu.w & 7)]))
						;
				}
				else if ((xs + ihs + 1) == (_huizhiquyu.w >> 3) && (xs + ihs + 1) == (_huizhiquyu.e >> 3))
				{
					(*huanchong)[y + ihy][xs + ihs + 1]
						=
						
						(*huanchong)[y + ihy][xs + ihs + 1]
						|
						(((*temp)[i] >> (8 - xy))&(_huizhi_buqian[(_huizhiquyu.w & 7)])&(_huizhi_buhou[(_huizhiquyu.e & 7)]))
						;
				}
			}
		}
	}
 void huizhiexqufan(uchar(*huanchong)[MAXH][MAXW / 8], char x, char y, uchar(*temp)[], char h, char w)
 {
	 char i, chicun,
		 xy, xs,
		 ihs, ihy;
	 //开始绘制
	 chicun = (h*w);
	 xy = (x >= 0 ? (x & 7) : 8 + (x & 7));
	 xs = (x >= 0 ? (x / 8) : (x / 8 - 1));
	 for (i = 0; i < chicun; i++)
	 {
		 ihy = (i % h);
		 if ((y + ihy) >= _huizhiquyu.n && (y + ihy) < _huizhiquyu.s)
		 {
			 ihs = (i / h);

			 if ((xs + ihs) >= (_huizhiquyu.w + 7) / 8 && (xs + ihs) < (_huizhiquyu.e / 8))
			 {
				 (*huanchong)[y + ihy][xs + ihs]
					 =
					 ~(
					 ~(*huanchong)[y + ihy][xs + ihs]
					 ^
					 ((*temp)[i] << xy)
					 );
			 }
			 else if ((xs + ihs) >= (_huizhiquyu.w + 7) / 8 && (xs + ihs) < ((_huizhiquyu.e + 7) / 8))
			 {
				 (*huanchong)[y + ihy][xs + ihs]
					 =
					 ~(
					 ~(*huanchong)[y + ihy][xs + ihs]
					 ^
					 (((*temp)[i] << xy)&(_huizhi_buhou[(_huizhiquyu.e & 7)]))
					 );
			 }
			 else if ((xs + ihs) >= _huizhiquyu.w / 8 && (xs + ihs) < (_huizhiquyu.e / 8))
			 {
				 (*huanchong)[y + ihy][xs + ihs]
					 =
					 ~(
					 ~(*huanchong)[y + ihy][xs + ihs]
					 ^
					 (((*temp)[i] << xy)&(_huizhi_buqian[(_huizhiquyu.w & 7)]))
					 );
			 }
			 else if ((xs + ihs) == _huizhiquyu.w / 8 && (xs + ihs) == (_huizhiquyu.e / 8))
			 {
				 (*huanchong)[y + ihy][xs + ihs]
					 =
					 ~(
					 ~(*huanchong)[y + ihy][xs + ihs]
					 ^
					 (((*temp)[i] << xy)&(_huizhi_buqian[(_huizhiquyu.w & 7)])&(_huizhi_buhou[(_huizhiquyu.e & 7)]))
					 );
			 }


			 if ((xs + ihs + 1) >= _huizhiquyu.w && (xs + ihs + 1) < (_huizhiquyu.e / 8))
			 {
				 (*huanchong)[y + ihy][xs + ihs + 1]
					 =
					 ~(
					 ~(*huanchong)[y + ihy][xs + ihs + 1]
					 ^
					 ((*temp)[i] >> (8 - xy))
					 );
			 }
			 else if ((xs + ihs + 1) >= (_huizhiquyu.w + 7) / 8 && (xs + ihs + 1) < ((_huizhiquyu.e + 7) / 8))
			 {
				 (*huanchong)[y + ihy][xs + ihs + 1]
					 =
					 ~(
					 ~(*huanchong)[y + ihy][xs + ihs + 1]
					 ^
					 (((*temp)[i] >> (8 - xy))&(_huizhi_buhou[(_huizhiquyu.e & 7)]))
					 );
			 }
			 else if ((xs + ihs + 1) >= _huizhiquyu.w / 8 && (xs + ihs + 1) < (_huizhiquyu.e / 8))
			 {
				 (*huanchong)[y + ihy][xs + ihs + 1]
					 =
					 ~(
					 ~(*huanchong)[y + ihy][xs + ihs + 1]
					 ^
					 (((*temp)[i] >> (8 - xy))&(_huizhi_buqian[(_huizhiquyu.w & 7)]))
					 );
			 }
			 else if ((xs + ihs + 1) == _huizhiquyu.w / 8 && (xs + ihs + 1) == (_huizhiquyu.e / 8))
			 {
				 (*huanchong)[y + ihy][xs + ihs + 1]
					 =
					 ~(
					 ~(*huanchong)[y + ihy][xs + ihs + 1]
					 ^
					 (((*temp)[i] >> (8 - xy))&(_huizhi_buqian[(_huizhiquyu.w & 7)])&(_huizhi_buhou[(_huizhiquyu.e & 7)]))
					 );
			 }
		 }
	 }
 }
 void huizhiex(char x, char y, uchar(*temp)[], char h, char w)
 {
	 char i, chicun,
		 xy, xs,
		 ihs, ihy;

	 //处理画笔颜色信息

	 if (huabiyanse == 0)
	 {
		 huizhicachu(&huanchonghong, x, y, temp, h, w);
		 huizhihuizhi(&huanchonglv, x, y, temp, h, w);
	 }
	 else if (huabiyanse == 1)
	 {
		 huizhicachu(&huanchonglv, x, y, temp, h, w);
		 huizhihuizhi(&huanchonghong, x, y, temp, h, w);
	 }
	 else if (huabiyanse == 3)
	 {
		 huizhihuizhi(&huanchonghong, x, y, temp, h, w);
		 huizhihuizhi(&huanchonglv, x, y, temp, h, w);
		 return;
	 }
	 else if (huabiyanse == 4)
	 {
		 huizhihuizhi(&huanchonglv, x, y, temp, h, w);
	 }
	 else if (huabiyanse == 5)
	 {
		 huizhihuizhi(&huanchonghong, x, y, temp, h, w);
	 }
	 else if (huabiyanse == 6)
	 {
		 huizhiqufan(&huanchonglv, x, y, temp, h, w);
	 }
	 else if (huabiyanse == 7)
	 {
		 huizhiqufan(&huanchonghong, x, y, temp, h, w);
	 }
	 else if (huabiyanse == 8)
	 {
		 huizhiqufan(&huanchonglv, x, y, temp, h, w);
		 huizhiqufan(&huanchonghong, x, y, temp, h, w);
	 }


 }

 void huizhidiancachu(uchar(*huanchong)[MAXH][MAXW / 8], char x, char y)
 {

	 //对应坐标处擦除一个点
	 if (y >= _huizhiquyu.n && y < _huizhiquyu.s && x >= _huizhiquyu.w && x < _huizhiquyu.e)
	 {
		 (*huanchong)[y][x / 8] = (*huanchong)[y][x / 8] | (1 << (x & 7));

	 }
 }
 void huizhidianhuizhi(uchar(*huanchong)[MAXH][MAXW / 8],char x, char y)
 {
	 //对应坐标处绘制一个点
	 if (y >= _huizhiquyu.n && y < _huizhiquyu.s && x >= _huizhiquyu.w && x < _huizhiquyu.e)
	 {
		 (*huanchong)[y][x / 8] = ~((~(*huanchong)[y][x / 8])
			 | (1 << (x & 7)));

	 }

 }
 void huizhidianqufan(uchar(*huanchong)[MAXH][MAXW / 8], char x, char y)
 {

	 //对应坐标处取反一个点
	 if (y >= _huizhiquyu.n && y < _huizhiquyu.s && x >= _huizhiquyu.w && x < _huizhiquyu.e)
	 {
		 (*huanchong)[y][x / 8] = ~(~(*huanchong)[y][x / 8] ^ (1 << (x & 7)));

	 }
 }
 void huizhidian(char x, char y)
 {
	 
	 //处理画笔信息
	 if (huabiyanse == 0)
	 {
		 huizhidiancachu(&huanchonghong,x, y);
		 huizhidianhuizhi(&huanchonglv, x, y);

	 }
	 else if (huabiyanse == 1)
	 {
		 huizhidiancachu(&huanchonglv, x, y);
		 huizhidianhuizhi(&huanchonghong, x, y);;
	 }
	 else if (huabiyanse == 3)
	 {
		 huizhidianhuizhi(&huanchonghong, x, y);
		 huizhidianhuizhi(&huanchonglv, x, y);
	 }
	 else if (huabiyanse == 4)
	 {
		 huizhidianhuizhi(&huanchonglv, x, y);
	 }
	 else if (huabiyanse == 5)
	 {
		 huizhidianhuizhi(&huanchonghong, x, y);
	 }
	 else if (huabiyanse == 6)
	 {
		 huizhidianqufan(&huanchonglv, x, y);
	 }
	 else if (huabiyanse == 7)
	 {
		 huizhidianqufan(&huanchonghong, x, y);
	 }
	 else if (huabiyanse == 8)
	 {
		 huizhidianqufan(&huanchonghong, x, y);
		 huizhidianqufan(&huanchonglv, x, y);
	 }
	 else
	 {
		 return;
	 }



 }

 void shuapingzhiyi(uchar(*huanchong)[MAXH][MAXW / 8])
 {
	 uchar i = 0, j = 0;
	 for (i = 0; i<MAXH; i++)
	 {
		 for (j = 0; j<(MAXW / 8); j++)
			 (*huanchong)[i][j] = 0;
	 }
 }
 void shuapingzhiling(uchar(*huanchong)[MAXH][MAXW / 8])
 {
	 uchar i = 0, j = 0;
	 for (i = 0; i<MAXH; i++)
	 {
		 for (j = 0; j<(MAXW / 8); j++)
			 (*huanchong)[i][j] = 0xff;
	 }
 }
 void shuaping(char a)
 {//格式化背景 参数为0:绿色  为1:红色  为3:橙色  其他为黑色
 //用于擦除已绘制的图形 来绘制下一帧图形
	 if (a == 0)
	 {
		 shuapingzhiling(&huanchonghong);
		 shuapingzhiyi(&huanchonglv);
	 }
	 else if (a == 1)
	 {
		 shuapingzhiling(&huanchonglv);
		 shuapingzhiyi(&huanchonghong);
	 }
	 else if (a == 2)
	 {
		 shuapingzhiling(huanchonghong);
		 shuapingzhiling(huanchonglv);
	 }
	 else if (a == 3)
	 {
		 shuapingzhiyi(huanchonghong);
		 shuapingzhiyi(huanchonglv);
	 }
	 else
	 {

		 return;

	 }


 }

 void baocunquyutiqu(uchar(*huanchong)[MAXH][MAXW / 8], char x, char y, uchar (*temp)[],char ti)
 {
	 char xs = x / 8;
	 (*temp)[ti] &= 0x00;
	 if (xs < MAXW&&xs >= 0)
	 (*temp)[ti] |= (*huanchong)[y][x / 8] >> (x & 7) ;
	 if (xs + 1 < MAXW&&xs >= 0)
	 (*temp)[ti] |= (*huanchong)[y][x / 8 + 1] << (8 - (x & 7)) ;
 }
 void baocunquyu(char x,char y, uchar (*templv)[],uchar (*temphong)[],char h,char w)
 {
	 char ti = 0,max = h*w,xz,yz;
	 for (; ti < max; ti++)
	 {
		 xz = x + ((ti / h) * 8);
		 yz = y + ti%h;
		 if (yz >= 0 && yz < MAXH)
		 {
			 baocunquyutiqu(&huanchonglv, xz, yz, templv, ti);
			 baocunquyutiqu(&huanchonghong, xz, yz, temphong, ti);
		 }
	 }

 }

 void tanchuquyutanchu(uchar(*huanchong)[MAXH][MAXW / 8], uchar x, uchar y, uchar(*temp)[], uchar ti)
 {
	 char xs = x/8;
	 if (xs < MAXW&&xs >= 0)
	 {
		 (*huanchong)[y][xs] &= 0xff >> (8 - (x & 7));
		 (*huanchong)[y][xs] |= (*temp)[ti] << (x & 7);
	 }
	 if (xs + 1 < MAXW&&xs >= 0)
	 {
		 (*huanchong)[y][xs + 1] &= 0xff << (x & 7);
		 (*huanchong)[y][xs + 1] |= (*temp)[ti] >> (8 - (x & 7));
	 }
 }
 void tanchuquyu(uchar x, uchar y, uchar(*templv)[], uchar(*temphong)[], uchar h, uchar w)
 {
	 char ti = 0, max = h*w,xz,yz;
	 for (; ti < max; ti++)
	 {
		 xz = x + ((ti / h) * 8);
		yz = y + ti%h;
		if (yz >= 0 && yz < MAXH)
		{
			tanchuquyutanchu(&huanchonglv, xz, yz, templv, ti);
			tanchuquyutanchu(&huanchonghong, xz, yz, temphong, ti);
		}
	 }

 }

 void zhengtiyidonghengW(char w)
 {
	 uchar x, y;
	 for (x = 0; x < MAXW / 8;x++)
	 for (y = 0; y < MAXH; y++)
	 {
		 huanchonghong[y][x] >>= w;
		 huanchonglv[y][x] >>= w;
		 if (x < 7)
		 {
			 huanchonghong[y][x] |= huanchonghong[y][x + 1] << (8 - w);
			 huanchonglv[y][x] |= huanchonglv[y][x + 1] << (8 - w);
		 }
	 }
 }
 void zhengtiyidonghengE(char w)
 {
	 char x, y;
	 for (x = (MAXW / 8)-1; x >= 0; x--)
	 for (y = 0; y < MAXH; y++)
	 {
		 huanchonghong[y][x] <<= w;
		 huanchonglv[y][x] <<= w;
		 if (x != 0)
		 {
			 huanchonghong[y][x] |= huanchonghong[y][x - 1] >> (8 - w);
			 huanchonglv[y][x] |= huanchonglv[y][x - 1] >> (8 - w);
		 }
	 }
 }
 void zhengtiyidongshuN(char h)
 {
	 char x, y;
	 for (x = 0; x < MAXW / 8; x++)
	 for (y = 0; y < MAXH; y++)
	 {
		 if (y+h < MAXH )
		 {	
			 huanchonghong[y][x] = huanchonghong[y + h][x];
			 huanchonglv[y][x] = huanchonghong[y + h][x];
			 
		 }
		 else
		 {
			 huanchonghong[y][x] = 0;
			 huanchonglv[y][x] = 0;
		 }

	 }
 }
 void zhengtiyidongshuS(char h)
 {
	 char x, y;
	 for (x = 0; x < MAXW / 8; x++)
	 for (y = MAXH; y >= 0; y--)
	 {
		 if (y + h >= 0 )
		 {
			 huanchonghong[y][x] = huanchonghong[y + h][x];
			 huanchonglv[y][x] = huanchonghong[y + h][x];

		 }
		 else
		 {
			 huanchonghong[y][x] = 0;
			 huanchonglv[y][x] = 0;
		 }

	 }
 }
 void zhengtiyidong(char w, char h)
 {

	 if (w > 0&& w < 9)
	 {

		 zhengtiyidonghengW( w);
	 }
	 else if (w < 0&& w > -9)
	 {
		 zhengtiyidonghengE( -w);
	 }
	 if (h > 0)
	 {
		 zhengtiyidongshuN(h);
	 }
	 else if (h < 0)
	 {
		 zhengtiyidongshuS(h);
	 }


 }


 void quyucachucachu(uchar(*huanchong)[MAXH][MAXW / 8])
 {
	 char x, y, ws = (_huizhiquyu.w / 8), wy = (_huizhiquyu.w & 7), es = (_huizhiquyu.e / 8), ey = (_huizhiquyu.e & 7);
	 if (es == ws)
	 {
		 for (y = _huizhiquyu.n; y < _huizhiquyu.s; y++)
				 (*huanchong)[y][ws] |= 
				 (_hui_juxing[ey - wy] << (wy));
	 }
	 else
	 {
		for (y = _huizhiquyu.n; y < _huizhiquyu.s; y++)
			(*huanchong)[y][ws] |=(0xff << (wy));
		for (x = ws+1; x < es; x++)
			for (y = _huizhiquyu.n; y < _huizhiquyu.s; y++)
				(*huanchong)[y][x] |= 0xff;
		for (y = _huizhiquyu.n + 1; y < _huizhiquyu.s; y++)
			(*huanchong)[y][es] |=(0xff >> (8-ey));
	 }
 }
 void quyucachu()
 {
	 quyucachucachu(&huanchonghong);
	 quyucachucachu(&huanchonglv);
 }

 void huizhiduobianxing(char xqi, char yqi, char(*temp)[], char c)
 {
	 //调用绘制线段函数根据数组坐标绘制一个多边形
	 huizhixianduan((*temp)[c * 2 - 2] + xqi, (*temp)[c * 2 - 1] + yqi,
		 (*temp)[0] + xqi, (*temp)[1] + yqi);
	 for (; c > 1; c--)
	 {
		 huizhixianduan((*temp)[c * 2 - 2] + xqi, (*temp)[c * 2 - 1] + yqi,
			 (*temp)[(c - 1) * 2 - 2] + xqi, (*temp)[(c - 1) * 2 - 1] + yqi);
	 }

 }

 void huizhitujuxing(char x, char y, char h, char w)
 {
	 char xn = x, yn = y, axw = x + w, axh = y + h;


	 //绘制一个矩形
	 for (; xn <= axw; xn++)
	 {
		 if (xn >= 0 && xn < MAXW)
		 {
			 if (y >= 0)
				 huizhidian(xn, y);
			 if (axh >= 0)
				 huizhidian(xn, axh);
		 }
	 }
	 for (; yn <= axh; yn++)
	 {
		 if (yn >= 0 && yn < MAXH)
		 {
			 if (x >= 0)
				 huizhidian(x, yn);
			 if (axw >= 0)
				 huizhidian(axw, yn);
		 }
	 }

 }

 void huizhixianduan(char xqi, char yqi, char xzhong, char yzhong)
 {
	 char h, w, x, y, xi, yi;

	 //处理坐标信息
	 if (xzhong < xqi)
	 {
		 w = xqi;
		 xqi = xzhong;
		 xzhong = w;
		 w = yzhong;
		 yzhong = yqi;
		 yqi = w;
	 }

	 //计算线段各个点
	 h = yzhong - yqi;
	 w = xzhong - xqi;
	 if (jueduizhi(w) >= jueduizhi(h))
	 {
		 for (xi = 0; xi <= w; xi++)
		 {
			 y = ((float)(xi*h) / (float)w) + (float)yqi + 0.5;
			 x = xi + xqi;

			 //调用绘制像素点绘制算出的坐标位置
			 huizhidian(x, y);
		 }
	 }

	 else
	 {
		 for (yi = 0; yi <= jueduizhi(h); yi++)
		 {
			 x = ((float)(yi*w) / (float)jueduizhi(h)) + (float)xqi + 0.5;
			 y = (yi*h / jueduizhi(h)) + yqi;

			 //调用绘制像素点绘制算出的坐标位置
			 huizhidian(x, y);
		 }
	 }


 }
 

 char jueduizhi(char temp)
 {//辅助用于求绝对值
	 if (temp < 0)
		 return (-temp);
	 else
		 return temp;
 }
