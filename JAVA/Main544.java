import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		Scanner in=new Scanner(System.in);
		int n, i, edge, j, count, v, u, k, value, start, end, step=0;
		int[][] result=new int[256][256];
		String city1, city2;
		String[] city=new String[256];
		
		while(in.hasNextInt()){
			if(step++>0) System.out.println();
			n=in.nextInt(); edge=in.nextInt();
			if(n+edge==0) break;
			for(i=0; i<n; i++)
				for(j=0; j<n; j++) result[i][j]=0;
			count=0;
			for(i=0; i<edge; i++){
				city1=in.next();
				city2=in.next();
				value=in.nextInt();
				for(j=0; j<count; j++) if(city[j].equals(city1)) break;
				v=j;
				if(j>=count) city[count++]=city1;
				
				for(k=0; k<count; k++) if(city[k].equals(city2)) break;
				u=k;
				if(k>=count) city[count++]=city2;
				result[v][u]=result[u][v]=value;
			}
			city1=in.next(); city2=in.next();
			start=end=0;
			for(i=0; i<n; i++){
				if(city[i].equals(city1)) start=i;
				else if(city[i].equals(city2)) end=i;
			}
			for(k=0; k<n; k++){                   //Floyd-Warshall algorithm
				for(i=0; i<n; i++){
					for(j=0; j<n; j++){
						result[i][j]=Math.max(result[i][j],Math.min(result[i][k],result[k][j]));
					}
				}
			}
			System.out.println("Scenario #"+step);
			System.out.println(result[start][end]+" tons");
		}
	}
}