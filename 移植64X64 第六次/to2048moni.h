#include <REGX52.H>
#define uchar unsigned char
#define uint unsigned int
#define MAXW 64
#define MAXH 64

#define J_Z 0
#define J_F 1
#define J_FZ 2
#define J_FZZ 3
#define J_FZZZ 4
#define J_FZZZZ 5

#define Z_FUKEY  0
#define Z_TKEY  1
#define Z_AKEY  2
#define Z_BKEY  3
#define Z_CKEY  4
#define Z_DKEY  5
#define Z_EKEY  6
#define Z_FKEY  7

#define SE_LV 0
#define SE_HONG 1
#define SE_HEI 2
#define SE_CHENG 3
#define SE_LVTOU 4
#define SE_HONGTOU 5
#define SE_LVFAN 6
#define SE_HONGFAN 7
#define SE_CHENGFAN 8
#define END 0xff
#define ONE 0x00
#define XIAOXIMAX 8
#define NOP 0xfe

#define JDA_Z _jiaodianA
#define JDA_T_1 _jdA_1
#define JDA_T_2 _jdA_2
#define JDA_Z_1 _jdA_lv
#define JDA_Z_2 _jdA_hong
#define WGJC(x,y) ((((uint)x)<<8)|(y))
#define WGJCX(i) (((i)>>8))
#define WGJCY(i) ((i)&0x0f)



sfr P0M0 = 0x94;
sfr P0M1 = 0x93;
sfr P1M0 = 0x92;
sfr P1M1 = 0x91;
sfr P2M0 = 0x96;
sfr P2M1 = 0x95;
sfr P3M0  = 0xB2;
sfr P3M1  = 0xB1;

sbit IA  =P0^5;  //行控制线A
sbit IB  =P0^6;  //行控制线B
sbit IC  =P0^7;  //行控制线C
sbit ID  =P1^0;  //行控制线D
sbit OE  =P1^7;  //使能端

sbit rck = P1^3;              //锁存	 
sbit sck = P1^4;	            //时钟

sbit R1 = P1^6;		     //数据R2和G2
sbit R2 = P1^5;
sbit G2 = P1^2;		     //数据R1和G1
sbit G1 = P1^1;

sbit S1 = P2^0;
sbit S2 = P2^1;
sbit S3 = P2^2;
sbit S4 = P2^3;
sbit S5 = P3^3;
sbit S6 = P3^2;

#define  scan0    {IA=0;IB=0;IC=0;ID=0;}
#define  scan1    {IA=1;IB=0;IC=0;ID=0;}
#define  scan2    {IA=0;IB=1;IC=0;ID=0;}
#define  scan3    {IA=1;IB=1;IC=0;ID=0;}
#define  scan4    {IA=0;IB=0;IC=1;ID=0;}
#define  scan5    {IA=1;IB=0;IC=1;ID=0;}
#define  scan6    {IA=0;IB=1;IC=1;ID=0;}
#define  scan7    {IA=1;IB=1;IC=1;ID=0;}
#define  scan8    {IA=0;IB=0;IC=0;ID=1;}
#define  scan9    {IA=1;IB=0;IC=0;ID=1;}
#define scan10    {IA=0;IB=1;IC=0;ID=1;}
#define scan11    {IA=1;IB=1;IC=0;ID=1;}
#define scan12    {IA=0;IB=0;IC=1;ID=1;}
#define scan13    {IA=1;IB=0;IC=1;ID=1;}
#define scan14    {IA=0;IB=1;IC=1;ID=1;}
#define scan15    {IA=1;IB=1;IC=1;ID=1;}





extern uchar  huanchonglv[MAXH][MAXW / 8];
extern uchar  huanchonghong[MAXH][MAXW / 8];
extern uchar _jdA_1[3];
extern uchar _jdA_2[3];

extern uchar _jdA_lv[3];
extern uchar _jdA_hong[3];


typedef struct _zancun
{
	uchar lvdata[48];
	uchar hongdata[48];
} ZANCUN, *ZZANCUN;

extern ZANCUN i;

//旧式焦点结构(已完全淘汰 只是方便用户使用 )
typedef struct _jiaodian{
	char x;
	char y;
} *ZJIAODIAN, JIAODIAN;

//新式焦点结构 增加更多功能
typedef struct _jiaodians{
	uchar (*ysi)[];//焦点样式
	uchar h;//焦点样式长度
	uchar w;//焦点样式宽度
	char xi;//焦点图片显示坐标
	char yi;//焦点图片显示坐标
	char x;//焦点中心点
	char y;//焦点中心点
	char qzx;//焦点中点于图的距离公式 xi - x
	char qzy;//焦点中点于图的距离公式 yi - y
} *ZJIAODIANS, JIAODIANS;
extern JIAODIANS _jiaodianA;//系统焦点

typedef struct _anniu{
	char w;
	char n;
	char e;
	char s;//方位
	uchar(*ys1)[];//一般时的样式
	uchar ys1se;
	uchar(*ys2)[];//鼠标停留在上面时的样式
	uchar ys2se;
	uchar(*ys3)[];//选中时的样式
	uchar ys3se;
	char ysh;//样式高度
	char ysw;//样式宽度
	char xz;//选中/未选中/鼠标停留 标志
}*ZANNIU, ANNIU;//按钮控件结构

typedef struct _huakuai{
	char w;
	char n;
	char e;
	char s;//方位
	char wi;
	char ni;
	char ei;
	char si;//初始化应于方位相同
	uchar(*ys1)[];//样式1
	uchar ys1se;
	uchar(*ys2)[];//样式2
	uchar ys2se;
	uchar(*ys3)[];//样式三
	uchar ys3se;
	char ysh;//样式高度
	char ysw;//样式宽度
	char xz;//选中/未选中/悬浮标志位
}HUAKUAI, *ZHUAKUAI;//滑块结构


typedef struct _juxing{
	char w;
	char n;
	char e;
	char s;
} *ZJUXING, JUXING;//矩形数据结构

typedef struct _xiaoxi{
	uchar i;//队列指针
	uchar xiaoxi[XIAOXIMAX];//消息队列
} *ZXIAOXI, XIAOXI;
extern XIAOXI _xiaoxiduilie;

//最下6行 2048 的LOGO
extern void dalogo();
//退出按钮
extern void tuichujian(uchar xiaoxi, char x, char y, uchar q);
//按钮控件
extern void kjanniu(ZANNIU temp, uchar xiaoxi, char x, char y);
//组合关联选择按钮(单选)
void zuheanniu(ZANNIU((*temp)[]), uchar xiaoxi, char x, char y, uchar i,uchar *z);

//控件无限制滑块
void kjhuakuai(ZHUAKUAI temp, uchar xiaoxi, char x, char y);

//查询按钮状态
extern char chaxunkjanniu(ZANNIU temp);

//修改状态表
extern void xiugaizhuangtaibiao(char temp, char key);

//查询状态表
extern char chaxunzhuangtaibiao(char key);

//复位状态表
extern void fuweizhuangtaibiao();

//查询1号焦点坐标,由系统自动调用
extern uint chaxunjiaodian_A();
//查询1号焦点坐标
extern void chaxunjiaodianA(ZJIAODIANS temp);

//工具网格检测 输入限制 为提高效率XY必须在最大区域之内
/*uchar x, uchar y, uchar h网格高度, uchar wx网格宽度 */
extern uint gjwanggejiance(uchar x, uchar y, uchar wx, uchar hy);

//工具矩形检测
extern char gjjuxingjiance(char x, char y, char w, char n, char e, char s);


//更改焦点中点 
extern void ggzongdian(ZJIAODIANS temp, char qzx, char qzy);

/*更改焦点样式
ggysijiaodian(ZJIAODIANS temp,需要更改样式的焦点
				uchar(*ysi)[], 样式地址
				uchar h, 样式高度
				uchar w样式宽度);*/
extern void ggysijiaodian(ZJIAODIANS temp, uchar(*ysi)[], uchar h, uchar w);

/*更改焦点
void ggjiaodian(ZJIAODIANS temp,需要更改的焦点地址
					char x,X坐标 
					char yY坐标)*/
extern void ggjiaodian(ZJIAODIANS temp, char x, char y);

/*通过偏移量改变焦点
void gbjiaodian(ZJIAODIANS temp, 需要改变的焦点
					char xi,X偏移 
					char yiY偏移)*/
extern void gbjiaodian(ZJIAODIANS temp, char xi, char yi);

/*显示焦点
void huizhijiaodian(ZJIAODIANS temp 需要显示焦点的地址,
					uchar se 需要显示成的颜色)*/
extern void huizhijiaodian(ZJIAODIANS temp, uchar se);

/*绘制焦点前的处理函数与后处理配套使用
void huizhijd_ONE(ZJIAODIANS temp 需要处理的焦点,
				uchar(*tutemplv)[]大于等于焦点图形尺寸的可变数组
				, uchar(*tutemphong)[]大于等于焦点图形尺寸的可变数组)*/
extern void huizhijd_ONE(ZJIAODIANS temp, uchar(*tutemplv)[], uchar(*tutemphong)[]);

/*绘制焦点刷新之后的处理函数于前处理配套使用
void huizhijd_END(ZJIAODIANS temp 需要处理的焦点,
uchar(*tutemplv)[]大于等于焦点图形尺寸的可变数组
, uchar(*tutemphong)[]大于等于焦点图形尺寸的可变数组)*/
extern void huizhijd_END(ZJIAODIANS temp, uchar(*tutemplv)[], uchar(*tutemphong)[]);

//消息的默认处理方式以便程序整洁
extern void morenchuli(uchar xiaoxi);

//修改界面指示器
extern void xiugaijiemian(char temp, char ceng);

//检查界面是否变动
extern uchar jianchajiemian(char ceng);

//查询一个界面指示
extern char chaxunjiemian(char ceng);

//同步界面指示器
extern void tongbujiemian(char ceng);

/*绘制矩形数据表*/
extern uchar _hui_juxing[];

/*绘制补前表*/
extern uchar _huizhi_buhou[];

/*绘制补后表*/
extern uchar _huizhi_buqian[];

/*画笔标志*/
extern uchar  huabiyanse;

/*绘制区域指示器*/
extern JUXING _huizhiquyu;

/*设置画笔颜色*/
extern void shezhihuabiyanse(char yanse);

/*获得区域*/
extern void huodequyu(ZJUXING temp);

/*设置一块矩形绘制区域*/
extern void shezhihuizhiquyu(char w, char n, char e, char s);

/*保存一块区域*/
extern void baocunquyu(uchar x, uchar y, uchar *templv[], uchar *temphong[], uchar h, uchar w);

/*弹出一块区域*/
extern void tanchuquyu(uchar x, uchar y, uchar(*templv)[], uchar(*temphong)[], uchar h, uchar w);

/*擦除当前绘制区域*/
extern void quyucachu();

/*整体移动 */
extern void zhengtiyidong(char w, char h, uchar se);

//插入一条消息
extern uchar charuxiaoxi(char i, uchar tdata);

//弹出一条消息
extern uchar tanchuxiaoxi();

//检测消息队列是否有消息
extern char jiancexiaoxi();

/*更新背景*/
extern void shuaping(char a);

/*刷新一页面的数据 */
extern void shuaxin();
/*求绝对值*/
extern char jueduizhi(char temp);

/*绘制一个像素点
void huizhidian( char X轴坐标,
char Y轴坐标);*/
extern void huizhidian(char, char);
/*检测点重叠yanse参数为需检测重叠的颜色 其余与绘制点函数相同*/
extern char jiancechongdiedian(char x, char y, char yanse);
/*在一个位置 绘制一个图形数据
void huizhi( char X轴坐标,
char Y轴坐标,
char* 需要绘制数组的指针,
char 此数组的长度,
char 次数组将要分成多少列显示 );*/
extern void huizhi(char, char, char(*)[], char, char);
/*检测图重叠yanse参数为需检测重叠的颜色 其余与绘制函数相同*/
extern char jiancechongdietu(char x, char y, uchar(*temp)[], char h, char w, char yanse);
/*在一个位置 绘制一个图形数据EX 加入区域限制 相对的效率会比绘制低
void huizhi( char X轴坐标,
char Y轴坐标,
char* 需要绘制数组的指针,
char 此数组的长度,
char 次数组将要分成多少列显示 );*/
extern void huizhiex(char x, char y, uchar(*temp)[], char h, char w);
/*绘制一个矩形区域
void huizhijuxing(ZJUXING 矩形结构的指针
, char 是否填充);	*/
extern void huizhijuxingquyu(ZJUXING temp, char tianchong);


/*绘制一个空心矩形图 推荐尽量避免使用此函数
使用huizhijuxing() 会更高效
void huizhitujuxing(char 这个矩形的X轴坐标,
char 这个矩形的Y坐标, 
char 这个矩形的高,
char 这个矩形的宽)
*/
extern void huizhitujuxing(char x, char y, char h, char w);

/*绘制一条线段
void huizhixianduan(char 线段起点的X轴坐标,
char 线段起点的Y轴坐标,
char 线段终点的X轴坐标,
char 线段终点的Y轴坐标);*/
extern void huizhixianduan(char, char, char, char);

/*绘制一个多边形
void huizhiduobianxing(char  这个多边形的X轴坐标,
char 这个多边形的Y轴坐标,
char* 这个多边形所有点的坐标数组的指针,
char  这个多边形有多少个顶点);*/
extern void huizhiduobianxing(char, char, char(*)[], char);



/* 底层绘制函数主要处理界面切换效果
MainPing_D(int 界面信息)*/
extern void MainPing_D(char);
/*界面运行中的局部处理
MainPing_Z(int 界面信息)*/
extern void MainPing_Z(char,uchar,uint);
/*顶层浮动界面输出*/
extern void MainPing_F_ONE();
/*顶层浮动界面善后*/
extern void MainPing_F_END();
/*消息更新*/
extern void Main_Xiaoxi();

/*用户层浮动界面*/
extern void MainPing_FY_ONE(char, uint);
/*用户层浮动界面*/
extern void MainPing_FY_END(char, uint);