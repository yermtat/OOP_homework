
#include"Point.h"

FILE* file;

void Point::setX(int new_x) {
	x = new_x;
}
void Point::setY(int new_y) {
	y = new_y;
}
void Point::setZ(int new_z) {
	z = new_z;
}

int Point::getX() {
	return x;
}
int Point::getY() {
	return y;
}
int Point::getZ() {
	return z;
}

void Point::setPoint() {

	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;
	cout << "Enter z: ";
	cin >> z;
}
void Point::getPoint() {
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;
}

void Point::save() {

	fopen_s(&file, "point.dat", "wb");

	fwrite((char*)&x, sizeof(int), 1, file);
	fwrite((char*)&y, sizeof(int), 1, file);
	fwrite((char*)&z, sizeof(int), 1, file);

	fclose(file);
}
void Point::load() {

	fopen_s(&file, "point.dat", "rb");

	fread((char*)&x, sizeof(int), 1, file);
	fread((char*)&y, sizeof(int), 1, file);
	fread((char*)&z, sizeof(int), 1, file);

	fclose(file);

}