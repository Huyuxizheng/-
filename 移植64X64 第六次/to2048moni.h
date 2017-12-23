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

sbit IA  =P0^5;  //�п�����A
sbit IB  =P0^6;  //�п�����B
sbit IC  =P0^7;  //�п�����C
sbit ID  =P1^0;  //�п�����D
sbit OE  =P1^7;  //ʹ�ܶ�

sbit rck = P1^3;              //����	 
sbit sck = P1^4;	            //ʱ��

sbit R1 = P1^6;		     //����R2��G2
sbit R2 = P1^5;
sbit G2 = P1^2;		     //����R1��G1
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

//��ʽ����ṹ(����ȫ��̭ ֻ�Ƿ����û�ʹ�� )
typedef struct _jiaodian{
	char x;
	char y;
} *ZJIAODIAN, JIAODIAN;

//��ʽ����ṹ ���Ӹ��๦��
typedef struct _jiaodians{
	uchar (*ysi)[];//������ʽ
	uchar h;//������ʽ����
	uchar w;//������ʽ���
	char xi;//����ͼƬ��ʾ����
	char yi;//����ͼƬ��ʾ����
	char x;//�������ĵ�
	char y;//�������ĵ�
	char qzx;//�����е���ͼ�ľ��빫ʽ xi - x
	char qzy;//�����е���ͼ�ľ��빫ʽ yi - y
} *ZJIAODIANS, JIAODIANS;
extern JIAODIANS _jiaodianA;//ϵͳ����

typedef struct _anniu{
	char w;
	char n;
	char e;
	char s;//��λ
	uchar(*ys1)[];//һ��ʱ����ʽ
	uchar ys1se;
	uchar(*ys2)[];//���ͣ��������ʱ����ʽ
	uchar ys2se;
	uchar(*ys3)[];//ѡ��ʱ����ʽ
	uchar ys3se;
	char ysh;//��ʽ�߶�
	char ysw;//��ʽ���
	char xz;//ѡ��/δѡ��/���ͣ�� ��־
}*ZANNIU, ANNIU;//��ť�ؼ��ṹ

typedef struct _huakuai{
	char w;
	char n;
	char e;
	char s;//��λ
	char wi;
	char ni;
	char ei;
	char si;//��ʼ��Ӧ�ڷ�λ��ͬ
	uchar(*ys1)[];//��ʽ1
	uchar ys1se;
	uchar(*ys2)[];//��ʽ2
	uchar ys2se;
	uchar(*ys3)[];//��ʽ��
	uchar ys3se;
	char ysh;//��ʽ�߶�
	char ysw;//��ʽ���
	char xz;//ѡ��/δѡ��/������־λ
}HUAKUAI, *ZHUAKUAI;//����ṹ


typedef struct _juxing{
	char w;
	char n;
	char e;
	char s;
} *ZJUXING, JUXING;//�������ݽṹ

typedef struct _xiaoxi{
	uchar i;//����ָ��
	uchar xiaoxi[XIAOXIMAX];//��Ϣ����
} *ZXIAOXI, XIAOXI;
extern XIAOXI _xiaoxiduilie;

//����6�� 2048 ��LOGO
extern void dalogo();
//�˳���ť
extern void tuichujian(uchar xiaoxi, char x, char y, uchar q);
//��ť�ؼ�
extern void kjanniu(ZANNIU temp, uchar xiaoxi, char x, char y);
//��Ϲ���ѡ��ť(��ѡ)
void zuheanniu(ZANNIU((*temp)[]), uchar xiaoxi, char x, char y, uchar i,uchar *z);

//�ؼ������ƻ���
void kjhuakuai(ZHUAKUAI temp, uchar xiaoxi, char x, char y);

//��ѯ��ť״̬
extern char chaxunkjanniu(ZANNIU temp);

//�޸�״̬��
extern void xiugaizhuangtaibiao(char temp, char key);

//��ѯ״̬��
extern char chaxunzhuangtaibiao(char key);

//��λ״̬��
extern void fuweizhuangtaibiao();

//��ѯ1�Ž�������,��ϵͳ�Զ�����
extern uint chaxunjiaodian_A();
//��ѯ1�Ž�������
extern void chaxunjiaodianA(ZJIAODIANS temp);

//���������� �������� Ϊ���Ч��XY�������������֮��
/*uchar x, uchar y, uchar h����߶�, uchar wx������ */
extern uint gjwanggejiance(uchar x, uchar y, uchar wx, uchar hy);

//���߾��μ��
extern char gjjuxingjiance(char x, char y, char w, char n, char e, char s);


//���Ľ����е� 
extern void ggzongdian(ZJIAODIANS temp, char qzx, char qzy);

/*���Ľ�����ʽ
ggysijiaodian(ZJIAODIANS temp,��Ҫ������ʽ�Ľ���
				uchar(*ysi)[], ��ʽ��ַ
				uchar h, ��ʽ�߶�
				uchar w��ʽ���);*/
extern void ggysijiaodian(ZJIAODIANS temp, uchar(*ysi)[], uchar h, uchar w);

/*���Ľ���
void ggjiaodian(ZJIAODIANS temp,��Ҫ���ĵĽ����ַ
					char x,X���� 
					char yY����)*/
extern void ggjiaodian(ZJIAODIANS temp, char x, char y);

/*ͨ��ƫ�����ı佹��
void gbjiaodian(ZJIAODIANS temp, ��Ҫ�ı�Ľ���
					char xi,Xƫ�� 
					char yiYƫ��)*/
extern void gbjiaodian(ZJIAODIANS temp, char xi, char yi);

/*��ʾ����
void huizhijiaodian(ZJIAODIANS temp ��Ҫ��ʾ����ĵ�ַ,
					uchar se ��Ҫ��ʾ�ɵ���ɫ)*/
extern void huizhijiaodian(ZJIAODIANS temp, uchar se);

/*���ƽ���ǰ�Ĵ��������������ʹ��
void huizhijd_ONE(ZJIAODIANS temp ��Ҫ����Ľ���,
				uchar(*tutemplv)[]���ڵ��ڽ���ͼ�γߴ�Ŀɱ�����
				, uchar(*tutemphong)[]���ڵ��ڽ���ͼ�γߴ�Ŀɱ�����)*/
extern void huizhijd_ONE(ZJIAODIANS temp, uchar(*tutemplv)[], uchar(*tutemphong)[]);

/*���ƽ���ˢ��֮��Ĵ�������ǰ��������ʹ��
void huizhijd_END(ZJIAODIANS temp ��Ҫ����Ľ���,
uchar(*tutemplv)[]���ڵ��ڽ���ͼ�γߴ�Ŀɱ�����
, uchar(*tutemphong)[]���ڵ��ڽ���ͼ�γߴ�Ŀɱ�����)*/
extern void huizhijd_END(ZJIAODIANS temp, uchar(*tutemplv)[], uchar(*tutemphong)[]);

//��Ϣ��Ĭ�ϴ���ʽ�Ա��������
extern void morenchuli(uchar xiaoxi);

//�޸Ľ���ָʾ��
extern void xiugaijiemian(char temp, char ceng);

//�������Ƿ�䶯
extern uchar jianchajiemian(char ceng);

//��ѯһ������ָʾ
extern char chaxunjiemian(char ceng);

//ͬ������ָʾ��
extern void tongbujiemian(char ceng);

/*���ƾ������ݱ�*/
extern uchar _hui_juxing[];

/*���Ʋ�ǰ��*/
extern uchar _huizhi_buhou[];

/*���Ʋ����*/
extern uchar _huizhi_buqian[];

/*���ʱ�־*/
extern uchar  huabiyanse;

/*��������ָʾ��*/
extern JUXING _huizhiquyu;

/*���û�����ɫ*/
extern void shezhihuabiyanse(char yanse);

/*�������*/
extern void huodequyu(ZJUXING temp);

/*����һ����λ�������*/
extern void shezhihuizhiquyu(char w, char n, char e, char s);

/*����һ������*/
extern void baocunquyu(uchar x, uchar y, uchar *templv[], uchar *temphong[], uchar h, uchar w);

/*����һ������*/
extern void tanchuquyu(uchar x, uchar y, uchar(*templv)[], uchar(*temphong)[], uchar h, uchar w);

/*������ǰ��������*/
extern void quyucachu();

/*�����ƶ� */
extern void zhengtiyidong(char w, char h, uchar se);

//����һ����Ϣ
extern uchar charuxiaoxi(char i, uchar tdata);

//����һ����Ϣ
extern uchar tanchuxiaoxi();

//�����Ϣ�����Ƿ�����Ϣ
extern char jiancexiaoxi();

/*���±���*/
extern void shuaping(char a);

/*ˢ��һҳ������� */
extern void shuaxin();
/*�����ֵ*/
extern char jueduizhi(char temp);

/*����һ�����ص�
void huizhidian( char X������,
char Y������);*/
extern void huizhidian(char, char);
/*�����ص�yanse����Ϊ�����ص�����ɫ ��������Ƶ㺯����ͬ*/
extern char jiancechongdiedian(char x, char y, char yanse);
/*��һ��λ�� ����һ��ͼ������
void huizhi( char X������,
char Y������,
char* ��Ҫ���������ָ��,
char ������ĳ���,
char �����齫Ҫ�ֳɶ�������ʾ );*/
extern void huizhi(char, char, char(*)[], char, char);
/*���ͼ�ص�yanse����Ϊ�����ص�����ɫ ��������ƺ�����ͬ*/
extern char jiancechongdietu(char x, char y, uchar(*temp)[], char h, char w, char yanse);
/*��һ��λ�� ����һ��ͼ������EX ������������ ��Ե�Ч�ʻ�Ȼ��Ƶ�
void huizhi( char X������,
char Y������,
char* ��Ҫ���������ָ��,
char ������ĳ���,
char �����齫Ҫ�ֳɶ�������ʾ );*/
extern void huizhiex(char x, char y, uchar(*temp)[], char h, char w);
/*����һ����������
void huizhijuxing(ZJUXING ���νṹ��ָ��
, char �Ƿ����);	*/
extern void huizhijuxingquyu(ZJUXING temp, char tianchong);


/*����һ�����ľ���ͼ �Ƽ���������ʹ�ô˺���
ʹ��huizhijuxing() �����Ч
void huizhitujuxing(char ������ε�X������,
char ������ε�Y����, 
char ������εĸ�,
char ������εĿ�)
*/
extern void huizhitujuxing(char x, char y, char h, char w);

/*����һ���߶�
void huizhixianduan(char �߶�����X������,
char �߶�����Y������,
char �߶��յ��X������,
char �߶��յ��Y������);*/
extern void huizhixianduan(char, char, char, char);

/*����һ�������
void huizhiduobianxing(char  �������ε�X������,
char �������ε�Y������,
char* �����������е�����������ָ��,
char  ���������ж��ٸ�����);*/
extern void huizhiduobianxing(char, char, char(*)[], char);



/* �ײ���ƺ�����Ҫ��������л�Ч��
MainPing_D(int ������Ϣ)*/
extern void MainPing_D(char);
/*���������еľֲ�����
MainPing_Z(int ������Ϣ)*/
extern void MainPing_Z(char,uchar,uint);
/*���㸡���������*/
extern void MainPing_F_ONE();
/*���㸡�������ƺ�*/
extern void MainPing_F_END();
/*��Ϣ����*/
extern void Main_Xiaoxi();

/*�û��㸡������*/
extern void MainPing_FY_ONE(char, uint);
/*�û��㸡������*/
extern void MainPing_FY_END(char, uint);