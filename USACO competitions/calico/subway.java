import java.io.*;
import java.util.*;

class subway {
    /**
     * Find the total distance the subway must travel until all passengers have
     * arrived at their ending station.
     *
     * N: the number of passengers
     * M: the number of stations
     * K: the maximum number of passengers the subway can carry
     * S: list of starting stations for each passenger
     * E: list of ending stations for each passenger
     */
    static int solve(int N, int M, int K, int[] S, int[] E) {
        ArrayList<Integer>[] stationStarts = new ArrayList[M];
        ArrayList<Integer>[] stationEnds = new ArrayList[M];
        ArrayList<Integer> onTrain = new ArrayList<>();
        int stationId = 0;
        int miles = 0;
        int passengersTotal = 0;
        for (int i = 0; i<M; i++){
            stationStarts[i] = new ArrayList<>();
            stationEnds[i] = new ArrayList<>();
        }
        for (int i = 0; i<N; i++){
            stationStarts[S[i]-1].add(i);
            stationEnds[E[i]-1].add(i);
        }
        //System.out.println();
        while (passengersTotal < N){
            for (int i = 0; i<stationEnds[stationId].size(); i++){
                if (onTrain.contains(stationEnds[stationId].get(i))){
                    passengersTotal++;
                }
            }
            onTrain.removeAll(stationEnds[stationId]);
            if (passengersTotal == N) break;
            for (int i = 0; i<stationStarts[stationId].size(); i++){
                if (onTrain.size() == K) break;
                onTrain.add(stationStarts[stationId].get(i));

            }
            stationStarts[stationId].removeAll(onTrain);
            stationId++;
            if (stationId == M) stationId = 0;
            miles++;
        }
        return miles;
    }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++) {
            String[] temp = in.readLine().split(" ");
            int N = Integer.parseInt(temp[0]);
            int M = Integer.parseInt(temp[1]);
            int K = Integer.parseInt(temp[2]);
            temp = in.readLine().split(" ");
            int[] S = new int[N];
            for (int j = 0; j < N; j++) {
                S[j] = Integer.parseInt(temp[j]);
            }
            temp = in.readLine().split(" ");
            int[] E = new int[N];
            for (int j = 0; j < N; j++) {
                E[j] = Integer.parseInt(temp[j]);
            }
            out.println(solve(N, M, K, S, E));
        }
        out.flush();
    }
}