import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		int[][] result=new int[5001][1000];
		int i=0, j=0, carry=0, num=0;
		Scanner in=new Scanner(System.in);
		result[0][0]=0;
		result[1][0]=1;
		for(i=2; i<=5000; i++){
			carry=0;
			for(j=0; j<1000; j++){
				result[i][j]=result[i-1][j]+result[i-2][j]+carry;
				if(result[i][j]>=1000){
					carry=result[i][j]/1000;
					result[i][j]=result[i][j]%1000;
				}
				else carry=0;
			}
		}
		while(in.hasNextInt()){
			num=in.nextInt();
			if(num==0) System.out.println("The Fibonacci number for 0 is 0");
			else{
				for(i=999; i>=0; i--) if(result[num][i]!=0) break;
				System.out.printf("The Fibonacci number for %d is %d", num, result[num][i--]);
				for(j=i; j>=0; j--){
					if(result[num][j]>=100) System.out.printf("%d", result[num][j]);
					else if(result[num][j]>=10) System.out.printf("0%d", result[num][j]);
					else System.out.printf("00%d", result[num][j]);
				}
				System.out.println();
			}
		}
	}
}