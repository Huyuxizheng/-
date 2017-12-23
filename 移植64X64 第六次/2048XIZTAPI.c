#include"to2048moni.h"

//消息队列
XIAOXI _xiaoxiduilie = { 0, 0, 0, 0, 0, 0 };

char _zhuangtaibiao[8] = { 1, 0, 0, 0, 0, 0, 0, 0 };//状态表

char _shijianbiao[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };//时间数据 秒 分 时 日 月 年年 上午/下午

char _jiemian[8] = { 1, 0, 0, 0, 0, 0, 0, 0};//界面表
char _jiemiant[8] = { 0, 0, 0, 0, 0, 0, 0, 0};//界面表T




//修改状态表
void xiugaizhuangtaibiao(char temp, char key)
{
	_zhuangtaibiao[key] = temp;
}

//查询状态表
char chaxunzhuangtaibiao( char key)
{
	return _zhuangtaibiao[key];
}

//复位状态表
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

//修改界面指示器
void xiugaijiemian(char temp,char ceng)
{
	_jiemian[ceng] = temp;
}

//检查界面是否变动
uchar jianchajiemian( char ceng)
{
	if (_jiemian[ceng] == _jiemiant[ceng])
	{
		return 0;
	}
	return 1;
}

//查询一个界面指示
char chaxunjiemian(char ceng)
{
	return _jiemian[ceng];
}

//同步界面指示器
void tongbujiemian(char ceng)
{
	_jiemiant[ceng] = _jiemian[ceng];
}

//插入一条消息
uchar charuxiaoxi(uchar i,uchar tdata)
{
	char ix;
	if (_xiaoxiduilie.i < XIAOXIMAX)
	{
		if (i == END)//末尾插入消息
		{
			_xiaoxiduilie.xiaoxi[_xiaoxiduilie.i] = tdata;
			_xiaoxiduilie.i++;


			return 1;
		}
		else if(i == ONE)//首位插入消息
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

//弹出一条消息
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

//检测消息队列是否有消息
char jiancexiaoxi()
{
	return _xiaoxiduilie.i;
}
