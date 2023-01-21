import java.util.Scanner;

public class Matrix
{
    private int _rows;
    private int _columns;
    private int[][] _matrix;

    Matrix(int rows, int columns)
    {
        _rows = rows;
        _columns = columns;
        _matrix = new int[_rows][_columns];
    }
    public void Fullfill()
    {
        Scanner in = new Scanner(System.in);
        for(int i = 0; i < _rows; i++)
        {
            System.out.println("Заполнение " + i + 1 + " строки\n");
            for(int j = 0; j < _columns; j++)
            {
                System.out.println("Введите " + j + 1 + " элемент\n");
                _matrix[i][j] = in.nextInt();
            }
        }
        in.close();
    }

    public int FindMinRow()
    {
        int min = 0;
        for (int i = 0; i < _rows; i++)
        {
            for(int j = 0; j < _rows; j++)
            {
                if(_matrix[min][j] > _matrix[i][j])
                    min = i;
            }
        }
        return min;
    }

    public int FindMaxColumn()
    {
        int max = 0;
        for (int i = 0; i < _rows; i++)
        {
            for(int j = 0; j < _rows; j++)
            {
                if(_matrix[i][max] < _matrix[i][j])
                    max = j;
            }
        }
        return max;
    }
}
