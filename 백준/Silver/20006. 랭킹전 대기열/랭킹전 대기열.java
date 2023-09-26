import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Comparator;

public class Main {
	private int p;
	private int m;
	private ArrayList<Room> rooms = new ArrayList<Room>();
	
	public void solution() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		p = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		loop:
		for(int i=1; i<=p; i++) {
			st = new StringTokenizer(br.readLine());
			int level = Integer.parseInt(st.nextToken());
			String nickname = st.nextToken();
			Player player = new Player(level, nickname);
			
			int j;
			for(j = 0; j < rooms.size(); j++) {
				Room room = rooms.get(j);
				int criterion = room.players.get(0).level;
				int gap = player.level-criterion;
				if(gap >= -10 && gap <= 10 && room.players.size() < m) {
					room.players.add(player);
					continue loop;
				}
			}
			Room newRoom = new Room(player);
			rooms.add(newRoom);
		}
		
		rooms.forEach(room -> {
			if(room.players.size() == m) {
				System.out.println("Started!");
			} else {
				System.out.println("Waiting!");
			}
			
			room.players.sort(Comparator.comparing(player -> player.nickname));
			room.players.forEach(player -> {
				player.printInfo();
			});
		});
	}
	
	public static void main(String[] args) throws Exception {
		new Main().solution();
	}
}

class Player {
	int level;
	String nickname;
	
	Player(int level, String nickname) {
		this.level = level;
		this.nickname = nickname;
	}
	
	void printInfo() {
		System.out.println(level + " " + nickname);
	}
}

class Room {
	ArrayList<Player> players = new ArrayList<Player>();
	
	Room(Player creator) {
		players.add(creator);
	}
}