class Solution {
    public int[] solution(int[] sequence, int k) {
        
        int[] answer = new int[2];
        
        int start = sequence.length - 1;
        int end = sequence.length - 1;
        int sum = sequence[sequence.length - 1];
        
        while (start >= 0 && end >= 0) {
            
            if (sum == k) {
                break;
            } else if (sum < k) {
                sum += sequence[--start];
            } else { // sum > k
                if(start == end) {
                    sum += sequence[--start];
                    sum -= sequence[end--];
                } else {
                    sum -= sequence[end--];
                }
            }
        }
        
        while(start > 0 && end > 0) {
            if(sequence[start-1] == sequence[end]) {
                start--;
                end--;
            } else {
                break;
            }
        }

        answer[0] = start;
        answer[1] = end;
        return answer;
    }
}