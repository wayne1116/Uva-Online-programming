import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		while(in.hasNext()){
			double len=in.nextDouble();
			System.out.printf("%.10f\n", Math.sin(Math.PI*108.0/180.0)*len/Math.sin(Math.PI*63.0/180.0));
		}
	}
}
