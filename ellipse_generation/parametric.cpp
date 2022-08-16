#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

float H, K, A, B;

void plot_four_points(float x, float y) {
    glVertex2i(H + x, K + y);  
    glVertex2i(H - x, K + y);  
    glVertex2i(H - x, K - y);  
    glVertex2i(H + x, K - y);  
}

const float THETA_START = 0;
const float THETA_END = M_PI / 2;

void display(void) {

    float theta = THETA_START;
    float d_theta = (1.0 / sqrt((A * A) + (B * B)));
    float x, y;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    while (theta <= THETA_END) {
        x = (A * cos(theta));
        y = (B * sin(theta));
        plot_four_points(x, y);
        theta += d_theta;
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
    cout << "Enter length of major (a) and minor (b) axes : ";
    cin >> A >> B;

	glutInit(&argc, argv);

	// Display mode which is of RGB (Red Green Blue) type
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Declares window size
	glutInitWindowSize(960, 540);

	// Declares window position which is (0, 0)
	// means lower left corner will indicate position (0, 0)
	glutInitWindowPosition(0, 0);

	// Name to window
	glutCreateWindow("Ellipse using parametric equation");

	// Call to myInit()
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}