#include"to2048moni.h"

int main()
{	
P0M0 = 0;
P0M1 = 0;
P1M0 = 0;
P1M1 = 0;
P2M0 = 0;
P2M1 = 0;
P3M0 = 0;
P3M1 = 0;
S1 = 1;
S2 = 1;
S3 = 1;
S4 = 1;
	while (1)
	{


		
//???
		Main_Xiaoxi();
		
//??
		if (jianchajiemian(J_Z))
		{
			MainPing_D(chaxunjiemian(J_Z));
			shuaxin();
		}
//?????
		 
		while (jiancexiaoxi())
			MainPing_Z(chaxunjiemian(J_Z),tanchuxiaoxi(),chaxunjiaodian_A());
		//???	
		MainPing_FY_ONE(chaxunjiemian(J_Z), chaxunjiaodian_A());

		if (chaxunzhuangtaibiao(0))
			MainPing_F_ONE();

		shuaxin();

		if (chaxunzhuangtaibiao(0))
			MainPing_F_END();

		MainPing_FY_END(chaxunjiemian(J_Z), chaxunjiaodian_A());
	}


}

void MainPing_F_ONE()
{  
	huizhijd_ONE(&JDA_Z,JDA_Z_1,JDA_Z_2);
	huizhijiaodian(&JDA_Z,SE_CHENGFAN);
}
void MainPing_F_END()
{
	huizhijd_END(&JDA_Z, JDA_Z_1, JDA_Z_2);
}