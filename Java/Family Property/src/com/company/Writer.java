package com.company;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;

/**
 * @Author Bigbug
 * @Email ibigbugcc@gmail.com
 * @Version 1.0
 * @Date 2020-12-14 12:38
 * @Package com.company
 */
public class Writer {
    static BufferedWriter writer;
    static void init(OutputStream outputStream) {
        writer = new BufferedWriter(new OutputStreamWriter(outputStream));
    }
    static void print(Object object) throws IOException {
        writer.write(object.toString());
    }
    static void println(Object object) throws IOException {
        writer.write(object.toString());
        writer.write("\n");
    }
    static void close() throws IOException {
        // TODO Auto-generated method stub
        writer.close();
    }
}
