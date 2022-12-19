#pragma once
#include "stdio.h"
#include "polygon.h"

#include "figure_basa.h"


class prism : public Figure_base
{

	void upd_shadow() override
	{
		point* ref = light;
		double y = 600;

		double t = (y - v[0]->y) / (ref->y - v[0]->y);
		double x = (ref->x - v[0]->x) * t + v[0]->x;
		double z = (ref->z - v[0]->z) * t + v[0]->z;

		point* A = new point(x, y, z);

		t = (y - v[1]->y) / (ref->y - v[1]->y);
		x = (ref->x - v[1]->x) * t + v[1]->x;
		z = (ref->z - v[1]->z) * t + v[1]->z;
		point* B = new point(x, y, z);

		t = (y - v[2]->y) / (ref->y - v[2]->y);
		x = (ref->x - v[2]->x) * t + v[2]->x;
		z = (ref->z - v[2]->z) * t + v[2]->z;
		point* C = new point(x, y, z);

		t = (y - v[3]->y) / (ref->y - v[3]->y);
		x = (ref->x - v[3]->x) * t + v[3]->x;
		z = (ref->z - v[3]->z) * t + v[3]->z;
		point* D = new point(x, y, z);

		t = (y - v[4]->y) / (ref->y - v[4]->y);
		x = (ref->x - v[4]->x) * t + v[4]->x;
		z = (ref->z - v[4]->z) * t + v[4]->z;
		point* E = new point(x, y, z);

		t = (y - v[5]->y) / (ref->y - v[5]->y);
		x = (ref->x - v[5]->x) * t + v[5]->x;
		z = (ref->z - v[5]->z) * t + v[5]->z;
		point* F = new point(x, y, z);


		A->project_rotate();
		B->project_rotate();
		C->project_rotate();
		D->project_rotate();
		E->project_rotate();
		F->project_rotate();
	
		S[0]->reset(A, B, C);
		S[1]->reset(D, E, F);
		S[2]->reset(A, B, E, D);
		S[3]->reset(C, A, D, F);
		S[4]->reset(B, C, F, E);


	}
public:

	prism()
	{
		v_n = 6;
		s_n = 5;
		side_flags = new int* [s_n];
		for (int i = 0; i < s_n; i++)
			side_flags[i] = new int[4];


		point* A = new point(0, 200, 100);
		point* B = new point(100, 200, 200);
		point* C = new point(200, 200, 100);
		point* D = new point(0, 100, 100);
		point* E = new point(100, 100, 200); 
		point* F = new point(200, 100, 100);

		v = new point * [v_n];
		T = new polygon * [s_n];
		S = new polygon * [s_n];
		v[0] = A;
		v[1] = B;
		v[2] = C;
		v[3] = D;
		v[4] = E;
		v[5] = F;


		polygon* s1 = new polygon(A, B, C);
		polygon* s2 = new polygon(D, E, F);
		polygon* s3 = new polygon(A, B, E, D);
		polygon* s4 = new polygon(C, A, D, F);
		polygon* s5 = new polygon(B, C, F, E);
	
		T[0] = s1;
		T[1] = s2;
		T[2] = s3;
		T[3] = s4;
		T[4] = s5;

		mid = new point;
		cam = new point(0, -1000, 500);
		light = new point(500, -500, 0);


		S[0] = new polygon(3);
		S[1] = new polygon(3);
		S[2] = new polygon(4);
		S[3] = new polygon(4);
		S[4] = new polygon(4);

		for (int i = 0; i < s_n; i++)
			side_flags[COLORED_BY][i] = 0;

		side_flags[BRIGHT][0] = 14; // желтый
		side_flags[BRIGHT][1] = 9; // голубой
		side_flags[BRIGHT][2] = 10; // зеленый
		side_flags[BRIGHT][3] = 12; // красный
		side_flags[BRIGHT][4] = 11;  // синий

		side_flags[DARK][0] = 6;  // желтый
		side_flags[DARK][1] = 1;  // голубой
		side_flags[DARK][2] = 2;  // зеленый
		side_flags[DARK][3] = 4;  // красный
		side_flags[DARK][4] = 3;  // синий

		for (int i = 0; i < s_n; i++)
			side_flags[VISIBLE][i] = 1;
	}

};