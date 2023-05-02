/*
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static int n;
    public static int[] DP;
    public static Scanner sc = new Scanner(new InputStreamReader(System.in));

    public static void main(String[] args) throws Exception {

        n = Integer.parseInt(br.readLine());
        DP = new int[n+1];

        DP[0] = 1;
        DP[1] = 1;

        for (int i = 2; i <= n; i++) {
            DP[i] = (DP[i-1] + DP[i-2] + 1) % 1000000007;
        }

        System.out.println(DP[n]);
    }
}
*/

#include <iostream>
using namespace std;

int DP[51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    
    DP[0] = 1;
    DP[1] = 1;
    
    for(int i=2; i<=n; i++) {
        DP[i] = (DP[i-2] + DP[i-1] + 1) % 1000000007;
    }
    
    cout << DP[n];
}