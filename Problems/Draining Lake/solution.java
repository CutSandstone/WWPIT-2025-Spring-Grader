import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;

public class solution {
    static int N;
    static int targetX = 0;
    static int targetY = 0;
    static int inputTime = 0;
    static int time = 0;
    static int[][] grid;

    static BufferedReader scanner;

    static Random random;

    static int totalSolves = 0;
    static int totalFails = 0;
    static long totalTime = 0;
    public static void main(String[] args) throws IOException {
        scanner = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(scanner.readLine());
        random = new Random();
        for (int t = 0; t < T; t++) {
            N = Integer.parseInt(scanner.readLine());
            solve();
        }
    }
    
    public static void solve() throws IOException {
        long startTime = System.nanoTime();

        // System.out.println("TARGET: (" + targetX + ", " + targetY + ")");
        inputTime = time = 0;
        
        int[] grid2 = new int[N * N];
        int total = N * N;
        for (int i = 0; i < N * N; i++) {
            grid2[i] = i;
        }
        int buffer = 10;

        int[][] guesses = new int[N - buffer][3];
        for (int t = 0; t < N - buffer; t++) {
            int mx = random.nextInt(N);
            int my = random.nextInt(N);
            boolean hit = input(mx, my);
            guesses[t][0] = mx;
            guesses[t][1] = my;
            guesses[t][2] = hit ? 1 : 0;
        }

        int operations = 0;
        for (int t = N - buffer - 1; t >= 0; t--) {
            // int mx = random.nextInt(N);
            // int my = random.nextInt(N);
            int mx = guesses[t][0];
            int my = guesses[t][1];
            // int mx;
            // int my;
            // while (true) {
            //     mx = random.nextInt(N);
            //     my = random.nextInt(N);
            //     boolean inside = false;
            //     boolean outside = false;
            //     for (int i = 0; i < total; i++) {
            //         if (dist(mx, my, grid2[i] % N, grid2[i] / N) <= time) {
            //             inside = true;
            //         }
            //         else {
            //             outside = true;
            //         }
            //         if (inside && outside) {
            //             break;
            //         }
            //     }
            //     if (inside && outside) {
            //         break;
            //     }
            // }
            // boolean hit = input(mx, my);
            boolean hit = false;
            if (guesses[t][2] == 1) {
                hit = true;
            }
            int[] grid3 = new int[total];
            int index = 0;
            for (int i = 0; i < total; i++) {
                if (!((dist(mx, my, grid2[i] % N, grid2[i] / N) <= t) ^ hit)) {
                    grid3[index++] = grid2[i];
                }
            }
            // System.out.println(index);
            total = index;
            grid2 = grid3;
            operations += total;
            if (total == 1) {
                break;
            }
        }
        if (total != 1) {
            for (int t = N - buffer; t < N; t++) {
                int bmx = 0;
                int bmy = 0;
                int bmd = Integer.MAX_VALUE;
                for (int my = 0; my < N; my++) {
                    for (int mx = 0; mx < N; mx++) {
                        int hit = 0;
                        int remaining = 0;
                        for (int i = 0; i < total; i++) {
                            if (dist(grid2[i] % N, grid2[i] / N, mx, my) <= t) {
                                hit += 1;
                            }
                            remaining += 1;
                        }
                        int d = Math.abs(hit - remaining / 2);
                        if (d <= bmd) {
                            bmx = mx;
                            bmy = my;
                            bmd = d;
                        }
                    }
                }
                boolean hit = input(bmx, bmy);
                
                int[] grid3 = new int[total];
                int index = 0;
                for (int i = 0; i < total; i++) {
                    if (!((dist(bmx, bmy, grid2[i] % N, grid2[i] / N) <= t) ^ hit)) {
                        grid3[index++] = grid2[i];
                    }
                }
                // System.out.println(index);
                total = index;
                grid2 = grid3;
                operations += total;
                if (total == 1) {
                    break;
                }
            }
        }
        // System.out.println("TOTAL OPERATIONS: " + operations);
        for (int i = 0; i < total; i++) {
            System.out.println("! " + (grid2[i] % N + 1) + " " + (grid2[i] / N + 1));
        }
        if (total > 1) {
            totalFails++;
        }
        // code battle advanced - 5:12 PM
        // i thought you needed to use up all the queries
        // or it would bork or something
        // while (inputTime < N) {
        //     input(0, 0);
        //     inputTime += 1;
        // }

        totalSolves++;
        // System.out.println((double) (System.nanoTime() - startTime) / 1000000);
        totalTime += System.nanoTime() - startTime;
    }
    
    public static void createGrid() {
        grid = new int[N][N];
    }
    public static boolean guessToGrid(int mx, int my) throws IOException {
        // System.out.println("GUESS: (" + mx + ", " + my + "), time " + time);
        boolean hit = input(mx, my);
        if (!hit) {
            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if (grid[y][x] == 0) {
                        if (dist(x, y, mx, my) <= time) {
                            grid[y][x] = 1;
                        }
                    }
                }
            }
        }
        else {
            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if (grid[y][x] == 0) {
                        if (dist(x, y, mx, my) > time) {
                            grid[y][x] = 1;
                        }
                    }
                }
            }
        }
        time++;
        return hit;
    }
    public static void answerFromGrid() {
        int answers = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (grid[y][x] == 0) {
                    System.out.println("! " + (x + 1) + " " + (y + 1));
                    answers++;
                    // return;
                }
            }
        }
        if (answers > 1) {
            totalFails++;
            System.out.println(">1 ANSWERS FOUND!!!");
        }
    }
    
    public static boolean bruteForce() throws IOException {
        int bmx = 0;
        int bmy = 0;
        int bmd = Integer.MAX_VALUE;
        for (int my = 0; my < N; my++) {
            for (int mx = 0; mx < N; mx++) {
                int hit = 0;
                int remaining = 0;
                for (int y = 0; y < N; y++) {
                    for (int x = 0; x < N; x++) {
                        if (grid[y][x] == 0) {
                            if (dist(x, y, mx, my) <= time) {
                                hit += 1;
                            }
                            remaining += 1;
                        }
                    }
                }
                int d = Math.abs(hit - remaining / 2);
                if (d <= bmd) {
                    bmx = mx;
                    bmy = my;
                    bmd = d;
                }
            }
        }
        return guessToGrid(bmx, bmy);
    }
    public static boolean progressGuessing() throws IOException {
        int mx;
        int my;
        while (true) {
            mx = random.nextInt(N);
            my = random.nextInt(N);
            int hit = 0;
            int remaining = 0;
            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if (grid[y][x] == 0) {
                        if (dist(x, y, mx, my) <= time) {
                            hit += 1;
                        }
                        remaining += 1;
                    }
                }
            }
            if (remaining == 1) {
                return guessToGrid(0, 0);
            }
            if (hit != 0 && hit != remaining) {
                break;
            }
        }
        return guessToGrid(mx, my);
    }
    
    public static boolean input(int x, int y) throws IOException {
        System.out.println("? " + (x + 1) + " " + (y + 1));
        System.out.flush();
        inputTime += 1;
        return scanner.readLine().equals("0");
        // return dist(x, y, targetX, targetY) <= inputTime++;
    }
    public static int dist(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }
}