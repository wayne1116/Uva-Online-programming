import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		String line;
		int a, i, result1, result2;
		a=in.nextInt();
		while(true){
			if(a==0) break;
			line=in.next();
			result1=result2=0;
			for(i=0; i<line.length(); i++){
				if(line.charAt(i)>='A' && line.charAt(i)<='Z')result1=result1*26+line.charAt(i)-65;
				else if(line.charAt(i)>='0' && line.charAt(i)<='9') result2=result2*10+line.charAt(i)-48;
			}
			if(Math.abs(result1-result2)<=100) System.out.println("nice");
			else System.out.println("not nice");
			a--;
		}
	}
}
