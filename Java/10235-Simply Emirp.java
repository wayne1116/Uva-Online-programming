import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		int i, j, limit, num, sum, num1;
		Scanner in=new Scanner(System.in);
		boolean[] prim=new boolean[1000000];
		prim[0]=prim[1]=false;
		for(i=2; i<1000000; i++){
			limit=(int)Math.sqrt(i);
			for(j=2; j<=limit; j++){
				if(i%j==0) break;
			}
			if(j>limit) prim[i]=true;
			else prim[i]=false;
		}
		while(in.hasNextInt()){
			num=in.nextInt();
			if(prim[num]){
				sum=0; num1=num;
				while(num1>0){
					sum=sum*10+(num1%10);
					num1/=10;
				}
				if(prim[sum] && sum!=num) System.out.println(num+" is emirp.");
				else System.out.println(num+" is prime.");
			}
			else System.out.println(num+" is not prime.");
		}
	}
}
