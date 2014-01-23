/********************************************************************************
*																				*
*		Practica 3 IG - Muñeco Nieve											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "TAfin.h"
#include <math.h>
#include <algorithm>


TAfin TAfin :: translated(float x, float y, float z)
{
	TAfin ret;
	ret.matriz[0] = matriz[0]; ret.matriz[4]=matriz[4]; ret.matriz[8]=matriz[8];   ret.matriz[12]=matriz[0]*x+matriz[4]*y+matriz[8]*z+matriz[12];
	ret.matriz[1] = matriz[1]; ret.matriz[5]=matriz[5]; ret.matriz[9]=matriz[9];   ret.matriz[13]=matriz[1]*x+matriz[5]*y+matriz[9]*z+matriz[13];
	ret.matriz[2] = matriz[2]; ret.matriz[6]=matriz[6]; ret.matriz[10]=matriz[10]; ret.matriz[14]=matriz[2]*x+matriz[6]*y+matriz[10]*z+matriz[14];
	ret.matriz[3] = matriz[3]; ret.matriz[7]=matriz[7]; ret.matriz[11]=matriz[11]; ret.matriz[15]=matriz[3]*x+matriz[7]*y+matriz[11]*z+matriz[15];
	return ret;
}

TAfin TAfin :: scaled(float sx, float sy, float sz)
{
	TAfin ret;
	ret.matriz[0] = matriz[0]*sx; ret.matriz[4] = matriz[4]*sy; ret.matriz[8] = matriz[8]*sz;  ret.matriz[12] = matriz[12];
	ret.matriz[1] = matriz[1]*sx; ret.matriz[5] = matriz[5]*sy; ret.matriz[9] = matriz[9]*sz;  ret.matriz[13] = matriz[13];
	ret.matriz[2] = matriz[2]*sx; ret.matriz[6] = matriz[6]*sy; ret.matriz[10] = matriz[10]*sz; ret.matriz[14] = matriz[14];
	ret.matriz[3] = matriz[3]*sx; ret.matriz[7] = matriz[7]*sy; ret.matriz[11] = matriz[11]*sz; ret.matriz[15] = matriz[15];
	return ret;
}

TAfin TAfin :: rotateX(float angle)
{
	TAfin ret;
	float coseno = cos(angle / 180 * 3.14159265);
	float seno = sin(angle / 180 * 3.14159265);

	ret.matriz[0] = matriz[0];
	ret.matriz[1] = matriz[1];
	ret.matriz[2] = matriz[2];
	ret.matriz[3] = matriz[3];
	ret.matriz[4] = matriz[4] * coseno + matriz[8] *seno;
    ret.matriz[5] = matriz[5] * coseno + matriz[9] *seno;
    ret.matriz[6] = matriz[6] * coseno + matriz[10]*seno;
    ret.matriz[7] = matriz[7] * coseno + matriz[11]*seno;
    ret.matriz[8] =-matriz[4] * seno + matriz[8] * coseno;
    ret.matriz[9] =-matriz[5] * seno + matriz[9] * coseno;
    ret.matriz[10]=-matriz[6] * seno + matriz[10]* coseno;
    ret.matriz[11]=-matriz[7] * seno + matriz[11]* coseno;
	ret.matriz[12]= matriz[12];
	ret.matriz[13]= matriz[13];
	ret.matriz[14]= matriz[14];
	ret.matriz[15]= matriz[15];

	return ret;
}

TAfin TAfin :: rotateY(float angle)
{
	TAfin ret;
	float coseno = cos(angle / 180 * 3.14159265);
	float seno = sin(angle / 180 * 3.14159265);

	ret.matriz[0] = matriz[0]*coseno - matriz[8]*seno;
	ret.matriz[1] = matriz[1]*coseno - matriz[9]*seno;
	ret.matriz[2] = matriz[2]*coseno - matriz[10]*seno;
	ret.matriz[3] = matriz[3]*coseno - matriz[11]*seno;
	ret.matriz[4] = matriz[4];
    ret.matriz[5] = matriz[5];
    ret.matriz[6] = matriz[6];
    ret.matriz[7] = matriz[7];
    ret.matriz[8] = matriz[0] * seno + matriz[8] * coseno;
    ret.matriz[9] = matriz[1] * seno + matriz[9] * coseno;
    ret.matriz[10]= matriz[2] * seno + matriz[10]* coseno;
    ret.matriz[11]= matriz[3] * seno + matriz[11]* coseno;
	ret.matriz[12]= matriz[12];
	ret.matriz[13]= matriz[13];
	ret.matriz[14]= matriz[14];
	ret.matriz[15]= matriz[15];

	return ret;
}

TAfin TAfin :: rotateZ(float angle)
{
	TAfin ret;
	float coseno = cos(angle / 180 * 3.14159265);
	float seno = sin(angle / 180 * 3.14159265);

	ret.matriz[0] = matriz[0]*coseno + matriz[4]*seno;
	ret.matriz[1] = matriz[1]*coseno + matriz[5]*seno;
	ret.matriz[2] = matriz[2]*coseno + matriz[6]*seno;
	ret.matriz[3] = matriz[3]*coseno + matriz[7]*seno;
	ret.matriz[4] =-matriz[0] * seno + matriz[4] * coseno;
    ret.matriz[5] =-matriz[1] * seno + matriz[5] * coseno;
    ret.matriz[6] =-matriz[2] * seno + matriz[6] * coseno;
    ret.matriz[7] =-matriz[3] * seno + matriz[7] * coseno;
    ret.matriz[8] = matriz[8];
    ret.matriz[9] = matriz[9];
    ret.matriz[10]= matriz[10];
    ret.matriz[11]= matriz[11];
	ret.matriz[12]= matriz[12];
	ret.matriz[13]= matriz[13];
	ret.matriz[14]= matriz[14];
	ret.matriz[15]= matriz[15];

	return ret;
}


TAfin TAfin :: postMultiplica(TAfin pos)
{
	TAfin ret;
	ret.matriz[0]=matriz[0]*pos.matriz[0]  + matriz[1]*pos.matriz[4]  + matriz[2]*pos.matriz[8]  + matriz[3]*pos.matriz[12];
	ret.matriz[1]=matriz[0]*pos.matriz[1]  + matriz[1]*pos.matriz[5]  + matriz[2]*pos.matriz[9]  + matriz[3]*pos.matriz[13];
	ret.matriz[2]=matriz[0]*pos.matriz[2]  + matriz[1]*pos.matriz[6]  + matriz[2]*pos.matriz[10]  + matriz[3]*pos.matriz[14];
	ret.matriz[3]=matriz[0]*pos.matriz[3]  + matriz[1]*pos.matriz[7]  + matriz[2]*pos.matriz[11]  + matriz[3]*pos.matriz[15];
	ret.matriz[4]=matriz[4]*pos.matriz[0]  + matriz[5]*pos.matriz[4]  + matriz[6]*pos.matriz[8]  + matriz[7]*pos.matriz[12];
	ret.matriz[5]=matriz[4]*pos.matriz[1]  + matriz[5]*pos.matriz[5]  + matriz[6]*pos.matriz[9]  + matriz[7]*pos.matriz[13];
	ret.matriz[6]=matriz[4]*pos.matriz[2]  + matriz[5]*pos.matriz[6]  + matriz[6]*pos.matriz[10]  + matriz[7]*pos.matriz[14];
	ret.matriz[7]=matriz[4]*pos.matriz[3]  + matriz[5]*pos.matriz[7]  + matriz[6]*pos.matriz[11]  + matriz[7]*pos.matriz[15];
	ret.matriz[8]=matriz[8]*pos.matriz[0]  + matriz[9]*pos.matriz[4]  + matriz[10]*pos.matriz[8] + matriz[11]*pos.matriz[12];
	ret.matriz[9]=matriz[8]*pos.matriz[1]  + matriz[9]*pos.matriz[5]  + matriz[10]*pos.matriz[9] + matriz[11]*pos.matriz[13];
	ret.matriz[10]=matriz[8]*pos.matriz[2]  + matriz[9]*pos.matriz[6]  + matriz[10]*pos.matriz[10] + matriz[11]*pos.matriz[14];
	ret.matriz[11]=matriz[8]*pos.matriz[3]  + matriz[9]*pos.matriz[7]  + matriz[10]*pos.matriz[11] + matriz[11]*pos.matriz[15];
	ret.matriz[12]=matriz[12]*pos.matriz[0] + matriz[13]*pos.matriz[4] + matriz[14]*pos.matriz[8] + matriz[15]*pos.matriz[12];
	ret.matriz[13]=matriz[12]*pos.matriz[1] + matriz[13]*pos.matriz[5] + matriz[14]*pos.matriz[9] + matriz[15]*pos.matriz[13];
	ret.matriz[14]=matriz[12]*pos.matriz[2] + matriz[13]*pos.matriz[6] + matriz[14]*pos.matriz[10] + matriz[15]*pos.matriz[14];
	ret.matriz[15]=matriz[12]*pos.matriz[3] + matriz[13]*pos.matriz[7] + matriz[14]*pos.matriz[11] + matriz[15]*pos.matriz[15];
	return ret;
}

TAfin TAfin :: trans()
{
	TAfin ret;
	for (int i=0; i<16; i++)
		ret.matriz[i]=matriz[i];

	std::swap(ret.matriz[1],  ret.matriz[4]);
    std::swap(ret.matriz[2],  ret.matriz[8]);
    std::swap(ret.matriz[3],  ret.matriz[12]);
    std::swap(ret.matriz[6],  ret.matriz[9]);
    std::swap(ret.matriz[7],  ret.matriz[13]);
    std::swap(ret.matriz[11], ret.matriz[14]);

	return ret;
}