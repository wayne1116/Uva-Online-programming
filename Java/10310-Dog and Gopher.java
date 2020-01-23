import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		int n=0, i=0;
		double[] location=new double[4];
		double[] tempx=new double[1024];
		double[] tempy=new double[1024];
		double len1, len2;
		while(in.hasNextInt()){
			n=in.nextInt();
			for(i=0; i<4; i++) location[i]=in.nextDouble();
			for(i=0; i<n; i++){
				tempx[i]=in.nextDouble();
				tempy[i]=in.nextDouble();
			}
			for(i=0; i<n; i++){
				len1=(location[0]-tempx[i])*(location[0]-tempx[i])+(location[1]-tempy[i])*(location[1]-tempy[i]);
				len2=(location[2]-tempx[i])*(location[2]-tempx[i])+(location[3]-tempy[i])*(location[3]-tempy[i]);
				if(len1*4<=len2){
					System.out.printf("The gopher can escape through the hole at (%.3f,%.3f).\n", tempx[i], tempy[i]);
					break;
				}
			}
			if(i>=n) System.out.println("The gopher cannot escape.");
		}
	}
}
