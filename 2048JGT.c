#include"to2048moni.h"

int main()
{	
	uint JA_XY;

	while (1)
	{
//并行层
		Main_Xiaoxi();
//底层
		if (jianchajiemian(J_Z))
		{
			MainPing_D(jianchajiemian(J_Z));
		}
//第二层
		JA_XY = _chaxunjiaodianA();
		while (jiancexiaoxi())
			MainPing_Z(jianchajiemian(J_Z),tanchuxiaoxi(),JA_XY);
//浮动层
		if (chaxunzhuangtaibiao(0))
		MainPing_F_ONE();
		shuaxin();
		if (chaxunzhuangtaibiao(0))
		MainPing_F_END();
	}


}

void MainPing_F_ONE()
{  
	huizhijdA_ONE();
	huizhijiaodianA(JDA_1);
}
void MainPing_F_END()
{
	huizhijdA_END();
}