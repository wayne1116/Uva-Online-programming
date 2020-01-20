import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	public static void main(String[] argv){
        	BigInteger[] fib=new BigInteger[5001];
        	Scanner in=new Scanner(System.in);
        	fib[0]=new BigInteger("0");
        	fib[1]=new BigInteger("1");
		for(int i=2; i<=5000; i++){
            		fib[i]=fib[i-1].add(fib[i-2]);
		}
		while(in.hasNextInt()){
			int num=in.nextInt();
			System.out.println("The Fibonacci number for "+num+" is "+fib[num]);
		}
	}
}
