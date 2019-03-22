import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		int start, end, num;
		String line;
		start=0; end=11;
		while(in.hasNextInt()){
			num=in.nextInt();
			if(num==0) break;
			line=in.next()+" "+in.next();
			if(line.equals("right on")){
				if(num>start && num<end) System.out.println("Stan may be honest");
				else System.out.println("Stan is dishonest");
				start=0; end=11;
			}
			else if(line.equals("too high")) end=Math.min(num,end);
			else start=Math.max(num,start);
		}
	}
}