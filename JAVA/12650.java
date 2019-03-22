import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		boolean[] array=new boolean[10001];
		int n, R, i, num, count;
		Scanner in=new Scanner(System.in);
		while(in.hasNext()){
			n=in.nextInt(); R=in.nextInt();
			for(i=0; i<n; i++) array[i]=false;
			count=0;
			while(count++<R){
				num=in.nextInt()-1;
				array[num]=true;
			}
			boolean flag=true;
			for(i=0; i<n; i++){
				if(array[i]==false){
					flag=false;
					System.out.print(i+1+" ");
				}
			}
			if(flag) System.out.print("*");
			System.out.println();
		}
	}
}