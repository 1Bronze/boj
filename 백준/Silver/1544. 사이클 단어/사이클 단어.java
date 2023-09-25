import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		Set<String> strSet = new HashSet<String>();
		int result = n;
		
		for(int i = 0; i < n; i++) {
			String temp = br.readLine();
			
			String rotated = temp;
			for(int j = 0; j < temp.length(); j++) {
				rotated = rotated.substring(1) + rotated.charAt(0);
				if(strSet.contains(rotated)) {
					result--;
					break;
				}
			}
			strSet.add(rotated);
		}
		
		System.out.println(result);
	}

}
