#include <stdio.h>
#include <math.h>

const double EARTH_RADIUS_METERS = 6371.393;
const double PI = 3.141592653589793;

double toRadians(double angdeg) {
    return angdeg / 180.0 * PI;
}

double distanceBetween(double lng1, double lng2, double lat) {
    double dLng = toRadians(lng2 - lng1);
    double tmp = cos(toRadians(lat));
    double a = tmp * tmp * sin(dLng / 2) * sin(dLng / 2);
    return EARTH_RADIUS_METERS * 2 * atan2(sqrt(a), sqrt(1 - a));
}

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("%.3f", distanceBetween(b, c, a));
}