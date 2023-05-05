import java.util.*;

class Solution {
    public String[] solution(String[] orders, int[] course) {

        List<String> answer = new ArrayList<>();

        // 1. orders에 있는 String을 오름차순으로 정렬한다.
        for (int i = 0; i < orders.length; i++) {
            char[] tmp = orders[i].toCharArray();
            Arrays.sort(tmp);
            orders[i] = new String(tmp);
        }

        // 2. course[i]개로 구성된 세트 메뉴를 추가한다.
        for (int i = 0; i < course.length; i++) {
            int num = course[i];

            // 3. num개의 조합을 뽑아서 <문자열, 뽑은횟수>를 map으로 저장한다.
            HashMap<String, Integer> countMap = new HashMap<String, Integer>();
            for (String order : orders) {
                comb(order, new StringBuilder(), -1, num, countMap);
            }

            // 4. 가장 많이 등장한 횟수를 찾는다.
            int max = 0;
            for (Map.Entry<String, Integer> entry : countMap.entrySet()) {
                max = Math.max(max, entry.getValue());
            }

            // 가장 많이 등장한 문자열을 answer에 추가한다.
            for (Map.Entry<String, Integer> entry : countMap.entrySet()) {
                if(max < 2) break;
                if(entry.getValue() == max) {
                    answer.add(entry.getKey());
                }
            }
        }

        Collections.sort(answer);
        return answer.toArray(new String[0]);
    }

    private void comb(String orders, StringBuilder sb, int cur, int condition, HashMap<String, Integer> countMap) {

        if (sb.length() == condition) {
            String target = sb.toString();
            countMap.put(target, countMap.getOrDefault(target, 0) + 1);
            return;
        }
        
        for (int i = cur + 1; i < orders.length(); i++) {
            sb.append(orders.charAt(i));
            comb(orders, sb, i, condition, countMap);
            sb.delete(sb.length()-1, sb.length());
        }
    }
}