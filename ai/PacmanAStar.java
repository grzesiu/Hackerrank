import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.ArrayList;

class Node implements Comparable<Node> {
    int x, y, g, h;
    boolean accessible;
    Node pred;

    public Node(char c, int x, int y, int fx, int fy) {
        this.accessible = c != '%';
        this.x = x;
        this.y = y;
        this.g = Integer.MAX_VALUE;
        this.h = Math.abs(x - fx) + Math.abs(y - fy);
    }

    @Override
    public int compareTo(Node n) {
        if (g + h < n.g + n.h) {
            return -1;
        }
        else if (g + h > n.g + n.h) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

public class PacmanAStar {
    public static final int[][] DS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    public static Node getCurr(PriorityQueue<Node> open) {
        Node curr;
        do {
            curr = open.poll();
        } while (!curr.accessible);
        return curr;
    }
    public static void findPath(int px, int py, int fx, int fy, int rows, int cols, Node[][] grid) {
        PriorityQueue<Node> open = new PriorityQueue<>();
        Node curr = grid[px][py];
        curr.g = 0;
        open.add(curr);

        while (!open.isEmpty()) {
            curr = getCurr(open);
            curr.accessible = false;
            for (int[] d : DS) {
                Node next = grid[curr.x + d[0]][curr.y + d[1]];
                if (next.accessible) {
                    int g = curr.g + 1;
                    if (g < next.g) {
                        next.g = g;
                        next.pred = curr;
                        if (next.h == 0) {
                            return;
                        }
                        open.add(next);
                    }
                }
            }
        }
        return;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int px = scanner.nextInt();
        int py = scanner.nextInt();
        int fx = scanner.nextInt();
        int fy = scanner.nextInt();
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        Node[][] grid = new Node[rows][cols];
        for(int i = 0; i < rows; i++) {
            String next = scanner.next();
            for(int j = 0; j < cols; j++) {
                grid[i][j] = new Node(next.charAt(j), i, j, fx, fy);
            }
        }

        findPath(px, py, fx, fy, rows, cols, grid);
        

        Node n = grid[fx][fy];
        System.out.println(n.g);
        ArrayList<Node> nodes = new ArrayList<>();
        while (n != null) {
            nodes.add(n);
            n = n.pred;
        }

        for (int i = nodes.size() - 1; i >= 0; i--) {
            System.out.printf("%d %d\n", nodes.get(i).x, nodes.get(i).y);
        }
    }
}
