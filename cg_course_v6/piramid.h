#pragma once
#include "stdio.h"
#include "polygon.h"

#include "figure_basa.h"


class piramid: public Figure_base
{

	void upd_shadow() override
	{
		point* ref = light;
		double y = 600;

		double k = (y - v[0]->y) / (ref->y - v[0]->y);
		double x = (ref->x - v[0]->x) * k + v[0]->x;
		double z = (ref->z - v[0]->z) * k + v[0]->z;

		point* A = new point(x, y, z);

		k = (y - v[1]->y) / (ref->y - v[1]->y);
		x = (ref->x - v[1]->x) * k + v[1]->x;
		z = (ref->z - v[1]->z) * k + v[1]->z;
		point* B = new point(x, y, z);

		k = (y - v[2]->y) / (ref->y - v[2]->y);
		x = (ref->x - v[2]->x) * k + v[2]->x;
		z = (ref->z - v[2]->z) * k + v[2]->z;
		point* C = new point(x, y, z);

		k = (y - v[3]->y) / (ref->y - v[3]->y);
		x = (ref->x - v[3]->x) * k + v[3]->x;
		z = (ref->z - v[3]->z) * k + v[3]->z;
		point* D = new point(x, y, z);

		k = (y - v[4]->y) / (ref->y - v[4]->y);
		x = (ref->x - v[4]->x) * k + v[4]->x;
		z = (ref->z - v[4]->z) * k + v[4]->z;
		point* E = new point(x, y, z);

		A->project_rotate();
		B->project_rotate();
		C->project_rotate();
		D->project_rotate();
		E->project_rotate();
		/*A->rotate(30, X);
		B->rotate(30, X);
		C->rotate(30, X);
		D->rotate(30, X);
		E->rotate(30, X);*/

		S[0]->reset(A, B, C, D);
		S[1]->reset(A, B, E);
		S[2]->reset(D, A, E);
		S[3]->reset(B, C, E);
		S[4]->reset(C, D, A);

	}

public:

	piramid()
	{
		v_n = 5;
		s_n = 5;
		side_flags = new int*[s_n];
		for (int i = 0; i < s_n; i++)
			side_flags[i] = new int[4];
		

		point* A = new point(0, 100, 200); // A
		point* B = new point(200, 100, 200); // B
		point* C = new point(200, 100, 0); // C
		point* D = new point(0, 100, 0); // D
		point* E = new point(100, 0, 100); // E

		v = new point * [s_n];
		T = new polygon * [s_n];
		S = new polygon * [s_n];
		v[0] = A;
		v[1] = B;
		v[2] = C;
		v[3] = D;
		v[4] = E;

		polygon* s1 = new polygon(A, B, C, D); 
		polygon* s2 = new polygon(A, B, E);
		polygon* s3 = new polygon(D, A, E);
		polygon* s4 = new polygon(B, C, E);
		polygon* s5 = new polygon(C, D, E);
		S[0] = new polygon(4);
		S[1] = new polygon(3);
		S[2] = new polygon(3);
		S[3] = new polygon(3);
		S[4] = new polygon(3);
		T[0] = s1;
		T[1] = s2;
		T[2] = s3;
		T[3] = s4;
		T[4] = s5;

		mid = new point;
		cam = new point(0, -1000, 500);
		light = new point(500, -500, 0);
		
		for (int i = 0; i < s_n; i++)
			side_flags[COLORED_BY][i] = 0;


		side_flags[BRIGHT][0] = 14; // желтый
		side_flags[BRIGHT][1] = 11; // голубой
		side_flags[BRIGHT][2] = 10; // зеленый
		side_flags[BRIGHT][3] = 12; // красный
		side_flags[BRIGHT][4] = 9; //  синий

		side_flags[DARK][0] = 6;
		side_flags[DARK][1] = 3;
		side_flags[DARK][2] = 2;
		side_flags[DARK][3] = 4;
		side_flags[DARK][4] = 1;

		for (int i = 0; i < s_n; i++)
			side_flags[VISIBLE][i] = 1;
	}

};