import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		int i=0, n=0, result=0;
		while(in.hasNextInt()){
			n=in.nextInt();
			if(n==0) break;
			result=n*(n+1)*(2*n+1)/6;
			System.out.println(result);
		}
	}
}
