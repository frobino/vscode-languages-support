namespace mathfuncs
{
    class MyMathClass
    {
    private:
        /* data */
    public:
        MyMathClass(/* args */);
        ~MyMathClass();

        // Returns a + b
        static double add(double a, double b);

        // Returns a - b
        static double subtract(double a, double b);

        // Returns a * b
        static double multiply(double a, double b);

        // Returns a / b
        static double divide(double a, double b);
    };
    
} // namespace MathFuncs
