import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		int[] prim=new int[100000];
		int count, i, j, num, num1, result, limit;
		prim[0]=2; count=1;
		for(i=3; i<=1000000; i+=2){
			limit=(int)Math.sqrt(i);
			for(j=2; j<=limit; j++){
				if(i%j==0) break;
			}
			if(j>limit) prim[count++]=i;
		}
		while(in.hasNextInt()){
			num=in.nextInt();
			if(num==0) break;
			i=0; result=0; num1=num;
			while(num>=prim[i] && i<count){
				if(num%prim[i]==0){
					++result;
					while(num%prim[i]==0) num/=prim[i];
				}
				++i;
			}
			System.out.println(num1+" : "+result);
		}
	}
}