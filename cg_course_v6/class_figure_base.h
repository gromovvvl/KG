#include "stdio.h"
#include "point.h"
#include "plane.h"
enum flags
{
	BRIGHT, DARK, VISIBLE, IS_LIGHT
};


class figure_base
{
protected:

	Point** points;
	int point_num;

	Plane** sides; 
	int side_num;

	Point* middle;
	
	int shadow_color;

	virtual void painters_alg() {};
	virtual void upd_and_draw_shadow() {};

	void project_each()
	{
		for (int i = 0; i < point_num; i++)
			points[i]->rotateX(30);
	}

	void unproject_each()
	{
		for (int i = 0; i < point_num; i++)
			points[i]->rotateX(-30);
	}

	void newMiddle()
	{
		double s = 0;
		for (int i = 0; i < point_num; i++)
			s += (*points[i])[X];

		s /= (double)point_num;
		middle->setx(s);
		
		s = 0;
		for (int i = 0; i < point_num; i++)
			s += (*points[i])[Y];
		
		s /= (double)point_num;
		middle->sety(s);
		
		s = 0;
		for (int i = 0; i < point_num; i++)
			s += (*points[i])[Z];

		s /= (double)point_num;
		middle->setz(s);
	}


	void getSloupeValue(Point* p, double* x, double* z, int table_y)
	{
		Point* L = new Point(0, 0, 0);
		double t = (table_y - (*p)[Y]) / ((*L)[Y] - (*p)[Y]);
		*x = ((*L)[X] - (*p)[X]) * t + (*p)[X];
		*z = ((*L)[Z] - (*p)[Z]) * t + (*p)[Z];
	}

	void move(double _x, double _y, double _z)
	{
		for (int i = 0; i < point_num; i++)
			points[i]->move_point(_x, _y, _z);
	}



public:

	figure_base()
	{
		middle = new Point(0, 0, 0);
		point_num = 0;
		shadow_color = 0;
		side_num = 0;
		points = nullptr;
	}


	void up()
	{
		for (int i = 0; i < point_num; i++)
			points[i]->move_point(0, -60, 0);
	}

	void down()
	{
		for (int i = 0; i < point_num; i++)
			points[i]->move_point(0, 60, 0);
	}

	void right()
	{
		for (int i = 0; i < point_num; i++)
			points[i]->move_point(60, 0, 0);
	}

	void left()
	{
		for (int i = 0; i < point_num; i++)
			points[i]->move_point(-60, 0, 0);
	}


	void away()
	{
		for (int i = 0; i < point_num; i++)
			points[i]->move_point(0, 0, -60);
	}

	void closer()
	{
		for (int i = 0; i < point_num; i++)
			points[i]->move_point(0, 0, 60);
	}


	void scale(double q)
	{
		newMiddle();
		move(-(*middle)[X], -(*middle)[Y], -(*middle)[Z]);

		for (int i = 0; i < point_num; i++)
			points[i]->scale(q,q,q);

		move((*middle)[X], (*middle)[Y], (*middle)[Z]);
	}


	void rotate(double _phi, int axis)
	{
		newMiddle();
		move(-(*middle)[X], -(*middle)[Y], -(*middle)[Z]);

		switch (axis)
		{
		case X:
			for (int i = 0; i < point_num; i++)
				points[i]->rotateX(_phi);
			break;
		case Y:
			for (int i = 0; i < point_num; i++)
				points[i]->rotateY(_phi);

			break;
		case Z:
			for (int i = 0; i < point_num; i++)
				points[i]->rotateZ(_phi);

			break;
		}
		move((*middle)[X], (*middle)[Y], (*middle)[Z]);
	}






};