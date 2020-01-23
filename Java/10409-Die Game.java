import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		String line;
		int n=0, up, north, east, south, west, temp;
		while(in.hasNextInt()){
			n=in.nextInt();
			if(n==0) break;
			up=1; north=2; south=5; east=4; west=3;
			while(n-->0){
				line=in.next();
				if(line.equals("north")){
					north=up;
					temp=up;
					up=south;
					south=7-temp;
				}
				else if(line.equals("south")){
					south=up;
					temp=up;
					up=north;
					north=7-temp;
				}
				else if(line.equals("east")){
					east=up;
					temp=up;
					up=west;
					west=7-temp;
				}
				else{
					west=up;
					temp=up;
					up=east;
					east=7-temp;
				}
			}
			System.out.println(up);
		}
	}
}
