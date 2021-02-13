/*
 ID: dongliu3
 LANG: JAVA
 TASK: ride
*/

import java.io.*;
import java.util.*;

class ride {
	public static void main (String[] args) throws IOException {
		Scanner r = new Scanner(new File("ride.in"));
		PrintWriter w = new PrintWriter(new FileWriter("ride.out"));

		String a = r.next();
		String b = r.next();
		if(getHash(a) == getHash(b)) {
			w.println("GO");
		} else {
			w.println("STAY");
		}
		w.close();
	}
	public static int getHash(String s) {
		int value = 1;
		for(int i = 0; i < s.length(); ++i) {
			value *= (s.charAt(i) - 'A' + 1);
			value %= 47;
		}
		return value;
	}
}