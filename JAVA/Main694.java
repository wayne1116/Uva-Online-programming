import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		long a, b, i, case1=1, temp=0;
		while(true){
			a=in.nextInt();
			b=in.nextInt();
			temp=a;
			if(a<0 && b<0) break;
			i=1;
			while(temp<=b){
				if(temp==1) break;
				else if(temp%2==0) temp/=2;
				else{
					temp=temp*3+1;
					if(temp>b) break;
				}
				i++;
			}
			System.out.println("Case "+case1+":"+" A = "+a+", limit = "+b+", number of terms = "+i);
			case1++;
		}
	}
}