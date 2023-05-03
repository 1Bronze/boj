import java.io.BufferedReader;
import java.io.InputStreamReader;
 
public class Main {
    
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        
        int num5 = 0;
        for(int i = 0; i < T; i++){
            
            int N = Integer.parseInt(br.readLine());
            for(int j = 5; j <= N; j *= 5){
                num5 += N / j;
            }
            
            System.out.println(num5);
            num5 = 0;
        }
    }
}