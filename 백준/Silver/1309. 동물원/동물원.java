import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int[] DP;

    public static void main(String[] args) throws Exception {

        int N = Integer.parseInt(br.readLine());
        DP = new int[N+1];

        DP[0] = 1;
        DP[1] = 3;
        for (int i = 2; i <=N; i++) {
            DP[i] = (2 * DP[i-1] + DP[i-2]) % 9901;
        }

        System.out.println(DP[N]);
    }
}