import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		double[] x=new double[4];
		double[] y=new double[4];
		int i=0;
		double resultx, resulty;
		while(in.hasNextDouble()){
			for(i=0; i<4; i++){
				x[i]=in.nextDouble(); 
				y[i]=in.nextDouble();
			}
			if(x[2]==x[0] && y[2]==y[0]){
				resultx=x[1]+x[3]-x[0];
				resulty=y[1]+y[3]-y[0];
			}
			else if(x[2]==x[1] && y[2]==y[1]){
				resultx=x[0]+x[3]-x[1];
				resulty=y[0]+y[3]-y[1];
			}
			else if(x[3]==x[0] && y[3]==y[0]){
				resultx=x[1]+x[2]-x[0];
				resulty=y[1]+y[2]-y[0];
			}
			else{
				resultx=x[0]+x[2]-x[1];
				resulty=y[0]+y[2]-y[1];
			}
			System.out.printf("%.3f %.3f\n", resultx, resulty);
		}
	}		
}