#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "stdio.h"
#include "math.h"
#include "../libwinbgi/src/graphics.h"

#define X 0
#define Y 1
#define Z 2
#define W 3

class Point
{
	double cor[4];

	double* multiply(double M[4][4]) {
		double m[4] = { cor[X], cor[Y], cor[Z], cor[W] };
		double res[4] = { 0, 0, 0, 0 };

		res[X] = m[0] * M[0][0] + m[1] * M[1][0] + m[2] * M[2][0] + m[3] * M[3][0];
		res[Y] = m[0] * M[0][1] + m[1] * M[1][1] + m[2] * M[2][1] + m[3] * M[3][1];
		res[Z] = m[0] * M[0][2] + m[1] * M[1][2] + m[2] * M[2][2] + m[3] * M[3][2];
		res[W] = m[0] * M[0][3] + m[1] * M[1][3] + m[2] * M[2][3] + m[3] * M[3][3];

		cor[X] = res[X];
		cor[Y] = res[Y];
		cor[Z] = res[Z];
		cor[W] = res[W];
		return res;
	}

public:
	Point() {	}

	double x, y, z;
	Point(double _x, double _y, double _z)
	{
		cor[X] = _x;
		cor[Y] = _y;
		cor[Z] = _z;
		cor[W] = 1;
		x = _x;
		y = _y;
		z = _z;
	}

	void setx(double _x)
	{
		cor[X] = _x; x = _x;
	}

	void sety(double _y)
	{
		cor[Y] = _y; y = _y;
	}


	void setz(double _z)
	{
		cor[Z] = _z; z = _z;
	}

	double operator[](int i) {
		return cor[i];
	}

	void set(double _x, double _y, double _z, double _w) {
		cor[X] = _x;	cor[Y] = _y;	cor[Z] = _z;	cor[W] = _w;
		x = _x;	y = _y;	z = _z;	
	}

	void move_point(double x, double y, double z) {
		double matrix[4][4] = {
			1,  0,  0,  0,	0,  1,  0,  0,	0,  0,  1,  0,	x, y, z, 1 };

		multiply(matrix);
	}

	void scale(double x, double y, double z) {
		double matrix[4][4] = {
			x, 0, 0, 0,	0, y, 0, 0,	0, 0, z, 0,	0, 0, 0, 1 };
		multiply(matrix);
	}

	void rotateX(double phi) {
		phi = phi * 3.1415 / 180;
		double matrix[4][4] = {
			1, 0, 0, 0,	0, cos(phi), -sin(phi), 0,	0, sin(phi), cos(phi),	0, 0, 0, 0, 1 };
		multiply(matrix);
	}

	void rotateY(double phi) {
		phi = phi * 3.1415 / 180;
		double matrix[4][4] = {
			cos(phi), 0, -sin(phi), 0,	0, 1, 0, 0,	sin(phi), 0, cos(phi), 0, 0, 0, 0, 1 };
		multiply(matrix);
	}

	void rotateZ(double phi) {
		phi = phi * 3.1415 / 180;
		double matrix[4][4] = {
			cos(phi), -sin(phi), 0, 0,	sin(phi), cos(phi), 0, 0,	0, 0, 1, 0,	0, 0, 0, 1 };
		multiply(matrix);
	}

	void project() {
		rotateX(30);		
	}

	void unproject() {
		rotateX(-30);	
	}

	void print()
	{
		printf("%f %f %f\n", cor[X], cor[Y], cor[Z]);
	}

};


class point
{
	double* multiply(double _m[4][4])
	{
		double x_ = x;
		double y_ = y;
		double z_ = z;
		double w_ = w;
		double cpy[4] = { x_, y_, z_, w_ };
		double res[4] = { 0,0,0,0 };

		res[X] = cpy[0] * _m[0][0] + cpy[1] * _m[1][0] + cpy[2] * _m[2][0] + cpy[3] * _m[3][0];
		res[Y] = cpy[0] * _m[0][1] + cpy[1] * _m[1][1] + cpy[2] * _m[2][1] + cpy[3] * _m[3][1];
		res[Z] = cpy[0] * _m[0][2] + cpy[1] * _m[1][2] + cpy[2] * _m[2][2] + cpy[3] * _m[3][2];
		res[W] = cpy[0] * _m[0][3] + cpy[1] * _m[1][3] + cpy[2] * _m[2][3] + cpy[3] * _m[3][3];

		x = res[X];
		y = res[Y];
		z = res[Z];
		w = res[W];
		return res;
	}

	void rotateX(double _phi) {
		_phi = _phi * 3.1415 / 180;

		double matrix[4][4] = {
			1, 0, 0, 0,
			0, cos(_phi), -sin(_phi), 0,
			0, sin(_phi), cos(_phi),
			0, 0, 0, 0, 1 };
		multiply(matrix);
	}

	void rotateY(double _phi) {
		_phi = _phi * 3.1415 / 180;

		double matrix[4][4] = {
			cos(_phi), 0, -sin(_phi), 0,
			0, 1, 0, 0,
			sin(_phi), 0, cos(_phi), 0,
			0, 0, 0, 1 };
		multiply(matrix);
	}

	void rotateZ(double _phi) {
		_phi = _phi * 3.1415 / 180;

		double matrix[4][4] = {
			cos(_phi), -sin(_phi), 0, 0,
			sin(_phi), cos(_phi), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1 };
		multiply(matrix);
	}

public:

	double x;
	double y;
	double z;
	double w;



	point()
	{

	}
	point(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
	{
		w = 1;
	}

	void print()
	{
		printf("%f %f %f %f\n", x, y, z, w);
	}

	void move(double _x, double _y, double _z)
	{
		double matrix[4][4] = {
			1,  0,  0,  0,
			0,  1,  0,  0,
			0,  0,  1,  0,
			_x, _y, _z, 1 };

		multiply(matrix);
	}

	void scale(double _x, double _y, double _z) {
		double matrix[4][4] = {
			_x, 0, 0, 0,
			0, _y, 0, 0,
			0, 0, _z, 0,
			0, 0, 0, 1 };

		multiply(matrix);
	}

	void rotate(double _phi, int _axis) {
		if (_axis == X)
			rotateX(_phi);
		if (_axis == Y)
			rotateY(_phi);
		if (_axis == Z)
			rotateZ(_phi);
	}
	
	double cx() {
		return x;
	}
	void cx(double _x) {
		x = _x;
	}

	double cy() {
		return y;
	}
	void cy(double _y) {
		y = _y;
	}

	double cz() {
		return z;
	}
	void cz(double _z) {
		z = _z;
	}

};