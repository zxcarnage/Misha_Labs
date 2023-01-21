import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        int rows;
        int columns;
        Scanner in = new Scanner(System.in);
        System.out.println("Введите количество строк:\n");
        rows = in.nextInt();
        System.out.println("Введите количество столбцов:\n");
        columns = in.nextInt();
        Matrix matrix = new Matrix(rows,columns);
        matrix.Fullfill();
        System.out.println("Строка с минимальным элементом: " + matrix.FindMinRow() + 1);
        System.out.println("Колонка с максимальным элементом: " + matrix.FindMaxColumn() + 1);
    }
}