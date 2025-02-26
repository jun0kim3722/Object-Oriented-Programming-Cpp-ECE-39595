class Complex
{
private:
    /* data */
    double real;
    double im;
public:
    Complex(double a, double b);
    bool operator<(const Complex &num) const;
    double get_real();
    double get_im();
    ~Complex() {};
};
