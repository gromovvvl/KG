#pragma once
#include "stdio.h"
#include "polygon.h"
#include "figure_basa.h"


class cube : public Figure_base
{

	void upd_shadow() override
	{
		point* ref = light;
		double y = 600;

		double t = (y - v[0]->y) / (ref->y - v[0]->y);
		double x = (ref->x - v[0]->x) * t + v[0]->x;
		double z = (ref->z - v[0]->z) * t + v[0]->z;

		point* A1 = new point(x, y, z);

		t = (y - v[1]->y) / (ref->y - v[1]->y);
		x = (ref->x - v[1]->x) * t + v[1]->x;
		z = (ref->z - v[1]->z) * t + v[1]->z;
		point* B1 = new point(x, y, z);

		t = (y - v[2]->y) / (ref->y - v[2]->y);
		x = (ref->x - v[2]->x) * t + v[2]->x;
		z = (ref->z - v[2]->z) * t + v[2]->z;
		point* C1 = new point(x, y, z);

		t = (y - v[3]->y) / (ref->y - v[3]->y);
		x = (ref->x - v[3]->x) * t + v[3]->x;
		z = (ref->z - v[3]->z) * t + v[3]->z;
		point* D1 = new point(x, y, z);

		t = (y - v[4]->y) / (ref->y - v[4]->y);
		x = (ref->x - v[4]->x) * t + v[4]->x;
		z = (ref->z - v[4]->z) * t + v[4]->z;
		point* A2 = new point(x, y, z);

		t = (y - v[5]->y) / (ref->y - v[5]->y);
		x = (ref->x - v[5]->x) * t + v[5]->x;
		z = (ref->z - v[5]->z) * t + v[5]->z;
		point* B2 = new point(x, y, z);

		t = (y - v[6]->y) / (ref->y - v[6]->y);
		x = (ref->x - v[6]->x) * t + v[6]->x;
		z = (ref->z - v[6]->z) * t + v[6]->z;
		point* C2 = new point(x, y, z);

		t = (y - v[7]->y) / (ref->y - v[7]->y);
		x = (ref->x - v[7]->x) * t + v[7]->x;
		z = (ref->z - v[7]->z) * t + v[7]->z;
		point* D2 = new point(x, y, z);


		A1->rotate(30, X);
		B1->rotate(30, X);
		C1->rotate(30, X);
		D1->rotate(30, X);
		A2->rotate(30, X);
		B2->rotate(30, X);
		C2->rotate(30, X);
		D2->rotate(30, X);

		S[0]->reset(A1, B1, C1, D1);
		S[1]->reset(A1, B1, B2, A2);
		S[2]->reset(B1, C1, C2, B2);
		S[3]->reset(C1, D1, D2, C2);
		S[4]->reset(D1, A1, A2, D2);
		S[5]->reset(A2, B2, C2, D2);

	}


public:

	cube()
	{
		v_n = 8;
		s_n = 6;
		clr = new int* [s_n];
		for (int i = 0; i < s_n; i++)
		{
			clr[i] = new int[4];
		}
		v = new point * [s_n];
		T = new polygon * [s_n];
		S = new polygon * [s_n];
		point* A = new point(0, 100, 100); // A
		point* B = new point(100, 100, 100); // B
		point* C = new point(100, 100, 0); // C
		point* D = new point(0, 100, 0); // D
		point* E = new point(0, 0, 100); // E
		point* F = new point(100, 0, 100); // F
		point* G = new point(100, 0, 0); // G
		point* H = new point(0, 0, 0); // H
		v[0] = A;
		v[1] = B;
		v[2] = C;
		v[3] = D;
		v[4] = E;
		v[5] = F;
		v[6] = G;
		v[7] = H;
		polygon* s1 = new polygon(A, B, C, D);
		polygon* s2 = new polygon(E, F, G, H);
		polygon* s3 = new polygon(A, B, F, E);
		polygon* s4 = new polygon(B, C, G, F);
		polygon* s5 = new polygon(C, D, H, G);
		polygon* s6 = new polygon(D, A, E, H);

		T[0] = s1;
		T[1] = s2;
		T[2] = s3;
		T[3] = s4;
		T[4] = s5;
		T[5] = s6;

		for (int i = 0; i < s_n; i++)
			S[i] = new polygon(4);


		mid = new point;
		cam = new point(0, -500, 1000);
		light = new point(500, -500, 0);

		for (int i = 0; i < s_n; i++)
			clr[FLAG][i] = 0;

		clr[BR][0] = 14; // желтый
		clr[BR][1] = 9; // голубой
		clr[BR][2] = 10; // зеленый
		clr[BR][3] = 12; // красный
		clr[BR][4] = 11;  // синий
		clr[BR][5] = 13; // белый

		clr[DR][0] = 6;  // желтый
		clr[DR][1] = 1;  // голубой
		clr[DR][2] = 2;  // зеленый
		clr[DR][3] = 4;  // красный
		clr[DR][4] = 3;  // синий
		clr[DR][5] = 5;  // белый

		for (int i = 0; i < s_n; i++)
			clr[VS][i] = 1;
	}



};