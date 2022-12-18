#include "../libwinbgi/src/graphics.h"
#include <stdio.h>
#include "piramid.h"
#include "cube.h"
#include "polygon.h"


int main()
{
	piramid* Piramid = new piramid();
	Piramid->move(350, 400, 0);
	Piramid->scale(0.5, 0.5, 0.5);

	cube* Cube = new cube();
	Cube->move(250, 400, -40);
	Cube->scale(0.5, 0.5, 0.5);

	initwindow(1000, 700);
	Cube->paint();
	Piramid->paint();
	
	char c;

	while (true)
	{
		c = getch();
		switch (c)
		{
		case 'u':
			Piramid->move(0, -40, 0);
			break;
		case 'j':
			Piramid->move(0, 40, 0);
			break;
		case 'h':
			Piramid->move(-40, 0, 0);
			break;
		case 'k':
			Piramid->move(40, 0, 0);
			break;
		case 'n':
			Piramid->move(0, 0, 40);
			break;
		case 'm':
			Piramid->move(0, 0, -40);
			break;

		case 'y':
			Piramid->scale(0.5, 0.5, 0.5);
			break;
		case 'i':
			Piramid->scale(2, 2, 2);
			break;
		case '7':
			Piramid->rotate(30, 0);
			break;
		case '8':
			Piramid->rotate(-30, 0);
			break;
		case '9':
			Piramid->rotate(30, 1);
			break;
		case '0':
			Piramid->rotate(-30, 1);
			break;
		case '-':
			Piramid->rotate(30, 2);
			break;
		case '=':
			Piramid->rotate(-30, 2);
			break;

		case '~':
			closegraph();
			return 0;

		case 'w':
			Cube->move(0, -40, 0);
			break;
		case 's':
			Cube->move(0, 40, 0);
			break;
		case 'a':
			Cube->move(-40, 0, 0);
			break;
		case 'd':
			Cube->move(40, 0, 0);
			break;
		case 'z':
			Cube->move(0, 0, 40);
			break;
		case 'x':
			Cube->move(0, 0, -40);
			break;

		case 'q':
			Cube->scale(0.5, 0.5, 0.5);
			break;
		case 'e':
			Cube->scale(2, 2, 2);
			break;
		case '1':
			Cube->rotate(30, 0);
			break;
		case '2':
			Cube->rotate(-30, 0);
			break;
		case '3':
			Cube->rotate(30, 1);
			break;
		case '4':
			Cube->rotate(-30, 1);
			break;
		case '5':
			Cube->rotate(30, 2);
			break;
		case '6':
			Cube->rotate(-30, 2);
			break;
		default:
			break;
		}
		
		
		clearviewport();
		Cube->paint();
		Piramid->paint();

	}

	getch();
	closegraph();
	return 0;
}


