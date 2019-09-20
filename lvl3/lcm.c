// Write a function who takes two unsigned int as parameters and returns the
// computed LCM of those parameters.
//
// LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
// integer divisible by the both integers.
//
// A LCM can be calculated in two ways:
//
// - You can calculate every multiples of each integers until you have a common
// multiple other than 0
//
// - You can use the HCF (Highest Common Factor) of these two integers and
// calculate as follows:
//
//     LCM(x, y) = | x * y | / HCF(x, y)
//
//  | x * y | means "Absolute value of the product of x by y"
//
// If at least one integer is null, LCM is equal to 0.
//
// Your function must be prototyped as follows:
//
//  unsigned int    lcm(unsigned int a, unsigned int b);

unsigned int lcm(unsigned int a, unsigned int b)
{
    int result;
    int hcf = 1;
    int i;
    int k;

    if (a > b)
        k = 1;
    else if (a < b)
        k = 2;
    else
        return (a);
    if (a == 0 || b == 0)
        return (0);
    if (a > 0 && b > 0)
    {
        if (k == 1)
        {
            i = b;
            while (i > 0)
            {
                if (a % i == 0 && b % i == 0)
                {
                    hcf = i;
                    break;
                }
                i--;
            }
        }
        if (k == 2)
        {
            i = a;
            while (i > 0)
            {
                if (a % i == 0 && b % i == 0)
                {
                    hcf = i;
                    break;
                }
                i--;
            }
        }
    }
    result = a * b / hcf;
    return (result);
}
