//HM_ex_1_3.04.2023
#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
class SquareMatrix 
{
private:
    int size;
    double matrix[MAX_SIZE][MAX_SIZE];
public:
    void init(int n) 
    {
        size = n;
        for (int i = 0; i < size; i++) 
        {
            for (int j = 0; j < size; j++) 
            {
                matrix[i][j] = 0;
            }
        }
    }

    void init(int n, double value) {
        size = n;
        for (int i = 0; i < size; i++) 
        {
            for (int j = 0; j < size; j++) 
            {
                matrix[i][j] = value;
            }
        }
    }
    void init(int n, char c) 
    {
        size = n;
        for (int i = 0; i < size; i++) 
        {
            for (int j = 0; j < size; j++) 
            {
                if (i == j) {
                    matrix[i][j] = c;
                }
                else {
                    matrix[i][j] = ' ';
                }
            }
        }
    }
    void print() {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++) 
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    double getMax() {
        double max = matrix[0][0];
        for (int i = 1; i < size; i++) 
        {
            if (matrix[i][i] > max) 
            {
                max = matrix[i][i];
            }
        }
        return max;
    }
    double getMin() {
        double min = matrix[0][0];
        for (int i = 1; i < size; i++) 
        {
            if (matrix[i][i] < min) 
            {
                min = matrix[i][i];
            }
        }
        return min;
    }
};
int main()
{
    SquareMatrix matrix;
    matrix.init(5, 'X');
    matrix.print();
    cout << "Max on diagonal: " << matrix.getMax() << endl;
    cout << "Min on diagonal: " << matrix.getMin() << endl;
    return 0;
}