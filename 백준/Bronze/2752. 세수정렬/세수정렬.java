import java.util.*;
import java.io.*;

class Main {
    
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n1 = Integer.parseInt(st.nextToken());
        int n2 = Integer.parseInt(st.nextToken());
        int n3 = Integer.parseInt(st.nextToken());
        
        ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(n1, n2, n3));
        Collections.sort(arr);
        System.out.println(arr.get(0) + " " + arr.get(1) + " " + arr.get(2));
    }
}