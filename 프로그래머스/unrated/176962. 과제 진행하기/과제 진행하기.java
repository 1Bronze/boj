import java.util.*;

class Solution {

    public static String[] solution(String[][] plans) {

        // 전체 일의 개수
        int size = plans.length;
        // plans 사용하기 쉽게 works로 변환
        List<Work> works = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            works.add(new Work(plans[i]));
        }
        Collections.sort(works, (a, b) -> {
            return a.startAt - b.startAt;
        });

        // 완료된 일의 개수
        int checkCnt = 0;
        // 현재 시간
        int time = works.get(0).startAt;
        // 결과를 저장할 배열
        String[] answer = new String[size];

        int i = 0;
        while(i < size-1) {
            Work cur = works.get(i);
            Work next = works.get(i + 1);

            int gap = next.startAt - time;
            if (cur.residue <= gap) { // 1. 작업을 시간안에 모두 마칠 수 있는 경우
                time += cur.residue;
                gap -= cur.residue;
                cur.residue = 0;
                answer[checkCnt++] = cur.name;

                while(gap > 0) { // 1-a. 작업을 마친 뒤 시간이 남았을 경우

                    int target = i - 1;
                    while(target>=0 && works.get(target).residue == 0) {
                        target -= 1;
                    }
                    if(target == -1) {
                        time = next.startAt;
                        break;
                    }

                    if(works.get(target).residue <= gap) {
                        time += works.get(target).residue;
                        gap -= works.get(target).residue;
                        works.get(target).residue = 0;
                        answer[checkCnt++] = works.get(target).name;
                    } else {
                        time = next.startAt;
                        works.get(target).residue -= gap;
                        gap = 0;
                    }
                }
            } else { // 2. 작업을 시간안에 마치지 못하는 경우
                time += gap;
                cur.residue -= gap;
                gap = 0;
            }

            i++;
        }

        int target = size - 1;
        while(checkCnt < size) {
            while(target>=0 && works.get(target).residue == 0) {
                target -= 1;
            }
            works.get(target).residue = 0;
            answer[checkCnt++] = works.get(target).name;
        }

        return answer;
    }
}

class Work {
    String name;
    int startAt;
    int residue;
    
    Work(String[] plan) {
        name = plan[0];
        StringTokenizer st = new StringTokenizer(plan[1], ":");
        startAt += 60 * Integer.parseInt(st.nextToken());
        startAt += Integer.parseInt(st.nextToken());
        residue = Integer.parseInt(plan[2]);
    }
}