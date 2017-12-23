#include"to2048moni.h"
#include"2048SJK.h"

code uchar HB_anniu_1[] =  { 0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00 };/*颜色1*/
code uchar HB_anniu_2[] =  { 0x00, 0x18, 0x3C, 0x7E, 0x7E, 0x3C, 0x18, 0x00 };/*颜色2*/
code uchar HB_anniu_3[] =  { 0xFF, 0x99, 0xBD, 0xFF, 0xFF, 0xBD, 0x99, 0xFF };/*颜色3*/
code uchar HB_anniu_4[] =  { 0x00, 0x00, 0x00, 0x14, 0x1C, 0x14, 0x00, 0x00 };/*橡皮1*/
code uchar HB_anniu_5[] =  { 0x00, 0x00, 0x24, 0x3C, 0x24, 0x24, 0x00, 0x00 };/*橡皮2*/
code uchar HB_anniu_6[] =  { 0xFF, 0x81, 0xA5, 0xBD, 0xA5, 0xA5, 0x81, 0xFF };/*橡皮3*/
code uchar HB_anniu_7[] =  { 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00 };/*线11*/
code uchar HB_anniu_8[] =  { 0xFF, 0x81, 0x81, 0x89, 0x81, 0x81, 0x81, 0xFF };/*线12*/
code uchar HB_anniu_10[] = { 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00 };/*线21*/
code uchar HB_anniu_11[] = { 0xFF, 0x81, 0x81, 0x99, 0x99, 0x81, 0x81, 0xFF };/*线22*/
code uchar HB_anniu_12[] = { 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00 };/*线31*/
code uchar HB_anniu_13[] = { 0xFF, 0x81, 0x81, 0xB9, 0xB9, 0xB9, 0x81, 0xFF };/*线32*/
code uchar HB_anniu_14[] = { 0x01 };/*线1*/
code uchar HB_anniu_15[] = { 0x03, 0x03 };/*线2*/
code uchar HB_anniu_16[] = { 0x07, 0x07, 0x07 };/*线3*/
  //  ****按钮结构****  //
 ANNIU lv =     { 0, 0, 8, 8, HB_anniu_1, SE_LVTOU, HB_anniu_2, SE_LVTOU, HB_anniu_3, SE_LVTOU, 8, 1, 1 };
 ANNIU hong =   { 0, 8, 8, 16, HB_anniu_1, SE_HONGTOU, HB_anniu_2, SE_HONGTOU, HB_anniu_3, SE_HONGTOU, 8, 1, 1 };
 ANNIU cheng =  { 0, 16, 8, 24, HB_anniu_1, SE_CHENG, HB_anniu_2, SE_CHENG, HB_anniu_3, SE_CHENG, 8, 1, 1 };
 ANNIU hc =     { 0, 24, 8, 32, HB_anniu_4, SE_CHENG, HB_anniu_5, SE_HONGTOU, HB_anniu_6, SE_CHENG, 8, 1, 1 };
 ANNIU xi =     { 0, 32, 8, 40, HB_anniu_7, SE_LVTOU, HB_anniu_7, SE_HONGTOU, HB_anniu_8, SE_CHENG, 8, 1, 1 };
 ANNIU zhong =  { 0, 40, 8, 48, HB_anniu_10, SE_LVTOU, HB_anniu_10, SE_HONGTOU, HB_anniu_11, SE_CHENG, 8, 1, 1 };
 ANNIU cu =     { 0, 48, 8, 56, HB_anniu_12, SE_LVTOU, HB_anniu_12, SE_HONGTOU, HB_anniu_13, SE_CHENG, 8, 1, 1 };
 //***********//
 
 //组合按钮结构//
 ZANNIU hbanniu[] = { &lv, &hong, &hc, &cheng};
 ZANNIU hbanniu2[] = { &xi, &zhong, &cu};
 
 //辅助：线指针 查询表
 uchar *hbt[] = { HB_anniu_14, HB_anniu_15, HB_anniu_16 };
 uchar hbh[] = { 1, 2, 3 };
 
 //此应用专用标志位
uchar z1 = NOP;
uchar z2 = NOP;
void hubandicen()
{//画板底层
	 shuaping(SE_HEI);
	zuheanniu(hbanniu, NOP, NOP, NOP, 4, &z1);//初始化组合按键
	zuheanniu(hbanniu2, NOP, NOP, NOP, 3, &z2);
	
	fuweizhuangtaibiao();//初始化状态表标志位
	 z1 = NOP;
   z2 = NOP;
	
	xiugaizhuangtaibiao(NOP, 7);//占用状态表后两位 作为本应用标志变量
	xiugaizhuangtaibiao(NOP, 6);
	
		dalogo();//打LOGO
	
		tuichujian(NOP, NOP, NOP, NOP);//初始化退出键
	
		tongbujiemian(J_Z);//完成底层绘制 同步界面
}
void huabanxiaoxichuliceng(uchar xiaoxi,char x,char y)
{//画板消息处理层
	zuheanniu(hbanniu, xiaoxi, x, y, 4, &z1);//相应组合按键消息
	zuheanniu(hbanniu2, xiaoxi, x, y, 3, &z2);
	
	//检查各个元素是否已设置
	if (z1 != NOP && z2 != NOP)
	if (xiaoxi == 5)
	if (gjjuxingjiance(x,y,9,0,64,56))
	if (chaxunzhuangtaibiao(6) != x || chaxunzhuangtaibiao(7) != y)
	{
		//根据鼠标位置作画
		shezhihuizhiquyu(9, 0, 64, 57);
		shezhihuabiyanse(z1);
		huizhiex(x, y, hbt[z2],hbh[z2] , 1 );
		xiugaizhuangtaibiao(NOP, 7);
		xiugaizhuangtaibiao(NOP, 6);
	}
	
		tuichujian(xiaoxi, x, y, 1);//响应退出键消息
	
		morenchuli(xiaoxi);//其他消息按系统默认方法处理
}
void huabanfudongceng1()
{//画板浮动层1
//服务于特殊需要的APP大多数一般任务都不必在此层完成
}
void huabanfudongceng2()
{//画板浮动层2
//服务于特殊需要的APP大多数一般任务都不必在此层完成
}