import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		long sum;
		int a=0, i=0, temp=0, n=0;
		a=in.nextInt();
		while(a-->0){
			n=in.nextInt();
			if((n-1)%3==0) System.out.println("NO");
			else System.out.println("YES");
		}
	}
}