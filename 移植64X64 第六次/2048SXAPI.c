#include"to2048moni.h"

void sleep(uint a)
{
	while(a--);
}

void shuaxinyihang(uchar hi)
{
	char wi = 0, i, temp = 1;
	for( wi = 0; wi < MAXW/8; wi++)
	{
		temp = 1;
		for(i = 0; i <= 7; i++)
		{
 
			G1 = (bit)(huanchonglv[hi][wi] & ( temp));
			R1 = (bit)(huanchonghong[hi][wi] & ( temp));	
			G2 = (bit)(huanchonglv[hi+16][wi] & ( temp));
			R2 = (bit)(huanchonghong[hi+16][wi] & ( temp));		
			sck = 0;
			sck = 1;
			temp <<= 1;	
		}

	}
	for( wi = 0; wi < MAXW/8; wi++)
	{
			temp = 1;
		for(i = 0; i <= 7; i++)
		{

			G1 = (bit)(huanchonglv[hi+32][wi] & ( temp));
			R1 = (bit)(huanchonghong[hi+32][wi] & ( temp));	
			G2 = (bit)(huanchonglv[hi+48][wi] & ( temp));
			R2 = (bit)(huanchonghong[hi+48][wi] & ( temp));		
			sck = 0;
			sck = 1;
			temp <<= 1;	
		}
			 

	}




		rck = 1;
		rck = 0;
	    rck = 1;
}


void hang(char a)
{
  switch(a)
        {
		case  0: scan0;break;
		  case  1: scan1;break;
		   case  2: scan2;break;
		    case  3: scan3;break;
             case  4: scan4;break;
		      case  5: scan5;break;
		       case  6: scan6;break;
		        case  7: scan7;break;
                 case  8: scan8;break;
		       case  9: scan9;break;
		      case 10:scan10;break;
		     case 11:scan11;break;
            case 12:scan12;break;
		   case 13:scan13;break;
		  case 14:scan14;break;
	     case 15:scan15;break;
	   default:break;
       } 


}
void shuaxin()
{	
	uchar hi,a = 6;	

	while(a--)
	for(hi = 0;hi<16;hi++){
	hang(hi);
 	shuaxinyihang(hi);
	OE = 0;
	sleep(600);
	OE = 1;
	}	
}