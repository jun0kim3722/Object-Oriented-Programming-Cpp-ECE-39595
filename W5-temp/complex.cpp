#include "complex.h"
#include <cmath>

Complex::Complex(double a, double b) {
    real = a;
    im = b;
}

bool Complex::operator<(const Complex &num) const {
    double this_size = sqrt(this->real * this->real + this->im * this->im);
    double given_size = sqrt(num.real * num.real + num.im * num.im);

    if (this_size < given_size) {
        return true;
    }
    else {
        return false;
    }
}

double Complex::get_real() {
    return real;
}

double Complex::get_im() {
    return im;
}