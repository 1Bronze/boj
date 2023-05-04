import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws Exception {

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N+1];
        boolean[] visited = new boolean[N+1];

        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        int num = 0;
        int answer = 0;
        for (int i = 1; i <= N; i++) {
            visited[i] = true;
            int tmp = dfs(arr, visited, i);
            visited[i] = false;
            if (num < tmp) {
                num = tmp;
                answer = i;
            }
        }

        System.out.println(answer);
    }

    public static int dfs(int[] arr, boolean[] visited, int cur) {

        int next = arr[cur];
        if (visited[next]) {
            return 1;
        }

        int ret = 1;
        visited[next] = true;
        ret += dfs(arr, visited, next);
        visited[next] = false;

        return ret;
    }
}
