#include"to2048moni.h"


void huizhijuxingquyuhuizhi(uchar(*huanchong)[MAXH][MAXW / 8], ZJUXING temp, char tianchong)
{
	char x, y, ws = (temp->w / 8), wy = (temp->w & 7), es = (temp->e / 8), ey = (temp->e & 7);
	if (es == ws)
	{

		//1///////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w + 7) / 8 && ws < (_huizhiquyu.e / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws])
				|
				(_hui_juxing[ey - wy] << (wy)));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					(_hui_juxing[ey - wy] << (wy)));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					(0x01 << (wy)));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws])
				|
				(_hui_juxing[ey - wy] << wy));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					(_hui_juxing[ey - wy] << wy));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					(0x01 << (ey)));
			}
		}
		/////////2//////////////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w + 7) / 8 && ws < ((_huizhiquyu.e + 7) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws])
				|
				((_hui_juxing[ey - wy] << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((_hui_juxing[ey - wy] << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((0x01 << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws])
				|
				((_hui_juxing[ey - wy] << wy)&_huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((_hui_juxing[ey - wy] << wy)&_huizhi_buhou[_huizhiquyu.e & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((0x01 << (ey))&_huizhi_buhou[_huizhiquyu.e & 7]));
			}
		}

		///////3////////////////////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w) / 8 && ws < ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws])
				|
				((_hui_juxing[ey - wy] << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((_hui_juxing[ey - wy] << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((0x01 << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws])
				|
				((_hui_juxing[ey - wy] << wy)&_huizhi_buqian[_huizhiquyu.w & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((_hui_juxing[ey - wy] << wy)&_huizhi_buqian[_huizhiquyu.w & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((0x01 << (ey))&_huizhi_buqian[_huizhiquyu.w & 7]));
			}
		}
		//////////////4////////////////////////////////////////////////////////////////
		if (ws == (_huizhiquyu.w) / 8 && ws == ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws])
				|
				((_hui_juxing[ey - wy] << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((_hui_juxing[ey - wy] << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((0x01 << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws])
				|
				((_hui_juxing[ey - wy] << wy)&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((_hui_juxing[ey - wy] << wy)&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((0x01 << (ey))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			}
		}

	}
	///////////////////////分界////////////////////////////////////////////////////
	else
	{
		////////1///////////////////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w + 7) / 8 && ws < (_huizhiquyu.e / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws]) | (0xff << (wy)));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) | (0xff << (wy)));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					(0x01 << (wy)));
			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws]) | (0xff << (wy)));
		}
		//////2///////////////////////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w + 7) / 8 && ws < ((_huizhiquyu.e + 7) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws]) |
				((0xff << (wy)))&_huizhi_buhou[_huizhiquyu.e & 7]);
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((0xff << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((0x01 << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]));
			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws]) |
				((0xff << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]));
		}
		////////3///////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w) / 8 && ws < ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws]) |
				((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((0x01 << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));
			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws]) |
				((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));
		}
		////////4/////////////////////////////////////////////////////////////////////
		if (ws == (_huizhiquyu.w) / 8 && ws == ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws]) |
				((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) |
					((0x01 << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws]) |
				((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
		}

		///////////分界2/////////////////////////////////////////////////////////////////////////
		x = ws;
		for (x++; x < es; x++)
		{
			//////////1///////////////////////////////////////////////////////////////////////////
			if (x >= (_huizhiquyu.w + 7) / 8 && x < (_huizhiquyu.e / 8))
			{
				if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
					(*huanchong)[temp->n][x] = 0;
				if (tianchong)
				{
					for (y = temp->n + 1; y < temp->s; y++)
					if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
						(*huanchong)[y][x] = 0;

				}
				if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
					(*huanchong)[temp->s][x] = 0;
			}
			////////2///////////////////////////////////////////////////////////////////
			if (x >= (_huizhiquyu.w + 7) / 8 && x < ((_huizhiquyu.e + 7) / 8))
			{
				if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
					(*huanchong)[temp->n][x] = ~((~(*huanchong)[temp->n][x]) |
					(0xff & _huizhi_buhou[_huizhiquyu.e & 7]));
				if (tianchong)
				{
					for (y = temp->n + 1; y < temp->s; y++)
					if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
						(*huanchong)[y][x] = ~((~(*huanchong)[y][x]) |
						(0xff & _huizhi_buhou[_huizhiquyu.e & 7]));

				}
				if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
					(*huanchong)[temp->s][x] = ~((~(*huanchong)[temp->s][x]) |
					(0xff & _huizhi_buhou[_huizhiquyu.e & 7]));
			}
			//////////3////////////////////////////////////////////////////////////////////////////
			if (x >= (_huizhiquyu.w) / 8 && x < ((_huizhiquyu.e) / 8))
			{
				if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
					(*huanchong)[temp->n][x] = ~((~(*huanchong)[temp->n][x]) |
					(0xff & _huizhi_buqian[_huizhiquyu.w & 7]));
				if (tianchong)
				{
					for (y = temp->n + 1; y < temp->s; y++)
					if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
						(*huanchong)[y][x] = ~((~(*huanchong)[y][x]) |
						(0xff & _huizhi_buqian[_huizhiquyu.w & 7]));

				}
				if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
					(*huanchong)[temp->s][x] = ~((~(*huanchong)[temp->s][x]) |
					(0xff & _huizhi_buqian[_huizhiquyu.w & 7]));
			}
			////////4/////////////////////////////////////////////////////////
			if (x == (_huizhiquyu.w) / 8 && x == ((_huizhiquyu.e) / 8))
			{
				if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
					(*huanchong)[temp->n][x] = ~((~(*huanchong)[temp->n][x]) |
					(0xff & _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
				if (tianchong)
				{
					for (y = temp->n + 1; y < temp->s; y++)
					if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
						(*huanchong)[y][x] = ~((~(*huanchong)[y][x]) |
						(0xff & _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));

				}
				if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
					(*huanchong)[temp->s][x] = ~((~(*huanchong)[temp->s][x]) |
					(0xff & _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			}


		}
		///////////分界3///////////////////////////////////////////////////////
		///////1////////////////////////////////////////////////////////
		if (es >= (_huizhiquyu.w + 7) / 8 && es < (_huizhiquyu.e / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][es] =
				~((~(*huanchong)[temp->n][es]) | (~(0xff << (ey)+1)));
			if (tianchong)
			{

				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) | (~(0xff << (ey)+1)));

			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) |
					(0x01 << (ey)));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][es] =
				~((~(*huanchong)[temp->s][es]) | (~(0xff << (ey)+1)));
		}
		////2////////////////////////////////////////////////////////////////////////////////
		if (es >= (_huizhiquyu.w + 7) / 8 && es < ((_huizhiquyu.e + 7) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][es] =
				~((~(*huanchong)[temp->n][es]) |
				((~(0xff << (ey)+1))& _huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{

				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) |
					((~(0xff << (ey)+1))& _huizhi_buhou[_huizhiquyu.e & 7]));

			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) |
					((0x01 << (ey))& _huizhi_buhou[_huizhiquyu.e & 7]));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][es] =
				~((~(*huanchong)[temp->s][es]) |
				((~(0xff << (ey)+1))& _huizhi_buhou[_huizhiquyu.e & 7]));
		}
		/////3///////////////////////////////////////////////////////////////////////////
		if (es >= (_huizhiquyu.w) / 8 && es < ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][es] =
				~((~(*huanchong)[temp->n][es]) |
				((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7]));
			if (tianchong)
			{

				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) |
					((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7]));

			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) |
					((0x01 << (ey))& _huizhi_buqian[_huizhiquyu.w & 7]));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][es] =
				~((~(*huanchong)[temp->s][es]) |
				((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7]));
		}

		/////////4////////////////////////////////////////////////////////////////////////////
		if (es == (_huizhiquyu.w) / 8 && es == ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][es] =
				~((~(*huanchong)[temp->n][es]) |
				((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{

				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) |
					((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));

			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) |
					((0x01 << (ey))& _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][es] =
				~((~(*huanchong)[temp->s][es]) |
				((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
		}


	}


}
void huizhijuxingquyucachu(uchar(*huanchong)[MAXH][MAXW / 8], ZJUXING temp, char tianchong)
{
	char x, y, ws = (temp->w / 8), wy = (temp->w & 7), es = (temp->e / 8), ey = (temp->e & 7);
	if (es == ws)
	{

		//1///////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w + 7) / 8 && ws < (_huizhiquyu.e / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				((*huanchong)[temp->n][ws])
				|
				(_hui_juxing[ey - wy] << (wy));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					(_hui_juxing[ey - wy] << (wy));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					(0x01 << (wy));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				((*huanchong)[temp->s][ws])
				|
				(_hui_juxing[ey - wy] << wy);
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					(_hui_juxing[ey - wy] << wy);
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					(0x01 << (ey));
			}
		}
		/////////2//////////////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w + 7) / 8 && ws < ((_huizhiquyu.e + 7) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				((*huanchong)[temp->n][ws])
				|
				((_hui_juxing[ey - wy] << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]);
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((_hui_juxing[ey - wy] << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]);
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((0x01 << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]);

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				((*huanchong)[temp->s][ws])
				|
				((_hui_juxing[ey - wy] << wy)&_huizhi_buhou[_huizhiquyu.e & 7]);
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((_hui_juxing[ey - wy] << wy)&_huizhi_buhou[_huizhiquyu.e & 7]);
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((0x01 << (ey))&_huizhi_buhou[_huizhiquyu.e & 7]);
			}
		}

		///////3////////////////////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w) / 8 && ws < ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				((*huanchong)[temp->n][ws])
				|
				((_hui_juxing[ey - wy] << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]);
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((_hui_juxing[ey - wy] << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]);
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((0x01 << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]);

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				((*huanchong)[temp->s][ws])
				|
				((_hui_juxing[ey - wy] << wy)&_huizhi_buqian[_huizhiquyu.w & 7]);
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((_hui_juxing[ey - wy] << wy)&_huizhi_buqian[_huizhiquyu.w & 7]);
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((0x01 << (ey))&_huizhi_buqian[_huizhiquyu.w & 7]);
			}
		}
		//////////////4////////////////////////////////////////////////////////////////
		if (ws == (_huizhiquyu.w) / 8 && ws == ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				((*huanchong)[temp->n][ws])
				|
				((_hui_juxing[ey - wy] << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((_hui_juxing[ey - wy] << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((0x01 << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				((*huanchong)[temp->s][ws])
				|
				((_hui_juxing[ey - wy] << wy)&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((_hui_juxing[ey - wy] << wy)&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((0x01 << (ey))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);
			}
		}

	}
	///////////////////////分界////////////////////////////////////////////////////
	else
	{
		////////1///////////////////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w + 7) / 8 && ws < (_huizhiquyu.e / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				((*huanchong)[temp->n][ws]) | (0xff << (wy));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) | (0xff << (wy));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					(0x01 << (wy));
			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				((*huanchong)[temp->s][ws]) | (0xff << (wy));
		}
		//////2///////////////////////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w + 7) / 8 && ws < ((_huizhiquyu.e + 7) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				((*huanchong)[temp->n][ws]) |
				((0xff << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]);
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((0xff << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]);
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((0x01 << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]);
			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				((*huanchong)[temp->s][ws]) |
				((0xff << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]);
		}
		////////3///////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w) / 8 && ws < ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				((*huanchong)[temp->n][ws]) |
				((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]);
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]);
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((0x01 << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]);
			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				((*huanchong)[temp->s][ws]) |
				((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]);
		}
		////////4/////////////////////////////////////////////////////////////////////
		if (ws == (_huizhiquyu.w) / 8 && ws == ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				((*huanchong)[temp->n][ws]) |
				((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					((*huanchong)[y][ws]) |
					((0x01 << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);
			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				((*huanchong)[temp->s][ws]) |
				((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);
		}

		///////////分界2/////////////////////////////////////////////////////////////////////////
		x = ws;
		for (x++; x < es; x++)
		{
			//////////1///////////////////////////////////////////////////////////////////////////
			if (x >= (_huizhiquyu.w + 7) / 8 && x < (_huizhiquyu.e / 8))
			{
				if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
					(*huanchong)[temp->n][x] = 0xff;
				if (tianchong)
				{
					for (y = temp->n + 1; y < temp->s; y++)
					if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
						(*huanchong)[y][x] = 0xff;

				}
				if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
					(*huanchong)[temp->s][x] = 0xff;
			}
			////////2///////////////////////////////////////////////////////////////////
			if (x >= (_huizhiquyu.w + 7) / 8 && x < ((_huizhiquyu.e + 7) / 8))
			{
				if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
					(*huanchong)[temp->n][x] = ((*huanchong)[temp->n][x]) |
					(0xff & _huizhi_buhou[_huizhiquyu.e & 7]);
				if (tianchong)
				{
					for (y = temp->n + 1; y < temp->s; y++)
					if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
						(*huanchong)[y][x] = ((*huanchong)[y][x]) |
						(0xff & _huizhi_buhou[_huizhiquyu.e & 7]);

				}
				if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
					(*huanchong)[temp->s][x] = ((*huanchong)[temp->s][x]) |
					(0xff & _huizhi_buhou[_huizhiquyu.e & 7]);
			}
			//////////3////////////////////////////////////////////////////////////////////////////
			if (x >= (_huizhiquyu.w) / 8 && x < ((_huizhiquyu.e) / 8))
			{
				if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
					(*huanchong)[temp->n][x] = ((*huanchong)[temp->n][x]) |
					(0xff & _huizhi_buqian[_huizhiquyu.w & 7]);
				if (tianchong)
				{
					for (y = temp->n + 1; y < temp->s; y++)
					if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
						(*huanchong)[y][x] = ((*huanchong)[y][x]) |
						(0xff & _huizhi_buqian[_huizhiquyu.w & 7]);

				}
				if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
					(*huanchong)[temp->s][x] = ((*huanchong)[temp->s][x]) |
					(0xff & _huizhi_buqian[_huizhiquyu.w & 7]);
			}
			////////4/////////////////////////////////////////////////////////
			if (x == (_huizhiquyu.w) / 8 && x == ((_huizhiquyu.e) / 8))
			{
				if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
					(*huanchong)[temp->n][x] = ((*huanchong)[temp->n][x]) |
					(0xff & _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);
				if (tianchong)
				{
					for (y = temp->n + 1; y < temp->s; y++)
					if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
						(*huanchong)[y][x] = ((*huanchong)[y][x]) |
						(0xff & _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);

				}
				if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
					(*huanchong)[temp->s][x] = ((*huanchong)[temp->s][x]) |
					(0xff & _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);
			}


		}
		///////////分界3///////////////////////////////////////////////////////
		///////1////////////////////////////////////////////////////////
		if (es >= (_huizhiquyu.w + 7) / 8 && es < (_huizhiquyu.e / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][es] =
				((*huanchong)[temp->n][es]) | (~(0xff << (ey)+1));
			if (tianchong)
			{

				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					((*huanchong)[y][es]) | (~(0xff << (ey)+1));

			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					((*huanchong)[y][es]) |
					(0x01 << (ey));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][es] =
				((*huanchong)[temp->s][es]) | (~(0xff << (ey)+1));
		}
		////2////////////////////////////////////////////////////////////////////////////////
		if (es >= (_huizhiquyu.w + 7) / 8 && es < ((_huizhiquyu.e + 7) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][es] =
				((*huanchong)[temp->n][es]) |
				((~(0xff << (ey)+1))& _huizhi_buhou[_huizhiquyu.e & 7]);
			if (tianchong)
			{

				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					((*huanchong)[y][es]) |
					((~(0xff << (ey)+1))& _huizhi_buhou[_huizhiquyu.e & 7]);

			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					((*huanchong)[y][es]) |
					((0x01 << (ey))& _huizhi_buhou[_huizhiquyu.e & 7]);

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][es] =
				((*huanchong)[temp->s][es]) |
				((~(0xff << (ey)+1))& _huizhi_buhou[_huizhiquyu.e & 7]);
		}
		/////3///////////////////////////////////////////////////////////////////////////
		if (es >= (_huizhiquyu.w) / 8 && es < ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][es] =
				((*huanchong)[temp->n][es]) |
				((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7]);
			if (tianchong)
			{

				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					((*huanchong)[y][es]) |
					((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7]);

			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					((*huanchong)[y][es]) |
					((0x01 << (ey))& _huizhi_buqian[_huizhiquyu.w & 7]);

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][es] =
				((*huanchong)[temp->s][es]) |
				((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7]);
		}

		/////////4////////////////////////////////////////////////////////////////////////////
		if (es == (_huizhiquyu.w) / 8 && es == ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][es] =
				((*huanchong)[temp->n][es]) |
				((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);
			if (tianchong)
			{

				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					((*huanchong)[y][es]) |
					((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);

			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					((*huanchong)[y][es]) |
					((0x01 << (ey))& _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][es] =
				((*huanchong)[temp->s][es]) |
				((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]);
		}


	}


}
void huizhijuxingquyuqufan(uchar(*huanchong)[MAXH][MAXW / 8], ZJUXING temp, char tianchong)
{
	char x, y, ws = (temp->w / 8), wy = (temp->w & 7), es = (temp->e / 8), ey = (temp->e & 7);
	if (es == ws)
	{

		//1///////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w + 7) / 8 && ws < (_huizhiquyu.e / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws])
				^
				(_hui_juxing[ey - wy] << (wy)));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					(_hui_juxing[ey - wy] << (wy)));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					(0x01 << (wy)));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws])
				^
				(_hui_juxing[ey - wy] << wy));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					(_hui_juxing[ey - wy] << wy));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					(0x01 << (ey)));
			}
		}
		/////////2//////////////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w + 7) / 8 && ws < ((_huizhiquyu.e + 7) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws])
				^
				((_hui_juxing[ey - wy] << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((_hui_juxing[ey - wy] << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((0x01 << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws])
				^
				((_hui_juxing[ey - wy] << wy)&_huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((_hui_juxing[ey - wy] << wy)&_huizhi_buhou[_huizhiquyu.e & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((0x01 << (ey))&_huizhi_buhou[_huizhiquyu.e & 7]));
			}
		}

		///////3////////////////////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w) / 8 && ws < ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws])
				^
				((_hui_juxing[ey - wy] << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((_hui_juxing[ey - wy] << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((0x01 << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws])
				^
				((_hui_juxing[ey - wy] << wy)&_huizhi_buqian[_huizhiquyu.w & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((_hui_juxing[ey - wy] << wy)&_huizhi_buqian[_huizhiquyu.w & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((0x01 << (ey))&_huizhi_buqian[_huizhiquyu.w & 7]));
			}
		}
		//////////////4////////////////////////////////////////////////////////////////
		if (ws == (_huizhiquyu.w) / 8 && ws == ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws])
				^
				((_hui_juxing[ey - wy] << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((_hui_juxing[ey - wy] << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((0x01 << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws])
				^
				((_hui_juxing[ey - wy] << wy)&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((_hui_juxing[ey - wy] << wy)&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((0x01 << (ey))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			}
		}

	}
	///////////////////////分界////////////////////////////////////////////////////
	else
	{
		////////1///////////////////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w + 7) / 8 && ws < (_huizhiquyu.e / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws]) | (0xff << (wy)));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^ (0xff << (wy)));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					(0x01 << (wy)));
			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws]) ^ (0xff << (wy)));
		}
		//////2///////////////////////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w + 7) / 8 && ws < ((_huizhiquyu.e + 7) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws]) ^
				((0xff << (wy)))&_huizhi_buhou[_huizhiquyu.e & 7]);
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((0xff << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((0x01 << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]));
			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws]) ^
				((0xff << (wy))&_huizhi_buhou[_huizhiquyu.e & 7]));
		}
		////////3///////////////////////////////////////////////////////////
		if (ws >= (_huizhiquyu.w) / 8 && ws < ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws]) ^
				((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((0x01 << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));
			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws]) ^
				((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7]));
		}
		////////4/////////////////////////////////////////////////////////////////////
		if (ws == (_huizhiquyu.w) / 8 && ws == ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][ws] =
				~((~(*huanchong)[temp->n][ws]) ^
				((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][ws] =
					~((~(*huanchong)[y][ws]) ^
					((0x01 << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][ws] =
				~((~(*huanchong)[temp->s][ws]) ^
				((0xff << (wy))&_huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
		}

		///////////分界2/////////////////////////////////////////////////////////////////////////
		x = ws;
		for (x++; x < es; x++)
		{
			//////////1///////////////////////////////////////////////////////////////////////////
			if (x >= (_huizhiquyu.w + 7) / 8 && x < (_huizhiquyu.e / 8))
			{
				if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
					(*huanchong)[temp->n][x] = ~(*huanchong)[temp->n][x];
				if (tianchong)
				{
					for (y = temp->n + 1; y < temp->s; y++)
					if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
						(*huanchong)[y][x] = ~(*huanchong)[y][x];

				}
				if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
					(*huanchong)[temp->s][x] = ~(*huanchong)[temp->s][x];
			}
			////////2///////////////////////////////////////////////////////////////////
			if (x >= (_huizhiquyu.w + 7) / 8 && x < ((_huizhiquyu.e + 7) / 8))
			{
				if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
					(*huanchong)[temp->n][x] = ~((~(*huanchong)[temp->n][x]) ^
					(0xff & _huizhi_buhou[_huizhiquyu.e & 7]));
				if (tianchong)
				{
					for (y = temp->n + 1; y < temp->s; y++)
					if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
						(*huanchong)[y][x] = ~((~(*huanchong)[y][x]) ^
						(0xff & _huizhi_buhou[_huizhiquyu.e & 7]));

				}
				if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
					(*huanchong)[temp->s][x] = ~((~(*huanchong)[temp->s][x]) ^
					(0xff & _huizhi_buhou[_huizhiquyu.e & 7]));
			}
			//////////3////////////////////////////////////////////////////////////////////////////
			if (x >= (_huizhiquyu.w) / 8 && x < ((_huizhiquyu.e) / 8))
			{
				if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
					(*huanchong)[temp->n][x] = ~((~(*huanchong)[temp->n][x]) ^
					(0xff & _huizhi_buqian[_huizhiquyu.w & 7]));
				if (tianchong)
				{
					for (y = temp->n + 1; y < temp->s; y++)
					if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
						(*huanchong)[y][x] = ~((~(*huanchong)[y][x]) ^
						(0xff & _huizhi_buqian[_huizhiquyu.w & 7]));

				}
				if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
					(*huanchong)[temp->s][x] = ~((~(*huanchong)[temp->s][x]) ^
					(0xff & _huizhi_buqian[_huizhiquyu.w & 7]));
			}
			////////4/////////////////////////////////////////////////////////
			if (x == (_huizhiquyu.w) / 8 && x == ((_huizhiquyu.e) / 8))
			{
				if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
					(*huanchong)[temp->n][x] = ~((~(*huanchong)[temp->n][x]) ^
					(0xff & _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
				if (tianchong)
				{
					for (y = temp->n + 1; y < temp->s; y++)
					if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
						(*huanchong)[y][x] = ~((~(*huanchong)[y][x]) ^
						(0xff & _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));

				}
				if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
					(*huanchong)[temp->s][x] = ~((~(*huanchong)[temp->s][x]) ^
					(0xff & _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			}


		}
		///////////分界3///////////////////////////////////////////////////////
		///////1////////////////////////////////////////////////////////
		if (es >= (_huizhiquyu.w + 7) / 8 && es < (_huizhiquyu.e / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][es] =
				~((~(*huanchong)[temp->n][es]) ^ (~(0xff << (ey)+1)));
			if (tianchong)
			{

				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) ^ (~(0xff << (ey)+1)));

			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) ^
					(0x01 << (ey)));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][es] =
				~((~(*huanchong)[temp->s][es]) ^ (~(0xff << (ey)+1)));
		}
		////2////////////////////////////////////////////////////////////////////////////////
		if (es >= (_huizhiquyu.w + 7) / 8 && es < ((_huizhiquyu.e + 7) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][es] =
				~((~(*huanchong)[temp->n][es]) ^
				((~(0xff << (ey)+1))& _huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{

				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) ^
					((~(0xff << (ey)+1))& _huizhi_buhou[_huizhiquyu.e & 7]));

			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) ^
					((0x01 << (ey))& _huizhi_buhou[_huizhiquyu.e & 7]));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][es] =
				~((~(*huanchong)[temp->s][es]) ^
				((~(0xff << (ey)+1))& _huizhi_buhou[_huizhiquyu.e & 7]));
		}
		/////3///////////////////////////////////////////////////////////////////////////
		if (es >= (_huizhiquyu.w) / 8 && es < ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][es] =
				~((~(*huanchong)[temp->n][es]) ^
				((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7]));
			if (tianchong)
			{

				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) ^
					((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7]));

			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) ^
					((0x01 << (ey))& _huizhi_buqian[_huizhiquyu.w & 7]));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][es] =
				~((~(*huanchong)[temp->s][es]) ^
				((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7]));
		}

		/////////4////////////////////////////////////////////////////////////////////////////
		if (es == (_huizhiquyu.w) / 8 && es == ((_huizhiquyu.e) / 8))
		{
			if (temp->n >= _huizhiquyu.n && temp->n < _huizhiquyu.s)
				(*huanchong)[temp->n][es] =
				~((~(*huanchong)[temp->n][es]) ^
				((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
			if (tianchong)
			{

				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) ^
					((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));

			}
			else
			{
				for (y = temp->n + 1; y < temp->s; y++)
				if (y >= _huizhiquyu.n && y < _huizhiquyu.s)
					(*huanchong)[y][es] =
					~((~(*huanchong)[y][es]) ^
					((0x01 << (ey))& _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));

			}
			if (temp->s >= _huizhiquyu.n && temp->s < _huizhiquyu.s)
				(*huanchong)[temp->s][es] =
				~((~(*huanchong)[temp->s][es]) ^
				((~(0xff << (ey)+1))& _huizhi_buqian[_huizhiquyu.w & 7] & _huizhi_buhou[_huizhiquyu.e & 7]));
		}


	}


}
void huizhijuxingquyu(ZJUXING temp, char tianchong)
{
	//处理画笔信息
	if (huabiyanse == 0)
	{
		huizhijuxingquyucachu(&huanchonghong, temp, tianchong);
		huizhijuxingquyuhuizhi(&huanchonglv, temp, tianchong);

	}
	else if (huabiyanse == 1)
	{
		huizhijuxingquyucachu(&huanchonglv, temp, tianchong);
		huizhijuxingquyuhuizhi(&huanchonghong, temp, tianchong);;
	}
	else if (huabiyanse == 3)
	{
		huizhijuxingquyuhuizhi(&huanchonghong, temp, tianchong);
		huizhijuxingquyuhuizhi(&huanchonglv, temp, tianchong);
	}
	else if (huabiyanse == 4)
	{
		huizhijuxingquyuhuizhi(&huanchonglv, temp, tianchong);
	}
	else if (huabiyanse == 5)
	{
		huizhijuxingquyuhuizhi(&huanchonghong, temp, tianchong);
	}
	else if (huabiyanse == 6)
	{
		huizhijuxingquyuqufan(&huanchonglv, temp, tianchong);
	}
	else if (huabiyanse == 7)
	{
		huizhijuxingquyuqufan(&huanchonghong, temp, tianchong);
	}
	else if (huabiyanse == 8)
	{
		huizhijuxingquyuqufan(&huanchonghong, temp, tianchong);
		huizhijuxingquyuqufan(&huanchonglv, temp, tianchong);
	}
	else
	{
		return;
	}

}