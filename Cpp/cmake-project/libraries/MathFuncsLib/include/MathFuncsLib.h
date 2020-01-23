namespace MathFuncs
{
    class MyMathClass
    {
    private:
        /* data */
    public:
        MyMathClass(/* args */);
        ~MyMathClass();

        // Returns a + b
        static double Add(double a, double b);

        // Returns a - b
        static double Subtract(double a, double b);

        // Returns a * b
        static double Multiply(double a, double b);

        // Returns a / b
        static double Divide(double a, double b);
    };
    
} // namespace MathFuncs
