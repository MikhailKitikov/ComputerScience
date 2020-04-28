import java.util.*;

public class MatrixShift {

	public static void main(String[] args) {
		
		Shift(args);
		
		System.exit(0);
	}
	
	public static void Shift(String[] args) {
		// Reading matrix size
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		if (n <= 1) {
			System.err.println("Invalid matrix size!");
			System.exit(1);
		}
		
		// Generating matrix
		Random rnd = new Random(System.currentTimeMillis());
		int [][] matr = new int [n][n];
		System.out.println("Initial matrix:");
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				matr[i][j] = rnd.nextInt() % (n + 1);
				System.out.print(matr[i][j] + "\t");
			}
			System.out.println();
		}
		System.out.println("---------------------");
		
		// Applying shifts to the matrix
		for (int q = 0; q < args.length; ++q) {
			String dir = "";
			int k = 0;
			String dirs = "udlr";
			try {
				StringTokenizer tok = new StringTokenizer(args[q]);
				dir = tok.nextToken();
				if (! (dir.equalsIgnoreCase("u") || dir.equalsIgnoreCase("d") || dir.equalsIgnoreCase("l") || dir.equalsIgnoreCase("r"))) {
					System.out.println("Error: invalid shift direction!");
					System.exit(1);
				}
				++q;
				if (q >= args.length) {
					System.out.println("Error: too few shift parameters!");
					System.exit(1);
				}
				tok = new StringTokenizer(args[q]);
				k = Integer.parseInt(tok.nextToken());		
				if (k < 0) {
					System.out.println("Error: k must be non-negative!");
					System.exit(1);
				}
			}
			catch (Exception e) {
				System.out.println("Exception: " + e.getClass().getName());
				System.exit(1);
			}	
					
			String [] dirsStr = {"Up", "Down", "Left", "Right"};
			char c = dir.charAt(0);
			String sh = dirsStr[dirs.indexOf(c)];
			System.out.println("\t" + sh + " shift (" + k + " points)");	
			if (k >= n) { k %= n; }
			
			switch (c) {
			case 'u': case 'U': {
				int [][] newMatr = new int [n][];
				for (int i = 0; i < n; ++i) {
					int newPos = i - k;
					if (newPos < 0) { newPos += n; }		
					newMatr[newPos] = matr[i];
				}
				matr = newMatr;
				break;
			}				
			case 'd': case 'D': {
				int [][] newMatr = new int [n][];
				for (int i = 0; i < n; ++i) {
					int newPos = i + k;
					if (newPos >= n) { newPos -= n; }		
					newMatr[newPos] = matr[i];
				}
				matr = newMatr;
				break;
			}
			case 'l': case 'L': {
				int [][] newMatr = new int [n][n];
				for (int i = 0; i < n; ++i) {
					int newPos = i - k;
					if (newPos < 0) { newPos += n; }		
					for (int j = 0; j < n; ++j) {
						newMatr[j][newPos] = matr[j][i];
					}
				}
				matr = newMatr;
				break;
			}
			case 'r': case 'R': {
				int [][] newMatr = new int [n][n];
				for (int i = 0; i < n; ++i) {
					int newPos = i + k;
					if (newPos >= n) { newPos -= n; }	
					for (int j = 0; j < n; ++j) {
						newMatr[j][newPos] = matr[j][i];
					}
				}
				matr = newMatr;
				break;
			}
			default:
				break;				
			}
			
			System.out.println("Shifted matrix:");
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					System.out.print(matr[i][j] + "\t");
				}
				System.out.println();
			}
			System.out.println("---------------");
		}
	}
	
}
