import java.util.Scanner;
public class Main{
	public static void main(String[] argv){
		int[][] dir=new int[4][2];
		int i=0, j=0, row=0, col=0, x=0, y=0, count=0, nextx, nexty;
		int[][] result=new int[16][16];
		boolean flag=false;
		boolean[][] flag1=new boolean[16][16];
		char[][] line=new char[32][32];
		String line1;
		Scanner in=new Scanner(System.in);
		
		dir[0][0]=-1; dir[0][1]=0;
		dir[1][0]=0; dir[1][1]=1;
		dir[2][0]=1; dir[2][1]=0;
		dir[3][0]=0; dir[3][1]=-1;
		while(true){
			row=in.nextInt(); col=in.nextInt();
			if(row==0 && col==0) break;
			System.out.println();
			x=in.nextInt()-1; y=in.nextInt()-1;
			for(i=0; i<row; i++){
				for(j=0; j<col; j++){
					line1=in.next();
					line[i][j]=line1.charAt(0);
					result[i][j]=-1;
					flag1[i][j]=false;
				}
				line[i][j]='\0';
			}
			count=0;
			result[x][y]=1;
			while(true){
				flag1[x][y]=true;
				flag=true; nextx=nexty=-1;
				for(i=0; i<4; i++){
					if(x+dir[i][0]>=0 && y+dir[i][1]>=0 && x+dir[i][0]<row && y+dir[i][1]<col){
						if(flag && line[x+dir[i][0]][y+dir[i][1]]=='0' && !flag1[x+dir[i][0]][y+dir[i][1]]){
							nextx=x+dir[i][0];
							nexty=y+dir[i][1];
							flag=false;
							count++;
						}
						if(line[x+dir[i][0]][y+dir[i][1]]=='X')
							result[x+dir[i][0]][y+dir[i][1]]=2;
						else
							result[x+dir[i][0]][y+dir[i][1]]=1;
					}
				}
				if(flag) break;
				x=nextx;
				y=nexty;
			}
			for(i=0; i<row; i++){
				for(j=0; j<col; j++) System.out.printf("|---");
				System.out.println("|");
				for(j=0; j<col; j++){
					if(result[i][j]==-1) System.out.printf("| ? ");
					else if(result[i][j]==1) System.out.printf("| 0 ");
					else System.out.printf("| X ");
				}
				System.out.println("|");
			}
			for(i=0; i<col; i++) System.out.printf("|---");
			System.out.println("|\n");
			System.out.println("NUMBER OF MOVEMENTS: "+count);
		}
	}
}
