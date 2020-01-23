import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		double radius, len;
		while(in.hasNextDouble()){
			radius=in.nextDouble();
			len=in.nextDouble();
			System.out.printf("%.3f\n", 0.5*len*radius*radius*Math.sin(2*Math.PI/len));
		}
	}
}
