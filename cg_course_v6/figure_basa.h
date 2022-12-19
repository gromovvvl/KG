#pragma once
#include "stdio.h"
#include "polygon.h"

#define BRIGHT 0
#define DARK 1
#define COLORED_BY 2
#define VISIBLE 3

class Figure_base
{

	void rotate_each(double _phi, int axis)
	{
		for (int i = 0; i < v_n; i++)
			v[i]->rotate(_phi, axis);
	}

	void scale_each(double _x, double _y, double _z)
	{
		for (int i = 0; i < v_n; i++)
			v[i]->scale(_x, _y, _z);
	}

	virtual void upd_shadow() {};

	void project()
	{
		rotate_each(30, X);
	}

	void unproject()
	{
		rotate_each(-30, X);
	}
	void project_each()
	{
		for (int i = 0; i < v_n; i++)
			v[i]->project_rotate();
	}

	void unproject_each()
	{
		for (int i = 0; i < v_n; i++)
			v[i]->unproject_rotate();
	}

	void upd_mid()
	{
		mid->x = 0;
		for (int i = 0; i < v_n; i++)
			mid->x += v[i]->x;

		mid->x /= (float)v_n;

		mid->y = 0;
		for (int i = 0; i < v_n; i++)
			mid->y += v[i]->y;

		mid->y /= (float)v_n;

		mid->z = 0;
		for (int i = 0; i < v_n; i++)
			mid->z += v[i]->z;

		mid->z /= (float)v_n;
		mid->w = 1;
	}
	
public:
	int s_n;
	int v_n;
	polygon** T;
	polygon** S;
	point** v;
	point* mid;
	point* cam;
	point* light;
	int** side_flags;
	
	Figure_base()
	{
		s_n = 0;
		v_n = 0;
		T = nullptr;
		S = nullptr;
		v = nullptr;
		mid = nullptr;
		cam = nullptr;
		light = nullptr;
		side_flags = nullptr;
	}


	void upd_sides()
	{
		for (int i = 0; i < s_n; i++)
		{
			T[i]->calc_coefs(0);
		}
	}

	void check_signs()
	{
		for (int i = 0; i < s_n; i++)
		{
			if (T[i]->sign(mid) == 1)
				T[i]->swap_sign();
		}
	}

	void check_colors()
	{
		point* ref = new point(light->x - mid->x, light->y - mid->y, light->z - mid->z);
		for (int i = 0; i < s_n; i++)
		{
			if (T[i]->isSeen(ref) == 1)
				side_flags[COLORED_BY][i] = BRIGHT;
			else
				side_flags[COLORED_BY][i] = DARK;
		}
	}

	void check_visibility()
	{
		point* ref = cam;
		for (int i = 0; i < s_n; i++)
		{
			if (T[i]->isSeen(ref) == 1)
				side_flags[VISIBLE][i] = 1;
			else
				side_flags[VISIBLE][i] = 0;
		}
	}

	void draw_fig()
	{
		printf("=== %d ===\n", s_n);
		for (int i = 0; i < s_n; i++)
		{
			if (side_flags[VISIBLE][i] == 1)
			{
				int l = side_flags[COLORED_BY][i];
				printf("color %d) %d\n", i, side_flags[l][i]);
				T[i]->color(side_flags[l][i]);
			}
		}
	}

	void draw_shadow()
	{
		for (int i = 0; i < s_n; i++)
		{
			S[i]->color(8);
		}
	}

	void move(double _x, double _y, double _z)
	{
		for (int i = 0; i < v_n; i++)
			v[i]->move(_x, _y, _z);
	}

	void scale(double _x, double _y, double _z)
	{
		upd_mid();
		move(-mid->x, -mid->y, -mid->z);
		scale_each(_x, _y, _z);
		move(mid->x, mid->y, mid->z);
	}

	void rotate(double _phi, int axis)
	{
		upd_mid();
		move(-mid->x, -mid->y, -mid->z);
		rotate_each(_phi, axis);
		move(mid->x, mid->y, mid->z);
	}

	void paint()
	{
		upd_mid();
		upd_sides();

		upd_shadow();
		draw_shadow();

		check_signs();
		check_colors();
		check_visibility();

		project_each();
		draw_fig();
		unproject_each();
	}

};
