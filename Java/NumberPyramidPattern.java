import java.util.*;

public class NumberPyramidPattern {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter the height of the pyramid: ");
            int n = sc.nextInt();
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < n - i; j++)
                    System.out.print(" ");
                for (int j = 0; j < i; j++) {
                    System.out.print(i);
                    System.out.print(" ");
                }
                System.out.println();
            }
        }
    }
}
