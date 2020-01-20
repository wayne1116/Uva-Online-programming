import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		Queue<Integer> q=new LinkedList<Integer>();
		int a, b, n, temp;
		while(in.hasNextInt()){
			a=in.nextInt(); b=in.nextInt(); n=0;
			if(a==1) System.out.println("[0;"+b+"]");
			else{
				while(a!=1){
					q.offer(a/b);
					temp=a%b;
					a=b;
					b=temp;
					n++;
				}
				System.out.print("["+q.poll()+";");
				n--;
				while(n-->1) System.out.print(q.poll()+",");
				System.out.println(q.poll()+"]");
			}
		}
	}
}
