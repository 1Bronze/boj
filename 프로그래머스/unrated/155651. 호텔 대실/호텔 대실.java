import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;

class Solution {
    public int solution(String[][] book_name) {

        // String[][] -> LinkedList 변환
        LinkedList<Booking> list = new LinkedList<>();
        for (int i = 0; i < book_name.length; i++) {
            list.add(new Booking(book_name[i]));
        }
        Collections.sort(list, (o1, o2) -> {
            return o1.startAt - o2.startAt;
        });

        int result = 0;
        while(!list.isEmpty()) {
            int time = -10;
            for (int i = 0; i < list.size(); i++) {
                if (time <= list.get(i).startAt) {
                    time = list.get(i).endAt;
                    list.remove(i);
                    i--;
                }
            }

            result += 1;
        }

        return result;
    }
}

class Booking {
    int startAt;
    int endAt;

    Booking(String[] book) {

        StringTokenizer st1 = new StringTokenizer(book[0], ":");
        StringTokenizer st2 = new StringTokenizer(book[1], ":");

        startAt += 60 * Integer.parseInt(st1.nextToken()) - 10;
        startAt += Integer.parseInt(st1.nextToken());

        endAt += 60 * Integer.parseInt(st2.nextToken());
        endAt += Integer.parseInt(st2.nextToken());
    }
}