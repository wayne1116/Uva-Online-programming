import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		double winp, losep, start, result;
		int a=0, n=0, i=0, win, j=0;
		a=in.nextInt();
		while(a-->0){
			n=in.nextInt();
			winp=in.nextDouble();
			losep=1-winp;
			win=in.nextInt();
			if(winp==0) System.out.println("0.0000");
			else{
				start=winp; result=1;
				for(i=0; i<win-1; i++) result*=losep;
				start*=result;
				for(j=i; j<n; j++) result*=losep;
				result=1-result;
				System.out.printf("%.4f\n",start/result);
			}
		}
	}
}