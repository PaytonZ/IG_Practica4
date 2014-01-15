#pragma once
class TAfin
{
	/* matriz
		m0 ,m4, m8, m12
		m1 ,m5, m9, m13
		m2 ,m6, m10, m14
		m3 ,m7, m11, m15
	*/
public:
	TAfin()
	{
		matriz[0] = matriz[5] = matriz[10] = matriz[15] = 1;
		matriz[1] = matriz[2] = matriz[3] = matriz[4] = matriz[6] = 0;
		matriz[7] = matriz[8] = matriz[9] = matriz[11] = matriz[12] = 0;
		matriz[13] = matriz[14] = 0;
	}
	~TAfin(void){}

	TAfin translated(float x, float y, float z);
	TAfin scaled(float Sx, float Sy, float Sz);
	TAfin rotateX(float angulo);
	TAfin rotateY(float angulo);
	TAfin rotateZ(float angulo);
	TAfin postMultiplica(TAfin);
	TAfin trans();


	float matriz[16];
};

