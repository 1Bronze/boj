import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static int n;
    public static int[] DP = new int[100];
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws Exception {

        n = Integer.parseInt(br.readLine());

        DP[0] = 1;
        DP[1] = 1;

        for (int i = 2; i <= n; i++) {
            DP[i] = (DP[i-1] + DP[i-2] + 1) % 1000000007;
        }

        System.out.println(DP[n]);
    }
}
