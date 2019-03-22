import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		double rad1, rad2, rad3;
		int a=0;
		a=Integer.parseInt(in.nextLine());
		while(a-->0){
			String[] num=(in.nextLine()).split(" ");
			if(num.length==1){
				rad1=Double.parseDouble(num[0])/2.0;
				rad2=rad1/2;
				System.out.printf("%.4f\n", Math.PI*(rad1*rad1-2*rad2*rad2));
			}
			else{
				rad1=Double.parseDouble(num[0]);
				rad2=Double.parseDouble(num[1]);
				rad3=rad1+rad2;
				System.out.printf("%.4f\n", Math.PI*(rad3*rad3-rad1*rad1-rad2*rad2));
			}
		}
	}
}