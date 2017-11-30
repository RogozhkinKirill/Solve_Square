#include <stdio.h>
#include <math.h>

int SolveSquare(double a , double b , double c , double *pX1 , double *pX2);
int UnitTests ();

int main ()
{
    double a = 0, b = 0, c = 0;
    int NumOfSolutions = -1;
    double x1 = 0, x2 = 0;


    int Ans = 0;
    int ResUT = 0;
    printf("Do you want to pass UnitTests?(1-yes; 2-no)\n");
    scanf("%d" , &Ans);
    if (Ans == 1)
    {
       ResUT = UnitTests();
       if (ResUT != 0)
       {
            return 0;
       }
    }

    int Ans1 = 0;
    printf("Do you want to continue to work with SolveSquare?(1-yes; 2-no)\n");
    scanf("%d" , &Ans1);
    if (Ans1 != 1)
    {
        return 0;
    }

    printf("Print a \n");
    scanf ("%lf" , &a);

    printf("Print b \n");
    scanf ("%lf" , &b);

    printf("Print c \n");
    scanf ("%lf" , &c);

    NumOfSolutions = SolveSquare (a, b, c , &x1 , &x2);
    switch (NumOfSolutions)
    {
        case -2 :
            printf("Error. Pointer on x1 or x2 = NULL");
                break;
        case -1 :
            printf("Infinite set roots");
                break;
        case 0 :
            printf(" Number of roots is %d \n" , NumOfSolutions);
                break;
        case 1 :
            printf(" Number of roots is %d \n Solution is %f \n"  , NumOfSolutions , x1);
                break;
        case 2 :
            printf(" Number of roots is %d \n x1 = %f \n x2 = %f \n" , NumOfSolutions , x1 , x2);
                break;
        default :
                break;
    }

    return 0 ;
}

int SolveSquare(double a , double b , double c , double *pX1 , double *pX2)
{
    if(pX1 && pX2)
    {
        int NumOfSolutions = 0;
        double D = 0.0;

        if (a == 0.0 && b == 0.0 && c == 0.0)
        {
            return -1;
        }

        if (a == 0.0 && b == 0.0)
        {
            return 0;
        }

        if (a == 0)
        {
            *pX1 = - (c / b);
            return 1;
        }

        D = b * b - 4.0 * a * c;

        if ( D < 0.0)
        {
            NumOfSolutions = 0;
        }
        else
        {
            if (D > 0.0)
            {
                NumOfSolutions = 2;

                *pX1 = (- b + sqrt(D)) / (2*a);
                *pX2 = (- b - sqrt(D)) / (2*a);
            }
            else
            {
                NumOfSolutions = 1;

                *pX1 = (-b) / (2*a);
            }
        }
        return NumOfSolutions;
    }
    else
    {
        return -2;
    }
}

int UnitTests()
{
    double x1 = 0 , x2 = 0;
    int NumOfSolutions = 0 , CountErr = 0;

    printf("UnitTest Pointer      started: ");
    NumOfSolutions = SolveSquare(0.0 , 0.0 , 0.0 , &x1 ,&x2);
    if (NumOfSolutions == -2)
    {
        printf("Error\n");
        return 1;
    }
    else
    {
        printf("Correct\n");
    }


    printf("UnitTest Roots=inf    started: ");
    NumOfSolutions = SolveSquare(0.0 , 0.0 , 0.0 , &x1 , &x2);
    if (NumOfSolutions == -1)
    {
        printf("Correct.\n");
    }
    else
    {
        printf("Error\n");
        CountErr += 1;
    }

    printf("UnitTest Roots=0      started: ");
    NumOfSolutions = SolveSquare(1.0 , 1.0 , 1.0 , &x1 , &x2);
    if (NumOfSolutions == 0)
    {
        printf("Correct\n");
    }
    else
    {
        printf("Error\n");
        CountErr += 1;
    }

    printf("UnitTest Roots=1 a=0  started: ");
    NumOfSolutions = SolveSquare(0.0 , 1.0 , 1.0 , &x1 , &x2);
    if (NumOfSolutions == 1)
    {
        printf("Correct\n");
    }
    else
    {
        printf("Error\n");
        CountErr += 1;
    }

    printf("UnitTest Roots=1 a<>0 started: ");
    NumOfSolutions = SolveSquare(1.0 , 2.0 , 1.0 , &x1 , &x2);
    if ((NumOfSolutions == 1) && (x1 == -1))
    {
        printf("Correct\n");
    }
    else
    {
        printf("Error\n");
        CountErr += 1;
    }

    printf("UnitTest Roots=2      started: ");
    NumOfSolutions = SolveSquare(1.0 , 3.0 , 2.0 , &x1 , &x2);
    if ((NumOfSolutions == 2) && (x1 == -1.0) && (x2 == -2.0))
    {
        printf("Correct\n");
    }
    else
    {
        printf("Error\n");
    }

    return CountErr;
}


