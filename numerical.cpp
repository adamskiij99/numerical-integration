#include <iostream>
#include <math.h>

// define functions
// 1-var
double f1 (double x) { return x * x * x; }
double f2 (double x) { return log(x) / (1.0 - x); }
double f3 (double x) { return log(x) / (1.0 - x * x); }
double f4 (double x) { return log((1 + x) / (1 - x)) / x; }
double f5 (double x) { return 1 / (1 + cos(x)); }

// 2-var
double f6 (double x, double y) { return 1 / pow(x - y, 0.1); }
double f7 (double x, double y) { return 1 / sqrt(x - y); }
double f8 (double x, double y) { return 1 / (x - y); }
double f9 (double x, double y) { return 1 / (x - y) * (x - y); }
double f10 (double x, double y) { return 1 / (1 - x * y); }
double f11 (double x, double y) { return 1 / sqrt(x * x + y * y); }

// display functions
void showMenu() {
    std::cout << "******* Available functions *******" << std::endl;
    std::cout << "Single variable:" << std::endl;
    std::cout << "f1(x) = x ^ 3" << std::endl;
    std::cout << "f2(x) = log(x) / (1 - x)" << std::endl;
    std::cout << "f3(x) = log(x) / (1 - x ^ 2)" << std::endl;
    std::cout << "f4(x) = log((1 + x) / (1 - x)) / x" << std::endl;
    std::cout << "f5(x) = 1 / (1 + cos(x))" << std::endl;
    std::cout << "Multivariable:" << std::endl;
    std::cout << "f6(x) = 1 / (x - y) ^ 0.1" << std::endl;
    std::cout << "f7(x) = 1 / (x - y) ^ 0.5" << std::endl;
    std::cout << "f8(x) = 1 / (x - y)" << std::endl;
    std::cout << "f9(x) = 1 / (x - y) ^ 2" << std::endl;
    std::cout << "f10(x) = 1 / (1 - x * y)" << std::endl;
    std::cout << "f11(x) = 1 / (x ^ 2 + y ^ 2) ^ 0.5" << std::endl;
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

// same as above but from x = A to x = B with N steps, and from y = C to y = D with M steps
double MidpointRuleValueTwo(double (*func)(double x, double y), double A, double B, double C, double D, int N, int M)
{
    double res = 0.0;
    double h1 = (B - A) / double (N);
    double h2 = (D - C) / double (M);
    for (double x = A + (0.5 * h1); x < B; x += h1)
    {
        for (double y = C + (0.5 * h2); y < D; y += h2)
        {
            res += func(x, y);
        }
    }
    return res * h1 * h2;
}

int main()
{
    char againPref = 'Y';
    int funcPref;

    double A;
    double B;
    double C;
    double D;
    int N;
    int M;

    double d;

    // interact with the user
    do{
        // clear screen and display function options
        system("cls");
        showMenu();

        int funcPref;

        std::cout << "Function preference: f";
        std::cin >> funcPref;

        // ask for x parameters
        std::cout << "Integrate from x = ";
        std::cin >> A;
        std::cout << "to x = ";
        std::cin >> B;
        std::cout << "with N steps, N = ";
        std::cin >> N;

        // also ask for y parameters if not single variable
        if (funcPref > 5) {
            std::cout << "and from y = ";
            std::cin >> C;
            std::cout << "to y = ";
            std::cin >> D;
            std::cout << "with M steps, M = ";
            std::cin >> M;
        }

        switch (funcPref) {
            case 1: d = MidpointRuleValue(f1, A, B, N); break;
            case 2: d = MidpointRuleValue(f2, A, B, N); break;
            case 3: d = MidpointRuleValue(f3, A, B, N); break;
            case 4: d = MidpointRuleValue(f4, A, B, N); break;
            case 5: d = MidpointRuleValue(f5, A, B, N); break;
            case 6: d = MidpointRuleValueTwo(f6, A, B, C, D, N, M); break;
            case 7: d = MidpointRuleValueTwo(f7, A, B, C, D, N, M); break;
            case 8: d = MidpointRuleValueTwo(f8, A, B, C, D, N, M); break;
            case 9: d = MidpointRuleValueTwo(f9, A, B, C, D, N, M); break;
            case 10: d = MidpointRuleValueTwo(f10, A, B, C, D, N, M); break;
            case 11: d = MidpointRuleValueTwo(f11, A, B, C, D, N, M); break;
        }

        std::cout << "Approximate integral is: " << d << std::endl;

        std::cout << "Again? (Y/N): ";
        std::cin >> againPref;
    } while (againPref == 'Y');

    return 0;
}
