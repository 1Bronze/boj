import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int[] dy = {-1, 0, 1, 0};
    public static int[] dx = {0, 1, 0, -1};
    public static int R, C, T;
    public static int[][] map;

    public static void main(String[] args) throws Exception {

        input();
        execute();
    }

    private static void input() throws IOException {
        StringTokenizer st1 = new StringTokenizer(br.readLine(), " ");
        R = Integer.parseInt(st1.nextToken());
        C = Integer.parseInt(st1.nextToken());
        T = Integer.parseInt(st1.nextToken());
        map = new int[R+1][C+1];

        for (int i = 1; i <= R; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine(), " ");
            for (int j = 1; j <= C; j++) {
                map[i][j] = Integer.parseInt(st2.nextToken());
            }
        }
    }

    private static void execute() {
        for (int i = 1; i <= T; i++) {
            diffuse();
            clean();
        }

        print();
    }

    private static void diffuse() {
        int[][] diffusion = new int[R + 1][C + 1];
        for (int y = 1; y <= R; y++) {
            for (int x = 1; x <= C; x++) {
                if (map[y][x] < 1) continue;
                int cnt = 0;
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if (ny < 1 || ny > R || nx < 1 || nx > C) continue;
                    if (map[ny][nx] == -1) continue;

                    diffusion[ny][nx] += map[y][x] / 5;
                    cnt += 1;
                }
                map[y][x] -= cnt * (map[y][x] / 5);
            }
        }
        for (int y = 1; y <= R; y++) {
            for (int x = 1; x <= C; x++) {
                map[y][x] += diffusion[y][x];
            }
        }
    }

    private static void clean() {

        int top = 0, bottom = 0;

        for (int i = 1; i <= R; i++) {
            if (map[i][1] == -1) {
                top = i;
                bottom = top + 1;
                break;
            }
        }

        for (int i = top-1; i > 1; i--) map[i][1] = map[i-1][1];
        for (int i = 1; i < C; i++) map[1][i] = map[1][i+1];
        for (int i = 1; i < top; i++) map[i][C] = map[i+1][C];
        for (int i = C; i > 2; i--) map[top][i] = map[top][i-1];
        map[top][2] = 0;

        for (int i = bottom+1; i < R; i++) map[i][1] = map[i+1][1];
        for (int i = 1; i < C; i++) map[R][i] = map[R][i+1];
        for (int i = R; i > bottom; i--) map[i][C] = map[i-1][C];
        for (int i = C; i > 2; i--) map[bottom][i] = map[bottom][i-1];
        map[bottom][2] = 0;
    }

    private static void print() {
        int answer = 2;

        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                answer += map[i][j];
            }
        }

        System.out.println(answer);
    }
}