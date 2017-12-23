#include"to2048moni.h"

//��Ϣ����
XIAOXI _xiaoxiduilie = { 0, 0, 0, 0, 0, 0 };

char _zhuangtaibiao[8] = { 1, 0, 0, 0, 0, 0, 0, 0 };//״̬��

char _shijianbiao[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };//ʱ������ �� �� ʱ �� �� ���� ����/����

char _jiemian[8] = { 1, 0, 0, 0, 0, 0, 0, 0};//�����
char _jiemiant[8] = { 0, 0, 0, 0, 0, 0, 0, 0};//�����T




//�޸�״̬��
void xiugaizhuangtaibiao(char temp, char key)
{
	_zhuangtaibiao[key] = temp;
}

//��ѯ״̬��
char chaxunzhuangtaibiao( char key)
{
	return _zhuangtaibiao[key];
}

//��λ״̬��
void fuweizhuangtaibiao()
{
	_zhuangtaibiao[0] =  1 ;
	_zhuangtaibiao[1] &= 0x00;
	_zhuangtaibiao[2] &= 0x00;
	_zhuangtaibiao[3] &= 0x00;
	_zhuangtaibiao[4] &= 0x00;
	_zhuangtaibiao[5] &= 0x00;
	_zhuangtaibiao[6] &= 0x00;
	_zhuangtaibiao[7] &= 0x00;

}

//�޸Ľ���ָʾ��
void xiugaijiemian(char temp,char ceng)
{
	_jiemian[ceng] = temp;
}

//�������Ƿ�䶯
uchar jianchajiemian( char ceng)
{
	if (_jiemian[ceng] == _jiemiant[ceng])
	{
		return 0;
	}
	return 1;
}

//��ѯһ������ָʾ
char chaxunjiemian(char ceng)
{
	return _jiemian[ceng];
}

//ͬ������ָʾ��
void tongbujiemian(char ceng)
{
	_jiemiant[ceng] = _jiemian[ceng];
}

//����һ����Ϣ
uchar charuxiaoxi(uchar i,uchar tdata)
{
	char ix;
	if (_xiaoxiduilie.i < XIAOXIMAX)
	{
		if (i == END)//ĩβ������Ϣ
		{
			_xiaoxiduilie.xiaoxi[_xiaoxiduilie.i] = tdata;
			_xiaoxiduilie.i++;


			return 1;
		}
		else if(i == ONE)//��λ������Ϣ
		{
			ix = _xiaoxiduilie.i;
			for (; ix > 0; ix--)
			{
				_xiaoxiduilie.xiaoxi[ix] = _xiaoxiduilie.xiaoxi[ix - 1];
			}
			_xiaoxiduilie.xiaoxi[0] = tdata;
			_xiaoxiduilie.i++;
			return 1;
		}
	}
	return 0;
}

//����һ����Ϣ
uchar tanchuxiaoxi()
{
	char i;
	uchar tdata;
	if (_xiaoxiduilie.i == 0)
	{
		return NOP;
	}
	else
	{
		i = 0;
		tdata = _xiaoxiduilie.xiaoxi[0];

		for (; i <_xiaoxiduilie.i-1; i++)
		{
			_xiaoxiduilie.xiaoxi[i] = _xiaoxiduilie.xiaoxi[i+1];
		}
		_xiaoxiduilie.xiaoxi[i] = 0;
		_xiaoxiduilie.i--;
		return tdata;
	}

}

//�����Ϣ�����Ƿ�����Ϣ
char jiancexiaoxi()
{
	return _xiaoxiduilie.i;
}
