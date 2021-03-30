//Rachel Culbertson
//010854980
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
class Color {
	private:
		float R, G, B;
	public:
		float getR() { return R; }
		float getG() { return G; }
		float getB() { return B; }
		void setR(float R1) { R = R1; }
		void setG(float G1) { G = G1; } 
		void setB(float B1) { B = B1; }
};
class Point {
	private:
		float x, y, z;
	public: 
		float getX() { return x; }
		float getY() { return y; }
		float getZ() { return z; }
		void setX(float x1) { x = x1; }
		void setY(float y1) { y = y1; }
		void setZ(float z1) { z = z1; }
};
class Normal {
	private:
 		float Nx, Ny, Nz;
	public:
		float getNx() { return Nx; }
		float getNy() { return Ny; }
		float getNz() { return Nz; }
		void setNx(float Nx1) { Nx = Nx1; }
		void setNy(float Ny1) { Ny = Ny1; }
		void setNz(float Nz1) { Nz = Nz1; }

};
class Rectangle {
	public:
		Color colors[4];
		Point points[4];
		Normal normals[4];
};
//Geometric operations
void translatePoint(Point &point, float Tx, float Ty, float Tz) {
	point.setX(point.getX() + Tx);
	point.setY(point.getY() + Ty);
	point.setZ(point.getZ() + Tz);
}
void scalePoint(Point &point, float Sx, float Sy, float Sz) {
	point.setX(point.getX() * Sx);
	point.setY(point.getY() * Sy);
	point.setZ(point.getZ() * Sz);
}
void rotateX(Point &point, float theta) {
	point.setY(point.getY()*cos(theta)-point.getZ()*sin(theta));
	point.setZ(point.getY()*sin(theta)+point.getZ()*cos(theta));	
}
void rotateY(Point &point, float theta) {
	point.setX(point.getX()*cos(theta)+point.getZ()*sin(theta));
	point.setY(-point.getX()*sin(theta)+point.getZ()*cos(theta));	
}
void rotateZ(Point &point, float theta) {
	point.setX(point.getX()*cos(theta)-point.getY()*sin(theta));
	point.setY(point.getX()*sin(theta)+point.getY()*cos(theta));	
}
Point projectPoint(float x, float y, float z, float d) {
	float xp = x/(z/d);
	float yp = y/(z/d);
	float zp = d;
	Point projPoint;
	projPoint.setX(xp);
	projPoint.setY(yp);
	projPoint.setZ(zp);
	return projPoint;
	
}
//Interpolation operations
float linearInterRange(float A, float Amin, float Amax, float Bmin, float Bmax) {
	float B;
	float Alpha = (A-Amin)/(Amax-Amin);
	B = Alpha*Bmax+(1-Alpha)*Bmin;
	return B;
}
float bilinearInter(float A, float B, float C, float D, float Alpha, float Beta) {
	float V = D*Alpha*Beta+C*(1-Alpha)*Beta-B*Alpha*(1-Beta)+A*(1-Alpha)*(1-Beta);
	return V;	
}
Point linearInterCoor(float x1, float y1, float z1, float x2, float y2, 
float z2, float A) {
	Point point;
	float x = A*x2+(1-A)*x1;
	float y = A*y2+(1-A)*y1;
	float z = A*z2+(1-A)*z1;
	point.setX(x); 
	point.setY(y);
	point.setZ(z);	
	return point;
}

//Shading operations
void normalize(float &Ax, float &Ay, float &Az) {
	float length = sqrt(pow(Ax, 2) + pow(Ay,2) + pow(Az, 2));
	Ax = Ax/length;
	Ay = Ay/length;
	Az = Az/length;

}
//Uses normalize so needs to be declared after
Normal linearInterNorm(float Nx1, float Ny1, float Nz1,
float Nx2, float Ny2, float Nz2, float A) {
	Normal normal;
	float Nx = A*Nx2+(1-A)*Nx1;
	float Ny = A*Ny2+(1-A)*Ny1;
	float Nz = A*Nz2+(1-A)*Nz1;
	normalize(Nx, Ny, Nz);
	normal.setNx(Nx);
	normal.setNy(Ny);
	normal.setNz(Nz);
	return normal;
}
float dotProduct(float Ax, float Ay, float Az, float Bx, float By, float Bz) {
	float scalar = Ax*Bx + Ay*By + Az*Bz;
	return scalar;
}
Point crossProduct(float Ax, float Ay, float Az, float Bx, float By, float Bz) {
	float Cx = Ay*Bz - Az*By;
	float Cy = Az*Bx - Ax*Bz;
	float Cz = Ax*By - Ay*Bx;
	Point crossProduct;
	crossProduct.setX(Cx);
	crossProduct.setY(Cy);
	crossProduct.setZ(Cz);
	return crossProduct;
}
float diffuse(float Lx, float Ly, float Lz, float Nx, float Ny, float Nz) {
	float scalar = dotProduct(Lx, Ly, Lz, Nx, Ny, Nz);
	return scalar;
}
Point idealReflector(float Lx, float Ly, float Lz, float Nx, float Ny, float Nz) {
	float Rx = 2*(Lx*Nx)*Nx-Lx;
	float Ry = 2*(Ly*Ny)*Ny-Ly;
	float Rz = 2*(Lz*Nz)*Nz-Lz;
	Point idealReflector;
	idealReflector.setX(Rx);
	idealReflector.setY(Ry);
	idealReflector.setZ(Rz);
	return idealReflector;
}
float specular(float Vx, float Vy, float Vz, float Rx, float Ry, float Rz, float P) {
	float scalar = pow(abs(dotProduct(Vx, Vy, Vz, Rx, Ry, Rz)), P);
	return scalar;
}
Color phong(float Px, float Py, float Pz, float Lx, float Ly, float Lz, 
float Nx, float Ny, float Nz, float Mr, float Mg, float Mb, float Ka, float Kd, 
float Ks, float Kp) {
	Color color;
	//Calculate Ideal Reflector
	Point reflector = idealReflector(Lx, Ly, Lz, Nx, Ny, Nz);
	float Rz, Ry, Rx;
	Rz = reflector.getZ();
	Ry = reflector.getY();
	Rx = reflector.getX();
	//Calculate viewer vector
	float Vx = -Px;
	float Vy = -Py;
	float Vz = -Pz;
	//Normalize Vectors
	normalize(Lx, Ly, Lz);
	normalize(Nx, Ny, Nz);
	normalize(Rx, Ry, Rz);
	normalize(Vx, Vy, Vz);
	float phong = Kd*(diffuse(Lx, Ly, Lz, Nx, Ny, Nz)) + Ks * 
	(specular(Vx, Vy, Vz, Rx, Ry, Rz, Kp)) + Ka;
	float Cr = Mr*phong;
	float Cg = Mg*phong;
	float Cb = Mb*phong;
	color.setR(Cr);
	color.setG(Cg);
	color.setB(Cb);
	return color;
}

int main(int argc, char *argv[]) {
	ifstream din;
	din.open("input.txt");
	float r,g,b;
	float Nx[4], Ny[4], Nz[4];
      	float Px[4], Py[4], Pz[4];
	while (!din.eof()) {
		string word; 
		//Read color
		if ((din >> word) && (word == "color"))
		     din >> r >> g >> b;
	        // Read four points of rectangle
	        for (int i=0; i<4; i++)
	        {
		   if ((din >> word) && (word == "normal"))
		     din >> Nx[i] >> Ny[i] >> Nz[i];
		   if ((din >> word) && (word == "point"))
		     din >> Px[i] >> Py[i] >> Pz[i];
	        }      
		// Check for end of file
		if (din.eof())
			continue;

	}
	din.close();

	float fraction13 = (float)1/3;
	float fraction23 = (float)2/3;
	//This code makes sense if you could see the picture I drew I'm sorry
	//Calcuate 12 points needed to get 9 rectangles
	Point p1 = linearInterCoor(Px[0], Py[0], Pz[0], Px[1], Py[1],
	Pz[1], fraction13);
	Point p2 = linearInterCoor(Px[0], Py[0], Pz[0], Px[1], Py[1],
	Pz[1], fraction23);
	Point p3 = linearInterCoor(Px[3], Py[3], Pz[3], Px[2], Py[2],
	Pz[2], fraction13);
	Point p4 = linearInterCoor(Px[3], Py[3], Pz[3], Px[2], Py[2],
	Pz[2], fraction23);
	Point p5 = linearInterCoor(Px[0], Py[0], Pz[0], Px[3], Py[3],
	Pz[3], fraction13);
	Point p6 = linearInterCoor(Px[0], Py[0], Pz[0], Px[3], Py[3],
	Pz[3], fraction23);
	Point p7 = linearInterCoor(Px[1], Py[1], Pz[1], Px[2], Py[2],
	Pz[2], fraction13);
	Point p8 = linearInterCoor(Px[1], Py[1], Pz[1], Px[2], Py[2],
	Pz[2], fraction23);
	Point p9 = linearInterCoor(p1.getX(), p1.getY(), p1.getZ(), 
	p3.getX(), p3.getY(), p3.getZ(),  fraction13);
	Point p10 = linearInterCoor(p1.getX(), p1.getY(), p1.getZ(), 
	p3.getX(), p3.getY(), p3.getZ(),  fraction23);
	Point p11 = linearInterCoor(p2.getX(), p2.getY(), p2.getZ(), 
	p4.getX(), p4.getY(), p4.getZ(),  fraction13);
	Point p12 = linearInterCoor(p2.getX(), p2.getY(), p2.getZ(), 
	p4.getX(), p4.getY(), p4.getZ(),  fraction23);

	//Do same thing for normals
	Normal n1 = linearInterNorm(Nx[0], Ny[0], Nz[0], Nx[1], Ny[1],
	Nz[1], fraction13);
	Normal n2 = linearInterNorm(Nx[0], Ny[0], Nz[0], Nx[1], Ny[1],
	Nz[1], fraction23);
	Normal n3 = linearInterNorm(Nx[3], Ny[3], Nz[3], Nx[2], Ny[2],
	Nz[2], fraction13);
	Normal n4 = linearInterNorm(Nx[3], Ny[3], Nz[3], Nx[2], Ny[2],
	Nz[2], fraction23);
	Normal n5 = linearInterNorm(Nx[0], Ny[0], Nz[0], Nx[3], Ny[3],
	Nz[3], fraction13);
	Normal n6 = linearInterNorm(Nx[0], Ny[0], Nz[0], Nx[3], Ny[3],
	Nz[3], fraction23);
	Normal n7 = linearInterNorm(Nx[1], Ny[1], Nz[1], Nx[2], Ny[2],
	Nz[2], fraction13);
	Normal n8 = linearInterNorm(Nx[1], Ny[1], Nz[1], Nx[2], Ny[2],
	Nz[2], fraction23);
	Normal n9 = linearInterNorm(n1.getNx(), n1.getNy(), n1.getNz(), 
	n3.getNx(), n3.getNy(), n3.getNz(),  fraction13);
	Normal n10 = linearInterNorm(n1.getNx(), n1.getNy(), n1.getNz(), 
	n3.getNx(), n3.getNy(), n3.getNz(),  fraction23);
	Normal n11 = linearInterNorm(n2.getNx(), n2.getNy(), n2.getNz(), 
	n4.getNx(), n4.getNy(), n4.getNz(),  fraction13);
	Normal n12 = linearInterNorm(n2.getNx(), n2.getNy(), n2.getNz(), 
	n4.getNx(), n4.getNy(), n4.getNz(),  fraction23);
	
	
	//Define 9 Rectangles
	Point orig1;
	orig1.setX(Px[0]);
	orig1.setY(Py[0]);
	orig1.setZ(Pz[0]);
	Point orig2;
	orig2.setX(Px[1]);
	orig2.setY(Py[1]);
	orig2.setZ(Pz[1]);
	Point orig3;
	orig3.setX(Px[2]);
	orig3.setY(Py[2]);
	orig3.setZ(Pz[2]);
	Point orig4;
	orig4.setX(Px[3]);
	orig4.setY(Py[3]);
	orig4.setZ(Pz[3]);
	Normal origN1;
	origN1.setNx(Nx[0]);
	origN1.setNy(Ny[0]);
	origN1.setNz(Nz[0]);
	Normal origN2;
	origN2.setNx(Nx[1]);
	origN2.setNy(Ny[1]);
	origN2.setNz(Nz[1]);
	Normal origN3;
	origN3.setNx(Nx[2]);
	origN3.setNy(Ny[2]);
	origN3.setNz(Nz[2]);
	Normal origN4;
	origN4.setNx(Nx[3]);
	origN4.setNy(Ny[3]);
	origN4.setNz(Nz[3]);

	Rectangle r1;
	r1.points[0] = p2;
	r1.points[1] = orig2;
	r1.points[2] = p7;
	r1.points[3] = p11;
	r1.normals[0] = n2;
	r1.normals[1] = origN2;
	r1.normals[2] = n7;
	r1.normals[3] = n11;
	
	Rectangle r2;
	r2.points[0] = p1;
	r2.points[1] = p2;
	r2.points[2] = p11;
	r2.points[3] = p9;
	r2.normals[0] = n1;
	r2.normals[1] = n2;
	r2.normals[2] = n11;
	r2.normals[3] = n9;	

	Rectangle r3;
	r3.points[0] = orig1;
	r3.points[1] = p1;
	r3.points[2] = p9;
	r3.points[3] = p5;
	r3.normals[0] = origN1;
	r3.normals[1] = n1;
	r3.normals[2] = n9;
	r3.normals[3] = n5;
	
	Rectangle r4; 
	r4.points[0] = p11;
	r4.points[1] = p7;
	r4.points[2] = p8;
	r4.points[3] = p12;
	r4.normals[0] = n11;
	r4.normals[1] = n7;
	r4.normals[2] = n8;
	r4.normals[3] = n12;

	Rectangle r5;
	r5.points[0] = p9;
	r5.points[1] = p11;
	r5.points[2] = p12;
	r5.points[3] = p10;
	r5.normals[0] = n9;
	r5.normals[1] = n11;
	r5.normals[2] = n12;
	r5.normals[3] = n10;

	Rectangle r6;
	r6.points[0] = p5;
	r6.points[1] = p9;
	r6.points[2] = p10;
	r6.points[3] = p6;
	r6.normals[0] = n5;
	r6.normals[1] = n9;
	r6.normals[2] = n10;
	r6.normals[3] = n6;

	Rectangle r7;
	r7.points[0] = p12;
	r7.points[1] = p8;
	r7.points[2] = orig3;
	r7.points[3] = p4;
	r7.normals[0] = n12;
	r7.normals[1] = n8;
	r7.normals[2] = origN3;
	r7.normals[3] = n4;

	Rectangle r8;
	r8.points[0] = p10;
	r8.points[1] = p12;
	r8.points[2] = p4;
	r8.points[3] = p3;
	r8.normals[0] = n10;
	r8.normals[1] = n12;
	r8.normals[2] = n4;
	r8.normals[3] = n3;
	
	Rectangle r9;
	r9.points[0] = p6;
	r9.points[1] = p10;
	r9.points[2] = p3;
	r9.points[3] = orig4;
	r9.normals[0] = n6;
	r9.normals[1] = n10;
	r9.normals[2] = n3;
	r9.normals[3] = origN4;
	
	Rectangle rectangles[9] = {r1, r2, r3, r4, r5, r6, r7, r8, r9};

	float Lx, Ly, Lz;
	float Ka, Kd, Ks, Kp;
	cout << "Enter the light direction (Enter as Lx Ly Lz)" << endl;
	cin >> Lx >> Ly >> Lz;
	cout << "Enter the Phong coefficients (Enter as Ka Kd Ks Kp)" << endl;
	cin >> Ka >> Kd >> Ks >> Kp;
	
	//Calculate phong shading 
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 4; j++) {
			float Px = rectangles[i].points[j].getX();
			float Py = rectangles[i].points[j].getY();
			float Pz = rectangles[i].points[j].getZ();
			float Nx = rectangles[i].normals[j].getNx();
			float Ny = rectangles[i].normals[j].getNy();
			float Nz = rectangles[i].normals[j].getNz();
			rectangles[i].colors[j] = phong(Px, Py, Pz, Lx, Ly, Lz, 
			Nx, Ny, Nz, r, g, b, Ka, Kd, Ks, Kp);
		}
	}


	ofstream dout;
	dout.open("output.txt");
	//Write to output
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 4; j++) {
			float R = rectangles[i].colors[j].getR();
			float G = rectangles[i].colors[j].getG();
			float B = rectangles[i].colors[j].getB();
			float Nx = rectangles[i].normals[j].getNx();
			float Ny = rectangles[i].normals[j].getNy();
			float Nz = rectangles[i].normals[j].getNz();
			float x = rectangles[i].points[j].getX();
			float y = rectangles[i].points[j].getY();
			float z = rectangles[i].points[j].getZ();
			dout << "color" << " " << R << " " << G << " " << B << endl;
			dout << "normal" << " " << Nx << " " << Ny << " " << Nz << endl; 
			dout << "point" << " " << x << " " << y << " " << z << endl;
		}
		dout << endl;
	}

	
	dout.close();

	return 0;
}
