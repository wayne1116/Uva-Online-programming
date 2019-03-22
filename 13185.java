import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		int[] array=new int[1024];
		int a, i, j, sum, limit, num;
		String line;
		array[1]=array[0]=-1;
		for(i=2; i<=1000; i++){
			sum=1; limit=(int)Math.sqrt(i);
			for(j=2; j<=limit; j++){
				if(i%j==0){
					if(i/j==j) sum+=j;
					else sum+=j+i/j;
				}
			}
			if(sum==i) array[i]=0;
			else if(sum<i) array[i]=-1;
			else array[i]=1;
		}
		a=in.nextInt();
		while(a-->0){
			num=in.nextInt();
			if(array[num]==-1) line="deficient";
			else if(array[num]==0) line="perfect";
			else line="abundant";
			System.out.println(line);
		}
	}
}