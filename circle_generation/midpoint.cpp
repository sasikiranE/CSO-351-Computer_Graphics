#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

float H, K, R;

void plot_eight_points(float x, float y) {
    glVertex2i(x + H, y + K);  
    glVertex2i(x + H,-y + K);  
    glVertex2i(-x + H, -y + K);  
    glVertex2i(-x + H, y + K);  
    glVertex2i(y + H, x + K);  
    glVertex2i(y + H, -x + K);  
    glVertex2i(-y + H, -x + K);  
    glVertex2i(-y + H, x + K);  
}


void display(void) {
    float x, y, d;
    x = 0, y = R, d = (5.0 / 4) - R;
    
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    while (x <= y) {
        plot_eight_points(x, y);
        if (d >= 0) {
            d += 2 * (x - y) + 5;
            y -= 1;
            x += 1;
        }
        else {
            d += 2 * x + 3;
            x += 1;
        }
    }

	glEnd();
	glFlush();
}

void myInit (void) {
	// Reset background color with black (since all three argument is 0.0)
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// Set picture color to green (in RGB model)
	// as only argument corresponding to G (Green) is 1.0 and rest are 0.0
	glColor3f(0.0, 0.0, 0.0);

	// Set width of point to one unit
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set window size in X- and Y- direction
	gluOrtho2D(-780, 780, -420, 420);
}

int main(int argc, char **argv) {

    cout << "Enter Circle Center (h, k) : ";
    cin >> H >> K;
    cout << "Enter the radius : ";
    cin >> R;

	glutInit(&argc, argv);

	// Display mode which is of RGB (Red Green Blue) type
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Declares window size
	glutInitWindowSize(960, 540);

	// Declares window position which is (0, 0)
	// means lower left corner will indicate position (0, 0)
	glutInitWindowPosition(0, 0);

	// Name to window
	glutCreateWindow("Circle using mid point algo");

	// Call to myInit()
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}