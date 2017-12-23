#include"to2048moni.h"

//按钮控件
void kjanniu(ZANNIU temp,uchar xiaoxi, char x, char y)
{
	JUXING ctemp;
	huodequyu(&ctemp);
	if (xiaoxi == NOP)
	{
		shezhihuizhiquyu(temp->w, temp->n, temp->e, temp->s);
		quyucachu();
		shezhihuabiyanse(temp->ys1se);
		huizhi(temp->w, temp->n, temp->ys1, temp->ysh, temp->ysw);
				temp->xz = 1;
	}
	else if (xiaoxi == 7)
	{
		if (gjjuxingjiance(x, y, temp->w, temp->n, temp->e, temp->s))
		{
			if (temp->xz == 3)
			{
			shezhihuizhiquyu(temp->w, temp->n, temp->e, temp->s);
			quyucachu();
			shezhihuabiyanse(temp->ys2se);
			huizhi(temp->w, temp->n, temp->ys2, temp->ysh, temp->ysw);
			temp->xz = 2;
			}
			else
			{
				shezhihuizhiquyu(temp->w, temp->n, temp->e, temp->s);
				quyucachu();
				shezhihuabiyanse(temp->ys3se);
				huizhi(temp->w, temp->n, temp->ys3, temp->ysh, temp->ysw);
				temp->xz = 3;
			}
		}
	}
	else if (gjjuxingjiance(x, y, temp->w, temp->n, temp->e, temp->s))
	{
		if (temp->xz == 1)
		{
			shezhihuizhiquyu(temp->w, temp->n, temp->e, temp->s);
			quyucachu();
			shezhihuabiyanse(temp->ys2se);
			huizhi(temp->w, temp->n, temp->ys2, temp->ysh, temp->ysw);
			temp->xz = 2;
		}
	}
	else
	{
		if (temp->xz == 2)
		{
			shezhihuizhiquyu(temp->w, temp->n, temp->e, temp->s);
			quyucachu();
			shezhihuabiyanse(temp->ys1se);
			huizhi(temp->w, temp->n, temp->ys1, temp->ysh, temp->ysw);
			temp->xz = 1;
		}

	}
	shezhihuizhiquyu(ctemp.w, ctemp.n, ctemp.e, ctemp.s);

}

//查询按钮状态
char chaxunkjanniu(ZANNIU temp)
{
	return temp->xz;

}
//组合关联选择按钮(单选)
void zuheanniu(ZANNIU((*temp)[]), uchar xiaoxi, char x, char y, uchar i,uchar *z)
{
	char a = 0,b = 0;
	for (a = 0; a < i; a++)
	{
		kjanniu((*temp)[a], xiaoxi, x, y);
		if ((*temp)[a]->xz == 3&&gjjuxingjiance(x,y,(*temp)[a]->w,(*temp)[a]->n,(*temp)[a]->e,(*temp)[a]->s))
		{
			for (b = 0; b < i; b++)
			{
				if ((*temp)[b]->xz == 3&&b != a)
				{

					(*temp)[b]->xz = 1;
					kjanniu((*temp)[b],NOP, NOP, NOP);					
				}
			}
			(*z) = a;
		}
	}
	for (a = 0; a < i; a++)
	{
		if ((*temp)[a]->xz == 3)
		{
			b = 0;
			break;
		}
	}
	if (b)
	{
		(*z) = NOP;
	}


}

//滑块查表
uchar kjhuakuaibiao[] = { 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,1};
uchar kjhuakuaichabiao(uchar x)
{
	if (x < 12)
	{
		return(kjhuakuaibiao[x]);
	}
	return 0;
}
//改变滑块
void gbkjhuakuai(ZHUAKUAI temp,char x, char y)
{
	temp->w += x;
	temp->e += x;
	temp->n += y;
	temp->s += y;
}
//同步滑块
void tbkjhuakuai(ZHUAKUAI temp)
{

	temp->wi = temp->w;
	temp->ei = temp->e;
	temp->ni = temp->n;
	temp->si = temp->s;

}
//控件无限制滑块
void kjhuakuai(ZHUAKUAI temp, uchar xiaoxi, char x, char y)
{
	JUXING ctemp;
	huodequyu(&ctemp);
	if (xiaoxi == NOP)
	{
		shezhihuizhiquyu(temp->w, temp->n, temp->e, temp->s);
		quyucachu();
		shezhihuabiyanse(temp->ys1se);
		huizhi(temp->w, temp->n, temp->ys1, temp->ysh, temp->ysw);
		temp->xz = 1;
	}
	else if (xiaoxi == 6)
	{
		if (gjjuxingjiance(x, y, temp->w, temp->n, temp->e, temp->s))
		{
			if (temp->xz == 2)
			{
				shezhihuizhiquyu(temp->w, temp->n, temp->e, temp->s);
				quyucachu();
				shezhihuabiyanse(temp->ys3se);
				huizhi(temp->w, temp->n, temp->ys3, temp->ysh, temp->ysw);
				temp->xz = 3;
			}
		}
	}
	else if (xiaoxi == 7 )
	{
			if (temp->xz == 3)
			{
				shezhihuizhiquyu(temp->w, temp->n, temp->e, temp->s);
				quyucachu();
				shezhihuabiyanse(temp->ys2se);
				huizhi(temp->w, temp->n, temp->ys2, temp->ysh, temp->ysw);
				temp->xz = 2;
		}
	}
	else if (kjhuakuaichabiao(xiaoxi) && temp->xz == 3)
	{
		switch (xiaoxi)
		{
		case 1:
			gbkjhuakuai(temp, 0, 1);
			break;
		case 2:
			gbkjhuakuai(temp, -1, 0);
			break;
		case 3:
			gbkjhuakuai(temp, 0, -1);
			break;
		case 4:
			gbkjhuakuai(temp, 1, 0);
			break;
		}

		shezhihuizhiquyu(temp->wi, temp->ni, temp->ei, temp->si);
		quyucachu();
		tbkjhuakuai(temp);
		shezhihuabiyanse(temp->ys3se);
		huizhi(temp->w, temp->n, temp->ys3, temp->ysh, temp->ysw);
		temp->xz = 3;
	}
	else if (gjjuxingjiance(x, y, temp->w, temp->n, temp->e, temp->s))
	{
		if (temp->xz == 1)
		{
			shezhihuizhiquyu(temp->w, temp->n, temp->e, temp->s);
			quyucachu();
			shezhihuabiyanse(temp->ys2se);
			huizhi(temp->w, temp->n, temp->ys2, temp->ysh, temp->ysw);
			temp->xz = 2;
		}
	}
	else
	{
		if (temp->xz == 2)
		{
			shezhihuizhiquyu(temp->w, temp->n, temp->e, temp->s);
			quyucachu();
			shezhihuabiyanse(temp->ys1se);
			huizhi(temp->w, temp->n, temp->ys1, temp->ysh, temp->ysw);
			temp->xz = 1;
		}

	}
	shezhihuizhiquyu(ctemp.w, ctemp.n, ctemp.e, ctemp.s);

}
