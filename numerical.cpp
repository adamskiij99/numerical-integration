#include <iostream>
#include <math.h>

// define functions
double f1 (double x) { return x * x * x; }
double f2 (double x) { return log(x) / (1.0 - x); }
double f3 (double x) { return log(x) / (1.0 - x * x); }
double f4 (double x) { return log((1 + x) / (1 - x)) / x; }
double f5 (double x) { return 1 / (1 + cos(x)); }

// display functions
void showMenu() {
    std::cout << "******* Available functions *******" << std::endl;
    std::cout << "f1(x) = x^3" << std::endl;
    std::cout << "f2(x) = log(x) / (1 - x)" << std::endl;
    std::cout << "f3(x) = log(x) / (1 - x^2)" << std::endl;
    std::cout << "f4(x) = log((1 + x) / (1 - x)) / x" << std::endl;
    std::cout << "f5(x) = 1 / (1 + cos(x))" << std::endl;
    std::cout << "***********************************" << std::endl;
}

// estimate integral of func from x = A to x = B, using the midpoint rule with N steps
double MidpointRuleValue(double (*func)(double x), double A, double B, int N)
{
    double res = 0.0;
    double h = (B - A) / double (N);
    for (double x = A + (0.5 * h); x < B; x += h)
    {
        res += func(x);
    }
    return res * h;
}

int main()
{
    char againPref = 'Y';
    int funcPref;

    double A;
    double B;
    int N;

    double d;

    // interact with the user
    do{
        // clear screen and display function options
        system("cls");
        showMenu();

        int funcPref;

        std::cout << "Function preference: f";
        std::cin >> funcPref;

        std::cout << "Integrate from x = ";
        std::cin >> A;
        std::cout << "to x = ";
        std::cin >> B;
        std::cout << "with N steps, N = ";
        std::cin >> N;

        switch (funcPref) {
            case 1: d = MidpointRuleValue(f1, A, B, N); break;
            case 2: d = MidpointRuleValue(f2, A, B, N); break;
            case 3: d = MidpointRuleValue(f3, A, B, N); break;
            case 4: d = MidpointRuleValue(f4, A, B, N); break;
            case 5: d = MidpointRuleValue(f5, A, B, N); break;
        }

        std::cout << "Approximate integral is: " << d << std::endl;

        std::cout << "Again? (Y/N): ";
        std::cin >> againPref;
    } while (againPref == 'Y');

    return 0;
}