import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		double[] number=new double[6];
		double middlex, middley, mx1, mx2, my1, my2, mc1, mc2;
		double deter, deterx, detery, x, y, radius;
		int i=0;
		while(in.hasNext()){
			for(i=0; i<6; i++) number[i]=in.nextDouble();
			middlex=(number[0]+number[2])/2;
			middley=(number[1]+number[3])/2;
			mx1=number[0]-number[2]; my1=number[1]-number[3];
			mc1=middlex*mx1+middley*my1;
		
			middlex=(number[0]+number[4])/2;
			middley=(number[1]+number[5])/2;
			mx2=number[0]-number[4]; my2=number[1]-number[5];
			mc2=middlex*mx2+middley*my2;
			
			deter=mx1*my2-mx2*my1; deterx=mc1*my2-mc2*my1; detery=mx1*mc2-mx2*mc1;
			x=deterx/deter; y=detery/deter;
			radius=Math.sqrt((x-number[0])*(x-number[0])+(y-number[1])*(y-number[1]));
			System.out.printf("%.2f\n", Math.PI*2*radius);
		}
	}
}