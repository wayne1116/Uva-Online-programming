import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		int n, k, result, remain;
		while(in.hasNextInt()){
			n=in.nextInt(); k=in.nextInt();
			result=remain=0;
			while(n>0){
				result+=n;
				remain+=n;
				n=remain/k;
				remain=remain%k;
			}
			System.out.println(result);
		}
	}
}