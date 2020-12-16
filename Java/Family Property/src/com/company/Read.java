package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @Author Bigbug
 * @Email ibigbugcc@gmail.com
 * @Version 1.0
 * @Date 2020-12-14 12:37
 * @Package com.company
 */
class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    // ** call this method to initialize reader for InputStream *//*
    static void init(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }

    // ** get next word *//*
    static String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            // TODO add ceck for eof if necessary
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
    static boolean hasNext()throws IOException {
        return tokenizer.hasMoreTokens();
    }
    static String nextLine() throws IOException{
        return reader.readLine();
    }
    static char nextChar() throws IOException{
        return next().charAt(0);
    }
    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
    static float nextFloat() throws IOException {
        return Float.parseFloat(next());
    }
    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
    static void close() throws IOException {
        reader.close();
    }
}