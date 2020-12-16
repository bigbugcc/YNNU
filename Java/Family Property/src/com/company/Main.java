package com.company;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Main {

    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        Writer.init(System.out);
        solve();
        Reader.close();
        Writer.close();
    }



    static int[]pre = new int[10001];
    static int[]personNum = new int[10001];
    static int[]houseNum = new int[10001];
    static int[]area = new int[10001];
    static class Family{
        int minNumber;
        int num;
        double houseNumAvg;
        double areaAvg;
        public Family(int i, int j, double d, double e) {
            this.minNumber = i;
            this.num = j;
            this.houseNumAvg = d;
            this.areaAvg = e;
        }
    }
    static ArrayList<Family> families = new ArrayList<Family>();
    private static void solve() throws IOException {
        int n = Reader.nextInt();
        for (int i = 0; i < pre.length; i++) {
            pre[i] = i;
        }
        for (int i = 0; i < n; i++) {
            int id = Reader.nextInt();
            int fid = Reader.nextInt();
            int mid = Reader.nextInt();
            if (fid!=-1) {
                union(id,fid);
            }
            if (mid!=-1) {
                union(id,mid);
            }
            int cnum = Reader.nextInt();
            for (int j = 0; j < cnum; j++) {
                int cid = Reader.nextInt();
                union(id, cid);
            }
            int pid = find(id);
            houseNum[pid] += Reader.nextInt();
            area[pid] += Reader.nextInt();
        }
        for (int i = 0; i < personNum.length; i++) {
            personNum[find(i)]++;
        }
        for (int i = 0; i < pre.length; i++) {
            if (pre[i] == i&&houseNum[i]!=0) {
                families.add(new Family(i,personNum[i],1.0*houseNum[i]/personNum[i],1.0*area[i]/personNum[i]));

            }
        }
        Collections.sort(families, new Comparator<Family>() {

            @Override
            public int compare(Family o1, Family o2) {
                // TODO Auto-generated method stub
                if (o1.areaAvg>o2.areaAvg) {
                    return -1;
                }else if(o1.areaAvg==o2.areaAvg) {
                    return o1.minNumber-o2.minNumber;
                }else
                    return 1;

            }
        });
        Writer.println(families.size());
        for (Family f : families) {
            Writer.println(String.format("%04d", f.minNumber)+" "+f.num+" "+String.format("%.3f", f.houseNumAvg)+" "+String.format("%.3f", f.areaAvg));
        }
    }
    static void union(int id1,int id2) {
        int pid1 = find(id1);
        int pid2 = find(id2);
        if (pid1<pid2) {
            pre[pid2] = pid1;
            houseNum[pid1]+=houseNum[pid2];
            area[pid1]+=area[pid2];
        }
        if (pid1>pid2) {
            pre[pid1] = pid2;
            houseNum[pid2]+=houseNum[pid1];
            area[pid2]+=area[pid1];
        }
    }
    private static int find(int id1) {
        while (id1!=pre[id1]) {
            id1 = pre[id1];
        }
        return id1;
    }
}
